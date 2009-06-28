import FWCore.ParameterSet.Config as cms

process = cms.Process("USER")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.default.limit = 10
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.maxEvents = cms.untracked.PSet( 
    input = cms.untracked.int32(-1) 
)

process.load("AnalysisCode.OffsetAnalysis.PoolSource_QCDpt15_plus_5PU_Full_Poisson_cfi")

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('effJetArea_QCDpt15_plus_5PU_Full_Poisson.root')
)

process.effJetArea = cms.EDAnalyzer('EffJetArea',
    genJets = cms.InputTag('iterativeCone5GenJets'),
    caloJets = cms.InputTag('iterativeCone5CaloJets'),
    dRmin = cms.double(0.15),
)

#process.printEventNumber = cms.OutputModule("AsciiOutputModule")

process.p = cms.Path(process.effJetArea)
#process.outpath = cms.EndPath(process.printEventNumber)
