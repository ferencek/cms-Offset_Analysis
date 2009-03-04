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
}

void plotProducer(const string& fFile, const string& fPlot, const string& fNameExt, const string& fExt, const string& fSwitch) {
  
   TH1F *h;
    
   TFile file(fFile.c_str());
   TDirectoryFile *dir = (TDirectoryFile*)file.Get("offsetAnalysis");
   TDirectoryFile *subDir = (TDirectoryFile*)dir->Get("PrimaryVertices");

   h = (TH1F*)subDir->Get(fPlot.c_str());

   string name = h->GetName();
   string fileName = name + "__" + fNameExt + "." + fExt;
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
     
   //h->SetLineWidth(2);
   h->Draw();
   
   if ( fSwitch.find("log") != string::npos ) c->SetLogy();
   c->SaveAs(fileName.c_str());
   
   delete c;
}

void plotProducer2(const string& fFile, const string& fPlot, const string& fNameExt, const string& fExt, const string& fSwitch) {
  
   TH2F *h;
    
   TFile file(fFile.c_str());
   TDirectoryFile *dir = (TDirectoryFile*)file.Get("offsetAnalysis");
   TDirectoryFile *subDir = (TDirectoryFile*)dir->Get("PrimaryVertices");

   h = (TH2F*)subDir->Get(fPlot.c_str());

   string name = h->GetName();
   string fileName = name + "__" + fNameExt + "." + fExt;
   
   TCanvas *c = new TCanvas("c","",1120,800);
   c->cd();
     
   h->Draw(fSwitch.c_str());

   c->SaveAs(fileName.c_str());
   
   delete c;
}

void makePlots() {
   // turn on/off batch mode
   //gROOT->SetBatch(kTRUE);
   // set ROOT style
   style();
   //********************************************
   // root files
   //********************************************
   // *** offlinePrimaryVertices ***
   string oPV_noise_only = "root_files/offlinePrimaryVertices_Noise-only.root";

   string oPV_onePU_IT_F = "root_files/offlinePrimaryVertices_1PU_InTime_Fixed.root";

   string oPV_twoPU_IT_F = "root_files/offlinePrimaryVertices_2PU_InTime_Fixed.root";

   string oPV_fivePU_IT_F = "root_files/offlinePrimaryVertices_5PU_InTime_Fixed.root";
   //********************************************
   // make plots
   //********************************************
   // *** offlinePrimaryVertices ***
   plotProducer(oPV_onePU_IT_F, "h_NofPVTracks", "offlinePrimaryVertices_1PU_InTime_Fixed","png","log");
   plotProducer(oPV_onePU_IT_F, "h_PVChi2overNdof", "offlinePrimaryVertices_1PU_InTime_Fixed","png","log");
   plotProducer(oPV_onePU_IT_F, "h_PVz", "offlinePrimaryVertices_1PU_InTime_Fixed","png","log");
   plotProducer(oPV_onePU_IT_F, "h_NofCPs", "offlinePrimaryVertices_1PU_InTime_Fixed","png","log");
   plotProducer(oPV_onePU_IT_F, "h_NofCPsEta25", "offlinePrimaryVertices_1PU_InTime_Fixed","png","log");
   plotProducer2(oPV_onePU_IT_F, "h_NofPVs_NofCPsEta25", "offlinePrimaryVertices_1PU_InTime_Fixed","png","colz");
   
   plotProducer(oPV_twoPU_IT_F, "h_NofPVTracks", "offlinePrimaryVertices_2PU_InTime_Fixed","png","log");
   plotProducer(oPV_twoPU_IT_F, "h_PVChi2overNdof", "offlinePrimaryVertices_2PU_InTime_Fixed","png","log");
   plotProducer(oPV_twoPU_IT_F, "h_PVz", "offlinePrimaryVertices_2PU_InTime_Fixed","png","log");
   
   plotProducer(oPV_fivePU_IT_F, "h_NofPVTracks", "offlinePrimaryVertices_5PU_InTime_Fixed","png","log");
   plotProducer(oPV_fivePU_IT_F, "h_PVChi2overNdof", "offlinePrimaryVertices_5PU_InTime_Fixed","png","log");
   plotProducer(oPV_fivePU_IT_F, "h_PVz", "offlinePrimaryVertices_5PU_InTime_Fixed","png","log");
}