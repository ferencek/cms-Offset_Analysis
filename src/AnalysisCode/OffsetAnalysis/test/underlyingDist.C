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
   
   //gStyle->SetOptStat(kFALSE);
   gStyle->SetOptStat(111110);
   gStyle->SetOptFit(1);
   gStyle->SetStatFont(42);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetLabelFont(42, "XYZ");
   gStyle->SetStatY(.9);
}

void underlyingDist(const string& fFile, const Int_t fFirstBin, const Int_t fLastBin, const string& fTitleExt, const string& fPlot, const string& fName) {
   
   TH2F *h;
   TH1D *hist;
   TF1 *fit;
   double res = 0;

   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("closureAnalysis");
   h = (TH2F*)subDir->Get(fPlot.c_str()); 
   hist = (TH1D*)h->ProjectionY("_py",fFirstBin,fLastBin)->Clone();

   string title = hist->GetTitle();
   title = title + " " + fTitleExt;
   hist->SetTitle(title.c_str());

   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();

   Double_t xmin = hist->GetMean()-1.5*hist->GetRMS();
   Double_t xmax = hist->GetMean()+1.5*hist->GetRMS();
   hist->Draw();
   hist->Fit("gaus","","",xmin,xmax);
   fit = hist->GetFunction("gaus");
   res = fit->GetParameter(2)/fit->GetParameter(1);

   char pTres[1024];
   sprintf (pTres, "#frac{#sigma(p^{calo}_{T}/p^{gen}_{T})}{<p^{calo}_{T}/p^{gen}_{T}>}=%1.3f", res);

   TLatex l;
   l.SetTextAlign(12);
   l.SetTextSize(0.05);
   l.SetTextFont(42);
   l.SetNDC();
   l.DrawLatex(0.62,0.3,pTres);

   if ( fName.find("corrected") != string::npos ) {
      TLatex l2;
      l2.SetTextAlign(12);
      l2.SetTextSize(0.05);
      l2.SetTextFont(42);
      l2.SetTextColor(kRed);
      l2.SetNDC();
      l2.DrawLatex(0.62,0.45,"Corrected");
   }

   c->SaveAs((fName + ".png").c_str());

   delete c;
}

void makePlots() {

   // set ROOT style
   style();
   //********************************************
   // root files
   //********************************************
   // *** QCD ***
   string QCDpt15_plus_1PU_F_P_05 = "root_files/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_1PU_F_P_c_05 = "root_files/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_corrected_ET0.5.root";
   string QCDpt15_plus_2PU_F_P_05 = "root_files/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_2PU_F_P_c_05 = "root_files/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_corrected_ET0.5.root";
   string QCDpt15_plus_5PU_F_P_05 = "root_files/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_5PU_F_P_c_05 = "root_files/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_corrected_ET0.5.root";
   //********************************************
   // make plots
   //********************************************
   // *** uncorrected ***
   // barrel
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 16, 20, "& 15<p_{T}^{gen}<20  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT15_20_B");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 21, 25, "& 20<p_{T}^{gen}<25  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT20_25_B");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 26, 30, "& 25<p_{T}^{gen}<30  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT25_30_B");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 31, 40, "& 30<p_{T}^{gen}<40  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT30_40_B");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 41, 50, "& 40<p_{T}^{gen}<50  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT40_50_B");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 51, 70, "& 50<p_{T}^{gen}<70  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT50_70_B");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 71, 100, "& 70<p_{T}^{gen}<100  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT70_100_B");
   // endcap
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 16, 20, "& 15<p_{T}^{gen}<20  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT15_20_E");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 21, 25, "& 20<p_{T}^{gen}<25  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT20_25_E");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 26, 30, "& 25<p_{T}^{gen}<30  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT25_30_E");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 31, 40, "& 30<p_{T}^{gen}<40  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT30_40_E");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 41, 50, "& 40<p_{T}^{gen}<50  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT40_50_E");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 51, 70, "& 50<p_{T}^{gen}<70  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT50_70_E");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 71, 100, "& 70<p_{T}^{gen}<100  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT70_100_E");
   // forward
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 16, 20, "& 15<p_{T}^{gen}<20  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT15_20_F");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 21, 25, "& 20<p_{T}^{gen}<25  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT20_25_F");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 26, 30, "& 25<p_{T}^{gen}<30  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT25_30_F");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 31, 40, "& 30<p_{T}^{gen}<40  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT30_40_F");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 41, 50, "& 40<p_{T}^{gen}<50  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT40_50_F");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 51, 70, "& 50<p_{T}^{gen}<70  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT50_70_F");
   underlyingDist(QCDpt15_plus_1PU_F_P_05, 71, 100, "& 70<p_{T}^{gen}<100  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT70_100_F");
   // *** corrected ***
   // barrel
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 16, 20, "& 15<p_{T}^{gen}<20  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT15_20_B_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 21, 25, "& 20<p_{T}^{gen}<25  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT20_25_B_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 26, 30, "& 25<p_{T}^{gen}<30  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT25_30_B_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 31, 40, "& 30<p_{T}^{gen}<40  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT30_40_B_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 41, 50, "& 40<p_{T}^{gen}<50  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT40_50_B_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 51, 70, "& 50<p_{T}^{gen}<70  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT50_70_B_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 71, 100, "& 70<p_{T}^{gen}<100  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT70_100_B_corrected");
   // endcap
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 16, 20, "& 15<p_{T}^{gen}<20  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT15_20_E_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 21, 25, "& 20<p_{T}^{gen}<25  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT20_25_E_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 26, 30, "& 25<p_{T}^{gen}<30  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT25_30_E_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 31, 40, "& 30<p_{T}^{gen}<40  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT30_40_E_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 41, 50, "& 40<p_{T}^{gen}<50  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT40_50_E_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 51, 70, "& 50<p_{T}^{gen}<70  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT50_70_E_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 71, 100, "& 70<p_{T}^{gen}<100  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT70_100_E_corrected");
   // forward
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 16, 20, "& 15<p_{T}^{gen}<20  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT15_20_F_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 21, 25, "& 20<p_{T}^{gen}<25  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT20_25_F_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 26, 30, "& 25<p_{T}^{gen}<30  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT25_30_F_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 31, 40, "& 30<p_{T}^{gen}<40  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT30_40_F_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 41, 50, "& 40<p_{T}^{gen}<50  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT40_50_F_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 51, 70, "& 50<p_{T}^{gen}<70  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT50_70_F_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_05, 71, 100, "& 70<p_{T}^{gen}<100  (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "QCD_plus_1PU_F_P__CaloJetpToverGenJetpT_pT70_100_F_corrected");
}
