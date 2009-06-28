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

import FWCore.ParameterSet.Config as cms

process.towerMakerAlt = cms.EDFilter("CaloTowersCreator",
    EBSumThreshold = cms.double(0.2), ## GeV, Scheme B
    EBWeight = cms.double(1.0),
    hfInput = cms.InputTag("hfreco"),
    AllowMissingInputs = cms.untracked.bool(False),
    EESumThreshold = cms.double(0.45), ## GeV, Scheme B
    HOThreshold = cms.double(1.1), ## GeV, Scheme B
    HBThreshold = cms.double(0.65), ## GeV, Scheme B
    EBThreshold = cms.double(0.09), ## GeV, ORCA value w/o selective readout
    HcalThreshold = cms.double(-1000.0), ## GeV, -1000 means cut not used 
    HEDWeight = cms.double(1.0),
    EEWeight = cms.double(1.0),
    UseHO = cms.bool(False), ## Disable HO
    HF1Weight = cms.double(1.0),
    HOWeight = cms.double(1.0),
    HESWeight = cms.double(1.0),
    hbheInput = cms.InputTag("hbhereco"),
    HF2Weight = cms.double(1.0),
    HF2Threshold = cms.double(0.7), ## GeV, Oprimized on 10% occupancy
    EEThreshold = cms.double(0.45), ## GeV, ORCA value w/o selective readout
    HESThreshold = cms.double(0.75), ## GeV, Scheme B
    hoInput = cms.InputTag("horeco"),
    HF1Threshold = cms.double(0.4), ## GeV, Oprimized on 10% occupancy
    HEDThreshold = cms.double(0.75), ## GeV, Scheme B
    EcutTower = cms.double(-1000.0), ## GeV, -1000 means cut not used
    ecalInputs = cms.VInputTag(cms.InputTag("ecalRecHit","EcalRecHitsEB"), cms.InputTag("ecalRecHit","EcalRecHitsEE")),
    HBWeight = cms.double(1.0),
    # Method for momentum reconstruction
    MomConstrMethod = cms.int32(0),
    #Depth, fraction of the respective calorimeter [0,1]
    MomEmDepth = cms.double(0),
    MomHadDepth = cms.double(0),
    MomTotDepth = cms.double(0)
)

process.offsetAnalysis = cms.EDAnalyzer("OffsetAnalysis",
    doOffset = cms.untracked.bool(DO_OFFSET),
    towerETcut = cms.untracked.double(0.5),
    caloTowers = cms.untracked.string('towerMakerAlt'),
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

process.p0 = cms.Path(process.towerMakerAlt)
process.p1 = cms.Path(process.offsetAnalysis)
process.schedule = cms.Schedule(process.p0,process.p1)
