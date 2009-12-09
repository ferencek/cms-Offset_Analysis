import FWCore.ParameterSet.Config as cms

process = cms.Process("USER")

process.load('Geometry.CMSCommonData.cmsIdealGeometryXML_cfi')
process.load('Geometry.CaloEventSetup.CaloGeometry_cff')
process.load('Geometry.CaloEventSetup.CaloTowerConstituents_cfi')

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 500
process.MessageLogger.cerr.default.limit = 10

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10000)
)
# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        # /ZeroBias/BeamCommissioning09-rereco_GR09_P_V7_v1/RECO, Run 123596
        '/store/data/BeamCommissioning09/ZeroBias/RECO/rereco_GR09_P_V7_v1/0099/FAB518C0-CCE2-DE11-AF25-002618943898.root',
        '/store/data/BeamCommissioning09/ZeroBias/RECO/rereco_GR09_P_V7_v1/0099/F8B75B81-CDE2-DE11-A9EE-0026189438DE.root',
        '/store/data/BeamCommissioning09/ZeroBias/RECO/rereco_GR09_P_V7_v1/0099/F869A7C0-CCE2-DE11-BE48-0026189438C1.root',
        '/store/data/BeamCommissioning09/ZeroBias/RECO/rereco_GR09_P_V7_v1/0099/F2D6FC8F-CDE2-DE11-B492-0026189437ED.root',
    )
)

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('OffsetAnalysis_histos_ZeroBias_R123596.root')
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

# Path definition
process.p = cms.Path(process.offsetAnalysis)
process.schedule = cms.Schedule(process.p)
