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


void stack_in_cone_contribs(const string& fFile, const string& fTitleExt, const string& fNameExt) {

   string title = "<E> in R_{cone}=0.5 " + fTitleExt + ";#eta;<E> [GeV]";

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
   
   TCanvas *c = new TCanvas("c", "",1120,800);
   c->cd();
   
   THStack *hs = new THStack("hs",title.c_str());
   
   hs->Add(p_AEC5EB);
   hs->Add(p_AEC5EE);
   hs->Add(p_AEC5HB);
   hs->Add(p_AEC5HE);
   hs->Add(p_AEC5HFl);
   hs->Add(p_AEC5HFs);
   //hs->Add(p_AEC5HO);
   hs->Draw("hist");
   
   TLegend *legend = new TLegend(.6,.55,.68,.85);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->SetTextFont(42);
   legend->AddEntry(p_AEC5EB,"EB","f");
   legend->AddEntry(p_AEC5EE,"EE","f");
   legend->AddEntry(p_AEC5HB,"HB","f");
   legend->AddEntry(p_AEC5HE,"HE","f");
   legend->AddEntry(p_AEC5HFl,"HFl","f");
   legend->AddEntry(p_AEC5HFs,"HFs","f");
   //legend->AddEntry(p_AEC5HO,"HO","f");
   legend->Draw();
   
//    size_t n1 = fNameExt.find("ET");
//    string label1 = "CaloTower E_{T}>" + fNameExt.substr(n1+2,3) + " GeV";
//    
//    TLatex l1;
//    l1.SetTextAlign(22);
//    l1.SetTextSize(0.05);
//    //l1.SetTextColor(kRed+1);
//    l1.SetTextFont(42);
//    l1.SetNDC();
//    l1.DrawLatex(0.5,0.3,label1.c_str());
   
   string fileName = "p_AvgEinC5_stacked__" + fNameExt + ".png";
   
   c->SetGridy();
   c->SaveAs(fileName.c_str());

   delete legend;
   delete hs;
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
   // *** noise ***
   stack_in_cone_contribs(noise_only_05, "for Noise-only (CMSSW_2_1_8, IDEAL_V9)", "Noise-only_ET0.5");

   // *** pile-up ***
//    stack_in_cone_contribs(onePU_IT_F_05, "for 1PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Fixed_ET0.5");
//    stack_in_cone_contribs(onePU_IT_P_05, "for 1PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Poisson_ET0.5");
//    stack_in_cone_contribs(onePU_F_P_05, "for 1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_Full_Poisson_ET0.5");
//    
//    stack_in_cone_contribs(twoPU_IT_F_05, "for 2PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Fixed_ET0.5");
//    stack_in_cone_contribs(twoPU_IT_P_05, "for 2PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Poisson_ET0.5");
//    stack_in_cone_contribs(twoPU_F_P_05, "for 2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_Full_Poisson_ET0.5");
// 
//    stack_in_cone_contribs(fivePU_IT_F_05, "for 5PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Fixed_ET0.5");
//    stack_in_cone_contribs(fivePU_IT_P_05, "for 5PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Poisson_ET0.5");
//    stack_in_cone_contribs(fivePU_F_P_05, "for 5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_Full_Poisson_ET0.5");
}