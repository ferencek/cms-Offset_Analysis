import FWCore.ParameterSet.Config as cms

process = cms.Process('USERHLT')

# import of standard configurations
process.load('Configuration/StandardSequences/Services_cff')
process.load('FWCore/MessageService/MessageLogger_cfi')
process.load('Configuration/StandardSequences/GeometryPilot2_cff')
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/VtxSmearedEarly10TeVCollision_cff')
process.load('Configuration/StandardSequences/Digi_cff')
process.load('Configuration/StandardSequences/SimL1Emulator_cff')
process.load('L1TriggerConfig/L1GtConfigProducers/Luminosity/lumi1030.L1Menu2008_2E30_Unprescaled_cff')
process.load('Configuration/StandardSequences/DigiToRaw_cff')
process.load('HLTrigger/Configuration/HLT_2E30_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load('Configuration/EventContent/EventContent_cff')

# grab all starting seeds from /dev/urandom
from IOMC.RandomEngine.RandomServiceHelper import RandomNumberServiceHelper
randHelper = RandomNumberServiceHelper(process.RandomNumberGeneratorService)
randHelper.populate()
process.RandomNumberGeneratorService.saveFileName = cms.untracked.string('CONDOR_OUTPUTFILENAME.random')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(CONDOR_MAXEVENTS)
)
process.options = cms.untracked.PSet(
    Rethrow = cms.untracked.vstring('ProductNotFound')
)
# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_13.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_14.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_15.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_16.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_17.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_18.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_19.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_20.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_21.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_23.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_24.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_25.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_26.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_27.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_28.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_29.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_30.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_31.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_32.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_33.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_34.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_35.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_36.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_37.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_38.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_39.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_40.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_41.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_42.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_43.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_44.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_45.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_46.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_47.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_48.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_49.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_50.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_51.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_52.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_53.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_54.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_55.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_56.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_57.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_58.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_59.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_60.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_61.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_62.root',
       '/store/user/ferencek/MCdata/QCDpt15/QCDpt15_Summer08_IDEAL_V9_GEN-SIM_64.root'
    ),
    skipEvents = cms.untracked.uint32(CONDOR_SKIPEVENTS)
)

# Mixing Module
from SimGeneral.MixingModule.mixObjects_cfi import *
process.mix = cms.EDFilter("MixingModule",
    LabelPlayback = cms.string(''),
    maxBunch = cms.int32(3),
    minBunch = cms.int32(-5), ## in terms of 25 ns
    bunchspace = cms.int32(25), ## nsec
    playback = cms.untracked.bool(False),
     
    input = cms.SecSource("PoolSource",
        nbPileupEvents = cms.PSet(
            averageNumber = cms.double(1)
        ),
        seed = cms.int32(1234567),
        type = cms.string('poisson'),
        fileNames = cms.untracked.vstring(
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/067FA3E7-BF82-DD11-AE57-00E08133E532.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/06823458-0C82-DD11-95A5-00163691DA0A.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/06B26108-C881-DD11-8C64-00163691DEEE.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/06CF6ED8-4A82-DD11-8CC9-0002B3E92671.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/06E0B648-6882-DD11-BA82-000E0C4D3F34.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/08020140-DF82-DD11-B0F2-00304865C45E.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/08037470-E181-DD11-A167-00E08130073C.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/085CBB8D-8C82-DD11-9EDD-0002B3E92671.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0864C0A3-BE82-DD11-8976-0002B3E92671.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/08C9F96D-FC81-DD11-8F57-00163691DC0A.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0A45F098-F881-DD11-9DA5-00163691DA0A.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0A83A35B-DA82-DD11-BE22-00E0813266C8.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0A88C719-0382-DD11-A75C-0016368E0DE0.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0AB715EB-3682-DD11-A779-00304865C49C.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0AEF857D-5182-DD11-ADDA-001E681E0F62.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0AFF2199-4184-DD11-840B-0016368E0820.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0C17618D-8C82-DD11-BB83-0002B3E92671.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0C642B25-B181-DD11-BAB8-00163691DC0E.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0C6E1A7C-5182-DD11-B490-001E682F1F9A.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0C910250-1382-DD11-8D17-00163691DE22.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0C9A5FCF-D381-DD11-A253-001E688651D5.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0CA4C1FC-5282-DD11-942E-001E682F1F1E.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0E016CD7-B482-DD11-8EFB-000E0C4D3F34.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0E33EF8E-4184-DD11-9DF1-00163691DDA2.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0E3D5A6B-B681-DD11-8434-00163691DA92.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0E416813-B181-DD11-9A51-00163691D5EA.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0E5918B8-F881-DD11-B2F1-00163691D762.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0E9B29CE-B182-DD11-AC5E-000E0C4D3F34.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/0EB93872-2C82-DD11-9A54-0002B3E92671.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/101025D6-D881-DD11-AE12-00163691D762.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/10261B97-D382-DD11-BFAF-0002B3E92671.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/10833A84-0B82-DD11-B94F-003048322948.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/10CADB67-F882-DD11-A28C-0002B3E92671.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/121858CF-9782-DD11-BBA3-000E0C4D3F34.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/12276B1E-C881-DD11-A27E-00163691D1AE.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/1228ACDA-D881-DD11-9EFF-0016368E0AE8.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/122B1937-D081-DD11-AE5A-00163691DBC6.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/12481D6C-B681-DD11-914D-00163691DC86.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/125C8D10-F682-DD11-B823-000E0C4D3F34.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/126F7260-E082-DD11-8162-003048341AFA.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/128C3C9D-DA82-DD11-867F-00E081325A56.root',
	   '/store/mc/Summer08/MinBias/GEN-SIM-RAW/IDEAL_V9_v1/0029/129C350B-B482-DD11-8641-001EC94BFFEB.root'
        )
    ),
    mixObjects = cms.PSet(
        mixCH = cms.PSet(
            mixCaloHits
        ),
        mixTracks = cms.PSet(
            mixSimTracks
        ),
        mixVertices = cms.PSet(
            mixSimVertices
        ),
        mixSH = cms.PSet(
            mixSimHits
        ),
        mixHepMC = cms.PSet(
            mixHepMCProducts
        )
    )
)
process.pdigi.replace(cms.SequencePlaceholder("mix"),process.mix)

# Output definition
process.output = cms.OutputModule("PoolOutputModule",
    outputCommands = process.RAWSIMEventContent.outputCommands,
    fileName = cms.untracked.string('CONDOR_OUTPUTFILENAME.root'),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN-SIM-RAW'),
        filterName = cms.untracked.string('')
    ),
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('digitization_step')
    )
)

# Additional output definition

# Other statements
process.GlobalTag.globaltag = 'IDEAL_V9::All'
process.MessageLogger.cerr.FwkReport.reportEvery = 100
process.RandomNumberGeneratorService.theSource.initialSeed = CONDOR_RANDOMNUMBER

# Path and EndPath definitions
process.digitization_step = cms.Path(process.pdigi)
process.L1simulation_step = cms.Path(process.SimL1Emulator)
process.digi2raw_step = cms.Path(process.DigiToRaw)
process.out_step = cms.EndPath(process.output)

# Schedule definition
process.schedule = cms.Schedule(process.digitization_step,process.L1simulation_step,process.digi2raw_step,process.HLTriggerFirstPath,process.HLT_L1Jet15,process.HLT_Jet30,process.HLT_Jet50,process.HLT_Jet80,process.HLT_Jet110,process.HLT_Jet180,process.HLT_Jet250,process.HLT_FwdJet20,process.HLT_DoubleJet150,process.HLT_DoubleJet125_Aco,process.HLT_DoubleFwdJet50,process.HLT_DiJetAve15,process.HLT_DiJetAve30,process.HLT_DiJetAve50,process.HLT_DiJetAve70,process.HLT_DiJetAve130,process.HLT_DiJetAve220,process.HLT_TripleJet85,process.HLT_QuadJet30,process.HLT_QuadJet60,process.HLT_SumET120,process.HLT_L1MET20,process.HLT_MET25,process.HLT_MET35,process.HLT_MET50,process.HLT_MET65,process.HLT_MET75,process.HLT_MET35_HT350,process.HLT_Jet180_MET60,process.HLT_Jet60_MET70_Aco,process.HLT_Jet100_MET60_Aco,process.HLT_DoubleJet125_MET60,process.HLT_DoubleFwdJet40_MET60,process.HLT_DoubleJet60_MET60_Aco,process.HLT_DoubleJet50_MET70_Aco,process.HLT_DoubleJet40_MET70_Aco,process.HLT_TripleJet60_MET60,process.HLT_QuadJet35_MET60,process.HLT_IsoEle15_L1I,process.HLT_IsoEle18_L1R,process.HLT_IsoEle15_LW_L1I,process.HLT_LooseIsoEle15_LW_L1R,process.HLT_Ele10_SW_L1R,process.HLT_Ele15_SW_L1R,process.HLT_Ele15_LW_L1R,process.HLT_EM80,process.HLT_EM200,process.HLT_DoubleIsoEle10_L1I,process.HLT_DoubleIsoEle12_L1R,process.HLT_DoubleIsoEle10_LW_L1I,process.HLT_DoubleIsoEle12_LW_L1R,process.HLT_DoubleEle5_SW_L1R,process.HLT_DoubleEle10_LW_OnlyPixelM_L1R,process.HLT_DoubleEle10_Z,process.HLT_DoubleEle6_Exclusive,process.HLT_IsoPhoton30_L1I,process.HLT_IsoPhoton10_L1R,process.HLT_IsoPhoton15_L1R,process.HLT_IsoPhoton20_L1R,process.HLT_IsoPhoton25_L1R,process.HLT_IsoPhoton40_L1R,process.HLT_Photon15_L1R,process.HLT_Photon25_L1R,process.HLT_DoubleIsoPhoton20_L1I,process.HLT_DoubleIsoPhoton20_L1R,process.HLT_DoublePhoton10_Exclusive,process.HLT_L1Mu,process.HLT_L1MuOpen,process.HLT_L2Mu9,process.HLT_IsoMu9,process.HLT_IsoMu11,process.HLT_IsoMu13,process.HLT_IsoMu15,process.HLT_Mu3,process.HLT_Mu5,process.HLT_Mu7,process.HLT_Mu9,process.HLT_Mu11,process.HLT_Mu13,process.HLT_Mu15,process.HLT_Mu15_L1Mu7,process.HLT_Mu15_Vtx2cm,process.HLT_Mu15_Vtx2mm,process.HLT_DoubleIsoMu3,process.HLT_DoubleMu3,process.HLT_DoubleMu3_Vtx2cm,process.HLT_DoubleMu3_Vtx2mm,process.HLT_DoubleMu3_JPsi,process.HLT_DoubleMu3_Upsilon,process.HLT_DoubleMu7_Z,process.HLT_DoubleMu3_SameSign,process.HLT_DoubleMu3_Psi2S,process.HLT_BTagIP_Jet180,process.HLT_BTagIP_Jet120_Relaxed,process.HLT_BTagIP_DoubleJet120,process.HLT_BTagIP_DoubleJet60_Relaxed,process.HLT_BTagIP_TripleJet70,process.HLT_BTagIP_TripleJet40_Relaxed,process.HLT_BTagIP_QuadJet40,process.HLT_BTagIP_QuadJet30_Relaxed,process.HLT_BTagIP_HT470,process.HLT_BTagIP_HT320_Relaxed,process.HLT_BTagMu_DoubleJet120,process.HLT_BTagMu_DoubleJet60_Relaxed,process.HLT_BTagMu_TripleJet70,process.HLT_BTagMu_TripleJet40_Relaxed,process.HLT_BTagMu_QuadJet40,process.HLT_BTagMu_QuadJet30_Relaxed,process.HLT_BTagMu_HT370,process.HLT_BTagMu_HT250_Relaxed,process.HLT_DoubleMu3_BJPsi,process.HLT_DoubleMu4_BJPsi,process.HLT_TripleMu3_TauTo3Mu,process.HLT_IsoTau_MET65_Trk20,process.HLT_IsoTau_MET35_Trk15_L1MET,process.HLT_LooseIsoTau_MET30,process.HLT_LooseIsoTau_MET30_L1MET,process.HLT_DoubleIsoTau_Trk3,process.HLT_DoubleLooseIsoTau,process.HLT_IsoEle8_IsoMu7,process.HLT_IsoEle10_Mu10_L1R,process.HLT_IsoEle12_IsoTau_Trk3,process.HLT_IsoEle10_BTagIP_Jet35,process.HLT_IsoEle12_Jet40,process.HLT_IsoEle12_DoubleJet80,process.HLT_IsoEle5_TripleJet30,process.HLT_IsoEle12_TripleJet60,process.HLT_IsoEle12_QuadJet35,process.HLT_IsoMu14_IsoTau_Trk3,process.HLT_IsoMu7_BTagIP_Jet35,process.HLT_IsoMu7_BTagMu_Jet20,process.HLT_IsoMu7_Jet40,process.HLT_NoL2IsoMu8_Jet40,process.HLT_Mu14_Jet50,process.HLT_Mu5_TripleJet30,process.HLT_BTagMu_Jet20_Calib,process.HLT_ZeroBias,process.HLT_MinBias,process.HLT_MinBiasHcal,process.HLT_MinBiasEcal,process.HLT_MinBiasPixel,process.HLT_MinBiasPixel_Trk5,process.HLT_BackwardBSC,process.HLT_ForwardBSC,process.HLT_CSCBeamHalo,process.HLT_CSCBeamHaloOverlapRing1,process.HLT_CSCBeamHaloOverlapRing2,process.HLT_CSCBeamHaloRing2or3,process.HLT_TrackerCosmics,process.AlCa_IsoTrack,process.AlCa_EcalPhiSym,process.AlCa_EcalPi0,process.HLTriggerFinalPath,process.out_step)
