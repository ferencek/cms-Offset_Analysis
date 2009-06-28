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
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_0.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_1.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_2.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_3.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_4.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_5.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_6.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_7.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_8.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_9.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_10.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_11.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_12.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_13.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_14.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_15.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_16.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_17.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_18.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_19.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_20.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_21.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_22.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_23.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_24.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_25.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_26.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_27.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_28.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_29.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_30.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_31.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_32.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_33.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_34.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_35.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_36.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_37.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_38.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_39.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_40.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_41.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_42.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_43.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_44.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_45.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_46.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_47.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_48.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23350_49.root'
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
