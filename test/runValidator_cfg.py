import FWCore.ParameterSet.Config as cms
process = cms.Process("Analysis")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load('Configuration.Geometry.GeometryRecoDB_cff')
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.GlobalTag.globaltag = cms.string("102X_upgrade2018_realistic_v15")

process.load("Analysis.displacedMuons-Validator.recoValidator_cfi")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)


process.source = cms.Source(
    "PoolSource",
    fileNames = cms.untracked.vstring(
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_0.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_1.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_2.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_3.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_4.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_5.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_6.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_7.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_8.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_9.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_10.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_11.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_12.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_13.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_14.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_15.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_16.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_17.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_18.root',
'file:/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/ZMM_HS/RECO_v2/output_19.root'
    )
)

process.options = cms.untracked.PSet(
    numberOfThreads = cms.untracked.uint32(8)
)

process.source.duplicateCheckMode = cms.untracked.string('noDuplicateCheck')


## path definitions
process.p      = cms.Path(
    process.recoValidator

)

