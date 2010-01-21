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


void overlay_plots(const string& fFile0, const string& fFile1, const double fYmax, const string& fPlot, const string& fLegendEnt1, const string& fLegendEnt2, const string& fName) {
  
   TProfile *p[2];
 
   TFile file0(fFile0.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file0.Get("offsetAnalysis");
   p[0] = (TProfile*)subDir->Get(fPlot.c_str());

   TFile file1(fFile1.c_str());
   subDir = (TDirectoryFile*)file1.Get("offsetAnalysis");
   p[1] = (TProfile*)subDir->Get(fPlot.c_str()); 

   p[0]->SetTitleOffset(1.5,"Y");
   p[0]->GetXaxis()->SetTitleSize(0.04);
   p[0]->GetYaxis()->SetTitleSize(0.04);
   
   double ymax = ((p[0]->GetMaximum())>(p[1]->GetMaximum())) ? p[0]->GetMaximum() : p[1]->GetMaximum();
   
   p[0]->GetYaxis()->SetRangeUser(0.,fYmax);
   
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
  
   p[0]->SetLineWidth(3);
   p[0]->SetLineColor(kRed);
   p[0]->SetFillColor(kRed);
   p[0]->Draw("hist");
   p[1]->SetLineWidth(3);
   p[1]->SetLineColor(kBlack);
   p[1]->SetMarkerStyle(20);
   p[1]->SetMarkerColor(kBlack);
   p[1]->Draw("sames");
   
   TLegend *legend = new TLegend(.57,.77,.9,.87);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
//    legend->SetFillStyle(0);
   legend->SetMargin(0.12);
   legend->AddEntry(p[0],fLegendEnt1.c_str(),"l");
   legend->AddEntry(p[1],fLegendEnt2.c_str(),"l");
   legend->Draw();
   
   TLatex l;
   l.SetTextAlign(12);
   l.SetTextSize(0.04);
   l.SetTextFont(62);
   l.SetNDC();
   l.DrawLatex(0.15,0.85,"CMS 2009 Preliminary");
   
   string fileName = fName;
   c->SetGridy();
   c->SaveAs(fileName.c_str());
   
   delete legend;
   delete c;
}

void stack_in_cone_contribs(const string& fFile, const double fYmax, const string& fTitleExt, const string& fNameExt) {

   string title = "<E> in R_{cone}=0.5 -- "+ fTitleExt +";#eta;<E> [GeV]";
   
   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("offsetAnalysis");
   
   TProfile *p_AEC5EB  = (TProfile*)subDir->Get("p_AvgEinC5EB");
   TProfile *p_AEC5EE  = (TProfile*)subDir->Get("p_AvgEinC5EE");
   TProfile *p_AEC5HB  = (TProfile*)subDir->Get("p_AvgEinC5HB");
   TProfile *p_AEC5HE  = (TProfile*)subDir->Get("p_AvgEinC5HE");
   TProfile *p_AEC5HFl = (TProfile*)subDir->Get("p_AvgEinC5HFl");
   TProfile *p_AEC5HFs = (TProfile*)subDir->Get("p_AvgEinC5HFs");
//    TProfile *p_AEC5HO  = (TProfile*)subDir->Get("p_AvgEinC5HO");
   
   TH1D *h_AEC5EB  = p_AEC5EB->ProjectionX();
   TH1D *h_AEC5EE  = p_AEC5EE->ProjectionX();
   TH1D *h_AEC5HB  = p_AEC5HB->ProjectionX();
   TH1D *h_AEC5HE  = p_AEC5HE->ProjectionX();
   TH1D *h_AEC5HFl = p_AEC5HFl->ProjectionX();
   TH1D *h_AEC5HFs = p_AEC5HFs->ProjectionX();
   //TH1D *h_AEC5HO  = p_AEC5HO->ProjectionX();
   
   h_AEC5EB->SetFillColor(50);
   h_AEC5EE->SetFillColor(8);
   h_AEC5HB->SetFillColor(4);
   h_AEC5HE->SetFillColor(6);
   h_AEC5HFl->SetFillColor(16);
   h_AEC5HFs->SetFillColor(12);
   //h_AEC5HO->SetFillColor(7);
   
//    TCanvas *c = new TCanvas("c", "",1120,800);
   TCanvas *c = new TCanvas("c", "",800,800);
   c->cd();
   
   TH2F *h_bg = new TH2F("h_bg",title.c_str(),100,-5.,5.,100,0.,fYmax);
   h_bg->GetXaxis()->SetTitleSize(0.05);
   h_bg->GetYaxis()->SetTitleSize(0.05);
   h_bg->SetTitleOffset(1.,"X");
   h_bg->SetTitleOffset(1.3,"Y");
   h_bg->Draw();
   
   THStack *hs = new THStack("hs","");
   
   hs->Add(h_AEC5EB);
   hs->Add(h_AEC5EE);
   hs->Add(h_AEC5HB);
   hs->Add(h_AEC5HE);
   hs->Add(h_AEC5HFl);
   hs->Add(h_AEC5HFs);
   //hs->Add(h_AEC5HO);
   hs->Draw("histsame");
   
   TLegend *legend = new TLegend(.65,.6,.75,.85);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
//    legend->SetFillStyle(0);
//    legend->SetTextFont(42);
   legend->AddEntry(h_AEC5EB,"EB","f");
   legend->AddEntry(h_AEC5HB,"HB","f");
   legend->AddEntry(h_AEC5EE,"EE","f");
   legend->AddEntry(h_AEC5HE,"HE","f");
   legend->AddEntry(h_AEC5HFl,"HFl","f");
   legend->AddEntry(h_AEC5HFs,"HFs","f");
   //legend->AddEntry(h_AEC5HO,"HO","f");
   legend->Draw();
   
   string fileName = "h_AvgEinC5_stacked_" + fNameExt;
   
   c->SetGridy();
   gPad->Modified();
   gPad->Update();
   c->SaveAs(fileName.c_str());

   delete legend;
   delete hs;
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
   string MC_MB2360 = "OffsetAnalysis_histos_MinBias2360GeV_STARTUP3X_V8D.root";
   // *** data ***
   string data_ZB_900 = "OffsetAnalysis_histos_ZeroBias_R124022_900GeV.root";
   string data_Coll_900 = "OffsetAnalysis_histos_Collisions_R124022_900GeV.root";
   string data_Coll_2360 = "OffsetAnalysis_histos_Collisions_R124120_2360GeV.root";
   //********************************************
   // make plots
   //********************************************
   overlay_plots(MC_noise, data_ZB_900, 0.365, "p_AvgEinC5", "NoiseOnly MC, STARTUP3X_V8I","ZeroBias, Run 124022", "p_AvgEinC5_NoiseMC_vs_ZB_R124022_900GeV.png");
   overlay_plots(MC_noise, data_ZB_900, 0.365, "p_AvgpTinC5", "NoiseOnly MC, STARTUP3X_V8I","ZeroBias, Run 124022", "p_AvgpTinC5_NoiseMC_vs_ZB_R124022_900GeV.png");
   stack_in_cone_contribs(MC_noise, 0.365, "NoiseOnly MC, STARTUP3X_V8I", "Noise_MC.png");
   stack_in_cone_contribs(data_ZB_900, 0.365, "ZeroBias, Run 124022, 900 GeV", "ZB_R124022_900GeV.png");
   
   overlay_plots(MC_MB900, data_Coll_900, 2.2, "p_AvgEinC5", "MinBias900GeV MC, STARTUP3X_V8I","Collisions, Run 124022", "p_AvgEinC5_MinBias900GeVMC_vs_Coll_R124022_900GeV.png");
   overlay_plots(MC_MB900, data_Coll_900, 0.41, "p_AvgpTinC5", "MinBias900GeV MC, STARTUP3X_V8I","Collisions, Run 124022", "p_AvgpTinC5_MinBias900GeVMC_vs_Coll_R124022_900GeV.png");
   stack_in_cone_contribs(MC_MB900, 2.2, "MinBias900GeV MC, STARTUP3X_V8I", "MinBias900GeV_MC.png");
   stack_in_cone_contribs(data_Coll_900, 2.2, "Collisions, Run 124022, 900 GeV", "Coll_R124022_900GeV.png");
   
   overlay_plots(MC_MB2360, data_Coll_2360, 4.2, "p_AvgEinC5", "MinBias2360GeV MC, STARTUP3X_V8D","Collisions, Run 124120", "p_AvgEinC5_MinBias2360GeVMC_vs_Coll_R124120_2360GeV.png");
   overlay_plots(MC_MB2360, data_Coll_2360, 0.5, "p_AvgpTinC5", "MinBias2360GeV MC, STARTUP3X_V8D","Collisions, Run 124120", "p_AvgpTinC5_MinBias2360GeVMC_vs_Coll_R124120_2360GeV.png");
   stack_in_cone_contribs(MC_MB2360, 4.2, "MinBias2360GeV MC, STARTUP3X_V8D", "MinBias2360GeV_MC.png");
   stack_in_cone_contribs(data_Coll_2360, 4.2, "Collisions, Run 124120, 2360 GeV", "Coll_R124120_2360GeV.png");
}