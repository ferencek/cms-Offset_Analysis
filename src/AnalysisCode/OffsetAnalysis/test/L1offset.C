void write_output(const string& fFile, const string& fPlot, const string& fFileName) {
  
   TProfile *p;
 
   TFile file(fFile.c_str());
   TDirectoryFile *subDir = (TDirectoryFile*)file.Get("offsetAnalysis");
   p = (TProfile*)subDir->Get(fPlot.c_str()); 
   
   Int_t nBins = p->GetNbinsX();
   
   ofstream fOutput(fFileName.c_str());
   
   for(Int_t i = 1; i<= nBins; i++) {
   
      char buffer[1024];
      Double_t lowerEdge = p->GetXaxis()->GetBinLowEdge(i);
      Double_t upperEdge = p->GetXaxis()->GetBinUpEdge(i);
      Double_t content = p->GetBinContent(i);
      
      sprintf(buffer,"%5.1f %5.1f %3.f %3.f %5.f %8.5f\n", lowerEdge, upperEdge, 3, 1, 5000, content);
      
      fOutput<<buffer;
   }
   // close output file
   fOutput.close();
}


void writeFiles() {
   // turn on/off batch mode
   gROOT->SetBatch(kTRUE);
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
   // write files
   //********************************************
//    write_output(noise_only_05, "p_AvgEinC5", "L1_parameters_Noise_only.txt");
   
//    write_output(onePU_IT_P_05, "p_AvgEinC5", "L1_parameters_1PU_InTime.txt");
   write_output(onePU_F_P_05, "p_AvgEinC5", "L1_parameters_1PU.txt");
   
//    write_output(twoPU_IT_P_05, "p_AvgEinC5", "L1_parameters_2PU_InTime.txt");
//    write_output(twoPU_F_P_05, "p_AvgEinC5", "L1_parameters_2PU.txt");
   
//    write_output(fivePU_IT_P_05, "p_AvgEinC5", "L1_parameters_5PU_InTime.txt");
//    write_output(fivePU_F_P_05, "p_AvgEinC5", "L1_parameters_5PU.txt");
}