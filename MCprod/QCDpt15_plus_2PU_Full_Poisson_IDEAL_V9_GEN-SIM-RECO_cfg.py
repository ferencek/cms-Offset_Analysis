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
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_0.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_1.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_2.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_3.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_4.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_5.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_6.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_7.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_8.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_9.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_10.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_11.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_12.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_13.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_14.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_15.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_16.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_17.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_18.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_19.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_20.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_21.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_22.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_23.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_24.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_25.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_26.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_27.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_28.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_29.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_30.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_31.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_32.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_33.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_34.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_35.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_36.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_37.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_38.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_39.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_40.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_41.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_42.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_43.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_44.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_45.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_46.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_47.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_48.root',
       'file:/uscmst1b_scratch/lpc1/lpcphys/ferencek/CMSSW_2_1_7/test/MCdata/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RAW_23351_49.root'
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
