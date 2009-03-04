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

void overlay_contribs_F(const string& fFile, const Int_t fMaxNPVs, const string& fTitleExt, const string& fName) {
  
   TProfile *p[fMaxNPVs+1];
 
   TFile file(fFile.c_str());
   TDirectoryFile *dir = (TDirectoryFile*)file.Get("offsetAnalysis");
   TDirectoryFile *subDir = (TDirectoryFile*)dir->Get("PVOffset");
   
   for (Int_t i = 0; i <= fMaxNPVs; i++) {
      char profName[1024];
      if ( fName.find("p_AvgEinC5NPV") != string::npos ) sprintf (profName, "p_AvgEinC5NPV%i", i);
      else sprintf (profName, "p_AvgpTinC5NPV%i", i);
      p[i] = (TProfile*)subDir->Get(profName); 
   } 
   
   string title = p[fMaxNPVs]->GetTitle();
   title = title + " " + fTitleExt;
   p[fMaxNPVs]->SetTitle(title.c_str());
   
//    double ymax = 2.5;
//    if ( fPlot.find("p_AvgEinC5") != string::npos ) ymax = 17;
//    p[0]->GetYaxis()->SetRangeUser(0,ymax);
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
     
   for (Int_t i = fMaxNPVs; i >= 0; i--) {
      p[i]->SetLineWidth(2);
      p[i]->SetLineStyle(fMaxNPVs-i+1);
      p[i]->SetLineColor(kRed+4-fMaxNPVs+i);
      if (i == fMaxNPVs) p[i]->Draw("hist"); else p[i]->Draw("histsame");
   } 
   
   TLegend *legend = new TLegend(.35,.57,.45,.87);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   for (Int_t i = fMaxNPVs; i >= 0; i--) {
      char entry[1024];
      sprintf (entry, "%i PV", i);
      legend->AddEntry(p[i], entry,"l"); 
   }
   legend->Draw();
   
   c->SetGridy();
   c->SaveAs(fName.c_str());
   
   delete legend;
   delete c;
}

void overlay_contribs_PV(const string& fFile0, const string& fFile1, const string& fFile2, const string& fFile3, const string& fFile4, const string& fPlot, const string& fTitleExt, const string& fExt) {
  
   TProfile *p[4];
 
   TFile file0(fFile0.c_str());
   TDirectoryFile *dir = (TDirectoryFile*)file0.Get("offsetAnalysis");
   TDirectoryFile *subDir = (TDirectoryFile*)dir->Get("PVOffset");
   if ( fPlot.find("C5NPV0") != string::npos ) p[0] = (TProfile*)subDir->Get(fPlot.c_str()); 

   TFile file1(fFile1.c_str());
   dir = (TDirectoryFile*)file1.Get("offsetAnalysis");
   subDir = (TDirectoryFile*)dir->Get("PVOffset");
   p[1] = (TProfile*)subDir->Get(fPlot.c_str()); 
       
   TFile file2(fFile2.c_str());
   dir = (TDirectoryFile*)file2.Get("offsetAnalysis");
   subDir = (TDirectoryFile*)dir->Get("PVOffset");
   p[2] = (TProfile*)subDir->Get(fPlot.c_str());
   
   TFile file3(fFile3.c_str());
   dir = (TDirectoryFile*)file3.Get("offsetAnalysis");
   subDir = (TDirectoryFile*)dir->Get("PVOffset");
   p[3] = (TProfile*)subDir->Get(fPlot.c_str());
   
   TFile file4(fFile4.c_str());
   dir = (TDirectoryFile*)file4.Get("offsetAnalysis");
   subDir = (TDirectoryFile*)dir->Get("PVOffset");
   p[4] = (TProfile*)subDir->Get(fPlot.c_str());
   
   string name = p[1]->GetName();
   string fileName = name + "__overlay." + fExt;
   
   string title = p[3]->GetTitle();
   title = title + " " + fTitleExt;
   p[3]->SetTitle(title.c_str());
   
//    double ymax = 2.5;
//    if ( fName.find("p_AvgEinC5") != string::npos ) ymax = 17;
//    p[0]->GetYaxis()->SetRangeUser(0,ymax);
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
     
   p[3]->SetLineWidth(2);
//    p[0]->SetLineStyle(3);
   p[3]->SetLineColor(kRed+3);
   p[3]->Draw("histsame");
   p[2]->SetLineWidth(2);
   p[2]->SetLineStyle(3);
   p[2]->SetLineColor(kRed+2);
   p[2]->Draw("histsame");
   if ( !(fPlot.find("C5NPV4") != string::npos) ) {
      p[1]->SetLineWidth(2);
      p[1]->SetLineStyle(7);
      p[1]->SetLineColor(kRed+1);
      p[1]->Draw("histsame");
   }
   if ( fPlot.find("C5NPV0") != string::npos ) {
      p[0]->SetLineWidth(2);
      p[0]->SetLineStyle(5);
      p[0]->SetLineColor(kRed);
      p[0]->Draw("histsame");
   }
   p[4]->SetLineWidth(2);
   p[4]->SetLineStyle(6);
   p[4]->SetLineColor(kGreen+2);
   p[4]->Draw("histsame");
   
   TLegend *legend = new TLegend(.36,.65,.64,.87);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->AddEntry(p[3],"5PU (full, Poisson)","l");
   legend->AddEntry(p[2],"2PU (full, Poisson)","l");
   if ( !(fPlot.find("C5NPV4") != string::npos) ) legend->AddEntry(p[1],"1PU (full, Poisson)","l");
   if ( fPlot.find("C5NPV0") != string::npos ) legend->AddEntry(p[0],"Noise-only","l");
   legend->AddEntry(p[4],"Noise-only and PU (full, Poisson)","l");
   legend->Draw();
   
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
   string pv_noise_only = "root_files/offlinePrimaryVertices_Noise-only.root";
   // *** pile-up ***
   string pv_1PU_I_F = "root_files/offlinePrimaryVertices_1PU_InTime_Fixed.root";
   string pv_1PU_F_P = "root_files/offlinePrimaryVertices_1PU_Full_Poisson.root";
   
   string pv_2PU_F_P = "root_files/offlinePrimaryVertices_2PU_Full_Poisson.root";
   
   string pv_5PU_F_P = "root_files/offlinePrimaryVertices_5PU_Full_Poisson.root";
   // *** noise-only and pile-up lumped together ***
   string pv_noise_and_PU_F_P = "root_files/offlinePrimaryVertices_Noise-only_and_PU_Full_Poisson.root";
   //********************************************
   // make plots
   //********************************************
   // *** overlay contributions ***
//    overlay_contribs_F(pv_noise_only,0,"for Noise-only (CMSSW_2_1_8, IDEAL_V9)","p_AvgEinC5NPV__Noise-only.png");
//    overlay_contribs_F(pv_noise_only,0,"for Noise-only (CMSSW_2_1_8, IDEAL_V9)","p_AvgpTinC5NPV__Noise-only.png");
//    
   overlay_contribs_F(pv_1PU_I_F,3,"for 1PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)","p_AvgEinC5NPV__1PU_InTime_Fixed.png");
   overlay_contribs_F(pv_1PU_I_F,3,"for 1PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)","p_AvgpTinC5NPV__1PU_InTime_Fixed.png");
//    overlay_contribs_F(pv_1PU_F_P,3,"for 1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)","p_AvgEinC5NPV__1PU_Full_Poisson.png");
//    overlay_contribs_F(pv_1PU_F_P,3,"for 1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)","p_AvgpTinC5NPV__1PU_Full_Poisson.png");
//    
//    overlay_contribs_F(pv_2PU_F_P,4,"for 2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)","p_AvgEinC5NPV__2PU_Full_Poisson.png");
//    overlay_contribs_F(pv_2PU_F_P,4,"for 2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)","p_AvgpTinC5NPV__2PU_Full_Poisson.png");
//    
//    overlay_contribs_F(pv_5PU_F_P,7,"for 5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)","p_AvgEinC5NPV__5PU_Full_Poisson.png");
//    overlay_contribs_F(pv_5PU_F_P,7,"for 5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)","p_AvgpTinC5NPV__5PU_Full_Poisson.png");
//    
//    overlay_contribs_F(pv_noise_and_PU_F_P,7,"for Noise-only and PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "p_AvgEinC5NPV__Noise-only_and_PU_Full_Poisson.png");
//    overlay_contribs_F(pv_noise_and_PU_F_P,7,"for Noise-only and PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "p_AvgpTinC5NPV__Noise-only_and_PU_Full_Poisson.png");
   
//    overlay_contribs_PV(pv_noise_only,pv_1PU_F_P,pv_2PU_F_P,pv_5PU_F_P,pv_noise_and_PU_F_P,"p_AvgEinC5NPV0","for 0 PV (CMSSW_2_1_8, IDEAL_V9)","png");
//    overlay_contribs_PV(pv_noise_only,pv_1PU_F_P,pv_2PU_F_P,pv_5PU_F_P,pv_noise_and_PU_F_P,"p_AvgpTinC5NPV0","for 0 PV (CMSSW_2_1_8, IDEAL_V9)","png");
//    
//    overlay_contribs_PV(pv_noise_only,pv_1PU_F_P,pv_2PU_F_P,pv_5PU_F_P,pv_noise_and_PU_F_P,"p_AvgEinC5NPV1","for 1 PV (CMSSW_2_1_8, IDEAL_V9)","png");
//    overlay_contribs_PV(pv_noise_only,pv_1PU_F_P,pv_2PU_F_P,pv_5PU_F_P,pv_noise_and_PU_F_P,"p_AvgpTinC5NPV1","for 1 PV (CMSSW_2_1_8, IDEAL_V9)","png");
//    
//    overlay_contribs_PV(pv_noise_only,pv_1PU_F_P,pv_2PU_F_P,pv_5PU_F_P,pv_noise_and_PU_F_P,"p_AvgEinC5NPV2","for 2 PV (CMSSW_2_1_8, IDEAL_V9)","png");
//    overlay_contribs_PV(pv_noise_only,pv_1PU_F_P,pv_2PU_F_P,pv_5PU_F_P,pv_noise_and_PU_F_P,"p_AvgpTinC5NPV2","for 2 PV (CMSSW_2_1_8, IDEAL_V9)","png");
//    
//    overlay_contribs_PV(pv_noise_only,pv_1PU_F_P,pv_2PU_F_P,pv_5PU_F_P,pv_noise_and_PU_F_P,"p_AvgEinC5NPV3","for 3 PV (CMSSW_2_1_8, IDEAL_V9)","png");
//    overlay_contribs_PV(pv_noise_only,pv_1PU_F_P,pv_2PU_F_P,pv_5PU_F_P,pv_noise_and_PU_F_P,"p_AvgpTinC5NPV3","for 3 PV (CMSSW_2_1_8, IDEAL_V9)","png");
//    
//    overlay_contribs_PV(pv_noise_only,pv_1PU_F_P,pv_2PU_F_P,pv_5PU_F_P,pv_noise_and_PU_F_P,"p_AvgEinC5NPV4","for 4 PV (CMSSW_2_1_8, IDEAL_V9)","png");
//    overlay_contribs_PV(pv_noise_only,pv_1PU_F_P,pv_2PU_F_P,pv_5PU_F_P,pv_noise_and_PU_F_P,"p_AvgpTinC5NPV4","for 4 PV (CMSSW_2_1_8, IDEAL_V9)","png");
}