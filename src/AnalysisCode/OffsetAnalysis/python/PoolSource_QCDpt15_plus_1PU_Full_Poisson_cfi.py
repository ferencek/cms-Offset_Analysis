import FWCore.ParameterSet.Config as cms
source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_0.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_1.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_2.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_3.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_4.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_5.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_6.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_7.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_8.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_9.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_10.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_11.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_12.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_13.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_14.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_15.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_16.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_17.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_18.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_19.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_20.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_21.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_22.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_23.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_24.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_25.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_26.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_27.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_28.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_29.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_30.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_31.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_32.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_33.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_34.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_35.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_36.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_37.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_38.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_39.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_40.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_41.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_42.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_43.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_44.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_45.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_46.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_47.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_48.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_16488_49.root'
    )
)