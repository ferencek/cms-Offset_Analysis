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
//    gStyle->SetOptTitle(0); // for PAS
   gStyle->SetPadLeftMargin(0.12); // for PAS
   gStyle->SetPadRightMargin(0.08); // for PAS
//    gStyle->SetStatFont(42);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetLabelFont(42, "XYZ");
}

void overlay_fracConeAreas(const string& fFile0, const string& fFile1, const string& fFile2, const string& fPlot, const string& fTitleExt, const string& fNameExt) {
  
   TProfile *p[3];
 
   TFile file0(fFile0.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file0.Get("offsetAnalysis");
   p[0] = (TProfile*)subDir->Get(fPlot.c_str()); 

   TFile file1(fFile1.c_str());
   subDir = (TDirectoryFile*)file1.Get("offsetAnalysis");
   p[1] = (TProfile*)subDir->Get(fPlot.c_str()); 
       
   TFile file2(fFile2.c_str());
   subDir = (TDirectoryFile*)file2.Get("offsetAnalysis");
   p[2] = (TProfile*)subDir->Get(fPlot.c_str()); 
   
   string name = p[0]->GetName();
   string fileName = name + "__" + fNameExt + ".png";
   
   string title = p[0]->GetTitle();
   title = title + " " + fTitleExt;
   p[0]->SetTitle(title.c_str());
   
   double ymax = 2.5;
   if ( fPlot.find("p_AvgEinC5") != string::npos ) ymax = 17;
   p[0]->GetYaxis()->SetRangeUser(0,ymax);
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
     
   p[0]->SetLineWidth(3);
   p[0]->SetLineStyle(3);
   p[0]->SetLineColor(kRed+1);
   p[0]->Draw("hist");
   p[1]->SetLineWidth(3);
   p[1]->SetLineStyle(7);
   p[1]->SetLineColor(kRed+2);
   p[1]->Draw("histsame");
   p[2]->SetLineWidth(3);
   p[2]->SetLineColor(kRed+3);
   p[2]->Draw("histsame");
   
   TLegend *legend = new TLegend(.13,.74,.22,.88);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->AddEntry(p[2],"5PU","l");
   legend->AddEntry(p[1],"2PU","l");
   legend->AddEntry(p[0],"1PU","l");
   legend->Draw();
   
   c->SetGridy();
   c->SaveAs(fileName.c_str());
   
   delete legend;
   delete c;
}

void overlay_fracConeAreasPAS(const string& fFile0, const string& fFile1, const string& fFile2, const string& fFile3, const string& fPlot, const string& fTitleExt, const string& fLegendExt, const string& fNameExt) {
  
   TProfile *p[4];
 
   TFile file0(fFile0.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file0.Get("offsetAnalysis");
   p[0] = (TProfile*)subDir->Get(fPlot.c_str()); 

   TFile file1(fFile1.c_str());
   subDir = (TDirectoryFile*)file1.Get("offsetAnalysis");
   p[1] = (TProfile*)subDir->Get(fPlot.c_str()); 
       
   TFile file2(fFile2.c_str());
   subDir = (TDirectoryFile*)file2.Get("offsetAnalysis");
   p[2] = (TProfile*)subDir->Get(fPlot.c_str());
   
   TFile file3(fFile3.c_str());
   subDir = (TDirectoryFile*)file3.Get("offsetAnalysis");
   p[3] = (TProfile*)subDir->Get(fPlot.c_str()); 
   
   string name = p[0]->GetName();
   string fileName = name + "__" + fNameExt;
   
//    string title = p[0]->GetTitle();
//    title = title + " " + fTitleExt;
   p[0]->SetTitle(fTitleExt.c_str());
   p[0]->GetYaxis()->SetTitle("<A_{frac}>");
   p[0]->GetYaxis()->SetRangeUser(0.,0.12);
   p[0]->SetTitleOffset(1.5,"Y");
   
//    TCanvas *c = new TCanvas("c","",1120,800);
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
  
   p[0]->SetLineWidth(2);
   p[0]->SetLineStyle(6);
   p[0]->SetLineColor(kBlue);
   p[0]->SetMarkerSize(.6);
   p[0]->SetMarkerStyle(26);
   p[0]->SetMarkerColor(kBlue);
   p[0]->Draw("hist");
   p[1]->SetLineWidth(2);
   p[1]->SetLineStyle(3);
   p[1]->SetLineColor(kRed+1);
   p[1]->SetMarkerSize(.6);
   p[1]->SetMarkerStyle(27);
   p[1]->SetMarkerColor(kRed+1);
   p[1]->Draw("histsame");
   p[2]->SetLineWidth(2);
   p[2]->SetLineStyle(7);
   p[2]->SetLineColor(kRed+2);
   p[2]->SetMarkerSize(.6);
   p[2]->SetMarkerStyle(25);
   p[2]->SetMarkerColor(kRed+2);
   p[2]->Draw("histsame");
   p[3]->SetLineWidth(2);
   p[3]->SetLineColor(kRed+3);
   p[3]->SetMarkerSize(.6);
   p[3]->SetMarkerStyle(24);
   p[3]->SetMarkerColor(kRed+3);
   p[3]->Draw("histsame");
   
   TLegend *legend = new TLegend(.4,.68,.6,.85);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->AddEntry(p[3],("5PU" + fLegendExt).c_str(),"l");
   legend->AddEntry(p[2],("2PU" + fLegendExt).c_str(),"l");
   legend->AddEntry(p[1],("1PU" + fLegendExt).c_str(),"l");
   legend->AddEntry(p[0],"Noise","l");
   legend->Draw();
   
   TLatex l;
   l.SetTextAlign(12);
   l.SetTextSize(0.04);
   l.SetTextFont(62);
   l.SetNDC();
//    l.DrawLatex(0.13,0.85,"CMS Preliminary");
   
   c->SetGridy();
   c->SaveAs(fileName.c_str());
   
   delete legend;
   delete c;
}

void overlay_fracJetAreasPAS(const string& fFile0, const string& fFile1, const string& fFile2, const string& fTitleExt, const string& fLegendExt, const string& fNameExt) {
  
   TH3D *h3[2];
   TH2D *h2[2];
   TProfile *p[3];
     
   TFile file0(fFile0.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file0.Get("effJetArea");
   h3[0] = (TH3D*)subDir->Get("h_EffJetArea_eta_pT");
   h3[0]->GetYaxis()->SetRangeUser(25,40);
   h2[0] = (TH2D*)h3[0]->Project3D("zx");
   p[0] = h2[0]->ProfileX("_pfx",1,110);
  
   TFile file1(fFile1.c_str());
   subDir = (TDirectoryFile*)file1.Get("effJetArea");
   h3[1] = (TH3D*)subDir->Get("h_EffJetArea_eta_pT");
   h3[1]->GetYaxis()->SetRangeUser(25,40);
   h2[1] = (TH2D*)h3[1]->Project3D("zx");
   p[1] = h2[1]->ProfileX("_pfx",1,110);
  
   TFile file2(fFile2.c_str());
   subDir = (TDirectoryFile*)file2.Get("offsetAnalysis");
   p[2] = (TProfile*)subDir->Get("p_EffConeArea");
  
   TH1D *h = new TH1D("h","",100,-5.,5.);
   
   for(int i=1;i<101;i++){
      h->SetBinContent(i,(p[0]->GetBinContent(i)+p[2]->GetBinContent(i)-(p[0]->GetBinContent(i)*p[2]->GetBinContent(i))));
   }
  //    string name = p[0]->GetName();
   string fileName = "p_EffJetArea_pT25_40__" + fNameExt;
     
   p[1]->SetTitle(fTitleExt.c_str());
     
   p[1]->GetYaxis()->SetRangeUser(0.,0.7);
//    p[1]->GetYaxis()->SetTitle("<towersArea/R_{cone}^{2}#pi>");
   p[1]->GetYaxis()->SetTitle("<A_{frac}>");
   p[1]->GetXaxis()->SetTitleSize(0.05);
   p[1]->GetYaxis()->SetTitleSize(0.05);
   p[1]->SetTitleOffset(1.2,"Y");
     
//    TCanvas *c = new TCanvas("c","",1120,800);
   TCanvas *c = new TCanvas("c","",800,800);
   c->cd();
   
   p[1]->SetLineWidth(3);
   p[1]->SetLineStyle(1);
   p[1]->SetLineColor(kRed+1);
   p[1]->SetMarkerSize(.6);
   p[1]->SetMarkerStyle(27);
   p[1]->SetMarkerColor(kRed+1);
   p[1]->Draw("hist");
   p[0]->SetLineWidth(3);
   p[0]->SetLineStyle(3);
   p[0]->SetLineColor(kBlue);
   p[0]->SetMarkerSize(.6);
   p[0]->SetMarkerStyle(26);
   p[0]->SetMarkerColor(kBlue);
   p[0]->Draw("histsame");
   h->SetLineWidth(3);
   h->SetLineStyle(2);
   h->SetLineColor(kGreen+2);
   h->SetMarkerSize(.6);
   h->SetMarkerStyle(25);
   h->SetMarkerColor(kGreen+2);
   h->Draw("same");
  
     
   TLegend *legend = new TLegend(.31,.71,.73,.86);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
     //legend->SetFillStyle(0);
   legend->AddEntry(p[1],("QCD+" + fLegendExt + " (observed)").c_str(),"l");
   legend->AddEntry(h,("QCD+" + fLegendExt+ " (\"expected\")").c_str(),"l");
   legend->AddEntry(p[0],"QCD no noise/no pile-up","l");
   legend->Draw();
     
   TLatex l;
   l.SetTextAlign(12);
   l.SetTextSize(0.04);
   l.SetTextFont(62);
   l.SetNDC();
//    l.DrawLatex(0.13,0.85,"CMS Preliminary");
     
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
   
   string QCDpt15_NN = "root_files/effJetArea_QCDpt15_NN.root";
   string QCDpt15_plus_1PU_IT_P = "root_files/effJetArea_QCDpt15_plus_1PU_InTime_Poisson.root";
   string QCDpt15_plus_1PU_F_P = "root_files/effJetArea_QCDpt15_plus_1PU_Full_Poisson.root";
   string QCDpt15_plus_2PU_IT_P = "root_files/effJetArea_QCDpt15_plus_2PU_InTime_Poisson.root";
   string QCDpt15_plus_2PU_F_P = "root_files/effJetArea_QCDpt15_plus_2PU_Full_Poisson.root";
   string QCDpt15_plus_5PU_IT_P = "root_files/effJetArea_QCDpt15_plus_5PU_InTime_Poisson.root";
   string QCDpt15_plus_5PU_F_P = "root_files/effJetArea_QCDpt15_plus_5PU_Full_Poisson.root";
   //********************************************
   // make plots
   //********************************************
   
   overlay_fracConeAreasPAS(noise_only_05,onePU_IT_P_05,twoPU_IT_P_05,fivePU_IT_P_05,"p_EffConeArea","In-time pile-up", "", "PU_IT_P_overlay.png");
   overlay_fracConeAreasPAS(noise_only_05,onePU_F_P_05,twoPU_F_P_05,fivePU_F_P_05,"p_EffConeArea","Full pile-up", "", "PU_F_P_overlay.png");

//    overlay_fracJetAreasPAS(QCDpt15_NN,QCDpt15_plus_1PU_IT_P,onePU_IT_P_05,"(CMSSW_2_1_8, IDEAL_V9)", "1PU (in-time)", "QCD_plus_1PU_IT_P_overlay.png");
//    overlay_fracJetAreasPAS(QCDpt15_NN,QCDpt15_plus_1PU_F_P,onePU_F_P_05,"(CMSSW_2_1_8, IDEAL_V9)", "1PU (full)", "QCD_plus_1PU_F_P_overlay.png");
   overlay_fracJetAreasPAS(QCDpt15_NN,QCDpt15_plus_2PU_IT_P,twoPU_IT_P_05,"In-time pile-up, 25<p_{T}^{gen}<40 GeV/c", "2PU", "QCD_plus_2PU_IT_P_overlay.png");
   overlay_fracJetAreasPAS(QCDpt15_NN,QCDpt15_plus_2PU_F_P,twoPU_F_P_05,"Full pile-up, 25<p_{T}^{gen}<40 GeV/c", "2PU", "QCD_plus_2PU_F_P_overlay.png");
   overlay_fracJetAreasPAS(QCDpt15_NN,QCDpt15_plus_5PU_IT_P,fivePU_IT_P_05,"In-time pile-up, 25<p_{T}^{gen}<40 GeV/c", "5PU", "QCD_plus_5PU_IT_P_overlay.png");
   overlay_fracJetAreasPAS(QCDpt15_NN,QCDpt15_plus_5PU_F_P,fivePU_F_P_05,"Full pile-up, 25<p_{T}^{gen}<40 GeV/c", "5PU", "QCD_plus_5PU_F_P_overlay.png");
}

// void overlay_effJetAreasPAS(const string& fFile0, const string& fFile1, const string& fFile2, const string& fFile3, const string& fPlot, const string& fTitleExt, const string& fLegendExt, const string& fNameExt) {
//   
//    TH3D *h3[4];
//    TH2D *h2[4];
//    TProfile *p[4];
//    
//    TFile file0(fFile0.c_str());
//    TDirectoryFile *subDir = (TDirectoryFile*)file0.Get("effJetArea");
//    h3[0] = (TH3D*)subDir->Get(fPlot.c_str());
//    h3[0]->GetYaxis()->SetRange(26,40);
//    h2[0] = (TH2D*)h3[0]->Project3D("zx");
//    p[0] = h2[0]->ProfileX("_pfx",1,110);
// 
//    TFile file1(fFile1.c_str());
//    subDir = (TDirectoryFile*)file1.Get("effJetArea");
//    h3[1] = (TH3D*)subDir->Get(fPlot.c_str());
//    h3[1]->GetYaxis()->SetRange(26,40);
//    h2[1] = (TH2D*)h3[1]->Project3D("zx");
//    p[1] = h2[1]->ProfileX("_pfx",1,110);
// 
//    TFile file2(fFile2.c_str());
//    subDir = (TDirectoryFile*)file2.Get("effJetArea");
//    h3[2] = (TH3D*)subDir->Get(fPlot.c_str());
//    h3[2]->GetYaxis()->SetRange(26,40);
//    h2[2] = (TH2D*)h3[2]->Project3D("zx");
//    p[2] = h2[2]->ProfileX("_pfx",1,110);
// 
//    TFile file3(fFile3.c_str());
//    subDir = (TDirectoryFile*)file3.Get("effJetArea");
//    h3[3] = (TH3D*)subDir->Get(fPlot.c_str());
//    h3[3]->GetYaxis()->SetRange(26,40);
//    h2[3] = (TH2D*)h3[3]->Project3D("zx");
//    p[3] = h2[3]->ProfileX("_pfx",1,110);
// 
// //    string name = p[0]->GetName();
//    string fileName = "p_EffJetArea_pT25_40__" + fNameExt;
//    
//    p[3]->SetTitle(fTitleExt.c_str());
//    
// //    p[0]->GetYaxis()->SetRangeUser(0.,0.12);
//    p[3]->GetYaxis()->SetTitle("<towersArea/R_{cone}^{2}#pi>");
//    p[3]->SetTitleOffset(1.25,"Y");
//    
//    TCanvas *c = new TCanvas("c","",1120,800);
// //    TCanvas *c = new TCanvas("c","",800,800);
//    c->cd();
//   
//    p[3]->SetLineWidth(2);
//    p[3]->SetLineColor(kRed+3);
//    p[3]->SetMarkerSize(.6);
//    p[3]->SetMarkerStyle(24);
//    p[3]->SetMarkerColor(kRed+3);
//    p[3]->Draw("p");
//    p[0]->SetLineWidth(2);
//    p[0]->SetLineStyle(6);
//    p[0]->SetLineColor(kBlue);
//    p[0]->SetMarkerSize(.6);
//    p[0]->SetMarkerStyle(26);
//    p[0]->SetMarkerColor(kBlue);
//    p[0]->Draw("psame");
//    p[1]->SetLineWidth(2);
//    p[1]->SetLineStyle(3);
//    p[1]->SetLineColor(kRed+1);
//    p[1]->SetMarkerSize(.6);
//    p[1]->SetMarkerStyle(27);
//    p[1]->SetMarkerColor(kRed+1);
//    p[1]->Draw("psame");
//    p[2]->SetLineWidth(2);
//    p[2]->SetLineStyle(7);
//    p[2]->SetLineColor(kRed+2);
//    p[2]->SetMarkerSize(.6);
//    p[2]->SetMarkerStyle(25);
//    p[2]->SetMarkerColor(kRed+2);
//    p[2]->Draw("psame");
// 
//    
//    TLegend *legend = new TLegend(.375,.65,.625,.8);
//    legend->SetBorderSize(1);
//    legend->SetFillColor(0);
//    //legend->SetFillStyle(0);
//    legend->SetHeader("25<p_{T}^{gen}<40 GeV/c");
//    legend->AddEntry(p[3],("QCD+5PU" + fLegendExt).c_str(),"lp");
//    legend->AddEntry(p[2],("QCD+2PU" + fLegendExt).c_str(),"lp");
//    legend->AddEntry(p[1],("QCD+1PU" + fLegendExt).c_str(),"lp");
//    legend->AddEntry(p[0],"QCD no noise/no pile-up","lp");
//    legend->Draw();
//    
//    TLatex l;
//    l.SetTextAlign(12);
//    l.SetTextSize(0.04);
//    l.SetTextFont(62);
//    l.SetNDC();
//    l.DrawLatex(0.13,0.85,"CMS Preliminary");
//    
//    c->SetGridy();
//    c->SaveAs(fileName.c_str());
//    
//    delete legend;
//    delete c;
// }