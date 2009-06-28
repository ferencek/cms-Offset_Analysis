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
   gStyle->SetPadLeftMargin(0.13); // for PAS/AN
//    gStyle->SetPadLeftMargin(0.13); // for Noise-only
   gStyle->SetPadRightMargin(0.07); // for PAS/AN
//    gStyle->SetPadRightMargin(0.07); // for Noise-only
//    gStyle->SetStatFont(42);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetLabelFont(42, "XYZ");
}


void stack_in_cone_contribs(const string& fFile, const double fYmax, const string& fTitleExt, const string& fNameExt) {

//    string title = "<E> in R_{cone}=0.5 " + fTitleExt + ";#eta;<E> [GeV]";
   string title = fTitleExt + ";#eta;<E> [GeV]";
   
   TFile file(fFile.c_str());
   file.cd("offsetAnalysis");
   
   TH1D *p_AEC5EB  = p_AvgEinC5EB->ProjectionX();
   TH1D *p_AEC5EE  = p_AvgEinC5EE->ProjectionX();
   TH1D *p_AEC5HB  = p_AvgEinC5HB->ProjectionX();
   TH1D *p_AEC5HE  = p_AvgEinC5HE->ProjectionX();
   TH1D *p_AEC5HFl = p_AvgEinC5HFl->ProjectionX();
   TH1D *p_AEC5HFs = p_AvgEinC5HFs->ProjectionX();
   //TH1D *p_AEC5HO  = p_AvgEinC5HO->ProjectionX();
   
   p_AEC5EB->SetFillColor(50);
   p_AEC5EE->SetFillColor(8);
   p_AEC5HB->SetFillColor(4);
   p_AEC5HE->SetFillColor(6);
   p_AEC5HFl->SetFillColor(16);
   p_AEC5HFs->SetFillColor(12);
   //p_AEC5HO->SetFillColor(7);
   
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
   
   hs->Add(p_AEC5EB);
   hs->Add(p_AEC5EE);
   hs->Add(p_AEC5HB);
   hs->Add(p_AEC5HE);
   hs->Add(p_AEC5HFl);
   hs->Add(p_AEC5HFs);
   //hs->Add(p_AEC5HO);
   hs->Draw("histsame");
   
   TLegend *legend = new TLegend(.57,.6,.67,.85);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
//    legend->SetTextFont(42);
   legend->AddEntry(p_AEC5EB,"EB","f");
   legend->AddEntry(p_AEC5HB,"HB","f");
   legend->AddEntry(p_AEC5EE,"EE","f");
   legend->AddEntry(p_AEC5HE,"HE","f");
   legend->AddEntry(p_AEC5HFl,"HFl","f");
   legend->AddEntry(p_AEC5HFs,"HFs","f");
   //legend->AddEntry(p_AEC5HO,"HO","f");
   legend->Draw();
   
//    size_t n1 = fNameExt.find("ET");
//    string label1 = "CaloTower E_{T}>" + fNameExt.substr(n1+2,3) + " GeV";
//    
//    TLatex l1;
//    l1.SetTextAlign(12);
//    l1.SetTextSize(0.04);
//    //l1.SetTextColor(kRed+1);
//    l1.SetTextFont(42);
//    l1.SetNDC();
//    l1.DrawLatex(0.12,0.85,fLabel.c_str());
   
   string fileName = "p_AvgEinC5_stacked__" + fNameExt + ".eps";
   
   c->SetGridy();
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
   // *** noise ***
   stack_in_cone_contribs(noise_only_05, 0.18, "Noise-only", "Noise-only_ET0.5");

   // *** pile-up ***
//    stack_in_cone_contribs(onePU_IT_F_05, 2.5, "for 1PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Fixed_ET0.5");
   stack_in_cone_contribs(onePU_IT_P_05, 2.5, "1PU (in-time)", "1PU_InTime_Poisson_ET0.5");
   stack_in_cone_contribs(onePU_F_P_05, 2.5, "1PU (full)", "1PU_Full_Poisson_ET0.5");
//    
//    stack_in_cone_contribs(twoPU_IT_F_05, 5., "for 2PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Fixed_ET0.5");
   stack_in_cone_contribs(twoPU_IT_P_05, 5., "2PU (in-time)", "2PU_InTime_Poisson_ET0.5");
   stack_in_cone_contribs(twoPU_F_P_05, 5., "2PU (full)", "2PU_Full_Poisson_ET0.5");
// 
//    stack_in_cone_contribs(fivePU_IT_F_05, 18., "for 5PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Fixed_ET0.5");
   stack_in_cone_contribs(fivePU_IT_P_05, 18. ,"5PU (in-time)", "5PU_InTime_Poisson_ET0.5");
   stack_in_cone_contribs(fivePU_F_P_05, 18., "5PU (full)", "5PU_Full_Poisson_ET0.5");
}