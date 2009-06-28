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
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_0.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_1.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_2.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_3.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_4.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_5.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_6.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_7.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_8.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_9.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_10.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_11.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_12.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_13.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_14.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_15.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_16.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_17.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_18.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_19.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_20.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_21.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_22.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_23.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_24.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_25.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_26.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_27.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_28.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_29.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_30.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_31.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_32.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_33.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_34.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_35.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_36.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_37.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_38.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_39.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_40.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_41.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_42.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_43.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_44.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_45.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_46.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_47.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_48.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_InTime_Poisson_IDEAL_V9_GEN-SIM-RAW_56754_49.root'
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
