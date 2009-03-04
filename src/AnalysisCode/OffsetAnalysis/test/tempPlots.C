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
   /*gStyle->SetStatX(.9);
   gStyle->SetStatY(.9);
   gStyle->SetStatW(0.25);
   gStyle->SetStatH(0.15);*/
}

void overlayPlots2(const string& fFile1, const string& fFile2, const string& fTitleExt, const string& fNameExt) {
   
   TProfile *p[5];
    
   TFile file1(fFile1.c_str());
   file1.cd("offsetAnalysis");
   p[0] = p_AvgETinC5; 

   TFile file2(fFile2.c_str());
   file2.cd("offsetAnalysis");
   p[1] = p_AvgpTinC5;
   
   string name = p[1]->GetName();
   string fileName = name + "__" + fNameExt + ".png";
   
   string title = p[1]->GetTitle();
   title = title + " " + fTitleExt;
   p[0]->SetTitle(title.c_str());
   p[0]->GetYaxis()->SetTitle("<p_{T}> [GeV]");
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
     
   p[0]->SetLineWidth(3);
   p[0]->SetLineColor(kRed+1);
   p[0]->Draw("hist");
   p[1]->SetLineWidth(3);
   p[1]->SetLineStyle(7);
   p[1]->SetLineColor(kBlue+1);
   p[1]->Draw("histsame");
   
   TLegend *legend = new TLegend(.15,.7,.45,.8);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->AddEntry(p[0],"14 TeV (CMSSW_2_1_2)","l");
   legend->AddEntry(p[1],"10 TeV (CMSSW_2_1_8)","l");
   legend->Draw();
   
   c->SetGridy();
   c->SaveAs(fileName.c_str());
   
   delete legend;
   delete c;
}

void makePlots() {

   // set ROOT style
   style();
   //********************************************
   // CMSSW_2_1_2 files
   //********************************************
   string noise212_noHO_05 = "path_to_212/root_files/noise__noHO_ET0.5.root";
   string onePU212_noHO_05 = "path_to_212/root_files/1PU_InTime_f__noHO_ET0.5.root";
   //********************************************
   // CMSSW_2_1_8 files
   //********************************************
   string noise_only_05 = "root_files/Noise-only_ET0.5.root";
   string onePU_IT_F_05 = "root_files/1PU_InTime_Fixed_ET0.5.root";
   //********************************************
   // make plots
   //********************************************
   //overlayPlots2(onePU212_noHO_05,onePU_IT_F_05,"for 1PU (in-time,fixed) (IDEAL_V9)","1PU_IT_F_14vs10TeV");
   overlayPlots2(onePU212_noHO_05,onePU_IT_F_05,"for 1PU (in-time,fixed) (IDEAL_V9)","1PU_IT_F_14vs10TeV");
}
