void style() {

   gStyle->Reset("Default");
   gStyle->SetCanvasColor(0);
   gStyle->SetPadColor(0);
   gStyle->SetTitleFillColor(10);
   gStyle->SetCanvasBorderMode(0);
   gStyle->SetStatColor(0);
   gStyle->SetPadBorderMode(0);
   gStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
   gStyle->SetPadTickY(1);
   gStyle->SetFrameBorderMode(0);
   gStyle->SetPalette(1);
     
   gStyle->SetOptStat(kFALSE);
//    gStyle->SetStatFont(42);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetLabelFont(42, "XYZ");
}

void in_cone_contrib(const string& fFile, const string& fTitleExt, const string& fNameExt, float fYmax, const string& fSwitch) {
  
   bool dopT = false;
   if ( fSwitch.find("pT") != string::npos ) dopT = true;
   
   TProfile *p;
    
   TFile file(fFile.c_str());
   file.cd("offsetAnalysis");
   if (dopT) p = p_AvgpTinC5; else p = p_AvgEinC5; 
   
   string name = p->GetName();
   string fileName = name + "__" + fNameExt + ".png";
   
   string title = p->GetTitle();
   title = title + " " + fTitleExt;
   p->SetTitle(title.c_str());
   
   //double ymax = p->GetMaximum();
   p->GetYaxis()->SetRangeUser(0,fYmax);
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
     
   p->SetLineWidth(3);
   p->SetLineColor(kBlue+3);
   p->Draw("hist");
  
//    size_t n1 = fNameExt.find("ET");
//    string label1 = "CaloTower E_{T}>" + fNameExt.substr(n1+2,3) + " GeV";
// 
//    TLatex l1;
//    l1.SetTextAlign(22);
//    l1.SetTextSize(0.04);
//    l1.SetTextColor(kRed+1);
//    l1.SetTextFont(42);
//    l1.SetNDC();
//    l1.DrawLatex(0.5,0.4,label1.c_str());
   
   c->SetGridy();
   c->SaveAs(fileName.c_str());
   
   //delete legend;
   delete c;
}

void overlay_contribs(const string& fFile0, const string& fFile1, const string& fFile2, const string& fPlot, const string& fTitleExt, const string& fNameExt) {
  
   TProfile *p[3];
 
   TFile file0(fFile0.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file0.Get("offsetAnalysis");
   p[0] = (TProfile*)subDir->Get(fPlot.c_str()); 

   TFile file1(fFile1.c_str());
   subDir = (TDirectoryFile*)file1.Get("offsetAnalysis");
   p[1] = (TProfile*)subDir->Get(fPlot.c_str()); 
       
   TFile file2(fFile2.c_str());
   subDir = (TDirectoryFile*)file2.Get("offsetAnalysis");
   p[2] = (TProfile*)subDir->Get(fPlot.c_str()); 
   
   string name = p[0]->GetName();
   string fileName = name + "__" + fNameExt + ".png";
   
   string title = p[0]->GetTitle();
   title = title + " " + fTitleExt;
   p[0]->SetTitle(title.c_str());
   
   double ymax = 2.5;
   if ( fPlot.find("p_AvgEinC5") != string::npos ) ymax = 17;
   p[0]->GetYaxis()->SetRangeUser(0,ymax);
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
     
   p[0]->SetLineWidth(3);
   p[0]->SetLineStyle(3);
   p[0]->SetLineColor(kRed+1);
   p[0]->Draw("histsame");
   p[1]->SetLineWidth(3);
   p[1]->SetLineStyle(7);
   p[1]->SetLineColor(kRed+2);
   p[1]->Draw("histsame");
   p[2]->SetLineWidth(3);
   p[2]->SetLineColor(kRed+3);
   p[2]->Draw("histsame");
   
   TLegend *legend = new TLegend(.13,.74,.22,.88);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->AddEntry(p[2],"5PU","l");
   legend->AddEntry(p[1],"2PU","l");
   legend->AddEntry(p[0],"1PU","l");
   legend->Draw();
   
   c->SetGridy();
   c->SaveAs(fileName.c_str());
   
   delete legend;
   delete c;
}

void makePlots() {

   // set ROOT style
   style();
   //********************************************
   // root files
   //********************************************
   // *** noise-only ***
   string noise_only_05 = "root_files/Noise-only_ET0.5.root";
   // *** pile-up ***
   string onePU_IT_F_05 = "root_files/1PU_InTime_Fixed_ET0.5.root";
   string onePU_IT_P_05 = "root_files/1PU_InTime_Poisson_ET0.5.root";
   string onePU_F_P_05 = "root_files/1PU_Full_Poisson_ET0.5.root";
   
   string twoPU_IT_F_05 = "root_files/2PU_InTime_Fixed_ET0.5.root";
   string twoPU_IT_P_05 = "root_files/2PU_InTime_Poisson_ET0.5.root";
   string twoPU_F_P_05 = "root_files/2PU_Full_Poisson_ET0.5.root";
   
   string fivePU_IT_F_05 = "root_files/5PU_InTime_Fixed_ET0.5.root";
   string fivePU_IT_P_05 = "root_files/5PU_InTime_Poisson_ET0.5.root";
   string fivePU_F_P_05 = "root_files/5PU_Full_Poisson_ET0.5.root";
   //********************************************
   // make plots
   //********************************************
   // *** noise ***
   in_cone_contrib(noise_only_05, "for Noise-only (CMSSW_2_1_8, IDEAL_V9)", "Noise-only_ET0.5", 0.18,"");
   in_cone_contrib(noise_only_05, "for Noise-only (CMSSW_2_1_8, IDEAL_V9)", "Noise-only_ET0.5", 0.18,"pT");
// 
//    // *** pile-up ***
   in_cone_contrib(onePU_IT_F_05, "for 1PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Fixed_ET0.5", 2.5,"");
   in_cone_contrib(onePU_IT_P_05, "for 1PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Poisson_ET0.5", 2.5,"");
   in_cone_contrib(onePU_F_P_05, "for 1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_Full_Poisson_ET0.5", 2.5,"");
   in_cone_contrib(onePU_IT_F_05, "for 1PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Fixed_ET0.5", 0.45,"pT");
   in_cone_contrib(onePU_IT_P_05, "for 1PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Poisson_ET0.5", 0.45,"pT");
   in_cone_contrib(onePU_F_P_05, "for 1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_Full_Poisson_ET0.5", 0.45,"pT");
   
   in_cone_contrib(twoPU_IT_F_05, "for 2PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Fixed_ET0.5", 5.0,"");
   in_cone_contrib(twoPU_IT_P_05, "for 2PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Poisson_ET0.5", 5.0,"");
   in_cone_contrib(twoPU_F_P_05, "for 2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_Full_Poisson_ET0.5", 5.0,"");
   in_cone_contrib(twoPU_IT_F_05, "for 2PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Fixed_ET0.5", 0.8,"pT");
   in_cone_contrib(twoPU_IT_P_05, "for 2PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Poisson_ET0.5", 0.8,"pT");
   in_cone_contrib(twoPU_F_P_05, "for 2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_Full_Poisson_ET0.5", 0.8,"pT");
   
   in_cone_contrib(fivePU_IT_F_05, "for 5PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Fixed_ET0.5", 18.0,"");
   in_cone_contrib(fivePU_IT_P_05, "for 5PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Poisson_ET0.5", 18.0,"");
   in_cone_contrib(fivePU_F_P_05, "for 5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_Full_Poisson_ET0.5", 18.0,"");
   in_cone_contrib(fivePU_IT_F_05, "for 5PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Fixed_ET0.5", 2.7,"pT");
   in_cone_contrib(fivePU_IT_P_05, "for 5PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Poisson_ET0.5", 2.7,"pT");
   in_cone_contrib(fivePU_F_P_05, "for 5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_Full_Poisson_ET0.5", 2.7,"pT");
   // *** overlay contributions ***
//    overlay_contribs(onePU_IT_F_05,twoPU_IT_F_05,fivePU_IT_F_05,"p_AvgEinC5","for PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)","PU_InTime_Fixed_overlay");
//    overlay_contribs(onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,"p_AvgEinC5","for PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)","PU_InTime_Poisson_overlay");
//    overlay_contribs(onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,"p_AvgEinC5","for PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)","PU_Full_Poisson_overlay");
//    
//    overlay_contribs(onePU_IT_F_05,twoPU_IT_F_05,fivePU_IT_F_05,"p_AvgpTinC5","for PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)","PU_InTime_Fixed_overlay");
//    overlay_contribs(onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,"p_AvgpTinC5","for PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)","PU_InTime_Poisson_overlay");
//    overlay_contribs(onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,"p_AvgpTinC5","for PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)","PU_Full_Poisson_overlay");
}