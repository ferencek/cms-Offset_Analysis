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
// $Id: OffsetAnalysis.cc,v 1.2 2009/06/28 17:51:43 ferencek Exp $
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
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"

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
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"

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
      void fillHistos(const TH2F* fHistIn, TH1F* fHistOut1, TH1F* fHistOut2);
      double deltaPhi(double phi1, double phi2);
      
      // ----------member data ---------------------------
      edm::Service<TFileService> fs;
      
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
      
      TH1F *h_CaloTowerE;
      TH1F *h_CaloTowerET;
      TH1F *h_nCaloTowers;
      
      TH2F *h_FracConeArea;
      TProfile *p_FracConeArea;
      
      TH2F *h_EinC5_Eta;
      TProfile *p_AvgEinC5;

      TProfile *p_AvgEinC5HB;
      TProfile *p_AvgEinC5HE;
      TProfile *p_AvgEinC5HO;
      TProfile *p_AvgEinC5HFl;
      TProfile *p_AvgEinC5HFs;
      TProfile *p_AvgEinC5EB;
      TProfile *p_AvgEinC5EE;
      
      TH2F *h_pTinC5_Eta;
      TProfile *p_AvgpTinC5;
      
      TH2F *h_EinER_iEta;
      TProfile *p_AvgEinER;

      TProfile *p_AvgEinERHB;
      TProfile *p_AvgEinERHE;
      TProfile *p_AvgEinERHO;
      TProfile *p_AvgEinERHFl;
      TProfile *p_AvgEinERHFs;
      TProfile *p_AvgEinEREB;
      TProfile *p_AvgEinEREE;
      
      TH1F *h_NofPVs;
      TH1F *h_NofPVTracks;
      TH1F *h_PVChi2overNdof;
      TH1F *h_PVz;
      TH1F *h_NofCPs;
      TH1F *h_NofCPsEta25;
      TH2F *h_NofPVs_NofCPsEta25;
      
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

      // CaloGeometry
      ESHandle<CaloGeometry> caloGeometry;
      // CaloTowerConstituentsMap
      ESHandle<CaloTowerConstituentsMap> caloTowerConstituentsMap;
      
      bool jobStartFlag;
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
   
   // CaloTower histograms
   h_CaloTowerE      = fs->make<TH1F>("h_CaloTowerE", "CaloTower Energy;E [GeV]",200,-5,10);
   h_CaloTowerET     = fs->make<TH1F>("h_CaloTowerET", "CaloTower E_{T};E_{T} [GeV]",200,-2,3);
   h_nCaloTowers   = fs->make<TH1F>("h_nCaloTowers","Number of CaloTowers per Event;Number of Calotowers",6000,0,6000);
   
   // fractional cone area
   h_FracConeArea = fs->make<TH2F>("h_FracConeArea","FracConeArea:#eta;#eta;towersArea/R_{cone}^{2}#pi",100,-5.,5.,110,0.,1.1);
   p_FracConeArea = fs->make<TProfile>("p_FracConeArea","Effective Cone Area;#eta;<towersArea/R_{cone}^{2}#pi>",100,-5.,5.);
   
   // in-cone energy contributions
   h_EinC5_Eta   = fs->make<TH2F>("h_EinC5_Eta","EinC5:#eta;#eta;E [GeV]",100,-5.,5.,770,-7.8,300.2);
   p_AvgEinC5    = fs->make<TProfile>("p_AvgEinC5", "<E> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   
   p_AvgEinC5EB  = fs->make<TProfile>("p_AvgEinC5EB", "<E_{EB}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   p_AvgEinC5EE  = fs->make<TProfile>("p_AvgEinC5EE", "<E_{EE}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   p_AvgEinC5HB  = fs->make<TProfile>("p_AvgEinC5HB", "<E_{HB}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   p_AvgEinC5HE  = fs->make<TProfile>("p_AvgEinC5HE", "<E_{HE}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   p_AvgEinC5HO  = fs->make<TProfile>("p_AvgEinC5HO", "<E_{HO}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   p_AvgEinC5HFl  = fs->make<TProfile>("p_AvgEinC5HFl", "<E_{HFl}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   p_AvgEinC5HFs  = fs->make<TProfile>("p_AvgEinC5HFs", "<E_{HFs}> in R_{cone}=0.5;#eta;<E> [GeV]",100,-5.,5.);
   
   // in-cone pT contribution
   h_pTinC5_Eta   = fs->make<TH2F>("h_pTinC5_Eta","pTinC5:#eta;#eta;p_{T} [GeV/c]",100,-5.,5.,525,-2.45,50.05);
   p_AvgpTinC5    = fs->make<TProfile>("p_AvgpTinC5", "<p_{T}> in R_{cone}=0.5;#eta;<p_{T}> [GeV/c]",100,-5.,5.);
   
   // energy in iEta rings
   h_EinER_iEta  = fs->make<TH2F>("h_EinER_iEta","EinER:i#eta;i#eta;E [GeV]",83,-41.5,41.5,770,-7.8,300.2);
   p_AvgEinER    = fs->make<TProfile>("p_AvgEinER", "<E> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   
   p_AvgEinEREB    = fs->make<TProfile>("p_AvgEinEREB", "<E_{EB}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   p_AvgEinEREE    = fs->make<TProfile>("p_AvgEinEREE", "<E_{EE}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   p_AvgEinERHB    = fs->make<TProfile>("p_AvgEinERHB", "<E_{HB}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   p_AvgEinERHE    = fs->make<TProfile>("p_AvgEinERHE", "<E_{HE}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   p_AvgEinERHO    = fs->make<TProfile>("p_AvgEinERHO", "<E_{HO}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   p_AvgEinERHFl   = fs->make<TProfile>("p_AvgEinERHFl", "<E_{HFl}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   p_AvgEinERHFs   = fs->make<TProfile>("p_AvgEinERHFs", "<E_{HFs}> in i#eta Ring;i#eta;<E> [GeV]",83,-41.5,41.5);
   
   // Primary Vertices
   if ( doPVs_ ) {
      TFileDirectory pvSubDir = fs->mkdir( "PrimaryVertices" );
      
      h_NofPVs      = pvSubDir.make<TH1F>("h_NofPVs","Number of Reconstructed PV's;# of PV's;Entries",11,-.5,10.5);
      h_NofPVTracks = pvSubDir.make<TH1F>("h_NofPVTracks","Number of Tracks Attached to PV;# of tracks;Entries",100,0.,100.);
      h_PVChi2overNdof = pvSubDir.make<TH1F>("h_PVChi2overNdof","#chi^{2}/ndof;#chi^{2}/ndof;Entries/0.1",110,-1.,10.);
      h_PVz            = pvSubDir.make<TH1F>("h_PVz","z Coordinate of PV's;z [cm];Entries/0.1",300,-15.,15.);
      h_NofCPs         = pvSubDir.make<TH1F>("h_NofCPs","Number of Charged Particles;# of charged particles;Entries",500,0.,500.);
      h_NofCPsEta25    = pvSubDir.make<TH1F>("h_NofCPsEta25","Number of Charged Particles with |#eta|<2.5;# of charged particles;Entries",250,0.,250.);
      h_NofPVs_NofCPsEta25 = pvSubDir.make<TH2F>("h_NofPVs_NofCPsEta25","# of PV's vs. # of Charged Particles with |#eta|<2.5;# of charged particles;# of PV's",250,0.,250.,11,-.5,10.5);
   
      // for PV dependent offset
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
   // mark the start of the job
   jobStartFlag = true;
   // initialize the random number generator
   randomNumber = new TRandom3;
   // initialize the event counter
   nEvt = 0;

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
      
      if (jobStartFlag) {
         // CaloGeometry
         iSetup.get<CaloGeometryRecord>().get(caloGeometry);
         
         // CaloTowerConstituentsMap
         iSetup.get<IdealGeometryRecord>().get(caloTowerConstituentsMap);
         
         jobStartFlag = false;
      }
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
      // sum of tower areas for towers that are inside the cone and above E_T threshold
      double towerAreaSum[100]={0.};
      
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
    
      double EinERHB[83]={0.};
      double EinERHE[83]={0.};
      double EinERHO[83]={0.};
      double EinERHFl[83]={0.};
      double EinERHFs[83]={0.};
      double EinEREB[83]={0.};
      double EinEREE[83]={0.};
      
      
      // initialize random Phi angle of the cone
      conePhi = (randomNumber->Uniform(-1.,1.))*M_PI;
      
      // =================== CaloTowers ====================================
      h_nCaloTowers->Fill(caloTowers->size());
      // loop over all CaloTowers
      for (CaloTowerCollection::const_iterator t = caloTowers->begin(); t != caloTowers->end(); ++t ) {
      
         double ET = t->et();
         if( ET < towerETcut_ ) continue;
         
         double towerArea = 0;
         // get area of the tower
         const CaloSubdetectorGeometry* towerGeometry = caloGeometry->getSubdetectorGeometry(DetId::Calo, CaloTowerDetId::SubdetId);
         const CaloCellGeometry* geometry = towerGeometry->getGeometry(t->id());
         if (geometry) {
           double dEta = fabs (geometry->getCorners() [0].eta() - geometry->getCorners() [2].eta());
           double dPhi = fabs (geometry->getCorners() [0].phi() - geometry->getCorners() [2].phi());
           towerArea = dEta * dPhi;
         }
         
         // double energySum = t->emEnergy()+t->hadEnergy()+t->outerEnergy(); //CaloTower energy (gets negative values as well)
         double energy = t->energy(); // CaloTower energy (gets positive values only)
         double eta = t->eta();
         int iEta = t->ieta();
         
         h_CaloTowerE->Fill( energy );
         h_CaloTowerET->Fill( ET );
         
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
                  if ( abs(detId.ieta())==28 && detId.depth()==3 ){
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
    
         EinERHB[iEta+41] += energyInHB;
         EinERHE[iEta+41] += energyInHE;
         EinERHO[iEta+41] += energyInHO;
         EinERHFl[iEta+41] += energyInHFl;
         EinERHFs[iEta+41] += energyInHFs;
         EinEREB[iEta+41] += energyInEB;
         EinEREE[iEta+41] += energyInEE;
         
         // loop over cones centered at different eta values and add energy from the calotower if it is within dR=0.5 from the cone axis
         for (int i = 0; i < 100; i++) {
            double coneEta = -4.95 + double(i)*0.1;
            double dPhi = deltaPhi(t->phi(), conePhi);
            double dEta = eta - coneEta ;
            double dR = sqrt(dPhi*dPhi + dEta*dEta);
            
            if (dR < 0.5){
               towerAreaSum[i] += towerArea;
             
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
         
         double fracConeArea = towerAreaSum[i]/(0.5*0.5*M_PI);
         
         h_FracConeArea->Fill(coneEta,fracConeArea);
         p_FracConeArea->Fill(coneEta,fracConeArea);
         
         h_EinC5_Eta->Fill(coneEta,EinC5[i]);
         p_AvgEinC5->Fill(coneEta,EinC5[i]);
         
         p_AvgEinC5HB->Fill(coneEta,EinC5HB[i]);
         p_AvgEinC5HE->Fill(coneEta,EinC5HE[i]);
         p_AvgEinC5HO->Fill(coneEta,EinC5HO[i]);
         p_AvgEinC5HFl->Fill(coneEta,EinC5HFl[i]);
         p_AvgEinC5HFs->Fill(coneEta,EinC5HFs[i]);
         p_AvgEinC5EB->Fill(coneEta,EinC5EB[i]);
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
           
         p_AvgEinERHB->Fill(i-41,EinERHB[i]);
         p_AvgEinERHE->Fill(i-41,EinERHE[i]);
         p_AvgEinERHO->Fill(i-41,EinERHO[i]);
         p_AvgEinERHFl->Fill(i-41,EinERHFl[i]);
         p_AvgEinERHFs->Fill(i-41,EinERHFs[i]);
         p_AvgEinEREB->Fill(i-41,EinEREB[i]);
         p_AvgEinEREE->Fill(i-41,EinEREE[i]);
      }
   } // if ( doOffset_ )
   // increment the event counter
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
