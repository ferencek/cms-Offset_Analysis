import FWCore.ParameterSet.Config as cms

process = cms.Process("USER")

process.load("Geometry.CMSCommonData.cmsIdealGeometryXML_cfi")
process.load("Geometry.CaloEventSetup.CaloGeometry_cfi")

process.CaloTowerConstituentsMapBuilder = cms.ESProducer("CaloTowerConstituentsMapBuilder",
    MapFile = cms.untracked.string('Geometry/CaloTopology/data/CaloTowerEEGeometric.map.gz')
)

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.default.limit = 10
process.MessageLogger.cerr.FwkReport.reportEvery = 500

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(MAX_EVTS)
)

process.load("AnalysisCode.OffsetAnalysis.PoolSource_INPUT_POOLSOURCE_cfi")

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('OUTPUT_FILENAME.root')
)

process.offsetAnalysis = cms.EDAnalyzer("OffsetAnalysis",
    doOffset = cms.untracked.bool(DO_OFFSET),
    towerETcut = cms.untracked.double(0.5),
    #caloTowers = cms.untracked.string('towerMakerAlt'),
    loopOverRecHits = cms.untracked.bool(False),
    recHitEvtLimit = cms.untracked.int32(2000),
    doPVs = cms.untracked.bool(DO_PVS),
    maxNPVs = cms.untracked.int32(MAX_NPVS),
    pvCollection = cms.InputTag('PV_COLLECTION'),
    savePlots = cms.untracked.bool(False),
    outputDir = cms.untracked.string('plots'),
    doEPS = cms.untracked.bool(True),
    doPNG = cms.untracked.bool(True)
)

process.p1 = cms.Path(process.offsetAnalysis)
process.schedule = cms.Schedule(process.p1)
