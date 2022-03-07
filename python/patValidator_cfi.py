import FWCore.ParameterSet.Config as cms

patValidator = cms.EDAnalyzer('recoValidator',
    nameOfOutput = cms.string('output.root'),
    EventInfo = cms.InputTag("generator"),
    RunInfo = cms.InputTag("generator"),
    MuonCollection = cms.InputTag("muons"),
    DisplacedCollection = cms.InputTag("slimmedDisplacedMuons"),
    DisplacedGlobalCollection = cms.InputTag("displacedGlobalMuons"),
    DisplacedTrackCollection = cms.InputTag("displacedTracks"),
    DisplacedStandaloneCollection = cms.InputTag("displacedStandAloneMuons"),
    theGenEventInfoProduct = cms.InputTag("generator"),
)


