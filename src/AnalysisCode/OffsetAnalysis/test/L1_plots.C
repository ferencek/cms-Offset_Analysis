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
//    gStyle->SetOptTitle(0); //
   gStyle->SetPadLeftMargin(0.13);
   gStyle->SetPadRightMargin(0.07);
//    gStyle->SetStatFont(42);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetLabelFont(42, "XYZ");
}

static TProfile* prof = 0;

Double_t offset(const Double_t fEta)
{
  Int_t bin = prof->GetXaxis()->FindBin(fEta);
  return prof->GetBinContent(bin);
}

Double_t L1_pT_1(Double_t *x, Double_t *p)
{
  Double_t energy = x[0]*cosh(0.);
  Double_t factor = (energy - offset(0.))/energy;  

  return factor;
}

Double_t L1_pT_2(Double_t *x, Double_t *p)
{
  Double_t energy = x[0]*cosh(1.0);
  Double_t factor = (energy - offset(1.0))/energy;  

  return factor;
}

Double_t L1_pT_3(Double_t *x, Double_t *p)
{
  Double_t energy = x[0]*cosh(2.5);
  Double_t factor = (energy - offset(3.5))/energy;  

  return factor;
}

Double_t L1_pT_4(Double_t *x, Double_t *p)
{
  Double_t energy = x[0]*cosh(3.5);
  Double_t factor = (energy - offset(3.5))/energy;  

  return factor;
}

Double_t L1_eta_1(Double_t *x, Double_t *p)
{
  Double_t energy = 10.*cosh(x[0]);
  Double_t factor = (energy - offset(x[0]))/energy;  

  return factor;
}

Double_t L1_eta_2(Double_t *x, Double_t *p)
{
  Double_t energy = 50.*cosh(x[0]);
  Double_t factor = (energy - offset(x[0]))/energy; 

  return factor;
}

Double_t L1_eta_3(Double_t *x, Double_t *p)
{
  Double_t energy = 200.*cosh(x[0]);
  Double_t factor = (energy - offset(x[0]))/energy; 

  return factor;
}

Double_t L1_eta_4(Double_t *x, Double_t *p)
{
  Double_t energy = 1000.*cosh(x[0]);
  Double_t factor = (energy - offset(x[0]))/energy;  

  return factor;
}


void L1_vs_pT(const string& fFile, const string& fTitle, const string& fName)
{
  TFile file(fFile.c_str());
  TDirectoryFile *subDir = (TDirectoryFile*)file.Get("offsetAnalysis");
  prof = (TProfile*)subDir->Get("p_AvgEinC5");
  
  TCanvas *c = new TCanvas("c","",800,800);
  c->cd();
  
  string title = fTitle + ";Uncorrected jet p_{T} [GeV/c];Correction factor";
  
  TH2F *h_bg = new TH2F("h_bg",title.c_str(), 100, .9, 1000., 100, 0.7,1.1);
  h_bg->SetStats(kFALSE);
  h_bg->SetTitleOffset(1.2,"X");
  h_bg->SetTitleOffset(1.7,"Y");
  h_bg->GetYaxis()->SetNdivisions(4);
  h_bg->Draw();
  
  TF1 *f1 = new TF1("f1",L1_pT_1,0.5,1000.,0);
  f1->SetLineWidth(0.5);
  f1->SetLineColor(kBlack);
  f1->Draw("same");
  
  TF1 *f2 = new TF1("f2",L1_pT_2,0.5,1000.,0);
  f2->SetLineWidth(0.5);
  f2->SetLineColor(kRed);
  f2->Draw("same");
  
  TF1 *f3 = new TF1("f3",L1_pT_3,0.5,1000.,0);
  f3->SetLineWidth(0.5);
  f3->SetLineColor(kGreen);
  f3->Draw("same");
  
  TF1 *f4 = new TF1("f4",L1_pT_4,0.5,1000.,0);
  f4->SetLineWidth(0.5);
  f4->SetLineColor(kBlue);
  f4->Draw("same");
  
  TLegend *legend = new TLegend(.65,.72,.85,.87);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->AddEntry(f1,"#eta = 0.0","l");
  legend->AddEntry(f2,"#eta = 1.0","l");
  legend->AddEntry(f3,"#eta = 2.5","l");
  legend->AddEntry(f4,"#eta = 3.5","l");
  legend->Draw();
  
  c->SetGridy();
  c->SetLogx();
  c->SaveAs(fName.c_str());
  
  delete legend;
  delete f1;
  delete f2;
  delete f3;
  delete f4;
  delete h_bg;
  delete c;
}

void L1_vs_eta(const string& fFile, const string& fTitle, const string& fName)
{
  TFile file(fFile.c_str());
  TDirectoryFile *subDir = (TDirectoryFile*)file.Get("offsetAnalysis");
  prof = (TProfile*)subDir->Get("p_AvgEinC5");
  
  TCanvas *c = new TCanvas("c","",800,800);
  c->cd();
  
  string title = fTitle + ";Jet #eta;Correction factor";
  
  TH2F *h_bg = new TH2F("h_bg",title.c_str(), 100, -6., 6., 100, 0.95,1.05);
  h_bg->SetStats(kFALSE);
  h_bg->SetTitleOffset(1.2,"X");
  h_bg->SetTitleOffset(1.7,"Y");
  h_bg->GetYaxis()->SetNdivisions(8);
  h_bg->Draw();
  
  TF1 *f1 = new TF1("f1",L1_eta_1,-5.,5.,0);
  f1->SetLineWidth(0.5);
  f1->SetLineColor(kBlack);
  f1->Draw("same");
  
  TF1 *f2 = new TF1("f2",L1_eta_2,-5.,5.,0);
  f2->SetLineWidth(0.5);
  f2->SetLineColor(kRed);
  f2->Draw("same");
  
  TF1 *f3 = new TF1("f3",L1_eta_3,-5.,5.,0);
  f3->SetLineWidth(0.5);
  f3->SetLineColor(kGreen);
  f3->Draw("same");
  
  TF1 *f4 = new TF1("f4",L1_eta_4,-5.,5.,0);
  f4->SetLineWidth(0.5);
  f4->SetLineColor(kBlue);
  f4->Draw("same");
  
  TLegend *legend = new TLegend(.65,.72,.85,.87);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->AddEntry(f1,"p_{T} = 10 GeV/c","l");
  legend->AddEntry(f2,"p_{T} = 50 GeV/c","l");
  legend->AddEntry(f3,"p_{T} = 200 GeV/c","l");
  legend->AddEntry(f4,"p_{T} = 1000 GeV/c","l");
  legend->Draw();
  
  c->SetGridy();
  c->SaveAs(fName.c_str());
  
  delete legend;
  delete f1;
  delete f2;
  delete f3;
  delete f4;
  delete h_bg;
  delete c;
}

void makePlots()
{
  // turn on/off batch mode
  gROOT->SetBatch(kTRUE);
  // set ROOT style
  style();
  
  // *** noise-only ***
  string noise_only_05 = "root_files/Noise-only_ET0.5.root";
  // *** pile-up ***
  string onePU_IT_P_05 = "root_files/1PU_InTime_Poisson_ET0.5.root";
  string onePU_F_P_05 = "root_files/1PU_Full_Poisson_ET0.5.root";

  string twoPU_IT_P_05 = "root_files/2PU_InTime_Poisson_ET0.5.root";
  string twoPU_F_P_05 = "root_files/2PU_Full_Poisson_ET0.5.root";

  string fivePU_IT_P_05 = "root_files/5PU_InTime_Poisson_ET0.5.root";
  string fivePU_F_P_05 = "root_files/5PU_Full_Poisson_ET0.5.root";
  //********************************************
  // make plots
  //********************************************
  L1_vs_pT(noise_only_05, "Noise-only", "L1_vs_pT_noise.png");
  L1_vs_eta(noise_only_05, "Noise-only", "L1_vs_eta_noise.png");
  
  L1_vs_pT(onePU_IT_P_05, "1PU In-time", "L1_vs_pT_1PUIT.png");
  L1_vs_eta(onePU_IT_P_05, "1PU In-time", "L1_vs_eta_1PUIT.png");
  
  L1_vs_pT(onePU_F_P_05, "1PU Full", "L1_vs_pT_1PUF.png");
  L1_vs_eta(onePU_F_P_05, "1PU Full", "L1_vs_eta_1PUF.png");
}