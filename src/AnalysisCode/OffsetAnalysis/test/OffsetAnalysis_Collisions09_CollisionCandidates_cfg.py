import FWCore.ParameterSet.Config as cms

process = cms.Process("USER")

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')

process.load('Geometry.CMSCommonData.cmsIdealGeometryXML_cfi')
process.load('Geometry.CaloEventSetup.CaloGeometry_cff')
process.load('Geometry.CaloEventSetup.CaloTowerConstituents_cfi')

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 10000
process.MessageLogger.cerr.default.limit = 10

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)
# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        # /MinimumBias/BeamCommissioning09-rereco_GR09_P_V7_v1/RECO, Run 123596
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/DABD5D6D-D4E2-DE11-8FFD-00261894387A.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/C476D121-DCE2-DE11-9DBB-002618943832.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/C0BE8D91-D5E2-DE11-BD6C-002618943829.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/C070AD79-D5E2-DE11-8A74-00261894387A.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/BEE0F677-15E3-DE11-9A0A-00248C0BE014.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/B6E79B91-D5E2-DE11-96B4-002618943984.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/B67DBF91-D5E2-DE11-A457-00261894395F.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/AC65FE60-D5E2-DE11-857A-002618943954.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/A2F66B2A-DBE2-DE11-A797-002618943901.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/A0A2F242-DDE2-DE11-B1EA-00248C0BE018.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/9CFCF26C-D5E2-DE11-A1BC-0026189438B3.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/9C2F4A3B-D7E2-DE11-8196-002354EF3BE0.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/9AC66043-DDE2-DE11-9E2D-0026189438DC.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/88079B43-DDE2-DE11-B5D6-00261894390C.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/8669F4A2-D8E2-DE11-BE6C-002618943884.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/72AF4044-D2E2-DE11-847B-0026189438C4.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/6683E742-DDE2-DE11-AA1D-002618943906.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/6481D742-DDE2-DE11-BBDD-002354EF3BE0.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/5EAC831D-DCE2-DE11-9247-002354EF3BE0.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/5EA38391-D5E2-DE11-B4A0-002618943910.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/50EC766E-D4E2-DE11-B9C4-0026189438B3.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/44835322-DCE2-DE11-A121-0026189438DC.root',
        '/store/data/BeamCommissioning09/MinimumBias/RECO/rereco_GR09_P_V7_v1/0099/26264A85-D5E2-DE11-8047-002618943906.root'
    )
)

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('OffsetAnalysis_histos_CollisionCandidates_R123596.root')
)

# For skimming based on technical trigger bits
process.load("L1TriggerConfig.L1GtConfigProducers.L1GtTriggerMaskTechTrigConfig_cff")
process.es_prefer_l1GtTriggerMaskTechTrig = cms.ESPrefer("L1GtTriggerMaskTechTrigTrivialProducer","l1GtTriggerMaskTechTrig")
process.load('HLTrigger.HLTfilters.hltLevel1GTSeed_cfi')
process.hltLevel1GTSeed.L1TechTriggerSeeding = cms.bool(True)
process.hltLevel1GTSeed.L1SeedsLogicalExpression = cms.string('0 AND 41')

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

process.GlobalTag.globaltag = 'GR09_P_V7::All'

# Path definition
process.p = cms.Path(process.hltLevel1GTSeed*process.offsetAnalysis)
process.schedule = cms.Schedule(process.p)
