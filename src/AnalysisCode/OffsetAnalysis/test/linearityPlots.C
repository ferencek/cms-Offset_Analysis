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
//    gStyle->SetOptTitle(0); // for PAS/AN
   gStyle->SetPadLeftMargin(0.11); // for PAS/AN
   gStyle->SetPadRightMargin(0.09); // for PAS/AN
//    gStyle->SetStatFont(42);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetLabelFont(42, "XYZ");
}

void getY(TProfile **fProfiles, Float_t fEta, double *fY, double *fY_e) {

   Int_t bin = fProfiles[0]->GetXaxis()->FindBin(fEta);
   
   for (int i=0; i<3; i++) {
      fY[i] = fProfiles[i]->GetBinContent(bin);
      fY_e[i] = fProfiles[i]->GetBinError(bin);
   }
}

void plotLines(const string& fFile0, const string& fFile1, const string& fFile2, const string& fPlot, const string& fTitleExt, const string& fName) {

   bool dopT = false;
   if ( fPlot.find("pTin") != string::npos ) dopT = true;
   
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
   
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
   
   string title;
   if (dopT) {
    title = fTitleExt + ";<N_{MB}>;<p_{T}> [GeV/c]";
   } else {
    title = fTitleExt + ";<N_{MB}>;<E> [GeV]";
   }
   
   TH2F *h_bg = new TH2F("h_bg",title.c_str(), 100, 0., 6., 100, 0.,1.1*(p[2]->GetMaximum()));
   h_bg->SetStats(kFALSE);
   h_bg->SetTitleOffset(.9,"X");
   h_bg->SetTitleOffset(1.,"Y");
   h_bg->GetXaxis()->SetTitleSize(0.05);
   h_bg->GetYaxis()->SetTitleSize(0.05);
   h_bg->Draw();
   
   double x[3] = {1.,2.,5.};
   double x_e[3] = {0.};
   
   double y_0[3];
   double y_0_e[3];
   getY(p, 0, y_0, y_0_e);
   
   double y_1[3];
   double y_1_e[3];
   getY(p, 1.3, y_1, y_1_e);
   
   double y_2[3];
   double y_2_e[3];
   getY(p, 2.4, y_2, y_2_e);
   
   double y_3[3];
   double y_3_e[3];
   getY(p, 3.5, y_3, y_3_e);
   
   TGraphErrors *g_0 = new TGraphErrors(3, x, y_0, x_e, y_0_e);
   g_0->SetLineColor(kBlue+1);
   g_0->SetLineWidth(3);
   g_0->SetLineStyle(7);
   g_0->SetMarkerSize(1.);
   g_0->SetMarkerStyle(24);
   g_0->SetMarkerColor(kBlue+1);
   g_0->Draw("PC");
   
   TGraphErrors *g_1 = new TGraphErrors(3, x, y_1, x_e, y_1_e);
   g_1->SetLineColor(kGreen+2);
   g_1->SetLineWidth(3);
   g_1->SetLineStyle(3);
   g_1->SetMarkerSize(1.);
   g_1->SetMarkerStyle(25);
   g_1->SetMarkerColor(kGreen+2);
   g_1->Draw("PC");
   
   TGraphErrors *g_2 = new TGraphErrors(3, x, y_2, x_e, y_2_e);
   g_2->SetLineColor(kBlack);
   g_2->SetLineWidth(3);
   g_2->SetLineStyle(5);
   g_2->SetMarkerSize(1.);
   g_2->SetMarkerStyle(26);
   g_2->SetMarkerColor(kBlack);
   g_2->Draw("PC");
   
   TGraphErrors *g_3 = new TGraphErrors(3, x, y_3, x_e, y_3_e);
   g_3->SetLineColor(kRed+1);
   g_3->SetLineWidth(3);
   g_3->SetMarkerSize(1.);
   g_3->SetMarkerStyle(27);
   g_3->SetMarkerColor(kRed+1);
   g_3->Draw("PC");
   
   TLegend *legend = new TLegend(.2,.57,.38,.8);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
//    legend->SetFillStyle(0);
//    legend->SetTextFont(42);
//    legend->SetHeader(fLegendHeader.c_str());
   legend->AddEntry(g_3," #eta = 3.5","lp");
   legend->AddEntry(g_2," #eta = 2.4","lp");
   legend->AddEntry(g_1," #eta = 1.3","lp");
   legend->AddEntry(g_0," #eta = 0","lp");
   legend->Draw();
   

//    TLatex l1;
//    l1.SetTextAlign(12);
//    l1.SetTextSize(0.05);
//    l1.SetTextFont(42);
//    l1.SetNDC();
//    l1.DrawLatex(0.2,0.45,label1.c_str());

   c->SetGridy();
   c->SetGridx();
   c->SaveAs(fName.c_str());

   delete legend;
   delete g_0;
   delete g_1;
   delete g_2;
   delete g_3;
   delete h_bg;
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
//    plotLines(onePU_IT_F_05,twoPU_IT_F_05,fivePU_IT_F_05,"(in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)","AvgEinC5_vs_nPU_IT_F_ET0.5.png");
//    plotLines(onePU_IT_F_05,twoPU_IT_F_05,fivePU_IT_F_05,"(in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)","AvgpTinC5_vs_nPU_IT_F_ET0.5.png");
   plotLines(onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,"p_AvgEinC5","In-time pile-up","AvgEinC5_vs_nPU_IT_P_ET0.5.eps");
   plotLines(onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,"p_AvgpTinC5","In-time pile-up","AvgpTinC5_vs_nPU_IT_P_ET0.5.eps");
   plotLines(onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,"p_AvgEinC5","Full pile-up","AvgEinC5_vs_nPU_F_P_ET0.5.eps");
   plotLines(onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,"p_AvgpTinC5","Full pile-up","AvgpTinC5_vs_nPU_F_P_ET0.5.eps");
}
