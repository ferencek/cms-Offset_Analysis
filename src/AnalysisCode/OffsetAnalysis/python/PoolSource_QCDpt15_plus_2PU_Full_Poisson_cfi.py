import FWCore.ParameterSet.Config as cms
source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_0.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_1.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_2.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_3.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_4.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_5.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_6.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_7.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_8.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_9.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_10.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_11.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_12.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_13.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_14.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_15.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_16.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_17.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_18.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_19.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_20.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_21.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_22.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_23.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_24.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_25.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_26.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_27.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_28.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_29.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_30.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_31.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_32.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_33.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_34.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_35.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_36.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_37.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_38.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_39.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_40.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_41.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_42.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_43.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_44.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_45.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_46.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_47.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_48.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/QCDpt15_plus_2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_26947_49.root'
    )
)