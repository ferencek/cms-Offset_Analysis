// -*- C++ -*-
//
// Package:    EffJetArea
// Class:      EffJetArea
// 
/**\class EffJetArea EffJetArea.cc AnalysisCode/OffsetAnalysis/src/EffJetArea.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  "Dinko Ferencek"
//         Created:  Thu Jul 10 16:58:39 CDT 2008
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

#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "DataFormats/JetReco/interface/CaloJetCollection.h"

//TFile Service
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "PhysicsTools/UtilAlgos/interface/TFileService.h"

// ROOT
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TH3D.h>
#include <TProfile.h>
#include <TProfile2D.h>
#include <Math/VectorUtil.h>

using namespace edm;
using namespace std;
using namespace reco;
using namespace ROOT::Math::VectorUtil;

//
// class declaration
//

class EffJetArea : public edm::EDAnalyzer {
   public:
      explicit EffJetArea(const edm::ParameterSet&);
      ~EffJetArea();


   private:
      virtual void beginJob(const edm::EventSetup&) ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      // ----------member data ---------------------------
      edm::Service<TFileService> fs;
      
      double dRmin_;
      double coneArea;
      
      edm::InputTag genJets_;
      edm::InputTag caloJets_;
      
      Handle<GenJetCollection>  genJets;
      Handle<CaloJetCollection>  caloJets;
      
      TH1D *h_DeltaR;
      TH3D *h_EffJetArea_eta_pT;
      TProfile2D *p_EffJetArea_eta_pT;
      TH2D *h_EffJetArea_pT;
      TProfile *p_EffJetArea_pT;
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
EffJetArea::EffJetArea(const edm::ParameterSet& iConfig)
{
   //now do what ever initialization is needed
   genJets_  = iConfig.getParameter<edm::InputTag> ( "genJets" );
   caloJets_ = iConfig.getParameter<edm::InputTag> ( "caloJets" );
   dRmin_    = iConfig.getParameter<double> ( "dRmin" );
   
   coneArea = 0.5*0.5*M_PI;
}


EffJetArea::~EffJetArea()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called once each job just before starting event loop  ------------
void 
EffJetArea::beginJob(const edm::EventSetup&)
{

   // book histograms
   h_DeltaR        = fs->make<TH1D>("h_DeltaR","#DeltaR(GenJet,CaloJet);#DeltaR;Entries/0.01",25,0.,.25);
   h_EffJetArea_eta_pT = fs->make<TH3D>("h_EffJetArea_eta_pT",";#eta;p_{T}^{gen} [GeV/c];towersArea/R_{cone}^{2}#pi",100,-5.,5.,200,0.,200.,110,0.,1.1);
   p_EffJetArea_eta_pT = fs->make<TProfile2D>("p_EffJetArea_eta_pT",";#eta;p_{T}^{gen} [GeV/c];<towersArea/R_{cone}^{2}#pi>",100,-5.,5.,200,0.,200.);
   h_EffJetArea_pT = fs->make<TH2D>("h_EffJetArea_pT",";p_{T}^{gen} [GeV/c];towersArea/R_{cone}^{2}#pi",200,0.,200.,110,0.,1.1);
   p_EffJetArea_pT = fs->make<TProfile>("p_EffJetArea_pT",";p_{T}^{gen} [GeV/c];<towersArea/R_{cone}^{2}#pi>",200,0.,200.);
}

// ------------ method called to for each event  ------------
void
EffJetArea::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

   try {
       iEvent.getByLabel (genJets_, genJets);
       iEvent.getByLabel (caloJets_, caloJets);
    } catch(std::exception& ce) {
       cerr << ">> [EffJetArea] caught std::exception " << ce.what() << endl;
       return;
   }

  
   for (GenJetCollection::const_iterator g = genJets->begin(); g != genJets->end(); ++g ) {
   
      double dR = -1.;
      double towersArea = 0.;
      double caloEta = 0.;
      
      for (CaloJetCollection::const_iterator c = caloJets->begin(); c != caloJets->end(); ++c ) {
      
         double deltaR = DeltaR( g->p4(), c->p4() );
         if ( dR < 0 && deltaR < dRmin_ ) {
            dR = deltaR;
            towersArea = c->towersArea();
            caloEta = c->eta();
         }
         else if ( deltaR < dR ) {
            dR = deltaR;
            towersArea = c->towersArea();
            caloEta = c->eta();
         }
      }
      
      if ( dR > 0 ) {
         double effJetArea = towersArea/coneArea;
         h_EffJetArea_eta_pT->Fill( caloEta, g->pt(), effJetArea );
         p_EffJetArea_eta_pT->Fill( caloEta, g->pt(), effJetArea );
         h_EffJetArea_pT->Fill( g->pt(), effJetArea );
         p_EffJetArea_pT->Fill( g->pt(), effJetArea );
         h_DeltaR->Fill( dR );
      }
   }
}

// ------------ method called once each job just after ending the event loop  ------------
void 
EffJetArea::endJob() {

}

//define this as a plug-in
DEFINE_FWK_MODULE(EffJetArea);
