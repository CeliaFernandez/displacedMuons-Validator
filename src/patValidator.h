#ifndef patValidator_H
#define patValidator_H

#include <memory>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"

// Generation
#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/GenRunInfoProduct.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"


// Utils
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "RecoVertex/VertexPrimitives/interface/TransientVertex.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "TrackPropagation/SteppingHelixPropagator/interface/SteppingHelixPropagator.h"
#include "TrackPropagation/SteppingHelixPropagator/interface/SteppingHelixStateInfo.h"
#include "MagneticField/Engine/interface/MagneticField.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "Geometry/CommonDetUnit/interface/GlobalTrackingGeometry.h"
#include "Geometry/Records/interface/GlobalTrackingGeometryRecord.h"
#include "TrackingTools/Records/interface/TrackingComponentsRecord.h"

#include "TrackingTools/TrajectoryState/interface/TrajectoryStateOnSurface.h"
#include "TrackingTools/GeomPropagators/interface/AnalyticalTrajectoryExtrapolatorToLine.h"
#include "TrackingTools/GeomPropagators/interface/AnalyticalImpactPointExtrapolator.h"
#include "DataFormats/GeometryCommonDetAlgo/interface/Measurement1D.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TrackingTools/IPTools/interface/IPTools.h"

// DisplacedGlobal handling
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

#include "DataFormats/Math/interface/deltaR.h"

// Tools
#include "CommonTools/Utils/interface/StringCutObjectSelector.h"

// STDLIB
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

// ROOT
#include "TLorentzVector.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"


class patValidator : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit patValidator(const edm::ParameterSet&);
      ~patValidator();
      edm::ConsumesCollector iC = consumesCollector();
      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      edm::ParameterSet parameters;
      std::string output_filename;

      //
      // --- Tokens and Handles
      //

      // Displaced muons
      edm::EDGetTokenT<edm::View<pat::Muon> > DisplacedToken_;
      edm::Handle<edm::View<pat::Muon> > DisplacedCollection_;

      //
      // --- Variables used
      //

      // Event info
      Int_t eventId = 0;
      Int_t luminosityBlock = 0;
      Int_t run = 0;

      // Histograms definition

      // general
      TH1F *h_mu_numberOfChambers;
      TH1F *h_mu_numberOfChambersCSCorDT;
      TH1F *h_mu_numberOfMatches;
      TH1F *h_mu_numberOfMatchedStations;
      TH1F *h_mu_numberOfMatchedRPCLayers;
      TH1F *h_mu_nDigisInStation;
      TH1F *h_mu_numberOfShowers;
      TH1F *h_dtr_numberOfChambers;
      TH1F *h_dtr_numberOfChambersCSCorDT;
      TH1F *h_dtr_numberOfMatches;
      TH1F *h_dtr_numberOfMatchedStations;
      TH1F *h_dtr_numberOfMatchedRPCLayers;
      TH1F *h_dtr_nDigisInStation;
      TH1F *h_dtr_numberOfShowers;
      TH1F *h_dgl_numberOfChambers;
      TH1F *h_dgl_numberOfChambersCSCorDT;
      TH1F *h_dgl_numberOfMatches;
      TH1F *h_dgl_numberOfMatchedStations;
      TH1F *h_dgl_numberOfMatchedRPCLayers;
      TH1F *h_dgl_nDigisInStation;
      TH1F *h_dgl_numberOfShowers;
      TH1F *h_dsa_numberOfChambers;
      TH1F *h_dsa_numberOfChambersCSCorDT;
      TH1F *h_dsa_numberOfMatches;
      TH1F *h_dsa_numberOfMatchedStations;
      TH1F *h_dsa_numberOfMatchedRPCLayers;
      TH1F *h_dsa_nDigisInStation;
      TH1F *h_dsa_numberOfShowers;
      TH1F *h_mu_type;
      TH1F *h_mu_numberOfSegments;

      // muon kinematics
      TH1F *h_mu_pt; 
      TH1F *h_dtr_pt; 
      TH1F *h_dgl_pt; 
      TH1F *h_dsa_pt; 
      TH1F *h_mu_eta; 
      TH1F *h_dtr_eta; 
      TH1F *h_dgl_eta; 
      TH1F *h_dsa_eta; 
      TH1F *h_mu_phi; 
      TH1F *h_dtr_phi; 
      TH1F *h_dgl_phi; 
      TH1F *h_dsa_phi; 

      // time
      TH1F *h_mu_time;
      TH1F *h_mu_timeErr;
      TH1F *h_dtr_time;
      TH1F *h_dtr_timeErr;
      TH1F *h_dgl_time;
      TH1F *h_dgl_timeErr;
      TH1F *h_dsa_time;
      TH1F *h_dsa_timeErr;

      // tracks
      TH1F *h_inn_dxy;
      TH1F *h_glb_dxy;
      TH1F *h_out_dxy;
      TH1F *h_inn_dxyErr;
      TH1F *h_glb_dxyErr;
      TH1F *h_out_dxyErr;
      TH1F *h_inn_dz;
      TH1F *h_glb_dz;
      TH1F *h_out_dz;
      TH1F *h_inn_dzErr;
      TH1F *h_glb_dzErr;
      TH1F *h_out_dzErr;
      TH1F *h_inn_normalizedChi2;
      TH1F *h_glb_normalizedChi2;
      TH1F *h_out_normalizedChi2;

      // hits
      TH1F *h_inn_numberOfValidHits;
      TH1F *h_inn_numberOfValidPixelHits;
      TH1F *h_inn_numberOfValidStripHits;
      TH1F *h_inn_numberOfValidMuonDTHits;
      TH1F *h_inn_numberOfValidMuonCSCHits;
      TH1F *h_inn_numberOfValidMuonRPCHits;
      TH1F *h_glb_numberOfValidHits;
      TH1F *h_glb_numberOfValidPixelHits;
      TH1F *h_glb_numberOfValidStripHits;
      TH1F *h_glb_numberOfValidMuonDTHits;
      TH1F *h_glb_numberOfValidMuonCSCHits;
      TH1F *h_glb_numberOfValidMuonRPCHits;
      TH1F *h_out_numberOfValidHits;
      TH1F *h_out_numberOfValidPixelHits;
      TH1F *h_out_numberOfValidStripHits;
      TH1F *h_out_numberOfValidMuonDTHits;
      TH1F *h_out_numberOfValidMuonCSCHits;
      TH1F *h_out_numberOfValidMuonRPCHits;

      // PF Isolation
      TH1F *h_isoR03_sumPt;
      TH1F *h_isoR03_emEt;
      TH1F *h_isoR03_hadEt;
      TH1F *h_isoR03_hoEt;
      TH1F *h_isoR03_nTracks;
      TH1F *h_isoR03_nJets;
      TH1F *h_isoR03_trackerVetoPt;
      TH1F *h_isoR03_emVetoEt;
      TH1F *h_isoR03_hadVetoEt;
      TH1F *h_isoR03_hoVetoEt;
      TH1F *h_isoR05_sumPt;
      TH1F *h_isoR05_emEt;
      TH1F *h_isoR05_hadEt;
      TH1F *h_isoR05_hoEt;
      TH1F *h_isoR05_nTracks;
      TH1F *h_isoR05_nJets;
      TH1F *h_isoR05_trackerVetoPt;
      TH1F *h_isoR05_emVetoEt;
      TH1F *h_isoR05_hadVetoEt;
      TH1F *h_isoR05_hoVetoEt;
      TH1F *h_pfIsoR03_sumChargedHadronPt;
      TH1F *h_pfIsoR03_sumNeutralHadronEt;
      TH1F *h_pfIsoR03_sumPhotonEt;
      TH1F *h_pfIsoR03_sumNeutralHadronEtHighThreshold;
      TH1F *h_pfIsoR03_sumPhotonEtHighThreshold;
      TH1F *h_pfIsoR03_sumPUPt;
      TH1F *h_pfIsoR04_sumChargedHadronPt;
      TH1F *h_pfIsoR04_sumNeutralHadronEt;
      TH1F *h_pfIsoR04_sumPhotonEt;
      TH1F *h_pfIsoR04_sumNeutralHadronEtHighThreshold;
      TH1F *h_pfIsoR04_sumPhotonEtHighThreshold;
      TH1F *h_pfIsoR04_sumPUPt;


      // Output definition
      TFile *file_out;

};

#endif






