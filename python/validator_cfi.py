import FWCore.ParameterSet.Config as cms

validator = cms.EDAnalyzer('validator',
    nameOfOutput = cms.string('output.root'),
    EventInfo = cms.InputTag("generator"),
    RunInfo = cms.InputTag("generator"),
    GenCollection = cms.InputTag("genParticles"),
    MuonCollection = cms.InputTag("muons"),
    DisplacedCollection = cms.InputTag("displacedMuons"),
    DisplacedGlobalCollection = cms.InputTag("displacedGlobalMuons"),
    DisplacedTrackCollection = cms.InputTag("displacedTracks"),
    DisplacedStandaloneCollection = cms.InputTag("displacedStandAloneMuons"),
    theGenEventInfoProduct = cms.InputTag("generator"),
)


