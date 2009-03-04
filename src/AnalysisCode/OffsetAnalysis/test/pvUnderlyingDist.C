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
//    gStyle->SetStatFont(42);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetLabelFont(42, "XYZ");
   gStyle->SetStatY(.9);
}

void underlyingDist(const string& fFile, const Int_t fFirstBin, const Int_t fLastBin, const string& fTitleExt, const string& fPlot, const string& fName) {
   
   TH2F *h;
   TH1D *hist;
   TF1 *fit;

   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("closureAnalysis");
   h = (TH2F*)subDir->Get(fPlot.c_str()); 
   hist = (TH1D*)h->ProjectionY("_py",fFirstBin,fLastBin)->Clone();

   string title = hist->GetTitle();
   title = title + " " + fTitleExt;
   hist->SetTitle(title.c_str());

   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
   
   Double_t res =0.;
   Double_t mean = hist->GetMean();
   Double_t mean_e = 0;
   Double_t sigma = hist->GetRMS();
   Double_t sigma_e = 0;
   Double_t xmin = mean - 1.5*sigma;
   Double_t xmax = mean + 1.5*sigma;
   Double_t epsilon = 10;
   Int_t counter = 0;
   do {
      hist->Fit("gaus","","",xmin,xmax);
      fit = hist->GetFunction("gaus");
      epsilon = fabs((mean-(fit->GetParameter(1)))/mean);
      mean = fit->GetParameter(1);
      mean_e = fit->GetParError(1);
      sigma = fit->GetParameter(2);
      sigma_e = fit->GetParError(2);
      xmin = mean - 1.1*sigma;
      xmax = mean + 1.1*sigma;
      counter++;
   } while ( epsilon > 0.001 && counter < 12 );
   res = sigma/mean;

   char pTres[1024];
   sprintf (pTres, "#frac{#sigma(p^{calo}_{T}/p^{gen}_{T})}{<p^{calo}_{T}/p^{gen}_{T}>}=%1.3f", res);

   TLatex l;
   l.SetTextAlign(12);
   l.SetTextSize(0.05);
   l.SetTextFont(42);
   l.SetNDC();
   l.DrawLatex(0.62,0.3,pTres);


   TLatex l2;
   l2.SetTextAlign(12);
   l2.SetTextSize(0.05);
   l2.SetTextFont(42);
   l2.SetNDC();
   l2.SetTextColor(kRed);
   if ( fFile.find("NN_ET") != string::npos ) l2.DrawLatex(0.62,0.45,"No noise");
   else if ( fFile.find("corrected_ET") != string::npos ) l2.DrawLatex(0.62,0.45,"Corrected");
   else if ( fFile.find("corrected_PV_ET") != string::npos ) l2.DrawLatex(0.62,0.45,"Corrected, PV");
   else if ( fFile.find("corrected_PV_Lumi_ET") != string::npos ) l2.DrawLatex(0.62,0.45,"Corrected, PV, Lumi");

   c->SaveAs((fName + ".png").c_str());

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
   // *** QCD ***
   string QCDpt15_NN = "root_files/closureAnalysis_QCDpt15_NN_ET0.5.root";
   string QCDpt15_plus_1PU_F_P = "root_files/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_1PU_F_P_c = "root_files/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_corrected_ET0.5.root";
   string QCDpt15_plus_1PU_F_P_c_pv = "root_files/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_corrected_PV_ET0.5.root";
   string QCDpt15_plus_1PU_F_P_c_pv_l = "root_files/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_corrected_PV_Lumi_ET0.5.root";
   string QCDpt15_plus_2PU_F_P = "root_files/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_2PU_F_P_c = "root_files/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_corrected_ET0.5.root";
   string QCDpt15_plus_2PU_F_P_c_pv = "root_files/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_corrected_PV_ET0.5.root";
   string QCDpt15_plus_2PU_F_P_c_pv_l = "root_files/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_corrected_PV_Lumi_ET0.5.root";
   string QCDpt15_plus_5PU_F_P = "root_files/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_5PU_F_P_c = "root_files/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_corrected_ET0.5.root";
   string QCDpt15_plus_5PU_F_P_c_pv = "root_files/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_corrected_PV_ET0.5.root";
   string QCDpt15_plus_5PU_F_P_c_pv_l = "root_files/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_corrected_PV_Lumi_ET0.5.root";
   //********************************************
   // make plots
   //********************************************
   // ====== QCD no noise ========
   // barrel
   underlyingDist(QCDpt15_NN, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT15_20_B__QCD_NN");
   underlyingDist(QCDpt15_NN, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT20_25_B__QCD_NN");
   underlyingDist(QCDpt15_NN, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT25_30_B__QCD_NN");
   underlyingDist(QCDpt15_NN, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT30_40_B__QCD_NN");
   underlyingDist(QCDpt15_NN, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT40_50_B__QCD_NN");
   underlyingDist(QCDpt15_NN, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT50_70_B__QCD_NN");
   underlyingDist(QCDpt15_NN, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT70_100_B__QCD_NN");
   
   // endcap
   underlyingDist(QCDpt15_NN, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT15_20_E__QCD_NN");
   underlyingDist(QCDpt15_NN, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT20_25_E__QCD_NN");
   underlyingDist(QCDpt15_NN, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT25_30_E__QCD_NN");
   underlyingDist(QCDpt15_NN, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT30_40_E__QCD_NN");
   underlyingDist(QCDpt15_NN, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT40_50_E__QCD_NN");
   underlyingDist(QCDpt15_NN, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT50_70_E__QCD_NN");
   underlyingDist(QCDpt15_NN, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT70_100_E__QCD_NN");
   
   // forward
   underlyingDist(QCDpt15_NN, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT15_20_F__QCD_NN");
   underlyingDist(QCDpt15_NN, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT20_25_F__QCD_NN");
   underlyingDist(QCDpt15_NN, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT25_30_F__QCD_NN");
   underlyingDist(QCDpt15_NN, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT30_40_F__QCD_NN");
   underlyingDist(QCDpt15_NN, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT40_50_F__QCD_NN");
   underlyingDist(QCDpt15_NN, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT50_70_F__QCD_NN");
   underlyingDist(QCDpt15_NN, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT70_100_F__QCD_NN");
   
   
   // ====== QCD+1PU ========
   // barrel
   underlyingDist(QCDpt15_plus_1PU_F_P, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT15_20_B__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT20_25_B__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT25_30_B__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT30_40_B__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT40_50_B__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT50_70_B__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT70_100_B__QCD_plus_1PU_F_P");
   
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT15_20_B__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT20_25_B__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT25_30_B__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT30_40_B__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT40_50_B__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT50_70_B__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT70_100_B__QCD_plus_1PU_F_P_corrected");
   
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT15_20_B__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT20_25_B__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT25_30_B__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT30_40_B__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT40_50_B__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT50_70_B__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT70_100_B__QCD_plus_1PU_F_P_corrected_PV");
   
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT15_20_B__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT20_25_B__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT25_30_B__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT30_40_B__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT40_50_B__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT50_70_B__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT70_100_B__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   
   // endcap
   underlyingDist(QCDpt15_plus_1PU_F_P, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT15_20_E__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT20_25_E__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT25_30_E__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT30_40_E__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT40_50_E__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT50_70_E__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT70_100_E__QCD_plus_1PU_F_P");
   
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT15_20_E__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT20_25_E__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT25_30_E__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT30_40_E__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT40_50_E__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT50_70_E__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT70_100_E__QCD_plus_1PU_F_P_corrected");
   
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT15_20_E__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT20_25_E__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT25_30_E__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT30_40_E__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT40_50_E__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT50_70_E__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT70_100_E__QCD_plus_1PU_F_P_corrected_PV");
   
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT15_20_E__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT20_25_E__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT25_30_E__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT30_40_E__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT40_50_E__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT50_70_E__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT70_100_E__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   
   // forward
   underlyingDist(QCDpt15_plus_1PU_F_P, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT15_20_F__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT20_25_F__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT25_30_F__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT30_40_F__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT40_50_F__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT50_70_F__QCD_plus_1PU_F_P");
   underlyingDist(QCDpt15_plus_1PU_F_P, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT70_100_F__QCD_plus_1PU_F_P");
   
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT15_20_F__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT20_25_F__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT25_30_F__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT30_40_F__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT40_50_F__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT50_70_F__QCD_plus_1PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_1PU_F_P_c, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT70_100_F__QCD_plus_1PU_F_P_corrected");
   
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT15_20_F__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT20_25_F__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT25_30_F__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT30_40_F__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT40_50_F__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT50_70_F__QCD_plus_1PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT70_100_F__QCD_plus_1PU_F_P_corrected_PV");
   
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT15_20_F__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT20_25_F__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT25_30_F__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT30_40_F__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT40_50_F__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT50_70_F__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_1PU_F_P_c_pv_l, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT70_100_F__QCD_plus_1PU_F_P_corrected_PV_Lumi");
   
   
   // ====== QCD+2PU ========
   // barrel
   underlyingDist(QCDpt15_plus_2PU_F_P, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT15_20_B__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT20_25_B__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT25_30_B__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT30_40_B__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT40_50_B__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT50_70_B__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT70_100_B__QCD_plus_2PU_F_P");
   
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT15_20_B__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT20_25_B__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT25_30_B__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT30_40_B__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT40_50_B__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT50_70_B__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT70_100_B__QCD_plus_2PU_F_P_corrected");
   
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT15_20_B__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT20_25_B__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT25_30_B__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT30_40_B__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT40_50_B__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT50_70_B__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT70_100_B__QCD_plus_2PU_F_P_corrected_PV");
   
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT15_20_B__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT20_25_B__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT25_30_B__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT30_40_B__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT40_50_B__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT50_70_B__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT70_100_B__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   
   // endcap
   underlyingDist(QCDpt15_plus_2PU_F_P, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT15_20_E__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT20_25_E__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT25_30_E__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT30_40_E__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT40_50_E__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT50_70_E__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT70_100_E__QCD_plus_2PU_F_P");
   
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT15_20_E__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT20_25_E__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT25_30_E__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT30_40_E__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT40_50_E__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT50_70_E__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT70_100_E__QCD_plus_2PU_F_P_corrected");
   
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT15_20_E__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT20_25_E__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT25_30_E__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT30_40_E__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT40_50_E__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT50_70_E__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT70_100_E__QCD_plus_2PU_F_P_corrected_PV");
   
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT15_20_E__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT20_25_E__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT25_30_E__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT30_40_E__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT40_50_E__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT50_70_E__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT70_100_E__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   
   // forward
   underlyingDist(QCDpt15_plus_2PU_F_P, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT15_20_F__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT20_25_F__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT25_30_F__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT30_40_F__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT40_50_F__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT50_70_F__QCD_plus_2PU_F_P");
   underlyingDist(QCDpt15_plus_2PU_F_P, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT70_100_F__QCD_plus_2PU_F_P");
   
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT15_20_F__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT20_25_F__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT25_30_F__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT30_40_F__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT40_50_F__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT50_70_F__QCD_plus_2PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_2PU_F_P_c, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT70_100_F__QCD_plus_2PU_F_P_corrected");
   
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT15_20_F__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT20_25_F__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT25_30_F__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT30_40_F__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT40_50_F__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT50_70_F__QCD_plus_2PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT70_100_F__QCD_plus_2PU_F_P_corrected_PV");
   
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT15_20_F__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT20_25_F__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT25_30_F__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT30_40_F__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT40_50_F__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT50_70_F__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_2PU_F_P_c_pv_l, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT70_100_F__QCD_plus_2PU_F_P_corrected_PV_Lumi");
   
   
   // ====== QCD+5PU ========
   // barrel
   underlyingDist(QCDpt15_plus_5PU_F_P, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT15_20_B__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT20_25_B__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT25_30_B__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT30_40_B__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT40_50_B__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT50_70_B__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT70_100_B__QCD_plus_5PU_F_P");
   
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT15_20_B__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT20_25_B__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT25_30_B__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT30_40_B__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT40_50_B__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT50_70_B__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT70_100_B__QCD_plus_5PU_F_P_corrected");
   
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT15_20_B__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT20_25_B__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT25_30_B__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT30_40_B__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT40_50_B__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT50_70_B__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT70_100_B__QCD_plus_5PU_F_P_corrected_PV");
   
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT15_20_B__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT20_25_B__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT25_30_B__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT30_40_B__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT40_50_B__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT50_70_B__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_B", "CaloJetpToverGenJetpT_dist_pT70_100_B__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   
   // endcap
   underlyingDist(QCDpt15_plus_5PU_F_P, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT15_20_E__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT20_25_E__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT25_30_E__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT30_40_E__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT40_50_E__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT50_70_E__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT70_100_E__QCD_plus_5PU_F_P");
   
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT15_20_E__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT20_25_E__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT25_30_E__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT30_40_E__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT40_50_E__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT50_70_E__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT70_100_E__QCD_plus_5PU_F_P_corrected");
   
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT15_20_E__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT20_25_E__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT25_30_E__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT30_40_E__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT40_50_E__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT50_70_E__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT70_100_E__QCD_plus_5PU_F_P_corrected_PV");
   
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT15_20_E__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT20_25_E__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT25_30_E__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT30_40_E__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT40_50_E__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT50_70_E__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_E", "CaloJetpToverGenJetpT_dist_pT70_100_E__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   
   // forward
   underlyingDist(QCDpt15_plus_5PU_F_P, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT15_20_F__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT20_25_F__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT25_30_F__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT30_40_F__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT40_50_F__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT50_70_F__QCD_plus_5PU_F_P");
   underlyingDist(QCDpt15_plus_5PU_F_P, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT70_100_F__QCD_plus_5PU_F_P");
   
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT15_20_F__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT20_25_F__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT25_30_F__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT30_40_F__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT40_50_F__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT50_70_F__QCD_plus_5PU_F_P_corrected");
   underlyingDist(QCDpt15_plus_5PU_F_P_c, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT70_100_F__QCD_plus_5PU_F_P_corrected");
   
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT15_20_F__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT20_25_F__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT25_30_F__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT30_40_F__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT40_50_F__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT50_70_F__QCD_plus_5PU_F_P_corrected_PV");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT70_100_F__QCD_plus_5PU_F_P_corrected_PV");
   
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 16, 20, "& 15<p_{T}^{gen}<20 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT15_20_F__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 21, 25, "& 20<p_{T}^{gen}<25 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT20_25_F__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 26, 30, "& 25<p_{T}^{gen}<30 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT25_30_F__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 31, 40, "& 30<p_{T}^{gen}<40 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT30_40_F__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 41, 50, "& 40<p_{T}^{gen}<50 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT40_50_F__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 51, 70, "& 50<p_{T}^{gen}<70 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT50_70_F__QCD_plus_5PU_F_P_corrected_PV_Lumi");
   underlyingDist(QCDpt15_plus_5PU_F_P_c_pv_l, 71, 100, "& 70<p_{T}^{gen}<100 GeV/c (CMSSW_2_1_8, IDEAL_V9)", "h_CaloJetpToverGenJetpT_pT_F", "CaloJetpToverGenJetpT_dist_pT70_100_F__QCD_plus_5PU_F_P_corrected_PV_Lumi");
}
