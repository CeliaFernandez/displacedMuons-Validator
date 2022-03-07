import FWCore.ParameterSet.Config as cms
process = cms.Process("Analysis")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load('Configuration.Geometry.GeometryRecoDB_cff')
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.GlobalTag.globaltag = cms.string("102X_upgrade2018_realistic_v15")

process.load("Analysis.displacedMuons-Validator.patValidator_cfi")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)



process.source = cms.Source(
    "PoolSource",
    fileNames = cms.untracked.vstring(
    'file:/afs/cern.ch/work/f/fernance/private/MuonPOG/L3-RECO/displacedCollections/21-11-17/CMSSW_12_1_0/src/step3_RAW2DIGI_L1Reco_RECO_RECOSIM_EI_PAT_NANO_VALIDATION_DQM_inMINIAODSIM.root')
)



## path definitions
process.p      = cms.Path(
    process.patValidator

)

