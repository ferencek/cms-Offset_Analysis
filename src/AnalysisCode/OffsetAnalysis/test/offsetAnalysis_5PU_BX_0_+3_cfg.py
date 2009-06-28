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
    input = cms.untracked.int32(-1)
)
# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_8/test/MCdata/5PU_Full_Poisson_BX_0_+3_IDEAL_V9_GEN-SIM-RECO_102522_0.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_8/test/MCdata/5PU_Full_Poisson_BX_0_+3_IDEAL_V9_GEN-SIM-RECO_102522_1.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_8/test/MCdata/5PU_Full_Poisson_BX_0_+3_IDEAL_V9_GEN-SIM-RECO_102522_2.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_8/test/MCdata/5PU_Full_Poisson_BX_0_+3_IDEAL_V9_GEN-SIM-RECO_102522_3.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_8/test/MCdata/5PU_Full_Poisson_BX_0_+3_IDEAL_V9_GEN-SIM-RECO_102522_4.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_8/test/MCdata/5PU_Full_Poisson_BX_0_+3_IDEAL_V9_GEN-SIM-RECO_102522_5.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_8/test/MCdata/5PU_Full_Poisson_BX_0_+3_IDEAL_V9_GEN-SIM-RECO_102522_6.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_8/test/MCdata/5PU_Full_Poisson_BX_0_+3_IDEAL_V9_GEN-SIM-RECO_102522_7.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_8/test/MCdata/5PU_Full_Poisson_BX_0_+3_IDEAL_V9_GEN-SIM-RECO_102522_8.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_8/test/MCdata/5PU_Full_Poisson_BX_0_+3_IDEAL_V9_GEN-SIM-RECO_102522_9.root'
    )
)

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('5PU_Full_Poisson_BX_0_+3_ET0.5.root')
)

process.offsetAnalysis = cms.EDAnalyzer("OffsetAnalysis",
    doOffset = cms.untracked.bool(True),
    towerETcut = cms.untracked.double(0.5),
    #caloTowers = cms.untracked.string('towerMakerAlt'),
    loopOverRecHits = cms.untracked.bool(False),
    recHitEvtLimit = cms.untracked.int32(2000),
    doPVs = cms.untracked.bool(False),
    maxNPVs = cms.untracked.int32(5),
    pvCollection = cms.InputTag('offlinePrimaryVertices'),
    savePlots = cms.untracked.bool(False),
    outputDir = cms.untracked.string('plots'),
    doEPS = cms.untracked.bool(True),
    doPNG = cms.untracked.bool(True)
)

process.p1 = cms.Path(process.offsetAnalysis)
process.schedule = cms.Schedule(process.p1)
