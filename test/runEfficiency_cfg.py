import FWCore.ParameterSet.Config as cms
process = cms.Process("DGAnalysis")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load('Configuration.Geometry.GeometryRecoDB_cff')
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load("TrackPropagation.SteppingHelixPropagator.SteppingHelixPropagatorOpposite_cfi")
process.GlobalTag.globaltag = cms.string("106X_upgrade2018_realistic_v15_L1v1")

process.load("Analysis.displacedCollections-Analyzer.displacedEfficiency_cfi")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)



process.source = cms.Source(
    "PoolSource",
    fileNames = cms.untracked.vstring(
    'file:/eos/user/f/fernance/LLP_Analysis/testfiles/2018UL/EXO-RunIISummer20UL18MiniAODv2_400_50_100.root')
)



## path definitions
process.p      = cms.Path(
    process.displacedEfficiency

)

