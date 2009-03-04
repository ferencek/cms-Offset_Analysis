import FWCore.ParameterSet.Config as cms

process = cms.Process("USER")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.default.limit = 10
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.maxEvents = cms.untracked.PSet( 
    input = cms.untracked.int32(-1) 
)

process.load("AnalysisCode.OffsetAnalysis.PoolSource_QCDpt15_plus_5PU_InTime_Poisson_cfi")

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('closureAnalysis_QCDpt15_plus_5PU_InTime_Poisson_corrected_Avg_Lumi_ET0.5.root')
)

process.caloJetCollectionClone = cms.EDProducer("CaloJetShallowCloneProducer",
    src = cms.InputTag("iterativeCone5CaloJets")
)

process.genJetCollectionClone = cms.EDProducer("GenJetShallowCloneProducer",
    src = cms.InputTag("iterativeCone5GenJets")
)

process.caloJetSele = cms.EDFilter("PtMinCandSelector",
    src = cms.InputTag("caloJetCollectionClone"),
    ptMin = cms.double(3.0)
)

process.genJetSele = cms.EDFilter("PtMinCandSelector",
    src = cms.InputTag("genJetCollectionClone"),
    ptMin = cms.double(15.0)
)

process.caloGenMatchMany = cms.EDFilter("CandOneToManyDeltaRMatcher",
    printDebug = cms.untracked.bool(False),
    src = cms.InputTag("caloJetSele"),
    matched = cms.InputTag("genJetSele")
)
process.caloCaloMatchMany = cms.EDFilter("CandOneToManyDeltaRMatcher",
    printDebug = cms.untracked.bool(False),
    src = cms.InputTag("caloJetSele"),
    matched = cms.InputTag("caloJetSele")
)

process.closureAnalysis = cms.EDAnalyzer('ClosureAnalysis',
    src = cms.InputTag('caloJetSele'),
    matched = cms.InputTag('genJetSele'),
    caloGenMatchMapMany = cms.InputTag('caloGenMatchMany'),
    caloCaloMatchMapMany = cms.InputTag('caloCaloMatchMany'),
    deltaR_max     = cms.double(0.25),
    iso_deltaR     = cms.double(1.0),
    doCorr         = cms.bool(True),
    doPVs          = cms.bool(False),
    maxNPVs        = cms.int32(4),
    pvCollection   = cms.InputTag('offlinePrimaryVertices'),
    offsetCorrPath = cms.string('/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_8/src/AnalysisCode/OffsetAnalysis/test/root_files/5PU_InTime_Poisson_ET0.5.root')
)

#process.printEventNumber = cms.OutputModule("AsciiOutputModule")

process.p = cms.Path(process.caloJetCollectionClone*process.genJetCollectionClone*process.caloJetSele*process.genJetSele*process.caloGenMatchMany*process.caloCaloMatchMany*process.closureAnalysis)
#process.outpath = cms.EndPath(process.printEventNumber)
