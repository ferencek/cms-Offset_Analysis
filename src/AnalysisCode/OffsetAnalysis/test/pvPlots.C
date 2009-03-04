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
     
   //gStyle->SetOptStat(kFALSE);
   gStyle->SetOptStat(111110);
//    gStyle->SetStatFont(42);
//    gStyle->SetTitleFont(42);
//    gStyle->SetTitleFont(42, "XYZ");
//    gStyle->SetLabelFont(42, "XYZ");

   gROOT->SetBatch(kTRUE);  // Turn on/off batch mode
}

void pv_dist(const string& fFile, const string& fTitle, const string& fNameExt) {
  
   TH1F *h;
    
   TFile file(fFile.c_str());
   TDirectoryFile *dir = (TDirectoryFile*)file.Get("offsetAnalysis");
   TDirectoryFile *subDir = (TDirectoryFile*)dir->Get("PrimaryVertices");

   h = (TH1F*)subDir->Get("h_NofPVs"); 
   
   string name = h->GetName();
   string fileName = name + "__" + fNameExt + ".png";
   
   h->SetTitle(fTitle.c_str());
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
     
   h->SetLineWidth(2);
   h->Draw();
   
   c->SetLogy();
   c->SaveAs(fileName.c_str());
   
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
   // *** offlinePrimaryVertices ***
   string oPV_noise_only = "root_files/offlinePrimaryVertices_Noise-only.root";

   string oPV_onePU_IT_F = "root_files/offlinePrimaryVertices_1PU_InTime_Fixed.root";
   string oPV_onePU_IT_P = "root_files/offlinePrimaryVertices_1PU_InTime_Poisson.root";
   string oPV_onePU_F_P = "root_files/offlinePrimaryVertices_1PU_Full_Poisson.root";
   
   string oPV_twoPU_IT_F = "root_files/offlinePrimaryVertices_2PU_InTime_Fixed.root";
   string oPV_twoPU_IT_P = "root_files/offlinePrimaryVertices_2PU_InTime_Poisson.root";
   string oPV_twoPU_F_P = "root_files/offlinePrimaryVertices_2PU_Full_Poisson.root";
   
   string oPV_fivePU_IT_F = "root_files/offlinePrimaryVertices_5PU_InTime_Fixed.root";
   string oPV_fivePU_IT_P = "root_files/offlinePrimaryVertices_5PU_InTime_Poisson.root";
   string oPV_fivePU_F_P = "root_files/offlinePrimaryVertices_5PU_Full_Poisson.root";

   string oPV_QCDpt15_NN = "root_files/offlinePrimaryVertices_QCDpt15_NN.root";
   string oPV_QCDpt15_plus_1PU_F_P = "root_files/offlinePrimaryVertices_QCDpt15_plus_1PU_Full_Poisson.root";
   string oPV_QCDpt15_plus_2PU_F_P = "root_files/offlinePrimaryVertices_QCDpt15_plus_2PU_Full_Poisson.root";
   string oPV_QCDpt15_plus_5PU_F_P = "root_files/offlinePrimaryVertices_QCDpt15_plus_5PU_Full_Poisson.root";
   // *** offlinePrimaryVerticesWithBS ***
   string oPVBS_noise_only = "root_files/offlinePrimaryVerticesWithBS_Noise-only.root";

   string oPVBS_onePU_IT_F = "root_files/offlinePrimaryVerticesWithBS_1PU_InTime_Fixed.root";
   string oPVBS_onePU_IT_P = "root_files/offlinePrimaryVerticesWithBS_1PU_InTime_Poisson.root";
   string oPVBS_onePU_F_P = "root_files/offlinePrimaryVerticesWithBS_1PU_Full_Poisson.root";
   
   string oPVBS_twoPU_IT_F = "root_files/offlinePrimaryVerticesWithBS_2PU_InTime_Fixed.root";
   string oPVBS_twoPU_IT_P = "root_files/offlinePrimaryVerticesWithBS_2PU_InTime_Poisson.root";
   string oPVBS_twoPU_F_P = "root_files/offlinePrimaryVerticesWithBS_2PU_Full_Poisson.root";
   
   string oPVBS_fivePU_IT_F = "root_files/offlinePrimaryVerticesWithBS_5PU_InTime_Fixed.root";
   string oPVBS_fivePU_IT_P = "root_files/offlinePrimaryVerticesWithBS_5PU_InTime_Poisson.root";
   string oPVBS_fivePU_F_P = "root_files/offlinePrimaryVerticesWithBS_5PU_Full_Poisson.root";
   // *** pixelVertices ***
   string pV_noise_only = "root_files/pixelVertices_Noise-only.root";

   string pV_onePU_IT_F = "root_files/pixelVertices_1PU_InTime_Fixed.root";
   string pV_onePU_IT_P = "root_files/pixelVertices_1PU_InTime_Poisson.root";
   string pV_onePU_F_P = "root_files/pixelVertices_1PU_Full_Poisson.root";
   
   string pV_twoPU_IT_F = "root_files/pixelVertices_2PU_InTime_Fixed.root";
   string pV_twoPU_IT_P = "root_files/pixelVertices_2PU_InTime_Poisson.root";
   string pV_twoPU_F_P = "root_files/pixelVertices_2PU_Full_Poisson.root";
   
   string pV_fivePU_IT_F = "root_files/pixelVertices_5PU_InTime_Fixed.root";
   string pV_fivePU_IT_P = "root_files/pixelVertices_5PU_InTime_Poisson.root";
   string pV_fivePU_F_P = "root_files/pixelVertices_5PU_Full_Poisson.root";
   //********************************************
   // make plots
   //********************************************
   // *** offlinePrimaryVertices ***
//    pv_dist(oPV_noise_only, "Noise-only (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_Noise-only");
// 
//    pv_dist(oPV_onePU_IT_F, "1PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_1PU_InTime_Fixed");
//    pv_dist(oPV_onePU_IT_P, "1PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_1PU_InTime_Poisson");
//    pv_dist(oPV_onePU_F_P, "1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_1PU_Full_Poisson");
//    
//    pv_dist(oPV_twoPU_IT_F, "2PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_2PU_InTime_Fixed");
//    pv_dist(oPV_twoPU_IT_P, "2PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_2PU_InTime_Poisson");
//    pv_dist(oPV_twoPU_F_P, "2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_2PU_Full_Poisson");
//    
//    pv_dist(oPV_fivePU_IT_F, "5PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_5PU_InTime_Fixed");
//    pv_dist(oPV_fivePU_IT_P, "5PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_5PU_InTime_Poisson");
//    pv_dist(oPV_fivePU_F_P, "5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_5PU_Full_Poisson");

   pv_dist(oPV_QCDpt15_NN, "QCD+0PU (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_QCDpt15_NN");
   pv_dist(oPV_QCDpt15_plus_1PU_F_P, "QCD+1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_QCDpt15_plus_1PU_Full_Poisson");
   pv_dist(oPV_QCDpt15_plus_2PU_F_P, "QCD+2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_QCDpt15_plus_2PU_Full_Poisson");
   pv_dist(oPV_QCDpt15_plus_5PU_F_P, "QCD+5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVertices_QCDpt15_plus_5PU_Full_Poisson");
   // *** offlinePrimaryVerticesWithBS ***
//    pv_dist(oPVBS_noise_only, "Noise-only (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVerticesWithBS_Noise-only");
// 
//    pv_dist(oPVBS_onePU_IT_F, "1PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVerticesWithBS_1PU_InTime_Fixed");
//    pv_dist(oPVBS_onePU_IT_P, "1PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVerticesWithBS_1PU_InTime_Poisson");
//    pv_dist(oPVBS_onePU_F_P, "1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVerticesWithBS_1PU_Full_Poisson");
//    
//    pv_dist(oPVBS_twoPU_IT_F, "2PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVerticesWithBS_2PU_InTime_Fixed");
//    pv_dist(oPVBS_twoPU_IT_P, "2PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVerticesWithBS_2PU_InTime_Poisson");
//    pv_dist(oPVBS_twoPU_F_P, "2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVerticesWithBS_2PU_Full_Poisson");
//    
//    pv_dist(oPVBS_fivePU_IT_F, "5PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVerticesWithBS_5PU_InTime_Fixed");
//    pv_dist(oPVBS_fivePU_IT_P, "5PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVerticesWithBS_5PU_InTime_Poisson");
//    pv_dist(oPVBS_fivePU_F_P, "5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "offlinePrimaryVerticesWithBS_5PU_Full_Poisson");
   // *** pixelVertices ***
//    pv_dist(pV_noise_only, "Noise-only (CMSSW_2_1_8, IDEAL_V9)", "pixelVertices_Noise-only");
// 
//    pv_dist(pV_onePU_IT_F, "1PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "pixelVertices_1PU_InTime_Fixed");
//    pv_dist(pV_onePU_IT_P, "1PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "pixelVertices_1PU_InTime_Poisson");
//    pv_dist(pV_onePU_F_P, "1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "pixelVertices_1PU_Full_Poisson");
//    
//    pv_dist(pV_twoPU_IT_F, "2PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "pixelVertices_2PU_InTime_Fixed");
//    pv_dist(pV_twoPU_IT_P, "2PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "pixelVertices_2PU_InTime_Poisson");
//    pv_dist(pV_twoPU_F_P, "2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "pixelVertices_2PU_Full_Poisson");
//    
//    pv_dist(pV_fivePU_IT_F, "5PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "pixelVertices_5PU_InTime_Fixed");
//    pv_dist(pV_fivePU_IT_P, "5PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "pixelVertices_5PU_InTime_Poisson");
//    pv_dist(pV_fivePU_F_P, "5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "pixelVertices_5PU_Full_Poisson");
}