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
        # /MinBias/Summer09-STARTUP3X_V8I_900GeV-v2/GEN-SIM-RECO
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/FCA81316-A5E2-DE11-A61A-0026189438D8.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/FC76A5C3-9CE2-DE11-8ADF-002354EF3BE0.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/FA9D2353-9CE2-DE11-865F-002618943831.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/F8D6B6ED-A0E2-DE11-A25E-002618FDA265.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/F8CCAC3B-99E2-DE11-BA43-002618943978.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/F8C7D01C-99E2-DE11-A3D8-0026189438C4.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/F88AA677-9BE2-DE11-A6EB-002618943860.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/F8741D98-9CE2-DE11-90EB-002618943860.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/F6630609-A1E2-DE11-9B5E-002618943886.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/F62F7579-9BE2-DE11-A94D-002618943860.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/F436F949-A1E2-DE11-9320-002618943960.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/F427A842-9FE2-DE11-AA2C-00261894386E.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/F2E938F0-A0E2-DE11-988C-0026189438C0.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/F29595A5-9CE2-DE11-9C6D-0026189438E3.root',
        '/store/mc/Summer09/MinBias/GEN-SIM-RECO/STARTUP3X_V8I_900GeV-v2/0002/F2434B24-A1E2-DE11-BD9A-002618943821.root'
    )
)

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('OffsetAnalysis_histos_MinBias900GeV_STARTUP3X_V8I.root')
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

process.GlobalTag.globaltag = 'STARTUP3X_V8I::All'

# Path definition
process.p = cms.Path(process.hltLevel1GTSeed*process.oneGoodVertexFilter*process.noScraping*process.offsetAnalysis)
process.schedule = cms.Schedule(process.p)
