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
   gStyle->SetOptFit(0111);
   gStyle->SetStatFont(42);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetLabelFont(42, "XYZ");
   gStyle->SetStatX(.95);
   gStyle->SetStatY(.9);
   gStyle->SetStatW(0.12);
   gStyle->SetStatH(0.1);
}

const float tower_size[41]=
{0.087, 0.087, 0.087, 0.087, 0.087, 
 0.087, 0.087, 0.087, 0.087, 0.087,
 0.087, 0.087, 0.087, 0.087, 0.087,
 0.087, 0.087, 0.087, 0.087, 0.087,
 0.090, 0.100, 0.113, 0.129, 0.150,
 0.178, 0.150, 0.350, 0.111, 0.175,
 0.175, 0.175, 0.175, 0.175, 0.174,
 0.178, 0.172, 0.175, 0.178, 0.173,
 0.302};

void getY(TH1D **fHistos, Float_t fXvalue, double *fY, double *fY_e) {

   Int_t bin = fHistos[0]->GetXaxis()->FindBin(fXvalue);
   
   for (int i=0; i<3; i++) {
      fY[i] = fHistos[i]->GetBinContent(bin);
      fY_e[i] = fHistos[i]->GetBinError(bin);
   }
}

void plotLine(const string& fFile1, const string& fFile2, const string& fFile3, const string& fTitleExt, const string& fName) {
   
   TH1D *p[3];
 
   TFile file1(fFile1.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file1.Get("offsetAnalysis");
   p[0] = ((TProfile*)subDir->Get("p_AvgEinER"))->ProjectionX(); 

   TFile file2(fFile2.c_str());
   subDir = (TDirectoryFile*)file2.Get("offsetAnalysis");
   p[1] = ((TProfile*)subDir->Get("p_AvgEinER"))->ProjectionX(); 
   
   TFile file3(fFile3.c_str());
   subDir = (TDirectoryFile*)file3.Get("offsetAnalysis");
   p[2] = ((TProfile*)subDir->Get("p_AvgEinER"))->ProjectionX(); 
   
   for (int i=41; i>0; i--) {
      p[0]->SetBinContent(i,p[0]->GetBinContent(i)/tower_size[41-i]);
      p[1]->SetBinContent(i,p[1]->GetBinContent(i)/tower_size[41-i]);
      p[2]->SetBinContent(i,p[2]->GetBinContent(i)/tower_size[41-i]);
   }
   for (int i=43; i<84; i++) {
      p[0]->SetBinContent(i,p[0]->GetBinContent(i)/tower_size[i-43]);
      p[1]->SetBinContent(i,p[1]->GetBinContent(i)/tower_size[i-43]);
      p[2]->SetBinContent(i,p[2]->GetBinContent(i)/tower_size[i-43]);
   }     

   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
   
   string title = "d<E>/d#eta in i#eta Ring vs. nPU " + fTitleExt + ";nPU;d<E>/d#eta [GeV]";
   
   double x[3] = {1.,2.,5.};
   double x_e[3] = {0.};
   
   double y[3];
   double y_e[3];

   for (int i=1; i<2; i++) {   

      getY(p, (Float_t)i, y, y_e);
   
      TH2F *h_bg = new TH2F("h_bg",title.c_str(), 100, 0., 6., 100, 0.,1.4*y[2]);
      h_bg->SetStats(kFALSE);
      h_bg->SetTitleOffset(1.2,"X");
      h_bg->SetTitleOffset(1.2,"Y");
      h_bg->Draw();
   
      TGraphErrors *ge = new TGraphErrors(3, x, y, x_e, y_e);
      ge->SetMarkerSize(0.9);
      ge->SetMarkerStyle(20);
      ge->SetMarkerColor(kRed);
      ge->Draw("P");
      ge->Fit("pol2","","",0.5,5.5);
   
      char iEta[8];
      sprintf (iEta, "%i", i);

      string l = "i#eta=";

      TLegend *legend = new TLegend(.15,.8,.25,.85);
      legend->SetBorderSize(1);
      legend->SetFillColor(0);
      //legend->SetFillStyle(0);
      legend->SetTextFont(42);
      legend->AddEntry(h_bg,(l + iEta).c_str(),"");
      legend->Draw();
   
      c->SetGridy();
      c->SaveAs((fName + "_iEta" + iEta + ".png").c_str());
   
      delete legend;
      delete ge;
      delete h_bg;
   }
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
//    plotLine(onePU_IT_F_05,twoPU_IT_F_05,fivePU_IT_F_05,"(in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)","AvgEinER_vs_nPU_IT_F_ET0.5");
//    plotLine(onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,"(in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)","AvgEinER_vs_nPU_IT_P_ET0.5");
   plotLine(onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,"(full, Poisson) (CMSSW_2_1_8, IDEAL_V9)","AvgEinER_vs_nPU_F_P_ET0.5");
}
