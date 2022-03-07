#include "Analysis/displacedMuons-Validator/src/validator.h"

////////
//////// -- Constructor
////////
validator::validator(const edm::ParameterSet& iConfig)
{

   usesResource("TFileService");

   parameters = iConfig;
   
   // Bin definition
   const unsigned int nBinsEta = 13;
   const double etaBins[nBinsEta+1] = {-2.4, -2.1, -1.6, -1.2, -0.9, -0.3, -0.2, 0.2, 0.3, 0.9, 1.2, 1.6, 2.1, 2.4};

   const unsigned int nBinsAbsEta = 7;
   const double absetaBins[nBinsAbsEta+1] = {0., 0.2, 0.3, 0.9, 1.2, 1.6, 2.1, 2.4};

   const unsigned int nBinsAbsZ = 14;
   const double abszBins[nBinsAbsZ+1] = {0., 10., 20., 30., 40., 50., 60., 70., 80., 90., 100., 125., 150., 200., 250.};

   const unsigned int nBinsZ = 28;
   const double zBins[nBinsZ+1] = {-250., -200., -150., -125., -100., -90., -80., -70., -60., -50., -40., -30., -20., -10., 0., 10., 20., 30., 40., 50., 60., 70., 80., 90., 100., 125., 150., 200., 250.};

   const unsigned int nBinsBool = 2;
   const double boolBins[nBinsBool+1] = {0., 1., 2.};

   h_count_track = new TH1F("h_count_track", ";N of muons of (inner/link/outer) type; Yield", 3, 0, 3);
   h_count_muon = new TH1F("h_count_muon", ";N of muons of (inner/link/outer) type; Yield", 3, 0, 3);

   h_pt_inner = new TH1F("h_pt_inner", ";reco::Track/Muon->pt() (GeV); Yield", 25, 0, 100);
   h_pt_link = new TH1F("h_pt_link", ";reco::Track/Muon->pt() (GeV); Yield", 25, 0, 100);
   h_pt_outer = new TH1F("h_pt_outer", ";reco::Track/Muon->pt() (GeV); Yield", 25, 0, 100);
   h_pt_dtr = new TH1F("h_pt_dtr", ";reco::Track/Muon->pt() (GeV); Yield", 25, 0, 100);
   h_pt_dgl = new TH1F("h_pt_dgl", ";reco::Track/Muon->pt() (GeV); Yield", 25, 0, 100);
   h_pt_dsa = new TH1F("h_pt_dsa", ";reco::Track/Muon->pt() (GeV); Yield", 25, 0, 100);

   /*
   h_eta_inner = new TH1F("h_eta_inner", ";reco::Track/Muon->eta() (GeV); Yield", nBinsEta, etaBins);
   h_eta_link = new TH1F("h_eta_link", ";reco::Track/Muon->eta() (GeV); Yield", nBinsEta, etaBins);
   h_eta_outer = new TH1F("h_eta_outer", ";reco::Track/Muon->eta() (GeV); Yield", nBinsEta, etaBins);
   h_eta_dtr = new TH1F("h_eta_dtr", ";reco::Track/Muon->eta() (GeV); Yield", nBinsEta, etaBins);
   h_eta_dgl = new TH1F("h_eta_dgl", ";reco::Track/Muon->eta() (GeV); Yield", nBinsEta, etaBins);
   h_eta_dsa = new TH1F("h_eta_dsa", ";reco::Track/Muon->eta() (GeV); Yield", nBinsEta, etaBins);
   */
   h_eta_inner = new TH1F("h_eta_inner", ";reco::Track/Muon->eta(); Yield", 20, -4., 4.);
   h_eta_link = new TH1F("h_eta_link", ";reco::Track/Muon->eta(); Yield", 20, -4., 4.);
   h_eta_outer = new TH1F("h_eta_outer", ";reco::Track/Muon->eta(); Yield", 20, -4., 4.);
   h_eta_dtr = new TH1F("h_eta_dtr", ";reco::Track/Muon->eta(); Yield", 20, -4., 4.);
   h_eta_dgl = new TH1F("h_eta_dgl", ";reco::Track/Muon->eta(); Yield", 20, -4., 4.);
   h_eta_dsa = new TH1F("h_eta_dsa", ";reco::Track/Muon->eta(); Yield", 20, -4., 4.);


   h_dmu_degeneration = new TH1F("h_dmu_degeneration", ";Degeneration); N. of gen muons", 4, 0, 4);
   h_mu_number = new TH1F("h_mu_number", ";Number of 'muons'/event; Events", 5, 0, 5);
   h_dmu_number = new TH1F("h_dmu_number", ";Number of dMuons/event; Events", 5, 0, 5);
   h_mu_pt_1 = new TH1F("h_mu_pt_1", ";p_{T} of leading muon; Events", 25, 0, 100); 
   h_mu_dpt_1 = new TH1F("h_mu_dpt_1", ";p_{T} of leading dMuon'; Events", 25, 0, 100); 
   h_mu_pt_2 = new TH1F("h_mu_pt_2", ";p_{T} of subleading muon; Events", 25, 0, 100); 
   h_mu_dpt_2 = new TH1F("h_mu_dpt_2", ";p_{T} of subleading dMuon'; Events", 25, 0, 100); 
   h_ptresponse_1 = new TH1F("h_ptresponse_1", ";p_{T}^{dMuon}/p_{T}^{muon} - 1; Events", 50, -0.05, 0.05); 
   h_ptresponse_2 = new TH1F("h_ptresponse_2", ";p_{T}^{dMuon}/p_{T}^{muon} - 1; Events", 50, -0.05, 0.05); 
   h_mu_eta_1 = new TH1F("h_mu_eta_1", ";p_{T} of leading muon; Events", 30, -3., 3.); 
   h_mu_deta_1 = new TH1F("h_mu_deta_1", ";p_{T} of leading dMuon'; Events", 30, -3., 3.); 
   h_mu_eta_2 = new TH1F("h_mu_eta_2", ";p_{T} of subleading muon; Events", 30, -3., 3.); 
   h_mu_deta_2 = new TH1F("h_mu_deta_2", ";p_{T} of subleading dMuon'; Events", 30, -3., 3.); 
   h_etaresponse_1 = new TH1F("h_etaresponse_1", ";p_{T}^{dMuon}/p_{T}^{muon} - 1; Events", 50, -0.05, 0.05); 
   h_etaresponse_2 = new TH1F("h_etaresponse_2", ";p_{T}^{dMuon}/p_{T}^{muon} - 1; Events", 50, -0.05, 0.05); 
   h_mu_phi_1 = new TH1F("h_mu_phi_1", ";p_{T} of leading muon; Events", 25, -3.14, 3.14); 
   h_mu_dphi_1 = new TH1F("h_mu_dphi_1", ";p_{T} of leading dMuon'; Events", 25, -3.14, 3.14); 
   h_mu_phi_2 = new TH1F("h_mu_phi_2", ";p_{T} of subleading muon; Events", 25, -3.14, 3.14); 
   h_mu_dphi_2 = new TH1F("h_mu_dphi_2", ";p_{T} of subleading dMuon'; Events", 25, -3.14, 3.14); 
   h_phiresponse_1 = new TH1F("h_phiresponse_1", ";p_{T}^{dMuon}/p_{T}^{muon} - 1; Events", 50, -0.05, 0.05); 
   h_phiresponse_2 = new TH1F("h_phiresponse_2", ";p_{T}^{dMuon}/p_{T}^{muon} - 1; Events", 50, -0.05, 0.05); 


   GenToken_ = consumes<edm::View<reco::GenParticle> >  (parameters.getParameter<edm::InputTag>("GenCollection"));
   MuonToken_ = consumes<edm::View<reco::Muon> >  (parameters.getParameter<edm::InputTag>("MuonCollection"));
   DisplacedToken_ = consumes<edm::View<reco::Muon> >  (parameters.getParameter<edm::InputTag>("DisplacedCollection"));
   DisplacedGlobalToken_ = consumes<edm::View<reco::Track> >  (parameters.getParameter<edm::InputTag>("DisplacedGlobalCollection"));
   DisplacedTrackToken_ = consumes<edm::View<reco::Track> >  (parameters.getParameter<edm::InputTag>("DisplacedTrackCollection"));
   DisplacedStandaloneToken_ = consumes<edm::View<reco::Track> >  (parameters.getParameter<edm::InputTag>("DisplacedStandaloneCollection"));

}



////////
//////// -- Destructor
////////
validator::~validator()
{

}

////////
//////// -- BeginJob
////////
void validator::beginJob()
{
  std::cout << "Begin Job" << std::endl;

  output_filename = parameters.getParameter<std::string>("nameOfOutput");
  file_out = new TFile(output_filename.c_str(), "RECREATE");
  file_bad_dgls.open("dgls_loss.txt");

}

////////
//////// -- EndJob
////////
void validator::endJob()
{
  std::cout << "End Job" << std::endl;

  file_out->cd();
  h_count_muon->Write();
  h_count_track->Write();
  h_pt_inner->Write();
  h_pt_link->Write();
  h_pt_outer->Write();
  h_pt_dtr->Write();
  h_pt_dgl->Write();
  h_pt_dsa->Write();
  h_eta_inner->Write();
  h_eta_link->Write();
  h_eta_outer->Write();
  h_eta_dtr->Write();
  h_eta_dgl->Write();
  h_eta_dsa->Write();

  h_dmu_degeneration->Write();
  h_mu_number->Write();
  h_dmu_number->Write();
  h_mu_pt_1->Write();
  h_mu_dpt_1->Write();
  h_mu_pt_2->Write();
  h_mu_dpt_2->Write();
  h_ptresponse_1->Write();
  h_ptresponse_2->Write();
  h_mu_eta_1->Write();
  h_mu_deta_1->Write();
  h_mu_eta_2->Write();
  h_mu_deta_2->Write();
  h_etaresponse_1->Write();
  h_etaresponse_2->Write();
  h_mu_phi_1->Write();
  h_mu_dphi_1->Write();
  h_mu_phi_2->Write();
  h_mu_dphi_2->Write();
  h_phiresponse_1->Write();
  h_phiresponse_2->Write();
  
  

  // here I write histograms
  file_out->Close();

  file_bad_dgls.close();

}


////////
//////// -- fillDescriptions
////////
void validator::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}


////////
//////// -- Analyze
////////
void validator::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

   bool ValidGen = iEvent.getByToken(GenToken_, GenCollection_);
   bool ValidMuons = iEvent.getByToken(MuonToken_, MuonCollection_);
   bool ValidDisplaced = iEvent.getByToken(DisplacedToken_, DisplacedCollection_);

   bool ValidDisplacedTrack = iEvent.getByToken(DisplacedTrackToken_, DisplacedTrackCollection_);
   //if (!ValidDisplacedTrack) { return; }

   iEvent.getByToken(DisplacedGlobalToken_, DisplacedGlobalCollection_);

   bool ValidDisplacedStandalone = iEvent.getByToken(DisplacedStandaloneToken_, DisplacedStandaloneCollection_);
   //if (!ValidDisplacedStandalone) { return; }



   //
   // -- Init the variables
   //

   // -> Event info
   eventId = 0;
   luminosityBlock = 0;
   run = 0;

   //
   // -- Pre-analysis
   //

   // -> Event info
   eventId = iEvent.id().event();
   luminosityBlock = iEvent.id().luminosityBlock();
   run = iEvent.id().run();


   //
   // -- Main analysis
   //
   
   for (const auto& dtr : *DisplacedTrackCollection_)
   {
     h_count_track->Fill(0);
     h_pt_dtr->Fill(dtr.pt());
     h_eta_dtr->Fill(dtr.eta());
   }

   int ndgl = 0;
   for (const auto& dgl : *DisplacedGlobalCollection_)
   {
     h_count_track->Fill(1);
     h_pt_dgl->Fill(dgl.pt());
     h_eta_dgl->Fill(dgl.eta());
     ndgl++;
   }

   for (const auto& dsa : *DisplacedStandaloneCollection_)
   {
     h_count_track->Fill(2);
     h_pt_dsa->Fill(dsa.pt());
     h_eta_dsa->Fill(dsa.eta());
   }

   int nlink = 0;
   for (const auto& mu : *DisplacedCollection_)
   {
     if (mu.isTrackerMuon()) {
       h_count_muon->Fill(0);
       h_pt_inner->Fill(mu.innerTrack()->pt());
       h_eta_inner->Fill(mu.innerTrack()->eta());
     }
     if (mu.isGlobalMuon()) {
       h_count_muon->Fill(1);
       h_pt_link->Fill(mu.globalTrack()->pt());
       h_eta_link->Fill(mu.globalTrack()->eta());
       nlink++;
     }
     if (mu.isStandAloneMuon()) {
       h_count_muon->Fill(2);
       h_pt_outer->Fill(mu.outerTrack()->pt());
       h_eta_outer->Fill(mu.outerTrack()->eta());
     }
   }

   if (nlink < ndgl) {

     file_bad_dgls << "EventId" << "\t" << "pt" << "\t" << "eta" << "\t" << "phi" << "\n";
     std::cout << ">>>>> Loss in dGlobal muons!!!!!" << std::endl;
     for (const auto& dgl : *DisplacedGlobalCollection_) {
       file_bad_dgls << eventId << "\t";
       file_bad_dgls << dgl.pt() << "\t";
       file_bad_dgls << dgl.eta() << "\t";
       file_bad_dgls << dgl.phi() << "\n";
     }
   }


   // Study overlap with muon collections
   //
   std::vector<reco::Muon> muons;
   for (const auto& mu : *MuonCollection_)
   {
     muons.push_back(mu);
   }
   std::sort(muons.begin(), muons.end(), [&](auto a, auto b){return a.pt() > b.pt(); });

   std::vector<reco::Muon> dMuons;
   for (const auto& dmu : *DisplacedCollection_)
   {
     dMuons.push_back(dmu);
   }
   std::sort(dMuons.begin(), dMuons.end(), [&](auto a, auto b){return a.pt() > b.pt(); });

   h_mu_number->Fill(muons.size());
   h_dmu_number->Fill(dMuons.size());

   if (muons.size() > 1 && dMuons.size() > 1){
     h_mu_pt_1->Fill(muons.at(0).pt());
     h_mu_pt_2->Fill(muons.at(1).pt());
     h_mu_eta_1->Fill(muons.at(0).eta());
     h_mu_eta_2->Fill(muons.at(1).eta());
     h_mu_phi_1->Fill(muons.at(0).phi());
     h_mu_phi_2->Fill(muons.at(1).phi());
   }
   if (dMuons.size() > 1 && muons.size() > 1){
     h_mu_dpt_1->Fill(dMuons.at(0).pt());
     h_mu_dpt_2->Fill(dMuons.at(1).pt());
     h_mu_deta_1->Fill(dMuons.at(0).eta());
     h_mu_deta_2->Fill(dMuons.at(1).eta());
     h_mu_dphi_1->Fill(dMuons.at(0).phi());
     h_mu_dphi_2->Fill(dMuons.at(1).phi());
   }

   if (muons.size() > 1 && dMuons.size() > 1){
     h_ptresponse_1->Fill(muons.at(0).pt()/dMuons.at(0).pt() - 1);
     h_ptresponse_2->Fill(muons.at(1).pt()/dMuons.at(1).pt() - 1);
     h_etaresponse_1->Fill(muons.at(0).eta()/dMuons.at(0).eta() - 1);
     h_etaresponse_2->Fill(muons.at(1).eta()/dMuons.at(1).eta() - 1);
     h_phiresponse_1->Fill(muons.at(0).phi()/dMuons.at(0).phi() - 1);
     h_phiresponse_2->Fill(muons.at(1).phi()/dMuons.at(1).phi() - 1);
   }


   /*
   // Study the degeneration for generated muons
   for (const auto& gen : *GenCollection_)
   {
   }
   */



}


