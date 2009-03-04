import FWCore.ParameterSet.Config as cms
source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       '/store/mc/Summer08/MinBias/GEN-SIM-RECO/IDEAL_V9_v1/0054/02328B76-C88B-DD11-8DD5-003048770348.root',
       '/store/mc/Summer08/MinBias/GEN-SIM-RECO/IDEAL_V9_v1/0054/024E589C-648B-DD11-8C62-001E682F205C.root',
       '/store/mc/Summer08/MinBias/GEN-SIM-RECO/IDEAL_V9_v1/0054/027BD798-758B-DD11-8CAA-001EC9AA932E.root',
       '/store/mc/Summer08/MinBias/GEN-SIM-RECO/IDEAL_V9_v1/0054/027FDE83-758B-DD11-9DE9-003048770DC2.root',
       '/store/mc/Summer08/MinBias/GEN-SIM-RECO/IDEAL_V9_v1/0054/02830C1E-778B-DD11-BADA-003048770DB8.root',
       '/store/mc/Summer08/MinBias/GEN-SIM-RECO/IDEAL_V9_v1/0054/02A8B62D-7F8B-DD11-B7EC-001EC9AAD530.root'
    )
)