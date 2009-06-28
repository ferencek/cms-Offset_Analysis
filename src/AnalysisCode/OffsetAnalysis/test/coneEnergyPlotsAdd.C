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
   gStyle->SetOptTitle(0); // for PAS
   gStyle->SetPadLeftMargin(0.12); // for PAS
   gStyle->SetPadRightMargin(0.08); // for PAS
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

void overlay_contribs2(const string& fFile0, const string& fFile1, const string& fPlot, const double fYmax, const string& fTitleExt, const string& fNameExt) {
  
   TProfile *p[2];
   
   TFile file0(fFile0.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file0.Get("offsetAnalysis");
   p[0] = (TProfile*)subDir->Get(fPlot.c_str()); 
  
   TFile file1(fFile1.c_str());
   subDir = (TDirectoryFile*)file1.Get("offsetAnalysis");
   p[1] = (TProfile*)subDir->Get(fPlot.c_str()); 
     
   string name = p[0]->GetName();
   string fileName = name + "__" + fNameExt;
     
   string title = p[0]->GetTitle();
   title = title + " " + fTitleExt;
   p[0]->SetTitle(title.c_str());
     
   p[0]->GetYaxis()->SetRangeUser(0,fYmax);
   p[0]->SetTitleOffset(1.25,"Y");
     
   TCanvas *c = new TCanvas("c","",1120,800);
  //    TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
    
   p[0]->SetLineWidth(3);
  //    p[0]->SetLineStyle(6);
   p[0]->SetLineColor(kGreen+2);
   p[0]->Draw("hist");
   p[1]->SetLineWidth(3);
   p[1]->SetLineStyle(2);
   p[1]->SetLineColor(kRed);
   p[1]->Draw("histsame");
  
     
   TLegend *legend = new TLegend(.35,.68,.65,.8);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
     //legend->SetFillStyle(0);
   legend->AddEntry(p[1],"J09 Scheme","l");
   legend->AddEntry(p[0],"Scheme B","l");
   legend->Draw();
     
   TLatex l;
   l.SetTextAlign(12);
   l.SetTextSize(0.04);
   l.SetTextFont(62);
   l.SetNDC();
   l.DrawLatex(0.13,0.85,"CMS Preliminary");
     
   c->SetGridy();
   c->SaveAs(fileName.c_str());
     
   delete legend;
   delete c;
}

void overlay_contribs3(const string& fFile0, const string& fFile1, const string& fFile2, const string& fPlot, const Double_t fYmax, const string& fTitleExt, const string& fLegend, const string& fNameExt) {
  
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
   string fileName = name + "__" + fNameExt;
     
   string title = p[0]->GetTitle();
   title = title + " " + fTitleExt;
   p[0]->SetTitle(title.c_str());
     
//    double ymax = 1.;
//    if ( fPlot.find("p_AvgEinC5") != string::npos ) ymax = 6.;
   p[0]->GetYaxis()->SetRangeUser(0,fYmax);
   p[0]->GetXaxis()->SetTitleSize(0.05);
   p[0]->GetYaxis()->SetTitleSize(0.05);
   p[0]->SetTitleOffset(1.15,"Y");
     
//    TCanvas *c = new TCanvas("c","",1120,800);
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
    
   p[0]->SetLineWidth(3);
   p[0]->SetLineStyle(2);
   p[0]->SetLineColor(kRed);
   p[0]->Draw("hist");
   p[1]->SetLineWidth(3);
//    p[1]->SetLineStyle(2);
   p[1]->SetLineColor(kBlack);
   p[1]->Draw("histsame");
   p[2]->SetLineWidth(3);
   p[2]->SetLineStyle(3);
   p[2]->SetLineColor(kGreen+2);
   p[2]->Draw("histsame");
  
     
   TLegend *legend = new TLegend(.37,.65,.67,.8);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
     //legend->SetFillStyle(0);
   legend->AddEntry(p[0],(fLegend + " (full, 25-ns BX)").c_str(),"l");
   legend->AddEntry(p[1],(fLegend + " (full, 50-ns BX)").c_str(),"l");
   legend->AddEntry(p[2],(fLegend + " (in-time)").c_str(),"l");
   legend->Draw();
     
   TLatex l;
   l.SetTextAlign(12);
   l.SetTextSize(0.04);
   l.SetTextFont(62);
   l.SetNDC();
//    l.DrawLatex(0.13,0.85,"CMS Preliminary");
     
   c->SetGridy();
   c->SaveAs(fileName.c_str());
     
   delete legend;
   delete c;
}

void overlay_contribs8(const string& fFile0, const string& fFile1, const string& fFile2, const string& fFile3, const string& fFile4, const string& fFile5, const string& fFile6, const string& fFile7, const string& fPlot, const string& fTitleExt, const string& fNameExt) {
  
   TProfile *p[8];
 
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
   
   TFile file4(fFile4.c_str());
   subDir = (TDirectoryFile*)file4.Get("offsetAnalysis");
   p[4] = (TProfile*)subDir->Get(fPlot.c_str());
   
   TFile file5(fFile5.c_str());
   subDir = (TDirectoryFile*)file5.Get("offsetAnalysis");
   p[5] = (TProfile*)subDir->Get(fPlot.c_str());
   
   TFile file6(fFile6.c_str());
   subDir = (TDirectoryFile*)file6.Get("offsetAnalysis");
   p[6] = (TProfile*)subDir->Get(fPlot.c_str());
   
   TFile file7(fFile7.c_str());
   subDir = (TDirectoryFile*)file7.Get("offsetAnalysis");
   p[7] = (TProfile*)subDir->Get(fPlot.c_str());
   
   string name = p[0]->GetName();
   string fileName = name + "__" + fNameExt;
   
   string title = p[0]->GetTitle();
   title = title + " " + fTitleExt;
   p[0]->SetTitle(title.c_str());
   
   double ymax = 3.;
   if ( fPlot.find("p_AvgEinC5") != string::npos ) ymax = 20.;
   p[0]->GetYaxis()->SetRangeUser(0,ymax);
   p[0]->SetTitleOffset(1.25,"Y");
   
   TCanvas *c = new TCanvas("c","",1120,800);
//    TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
  
   p[0]->SetLineWidth(3);
//    p[0]->SetLineStyle(6);
   p[0]->SetLineColor(kBlack);
   p[0]->Draw("hist");
   p[1]->SetLineWidth(3);
   p[1]->SetLineStyle(2);
   p[1]->SetLineColor(kCyan);
   p[1]->Draw("histsame");
   p[2]->SetLineWidth(3);
   p[2]->SetLineStyle(3);
   p[2]->SetLineColor(kBlue);
//    p[2]->Draw("histsame");
   p[3]->SetLineWidth(3);
   p[3]->SetLineStyle(4);
   p[3]->SetLineColor(kOrange-3);
//    p[3]->Draw("histsame");
   p[4]->SetLineWidth(3);
   p[4]->SetLineStyle(5);
   p[4]->SetLineColor(kViolet-5);
//    p[4]->Draw("histsame");
   p[5]->SetLineWidth(3);
   p[5]->SetLineStyle(6);
   p[5]->SetLineColor(kGray+2);
   p[5]->Draw("histsame");
   p[6]->SetLineWidth(3);
   p[6]->SetLineStyle(7);
   p[6]->SetLineColor(kRed);
   p[6]->Draw("histsame");
   p[7]->SetLineWidth(3);
   p[7]->SetLineStyle(8);
   p[7]->SetLineColor(kGreen+2);
   p[7]->Draw("histsame");
   
   TLegend *legend = new TLegend(.39,.65,.61,.8);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->AddEntry(p[0],"5PU (BX -5 +3)","l");
   legend->AddEntry(p[1],"5PU (BX -8 +3)","l");
//    legend->AddEntry(p[4],"5PU (BX -1 +1)","l");
//    legend->AddEntry(p[3],"5PU (BX 0 +3)","l");
//    legend->AddEntry(p[2],"5PU (BX -5 0)","l");
   legend->AddEntry(p[6],"5PU (50 ns, BX -5 +3)","l");
   legend->AddEntry(p[5],"5PU (75 ns, BX -5 +3)","l");
   legend->AddEntry(p[7],"5PU (BX 0)","l");
   legend->Draw();
   
   TLatex l;
   l.SetTextAlign(12);
   l.SetTextSize(0.04);
   l.SetTextFont(62);
   l.SetNDC();
   l.DrawLatex(0.13,0.85,"CMS Preliminary");
   
   c->SetGridy();
   c->SaveAs(fileName.c_str());
   
   delete legend;
   delete c;
}

void in_cone_contrib_error(const string& fFile, const string& fPlot, const string& fNameExt) {

   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("offsetAnalysis");
   TProfile *p = (TProfile*)subDir->Get(fPlot.c_str());
     
   string name = p->GetName();
   string fileName = name + "__" + fNameExt + ".png";
     
   TH1D *h_e = new TH1D((name + "_error").c_str(),";#eta;error [%]",100,-5.,5.);
   
   for(int i=1;i<101;i++){
      h_e->SetBinContent(i,(p->GetBinError(i)/p->GetBinContent(i))*100);
   }
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
       
   h_e->Draw("");
     
   c->SaveAs(fileName.c_str());
     
     //delete legend;
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
   // Noise
   string noise = "root_files/Noise-only_ET0.5.root";
   
   string noise_Alt = "root_files/Noise-only_AltScheme_ET0.5.root";
   // 1PU
   string onePU_IT_P = "root_files/1PU_InTime_Poisson_ET0.5.root";
   string onePU_F_P = "root_files/1PU_Full_Poisson_ET0.5.root";
   
   string onePU_IT_P_Alt = "root_files/1PU_InTime_Poisson_AltScheme_ET0.5.root";
   string onePU_F_P_Alt = "root_files/1PU_Full_Poisson_AltScheme_ET0.5.root";
   // 2PU
   string twoPU_IT_P = "root_files/2PU_InTime_Poisson_ET0.5.root";
   string twoPU_F_P = "root_files/2PU_Full_Poisson_ET0.5.root";
   string twoPU_50nsBX_F_P = "root_files/2PU_Full_Poisson_50nsBX_ET0.5.root";
   
   string twoPU_IT_P_Alt = "root_files/2PU_InTime_Poisson_AltScheme_ET0.5.root";
   string twoPU_F_P_Alt = "root_files/2PU_Full_Poisson_AltScheme_ET0.5.root";
   // 5PU
   string fivePU_IT_P = "root_files/5PU_InTime_Poisson_ET0.5.root";
   string fivePU_F_P = "root_files/5PU_Full_Poisson_ET0.5.root";
   string fivePU_BX_m8_3_F_P = "root_files/5PU_Full_Poisson_BX_-8_+3_ET0.5.root";
   string fivePU_BX_m5_0_F_P = "root_files/5PU_Full_Poisson_BX_-5_0_ET0.5.root";
   string fivePU_BX_0_3_F_P = "root_files/5PU_Full_Poisson_BX_0_+3_ET0.5.root";
   string fivePU_BX_m1_1_F_P = "root_files/5PU_Full_Poisson_BX_-1_+1_ET0.5.root";
   string fivePU_75nsBX_F_P = "root_files/5PU_Full_Poisson_75nsBX_ET0.5.root";
   string fivePU_50nsBX_F_P = "root_files/5PU_Full_Poisson_50nsBX_ET0.5.root";
   string fivePU_0T_F_P = "root_files/5PU_Full_Poisson_0T_ET0.5.root";
   
   string fivePU_IT_P_Alt = "root_files/5PU_InTime_Poisson_AltScheme_ET0.5.root";
   string fivePU_F_P_Alt = "root_files/5PU_Full_Poisson_AltScheme_ET0.5.root";
   //********************************************
   // make plots
   //********************************************
//    overlay_contribs2(noise,noise_Alt,"p_AvgpTinC5",1.5,"for Noise-only (CMSSW_2_1_8, IDEAL_V9)", "Noise-only_SchemeComp.eps");
//    overlay_contribs2(noise,noise_Alt,"p_AvgEinC5",1.5,"for Noise-only (CMSSW_2_1_8, IDEAL_V9)", "Noise-only_SchemeComp.eps");
//    
//    overlay_contribs2(onePU_IT_P,onePU_IT_P_Alt,"p_AvgpTinC5",1.7,"for 1PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_IT_P_SchemeComp.eps");
//    overlay_contribs2(onePU_IT_P,onePU_IT_P_Alt,"p_AvgEinC5",3.,"for 1PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_IT_P_SchemeComp.eps");
//    
//    overlay_contribs2(onePU_F_P,onePU_F_P_Alt,"p_AvgpTinC5",1.7,"for 1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_F_P_SchemeComp.eps");
//    overlay_contribs2(onePU_F_P,onePU_F_P_Alt,"p_AvgEinC5",3.,"for 1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_F_P_SchemeComp.eps");
//    
//    overlay_contribs2(twoPU_IT_P,twoPU_IT_P_Alt,"p_AvgpTinC5",2.,"for 2PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_IT_P_SchemeComp.eps");
//    overlay_contribs2(twoPU_IT_P,twoPU_IT_P_Alt,"p_AvgEinC5",6.,"for 2PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_IT_P_SchemeComp.eps");
//    
//    overlay_contribs2(twoPU_F_P,twoPU_F_P_Alt,"p_AvgpTinC5",2.,"for 2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_F_P_SchemeComp.eps");
//    overlay_contribs2(twoPU_F_P,twoPU_F_P_Alt,"p_AvgEinC5",6.,"for 2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_F_P_SchemeComp.eps");
//    
//    overlay_contribs2(fivePU_IT_P,fivePU_IT_P_Alt,"p_AvgpTinC5",3.2,"for 5PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_IT_P_SchemeComp.eps");
//    overlay_contribs2(fivePU_IT_P,fivePU_IT_P_Alt,"p_AvgEinC5",22.,"for 5PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_IT_P_SchemeComp.eps");
//    
//    overlay_contribs2(fivePU_F_P,fivePU_F_P_Alt,"p_AvgpTinC5",3.2,"for 5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_F_P_SchemeComp.eps");
//    overlay_contribs2(fivePU_F_P,fivePU_F_P_Alt,"p_AvgEinC5",22.,"for 5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_F_P_SchemeComp.eps");
   
//    overlay_contribs3(twoPU_F_P,twoPU_50nsBX_F_P,twoPU_IT_P,"p_AvgpTinC5","for 2PU (CMSSW_2_1_8, IDEAL_V9)", "2PU_startup.eps");
      overlay_contribs3(twoPU_F_P,twoPU_50nsBX_F_P,twoPU_IT_P,"p_AvgEinC5", 6, "for 2PU (CMSSW_2_1_8, IDEAL_V9)","2PU", "2PU_startup.png");
      overlay_contribs3(fivePU_F_P,fivePU_50nsBX_F_P,fivePU_IT_P,"p_AvgEinC5", 20, "for 5PU (CMSSW_2_1_8, IDEAL_V9)","5PU", "5PU_startup.png");
//    
//    overlay_contribs8(fivePU_F_P,fivePU_BX_m8_3_F_P,fivePU_BX_m5_0_F_P,fivePU_BX_0_3_F_P,fivePU_BX_m1_1_F_P,fivePU_75nsBX_F_P,fivePU_50nsBX_F_P,fivePU_IT_P,"p_AvgpTinC5","for 5PU (CMSSW_2_1_8, IDEAL_V9)", "5PU_comparison.png");
//    overlay_contribs8(fivePU_F_P,fivePU_BX_m8_3_F_P,fivePU_BX_m5_0_F_P,fivePU_BX_0_3_F_P,fivePU_BX_m1_1_F_P,fivePU_75nsBX_F_P,fivePU_50nsBX_F_P,fivePU_IT_P,"p_AvgEinC5","for 5PU (CMSSW_2_1_8, IDEAL_V9)", "5PU_comparison.png");

//     in_cone_contrib_error(fivePU_F_P,"p_AvgEinC5","error_5PU_F_P");
//     in_cone_contrib_error(fivePU_F_P,"p_AvgpTinC5","error_5PU_F_P");
//     in_cone_contrib_error(fivePU_IT_P,"p_AvgEinC5","error_5PU_IT_P");
//     in_cone_contrib_error(fivePU_IT_P,"p_AvgpTinC5","error_5PU_IT_P");
//     
//     in_cone_contrib_error(twoPU_F_P,"p_AvgEinC5","error_2PU_F_P");
//     in_cone_contrib_error(twoPU_F_P,"p_AvgpTinC5","error_2PU_F_P");
//     in_cone_contrib_error(twoPU_IT_P,"p_AvgEinC5","error_2PU_IT_P");
//     in_cone_contrib_error(twoPU_IT_P,"p_AvgpTinC5","error_2PU_IT_P");
//     
//     in_cone_contrib_error(onePU_F_P,"p_AvgEinC5","error_1PU_F_P");
//     in_cone_contrib_error(onePU_F_P,"p_AvgpTinC5","error_1PU_F_P");
//     in_cone_contrib_error(onePU_IT_P,"p_AvgEinC5","error_1PU_IT_P");
//     in_cone_contrib_error(onePU_IT_P,"p_AvgpTinC5","error_1PU_IT_P");
}