import FWCore.ParameterSet.Config as cms

process = cms.Process('RECO')

# import of standard configurations
process.load('Configuration/StandardSequences/Services_cff')
process.load('FWCore/MessageService/MessageLogger_cfi')
process.load('Configuration/StandardSequences/MixingNoPileUp_cff')
process.load('Configuration/StandardSequences/GeometryPilot2_cff')
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/RawToDigi_cff')
process.load('Configuration/StandardSequences/Reconstruction_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load('Configuration/EventContent/EventContent_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(CONDOR_MAXEVENTS)
)
process.options = cms.untracked.PSet(
    Rethrow = cms.untracked.vstring('ProductNotFound')
)
# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/2PU_Full_Poisson_50nsBX_IDEAL_V9_GEN-SIM-RAW_103902_0.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/2PU_Full_Poisson_50nsBX_IDEAL_V9_GEN-SIM-RAW_103902_1.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/2PU_Full_Poisson_50nsBX_IDEAL_V9_GEN-SIM-RAW_103902_2.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/2PU_Full_Poisson_50nsBX_IDEAL_V9_GEN-SIM-RAW_103902_3.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/2PU_Full_Poisson_50nsBX_IDEAL_V9_GEN-SIM-RAW_103902_4.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/2PU_Full_Poisson_50nsBX_IDEAL_V9_GEN-SIM-RAW_103902_5.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/2PU_Full_Poisson_50nsBX_IDEAL_V9_GEN-SIM-RAW_103902_6.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/2PU_Full_Poisson_50nsBX_IDEAL_V9_GEN-SIM-RAW_103902_7.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/2PU_Full_Poisson_50nsBX_IDEAL_V9_GEN-SIM-RAW_103902_8.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/2PU_Full_Poisson_50nsBX_IDEAL_V9_GEN-SIM-RAW_103902_9.root'
    ),
    skipEvents = cms.untracked.uint32(CONDOR_SKIPEVENTS)
)

# Output definition
process.output = cms.OutputModule("PoolOutputModule",
    outputCommands = process.RECOSIMEventContent.outputCommands,
    fileName = cms.untracked.string('CONDOR_SCRATCH_DIR/CONDOR_OUTPUTFILENAME.root'),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN-SIM-RECO'),
        filterName = cms.untracked.string('')
    )
)

# Additional output definition

# Other statements
process.GlobalTag.globaltag = 'IDEAL_V9::All'
process.MessageLogger.cerr.FwkReport.reportEvery = 100

# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.reconstruction_step = cms.Path(process.reconstruction)
process.out_step = cms.EndPath(process.output)

# Schedule definition
process.schedule = cms.Schedule(process.raw2digi_step,process.reconstruction_step,process.out_step)
