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

void closurePlot(const string& fFile1, const string& fFile2, const string& fFile3, const string& fPlot, const string& fTitleExt, const string& fNameExt, const string& fLegend) { 
 
   TProfile *p[3];
    
   TFile file1(fFile1.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file1.Get("closureAnalysis");
   p[0] = (TProfile*)subDir->Get(fPlot.c_str()); 

   TFile file2(fFile2.c_str());
   subDir = (TDirectoryFile*)file2.Get("closureAnalysis");
   p[1] = (TProfile*)subDir->Get(fPlot.c_str()); 
       
   TFile file3(fFile3.c_str());
   subDir = (TDirectoryFile*)file3.Get("closureAnalysis");
   p[2] = (TProfile*)subDir->Get(fPlot.c_str()); 
   
   string name = p[0]->GetName();
   string fileName = name + "__" + fNameExt + ".png";
   
   string title = p[0]->GetTitle();
   title += fTitleExt;
   p[0]->SetTitle(title.c_str());
   
   double ymin = p[0]->GetMinimum();
   double ymax = p[1]->GetMaximum();
   p[0]->GetYaxis()->SetRangeUser(0.25,0.9);
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
     
   p[0]->SetLineWidth(2);
   //p[0]->SetLineStyle(2);
   //p[0]->SetLineColor(kGray+3);
   p[0]->SetMarkerSize(.8);
   p[0]->SetMarkerStyle(20);
   p[0]->Draw();
   //p[0]->Draw("histcsame");
   p[1]->SetLineWidth(2);
   //p[1]->SetLineStyle(3);
   p[1]->SetLineColor(kRed+1);
   p[1]->SetMarkerSize(.8);
   p[1]->SetMarkerStyle(21);
   p[1]->SetMarkerColor(kRed+1);
   p[1]->Draw("same");
   //p[1]->Draw("histcsame");
   p[2]->SetLineWidth(2);
   p[2]->SetLineColor(kGreen+2);
   p[2]->SetMarkerSize(.8);
   p[2]->SetMarkerStyle(22);
   p[2]->SetMarkerColor(kGreen+2);
   p[2]->Draw("same");
   //p[2]->Draw("histcsame");
   
   TLegend *legend = new TLegend(.15,.77,.37,.89);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->AddEntry(p[0],"QCD no noise","lp");
   legend->AddEntry(p[1],fLegend.c_str(),"lp");
   fLegend += " (corrected)";
   legend->AddEntry(p[2],fLegend.c_str(),"lp");
   legend->Draw();
  
//    size_t n1 = fNameExt.find("ET");
//    string label1 = "E_{T}>" + fNameExt.substr(n1+2,3) + " GeV";
// 
//    TLatex l1;
//    l1.SetTextAlign(22);
//    l1.SetTextSize(0.05);
//    l1.SetTextFont(42);
//    l1.SetNDC();
//    l1.DrawLatex(0.5,0.3,label1.c_str());
   
   c->SetGridy();
   c->SaveAs(fileName.c_str());
   
   delete legend;
   delete c;
}

void dividePlots(const string& fFile0, const string& fFile1, const string& fFile2, const string& fFile3, const string& fFile4, const string& fFile5, const string& fFile6, const string& fPlot, const string& fNameExt) { 
 
   TProfile *p[7];
    
   TFile file0(fFile0.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file0.Get("closureAnalysis");
   p[0] = (TProfile*)subDir->Get(fPlot.c_str());
   
   TFile file1(fFile1.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file1.Get("closureAnalysis");
   p[1] = (TProfile*)subDir->Get(fPlot.c_str()); 

   TFile file2(fFile2.c_str());
   subDir = (TDirectoryFile*)file2.Get("closureAnalysis");
   p[2] = (TProfile*)subDir->Get(fPlot.c_str()); 
       
   TFile file3(fFile3.c_str());
   subDir = (TDirectoryFile*)file3.Get("closureAnalysis");
   p[3] = (TProfile*)subDir->Get(fPlot.c_str());
    
   TFile file4(fFile4.c_str());
   subDir = (TDirectoryFile*)file4.Get("closureAnalysis");
   p[4] = (TProfile*)subDir->Get(fPlot.c_str());
   
   TFile file5(fFile5.c_str());
   subDir = (TDirectoryFile*)file5.Get("closureAnalysis");
   p[5] = (TProfile*)subDir->Get(fPlot.c_str());
   
   TFile file6(fFile6.c_str());
   subDir = (TDirectoryFile*)file6.Get("closureAnalysis");
   p[6] = (TProfile*)subDir->Get(fPlot.c_str());
   
   string title = p[1]->GetTitle();
   
   string name = p[0]->GetName();
   string fileName = name + "__" + fNameExt+ ".png";
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
   
   p[1]->GetYaxis()->SetRangeUser(0.9,1.55);
   p[1]->GetYaxis()->SetTitle("<p_{T}^{calo, PU}/p_{T}^{gen}>/<p_{T}^{calo, no noise}/p_{T}^{gen}>");
   p[1]->GetXaxis()->SetTitle("#eta^{calo}");
   p[1]->SetTitle((title).c_str());
   p[1]->Divide(p[0]);
   p[1]->SetLineWidth(2);
   p[1]->SetLineStyle(3);
   p[1]->SetLineColor(kRed);
   p[1]->SetMarkerSize(.8);
   p[1]->SetMarkerStyle(20);
   p[1]->SetMarkerColor(kRed);
   p[1]->Draw("histlp");

   p[2]->Divide(p[0]);
   p[2]->SetLineWidth(2);
   p[2]->SetLineStyle(7);
   p[2]->SetLineColor(kRed+1);
   p[2]->SetMarkerSize(.8);
   p[2]->SetMarkerStyle(21);
   p[2]->SetMarkerColor(kRed+1);
   p[2]->Draw("histsamelp");
   
   p[3]->Divide(p[0]);
   p[3]->SetLineWidth(2);
   p[3]->SetLineColor(kRed+2);
   p[3]->SetMarkerSize(1.0);
   p[3]->SetMarkerStyle(22);
   p[3]->SetMarkerColor(kRed+2);
   p[3]->Draw("histsamelp");
   
   p[4]->Divide(p[0]);
   p[4]->SetLineWidth(2);
   p[4]->SetLineStyle(3);
   p[4]->SetLineColor(kGreen);
   p[4]->SetMarkerSize(.8);
   p[4]->SetMarkerStyle(20);
   p[4]->SetMarkerColor(kGreen);
   p[4]->Draw("histsamelp");

   p[5]->Divide(p[0]);
   p[5]->SetLineWidth(2);
   p[5]->SetLineStyle(7);
   p[5]->SetLineColor(kGreen+1);
   p[5]->SetMarkerSize(.8);
   p[5]->SetMarkerStyle(21);
   p[5]->SetMarkerColor(kGreen+1);
   p[5]->Draw("histsamelp");
   
   p[6]->GetYaxis()->SetRangeUser(0.9,1.55);
   p[6]->Divide(p[0]);
   p[6]->SetLineWidth(2);
   p[6]->SetLineColor(kGreen+2);
   p[6]->SetMarkerSize(1.0);
   p[6]->SetMarkerStyle(22);
   p[6]->SetMarkerColor(kGreen+2);
   p[6]->Draw("histsamelp");
   
   TLegend *legend = new TLegend(.37,.62,.63,.89);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->AddEntry(p[3],"QCD+5PU","lp");
   legend->AddEntry(p[2],"QCD+2PU","lp");
   legend->AddEntry(p[1],"QCD+1PU","lp");
   legend->AddEntry(p[6],"QCD+5PU (corrected)","lp");
   legend->AddEntry(p[5],"QCD+2PU (corrected)","lp");
   legend->AddEntry(p[4],"QCD+1PU (corrected)","lp");
   legend->Draw();
   
   c->SetGridy();
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
   // *** QCD ***
   string QCDpt15_NN = "root_files/closureAnalysis_QCDpt15_NN_ET0.5.root";
   string QCDpt15_plus_1PU_I_P = "root_files/closureAnalysis_QCDpt15_plus_1PU_InTime_Poisson_ET0.5.root";
   string QCDpt15_plus_1PU_I_P_c_a_l = "root_files/closureAnalysis_QCDpt15_plus_1PU_InTime_Poisson_corrected_Avg_Lumi_ET0.5.root";
   string QCDpt15_plus_1PU_F_P = "root_files/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_1PU_F_P_c = "root_files/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_corrected_ET0.5.root";
   string QCDpt15_plus_1PU_F_P_c_a_l = "root_files/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_corrected_Avg_Lumi_ET0.5.root";
   string QCDpt15_plus_2PU_I_P = "root_files/closureAnalysis_QCDpt15_plus_2PU_InTime_Poisson_ET0.5.root";
   string QCDpt15_plus_2PU_I_P_c_a_l = "root_files/closureAnalysis_QCDpt15_plus_2PU_InTime_Poisson_corrected_Avg_Lumi_ET0.5.root";
   string QCDpt15_plus_2PU_F_P = "root_files/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_2PU_F_P_c = "root_files/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_corrected_ET0.5.root";
   string QCDpt15_plus_2PU_F_P_c_a_l = "root_files/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_corrected_Avg_Lumi_ET0.5.root";
   string QCDpt15_plus_5PU_I_P = "root_files/closureAnalysis_QCDpt15_plus_5PU_InTime_Poisson_ET0.5.root";
   string QCDpt15_plus_5PU_I_P_c_a_l = "root_files/closureAnalysis_QCDpt15_plus_5PU_InTime_Poisson_corrected_Avg_Lumi_ET0.5.root";
   string QCDpt15_plus_5PU_F_P = "root_files/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_5PU_F_P_c = "root_files/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_corrected_ET0.5.root";
   string QCDpt15_plus_5PU_F_P_c_a_l = "root_files/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_corrected_Avg_Lumi_ET0.5.root";
   //********************************************
   // make plots
   //********************************************
   // *** QCD+1PU ***

//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_1PU_c_05, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_1PU_c_05, "p_CaloJetpToverGenJetpT_pT_B", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_1PU_c_05, "p_CaloJetpToverGenJetpT_pT_E", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_1PU_c_05, "p_CaloJetpToverGenJetpT_pT_F", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_1PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT15_20", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_1PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT20_25", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_1PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT25_30", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_1PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT30_40", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_1PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT40_50", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_1PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT50_70", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_1PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT70_100", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");

   closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");

   // *** QCD+2PU ***
   
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_2PU_05, QCDpt15_plus_2PU_c_05, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_2PU_05, QCDpt15_plus_2PU_c_05, "p_CaloJetpToverGenJetpT_pT_B", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_2PU_05, QCDpt15_plus_2PU_c_05, "p_CaloJetpToverGenJetpT_pT_E", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_2PU_05, QCDpt15_plus_2PU_c_05, "p_CaloJetpToverGenJetpT_pT_F", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_2PU_05, QCDpt15_plus_2PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT15_20", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_2PU_05, QCDpt15_plus_2PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT20_25", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_2PU_05, QCDpt15_plus_2PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT25_30", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_2PU_05, QCDpt15_plus_2PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT30_40", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_2PU_05, QCDpt15_plus_2PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT40_50", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_2PU_05, QCDpt15_plus_2PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT50_70", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_2PU_05, QCDpt15_plus_2PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT70_100", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");

   closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");

   // *** QCD+5PU ***
   
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_5PU_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_5PU_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_pT_B", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_5PU_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_pT_E", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_5PU_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_pT_F", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_5PU_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT15_20", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_5PU_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT20_25", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_5PU_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT25_30", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_5PU_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT30_40", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_5PU_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT40_50", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_5PU_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT50_70", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN_05, QCDpt15_plus_5PU_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT70_100", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");

   closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");

   // divide plots
   
//    dividePlots(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_2PU_05, QCDpt15_plus_5PU_05, QCDpt15_plus_1PU_c_05, QCDpt15_plus_2PU_c_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT15_20", "QCDnPUoverQCDNN");
//    dividePlots(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_2PU_05, QCDpt15_plus_5PU_05, QCDpt15_plus_1PU_c_05, QCDpt15_plus_2PU_c_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT25_30", "QCDnPUoverQCDNN");
//    dividePlots(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_2PU_05, QCDpt15_plus_5PU_05, QCDpt15_plus_1PU_c_05, QCDpt15_plus_2PU_c_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT30_40", "QCDnPUoverQCDNN");

   dividePlots(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "QCDnPUIPoverQCDNN");
   dividePlots(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "QCDnPUIPoverQCDNN");
   dividePlots(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "QCDnPUIPoverQCDNN");

}