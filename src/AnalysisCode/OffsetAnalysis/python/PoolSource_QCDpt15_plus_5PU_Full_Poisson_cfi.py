import FWCore.ParameterSet.Config as cms
source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_0.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_1.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_2.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_3.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_4.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_5.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_6.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_7.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_8.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_9.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_10.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_11.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_12.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_13.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_14.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_15.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_16.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_17.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_18.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_19.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_20.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_21.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_22.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_23.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_24.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_25.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_26.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_27.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_28.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_29.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_30.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_31.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_32.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_33.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_34.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_35.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_36.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_37.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_38.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_39.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_40.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_41.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_42.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_43.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_44.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_45.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_46.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_47.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_48.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_30269_49.root'
    )
)