#ifndef validator_H
#define validator_H

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
#include "DataFormats/VertexReco/interface/Vertex.h"
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
#include "TrackingTools/IPTools/interface/IPTools.h"

// DisplacedGlobal handling
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

#include "DataFormats/Math/interface/deltaR.h"

// Jets
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/PatCandidates/interface/Jet.h"


// STDLIB
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// ROOT
#include "TLorentzVector.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"


class validator : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit validator(const edm::ParameterSet&);
      ~validator();
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

      // Generated particles
      edm::EDGetTokenT<edm::View<reco::GenParticle> > GenToken_;
      edm::Handle<edm::View<reco::GenParticle> > GenCollection_;

      // Prompt muons
      edm::EDGetTokenT<edm::View<reco::Muon> > MuonToken_;
      edm::Handle<edm::View<reco::Muon> > MuonCollection_;

      // Displaced muons
      edm::EDGetTokenT<edm::View<reco::Muon> > DisplacedToken_;
      edm::Handle<edm::View<reco::Muon> > DisplacedCollection_;

      // Displaced Tracks
      edm::EDGetTokenT<edm::View<reco::Track> > DisplacedTrackToken_;
      edm::Handle<edm::View<reco::Track> > DisplacedTrackCollection_;

      // Displaced Global Muons
      edm::EDGetTokenT<edm::View<reco::Track> > DisplacedGlobalToken_;
      edm::Handle<edm::View<reco::Track> > DisplacedGlobalCollection_;

      // Displaced Global Muons
      edm::EDGetTokenT<edm::View<reco::Track> > DisplacedStandaloneToken_;
      edm::Handle<edm::View<reco::Track> > DisplacedStandaloneCollection_;


      //
      // --- Variables used
      //

      // Event info
      Int_t eventId = 0;
      Int_t luminosityBlock = 0;
      Int_t run = 0;

      // Histograms definition
      TH1F *h_count_track; 
      TH1F *h_count_muon; 

      TH1F *h_valid_dgl; 
      TH1F *h_pt_inner; 
      TH1F *h_pt_link; 
      TH1F *h_pt_outer; 
      TH1F *h_pt_dtr; 
      TH1F *h_pt_dgl; 
      TH1F *h_pt_dsa; 

      TH1F *h_eta_inner; 
      TH1F *h_eta_link; 
      TH1F *h_eta_outer; 
      TH1F *h_eta_dtr; 
      TH1F *h_eta_dgl; 
      TH1F *h_eta_dsa; 

      // Histograms to check overlap and consistency
      TH1F *h_dmu_degeneration; // degeneration
      TH1F *h_mu_number;        // number of standard muons
      TH1F *h_dmu_number;       // number of displaced muons
      TH1F *h_mu_pt_1;          // pt of leading muon
      TH1F *h_mu_dpt_1;         // pt of leading displaced muon
      TH1F *h_mu_pt_2;          // pt of subleading muon
      TH1F *h_mu_dpt_2;         // pt of subleading displaced muon
      TH1F *h_ptresponse_1;     // pt response of leading muon
      TH1F *h_ptresponse_2;     // pt response of subleading muon
      TH1F *h_mu_eta_1;          // eta of leading muon
      TH1F *h_mu_deta_1;         // eta of leading displaced muon
      TH1F *h_mu_eta_2;          // eta of subleading muon
      TH1F *h_mu_deta_2;         // eta of subleading displaced muon
      TH1F *h_etaresponse_1;     // eta response of leading muon
      TH1F *h_etaresponse_2;     // eta response of subleading muon
      TH1F *h_mu_phi_1;          // phi of leading muon
      TH1F *h_mu_dphi_1;         // phi of leading displaced muon
      TH1F *h_mu_phi_2;          // phi of subleading muon
      TH1F *h_mu_dphi_2;         // phi of subleading displaced muon
      TH1F *h_phiresponse_1;     // phi response of leading muon
      TH1F *h_phiresponse_2;     // phi response of subleading muon


      // Output definition
      TFile *file_out;

      std::ofstream file_bad_dgls;


};

#endif






