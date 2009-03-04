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

const float tower_size[41]=
{0.087, 0.087, 0.087, 0.087, 0.087, 
 0.087, 0.087, 0.087, 0.087, 0.087,
 0.087, 0.087, 0.087, 0.087, 0.087,
 0.087, 0.087, 0.087, 0.087, 0.087,
 0.090, 0.100, 0.113, 0.129, 0.150,
 0.178, 0.150, 0.350, 0.111, 0.175,
 0.175, 0.175, 0.175, 0.175, 0.174,
 0.178, 0.172, 0.175, 0.178, 0.173,
 0.302};

void stack_ring_contribs(const string& fFile, const string& fTitleExt, const string& fNameExt) {
                                
   string title = "<E> in i#eta Ring " + fTitleExt + ";i#eta;<E> [GeV]";
                                
   TFile file(fFile.c_str());   
   file.cd("offsetAnalysis");   
                                
   TH1D *p_AEEREB  = p_AvgEinEREB->ProjectionX();
   TH1D *p_AEEREE  = p_AvgEinEREE->ProjectionX();
   TH1D *p_AEERHB  = p_AvgEinERHB->ProjectionX();
   TH1D *p_AEERHE  = p_AvgEinERHE->ProjectionX();
   TH1D *p_AEERHFl = p_AvgEinERHFl->ProjectionX();
   TH1D *p_AEERHFs = p_AvgEinERHFs->ProjectionX();
   //TH1D *p_AEERHO  = p_AvgEinC5HO->ProjectionX();
         
   p_AEEREB->SetFillColor(50);
   p_AEEREE->SetFillColor(8);
   p_AEERHB->SetFillColor(4);
   p_AEERHE->SetFillColor(6);
   p_AEERHFl->SetFillColor(16);
   p_AEERHFs->SetFillColor(12);
   //p_AEERHO->SetFillColor(7);
   
   TCanvas *c = new TCanvas("c", "",1120,800);
   c->cd();
   
   THStack *hs = new THStack("hs",title.c_str());
   
   hs->Add(p_AEEREB);
   hs->Add(p_AEEREE);
   hs->Add(p_AEERHB);
   hs->Add(p_AEERHE);
   hs->Add(p_AEERHFl);
   hs->Add(p_AEERHFs);
   //hs->Add(p_AEERHO);
   hs->Draw("hist");
   
   TLegend *legend = new TLegend(.6,.55,.68,.85);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->SetTextFont(42);
   legend->AddEntry(p_AEEREB,"EB","f");
   legend->AddEntry(p_AEEREE,"EE","f");
   legend->AddEntry(p_AEERHB,"HB","f");
   legend->AddEntry(p_AEERHE,"HE","f");
   legend->AddEntry(p_AEERHFl,"HFl","f");
   legend->AddEntry(p_AEERHFs,"HFs","f");
   //legend->AddEntry(p_AEERHO,"HO","f");
   legend->Draw();
   
   string fileName = "p_AvgEinER_stacked__" + fNameExt + ".png";
   
   c->SetGridy();
   c->SaveAs(fileName.c_str());

   delete legend;
   delete hs;
   delete c;
}

void stack_norm_ring_contribs(const string& fFile, const string& fTitleExt, const string& fNameExt) {
                                
   string title = "d<E>/d#eta in i#eta Ring " + fTitleExt + ";i#eta;d<E>/d#eta [GeV]";
                                
   TFile file(fFile.c_str());   
   file.cd("offsetAnalysis");   
                                
   TH1D *p_AEEREB  = p_AvgEinEREB->ProjectionX();
   TH1D *p_AEEREE  = p_AvgEinEREE->ProjectionX();
   TH1D *p_AEERHB  = p_AvgEinERHB->ProjectionX();
   TH1D *p_AEERHE  = p_AvgEinERHE->ProjectionX();
   TH1D *p_AEERHFl = p_AvgEinERHFl->ProjectionX();
   TH1D *p_AEERHFs = p_AvgEinERHFs->ProjectionX();
   //TH1D *p_AEERHO  = p_AvgEinC5HO->ProjectionX();

   for (int i=41; i>0; i--) {
      p_AEEREB->SetBinContent(i,p_AEEREB->GetBinContent(i)/tower_size[41-i]);
      p_AEEREE->SetBinContent(i,p_AEEREE->GetBinContent(i)/tower_size[41-i]);
      p_AEERHB->SetBinContent(i,p_AEERHB->GetBinContent(i)/tower_size[41-i]);
      p_AEERHE->SetBinContent(i,p_AEERHE->GetBinContent(i)/tower_size[41-i]);
      p_AEERHFl->SetBinContent(i,p_AEERHFl->GetBinContent(i)/tower_size[41-i]);
      p_AEERHFs->SetBinContent(i,p_AEERHFs->GetBinContent(i)/tower_size[41-i]);
   }
   for (int i=43; i<84; i++) {
      p_AEEREB->SetBinContent(i,p_AEEREB->GetBinContent(i)/tower_size[i-43]);
      p_AEEREE->SetBinContent(i,p_AEEREE->GetBinContent(i)/tower_size[i-43]);
      p_AEERHB->SetBinContent(i,p_AEERHB->GetBinContent(i)/tower_size[i-43]);
      p_AEERHE->SetBinContent(i,p_AEERHE->GetBinContent(i)/tower_size[i-43]);
      p_AEERHFl->SetBinContent(i,p_AEERHFl->GetBinContent(i)/tower_size[i-43]);
      p_AEERHFs->SetBinContent(i,p_AEERHFs->GetBinContent(i)/tower_size[i-43]);
   }     
         
   p_AEEREB->SetFillColor(50);
   p_AEEREE->SetFillColor(8);
   p_AEERHB->SetFillColor(4);
   p_AEERHE->SetFillColor(6);
   p_AEERHFl->SetFillColor(16);
   p_AEERHFs->SetFillColor(12);
   //p_AEERHO->SetFillColor(7);
   
   TCanvas *c = new TCanvas("c", "",1120,800);
   c->cd();
   
   THStack *hs = new THStack("hs",title.c_str());
   
   hs->Add(p_AEEREB);
   hs->Add(p_AEEREE);
   hs->Add(p_AEERHB);
   hs->Add(p_AEERHE);
   hs->Add(p_AEERHFl);
   hs->Add(p_AEERHFs);
   //hs->Add(p_AEERHO);
   hs->Draw("hist");
   
   TLegend *legend = new TLegend(.6,.55,.68,.85);
   legend->SetBorderSize(1);
   legend->SetFillColor(0);
   //legend->SetFillStyle(0);
   legend->SetTextFont(42);
   legend->AddEntry(p_AEEREB,"EB","f");
   legend->AddEntry(p_AEEREE,"EE","f");
   legend->AddEntry(p_AEERHB,"HB","f");
   legend->AddEntry(p_AEERHE,"HE","f");
   legend->AddEntry(p_AEERHFl,"HFl","f");
   legend->AddEntry(p_AEERHFs,"HFs","f");
   //legend->AddEntry(p_AEERHO,"HO","f");
   legend->Draw();
   
   string fileName = "p_NormAvgEinER_stacked__" + fNameExt + ".png";
   
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
//    stack_in_cone_contribs(noise_only_05, "for Noise-only (CMSSW_2_1_8, IDEAL_V9)", "Noise-only_ET0.5");

   // *** pile-up ***
//    stack_ring_contribs(onePU_IT_F_05, "for 1PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Fixed_ET0.5");
//    stack_ring_contribs(onePU_IT_P_05, "for 1PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Poisson_ET0.5");
//    stack_ring_contribs(onePU_F_P_05, "for 1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_Full_Poisson_ET0.5");
//    
//    stack_ring_contribs(twoPU_IT_F_05, "for 2PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Fixed_ET0.5");
//    stack_ring_contribs(twoPU_IT_P_05, "for 2PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Poisson_ET0.5");
//    stack_ring_contribs(twoPU_F_P_05, "for 2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_Full_Poisson_ET0.5");
// 
//    stack_ring_contribs(fivePU_IT_F_05, "for 5PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Fixed_ET0.5");
//    stack_ring_contribs(fivePU_IT_P_05, "for 5PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Poisson_ET0.5");
//    stack_ring_contribs(fivePU_F_P_05, "for 5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_Full_Poisson_ET0.5");
//    // normalized contributions
//    stack_norm_ring_contribs(onePU_IT_F_05, "for 1PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Fixed_ET0.5");
//    stack_norm_ring_contribs(onePU_IT_P_05, "for 1PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_InTime_Poisson_ET0.5");
//    stack_norm_ring_contribs(onePU_F_P_05, "for 1PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "1PU_Full_Poisson_ET0.5");
//    
//    stack_norm_ring_contribs(twoPU_IT_F_05, "for 2PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Fixed_ET0.5");
//    stack_norm_ring_contribs(twoPU_IT_P_05, "for 2PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_InTime_Poisson_ET0.5");
//    stack_norm_ring_contribs(twoPU_F_P_05, "for 2PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "2PU_Full_Poisson_ET0.5");
// 
//    stack_norm_ring_contribs(fivePU_IT_F_05, "for 5PU (in-time, fixed) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Fixed_ET0.5");
//    stack_norm_ring_contribs(fivePU_IT_P_05, "for 5PU (in-time, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_InTime_Poisson_ET0.5");
//    stack_norm_ring_contribs(fivePU_F_P_05, "for 5PU (full, Poisson) (CMSSW_2_1_8, IDEAL_V9)", "5PU_Full_Poisson_ET0.5");
}