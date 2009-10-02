import FWCore.ParameterSet.Config as cms
source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/NeutrinoGun_IDEAL_V9_GEN-SIM-RECO_27368_0.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/NeutrinoGun_IDEAL_V9_GEN-SIM-RECO_27368_1.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/NeutrinoGun_IDEAL_V9_GEN-SIM-RECO_27368_2.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/NeutrinoGun_IDEAL_V9_GEN-SIM-RECO_27368_3.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/NeutrinoGun_IDEAL_V9_GEN-SIM-RECO_27368_4.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/NeutrinoGun_IDEAL_V9_GEN-SIM-RECO_27368_5.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/NeutrinoGun_IDEAL_V9_GEN-SIM-RECO_27368_6.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/NeutrinoGun_IDEAL_V9_GEN-SIM-RECO_27368_7.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/NeutrinoGun_IDEAL_V9_GEN-SIM-RECO_27368_8.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/NeutrinoGun_IDEAL_V9_GEN-SIM-RECO_27368_9.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_0.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_1.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_2.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_3.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_4.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_5.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_6.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_7.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_8.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_9.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_10.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_11.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_12.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_13.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_14.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_15.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_16.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_17.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_18.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/1PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27361_19.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_0.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_1.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_2.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_3.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_4.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_5.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_6.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_7.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_8.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_9.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_10.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_11.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_12.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_13.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_14.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_15.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_16.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_17.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_18.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/2PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27360_19.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_0.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_1.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_2.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_3.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_4.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_5.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_6.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_7.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_8.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_9.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_10.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_11.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_12.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_13.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_14.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_15.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_16.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_17.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_18.root',
       'file:/uscms_data/d1/cmsjtmet/MCdata/MC218/5PU_Full_Poisson_IDEAL_V9_GEN-SIM-RECO_27365_19.root'
    )
)