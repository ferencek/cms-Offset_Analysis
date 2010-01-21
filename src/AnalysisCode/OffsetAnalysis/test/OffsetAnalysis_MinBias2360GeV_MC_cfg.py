import FWCore.ParameterSet.Config as cms

process = cms.Process("USER")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')

process.load('Geometry.CMSCommonData.cmsIdealGeometryXML_cfi')
process.load('Geometry.CaloEventSetup.CaloGeometry_cff')
process.load('Geometry.CaloEventSetup.CaloTowerConstituents_cfi')

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
process.MessageLogger.cerr.default.limit = 10

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)
# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        # /MinBias/Summer09-STARTUP3X_V8D_2360GeV-v2/GEN-SIM-RECO
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8D_2360GeV-v2/0004/FED63CFD-18DE-DE11-B2B4-002618943957.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8D_2360GeV-v2/0004/FC2A02B4-18DE-DE11-A2C0-0026189438FE.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8D_2360GeV-v2/0004/FAAFEE64-20DE-DE11-A190-002618FDA237.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8D_2360GeV-v2/0004/FA77B88B-17DE-DE11-AD68-00248C0BE014.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8D_2360GeV-v2/0004/E67E0EDD-18DE-DE11-8833-0026189438CF.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8D_2360GeV-v2/0004/E43859B9-1BDE-DE11-8C99-0026189438AC.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8D_2360GeV-v2/0004/DEE92410-1CDE-DE11-857C-00261894387A.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8D_2360GeV-v2/0004/DA79E6B6-1DDE-DE11-AF77-002354EF3BDA.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8D_2360GeV-v2/0004/D80014A9-1EDE-DE11-AB41-002618943944.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8D_2360GeV-v2/0004/D435BCAE-17DE-DE11-A01A-002618943920.root'
    )
)

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('OffsetAnalysis_histos_MinBias2360GeV_STARTUP3X_V8D.root')
)

# For skimming based on technical trigger bits
process.load('HLTrigger.HLTfilters.hltLevel1GTSeed_cfi')
process.hltLevel1GTSeed.L1TechTriggerSeeding = cms.bool(True)
process.hltLevel1GTSeed.L1SeedsLogicalExpression = cms.string('40 OR 41')

# Select only events with at least one good vertex
process.oneGoodVertexFilter = cms.EDFilter("VertexSelector",
   src = cms.InputTag("offlinePrimaryVertices"),
   cut = cms.string("!isFake && tracksSize > 3 && abs(z) <= 15 && position.Rho <= 2"),
   filter = cms.bool(True)   # otherwise it won't filter the events, just produce an empty vertex collection.
)

# Remove the so-called "scaping" events
process.noScraping = cms.EDFilter("FilterOutScraping",
    applyfilter = cms.untracked.bool(True),
    debugOn = cms.untracked.bool(False), ## Or 'True' to get some per-event info
    numtrack = cms.untracked.uint32(10),
    thresh = cms.untracked.double(0.2)
)

process.offsetAnalysis = cms.EDAnalyzer("OffsetAnalysis",
    doOffset = cms.untracked.bool(True),
    towerETcut = cms.untracked.double(0.5),
    #caloTowers = cms.untracked.string('towerMaker'),
    loopOverRecHits = cms.untracked.bool(False),
    recHitEvtLimit = cms.untracked.int32(2000),
    doPVs = cms.untracked.bool(False),
    maxNPVs = cms.untracked.int32(5),
    pvCollection = cms.InputTag('offlinePrimaryVertices')
)

process.GlobalTag.globaltag = 'STARTUP3X_V8D::All'

# Path definition
process.p = cms.Path(process.hltLevel1GTSeed*process.oneGoodVertexFilter*process.noScraping*process.offsetAnalysis)
process.schedule = cms.Schedule(process.p)
