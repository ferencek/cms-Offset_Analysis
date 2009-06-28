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

void closurePlot(const string& fFile0, const string& fFile1, const string& fFile2, const string& fFile3, const string& fPlot, const string& fTitleExt, const string& fNameExt, const string& fLegend) { 
 
   TProfile *p[4];
    
   TFile file0(fFile0.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file0.Get("closureAnalysis");
   p[0] = (TProfile*)subDir->Get(fPlot.c_str()); 

   TFile file1(fFile1.c_str());
   subDir = (TDirectoryFile*)file1.Get("closureAnalysis");
   p[1] = (TProfile*)subDir->Get(fPlot.c_str()); 
       
   TFile file2(fFile2.c_str());
   subDir = (TDirectoryFile*)file2.Get("closureAnalysis");
   p[2] = (TProfile*)subDir->Get(fPlot.c_str());
   
   TFile file3(fFile3.c_str());
   subDir = (TDirectoryFile*)file3.Get("closureAnalysis");
   p[3] = (TProfile*)subDir->Get(fPlot.c_str());
   
   string name = p[3]->GetName();
   string fileName = name + "__" + fNameExt + ".png";
   
   string title = p[3]->GetTitle();
   p[3]->SetTitle((title + fTitleExt).c_str());
   
   p[3]->GetYaxis()->SetRangeUser(0.25,0.95);
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
   
   p[3]->SetLineWidth(2);
   p[3]->SetLineColor(kBlue);
   p[3]->SetMarkerSize(.8);
   p[3]->SetMarkerStyle(26);
   p[3]->SetMarkerColor(kBlue);
   p[3]->Draw();
   p[0]->SetLineWidth(2);
   //p[0]->SetLineStyle(2);
   //p[0]->SetLineColor(kGray+3);
   p[0]->SetMarkerSize(.8);
   p[0]->SetMarkerStyle(20);
   p[0]->Draw("same");
   p[1]->SetLineWidth(2);
   //p[1]->SetLineStyle(3);
   p[1]->SetLineColor(kRed+1);
   p[1]->SetMarkerSize(.8);
   p[1]->SetMarkerStyle(21);
   p[1]->SetMarkerColor(kRed+1);
   p[1]->Draw("same");
   p[2]->SetLineWidth(2);
   p[2]->SetLineColor(kGreen+2);
   p[2]->SetMarkerSize(.8);
   p[2]->SetMarkerStyle(22);
   p[2]->SetMarkerColor(kGreen+2);
   p[2]->Draw("same");
   
   TLegend *legend = new TLegend(.15,.74,.44,.89);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->AddEntry(p[1],fLegend.c_str(),"lp");
   legend->AddEntry(p[3],(fLegend + " (corrected: PV, Lumi)").c_str(),"lp");
   legend->AddEntry(p[2],(fLegend + " (corrected: Avg, Lumi)").c_str(),"lp");
   legend->AddEntry(p[0],"QCD no offset","lp");
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

void pvClosurePlot(const string& fFile0, const string& fFile1, const string& fFile2, const string& fFile3, const Int_t fMaxNPVs, const string& fPlot, const string& fTitleExt, const string& fNameExt, const string& fLegend) { 
 
   TProfile *p[4];
    
   TFile file0(fFile0.c_str());
   TDirectoryFile *dir = (TDirectoryFile*)file0.Get("closureAnalysis");
   TDirectoryFile *subDir;
   p[0] = (TProfile*)dir->Get(fPlot.c_str()); 

   TFile file1(fFile1.c_str());
   
   TFile file2(fFile2.c_str());
   dir = (TDirectoryFile*)file2.Get("closureAnalysis");
   p[2] = (TProfile*)dir->Get(fPlot.c_str());
      
   TFile file3(fFile3.c_str());
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
   
   for (int i=1; i<= fMaxNPVs; i++) {
      char profileName[1024];
      sprintf(profileName, (fPlot + "_NPV%i").c_str(), i);
      
      char npv[1024];
      sprintf(npv, "NPV%i", i);
      
      dir = (TDirectoryFile*)file1.Get("closureAnalysis");
      subDir = (TDirectoryFile*)dir->Get("PVDependent");
      p[1] = (TProfile*)subDir->Get(profileName);
       
      dir = (TDirectoryFile*)file3.Get("closureAnalysis");
      subDir = (TDirectoryFile*)dir->Get("PVDependent");
      p[3] = (TProfile*)subDir->Get(profileName);
   
      string name = p[1]->GetName();
      string fileName = name + "__" + fNameExt + ".png";
      string title = p[1]->GetTitle();
      p[1]->SetTitle((title + fTitleExt).c_str());
      p[1]->GetYaxis()->SetRangeUser(0.25,0.95);
      
      p[1]->SetLineWidth(2);
      p[1]->SetLineColor(kRed+1);
      p[1]->SetMarkerSize(.8);
      p[1]->SetMarkerStyle(21);
      p[1]->SetMarkerColor(kRed+1);
      p[1]->Draw();
      p[2]->SetLineWidth(2);
      p[2]->SetLineColor(kGreen+2);
      p[2]->SetMarkerSize(.8);
      p[2]->SetMarkerStyle(22);
      p[2]->SetMarkerColor(kGreen+2);
      p[2]->Draw("same");
      p[3]->SetLineWidth(2);
      p[3]->SetLineColor(kBlue);
      p[3]->SetMarkerSize(.8);
      p[3]->SetMarkerStyle(26);
      p[3]->SetMarkerColor(kBlue);
      p[3]->Draw("same");
      p[0]->SetLineWidth(2);
      //p[0]->SetLineColor(kGray+3);
      p[0]->SetMarkerSize(.8);
      p[0]->SetMarkerStyle(20);
      p[0]->Draw("same");
      
      TLegend *legend = new TLegend(.15,.74,.44,.89);
      legend->SetBorderSize(1);
      legend->SetFillColor(0);
      //legend->SetFillStyle(0);
      legend->AddEntry(p[1],(fLegend + " (" + npv +")").c_str(),"lp");
      legend->AddEntry(p[2],(fLegend + " (corrected: Avg, Lumi)").c_str(),"lp");
      legend->AddEntry(p[3],(fLegend + " (" + npv + ", corrected: PV, Lumi)").c_str(),"lp");
      legend->AddEntry(p[0],"QCD no offset","lp");
      legend->Draw();
      
      c->SetGridy();
      c->SaveAs(fileName.c_str());
      
      delete legend;
   }

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
   
   string name = p[0]->GetName();
   string fileName = name + "__" + fNameExt+ ".png";
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
   
   p[1]->GetYaxis()->SetRangeUser(0.9,1.55);
   p[1]->GetYaxis()->SetTitle("(QCD+nPU)/(QCD no noise)");
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

void pvDividePlots(const string& fFile0, const string& fFile1, const string& fFile2, const Int_t fMaxNPVs, const string& fPlot, const string& fNameExt, const string& fLegend) { 
 
   TProfile *p[fMaxNPVs+1];
   TProfile *pc[fMaxNPVs+1];
    
   TFile file0(fFile0.c_str());
   TDirectoryFile *dir = (TDirectoryFile*)file0.Get("closureAnalysis");
   TDirectoryFile *subDir;
   p[0] = (TProfile*)dir->Get(fPlot.c_str());
   
   TFile file1(fFile1.c_str());

   TFile file2(fFile2.c_str());
   
   string name = p[0]->GetName();
   string fileName = name + "__" + fNameExt+ ".png";
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
   
   TLegend *legend = new TLegend(.37,.62,.63,.89);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   
   for (int i=1; i<=fMaxNPVs; i++) {
      char profileName[1024];
      sprintf(profileName, (fPlot + "_NPV%i").c_str(), i);
      
      char npv[1024];
      sprintf(npv, "NPV%i", i);
      
      dir = (TDirectoryFile*)file1.Get("closureAnalysis");
      subDir = (TDirectoryFile*)dir->Get("PVDependent");
      p[i] = (TProfile*)subDir->Get(profileName);
      
      if (i==1) p[i]->GetYaxis()->SetRangeUser(0.85,1.65);
      if (i==1) p[i]->GetYaxis()->SetTitle("<p_{T}^{calo, PU}/p_{T}^{gen}>/<p_{T}^{calo, no noise}/p_{T}^{gen}>");
      
      p[i]->Divide(p[0]);
      p[i]->SetLineWidth(2);
      p[i]->SetLineStyle(1+fMaxNPVs-i);
      p[i]->SetLineColor(kRed+3-fMaxNPVs+i);
      p[i]->SetMarkerSize(.8);
      p[i]->SetMarkerStyle(19+i);
      p[i]->SetMarkerColor(kRed+3-fMaxNPVs+i);
      if ( i == 1 ) p[i]->Draw("histlp");
      else p[i]->Draw("histsamelp");
      
      legend->AddEntry(p[i],(fLegend + " (" + npv +")").c_str(),"lp");
   }
   
   for (int i=1; i<=fMaxNPVs; i++) {
      char profileName[1024];
      sprintf(profileName, (fPlot + "_NPV%i").c_str(), i);
      
      char npv[1024];
      sprintf(npv, "NPV%i", i);
      
      dir = (TDirectoryFile*)file2.Get("closureAnalysis");
      subDir = (TDirectoryFile*)dir->Get("PVDependent");
      pc[i] = (TProfile*)subDir->Get(profileName);
      
      pc[i]->Divide(p[0]);
      pc[i]->SetLineWidth(2);
      pc[i]->SetLineStyle(1+fMaxNPVs-i);
      pc[i]->SetLineColor(kGreen+3-fMaxNPVs+i);
      pc[i]->SetMarkerSize(.8);
      pc[i]->SetMarkerStyle(19+i);
      pc[i]->SetMarkerColor(kGreen+3-fMaxNPVs+i);
      pc[i]->Draw("histsamelp");
      
      legend->AddEntry(pc[i],(fLegend + " (" + npv + ", corrected)").c_str(),"lp");
   }
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
   string QCDpt15_plus_1PU_F_P = "root_files/closureAnalysis_old_binning/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_1PU_F_P_c_a_l = "root_files/closureAnalysis_old_binning/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_corrected_Avg_Lumi_ET0.5.root";
   string QCDpt15_plus_1PU_F_P_c_pv_l = "root_files/closureAnalysis_old_binning/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_corrected_PV_Lumi_ET0.5.root";
//    string QCDpt15_plus_1PU_F_P_c_pv = "root_files/closureAnalysis_old_binning/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_corrected_PV_ET0.5.root";
   string QCDpt15_plus_2PU_F_P = "root_files/closureAnalysis_old_binning/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_2PU_F_P_c_a_l = "root_files/closureAnalysis_old_binning/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_corrected_Avg_Lumi_ET0.5.root";
   string QCDpt15_plus_2PU_F_P_c_pv_l = "root_files/closureAnalysis_old_binning/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_corrected_PV_Lumi_ET0.5.root";
//    string QCDpt15_plus_2PU_F_P_c_pv = "root_files/closureAnalysis_old_binning/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_corrected_PV_ET0.5.root";
   string QCDpt15_plus_5PU_F_P = "root_files/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_ET0.5.root";
   string QCDpt15_plus_5PU_F_P_c_a_l = "root_files/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_corrected_Avg_Lumi_ET0.5.root";
   string QCDpt15_plus_5PU_F_P_c_pv_l = "closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_corrected_PV_Lumi_new_ET0.5.root";
//    string QCDpt15_plus_5PU_F_P_c_pv = "root_files/closureAnalysis_old_binning/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_corrected_PV_ET0.5.root";
   //********************************************
   // make plots
   //********************************************
   // *** QCD+1PU ***
   
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c, QCDpt15_plus_1PU_F_P_c_pv, QCDpt15_plus_1PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c, QCDpt15_plus_1PU_F_P_c_pv, QCDpt15_plus_1PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c, QCDpt15_plus_1PU_F_P_c_pv, QCDpt15_plus_1PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c, QCDpt15_plus_1PU_F_P_c_pv, QCDpt15_plus_1PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c, QCDpt15_plus_1PU_F_P_c_pv, QCDpt15_plus_1PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c, QCDpt15_plus_1PU_F_P_c_pv, QCDpt15_plus_1PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c, QCDpt15_plus_1PU_F_P_c_pv, QCDpt15_plus_1PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c, QCDpt15_plus_1PU_F_P_c_pv, QCDpt15_plus_1PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c, QCDpt15_plus_1PU_F_P_c_pv, QCDpt15_plus_1PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c, QCDpt15_plus_1PU_F_P_c_pv, QCDpt15_plus_1PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c, QCDpt15_plus_1PU_F_P_c_pv, QCDpt15_plus_1PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
   
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_1PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_1PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_1PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_1PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_1PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_1PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_1PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_1PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_1PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_1PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_a_l, QCDpt15_plus_1PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_1PU", "QCD+1PU");
   
   // *** QCD+2PU ***
   
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c, QCDpt15_plus_2PU_F_P_c_pv, QCDpt15_plus_2PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c, QCDpt15_plus_2PU_F_P_c_pv, QCDpt15_plus_2PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c, QCDpt15_plus_2PU_F_P_c_pv, QCDpt15_plus_2PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c, QCDpt15_plus_2PU_F_P_c_pv, QCDpt15_plus_2PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c, QCDpt15_plus_2PU_F_P_c_pv, QCDpt15_plus_2PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c, QCDpt15_plus_2PU_F_P_c_pv, QCDpt15_plus_2PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c, QCDpt15_plus_2PU_F_P_c_pv, QCDpt15_plus_2PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c, QCDpt15_plus_2PU_F_P_c_pv, QCDpt15_plus_2PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c, QCDpt15_plus_2PU_F_P_c_pv, QCDpt15_plus_2PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c, QCDpt15_plus_2PU_F_P_c_pv, QCDpt15_plus_2PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c, QCDpt15_plus_2PU_F_P_c_pv, QCDpt15_plus_2PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");

//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_pv_l, 5,"p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_a_l, QCDpt15_plus_2PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_2PU", "QCD+2PU");

   // *** QCD+5PU ***
   
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c, QCDpt15_plus_5PU_F_P_c_pv, QCDpt15_plus_5PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c, QCDpt15_plus_5PU_F_P_c_pv, QCDpt15_plus_5PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c, QCDpt15_plus_5PU_F_P_c_pv, QCDpt15_plus_5PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c, QCDpt15_plus_5PU_F_P_c_pv, QCDpt15_plus_5PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c, QCDpt15_plus_5PU_F_P_c_pv, QCDpt15_plus_5PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
   closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU_new", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c, QCDpt15_plus_5PU_F_P_c_pv, QCDpt15_plus_5PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c, QCDpt15_plus_5PU_F_P_c_pv, QCDpt15_plus_5PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c, QCDpt15_plus_5PU_F_P_c_pv, QCDpt15_plus_5PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c, QCDpt15_plus_5PU_F_P_c_pv, QCDpt15_plus_5PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    closurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c, QCDpt15_plus_5PU_F_P_c_pv, QCDpt15_plus_5PU_F_P_c_pv_l, "p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");

//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_pT", "(CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_pT_B", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_pT_E", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_pT_F", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT15_20", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT20_25", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT25_30", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT30_40", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT40_50", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT50_70", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");
//    pvClosurePlot(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_a_l, QCDpt15_plus_5PU_F_P_c_pv_l, 4,"p_CaloJetpToverGenJetpT_eta_pT70_100", "  (CMSSW_2_1_8, IDEAL_V9)", "QCD_plus_5PU", "QCD+5PU");

   // divide plots
   
//    dividePlots(QCDpt15_NN, QCDpt15_plus_1PU, QCDpt15_plus_2PU, QCDpt15_plus_5PU, QCDpt15_plus_1PU_c, QCDpt15_plus_2PU_c, QCDpt15_plus_5PU_c, "p_CaloJetpToverGenJetpT_eta_pT15_20", "QCDnPUoverQCDNN");
//    dividePlots(QCDpt15_NN, QCDpt15_plus_1PU, QCDpt15_plus_2PU, QCDpt15_plus_5PU, QCDpt15_plus_1PU_c, QCDpt15_plus_2PU_c, QCDpt15_plus_5PU_c, "p_CaloJetpToverGenJetpT_eta_pT25_30", "QCDnPUoverQCDNN");
//    dividePlots(QCDpt15_NN, QCDpt15_plus_1PU, QCDpt15_plus_2PU, QCDpt15_plus_5PU, QCDpt15_plus_1PU_c, QCDpt15_plus_2PU_c, QCDpt15_plus_5PU_c, "p_CaloJetpToverGenJetpT_eta_pT15_20", "QCDnPUoverQCDNN");

//    pvDividePlots(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_pv_l, 2, "p_CaloJetpToverGenJetpT_eta_pT15_20", "QCD1PUoverQCDNN","QCD+1PU");
//    pvDividePlots(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_pv_l, 4, "p_CaloJetpToverGenJetpT_eta_pT15_20", "QCD2PUoverQCDNN","QCD+2PU");
//    pvDividePlots(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_pv_l, 5, "p_CaloJetpToverGenJetpT_eta_pT15_20", "QCD5PUoverQCDNN","QCD+5PU");

//    pvDividePlots(QCDpt15_NN, QCDpt15_plus_1PU_F_P, QCDpt15_plus_1PU_F_P_c_pv_l, 2, "p_CaloJetpToverGenJetpT_eta_pT20_25", "QCD1PUoverQCDNN","QCD+1PU");
//    pvDividePlots(QCDpt15_NN, QCDpt15_plus_2PU_F_P, QCDpt15_plus_2PU_F_P_c_pv_l, 4, "p_CaloJetpToverGenJetpT_eta_pT20_25", "QCD2PUoverQCDNN","QCD+2PU");
//    pvDividePlots(QCDpt15_NN, QCDpt15_plus_5PU_F_P, QCDpt15_plus_5PU_F_P_c_pv_l, 5, "p_CaloJetpToverGenJetpT_eta_pT20_25", "QCD5PUoverQCDNN","QCD+5PU");

}