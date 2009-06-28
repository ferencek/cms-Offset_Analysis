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
   
   gStyle->SetOptStat(1110);
//    gStyle->SetOptTitle(0); // for PAS/AN
   gStyle->SetPadLeftMargin(0.12); // for PAS/AN
   gStyle->SetPadRightMargin(0.08); // for PAS/AN
//    gStyle->SetStatFont(42);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetLabelFont(42, "XYZ");
}

void plot_dist(const string& fFile0, const string& fFile1, const string& fFile2, const string& fFile3, const double fEta, const double fYmax, const string& fTitle, const string& fName) {
   
   TH2F *h2[4];
   TH1D *h1[4];
   
   TFile file0(fFile0.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file0.Get("offsetAnalysis");
   h2[0] = (TH2F*)subDir->Get("h_EinC5_Eta");
   Int_t bin = h2[0]->GetXaxis()->FindBin(fEta);
   h1[0] = h2[0]->ProjectionY("_py",bin,bin);
   
   TFile file1(fFile1.c_str());
   subDir = (TDirectoryFile*)file1.Get("offsetAnalysis");
   h2[1] = (TH2F*)subDir->Get("h_EinC5_Eta");
   h1[1] = h2[1]->ProjectionY("_py",bin,bin);
   
   TFile file2(fFile2.c_str());
   subDir = (TDirectoryFile*)file2.Get("offsetAnalysis");
   h2[2] = (TH2F*)subDir->Get("h_EinC5_Eta");
   h1[2] = h2[2]->ProjectionY("_py",bin,bin);
   
   TFile file3(fFile3.c_str());
   subDir = (TDirectoryFile*)file3.Get("offsetAnalysis");
   h2[3] = (TH2F*)subDir->Get("h_EinC5_Eta");
   h1[3] = h2[3]->ProjectionY("_py",bin,bin);
   
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
   
   h1[3]->SetTitle(fTitle.c_str());
   h1[3]->GetXaxis()->SetRangeUser(-0.2,fYmax);
   h1[3]->GetXaxis()->SetTitleSize(0.05);
   h1[3]->GetYaxis()->SetTitle("Entries/(0.4 GeV)");
   h1[3]->GetYaxis()->SetTitleSize(0.05);
   h1[3]->SetTitleOffset(.9,"X");
   h1[3]->SetTitleOffset(1.2,"Y");
   
   h1[3]->SetLineColor(kRed+3);
   h1[3]->SetLineWidth(3);
   h1[3]->Draw("");
   
   h1[2]->SetLineColor(kRed+2);
   h1[2]->SetLineWidth(3);
   h1[2]->SetLineStyle(2);
   h1[2]->Draw("sames");
   
   h1[1]->SetLineColor(kRed+1);
   h1[1]->SetLineWidth(3);
   h1[1]->SetLineStyle(3);
   h1[1]->Draw("sames");
   
   h1[0]->SetLineColor(kBlue);
   h1[0]->SetLineWidth(3);
   h1[0]->SetLineStyle(4);
   h1[0]->Draw("sames");
   
   //update the current pad (needed to modify statboxes)
   gPad->Update();
   
   // get the statboxes and set colors
   TPaveStats *st1 = (TPaveStats*)h1[3]->GetListOfFunctions()->FindObject("stats");
   st1->SetTextColor(kRed+3);
   st1->SetLineColor(kRed+3);
   st1->SetOptStat(1110);
   TPaveStats *st2 = (TPaveStats*)h1[2]->GetListOfFunctions()->FindObject("stats");
   st2->SetTextColor(kRed+2);
   st2->SetLineColor(kRed+2);
   st2->SetOptStat(1110);
   TPaveStats *st3 = (TPaveStats*)h1[1]->GetListOfFunctions()->FindObject("stats");
   st3->SetTextColor(kRed+1);
   st3->SetLineColor(kRed+1);
   st3->SetOptStat(1110);
   TPaveStats *st4 = (TPaveStats*)h1[0]->GetListOfFunctions()->FindObject("stats");
   st4->SetTextColor(kBlue);
   st4->SetLineColor(kBlue);
   st4->SetOptStat(1110);

   // set the positions of the statboxes
   double x1 = st1->GetX1NDC();
   double y1 = st1->GetY1NDC();
   double x2 = st1->GetX2NDC();
   double y2 = st1->GetY2NDC();
   //double xx = x2-x1;
   double yy = y2-y1;
   st2->SetX1NDC(x1);
   st2->SetY1NDC(y1-yy);
   st2->SetX2NDC(x2);
   st2->SetY2NDC(y1);
   st3->SetX1NDC(x1);
   st3->SetY1NDC(y1-2*yy);
   st3->SetX2NDC(x2);
   st3->SetY2NDC(y1-yy);
   st4->SetX1NDC(x1);
   st4->SetY1NDC(y1-3*yy);
   st4->SetX2NDC(x2);
   st4->SetY2NDC(y1-2*yy);
   gPad->Modified();
   
   TLegend *legend = new TLegend(.25,.68,.42,.86);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
//    legend->SetFillStyle(0);
//    legend->SetTextFont(42);
   legend->AddEntry(h1[3],"5PU","l");
   legend->AddEntry(h1[2],"2PU","l");
   legend->AddEntry(h1[1],"1PU","l");
   legend->AddEntry(h1[0],"Noise","l");
   legend->Draw();

   c->SetLogy();
   c->SaveAs(fName.c_str());

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
   plot_dist(noise_only_05,onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,0.,30.,"In-time pile-up, #eta=0","EinC5_PU_IT_P_eta0.0.eps");
   plot_dist(noise_only_05,onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,1.3,50.,"In-time pile-up, #eta=1.3","EinC5_PU_IT_P_eta1.3.eps");
   plot_dist(noise_only_05,onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,2.4,140.,"In-time pile-up, #eta=2.4","EinC5_PU_IT_P_eta2.4.eps");
   plot_dist(noise_only_05,onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,3.5.,200.,"In-time pile-up, #eta=3.5","EinC5_PU_IT_P_eta3.5.eps");
   
   plot_dist(noise_only_05,onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,0.,30.,"Full pile-up, #eta=0","EinC5_PU_F_P_eta0.0.eps");
   plot_dist(noise_only_05,onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,1.3,50.,"Full pile-up, #eta=1.3","EinC5_PU_F_P_eta1.3.eps");
   plot_dist(noise_only_05,onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,2.4,140.,"Full pile-up, #eta=2.4","EinC5_PU_F_P_eta2.4.eps");
   plot_dist(noise_only_05,onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,3.5.,200.,"Full pile-up, #eta=3.5","EinC5_PU_F_P_eta3.5.eps");
}
