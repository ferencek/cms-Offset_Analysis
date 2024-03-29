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
   gStyle->SetOptTitle(0); // for PAS/AN
   gStyle->SetPadLeftMargin(0.13); // for Noise-only
   gStyle->SetPadRightMargin(0.07); // for Noise-only
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
   p->Draw("");
  
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
   p[0]->Draw("hist");
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

void in_cone_contribPAS(const string& fFile, const string& fPlot, const string& fTitleExt, const string& fNameExt) {
  
   TProfile *p;
 
   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("offsetAnalysis");
   p = (TProfile*)subDir->Get(fPlot.c_str()); 
   
   string name = p->GetName();
   string fileName = name + "__" + fNameExt;
   
   string title = p->GetTitle();
   title = title + " " + fTitleExt;
   p->SetTitle(title.c_str());
   
   p->GetYaxis()->SetRangeUser(0,.18);
   if ( fPlot.find("p_AvgpTinC5") != string::npos ) {
      p->GetYaxis()->SetRangeUser(0,.18);
   }
   p->SetTitleOffset(1.3,"Y");
   p->GetXaxis()->SetTitleSize(0.05);
   p->GetYaxis()->SetTitleSize(0.05);
   
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
  
   p->SetLineWidth(3);
   p->SetLineColor(kBlue);
   p->SetMarkerSize(.6);
   p->SetMarkerStyle(26);
   p->SetMarkerColor(kBlue);
   p->Draw("hist");
   
//    TLatex l;
//    l.SetTextAlign(12);
//    l.SetTextSize(0.04);
//    l.SetTextFont(62);
//    l.SetNDC();
//    l.DrawLatex(0.13,0.85,"CMS Preliminary");
   
   c->SetGridy();
   c->SaveAs(fileName.c_str());
   
   delete c;
}

void overlay_contribsPAS(const string& fFile0, const string& fFile1, const string& fFile2, const string& fFile3, const string& fPlot, const string& fTitleExt, const string& fLegendExt, const string& fNameExt) {
  
   TProfile *p[4];
 
   TFile file0(fFile0.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file0.Get("offsetAnalysis");
   p[0] = (TProfile*)subDir->Get(fPlot.c_str()); 

   TFile file1(fFile1.c_str());
   subDir = (TDirectoryFile*)file1.Get("offsetAnalysis");
   p[1] = (TProfile*)subDir->Get(fPlot.c_str()); 
       
   TFile file2(fFile2.c_str());
   subDir = (TDirectoryFile*)file2.Get("offsetAnalysis");
   p[2] = (TProfile*)subDir->Get(fPlot.c_str());
   
   TFile file3(fFile3.c_str());
   subDir = (TDirectoryFile*)file3.Get("offsetAnalysis");
   p[3] = (TProfile*)subDir->Get(fPlot.c_str()); 
   
   string name = p[0]->GetName();
   string fileName = name + "__" + fNameExt;
   
   string title = p[0]->GetTitle();
   title = title + " " + fTitleExt;
   p[0]->SetTitle(title.c_str());
   
   p[0]->GetYaxis()->SetRangeUser(0,20.);
   if ( fPlot.find("p_AvgpTinC5") != string::npos ) {
      p[0]->GetYaxis()->SetRangeUser(0,3.);
   }
   p[0]->SetTitleOffset(1.,"Y");
   p[0]->GetXaxis()->SetTitleSize(0.05);
   p[0]->GetYaxis()->SetTitleSize(0.05);
   
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
  
   p[0]->SetLineWidth(3);
   p[0]->SetLineStyle(4);
   p[0]->SetLineColor(kBlue);
   p[0]->SetMarkerSize(.6);
   p[0]->SetMarkerStyle(26);
   p[0]->SetMarkerColor(kBlue);
   p[0]->Draw("hist");
   p[1]->SetLineWidth(3);
   p[1]->SetLineStyle(3);
   p[1]->SetLineColor(kRed+1);
   p[1]->SetMarkerSize(.8);
   p[1]->SetMarkerStyle(27);
   p[1]->SetMarkerColor(kRed+1);
   p[1]->Draw("histsame");
   p[2]->SetLineWidth(3);
   p[2]->SetLineStyle(2);
   p[2]->SetLineColor(kRed+2);
   p[2]->SetMarkerSize(.6);
   p[2]->SetMarkerStyle(25);
   p[2]->SetMarkerColor(kRed+2);
   p[2]->Draw("histsame");
   p[3]->SetLineWidth(3);
   p[3]->SetLineColor(kRed+3);
   p[3]->SetMarkerSize(.6);
   p[3]->SetMarkerStyle(24);
   p[3]->SetMarkerColor(kRed+3);
   p[3]->Draw("histsame");
   
//    TLegend *legend = new TLegend(.38,.63,.62,.78);
   TLegend *legend = new TLegend(.31,.63,.68,.78); // wider box for PU (in-time, fixed)
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->AddEntry(p[3],("5PU" + fLegendExt).c_str(),"l");
   legend->AddEntry(p[2],("2PU" + fLegendExt).c_str(),"l");
   legend->AddEntry(p[1],("1PU" + fLegendExt).c_str(),"l");
   legend->AddEntry(p[0],"Noise","l");
   legend->Draw();
   
//    TLatex l;
//    l.SetTextAlign(12);
//    l.SetTextSize(0.04);
//    l.SetTextFont(62);
//    l.SetNDC();
//    l.DrawLatex(0.13,0.85,"CMS Preliminary");
   
   if ( fLegendExt.find("full") != string::npos ) {
      TLatex l2;
      l2.SetTextAlign(12);
      l2.SetTextSize(0.03);
      l2.SetTextFont(62);
      l2.SetNDC();
      l2.DrawLatex(0.38,0.8,"Bunch spacing: 25 ns");
   }
   c->SetGridy();
   c->SaveAs(fileName.c_str());
   
   delete legend;
   delete c;
}


void makePlots() {
   // turn on/off batch mode
   gROOT->SetBatch(kTRUE);
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
//    in_cone_contrib(noise_only_05, "for Noise-only (CMSSW_2_1_8, IDEAL_V9)", "Noise-only_ET0.5", 0.18,"");
//    in_cone_contrib(noise_only_05, "for Noise-only (CMSSW_2_1_8, IDEAL_V9)", "Noise-only_ET0.5", 0.18,"pT");

//    // *** pile-up ***
//    in_cone_contrib(onePU_IT_F_05, "for 1PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Fixed_ET0.5", 2.5,"");
//    in_cone_contrib(onePU_IT_P_05, "for 1PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Poisson_ET0.5", 2.5,"");
//    in_cone_contrib(onePU_F_P_05, "for 1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_Full_Poisson_ET0.5", 2.5,"");
//    in_cone_contrib(onePU_IT_F_05, "for 1PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Fixed_ET0.5", 0.45,"pT");
//    in_cone_contrib(onePU_IT_P_05, "for 1PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Poisson_ET0.5", 0.45,"pT");
//    in_cone_contrib(onePU_F_P_05, "for 1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_Full_Poisson_ET0.5", 0.45,"pT");
//    
//    in_cone_contrib(twoPU_IT_F_05, "for 2PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Fixed_ET0.5", 5.0,"");
//    in_cone_contrib(twoPU_IT_P_05, "for 2PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Poisson_ET0.5", 5.0,"");
//    in_cone_contrib(twoPU_F_P_05, "for 2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_Full_Poisson_ET0.5", 5.0,"");
//    in_cone_contrib(twoPU_IT_F_05, "for 2PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Fixed_ET0.5", 0.8,"pT");
//    in_cone_contrib(twoPU_IT_P_05, "for 2PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Poisson_ET0.5", 0.8,"pT");
//    in_cone_contrib(twoPU_F_P_05, "for 2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_Full_Poisson_ET0.5", 0.8,"pT");
//    
//    in_cone_contrib(fivePU_IT_F_05, "for 5PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Fixed_ET0.5", 18.0,"");
//    in_cone_contrib(fivePU_IT_P_05, "for 5PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Poisson_ET0.5", 18.0,"");
//    in_cone_contrib(fivePU_F_P_05, "for 5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_Full_Poisson_ET0.5", 18.0,"");
//    in_cone_contrib(fivePU_IT_F_05, "for 5PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Fixed_ET0.5", 2.7,"pT");
//    in_cone_contrib(fivePU_IT_P_05, "for 5PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Poisson_ET0.5", 2.7,"pT");
//    in_cone_contrib(fivePU_F_P_05, "for 5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_Full_Poisson_ET0.5", 2.7,"pT");

   // *** overlay contributions ***
//    overlay_contribs(onePU_IT_F_05,twoPU_IT_F_05,fivePU_IT_F_05,"p_AvgEinC5","for PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)","PU_InTime_Fixed_overlay");
//    overlay_contribs(onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,"p_AvgEinC5","for PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)","PU_InTime_Poisson_overlay");
//    overlay_contribs(onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,"p_AvgEinC5","for PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)","PU_Full_Poisson_overlay");
//    
//    overlay_contribs(onePU_IT_F_05,twoPU_IT_F_05,fivePU_IT_F_05,"p_AvgpTinC5","for PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)","PU_InTime_Fixed_overlay");
//    overlay_contribs(onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,"p_AvgpTinC5","for PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)","PU_InTime_Poisson_overlay");
//    overlay_contribs(onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,"p_AvgpTinC5","for PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)","PU_Full_Poisson_overlay");

   // plots for the PAS
//    in_cone_contribPAS(noise_only_05,"p_AvgpTinC5","for Noise-only (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "Noise-only_ET0.5.eps");
//    in_cone_contribPAS(noise_only_05,"p_AvgEinC5","for Noise-only (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)",  "Noise-only_ET0.5.eps");
   
   overlay_contribsPAS(noise_only_05,onePU_IT_F_05,twoPU_IT_F_05,fivePU_IT_F_05,"p_AvgpTinC5","for PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", " (in-time, fixed)", "PU_InTime_Fixed_overlay.eps");
   overlay_contribsPAS(noise_only_05,onePU_IT_F_05,twoPU_IT_F_05,fivePU_IT_F_05,"p_AvgEinC5","for PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", " (in-time, fixed)", "PU_InTime_Fixed_overlay.eps");
// //    
//    overlay_contribsPAS(noise_only_05,onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,"p_AvgpTinC5","for PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", " (in-time)", "PU_InTime_Poisson_overlay.eps");
//    overlay_contribsPAS(noise_only_05,onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,"p_AvgEinC5","for PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", " (in-time)", "PU_InTime_Poisson_overlay.eps");
// //    
//    overlay_contribsPAS(noise_only_05,onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,"p_AvgpTinC5","for PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", " (full)", "PU_Full_Poisson_overlay.eps");
//    overlay_contribsPAS(noise_only_05,onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,"p_AvgEinC5","for PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", " (full)",  "PU_Full_Poisson_overlay.eps");
}