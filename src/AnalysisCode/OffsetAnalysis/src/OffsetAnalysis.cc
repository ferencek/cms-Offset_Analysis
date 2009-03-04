// -*- C++ -*-
//
// Package:    OffsetAnalysis
// Class:      OffsetAnalysis
// 
/**\class OffsetAnalysis OffsetAnalysis.cc AnalysisCode/OffsetAnalysis/src/OffsetAnalysis.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  "Dinko Ferencek"
//         Created:  Mon Jun  9 18:48:23 CDT 2008
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

#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/CaloTowers/interface/CaloTower.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"

#include "Geometry/CaloTopology/interface/CaloTowerConstituentsMap.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"

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
#include <TRandom3.h>

#include <iostream>

using namespace edm;
using namespace std;
using namespace reco;

//
// class declaration
//

class OffsetAnalysis : public edm::EDAnalyzer {
   public:
      explicit OffsetAnalysis(const edm::ParameterSet&);
      ~OffsetAnalysis();


   private:
      virtual void beginJob(const edm::EventSetup&);
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob();
      template <class histType> histType* savePlot(histType*, const std::string&, const Option_t*);
      void fillHistos(const TH2F* fHistIn, TH1F* fHistOut1, TH1F* fHistOut2);
      double deltaPhi(double phi1, double phi2);
      
      // ----------member data ---------------------------
      edm::Service<TFileService> fs;

      TH1F *h_NofPVs;
      TH1F *h_NofPVTracks;
      TH1F *h_PVChi2overNdof;
      TH1F *h_PVz;
      TH1F *h_NofCPs;
      TH1F *h_NofCPsEta25;
      TH2F *h_NofPVs_NofCPsEta25;
      
      TH1F *h_RecHitEinEB; 
      TH1F *h_RecHitEinEE;
      TH1F *h_RecHitEinHB;
      TH1F *h_RecHitEinHE;
      TH1F *h_RecHitEinHO;
      TH1F *h_RecHitEinHFl;
      TH1F *h_RecHitEinHFs;
      
      TH2F *h_RecHitEinEB_iEta;
      TH2F *h_RecHitEinEE_iEta;
      TH2F *h_RecHitEinHB_iEta;
      TH2F *h_RecHitEinHE_iEta;
      TH2F *h_RecHitEinHO_iEta;
      TH2F *h_RecHitEinHFl_iEta;
      TH2F *h_RecHitEinHFs_iEta;
      
      TH1F *h_nRecHitsInEB; 
      TH1F *h_nRecHitsInEE;
      TH1F *h_nRecHitsInHB; 
      TH1F *h_nRecHitsInHE;
      TH1F *h_nRecHitsInHO; 
      TH1F *h_nRecHitsInHFl;
      TH1F *h_nRecHitsInHFs;
      
      TH1F *h_MeanRecHitEinEB;
      TH1F *h_MeanRecHitEinEE;
      TH1F *h_MeanRecHitEinHB;
      TH1F *h_MeanRecHitEinHE;
      TH1F *h_MeanRecHitEinHO;
      TH1F *h_MeanRecHitEinHFl;
      TH1F *h_MeanRecHitEinHFs;
      
      TH1F *h_RMSRecHitEinEB;
      TH1F *h_RMSRecHitEinEE;
      TH1F *h_RMSRecHitEinHB;
      TH1F *h_RMSRecHitEinHE;
      TH1F *h_RMSRecHitEinHO;
      TH1F *h_RMSRecHitEinHFl;
      TH1F *h_RMSRecHitEinHFs;
      
//       TH2F *h_CaloTowerE_iEta_iPhi;
//       TH1F *h_ETminusPT; 
//       TH1F *h_PTandPxPy; 
//       TH1F *h_ETandE;
//       TH1F *h_PTandPx;
//       TH1F *h_PTandPy;
      
      TH1F *h_CaloTowerE;
      TH1F *h_CaloTowerET;
//       TH1F *h_CaloTowerEinB;
//       TH1F *h_CaloTowerETinB;
//       TH1F *h_CaloTowerEinE;
//       TH1F *h_CaloTowerETinE;
//       TH1F *h_CaloTowerEinF;
//       TH1F *h_CaloTowerETinF;
//       TH1F *h_CaloTowerEta;
//       TH1F *h_CaloTowerPhi;
      TH1F *h_nCaloTowers;

      TH2F *h_EinC5_Eta;
      TProfile *p_AvgEinC5;
      TH2F *h_pTinC5_Eta;
      TProfile *p_AvgpTinC5;

      TH2F *h_EinC5HB_Eta;
      TProfile *p_AvgEinC5HB;
      TH2F *h_EinC5HE_Eta;
      TProfile *p_AvgEinC5HE;
      TH2F *h_EinC5HO_Eta;
      TProfile *p_AvgEinC5HO;
      TH2F *h_EinC5HFl_Eta;
      TProfile *p_AvgEinC5HFl;
      TH2F *h_EinC5HFs_Eta;
      TProfile *p_AvgEinC5HFs;
      TH2F *h_EinC5EB_Eta;
      TProfile *p_AvgEinC5EB;
      TH2F *h_EinC5EE_Eta;
      TProfile *p_AvgEinC5EE;
      
      TH2F *h_EinER_iEta;
      TProfile *p_AvgEinER;
      TH2F *h_ETinER_iEta;
      TProfile *p_AvgETinER;

      TH2F *h_EinERHB_iEta;
      TProfile *p_AvgEinERHB;
      TH2F *h_EinERHE_iEta;
      TProfile *p_AvgEinERHE;
      TH2F *h_EinERHO_iEta;
      TProfile *p_AvgEinERHO;
      TH2F *h_EinERHFl_iEta;
      TProfile *p_AvgEinERHFl;
      TH2F *h_EinERHFs_iEta;
      TProfile *p_AvgEinERHFs;
      TH2F *h_EinEREB_iEta;
      TProfile *p_AvgEinEREB;
      TH2F *h_EinEREE_iEta;
      TProfile *p_AvgEinEREE;
      
      TH2F *h_ETinERHB_iEta;
      TProfile *p_AvgETinERHB;
      TH2F *h_ETinERHE_iEta;
      TProfile *p_AvgETinERHE;
      TH2F *h_ETinERHO_iEta;
      TProfile *p_AvgETinERHO;
      TH2F *h_ETinERHFl_iEta;
      TProfile *p_AvgETinERHFl;
      TH2F *h_ETinERHFs_iEta;
      TProfile *p_AvgETinERHFs;
      TH2F *h_ETinEREB_iEta;
      TProfile *p_AvgETinEREB;
      TH2F *h_ETinEREE_iEta;
      TProfile *p_AvgETinEREE;
      
      map<int, TProfile*> p_AvgEinC5NPV;
      map<int, TProfile*> p_AvgpTinC5NPV;
      
      int nEvt;
      
      InputTag caloTowers_;
      InputTag pvCollection_;

      // HCAL RecHits
      Handle<HBHERecHitCollection> hbheRecHits;
      Handle<HFRecHitCollection> hfRecHits;
      Handle<HORecHitCollection> hoRecHits;
      // ECAL RecHits
      Handle<EBRecHitCollection> ebRecHits;
      Handle<EERecHitCollection> eeRecHits;
      // CaloTowers
      Handle<CaloTowerCollection> caloTowers;
      // Primary Vertices
      Handle<VertexCollection> pvCollection;
      // GenParticles
      Handle<GenParticleCollection> genParticles;

      // CaloTowerConstituentsMap
      ESHandle<CaloTowerConstituentsMap> caloTowerConstituentsMap;

      TRandom3 *randomNumber;
      double conePhi;
      double towerETcut_;
      bool doOffset_;
      bool loopOverRecHits_;
      int recHitEvtLimit_;
      bool doPVs_;
      int maxNPVs_;
      bool savePlots_;
      string outputDir_;
      bool doPNG_;
      bool doEPS_;
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
OffsetAnalysis::OffsetAnalysis(const edm::ParameterSet& iConfig)

{
   // now do what ever initialization is needed
   doOffset_        = iConfig.getUntrackedParameter<bool>("doOffset",true);
   towerETcut_      = iConfig.getUntrackedParameter<double>("towerETcut",-1000.);
   loopOverRecHits_ = iConfig.getUntrackedParameter<bool>("loopOverRecHits",false);
   recHitEvtLimit_  = iConfig.getUntrackedParameter<int>("recHitEvtLimit",2000);
   caloTowers_      = iConfig.getUntrackedParameter<string>("caloTowers","towerMaker");
   doPVs_           = iConfig.getUntrackedParameter<bool>("doPVs",true);
   maxNPVs_         = iConfig.getUntrackedParameter<int>("maxNPVs",0);
   pvCollection_    = iConfig.getParameter<InputTag>("pvCollection");
   savePlots_       = iConfig.getUntrackedParameter<bool>("savePlots",false);
   outputDir_       = iConfig.getUntrackedParameter<string>("outputDir",".");
   doPNG_           = iConfig.getUntrackedParameter<bool>("doPNG",true);
   doEPS_           = iConfig.getUntrackedParameter<bool>("doEPS",false);
   
   // set ROOT style
   gStyle->Reset("Default");
   gStyle->SetCanvasColor(0);
   gStyle->SetPadColor(0);
   gStyle->SetTitleFillColor(10);
   gStyle->SetCanvasBorderMode(0);
   gStyle->SetStatColor(0);
   gStyle->SetPadBorderMode(0);
   gStyle->SetFrameBorderMode(0);
   gStyle->SetOptStat("nouemr");
   gStyle->SetPalette(1);
   gStyle->SetOptFit(111);
   gStyle->SetStatX(1.0);
   gStyle->SetStatY(1.0);
   gStyle->SetStatW(0.18);
   gStyle->SetStatH(0.15);
}


OffsetAnalysis::~OffsetAnalysis()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called once each job just before starting event loop  ------------
void 
OffsetAnalysis::beginJob(const edm::EventSetup&)
{
   // book all histograms
   // Primary Vertices
   TFileDirectory pvSubDir = fs->mkdir( "PrimaryVertices" );
   
   h_NofPVs      = pvSubDir.make<TH1F>("h_NofPVs","Number of Reconstructed PV's;# of PV's;Entries",11,-.5,10.5);
   h_NofPVTracks = pvSubDir.make<TH1F>("h_NofPVTracks","Number of Tracks Attached to PV;# of tracks;Entries",100,0.,100.);
   h_PVChi2overNdof = pvSubDir.make<TH1F>("h_PVChi2overNdof","#chi^{2}/ndof;#chi^{2}/ndof;Entries/0.1",110,-1.,10.);
   h_PVz            = pvSubDir.make<TH1F>("h_PVz","z Coordinate of PV's;z [cm];Entries/0.1",300,-15.,15.);
   h_NofCPs         = pvSubDir.make<TH1F>("h_NofCPs","Number of Charged Particles;# of charged particles;Entries",500,0.,500.);
   h_NofCPsEta25    = pvSubDir.make<TH1F>("h_NofCPsEta25","Number of Charged Particles with |#eta|<2.5;# of charged particles;Entries",250,0.,250.);
   h_NofPVs_NofCPsEta25 = pvSubDir.make<TH2F>("h_NofPVs_NofCPsEta25","# of PV's vs. # of Charged Particles with |#eta|<2.5;# of charged particles;# of PV's",250,0.,250.,11,-.5,10.5);
   
   // RecHit histograms
   h_RecHitEinEB    = fs->make<TH1F>("h_RecHitEinEB","EB RecHit E;E [GeV]",100,-0.3,0.3);
   h_RecHitEinEE    = fs->make<TH1F>("h_RecHitEinEE","EE RecHit E;E [GeV]",100,-1,1);
   h_RecHitEinHB    = fs->make<TH1F>("h_RecHitEinHB","HB RecHit E;E [GeV]",100,-2,2);
   h_RecHitEinHE    = fs->make<TH1F>("h_RecHitEinHE","HE RecHit E;E [GeV]",100,-2,2);
   h_RecHitEinHO    = fs->make<TH1F>("h_RecHitEinHO","HO RecHit E;E [GeV]",100,-4.5,4.5);
   h_RecHitEinHFl   = fs->make<TH1F>("h_RecHitEinHFl","HFl RecHit E;E [GeV]",100,-4,4);
   h_RecHitEinHFs   = fs->make<TH1F>("h_RecHitEinHFs","HFs RecHit E;E [GeV]",100,-4,4);
   
   h_RecHitEinEB_iEta    = fs->make<TH2F>("h_RecHitEinEB_iEta","RecHitEinEB:iEta;i#eta;E [GeV]",83,-41.5,41.5,100,-0.3,0.3);
   h_RecHitEinEE_iEta    = fs->make<TH2F>("h_RecHitEinEE_iEta","RecHitEinEE:iEta;i#eta;E [GeV]",83,-41.5,41.5,100,-1,1);
   h_RecHitEinHB_iEta    = fs->make<TH2F>("h_RecHitEinHB_iEta","RecHitEinHB:iEta;i#eta;E [GeV]",83,-41.5,41.5,100,-2,2);
   h_RecHitEinHE_iEta    = fs->make<TH2F>("h_RecHitEinHE_iEta","RecHitEinHE:iEta;i#eta;E [GeV]",83,-41.5,41.5,100,-3,3);
   h_RecHitEinHO_iEta    = fs->make<TH2F>("h_RecHitEinHO_iEta","RecHitEinHO:iEta;i#eta;E [GeV]",83,-41.5,41.5,100,-4.5,4.5);
   h_RecHitEinHFl_iEta   = fs->make<TH2F>("h_RecHitEinHFl_iEta","RecHitEinHFl:iEta;i#eta;E [GeV]",83,-41.5,41.5,100,-2,2);
   h_RecHitEinHFs_iEta   = fs->make<TH2F>("h_RecHitEinHFs_iEta","RecHitEinHFs:iEta;i#eta;E [GeV]",83,-41.5,41.5,100,-2,2);
   
   h_nRecHitsInEB   = fs->make<TH1F>("h_nRecHitsInEB","Number of RecHits in EB;Number of RecHits",65000,0,65000);
   h_nRecHitsInEE   = fs->make<TH1F>("h_nRecHitsInEE","Number of RecHits in EE;Number of RecHits",20000,0,20000);
   h_nRecHitsInHB   = fs->make<TH1F>("h_nRecHitsInHB","Number of RecHits in HB;Number of RecHits",1500,0,3000);
   h_nRecHitsInHE   = fs->make<TH1F>("h_nRecHitsInHE","Number of RecHits in HE;Number of RecHits",1500,0,3000);
   h_nRecHitsInHO   = fs->make<TH1F>("h_nRecHitsInHO","Number of RecHits in HO;Number of RecHits",1500,0,3000);
   h_nRecHitsInHFl  = fs->make<TH1F>("h_nRecHitsInHFl","Number of RecHits in HFl;Number of RecHits",1500,0,3000);
   h_nRecHitsInHFs  = fs->make<TH1F>("h_nRecHitsInHFs","Number of RecHits in HFs;Number of RecHits",1500,0,3000);
   
   h_MeanRecHitEinEB    = fs->make<TH1F>("h_MeanRecHitEinEB","EB Mean RecHit E;i#eta;#bar{E} [GeV]",83,-41.5,41.5);
   h_MeanRecHitEinEE    = fs->make<TH1F>("h_MeanRecHitEinEE","EE Mean RecHit E;i#eta;#bar{E} [GeV]",83,-41.5,41.5);
   h_MeanRecHitEinHB    = fs->make<TH1F>("h_MeanRecHitEinHB","HB Mean RecHit E;i#eta;#bar{E} [GeV]",83,-41.5,41.5);
   h_MeanRecHitEinHE    = fs->make<TH1F>("h_MeanRecHitEinHE","HE Mean RecHit E;i#eta;#bar{E} [GeV]",83,-41.5,41.5);
   h_MeanRecHitEinHO    = fs->make<TH1F>("h_MeanRecHitEinHO","HO Mean RecHit E;i#eta;#bar{E} [GeV]",83,-41.5,41.5);
   h_MeanRecHitEinHFl   = fs->make<TH1F>("h_MeanRecHitEinHFl","Hfl Mean RecHit E;i#eta;#bar{E} [GeV]",83,-41.5,41.5);
   h_MeanRecHitEinHFs   = fs->make<TH1F>("h_MeanRecHitEinHFs","HFs Mean RecHit E;i#eta;#bar{E} [GeV]",83,-41.5,41.5);
   
   h_RMSRecHitEinEB    = fs->make<TH1F>("h_RMSRecHitEinEB","EB RMS RecHit E;i#eta;RMS E [GeV]",83,-41.5,41.5);
   h_RMSRecHitEinEE    = fs->make<TH1F>("h_RMSRecHitEinEE","EE RMS RecHit E;i#eta;RMS E [GeV]",83,-41.5,41.5);
   h_RMSRecHitEinHB    = fs->make<TH1F>("h_RMSRecHitEinHB","HB RMS RecHit E;i#eta;RMS E [GeV]",83,-41.5,41.5);
   h_RMSRecHitEinHE    = fs->make<TH1F>("h_RMSRecHitEinHE","HE RMS RecHit E;i#eta;RMS E [GeV]",83,-41.5,41.5);
   h_RMSRecHitEinHO    = fs->make<TH1F>("h_RMSRecHitEinHO","HO RMS RecHit E;i#eta;RMS E [GeV]",83,-41.5,41.5);
   h_RMSRecHitEinHFl   = fs->make<TH1F>("h_RMSRecHitEinHFl","HFl RMS RecHit E;i#eta;RMS E [GeV]",83,-41.5,41.5);
   h_RMSRecHitEinHFs   = fs->make<TH1F>("h_RMSRecHitEinHFs","HFs RMS RecHit E;i#eta;RMS E [GeV]",83,-41.5,41.5);
   
   // additional histograms for debugging purposes
   //TFileDirectory recHitSubDir = fs->mkdir( "Additional" );

//    h_CaloTowerE_iEta_iPhi      = recHitSubDir.make<TH2F>("h_CaloTowerE_iEta_iPhi","Calorimeter energy deposits;i#eta;i#phi",83,-41.5,41.5,72,0.5,72.5);
//    h_ETminusPT = recHitSubDir.make<TH1F>("h_ETminusPT",";E [GeV]",201,-0.5,0.5);
//    h_PTandPxPy = recHitSubDir.make<TH1F>("h_PTandPxPy",";E [GeV]",201,-0.5,0.5);
//    h_ETandE = recHitSubDir.make<TH1F>("h_ETandE",";E [GeV]",201,-0.5,0.5);
//    h_PTandPx = recHitSubDir.make<TH1F>("h_PTandPx",";E [GeV]",201,-0.5,0.5);
//    h_PTandPy = recHitSubDir.make<TH1F>("h_PTandPy",";E [GeV]",201,-0.5,0.5);
   
   // CaloTower histograms
   h_CaloTowerE      = fs->make<TH1F>("h_CaloTowerE", "CaloTower Energy;E [GeV]",200,-5,10);
   h_CaloTowerET     = fs->make<TH1F>("h_CaloTowerET", "CaloTower E_{T};E_{T} [GeV]",200,-2,3);
//    h_CaloTowerEinB   = fs->make<TH1F>("h_CaloTowerEinB", "CaloTower Energy in Barrel Region;E [GeV]",150,-2,5);
//    h_CaloTowerETinB  = fs->make<TH1F>("h_CaloTowerETinB", "CaloTower E_{T} in Barrel Region;E_{T} [GeV]",150,-2,3);
//    h_CaloTowerEinE   = fs->make<TH1F>("h_CaloTowerEinE", "CaloTower Energy in Endcap Region;E [GeV]",150,-2,4);
//    h_CaloTowerETinE  = fs->make<TH1F>("h_CaloTowerETinE", "CaloTower E_{T} in Endcap Region;E_{T} [GeV]",150,-1,1);
//    h_CaloTowerEinF   = fs->make<TH1F>("h_CaloTowerEinF", "CaloTower Energy in Forward Region;E [GeV]",150,-2,8);
//    h_CaloTowerETinF  = fs->make<TH1F>("h_CaloTowerETinF", "CaloTower E_{T} in Forward Region;E_{T} [GeV]",150,-1,1);
//    h_CaloTowerEta = fs->make<TH1F>("h_CaloTowerEta", "CaloTower #eta;#eta",200,-5,5 );
//    h_CaloTowerPhi = fs->make<TH1F>("h_CaloTowerPhi", "CaloTower #phi;#phi",72,-3.1416,3.1416 );
   h_nCaloTowers   = fs->make<TH1F>("h_nCaloTowers","Number of CaloTowers in Event;Number of Calotowers",6000,0,6000);
   
   // in-cone energy contributions
   h_EinC5_Eta   = fs->make<TH2F>("h_EinC5_Eta","EinC5:#eta;#eta;E [GeV]",100,-5.,5.,1550,-10,300);
   p_AvgEinC5    = fs->make<TProfile>("p_AvgEinC5", "<E> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   
   h_EinC5HB_Eta = fs->make<TH2F>    ("h_EinC5HB_Eta","HB EinC5:#eta;#eta;E [GeV]",100,-5.,5.,120,-10,10);
   p_AvgEinC5HB  = fs->make<TProfile>("p_AvgEinC5HB", "<E_{HB}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   h_EinC5HE_Eta = fs->make<TH2F>    ("h_EinC5HE_Eta","HE EinC5:#eta;#eta;E [GeV]",100,-5.,5.,120,-10,10);
   p_AvgEinC5HE  = fs->make<TProfile>("p_AvgEinC5HE", "<E_{HE}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   h_EinC5HO_Eta = fs->make<TH2F>    ("h_EinC5HO_Eta","HO EinC5:#eta;#eta;E [GeV]",100,-5.,5.,120,-10,10);
   p_AvgEinC5HO  = fs->make<TProfile>("p_AvgEinC5HO", "<E_{HO}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   h_EinC5HFl_Eta = fs->make<TH2F>    ("h_EinC5HFl_Eta","HFl EinC5:#eta;#eta;E [GeV]",100,-5.,5.,120,-10,10);
   p_AvgEinC5HFl  = fs->make<TProfile>("p_AvgEinC5HFl", "<E_{HFl}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   h_EinC5HFs_Eta = fs->make<TH2F>    ("h_EinC5HFs_Eta","HFs EinC5:#eta;#eta;E [GeV]",100,-5.,5.,120,-10,10);
   p_AvgEinC5HFs  = fs->make<TProfile>("p_AvgEinC5HFs", "<E_{HFs}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   h_EinC5EB_Eta = fs->make<TH2F>    ("h_EinC5EB_Eta","EB EinC5:#eta;#eta;E [GeV]",100,-5.,5.,120,-10,10);
   p_AvgEinC5EB  = fs->make<TProfile>("p_AvgEinC5EB", "<E_{EB}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   h_EinC5EE_Eta = fs->make<TH2F>    ("h_EinC5EE_Eta","EE EinC5:#eta;#eta;E [GeV]",100,-5.,5.,120,-10,10);
   p_AvgEinC5EE  = fs->make<TProfile>("p_AvgEinC5EE", "<E_{EE}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   
   // in-cone pT contribution
   h_pTinC5_Eta   = fs->make<TH2F>("h_pTinC5_Eta","pTinC5:#eta;#eta;p_{T} [GeV/c]",100,-5.,5.,1575,-2.5,50);
   p_AvgpTinC5    = fs->make<TProfile>("p_AvgpTinC5", "<p_{T}> in R_{cone}=0.5;#eta;<p_{T}> [GeV/c]",100,-5.,5.);
   
   // energy in iEta rings
   h_EinER_iEta  = fs->make<TH2F>("h_EinER_iEta","EinER:i#eta;i#eta;E [GeV]",83,-41.5,41.5,1550,-10,300);
   p_AvgEinER    = fs->make<TProfile>("p_AvgEinER", "<E> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   h_ETinER_iEta = fs->make<TH2F>("h_ETinER_iEta","ETinER:i#eta;i#eta;E_{T} [GeV]",83,-41.5,41.5,1575,-2.5,50);
   p_AvgETinER   = fs->make<TProfile>("p_AvgETinER", "<E_{T}> in i#eta Ring;i#eta;<E_{T}> [GeV]",83,-41.5,41.5);
   
   h_EinERHB_iEta  = fs->make<TH2F>    ("h_EinERHB_iEta","HB EinER:i#eta HB;i#eta;E [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgEinERHB    = fs->make<TProfile>("p_AvgEinERHB", "<E_{HB}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   h_EinERHE_iEta  = fs->make<TH2F>    ("h_EinERHE_iEta","HE EinER:i#eta;i#eta;E [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgEinERHE    = fs->make<TProfile>("p_AvgEinERHE", "<E_{HE}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   h_EinERHO_iEta  = fs->make<TH2F>    ("h_EinERHO_iEta","HO EinER:i#eta;i#eta;E [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgEinERHO    = fs->make<TProfile>("p_AvgEinERHO", "<E_{HO}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   h_EinERHFl_iEta = fs->make<TH2F>    ("h_EinERHFl_iEta","HFl EinER:i#eta;i#eta;E [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgEinERHFl   = fs->make<TProfile>("p_AvgEinERHFl", "<E_{HFl}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   h_EinERHFs_iEta = fs->make<TH2F>    ("h_EinERHFs_iEta","HFs EinER:i#eta;i#eta;E [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgEinERHFs   = fs->make<TProfile>("p_AvgEinERHFs", "<E_{HFs}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   h_EinEREB_iEta  = fs->make<TH2F>    ("h_EinEREB_iEta","EB EinER:i#eta;i#eta;E [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgEinEREB    = fs->make<TProfile>("p_AvgEinEREB", "<E_{EB}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   h_EinEREE_iEta  = fs->make<TH2F>    ("h_EinEREE_iEta","EE EinER:i#eta;i#eta;E [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgEinEREE    = fs->make<TProfile>("p_AvgEinEREE", "<E_{EE}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   
   h_ETinERHB_iEta  = fs->make<TH2F>    ("h_ETinERHB_iEta","HB ETinER:i#eta HB;i#eta;E_{T} [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgETinERHB    = fs->make<TProfile>("p_AvgETinERHB", "<(E_{HB})_{T}> in i#eta Ring;i#eta;<E_{T}> [GeV]",83,-41.5,41.5);
   h_ETinERHE_iEta  = fs->make<TH2F>    ("h_ETinERHE_iEta","HE ETinER:i#eta;i#eta;E_{T} [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgETinERHE    = fs->make<TProfile>("p_AvgETinERHE", "<(E_{HE})_{T}> in i#eta Ring;i#eta;<E_{T}> [GeV]",83,-41.5,41.5);
   h_ETinERHO_iEta  = fs->make<TH2F>    ("h_ETinERHO_iEta","HO ETinER:i#eta;i#eta;E_{T} [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgETinERHO    = fs->make<TProfile>("p_AvgETinERHO", "<(E_{HO})_{T}> in i#eta Ring;i#eta;<E_{T}> [GeV]",83,-41.5,41.5);
   h_ETinERHFl_iEta = fs->make<TH2F>    ("h_ETinERHFl_iEta","HFl ETinER:i#eta;i#eta;E_{T} [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgETinERHFl   = fs->make<TProfile>("p_AvgETinERHFl", "<(E_{HFl})_{T}> in i#eta Ring;i#eta;<E_{T}> [GeV]",83,-41.5,41.5);
   h_ETinERHFs_iEta = fs->make<TH2F>    ("h_ETinERHFs_iEta","HFs ETinER:i#eta;i#eta;E_{T} [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgETinERHFs   = fs->make<TProfile>("p_AvgETinERHFs", "<(E_{HFs})_{T}> in i#eta Ring;i#eta;<E_{T}> [GeV]",83,-41.5,41.5);
   h_ETinEREB_iEta  = fs->make<TH2F>    ("h_ETinEREB_iEta","EB ETinER:i#eta;i#eta;E_{T} [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgETinEREB    = fs->make<TProfile>("p_AvgETinEREB", "<(E_{EB})_{T}> in i#eta Ring;i#eta;<E_{T}> [GeV]",83,-41.5,41.5);
   h_ETinEREE_iEta  = fs->make<TH2F>    ("h_ETinEREE_iEta","EE ETinER:i#eta;i#eta;E_{T} [GeV]",83,-41.5,41.5,120,-10,10);
   p_AvgETinEREE    = fs->make<TProfile>("p_AvgETinEREE", "<(E_{EE})_{T}> in i#eta Ring;i#eta;<E_{T}> [GeV]",83,-41.5,41.5);
   
   // for PV dependent offset
   if ( doPVs_ ) {
      TFileDirectory pvOffsetSubDir = fs->mkdir( "PVOffset" );
      for (int i = 0; i <= maxNPVs_; i++) {
         char AvgEProf[1024];
         char AvgpTProf[1024];
         sprintf (AvgEProf, "p_AvgEinC5NPV%i", i);
         sprintf (AvgpTProf, "p_AvgpTinC5NPV%i", i);
         
         p_AvgEinC5NPV[i]  = pvOffsetSubDir.make<TProfile>(AvgEProf, "<E> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
         p_AvgpTinC5NPV[i] = pvOffsetSubDir.make<TProfile>(AvgpTProf, "<p_{T}> in R_{cone}=0.5;#eta;<p_{T}> [GeV/c]",100,-5.,5.);
      }
   }
   
   // initialize event counter
   nEvt = 0;
   
   randomNumber = new TRandom3;
}
// ------------ method called to for each event  ------------
void
OffsetAnalysis::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   // ==========================================
   // ======= Primary Vertex Analysis ==========
   // ==========================================
   int nPV = 0;    // number of reconstructed Primary Vertices
   if ( doPVs_ ) {
      // get PV collection
      try {
          iEvent.getByLabel(pvCollection_, pvCollection);
          iEvent.getByLabel("genParticles", genParticles);
      } catch(std::exception& ce) {
          cerr << "[OffsetAnalysis] caught std::exception " << ce.what() << endl;
          return;
      }
      // loop over all Primary Vertices
      for ( VertexCollection::const_iterator pv = pvCollection->begin(); pv != pvCollection->end(); ++pv ) {
         if ( !pv->isFake() ) {
            nPV++;
            h_NofPVTracks->Fill( pv->tracksSize() );
            h_PVChi2overNdof->Fill( pv->chi2()/pv->ndof() );
            h_PVz->Fill( pv->z() );
         }
      }
      // fill in the number of valid reconstructed primary vertices
      h_NofPVs->Fill( nPV );
      // loop over all GenParticles
      int nCP = 0;      // number of charged particles
      int nCPEta25 = 0; // number of charged particles with |eta|<2.5, i.e., inside the tracker volume
      for ( GenParticleCollection::const_iterator gp = genParticles->begin(); gp != genParticles->end(); ++gp ) {
         int q = abs(gp->charge());
         if ( q == 1 ) nCP++;
         if ( q == 1 && fabs(gp->eta()) < 2.5 ) nCPEta25++;
      }
      // fill in the number of charged GenParticles
      h_NofCPs->Fill( nCP );
      h_NofCPsEta25->Fill( nCPEta25 );
      h_NofPVs_NofCPsEta25->Fill( nCPEta25, nPV );
   }
   // ==================================
   // ======= Offset Analysis ==========
   // ==================================
   if ( doOffset_ ) { 
      // get collections
      try {
          iEvent.getByLabel("hbhereco", hbheRecHits);
          iEvent.getByLabel("hfreco", hfRecHits);
          iEvent.getByLabel("horeco", hoRecHits );
          iEvent.getByLabel("ecalRecHit", "EcalRecHitsEB", ebRecHits);
          iEvent.getByLabel("ecalRecHit", "EcalRecHitsEE", eeRecHits);
          iEvent.getByLabel(caloTowers_, caloTowers);
      } catch(std::exception& ce) {
          cerr << "[OffsetAnalysis] caught std::exception " << ce.what() << endl;
          return;
      }
      // CaloTowerConstituentsMap
      iSetup.get<IdealGeometryRecord>().get(caloTowerConstituentsMap);
      
      // RecHit counters
      int nRecHitsInHB = 0;
      int nRecHitsInHE = 0;
      int nRecHitsInHFl = 0;
      int nRecHitsInHFs = 0;
      
      // loop over ECAL and HCAL RecHits (if requested)
      if ( loopOverRecHits_ && nEvt < recHitEvtLimit_ ) {
         // loop over all HBHE RecHits
         for (HBHERecHitCollection::const_iterator h = hbheRecHits->begin(); h != hbheRecHits->end(); ++h ) {
            if ( h->id().subdet() == HcalBarrel ) { // HB only
               h_RecHitEinHB->Fill(h->energy());
               h_RecHitEinHB_iEta->Fill(h->id().ieta(),h->energy());
               nRecHitsInHB++;
            }
            else if ( h->id().subdet() == HcalEndcap ){ // HE only
               h_RecHitEinHE->Fill(h->energy());
               h_RecHitEinHE_iEta->Fill(h->id().ieta(),h->energy());
               nRecHitsInHE++;
            }
         }
         h_nRecHitsInHB->Fill(nRecHitsInHB);
         h_nRecHitsInHE->Fill(nRecHitsInHE);
         
         // loop over all HO RecHits
         for (HORecHitCollection::const_iterator h = hoRecHits->begin(); h != hoRecHits->end(); ++h) {
            h_RecHitEinHO->Fill(h->energy());
            h_RecHitEinHO_iEta->Fill(h->id().ieta(),h->energy());
         }
         h_nRecHitsInHO->Fill(hoRecHits->size());
         
         // loop over all HF RecHits
         for (HFRecHitCollection::const_iterator h = hfRecHits->begin(); h != hfRecHits->end(); ++h) {
            if ( h->id().depth() == 1 ) { // HF long only
               h_RecHitEinHFl->Fill(h->energy());
               h_RecHitEinHFl_iEta->Fill(h->id().ieta(),h->energy());
               nRecHitsInHFl++;
            } 
            else if ( h->id().depth() == 2 ) { // HF short only
               h_RecHitEinHFs->Fill(h->energy());
               h_RecHitEinHFs_iEta->Fill(h->id().ieta(),h->energy());
               nRecHitsInHFs++;
            }
         }
         h_nRecHitsInHFl->Fill(nRecHitsInHFl);
         h_nRecHitsInHFs->Fill(nRecHitsInHFs);
         
         // loop over all EB RecHits 
         for (EBRecHitCollection::const_iterator h = ebRecHits->begin(); h != ebRecHits->end(); ++h) {
            h_RecHitEinEB->Fill(h->energy());
            
            EBDetId detId = h->id();
            h_RecHitEinEB_iEta->Fill(detId.tower_ieta(),h->energy());
         }
         h_nRecHitsInEB->Fill( ebRecHits->size() );
         
         // loop over all EE RecHits
         for (EERecHitCollection::const_iterator h = eeRecHits->begin(); h != eeRecHits->end(); ++h) {
            h_RecHitEinEE->Fill(h->energy());
            
            EEDetId detId = h->id();
            CaloTowerDetId towerDetId = (*caloTowerConstituentsMap).towerOf(detId);
            h_RecHitEinEE_iEta->Fill(towerDetId.ieta(),h->energy());
         }
         h_nRecHitsInEE->Fill(eeRecHits->size());
      }
      
      // in-cone energy contributions
      double EinC5[100]={0.};
    
      double EinC5HB[100]={0.};
      double EinC5HE[100]={0.};
      double EinC5HO[100]={0.};
      double EinC5HFl[100]={0.};
      double EinC5HFs[100]={0.};
      double EinC5EB[100]={0.};
      double EinC5EE[100]={0.};
      
      // in-cone pT contribution
      double pXinC5[100]={0.};
      double pYinC5[100]={0.};
      double pTinC5[100]={0.};
      
      // energy in iEta rings
      double EinER[83]={0.};
      double ETinER[83]={0.};
    
      double EinERHB[83]={0.};
      double EinERHE[83]={0.};
      double EinERHO[83]={0.};
      double EinERHFl[83]={0.};
      double EinERHFs[83]={0.};
      double EinEREB[83]={0.};
      double EinEREE[83]={0.};
      
      double ETinERHB[83]={0.};
      double ETinERHE[83]={0.};
      double ETinERHO[83]={0.};
      double ETinERHFl[83]={0.};
      double ETinERHFs[83]={0.};
      double ETinEREB[83]={0.};
      double ETinEREE[83]={0.};
      
      
      // initialize random Phi angle of the cone
      conePhi = (randomNumber->Uniform(-1.,1.))*M_PI;
      
      // =================== CaloTowers ====================================
      h_nCaloTowers->Fill(caloTowers->size());
      // loop over all CaloTowers
      for (CaloTowerCollection::const_iterator t = caloTowers->begin(); t != caloTowers->end(); ++t ) {
      
         double ET = t->et();
         if( ET < towerETcut_ ) continue;
      
         // double energySum = t->emEnergy()+t->hadEnergy()+t->outerEnergy(); //CaloTower energy (gets negative values as well)
         double energy = t->energy(); // CaloTower energy (gets positive values only)
         double eta = t->eta();
         int iEta = t->ieta();
         
         h_CaloTowerE->Fill( energy );
         h_CaloTowerET->Fill( ET );
   //       h_CaloTowerE_iEta_iPhi->Fill(t->id().ieta(),t->id().iphi(),energy);
         
   //       h_ETminusPT->Fill( t->pt()-t->et() );
   //       h_PTandPxPy->Fill( t->pt()-sqrt((t->px())*(t->px())+(t->py())*(t->py())) );
   //       h_ETandE->Fill( t->et()-(energy/cosh(eta)) );
   //       h_PTandPx->Fill( t->px()-t->et()*cos(phi) );
   //       h_PTandPy->Fill( t->py()-t->et()*sin(phi) );
         
   //       int iEtaAbs = t->ietaAbs(); // CaloTower abs(iEta)
   //       if ( iEtaAbs < 17 ) {
   //          h_CaloTowerEinB->Fill( energy );
   // 	    h_CaloTowerETinB->Fill( ET );
   //       } else if ( iEtaAbs > 16 && iEtaAbs < 30) {
   //          h_CaloTowerEinE->Fill( energy );
   // 	    h_CaloTowerETinE->Fill( ET );
   //       } else {
   //          h_CaloTowerEinF->Fill( energy );
   // 	    h_CaloTowerETinF->Fill( ET );
   //       }
         
         // subdetector tower energy contributions
         double energyInHB=0;
         double energyInHE=0;
         double energyInHO=0;
         double energyInHFl=0;
         double energyInHFs=0;
         double energyInEB=0;
         double energyInEE=0;
         
         // loop over constituent RecHits
         for (size_t j = 0; j < t->constituentsSize() ; j++) {
            // ECAL RecHit
            if ( t->constituent(j).det() == DetId::Ecal ) {
               if ( t->constituent(j).subdetId() == 1 ) { // ECAL Barrel
                  EBDetId detId = t->constituent(j);
                  EBRecHitCollection::const_iterator theRecHit = ebRecHits->find(detId);
                  energyInEB += theRecHit->energy();
               } 
               else if ( t->constituent(j).subdetId() == 2 ) { // ECAL Endcap
                  EEDetId detId = t->constituent(j);
                  EERecHitCollection::const_iterator theRecHit = eeRecHits->find(detId);
                  energyInEE += theRecHit->energy();
               }
            }
            // HCAL RecHit
            if ( t->constituent(j).det() == DetId::Hcal ) {
               HcalDetId detId = t->constituent(j);
               if ( detId.subdet() == HcalBarrel ){ // HCAL Barrel
                  HBHERecHitCollection::const_iterator theRecHit = hbheRecHits->find(detId);
                  energyInHB += theRecHit->energy();
               }
               else if ( detId.subdet() == HcalEndcap ) { // HCAL Endcap
                  HBHERecHitCollection::const_iterator theRecHit = hbheRecHits->find(detId);
                  if ( abs(detId.ieta())==28 && detId.depth()==3){
                     energyInHE += theRecHit->energy()/2; // Depth 3 is split between towers 28 & 29
                  }
                  else {
                     energyInHE += theRecHit->energy();
                  }
               }
               else if ( detId.subdet() == HcalOuter ) { // HCAL Outer
                  HORecHitCollection::const_iterator theRecHit = hoRecHits->find(detId);
                  energyInHO += theRecHit->energy();
               }
               else if ( detId.subdet() == HcalForward  ){ // HCAL Forward
                  HFRecHitCollection::const_iterator theRecHit = hfRecHits->find(detId);
                  if ( theRecHit->id().depth() == 1 ) { // HF long
                     energyInHFl += theRecHit->energy();
                  }
                  else if ( theRecHit->id().depth() == 2 ) { // HF short
                     energyInHFs += theRecHit->energy();
                  }
               }
            }
         }
         
         // add calotower energy to the iEta ring energy
         EinER[iEta+41]  += energy;
         ETinER[iEta+41] += ET;	
    
         EinERHB[iEta+41] += energyInHB;
         EinERHE[iEta+41] += energyInHE;
         EinERHO[iEta+41] += energyInHO;
         EinERHFl[iEta+41] += energyInHFl;
         EinERHFs[iEta+41] += energyInHFs;
         EinEREB[iEta+41] += energyInEB;
         EinEREE[iEta+41] += energyInEE;
               
         ETinERHB[iEta+41] += energyInHB/cosh(eta);
         ETinERHE[iEta+41] += energyInHE/cosh(eta);
         ETinERHO[iEta+41] += energyInHO/cosh(eta);
         ETinERHFl[iEta+41] += energyInHFl/cosh(eta);
         ETinERHFs[iEta+41] += energyInHFs/cosh(eta);
         ETinEREB[iEta+41] += energyInEB/cosh(eta);
         ETinEREE[iEta+41] += energyInEE/cosh(eta);
         
         // loop over cones centered at different Eta values and add energy from the calotower if it is within dR=0.5 from the cone axis
         for (int i = 0; i < 100; i++) {
            double coneEta = -4.95 + double(i)*0.1;
            double dPhi = deltaPhi(t->phi(), conePhi);
            double dEta = eta - coneEta ;
            double dR = sqrt(dPhi*dPhi + dEta*dEta);
            
            if (dR < 0.5){
               EinC5[i]  += energy;	
    
               EinC5HB[i] += energyInHB;
               EinC5HE[i] += energyInHE;
               EinC5HO[i] += energyInHO;
               EinC5HFl[i] += energyInHFl;
               EinC5HFs[i] += energyInHFs;
               EinC5EB[i] += energyInEB;
               EinC5EE[i] += energyInEE;
               
               pXinC5[i] += t->px();
               pYinC5[i] += t->py();
            }
         }
      }
      // calculate in-cone pT contribution from px and py components
      for (int i = 0; i < 100; i++) {
         pTinC5[i] = sqrt((pXinC5[i])*(pXinC5[i])+(pYinC5[i])*(pYinC5[i]));
      }
      // fill in the histograms
      for (int i = 0; i < 100; i++) {
         double coneEta = -4.95 + double(i)*0.1;
         
         h_EinC5_Eta->Fill(coneEta,EinC5[i]);
         p_AvgEinC5->Fill(coneEta,EinC5[i]);
         
         h_EinC5HB_Eta->Fill(coneEta,EinC5HB[i]);
         p_AvgEinC5HB->Fill(coneEta,EinC5HB[i]);
         h_EinC5HE_Eta->Fill(coneEta,EinC5HE[i]);
         p_AvgEinC5HE->Fill(coneEta,EinC5HE[i]);
         h_EinC5HO_Eta->Fill(coneEta,EinC5HO[i]);
         p_AvgEinC5HO->Fill(coneEta,EinC5HO[i]);
         h_EinC5HFl_Eta->Fill(coneEta,EinC5HFl[i]);
         p_AvgEinC5HFl->Fill(coneEta,EinC5HFl[i]);
         h_EinC5HFs_Eta->Fill(coneEta,EinC5HFs[i]);
         p_AvgEinC5HFs->Fill(coneEta,EinC5HFs[i]);
         h_EinC5EB_Eta->Fill(coneEta,EinC5EB[i]);
         p_AvgEinC5EB->Fill(coneEta,EinC5EB[i]);
         h_EinC5EE_Eta->Fill(coneEta,EinC5EE[i]);
         p_AvgEinC5EE->Fill(coneEta,EinC5EE[i]);
         
         h_pTinC5_Eta->Fill(coneEta,pTinC5[i]);
         p_AvgpTinC5->Fill(coneEta,pTinC5[i]);
         
         if ( doPVs_ && nPV <= maxNPVs_ ) {
            p_AvgEinC5NPV[nPV]->Fill(coneEta,EinC5[i]);
            p_AvgpTinC5NPV[nPV]->Fill(coneEta,pTinC5[i]);
         }
      }
      
      for (int i = 0; i < 83; i++) {
   
         h_EinER_iEta->Fill(i-41,EinER[i]);
         p_AvgEinER->Fill(i-41,EinER[i]);
         h_ETinER_iEta->Fill(i-41,ETinER[i]);
         p_AvgETinER->Fill(i-41,ETinER[i]);
           
         h_EinERHB_iEta->Fill(i-41,EinERHB[i]);
         p_AvgEinERHB->Fill(i-41,EinERHB[i]);
         h_EinERHE_iEta->Fill(i-41,EinERHE[i]);
         p_AvgEinERHE->Fill(i-41,EinERHE[i]);
         h_EinERHO_iEta->Fill(i-41,EinERHO[i]);
         p_AvgEinERHO->Fill(i-41,EinERHO[i]);
         h_EinERHFl_iEta->Fill(i-41,EinERHFl[i]);
         p_AvgEinERHFl->Fill(i-41,EinERHFl[i]);
         h_EinERHFs_iEta->Fill(i-41,EinERHFs[i]);
         p_AvgEinERHFs->Fill(i-41,EinERHFs[i]);
         h_EinEREB_iEta->Fill(i-41,EinEREB[i]);
         p_AvgEinEREB->Fill(i-41,EinEREB[i]);
         h_EinEREE_iEta->Fill(i-41,EinEREE[i]);
         p_AvgEinEREE->Fill(i-41,EinEREE[i]);
           
         h_ETinERHB_iEta->Fill(i-41,ETinERHB[i]);
         p_AvgETinERHB->Fill(i-41,ETinERHB[i]);
         h_ETinERHE_iEta->Fill(i-41,ETinERHE[i]);
         p_AvgETinERHE->Fill(i-41,ETinERHE[i]);
         h_ETinERHO_iEta->Fill(i-41,ETinERHO[i]);
         p_AvgETinERHO->Fill(i-41,ETinERHO[i]);
         h_ETinERHFl_iEta->Fill(i-41,ETinERHFl[i]);
         p_AvgETinERHFl->Fill(i-41,ETinERHFl[i]);
         h_ETinERHFs_iEta->Fill(i-41,ETinERHFs[i]);
         p_AvgETinERHFs->Fill(i-41,ETinERHFs[i]);
         h_ETinEREB_iEta->Fill(i-41,ETinEREB[i]);
         p_AvgETinEREB->Fill(i-41,ETinEREB[i]);
         h_ETinEREE_iEta->Fill(i-41,ETinEREE[i]);
         p_AvgETinEREE->Fill(i-41,ETinEREE[i]);
      }
   }
   // increase event counter
   nEvt++;
}


// ------------ method called once each job just after ending the event loop  ------------
void 
OffsetAnalysis::endJob() {
   // fill RecHit Mean and RMS energy histograms
   fillHistos(h_RecHitEinEB_iEta,  h_MeanRecHitEinEB,  h_RMSRecHitEinEB);
   fillHistos(h_RecHitEinEE_iEta,  h_MeanRecHitEinEE,  h_RMSRecHitEinEE);
   fillHistos(h_RecHitEinHB_iEta,  h_MeanRecHitEinHB,  h_RMSRecHitEinHB);
   fillHistos(h_RecHitEinHE_iEta,  h_MeanRecHitEinHE,  h_RMSRecHitEinHE);
   fillHistos(h_RecHitEinHFl_iEta, h_MeanRecHitEinHFl, h_RMSRecHitEinHFl);
   fillHistos(h_RecHitEinHFs_iEta, h_MeanRecHitEinHFs, h_RMSRecHitEinHFs);
   fillHistos(h_RecHitEinHO_iEta,  h_MeanRecHitEinHO,  h_RMSRecHitEinHO);

   // save plots in PNG and/or EPS format
   if (savePlots_ && (doPNG_ || doEPS_)) {
      outputDir_ = outputDir_ + "/";
      if (outputDir_ != "./") system(("/bin/mkdir -p " + outputDir_).c_str());
	 cout<<"*************************************"<<endl;
	 cout<<"====================================="<<endl;
	 cout<<" Saving plots to '"<<outputDir_<<"'"<<endl;
	 
	 savePlot<TH1F>(h_RecHitEinEB, outputDir_,""); 
	 savePlot<TH1F>(h_RecHitEinEE, outputDir_,"");
	 savePlot<TH1F>(h_RecHitEinHB, outputDir_,""); 
	 savePlot<TH1F>(h_RecHitEinHE, outputDir_,"");
	 savePlot<TH1F>(h_RecHitEinHO, outputDir_,""); 
	 savePlot<TH1F>(h_RecHitEinHFl, outputDir_,"");
	 savePlot<TH1F>(h_RecHitEinHFs, outputDir_,""); 
	 
	 savePlot<TH2F>(h_RecHitEinEB_iEta, outputDir_,"");
	 savePlot<TH2F>(h_RecHitEinEE_iEta, outputDir_,"");
	 savePlot<TH2F>(h_RecHitEinHB_iEta, outputDir_,"");
	 savePlot<TH2F>(h_RecHitEinHE_iEta, outputDir_,"");
	 savePlot<TH2F>(h_RecHitEinHO_iEta, outputDir_,"");
	 savePlot<TH2F>(h_RecHitEinHFl_iEta, outputDir_,"");
	 savePlot<TH2F>(h_RecHitEinHFs_iEta, outputDir_,"");
	 
	 gStyle->SetOptStat(kFALSE);
	 
	 savePlot<TH1F>(h_MeanRecHitEinEB, outputDir_,"*PC");
	 savePlot<TH1F>(h_MeanRecHitEinEE, outputDir_,"*PC");
	 savePlot<TH1F>(h_MeanRecHitEinHB, outputDir_,"*PC");
	 savePlot<TH1F>(h_MeanRecHitEinHE, outputDir_,"*PC");
	 savePlot<TH1F>(h_MeanRecHitEinHFl, outputDir_,"*PC");
	 savePlot<TH1F>(h_MeanRecHitEinHFs, outputDir_,"*PC");
	 savePlot<TH1F>(h_MeanRecHitEinHO, outputDir_,"*PC");
	 
	 savePlot<TH1F>(h_RMSRecHitEinEB, outputDir_,"*PC");
	 savePlot<TH1F>(h_RMSRecHitEinEE, outputDir_,"*PC");
	 savePlot<TH1F>(h_RMSRecHitEinHB, outputDir_,"*PC");
	 savePlot<TH1F>(h_RMSRecHitEinHE, outputDir_,"*PC");
	 savePlot<TH1F>(h_RMSRecHitEinHFl, outputDir_,"*PC");
	 savePlot<TH1F>(h_RMSRecHitEinHFs, outputDir_,"*PC");
	 savePlot<TH1F>(h_RMSRecHitEinHO, outputDir_,"*PC");
	  
	 cout<<" Saving completed!"<<endl;
	 cout<<"====================================="<<endl;
	 cout<<"*************************************"<<endl;
   }
}
  
template <class histType> histType* OffsetAnalysis::savePlot(histType* fHist, const std::string& fOutputDir, const Option_t* fOption) {
   
   string name = fHist->GetName();
   string pngName = name + ".png";
   string saveName = fOutputDir + pngName;
   
   /*string title = fHist->GetTitle();
   title = title + "  (CMSSW_1_8_4)";
   fHist->SetTitle(title.c_str());*/
   
   TCanvas *c = new TCanvas("c","",1400,1000);
   c->cd();

   fHist->Draw(fOption);

   c->SaveAs(saveName.c_str());
   if (doEPS_) {
      string epsName = name + ".eps";
      saveName = fOutputDir + epsName;
      c->SaveAs(saveName.c_str());
   }
   delete c;

   return fHist;
}

void OffsetAnalysis::fillHistos(const TH2F* fHistIn, TH1F* fHistOut1, TH1F* fHistOut2) {
   
   for (int i=1; i<84; i++) {

      fHistOut1->Fill( i-42, fHistIn->ProjectionY("_py",i,i)->GetMean() );
      fHistOut2->Fill( i-42, fHistIn->ProjectionY("_py",i,i)->GetRMS() );
   }

   return;
}

double OffsetAnalysis::deltaPhi(double phi1, double phi2) {
   double dPhi = fabs(phi1 - phi2);
   if (dPhi > M_PI) dPhi = 2.0*M_PI - dPhi;
   return dPhi;
}

//define this as a plug-in
DEFINE_FWK_MODULE(OffsetAnalysis);
