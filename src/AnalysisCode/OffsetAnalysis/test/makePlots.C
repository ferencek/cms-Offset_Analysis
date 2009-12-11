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
//    gStyle->SetOptTitle(0);
   gStyle->SetPadLeftMargin(0.13);
   gStyle->SetPadRightMargin(0.07);
}

void overlay_plots1(const string& fFile0, const string& fFile1, const string& fPlot, const string& fName) {
  
   TH1F *h[2];
 
   TFile file0(fFile0.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file0.Get("offsetAnalysis");
   h[0] = (TH1F*)subDir->Get(fPlot.c_str()); 

   TFile file1(fFile1.c_str());
   subDir = (TDirectoryFile*)file1.Get("offsetAnalysis");
   h[1] = (TH1F*)subDir->Get(fPlot.c_str()); 

   h[0]->SetTitleOffset(1.5,"Y");
   h[0]->GetXaxis()->SetTitleSize(0.04);
   h[0]->GetYaxis()->SetTitleSize(0.04);
   
   double ymax = ((h[0]->GetMaximum())>(h[1]->GetMaximum())) ? h[0]->GetMaximum() : h[1]->GetMaximum();
   
   h[0]->GetYaxis()->SetRangeUser(0.,1.2*ymax);
   
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
  
   h[0]->SetLineWidth(3);
   h[0]->SetLineColor(kRed);
   h[0]->SetFillColor(kRed);
   h[0]->Draw("hist");
   h[1]->SetLineWidth(3);
   h[1]->SetLineColor(kBlack);
   h[1]->SetMarkerStyle(20);
   h[1]->SetMarkerColor(kBlack);
   h[1]->Draw("sames");
   
   TLegend *legend = new TLegend(.57,.77,.9,.87);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   legend->SetMargin(0.12);
   legend->AddEntry(h[0],"NoiseOnly MC, STARTUP3X_V8I","l");
   legend->AddEntry(h[1],"ZeroBias data, Run 123596","l");
   legend->Draw();
   
   TLatex l;
   l.SetTextAlign(12);
   l.SetTextSize(0.04);
   l.SetTextFont(62);
   l.SetNDC();
   l.DrawLatex(0.15,0.85,"CMS 2009 Preliminary");
   
   string fileName = fName;
   c->SaveAs(fileName.c_str());
   
   delete legend;
   delete c;
}


void overlay_plots2(const string& fFile0, const string& fFile1, const string& fPlot, const string& fName) {
  
   TH1F *h[2];
 
   TFile file0(fFile0.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file0.Get("offsetAnalysis");
   h[0] = (TH1F*)subDir->Get(fPlot.c_str()); 

   TFile file1(fFile1.c_str());
   subDir = (TDirectoryFile*)file1.Get("offsetAnalysis");
   h[1] = (TH1F*)subDir->Get(fPlot.c_str()); 

   h[0]->SetTitleOffset(1.5,"Y");
   h[0]->GetXaxis()->SetTitleSize(0.04);
   h[0]->GetYaxis()->SetTitleSize(0.04);
   
   double ymax = ((h[0]->GetMaximum())>(h[1]->GetMaximum())) ? h[0]->GetMaximum() : h[1]->GetMaximum();
   
   h[0]->GetYaxis()->SetRangeUser(0.,1.2*ymax);
   
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
  
   h[0]->SetLineWidth(3);
   h[0]->SetLineColor(kRed);
   h[0]->SetFillColor(kRed);
   h[0]->Draw("hist");
   h[1]->SetLineWidth(3);
   h[1]->SetLineColor(kBlack);
   h[1]->SetMarkerStyle(20);
   h[1]->SetMarkerColor(kBlack);
   h[1]->Draw("sames");
   
   TLegend *legend = new TLegend(.57,.77,.9,.87);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   legend->SetMargin(0.12);
   legend->AddEntry(h[0],"900 GeV MinBias MC, STARTUP3X_V8I","l");
   legend->AddEntry(h[1],"Collision candidates, Run 123596","l");
   legend->Draw();
   
   TLatex l;
   l.SetTextAlign(12);
   l.SetTextSize(0.04);
   l.SetTextFont(62);
   l.SetNDC();
   l.DrawLatex(0.15,0.85,"CMS 2009 Preliminary");
   
   string fileName = fName;
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
   // *** MC ***
   string MC_noise = "OffsetAnalysis_histos_NoiseOnly_STARTUP3X_V8I.root";
   string MC_MB900 = "OffsetAnalysis_histos_MinBias900GeV_STARTUP3X_V8I.root";
   // *** data ***
   string data_ZB = "OffsetAnalysis_histos_ZeroBias_R123596.root";
   string data_CC = "OffsetAnalysis_histos_CollisionCandidates_R123596.root";
   //********************************************
   // make plots
   //********************************************
   overlay_plots1(MC_noise, data_ZB, "p_AvgEinC5", "p_AvgEinC5_NoiseMC_vs_ZB_R123596.png");
   overlay_plots1(MC_noise, data_ZB, "p_AvgpTinC5", "p_AvgpTinC5_NoiseMC_vs_ZB_R123596.png");
   
   overlay_plots2(MC_MB900, data_CC, "p_AvgEinC5", "p_AvgEinC5_MinBias900GeVMC_vs_CC_R123596.png");
   overlay_plots2(MC_MB900, data_CC, "p_AvgpTinC5", "p_AvgpTinC5_MinBias900GeVMC_vs_CC_R123596.png");
}