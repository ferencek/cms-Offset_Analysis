// -*- C++ -*-
//
// Package:    ClosureAnalysis
// Class:      ClosureAnalysis
// 
/**\class ClosureAnalysis ClosureAnalysis.cc AnalysisCode/OffsetAnalysis/src/ClosureAnalysis.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  "Dinko Ferencek"
//         Created:  Sat Nov  8 19:31:22 CST 2008
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/Candidate/interface/CandMatchMap.h"
#include "DataFormats/Candidate/interface/CandMatchMapMany.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

//TFile Service
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "PhysicsTools/UtilAlgos/interface/TFileService.h"

// ROOT
#include <TROOT.h>
#include <TSystem.h>
#include <TStyle.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TProfile.h>

#include <Math/VectorUtil.h>

using namespace std;
using namespace edm;
using namespace reco;
using namespace ROOT::Math::VectorUtil;

//
// class declaration
//

class ClosureAnalysis : public edm::EDAnalyzer {
   public:
      explicit ClosureAnalysis(const edm::ParameterSet&);
      ~ClosureAnalysis();


   private:
      virtual void beginJob(const edm::EventSetup&) ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;
      double getCorrection(const TProfile*, double);

      // ----------member data ---------------------------
      edm::Service<TFileService> fs;
      
      Handle<CandidateCollection> source;
      Handle<CandidateCollection> matched;
      Handle<CandMatchMapMany>    caloGenMatchedJetsMany;
      Handle<CandMatchMapMany>    caloCaloMatchedJetsMany;
      Handle<VertexCollection> pvCollection;
         
      InputTag source_;
      InputTag matched_;
      InputTag caloGenMatchedJetsMany_;
      InputTag caloCaloMatchedJetsMany_;
      InputTag pvCollection_;
            
      double dR_max;
      double iso_dR;
      bool doCorr_;
      bool doPVs_;
      int maxNPVs_;
      int minNPVs;
      string offsetCorrPath_;
      
      TH1F *h_CaloJetEta; 
      TH1F *h_GenJetpT;
      TH1F *h_CaloCaloDeltaR; 
      TH1F *h_CaloGenDeltaR;
      TH1F *h_GenJetMatches;
      TH2F *h_CaloJetpToverGenJetpT_pT;
      TProfile *p_CaloJetpToverGenJetpT_pT;
      TProfile *p_CaloJetpToverGenJetpT_pT_B;
      TH2F *h_CaloJetpToverGenJetpT_pT_B;
      TProfile *p_CaloJetpToverGenJetpT_pT_E;
      TH2F *h_CaloJetpToverGenJetpT_pT_E;
      TProfile *p_CaloJetpToverGenJetpT_pT_F;
      TH2F *h_CaloJetpToverGenJetpT_pT_F;
      TProfile *p_CaloJetpToverGenJetpT_eta_pT15_20;
      TProfile *p_CaloJetpToverGenJetpT_eta_pT20_25;
      TProfile *p_CaloJetpToverGenJetpT_eta_pT25_30;
      TProfile *p_CaloJetpToverGenJetpT_eta_pT30_40;
      TProfile *p_CaloJetpToverGenJetpT_eta_pT40_50;
      TProfile *p_CaloJetpToverGenJetpT_eta_pT50_70;
      TProfile *p_CaloJetpToverGenJetpT_eta_pT70_100;
      TProfile *p_CaloJetEoverGenJetE_pT;
      TProfile *p_CaloJetEoverGenJetE_pT_B;
      TProfile *p_CaloJetEoverGenJetE_pT_E;
      TProfile *p_CaloJetEoverGenJetE_pT_F;
      TProfile *p_CaloJetEoverGenJetE_eta_pT15_20;
      TProfile *p_CaloJetEoverGenJetE_eta_pT20_25;
      TProfile *p_CaloJetEoverGenJetE_eta_pT25_30;
      TProfile *p_CaloJetEoverGenJetE_eta_pT30_40;
      TProfile *p_CaloJetEoverGenJetE_eta_pT40_50;
      TProfile *p_CaloJetEoverGenJetE_eta_pT50_70;
      TProfile *p_CaloJetEoverGenJetE_eta_pT70_100;
      
      map<int, TH2F*> h_CaloJetpToverGenJetpT_pT_NPV;
      map<int, TProfile*> p_CaloJetpToverGenJetpT_pT_NPV;
      map<int, TProfile*> p_CaloJetpToverGenJetpT_pT_B_NPV;
      map<int, TH2F*> h_CaloJetpToverGenJetpT_pT_B_NPV;
      map<int, TProfile*> p_CaloJetpToverGenJetpT_pT_E_NPV;
      map<int, TH2F*> h_CaloJetpToverGenJetpT_pT_E_NPV;
      map<int, TProfile*> p_CaloJetpToverGenJetpT_pT_F_NPV;
      map<int, TH2F*> h_CaloJetpToverGenJetpT_pT_F_NPV;
      map<int, TProfile*> p_CaloJetpToverGenJetpT_eta_pT15_20_NPV;
      map<int, TProfile*> p_CaloJetpToverGenJetpT_eta_pT20_25_NPV;
      map<int, TProfile*> p_CaloJetpToverGenJetpT_eta_pT25_30_NPV;
      map<int, TProfile*> p_CaloJetpToverGenJetpT_eta_pT30_40_NPV;
      map<int, TProfile*> p_CaloJetpToverGenJetpT_eta_pT40_50_NPV;
      map<int, TProfile*> p_CaloJetpToverGenJetpT_eta_pT50_70_NPV;
      map<int, TProfile*> p_CaloJetpToverGenJetpT_eta_pT70_100_NPV;
      
      TFile *offsetCorrFile;
      TDirectoryFile *offsetCorrDir;
      TDirectoryFile *offsetCorrSubDir;
      TProfile *pTcorr;
      TProfile *Ecorr;
      map<int, TProfile*> pTcorrNPV;
      map<int, TProfile*> EcorrNPV;
      
      TH1F *h_NofPVs;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
ClosureAnalysis::ClosureAnalysis(const edm::ParameterSet& iConfig)
{
   // now do what ever initialization is needed
   source_                  = iConfig.getParameter<InputTag> ("src");
   matched_                 = iConfig.getParameter<InputTag> ("matched");
   caloGenMatchedJetsMany_  = iConfig.getParameter<InputTag> ("caloGenMatchMapMany");
   caloCaloMatchedJetsMany_ = iConfig.getParameter<InputTag> ("caloCaloMatchMapMany");
   dR_max           = iConfig.getParameter<double>("deltaR_max");
   iso_dR           = iConfig.getParameter<double>("iso_deltaR");
   doCorr_          = iConfig.getParameter<bool>("doCorr");
   doPVs_           = iConfig.getParameter<bool>("doPVs");
   maxNPVs_         = iConfig.getParameter<int>("maxNPVs");
   pvCollection_    = iConfig.getParameter<InputTag>("pvCollection");
   offsetCorrPath_  = iConfig.getParameter<string>("offsetCorrPath");
}


ClosureAnalysis::~ClosureAnalysis()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called once each job just before starting event loop  ------------
void 
ClosureAnalysis::beginJob(const edm::EventSetup&)
{
   minNPVs = 0;
   if ( doCorr_ ) minNPVs = 1; // offset correction for QCD+PU with NPV=0 does not exist

   // book all histograms
   h_CaloJetEta = fs->make<TH1F>("h_CaloJetEta",";#eta^{calo};Entries/0.2",50,-5.,5.);
   h_GenJetpT   = fs->make<TH1F>("h_GenJetpT",";p_{T}^{gen} [GeV/c];Entries/(1 GeV/c)",100,0.,100.);
   h_CaloCaloDeltaR = fs->make<TH1F>("h_CaloCaloDeltaR","#DeltaR(CaloJet_{i},CaloJet_{j});#DeltaR;Entries/0.02",100,0.,2.);
   h_CaloGenDeltaR  = fs->make<TH1F>("h_CaloGenDeltaR","#DeltaR(CaloJet_{i},GenJet_{j});#DeltaR;Entries/0.02",100,0.,2.);
   h_GenJetMatches  = fs->make<TH1F>("h_GenMatches","# of GenJets with #DeltaR<0.25;# of GenJets;Entries",4,-0.5,3.5);
   float Xbins[8] = {15,20,25,30,40,50,70,100};
   // CaloJetpT/GenJetpT histograms
   h_CaloJetpToverGenJetpT_pT = fs->make<TH2F>("h_CaloJetpToverGenJetpT_pT",";p_{T}^{gen} [GeV/c];p_{T}^{calo}/p_{T}^{gen}",100,0.,100.,150,0.,1.5);
   p_CaloJetpToverGenJetpT_pT = fs->make<TProfile>("p_CaloJetpToverGenJetpT_pT",";p_{T}^{gen} [GeV/c];<p_{T}^{calo}/p_{T}^{gen}>",7,Xbins);
   h_CaloJetpToverGenJetpT_pT_B = fs->make<TH2F>("h_CaloJetpToverGenJetpT_pT_B","|#eta^{calo}|<1.3;p_{T}^{gen} [GeV/c];p_{T}^{calo}/p_{T}^{gen}",100,0.,100.,150,0.,1.5);
   p_CaloJetpToverGenJetpT_pT_B = fs->make<TProfile>("p_CaloJetpToverGenJetpT_pT_B","|#eta^{calo}|<1.3;p_{T}^{gen} [GeV/c];<p_{T}^{calo}/p_{T}^{gen}>",7,Xbins);
   h_CaloJetpToverGenJetpT_pT_E = fs->make<TH2F>("h_CaloJetpToverGenJetpT_pT_E","1.3<|#eta^{calo}|<2.8;p_{T}^{gen} [GeV/c];p_{T}^{calo}/p_{T}^{gen}",100,0.,100.,150,0.,1.5);
   p_CaloJetpToverGenJetpT_pT_E = fs->make<TProfile>("p_CaloJetpToverGenJetpT_pT_E","1.3<|#eta^{calo}|<2.8;p_{T}^{gen} [GeV/c];<p_{T}^{calo}/p_{T}^{gen}>",7,Xbins);
   h_CaloJetpToverGenJetpT_pT_F = fs->make<TH2F>("h_CaloJetpToverGenJetpT_pT_F","|#eta^{calo}|>2.8;p_{T}^{gen} [GeV/c];p_{T}^{calo}/p_{T}^{gen}",100,0.,100.,150,0.,1.5);
   p_CaloJetpToverGenJetpT_pT_F = fs->make<TProfile>("p_CaloJetpToverGenJetpT_pT_F","|#eta^{calo}|>2.8;p_{T}^{gen} [GeV/c];<p_{T}^{calo}/p_{T}^{gen}>",7,Xbins);
   p_CaloJetpToverGenJetpT_eta_pT15_20 = fs->make<TProfile>("p_CaloJetpToverGenJetpT_eta_pT15_20","15<p_{T}^{gen}<20 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
   p_CaloJetpToverGenJetpT_eta_pT20_25 = fs->make<TProfile>("p_CaloJetpToverGenJetpT_eta_pT20_25","20<p_{T}^{gen}<25 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
   p_CaloJetpToverGenJetpT_eta_pT25_30 = fs->make<TProfile>("p_CaloJetpToverGenJetpT_eta_pT25_30","25<p_{T}^{gen}<30 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
   p_CaloJetpToverGenJetpT_eta_pT30_40 = fs->make<TProfile>("p_CaloJetpToverGenJetpT_eta_pT30_40","30<p_{T}^{gen}<40 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
   p_CaloJetpToverGenJetpT_eta_pT40_50 = fs->make<TProfile>("p_CaloJetpToverGenJetpT_eta_pT40_50","40<p_{T}^{gen}<50 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
   p_CaloJetpToverGenJetpT_eta_pT50_70 = fs->make<TProfile>("p_CaloJetpToverGenJetpT_eta_pT50_70","50<p_{T}^{gen}<70 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
   p_CaloJetpToverGenJetpT_eta_pT70_100 = fs->make<TProfile>("p_CaloJetpToverGenJetpT_eta_pT70_100","70<p_{T}^{gen}<100 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
   // CaloJetE/GenJetE histograms
   p_CaloJetEoverGenJetE_pT = fs->make<TProfile>("p_CaloJetEoverGenJetE_pT","<E^{calo}/E^{gen}>;p_{T}^{gen} [GeV/c]",7,Xbins);
   p_CaloJetEoverGenJetE_pT_B = fs->make<TProfile>("p_CaloJetEoverGenJetE_pT_B","|#eta^{calo}|<1.3;p_{T}^{gen} [GeV/c];<E^{calo}/E^{gen}>",7,Xbins);
   p_CaloJetEoverGenJetE_pT_E = fs->make<TProfile>("p_CaloJetEoverGenJetE_pT_E","1.3<|#eta^{calo}|<2.8;p_{T}^{gen} [GeV/c];<E^{calo}/E^{gen}>",7,Xbins);
   p_CaloJetEoverGenJetE_pT_F = fs->make<TProfile>("p_CaloJetEoverGenJetE_pT_F","|#eta^{calo}|>2.8;p_{T}^{gen} [GeV/c];<E^{calo}/E^{gen}>",7,Xbins);
   p_CaloJetEoverGenJetE_eta_pT15_20 = fs->make<TProfile>("p_CaloJetEoverGenJetE_eta_pT15_20","15<p_{T}^{gen}<20 GeV/c;#eta^{calo};<E^{calo}/E^{gen}>",50,-5.,5.);
   p_CaloJetEoverGenJetE_eta_pT20_25 = fs->make<TProfile>("p_CaloJetEoverGenJetE_eta_pT20_25","20<p_{T}^{gen}<25 GeV/c;#eta^{calo};<E^{calo}/E^{gen}>",50,-5.,5.);
   p_CaloJetEoverGenJetE_eta_pT25_30 = fs->make<TProfile>("p_CaloJetEoverGenJetE_eta_pT25_30","25<p_{T}^{gen}<30 GeV/c;#eta^{calo};<E^{calo}/E^{gen}>",50,-5.,5.);
   p_CaloJetEoverGenJetE_eta_pT30_40 = fs->make<TProfile>("p_CaloJetEoverGenJetE_eta_pT30_40","30<p_{T}^{gen}<40 GeV/c;#eta^{calo};<E^{calo}/E^{gen}>",50,-5.,5.);
   p_CaloJetEoverGenJetE_eta_pT40_50 = fs->make<TProfile>("p_CaloJetEoverGenJetE_eta_pT40_50","40<p_{T}^{gen}<50 GeV/c;#eta^{calo};<E^{calo}/E^{gen}>",50,-5.,5.);
   p_CaloJetEoverGenJetE_eta_pT50_70 = fs->make<TProfile>("p_CaloJetEoverGenJetE_eta_pT50_70","50<p_{T}^{gen}<70 GeV/c;#eta^{calo};<E^{calo}/E^{gen}>",50,-5.,5.);
   p_CaloJetEoverGenJetE_eta_pT70_100 = fs->make<TProfile>("p_CaloJetEoverGenJetE_eta_pT70_100","70<p_{T}^{gen}<100 GeV/c;#eta^{calo};<E^{calo}/E^{gen}>",50,-5.,5.);
   
   // PV dependent CaloJetpT/GenJetpT histograms
   if ( doPVs_ ) {
      TFileDirectory pvSubDir = fs->mkdir( "PVDependent" );
      h_NofPVs = pvSubDir.make<TH1F>("h_NofPVs","Number of Reconstructed PV's;# of PV's;Entries",11,-.5,10.5);
      
      string name = "CaloJetpToverGenJetpT";
      
      for (int i = minNPVs; i <= maxNPVs_; i++) {
         char NPVs[1024];
         sprintf (NPVs, "%i", i);
         
         h_CaloJetpToverGenJetpT_pT_NPV[i] = pvSubDir.make<TH2F>(("h_" + name + "_pT_NPV" + NPVs).c_str(),";p_{T}^{gen} [GeV/c];p_{T}^{calo}/p_{T}^{gen}",100,0.,100.,150,0.,1.5);
         p_CaloJetpToverGenJetpT_pT_NPV[i] = pvSubDir.make<TProfile>(("p_" + name + "_pT_NPV" + NPVs).c_str(),";p_{T}^{gen} [GeV/c];<p_{T}^{calo}/p_{T}^{gen}>",7,Xbins);
         h_CaloJetpToverGenJetpT_pT_B_NPV[i] = pvSubDir.make<TH2F>(("h_" + name + "_pT_B_NPV" + NPVs).c_str(),"|#eta^{calo}|<1.3;p_{T}^{gen} [GeV/c];p_{T}^{calo}/p_{T}^{gen}",100,0.,100.,150,0.,1.5);
         p_CaloJetpToverGenJetpT_pT_B_NPV[i] = pvSubDir.make<TProfile>(("p_" + name + "_pT_B_NPV" + NPVs).c_str(),"|#eta^{calo}|<1.3;p_{T}^{gen} [GeV/c];<p_{T}^{calo}/p_{T}^{gen}>",7,Xbins);
         h_CaloJetpToverGenJetpT_pT_E_NPV[i] = pvSubDir.make<TH2F>(("h_" + name + "_pT_E_NPV" + NPVs).c_str(),"1.3<|#eta^{calo}|<2.8;p_{T}^{gen} [GeV/c];p_{T}^{calo}/p_{T}^{gen}",100,0.,100.,150,0.,1.5);
         p_CaloJetpToverGenJetpT_pT_E_NPV[i] = pvSubDir.make<TProfile>(("p_" + name + "_pT_E_NPV" + NPVs).c_str(),"1.3<|#eta^{calo}|<2.8;p_{T}^{gen} [GeV/c];<p_{T}^{calo}/p_{T}^{gen}>",7,Xbins);
         h_CaloJetpToverGenJetpT_pT_F_NPV[i] = pvSubDir.make<TH2F>(("h_" + name + "_pT_F_NPV" + NPVs).c_str(),"|#eta^{calo}|>2.8;p_{T}^{gen} [GeV/c];p_{T}^{calo}/p_{T}^{gen}",100,0.,100.,150,0.,1.5);
         p_CaloJetpToverGenJetpT_pT_F_NPV[i] = pvSubDir.make<TProfile>(("p_" + name + "_pT_F_NPV" + NPVs).c_str(),"|#eta^{calo}|>2.8;p_{T}^{gen} [GeV/c];<p_{T}^{calo}/p_{T}^{gen}>",7,Xbins);
         p_CaloJetpToverGenJetpT_eta_pT15_20_NPV[i] = pvSubDir.make<TProfile>(("p_" + name + "_eta_pT15_20_NPV" + NPVs).c_str(),"15<p_{T}^{gen}<20 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
         p_CaloJetpToverGenJetpT_eta_pT20_25_NPV[i] = pvSubDir.make<TProfile>(("p_" + name + "_eta_pT20_25_NPV" + NPVs).c_str(),"20<p_{T}^{gen}<25 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
         p_CaloJetpToverGenJetpT_eta_pT25_30_NPV[i] = pvSubDir.make<TProfile>(("p_" + name + "_eta_pT25_30_NPV" + NPVs).c_str(),"25<p_{T}^{gen}<30 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
         p_CaloJetpToverGenJetpT_eta_pT30_40_NPV[i] = pvSubDir.make<TProfile>(("p_" + name + "_eta_pT30_40_NPV" + NPVs).c_str(),"30<p_{T}^{gen}<40 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
         p_CaloJetpToverGenJetpT_eta_pT40_50_NPV[i] = pvSubDir.make<TProfile>(("p_" + name + "_eta_pT40_50_NPV" + NPVs).c_str(),"40<p_{T}^{gen}<50 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
         p_CaloJetpToverGenJetpT_eta_pT50_70_NPV[i] = pvSubDir.make<TProfile>(("p_" + name + "_eta_pT50_70_NPV" + NPVs).c_str(),"50<p_{T}^{gen}<70 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
         p_CaloJetpToverGenJetpT_eta_pT70_100_NPV[i] = pvSubDir.make<TProfile>(("p_" + name + "_eta_pT70_100_NPV" + NPVs).c_str(),"70<p_{T}^{gen}<100 GeV/c;#eta^{calo};<p_{T}^{calo}/p_{T}^{gen}>",50,-5.,5.);
      }
   }
   
   // if offset correction is going to be performed
   if ( doCorr_ && !doPVs_ ) {
      offsetCorrFile = new TFile(offsetCorrPath_.c_str(),"READ");
      offsetCorrDir = (TDirectoryFile*)offsetCorrFile->Get("offsetAnalysis");
      pTcorr = (TProfile*)offsetCorrDir->Get("p_AvgpTinC5");
      Ecorr = (TProfile*)offsetCorrDir->Get("p_AvgEinC5");
   }
   else if ( doCorr_ && doPVs_ ) { // if PV dependent offset correction is going to be performed
      offsetCorrFile = new TFile(offsetCorrPath_.c_str(),"READ");
      offsetCorrDir = (TDirectoryFile*)offsetCorrFile->Get("offsetAnalysis");
      offsetCorrSubDir = (TDirectoryFile*)offsetCorrDir->Get("PVOffset");
      for (int i = 0; i < maxNPVs_; i++) {
         char AvgpTProf[1024];
         char AvgEProf[1024];
         sprintf (AvgpTProf, "p_AvgpTinC5NPV%i", i);
         sprintf (AvgEProf, "p_AvgEinC5NPV%i", i);
         
         pTcorrNPV[i]  = (TProfile*)offsetCorrSubDir->Get(AvgpTProf);
         EcorrNPV[i] = (TProfile*)offsetCorrSubDir->Get(AvgEProf);
      }
   }
   // debug
//    cout<<" >> ++++++++++++ begin job executed!"<<endl;
}

// ------------ method called to for each event  ------------
void
ClosureAnalysis::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   // debug
//    cout<<" >> ++++++++++++ analyze started!"<<endl;
//    // Debugging
//    if (doCorr_ && !doPVs_) {
//       cout<<">> ============== Debugging output: !doPVs ================"<<endl;
//       cout<<">> pTcorr(1.0) = "<<getCorrection(pTcorr,1.0)<<endl;
//    } else if (doCorr_ && doPVs_) {
//       cout<<">> ============== Debugging output: doPVs ================"<<endl;
//       cout<<">> pTcorrNPV0(1.0) = "<<getCorrection(pTcorrNPV[0],1.0)<<endl;
//       cout<<">> pTcorrNPV1(1.0) = "<<getCorrection(pTcorrNPV[1],1.0)<<endl;
//       cout<<">> pTcorrNPV2(1.0) = "<<getCorrection(pTcorrNPV[2],1.0)<<endl;
//    }
   // ==========================================
   // ======= Primary Vertices ==========
   // ==========================================
   int nPV = 0;    // number of reconstructed Primary Vertices
   bool PVcond = true;
   if ( doPVs_ ) {
      // get PV collection
      try {
          iEvent.getByLabel(pvCollection_, pvCollection);
      } catch(std::exception& ce) {
          cerr << "[ClosureAnalysis] caught std::exception " << ce.what() << endl;
          return;
      }
      // loop over all Primary Vertices
      for ( VertexCollection::const_iterator pv = pvCollection->begin(); pv != pvCollection->end(); ++pv ) {
         if ( !pv->isFake() ) nPV++;
      }
      // fill in the number of valid reconstructed primary vertices
      h_NofPVs->Fill( nPV );
      // debug
//       cout<<" >> ++++++++++++ NPVs = "<<nPV<<endl;
//       cout<<" >> ++++++++++++ minNPVs = "<<minNPVs<<endl;
      if ( nPV < minNPVs || nPV > maxNPVs_ ) PVcond = false;
   }
   // debug
//    cout<<" >> ++++++++++++ PV part executed!"<<endl;
   // ==========================================
   // ============== Closure Test ==============
   // ==========================================
   try {
      iEvent.getByLabel (source_,source);
      iEvent.getByLabel (matched_,matched);
      iEvent.getByLabel (caloGenMatchedJetsMany_, caloGenMatchedJetsMany);
      iEvent.getByLabel (caloCaloMatchedJetsMany_, caloCaloMatchedJetsMany);
   } catch(std::exception& ce) {
      cerr << "[ClosureAnalysis] caught std::exception " << ce.what() << endl;
      return;
   }
   // debug
//    cout<<" >> ++++++++++++ getByLabel part executed!"<<endl;
   // loop over all CaloJets
   for( CandMatchMapMany::const_iterator cg = caloGenMatchedJetsMany->begin();
                                         cg != caloGenMatchedJetsMany->end();
                                         cg++ ) {
      // debug
//       cout<<" >> ++++++++++++ entered CaloJet loop!"<<endl;
      const Candidate *sourceRef = &*(cg->key);
      bool isIsolated = true;
      // check if a given CaloJet is isolated from other CaloJets
      for( CandMatchMapMany::const_iterator cc = caloCaloMatchedJetsMany->begin();
                                            cc != caloCaloMatchedJetsMany->end();
                                            cc++ ) {
         const Candidate *ccSourceRef = &*(cc->key);
	 // find a given CaloJet in the MatchMap and check its distance from other CaloJets
         if ( sourceRef == ccSourceRef ) {
	    const vector< pair<CandidateRef, double> > vectMatched = cc->val;
            vector< pair<CandidateRef, double> >::const_iterator matchIter;
            for ( matchIter = vectMatched.begin(); matchIter != vectMatched.end(); matchIter++ ) {
	       //const Candidate *matchedRef = &*( (*matchIter).first );
	       double dR = (*matchIter).second;
	       // if dR from any other CaloJet is less than iso_dR, CaloJet is considered as non-isolated 
	       if (dR > 0.001 && dR < iso_dR) {
		  isIsolated = false;
		  h_CaloCaloDeltaR->Fill(dR);
		  break;
	       }
            }
	 }
      }
      // debug
//       cout<<" >> ++++++++++++ isIsolated part executed!"<<endl;
      // if a given CaloJet is isolated from other CaloJets, also check that there is only one GenJet with dR<dR_max
      if ( isIsolated ) {
	 int nMatchedGenJets = 0;
	 double deltaR = -1.;
         double matchedGenJetpT = -1.;
	 double matchedGenJetE = -1.;
	 const vector< pair<CandidateRef, double> > vectMatched = cg->val;
	 vector< pair<CandidateRef, double> >::const_iterator matchIter;
	 for ( matchIter = vectMatched.begin(); matchIter != vectMatched.end(); matchIter++ ) {
	    const Candidate *matchedRef = &*( (*matchIter).first );
	    double dR = (*matchIter).second;
	    //h_CaloGenDeltaR->Fill(dR);
	    if ( deltaR < 0 && dR < dR_max) {
	       deltaR = dR;
	       matchedGenJetpT = matchedRef->pt();
	       matchedGenJetE = matchedRef->energy();
	       nMatchedGenJets++;
	    } else if ( deltaR > 0 && dR < deltaR ) {
	       deltaR = dR;
	       matchedGenJetpT = matchedRef->pt();
	       matchedGenJetE = matchedRef->energy();
	       nMatchedGenJets++;
	    }
	 }
	 h_GenJetMatches->Fill(nMatchedGenJets);
	 // fill the histograms if there is only one GenJet with dR<dR_max and |CaloJet eta|<5 (offset correction was not derived for |CaloJet eta|>5)
	 double caloJetEta = sourceRef->eta();
	 // debug
//          cout<<" >> ++++++++++++ nMatchedGenJets part executed!"<<endl;
//          cout<<" >> ++++++++++++ nMatchedGenJets = "<<nMatchedGenJets<<endl;
	 if ( nMatchedGenJets == 1 && fabs(caloJetEta)<5 ) {
	    double caloJetpT = 0;
	    double caloJetE = 0;
	    if ( doCorr_ && !doPVs_ ) {
	       // debug
//                cout<<" >> ++++++++++++ entered PV independent caloJetpT correction!"<<endl;
	       caloJetpT = sourceRef->pt()-getCorrection(pTcorr,caloJetEta);
	       caloJetE = sourceRef->energy()-getCorrection(Ecorr,caloJetEta);
	    } else if ( doCorr_ && doPVs_ && PVcond ) {
	       // debug
//                cout<<" >> ++++++++++++ entered PV dependent caloJetpT correction!"<<endl;
	       caloJetpT = sourceRef->pt()-getCorrection(pTcorrNPV[nPV-1],caloJetEta);
	       caloJetE = sourceRef->energy()-getCorrection(EcorrNPV[nPV-1],caloJetEta);
	    } else {
	       // debug
//                cout<<" >> ++++++++++++ no correction for caloJetpT!"<<endl;
	       caloJetpT = sourceRef->pt();
	       caloJetE = sourceRef->energy();
	    }
	    // debug
//             cout<<" >> ++++++++++++ caloJetpT part executed!"<<endl;
	    double pT_ratio = caloJetpT/matchedGenJetpT;
	    double E_ratio = caloJetE/matchedGenJetE;
	    h_CaloGenDeltaR->Fill(deltaR);
	    h_GenJetpT->Fill(matchedGenJetpT);
	    h_CaloJetEta->Fill(caloJetEta);
            h_CaloJetpToverGenJetpT_pT->Fill(matchedGenJetpT,pT_ratio);
	    p_CaloJetpToverGenJetpT_pT->Fill(matchedGenJetpT,pT_ratio);
	    p_CaloJetEoverGenJetE_pT->Fill(matchedGenJetpT,E_ratio);
	    // debug
//             cout<<" >> ++++++++++++ doPVs_ = "<<doPVs_<<endl;
//             cout<<" >> ++++++++++++ PVcond = "<<PVcond<<endl;
	    if ( doPVs_ && PVcond ) {
               h_CaloJetpToverGenJetpT_pT_NPV[nPV]->Fill(matchedGenJetpT,pT_ratio);
               p_CaloJetpToverGenJetpT_pT_NPV[nPV]->Fill(matchedGenJetpT,pT_ratio);
               // debug
//                cout<<" >> ++++++++++++ CaloJetpToverGenJetpT_pT_NPV part executed!"<<endl;
//                cout<<" >> ++++++++++++ NPVs = "<<nPV<<endl;
	    }
	    // fill the histograms for different CaloJet eta bins
	    if ( fabs(caloJetEta)<1.3 ) {
               h_CaloJetpToverGenJetpT_pT_B->Fill(matchedGenJetpT,pT_ratio);
	       p_CaloJetpToverGenJetpT_pT_B->Fill(matchedGenJetpT,pT_ratio);
	       p_CaloJetEoverGenJetE_pT_B->Fill(matchedGenJetpT,E_ratio);
	       if ( doPVs_ && PVcond ) {
                  h_CaloJetpToverGenJetpT_pT_B_NPV[nPV]->Fill(matchedGenJetpT,pT_ratio);
                  p_CaloJetpToverGenJetpT_pT_B_NPV[nPV]->Fill(matchedGenJetpT,pT_ratio);
	       }
	    } else if ( fabs(caloJetEta)>=1.3 && fabs(caloJetEta)<2.8 ) {
               h_CaloJetpToverGenJetpT_pT_E->Fill(matchedGenJetpT,pT_ratio);
	       p_CaloJetpToverGenJetpT_pT_E->Fill(matchedGenJetpT,pT_ratio);
	       p_CaloJetEoverGenJetE_pT_E->Fill(matchedGenJetpT,E_ratio);
	       if ( doPVs_ && PVcond ) {
                  h_CaloJetpToverGenJetpT_pT_E_NPV[nPV]->Fill(matchedGenJetpT,pT_ratio);
                  p_CaloJetpToverGenJetpT_pT_E_NPV[nPV]->Fill(matchedGenJetpT,pT_ratio);
	       }
	    } else if ( fabs(caloJetEta)>=2.8 ) {
               h_CaloJetpToverGenJetpT_pT_F->Fill(matchedGenJetpT,pT_ratio);
	       p_CaloJetpToverGenJetpT_pT_F->Fill(matchedGenJetpT,pT_ratio);
	       p_CaloJetEoverGenJetE_pT_F->Fill(matchedGenJetpT,E_ratio);
	       if ( doPVs_ && PVcond ) {
                  h_CaloJetpToverGenJetpT_pT_F_NPV[nPV]->Fill(matchedGenJetpT,pT_ratio);
                  p_CaloJetpToverGenJetpT_pT_F_NPV[nPV]->Fill(matchedGenJetpT,pT_ratio);
	       }
	    }
	    // fill the histograms for different GenJet pT bins
	    if ( matchedGenJetpT>=15 && matchedGenJetpT<20 ) {
	       p_CaloJetpToverGenJetpT_eta_pT15_20->Fill(caloJetEta,pT_ratio);
	       p_CaloJetEoverGenJetE_eta_pT15_20->Fill(caloJetEta,E_ratio);
	       if ( doPVs_ && PVcond ) {
	          p_CaloJetpToverGenJetpT_eta_pT15_20_NPV[nPV]->Fill(caloJetEta,pT_ratio);
	       }
	    } else if ( matchedGenJetpT>=20 && matchedGenJetpT<25 ) {
	       p_CaloJetpToverGenJetpT_eta_pT20_25->Fill(caloJetEta,pT_ratio);
	       p_CaloJetEoverGenJetE_eta_pT20_25->Fill(caloJetEta,E_ratio);
	       if ( doPVs_ && PVcond ) {
	          p_CaloJetpToverGenJetpT_eta_pT20_25_NPV[nPV]->Fill(caloJetEta,pT_ratio);
	       }
	    } else if ( matchedGenJetpT>=25 && matchedGenJetpT<30 ) {
	       p_CaloJetpToverGenJetpT_eta_pT25_30->Fill(caloJetEta,pT_ratio);
	       p_CaloJetEoverGenJetE_eta_pT25_30->Fill(caloJetEta,E_ratio);
	       if ( doPVs_ && PVcond ) {
	          p_CaloJetpToverGenJetpT_eta_pT25_30_NPV[nPV]->Fill(caloJetEta,pT_ratio);
	       }
	    } else if ( matchedGenJetpT>=30 && matchedGenJetpT<40 ) {
	       p_CaloJetpToverGenJetpT_eta_pT30_40->Fill(caloJetEta,pT_ratio);
	       p_CaloJetEoverGenJetE_eta_pT30_40->Fill(caloJetEta,E_ratio);
	       if ( doPVs_ && PVcond ) {
	          p_CaloJetpToverGenJetpT_eta_pT30_40_NPV[nPV]->Fill(caloJetEta,pT_ratio);
	       }
	    } else if ( matchedGenJetpT>=40 && matchedGenJetpT<50 ) {
	       p_CaloJetpToverGenJetpT_eta_pT40_50->Fill(caloJetEta,pT_ratio);
	       p_CaloJetEoverGenJetE_eta_pT40_50->Fill(caloJetEta,E_ratio);
	       if ( doPVs_ && PVcond ) {
	          p_CaloJetpToverGenJetpT_eta_pT40_50_NPV[nPV]->Fill(caloJetEta,pT_ratio);
	       }
	    } else if ( matchedGenJetpT>=50 && matchedGenJetpT<70 ) {
	       p_CaloJetpToverGenJetpT_eta_pT50_70->Fill(caloJetEta,pT_ratio);
	       p_CaloJetEoverGenJetE_eta_pT50_70->Fill(caloJetEta,E_ratio);
	       if ( doPVs_ && PVcond ) {
	          p_CaloJetpToverGenJetpT_eta_pT50_70_NPV[nPV]->Fill(caloJetEta,pT_ratio);
	       }
	    } else if ( matchedGenJetpT>=70 && matchedGenJetpT<100 ) {
	       p_CaloJetpToverGenJetpT_eta_pT70_100->Fill(caloJetEta,pT_ratio);
	       p_CaloJetEoverGenJetE_eta_pT70_100->Fill(caloJetEta,E_ratio);
	       if ( doPVs_ && PVcond ) {
	          p_CaloJetpToverGenJetpT_eta_pT70_100_NPV[nPV]->Fill(caloJetEta,pT_ratio);
	       }
	    }
	 }
      }
   }
   // debug
//    cout<<" >> ++++++++++++ analysis finished!"<<endl;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
ClosureAnalysis::endJob() {
   // debug
//    cout<<" >> ++++++++++++ end job executed!"<<endl;
}

double ClosureAnalysis::getCorrection(const TProfile *fCorr, const double fEta)
{
   Int_t bin = fCorr->GetXaxis()->FindBin(fEta);
   return fCorr->GetBinContent(bin);
}

//define this as a plug-in
DEFINE_FWK_MODULE(ClosureAnalysis);
