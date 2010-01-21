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
        # /MinimumBias/BeamCommissioning09-BSCNOBEAMHALO-Dec14thSkim_v1/RAW-RECO, Run 124120
        '/store/data/BeamCommissioning09/MinimumBias/RAW-RECO/BSCNOBEAMHALO-Dec14thSkim_v1/0100/88681630-17EA-DE11-8259-0024E8768299.root',
        '/store/data/BeamCommissioning09/MinimumBias/RAW-RECO/BSCNOBEAMHALO-Dec14thSkim_v1/0100/5685AC0D-18EA-DE11-B2F9-001D096760DE.root'
    )
)

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('OffsetAnalysis_histos_Collisions_R124120_2360GeV.root')
)

# For skimming based on the HLT_PhysicsDeclared bit
from HLTrigger.HLTfilters.hltHighLevelDev_cfi import hltHighLevelDev
process.physDecl = hltHighLevelDev.clone(HLTPaths = ['HLT_PhysicsDeclared'], HLTPathsPrescales = [1])

# For skimming based on technical trigger bits
process.load("L1TriggerConfig.L1GtConfigProducers.L1GtTriggerMaskTechTrigConfig_cff")
process.load('HLTrigger.HLTfilters.hltLevel1GTSeed_cfi')
process.hltLevel1GTSeed.L1TechTriggerSeeding = cms.bool(True)
process.hltLevel1GTSeed.L1SeedsLogicalExpression = cms.string('0 AND (40 OR 41) AND NOT (36 OR 37 OR 38 OR 39)')

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
    towerETcut = cms.untracked.double(0.3),
    #caloTowers = cms.untracked.string('towerMaker'),
    loopOverRecHits = cms.untracked.bool(False),
    recHitEvtLimit = cms.untracked.int32(2000),
    doPVs = cms.untracked.bool(False),
    maxNPVs = cms.untracked.int32(5),
    pvCollection = cms.InputTag('offlinePrimaryVertices')
)

process.GlobalTag.globaltag = 'GR09_P_V7::All'

# Path definition
process.p = cms.Path(process.physDecl*process.hltLevel1GTSeed*process.oneGoodVertexFilter*process.noScraping*process.offsetAnalysis)
process.schedule = cms.Schedule(process.p)
