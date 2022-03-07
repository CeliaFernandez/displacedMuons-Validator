import FWCore.ParameterSet.Config as cms

recoValidator = cms.EDAnalyzer('recoValidator',
    nameOfOutput = cms.string('output.root'),
    EventInfo = cms.InputTag("generator"),
    RunInfo = cms.InputTag("generator"),
    BeamSpot = cms.InputTag("offlineBeamSpot"),
    MuonCollection = cms.InputTag("muons"),
    DisplacedCollection = cms.InputTag("displacedMuons"),
    DisplacedGlobalCollection = cms.InputTag("displacedGlobalMuons"),
    DisplacedTrackCollection = cms.InputTag("displacedTracks"),
    DisplacedStandaloneCollection = cms.InputTag("displacedStandAloneMuons"),
    theGenEventInfoProduct = cms.InputTag("generator"),
)


