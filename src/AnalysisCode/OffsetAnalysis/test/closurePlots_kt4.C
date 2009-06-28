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
   gStyle->SetPadLeftMargin(0.12); // for PAS/AN
   gStyle->SetPadRightMargin(0.08); // for PAS/AN
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
   string fileName = name + "__" + fNameExt + ".eps";
   
   string title = p[0]->GetTitle();
   title = fTitleExt + ", " + title;
   p[0]->SetTitle(title.c_str());
   
//    double ymin = p[0]->GetMinimum();
//    double ymax = p[1]->GetMaximum();
   p[0]->GetYaxis()->SetRangeUser(0.28,0.88);
   p[0]->GetXaxis()->SetTitleSize(0.05);
   p[0]->GetYaxis()->SetTitle("R_{E}=<E^{calo}/E^{gen}>");
   p[0]->GetYaxis()->SetTitleSize(0.05);
//    p[0]->SetTitleOffset(0.85.,"X"); // for p_T^{gen} on x-axis
   p[0]->SetTitleOffset(1.15,"Y");
   
//    TCanvas *c = new TCanvas("c","",1120,800);
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
     
   p[0]->SetLineWidth(3);
   //p[0]->SetLineStyle(2);
   //p[0]->SetLineColor(kGray+3);
   p[0]->SetMarkerSize(1.);
   p[0]->SetMarkerStyle(20);
   p[0]->Draw();
   //p[0]->Draw("histcsame");
   p[1]->SetLineWidth(3);
   p[1]->SetLineStyle(7);
   p[1]->SetLineColor(kRed+1);
   p[1]->SetMarkerSize(1.);
   p[1]->SetMarkerStyle(21);
   p[1]->SetMarkerColor(kRed+1);
   p[1]->Draw("same");
   //p[1]->Draw("histcsame");
   p[2]->SetLineWidth(3);
   p[2]->SetLineStyle(3);
   p[2]->SetLineColor(kGreen+2);
   p[2]->SetMarkerSize(1.);
   p[2]->SetMarkerStyle(22);
   p[2]->SetMarkerColor(kGreen+2);
   p[2]->Draw("same");
   //p[2]->Draw("histcsame");
   
   TLegend *legend = new TLegend(.15,.7,.6,.85);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->AddEntry(p[1],fLegend.c_str(),"lp");
   fLegend += " (corrected)";
   legend->AddEntry(p[2],fLegend.c_str(),"lp");
   legend->AddEntry(p[0],"QCD no noise/no pile-up","lp");
   legend->Draw();
  
//    size_t n1 = fNameExt.find("ET");
//    string label1 = "E_{T}>" + fNameExt.substr(n1+2,3) + " GeV";
// 
//    TLatex l1;
//    l1.SetTextAlign(12);
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

void dividePlotsPAS(const string& fFile0, const string& fFile1, const string& fFile2, const string& fFile3, const string& fFile4, const string& fFile5, const string& fFile6, const string& fPlot, const string& fLabel, const string& fNameExt) { 
 
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
   string fileName = name + "__" + fNameExt;
   
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
   
   p[1]->GetYaxis()->SetRangeUser(0.95,1.65);
   if ( fPlot.find("p_CaloJetEoverGenJetE") != string::npos ) p[1]->GetYaxis()->SetTitle("R_{E}/R_{E}^{no offset}");
   else p[1]->GetYaxis()->SetTitle("R_{p_{T}}/R_{p_{T}}^{no offset}");
   p[1]->GetXaxis()->SetTitleSize(0.05);
   p[1]->GetYaxis()->SetTitleSize(0.05);
//    p[1]->GetYaxis()->SetLabelSize(0.02);
   
   p[1]->GetXaxis()->SetTitle("#eta");
   p[1]->SetTitle((title).c_str());
   p[1]->SetTitleOffset(1.,"X");
   p[1]->SetTitleOffset(1.15,"Y");
   p[1]->Divide(p[0]);
   p[1]->SetLineWidth(2);
   p[1]->SetLineStyle(3);
   p[1]->SetLineColor(kRed);
   p[1]->SetMarkerSize(.8);
   p[1]->SetMarkerStyle(20);
   p[1]->SetMarkerColor(kRed);
//    p[1]->GetYaxis()->SetNdivisions(40);
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
   p[4]->SetMarkerStyle(24);
   p[4]->SetMarkerColor(kGreen);
   p[4]->Draw("histsamelp");

   p[5]->Divide(p[0]);
   p[5]->SetLineWidth(2);
   p[5]->SetLineStyle(7);
   p[5]->SetLineColor(kGreen+1);
   p[5]->SetMarkerSize(.8);
   p[5]->SetMarkerStyle(25);
   p[5]->SetMarkerColor(kGreen+1);
   p[5]->Draw("histsamelp");

   p[6]->Divide(p[0]);
   p[6]->SetLineWidth(2);
   p[6]->SetLineColor(kGreen+2);
   p[6]->SetMarkerSize(1.0);
   p[6]->SetMarkerStyle(26);
   p[6]->SetMarkerColor(kGreen+2);
   p[6]->Draw("histsamelp");
   
   TLegend *legend = new TLegend(.34,.55,.7,.77);
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
   
   TLatex l;
   l.SetTextAlign(12);
   l.SetTextSize(0.04);
   l.SetTextFont(62);
   l.SetNDC();
//    l.DrawLatex(0.14,0.85,"CMS Preliminary");
   
   string label = fLabel + ", " + p[1]->GetTitle();
   
   TLatex l2;
   l2.SetTextAlign(12);
   l2.SetTextSize(0.03);
   l2.SetTextFont(62);
   l2.SetNDC();
   l2.DrawLatex(0.34,0.795,label.c_str());
   
   c->SetGridy(20);
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
   string QCDpt15_NN = "root_files/closureAnalysis_kt4_QCDpt15_NN_ET0.5.root";
   string QCDpt15_plus_1PU_IT_P = "root_files/closureAnalysis_kt4_QCDpt15_plus_1PU_InTime_Poisson_ET0.5.root";
   string QCDpt15_plus_1PU_IT_P_c_a_l = "root_files/closureAnalysis_kt4_QCDpt15_plus_1PU_InTime_Poisson_corrected_Avg_Lumi_ET0.5.root";
   string QCDpt15_plus_1PU_F_P = "root_files/closureAnalysis_kt4_QCDpt15_plus_1PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_1PU_F_P_c_a_l = "root_files/closureAnalysis_kt4_QCDpt15_plus_1PU_Full_Poisson_corrected_Avg_Lumi_ET0.5.root";
   string QCDpt15_plus_2PU_IT_P = "root_files/closureAnalysis_kt4_QCDpt15_plus_2PU_InTime_Poisson_ET0.5.root";
   string QCDpt15_plus_2PU_IT_P_c_a_l = "root_files/closureAnalysis_kt4_QCDpt15_plus_2PU_InTime_Poisson_corrected_Avg_Lumi_ET0.5.root";
   string QCDpt15_plus_2PU_F_P = "root_files/closureAnalysis_kt4_QCDpt15_plus_2PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_2PU_F_P_c_a_l = "root_files/closureAnalysis_kt4_QCDpt15_plus_2PU_Full_Poisson_corrected_Avg_Lumi_ET0.5.root";
   string QCDpt15_plus_5PU_IT_P = "root_files/closureAnalysis_kt4_QCDpt15_plus_5PU_InTime_Poisson_ET0.5.root";
   string QCDpt15_plus_5PU_IT_P_c_a_l = "root_files/closureAnalysis_kt4_QCDpt15_plus_5PU_InTime_Poisson_corrected_Avg_Lumi_ET0.5.root";
   string QCDpt15_plus_5PU_F_P = "root_files/closureAnalysis_kt4_QCDpt15_plus_5PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_5PU_F_P_c_a_l = "root_files/closureAnalysis_kt4_QCDpt15_plus_5PU_Full_Poisson_corrected_Avg_Lumi_ET0.5.root";
   //********************************************
   // make plots
   //********************************************
   // *** QCD+1PU ***
   
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");

//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
   
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_60", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT60_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_IT_P, QCDpt15_plus_1PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_pT_B", "In-time pile-up", "QCD_plus_1PU_IT_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_IT_P, QCDpt15_plus_1PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_pT_E", "In-time pile-up", "QCD_plus_1PU_IT_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_IT_P, QCDpt15_plus_1PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_pT_F", "In-time pile-up", "QCD_plus_1PU_IT_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_IT_P, QCDpt15_plus_1PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT25_40", "In-time pile-up", "QCD_plus_1PU_IT_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT40_60", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT60_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_I_P", "QCD+1PU");
//    
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_60", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT60_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_pT_B", "Full pile-up", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_pT_E", "Full pile-up", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_pT_F", "Full pile-up", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT25_40", "Full pile-up", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT40_60", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT60_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU_F_P", "QCD+1PU");

   // *** QCD+2PU ***
   
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");

//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
   
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_60", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT60_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_IT_P, QCDpt15_plus_2PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_pT_B", "In-time pile-up", "QCD_plus_2PU_IT_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_IT_P, QCDpt15_plus_2PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_pT_E", "In-time pile-up", "QCD_plus_2PU_IT_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_IT_P, QCDpt15_plus_2PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_pT_F", "In-time pile-up", "QCD_plus_2PU_IT_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_IT_P, QCDpt15_plus_2PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT25_40", "In-time pile-up", "QCD_plus_2PU_IT_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT40_60", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_I_P, QCDpt15_plus_2PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT60_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_I_P", "QCD+2PU");
//    
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_60", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT60_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_pT_B", "Full pile-up", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_pT_E", "Full pile-up", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_pT_F", "Full pile-up", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT25_40", "Full pile-up", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT40_60", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT60_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU_F_P", "QCD+2PU");

   // *** QCD+5PU ***
   
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");

//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
   
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_60", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT60_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_IT_P, QCDpt15_plus_5PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_pT_B", "In-time pile-up", "QCD_plus_5PU_IT_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_IT_P, QCDpt15_plus_5PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_pT_E", "In-time pile-up", "QCD_plus_5PU_IT_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_IT_P, QCDpt15_plus_5PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_pT_F", "In-time pile-up", "QCD_plus_5PU_IT_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_IT_P, QCDpt15_plus_5PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT25_40", "In-time pile-up", "QCD_plus_5PU_IT_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT40_60", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_I_P, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT60_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_I_P", "QCD+5PU");
//    
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_60", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT60_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_pT_B", "Full pile-up", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_pT_E", "Full pile-up", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_pT_F", "Full pile-up", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT25_40", "Full pile-up", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT40_60", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT60_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_F_P", "QCD+5PU");

   // divide plots
   
//    dividePlots(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_2PU_05, QCDpt15_plus_5PU_05, QCDpt15_plus_1PU_c_05, QCDpt15_plus_2PU_c_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT15_20", "QCDnPUoverQCDNN");
//    dividePlots(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_2PU_05, QCDpt15_plus_5PU_05, QCDpt15_plus_1PU_c_05, QCDpt15_plus_2PU_c_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT25_30", "QCDnPUoverQCDNN");
//    dividePlots(QCDpt15_NN_05, QCDpt15_plus_1PU_05, QCDpt15_plus_2PU_05, QCDpt15_plus_5PU_05, QCDpt15_plus_1PU_c_05, QCDpt15_plus_2PU_c_05, QCDpt15_plus_5PU_c_05, "p_CaloJetpToverGenJetpT_eta_pT30_40", "QCDnPUoverQCDNN");

//    dividePlots(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "QCDnPUIPoverQCDNN");
//    dividePlots(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "QCDnPUIPoverQCDNN");
//    dividePlots(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "QCDnPUIPoverQCDNN");

//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "QCDnPUIPoverQCDNN.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "QCDnPUIPoverQCDNN.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_40", "QCDnPUIPoverQCDNN.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_60", "QCDnPUIPoverQCDNN.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT60_100", "QCDnPUIPoverQCDNN.png");
//    
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT15_20", "QCDnPUIPoverQCDNN.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT20_25", "QCDnPUIPoverQCDNN.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_IT_P, QCDpt15_plus_2PU_IT_P, QCDpt15_plus_5PU_IT_P, QCDpt15_plus_1PU_IT_P_c_a_l, QCDpt15_plus_2PU_IT_P_c_a_l, QCDpt15_plus_5PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT25_40", "In-time PU", "QCDnPUIPoverQCDNN.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_IT_P, QCDpt15_plus_2PU_IT_P, QCDpt15_plus_5PU_IT_P, QCDpt15_plus_1PU_IT_P_c_a_l, QCDpt15_plus_2PU_IT_P_c_a_l, QCDpt15_plus_5PU_IT_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT40_60", "In-time PU", "QCDnPUIPoverQCDNN.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_I_P, QCDpt15_plus_2PU_I_P, QCDpt15_plus_5PU_I_P, QCDpt15_plus_1PU_I_P_c_a_l, QCDpt15_plus_2PU_I_P_c_a_l, QCDpt15_plus_5PU_I_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT60_100", "QCDnPUIPoverQCDNN.png");
//    
//    
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_2PU_F_P, QCDpt15_plus_5PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "QCDnPUFPoverQCDNN.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_2PU_F_P, QCDpt15_plus_5PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "QCDnPUFPoverQCDNN.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_2PU_F_P, QCDpt15_plus_5PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT25_40", "QCDnPUFPoverQCDNN.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_2PU_F_P, QCDpt15_plus_5PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT40_60", "QCDnPUFPoverQCDNN.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_2PU_F_P, QCDpt15_plus_5PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetpToverGenJetpT_eta_pT60_100", "QCDnPUFPoverQCDNN.png");
//    
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_2PU_F_P, QCDpt15_plus_5PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT15_20", "QCDnPUFPoverQCDNN.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_2PU_F_P, QCDpt15_plus_5PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT20_25", "QCDnPUFPoverQCDNN.png");
   dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_2PU_F_P, QCDpt15_plus_5PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT25_40", "Full PU", "QCDnPUFPoverQCDNN_kt4.png");
   dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_2PU_F_P, QCDpt15_plus_5PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT40_60", "Full PU", "QCDnPUFPoverQCDNN_kt4.png");
//    dividePlotsPAS(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_2PU_F_P, QCDpt15_plus_5PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_a_l, "p_CaloJetEoverGenJetE_eta_pT60_100", "QCDnPUFPoverQCDNN.png");

}