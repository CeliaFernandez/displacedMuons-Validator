#include "Analysis/displacedMuons-Validator/src/patValidator.h"

////////
//////// -- Constructor
////////
patValidator::patValidator(const edm::ParameterSet& iConfig)
{

   usesResource("TFileService");

   parameters = iConfig;
   
   // Bin definition
   const unsigned int nBinsEta = 13;
   const double etaBins[nBinsEta+1] = {-2.4, -2.1, -1.6, -1.2, -0.9, -0.3, -0.2, 0.2, 0.3, 0.9, 1.2, 1.6, 2.1, 2.4};

   const unsigned int nBinsAbsEta = 7;
   const double absetaBins[nBinsAbsEta+1] = {0., 0.2, 0.3, 0.9, 1.2, 1.6, 2.1, 2.4};

   const unsigned int nBinsDxy = 20;
   const double dxyBins[nBinsDxy+1] = {-80., -70., -60., -50., -40., -30., -20., -10., -5., -2., 0., 2., 5., 10., 20., 30., 40., 50., 60., 70., 80.};

   const unsigned int nBinsDz = 28;
   const double dzBins[nBinsDz+1] = {-200., -150., -130., -110., -90., -80., -70., -60., -50., -40., -30., -20., -10., -5., 0., 5., 10., 20., 30., 40., 50., 60., 70., 80., 90., 110., 130., 150., 200.};

   const unsigned int nBinsAbsZ = 14;
   const double abszBins[nBinsAbsZ+1] = {0., 10., 20., 30., 40., 50., 60., 70., 80., 90., 100., 125., 150., 200., 250.};

   const unsigned int nBinsZ = 28;
   const double zBins[nBinsZ+1] = {-250., -200., -150., -125., -100., -90., -80., -70., -60., -50., -40., -30., -20., -10., 0., 10., 20., 30., 40., 50., 60., 70., 80., 90., 100., 125., 150., 200., 250.};

   const unsigned int nBinsBool = 2;
   const double boolBins[nBinsBool+1] = {0., 1., 2.};

   // general
   h_mu_numberOfChambers = new TH1F("h_mu_numberOfChambers", ";muon->numberOfChambers();", 25, 0, 25);
   h_mu_numberOfChambersCSCorDT = new TH1F("h_mu_numberOfChambersCSCorDT", ";muon->numberOfChambersCSCorDT();", 25, 0, 25);
   h_mu_numberOfMatches = new TH1F("h_mu_numberOfMatches", ";muon->numberOfMatches();", 9, 0, 9);
   h_mu_numberOfMatchedStations = new TH1F("h_mu_numberOfMatchedStations", ";muon->numberOfMatchedStations();", 6, 0, 6);
   h_mu_numberOfMatchedRPCLayers = new TH1F("h_mu_numberOfMatchedRPCLayers", ";muon->numberOfMatchedRPCLayers();", 10, 0, 10);
   h_mu_nDigisInStation = new TH1F("h_mu_nDigisInStation", ";muon->nDigisInStation();", 7, 0, 7);
   h_mu_numberOfShowers = new TH1F("h_mu_numberOfShowers", ";muon->numberOfShowers();", 4, 0, 4);
   h_dtr_numberOfChambers = new TH1F("h_dtr_numberOfChambers", ";muon->numberOfChambers();", 25, 0, 25);
   h_dtr_numberOfChambersCSCorDT = new TH1F("h_dtr_numberOfChambersCSCorDT", ";muon->numberOfChambersCSCorDT();", 25, 0, 25);
   h_dtr_numberOfMatches = new TH1F("h_dtr_numberOfMatches", ";muon->numberOfMatches();", 9, 0, 9);
   h_dtr_numberOfMatchedStations = new TH1F("h_dtr_numberOfMatchedStations", ";muon->numberOfMatchedStations();", 6, 0, 6);
   h_dtr_numberOfMatchedRPCLayers = new TH1F("h_dtr_numberOfMatchedRPCLayers", ";muon->numberOfMatchedRPCLayers();", 10, 0, 10);
   h_dtr_nDigisInStation = new TH1F("h_dtr_nDigisInStation", ";muon->nDigisInStation();", 7, 0, 7);
   h_dtr_numberOfShowers = new TH1F("h_dtr_numberOfShowers", ";muon->numberOfShowers();", 4, 0, 4);
   h_dgl_numberOfChambers = new TH1F("h_dgl_numberOfChambers", ";muon->numberOfChambers();", 25, 0, 25);
   h_dgl_numberOfChambersCSCorDT = new TH1F("h_dgl_numberOfChambersCSCorDT", ";muon->numberOfChambersCSCorDT();", 25, 0, 25);
   h_dgl_numberOfMatches = new TH1F("h_dgl_numberOfMatches", ";muon->numberOfMatches();", 9, 0, 9);
   h_dgl_numberOfMatchedStations = new TH1F("h_dgl_numberOfMatchedStations", ";muon->numberOfMatchedStations();", 6, 0, 6);
   h_dgl_numberOfMatchedRPCLayers = new TH1F("h_dgl_numberOfMatchedRPCLayers", ";muon->numberOfMatchedRPCLayers();", 10, 0, 10);
   h_dgl_nDigisInStation = new TH1F("h_dgl_nDigisInStation", ";muon->nDigisInStation();", 7, 0, 7);
   h_dgl_numberOfShowers = new TH1F("h_dgl_numberOfShowers", ";muon->numberOfShowers();", 4, 0, 4);
   h_dsa_numberOfChambers = new TH1F("h_dsa_numberOfChambers", ";muon->numberOfChambers();", 25, 0, 25);
   h_dsa_numberOfChambersCSCorDT = new TH1F("h_dsa_numberOfChambersCSCorDT", ";muon->numberOfChambersCSCorDT();", 25, 0, 25);
   h_dsa_numberOfMatches = new TH1F("h_dsa_numberOfMatches", ";muon->numberOfMatches();", 9, 0, 9);
   h_dsa_numberOfMatchedStations = new TH1F("h_dsa_numberOfMatchedStations", ";muon->numberOfMatchedStations();", 6, 0, 6);
   h_dsa_numberOfMatchedRPCLayers = new TH1F("h_dsa_numberOfMatchedRPCLayers", ";muon->numberOfMatchedRPCLayers();", 10, 0, 10);
   h_dsa_nDigisInStation = new TH1F("h_dsa_nDigisInStation", ";muon->nDigisInStation();", 7, 0, 7);
   h_dsa_numberOfShowers = new TH1F("h_dsa_numberOfShowers", ";muon->numberOfShowers();", 4, 0, 4);

   h_mu_type = new TH1F("h_mu_type", ";muon->type();", 9, 0, 9);
   h_mu_numberOfSegments = new TH1F("h_mu_numberOfSegments", ";muon->numberOfSegments();", 20, 0, 20);

   // muon kinematics
   h_mu_pt = new TH1F("h_mu_pt", ";muon->pt();", 80, 0, 120);
   h_dtr_pt = new TH1F("h_dtr_pt", ";muon->pt();", 80, 0, 120);
   h_dgl_pt = new TH1F("h_dgl_pt", ";muon->pt();", 80, 0, 120);
   h_dsa_pt = new TH1F("h_dsa_pt", ";muon->pt();", 80, 0, 120);
   h_mu_eta = new TH1F("h_mu_eta", ";muon->eta();", nBinsEta, etaBins);
   h_dtr_eta = new TH1F("h_dtr_eta", ";muon->eta();", nBinsEta, etaBins);
   h_dgl_eta = new TH1F("h_dgl_eta", ";muon->eta();", nBinsEta, etaBins);
   h_dsa_eta = new TH1F("h_dsa_eta", ";muon->eta();", nBinsEta, etaBins);
   h_mu_phi = new TH1F("h_mu_phi", ";muon->phi();", 30, -3.14, 3.14);
   h_dtr_phi = new TH1F("h_dtr_phi", ";muon->phi();", 30, -3.14, 3.14);
   h_dgl_phi = new TH1F("h_dgl_phi", ";muon->phi();", 30, -3.14, 3.14);
   h_dsa_phi = new TH1F("h_dsa_phi", ";muon->phi();", 30, -3.14, 3.14);
   // time
   h_mu_time = new TH1F("h_mu_time", ";muon->time().timeAtIpInOut;", 40, -40, 20); 
   h_mu_timeErr = new TH1F("h_mu_timeErr", ";muon->time().timeAtIpInOutErr;", 30, 0, 5); 
   h_dtr_time = new TH1F("h_dtr_time", ";muon->time().timeAtIpInOut;", 40, -40, 20); 
   h_dtr_timeErr = new TH1F("h_dtr_timeErr", ";muon->time().timeAtIpInOutErr;", 30, 0, 5); 
   h_dgl_time = new TH1F("h_dgl_time", ";muon->time().timeAtIpInOut;", 40, -40, 20); 
   h_dgl_timeErr = new TH1F("h_dgl_timeErr", ";muon->time().timeAtIpInOutErr;", 30, 0, 5); 
   h_dsa_time = new TH1F("h_dsa_time", ";muon->time().timeAtIpInOut;", 40, -40, 20); 
   h_dsa_timeErr = new TH1F("h_dsa_timeErr", ";muon->time().timeAtIpInOutErr;", 30, 0, 5); 
   // tracks
   h_inn_dxy = new TH1F("h_inn_dxy", ";track()->dxy();", nBinsDxy, dxyBins);
   h_glb_dxy = new TH1F("h_glb_dxy", ";track()->dxy();", nBinsDxy, dxyBins);
   h_out_dxy = new TH1F("h_out_dxy", ";track()->dxy();", nBinsDxy, dxyBins);
   h_inn_dxyErr = new TH1F("h_inn_dxyErr", ";track()->dxyError();", 50, 0, 10);
   h_glb_dxyErr = new TH1F("h_glb_dxyErr", ";track()->dxyError();", 50, 0, 10);
   h_out_dxyErr = new TH1F("h_out_dxyErr", ";track()->dxyError();", 50, 0, 10);
   h_inn_dz = new TH1F("h_inn_dz", ";track()->dz();", nBinsDz, dzBins);
   h_glb_dz = new TH1F("h_glb_dz", ";track()->dz();", nBinsDz, dzBins);
   h_out_dz = new TH1F("h_out_dz", ";track()->dz();", nBinsDz, dzBins);
   h_inn_dzErr = new TH1F("h_inn_dzErr", ";track()->dzError();", 50, 0, 10);
   h_glb_dzErr = new TH1F("h_glb_dzErr", ";track()->dzError();", 50, 0, 10);
   h_out_dzErr = new TH1F("h_out_dzErr", ";track()->dzError();", 50, 0, 10);
   h_inn_normalizedChi2 = new TH1F("h_inn_normalizedChi2", ";track()->normalizedChi2();", 20, 0, 10);
   h_glb_normalizedChi2 = new TH1F("h_glb_normalizedChi2", ";track()->normalizedChi2();", 20, 0, 10);
   h_out_normalizedChi2 = new TH1F("h_out_normalizedChi2", ";track()->normalizedChi2();", 20, 0, 10);

   h_inn_numberOfValidHits = new TH1F("h_inn_numberOfValidHits", ";track()->hitPattern().numberOfValidHits();", 80, 0, 80);
   h_inn_numberOfValidPixelHits = new TH1F("h_inn_numberOfValidPixelHits", ";track()->hitPattern().numberOfValidPixelHits();", 10, 0, 10);
   h_inn_numberOfValidStripHits = new TH1F("h_inn_numberOfValidStripHits", ";track()->hitPattern().numberOfValidStripHits();", 30, 0, 30);
   h_inn_numberOfValidMuonDTHits = new TH1F("h_inn_numberOfValidMuonDTHits", ";track()->hitPattern().numberOfValidMuonDTHits();", 50, 0, 50);
   h_inn_numberOfValidMuonCSCHits = new TH1F("h_inn_numberOfValidMuonCSCHits", ";track()->hitPattern().numberOfValidMuonCSCHits();", 30, 0, 30);
   h_inn_numberOfValidMuonRPCHits = new TH1F("h_inn_numberOfValidMuonRPCHits", ";track()->hitPattern().numberOfValidMuonRPCHits();", 10, 0, 10);
   h_glb_numberOfValidHits = new TH1F("h_glb_numberOfValidHits", ";track()->hitPattern().numberOfValidHits();", 80, 0, 80);
   h_glb_numberOfValidPixelHits = new TH1F("h_glb_numberOfValidPixelHits", ";track()->hitPattern().numberOfValidPixelHits();", 10, 0, 10);
   h_glb_numberOfValidStripHits = new TH1F("h_glb_numberOfValidStripHits", ";track()->hitPattern().numberOfValidStripHits();", 30, 0, 30);
   h_glb_numberOfValidMuonDTHits = new TH1F("h_glb_numberOfValidMuonDTHits", ";track()->hitPattern().numberOfValidMuonDTHits();", 50, 0, 50);
   h_glb_numberOfValidMuonCSCHits = new TH1F("h_glb_numberOfValidMuonCSCHits", ";track()->hitPattern().numberOfValidMuonCSCHits();", 30, 0, 30);
   h_glb_numberOfValidMuonRPCHits = new TH1F("h_glb_numberOfValidMuonRPCHits", ";track()->hitPattern().numberOfValidMuonRPCHits();", 10, 0, 10);
   h_out_numberOfValidHits = new TH1F("h_out_numberOfValidHits", ";track()->hitPattern().numberOfValidHits();", 80, 0, 80);
   h_out_numberOfValidPixelHits = new TH1F("h_out_numberOfValidPixelHits", ";track()->hitPattern().numberOfValidPixelHits();", 10, 0, 10);
   h_out_numberOfValidStripHits = new TH1F("h_out_numberOfValidStripHits", ";track()->hitPattern().numberOfValidStripHits();", 30, 0, 30);
   h_out_numberOfValidMuonDTHits = new TH1F("h_out_numberOfValidMuonDTHits", ";track()->hitPattern().numberOfValidMuonDTHits();", 50, 0, 50);
   h_out_numberOfValidMuonCSCHits = new TH1F("h_out_numberOfValidMuonCSCHits", ";track()->hitPattern().numberOfValidMuonCSCHits();", 30, 0, 30);
   h_out_numberOfValidMuonRPCHits = new TH1F("h_out_numberOfValidMuonRPCHits", ";track()->hitPattern().numberOfValidMuonRPCHits();", 10, 0, 10);

   h_isoR03_sumPt = new TH1F("h_isoR03_sumPt", ";muon->isolationR03().sumPt;", 20, 0, 20);
   h_isoR03_emEt = new TH1F("h_isoR03_emEt", ";muon->isolationR03().emEt;", 20, 0, 20);
   h_isoR03_hadEt = new TH1F("h_isoR03_hadEt", ";muon->isolationR03().hadEt;", 20, 0, 20);
   h_isoR03_hoEt = new TH1F("h_isoR03_hoEt", ";muon->isolationR03().hoEt;", 20, 0, 20);
   h_isoR03_nTracks = new TH1F("h_isoR03_nTracks", ";muon->isolationR03().nTracks;", 20, 0, 20);
   h_isoR03_nJets = new TH1F("h_isoR03_nJets", ";muon->isolationR03().nJets;", 20, 0, 20);
   h_isoR03_trackerVetoPt = new TH1F("h_isoR03_trackerVetoPt", ";muon->isolationR03().trackerVetoPt;", 40, 0, 100);
   h_isoR03_emVetoEt = new TH1F("h_isoR03_emVetoEt", ";muon->isolationR03().emVetoEt;", 20, 0, 20);
   h_isoR03_hadVetoEt = new TH1F("h_isoR03_hadVetoEt", ";muon->isolationR03().hadVetoEt;", 20, 0, 20);
   h_isoR03_hoVetoEt = new TH1F("h_isoR03_hoVetoEt", ";muon->isolationR03().hoVetoEt;", 20, 0, 20);
   h_isoR05_sumPt = new TH1F("h_isoR05_sumPt", ";muon->isolationR05().sumPt;", 20, 0, 20);
   h_isoR05_emEt = new TH1F("h_isoR05_emEt", ";muon->isolationR05().emEt;", 20, 0, 20);
   h_isoR05_hadEt = new TH1F("h_isoR05_hadEt", ";muon->isolationR05().hadEt;", 20, 0, 20);
   h_isoR05_hoEt = new TH1F("h_isoR05_hoEt", ";muon->isolationR05().hoEt;", 20, 0, 20);
   h_isoR05_nTracks = new TH1F("h_isoR05_nTracks", ";muon->isolationR05().nTracks;", 20, 0, 20);
   h_isoR05_nJets = new TH1F("h_isoR05_nJets", ";muon->isolationR05().nJets;", 20, 0, 20);
   h_isoR05_trackerVetoPt = new TH1F("h_isoR05_trackerVetoPt", ";muon->isolationR05().trackerVetoPt;", 40, 0, 100);
   h_isoR05_emVetoEt = new TH1F("h_isoR05_emVetoEt", ";muon->isolationR05().emVetoEt;", 20, 0, 20);
   h_isoR05_hadVetoEt = new TH1F("h_isoR05_hadVetoEt", ";muon->isolationR05().hadVetoEt;", 20, 0, 20);
   h_isoR05_hoVetoEt = new TH1F("h_isoR05_hoVetoEt", ";muon->isolationR05().hoVetoEt;", 20, 0, 20);

   h_pfIsoR03_sumChargedHadronPt = new TH1F("h_pfIsoR03_sumChargedHadronPt", ";muon->pfIsolationR03().sumChargedHadronPt;", 20, 0, 20);
   h_pfIsoR03_sumNeutralHadronEt = new TH1F("h_pfIsoR03_sumNeutralHadronEt", ";muon->pfIsolationR03().sumNeutralHadronEt;", 20, 0, 20);
   h_pfIsoR03_sumPhotonEt = new TH1F("h_pfIsoR03_sumPhotonEt", ";muon->pfIsolationR03().sumPhotonEt;", 20, 0, 20);
   h_pfIsoR03_sumNeutralHadronEtHighThreshold = new TH1F("h_pfIsoR03_sumNeutralHadronEtHighThreshold", ";muon->pfIsolationR03().sumNeutralHadronEtHighThreshold;", 20, 0, 20);
   h_pfIsoR03_sumPhotonEtHighThreshold = new TH1F("h_pfIsoR03_sumPhotonEtHighThreshold", ";muon->pfIsolationR03().sumPhotonEtHighThreshold;", 20, 0, 20);
   h_pfIsoR03_sumPUPt = new TH1F("h_pfIsoR03_sumPUPt", ";muon->pfIsolationR03().sumPUPt;", 20, 0, 20);

   h_pfIsoR04_sumChargedHadronPt = new TH1F("h_pfIsoR04_sumChargedHadronPt", ";muon->pfIsolationR04().sumChargedHadronPt;", 20, 0, 20);
   h_pfIsoR04_sumNeutralHadronEt = new TH1F("h_pfIsoR04_sumNeutralHadronEt", ";muon->pfIsolationR04().sumNeutralHadronEt;", 20, 0, 20);
   h_pfIsoR04_sumPhotonEt = new TH1F("h_pfIsoR04_sumPhotonEt", ";muon->pfIsolationR04().sumPhotonEt;", 20, 0, 20);
   h_pfIsoR04_sumNeutralHadronEtHighThreshold = new TH1F("h_pfIsoR04_sumNeutralHadronEtHighThreshold", ";muon->pfIsolationR04().sumNeutralHadronEtHighThreshold;", 20, 0, 20);
   h_pfIsoR04_sumPhotonEtHighThreshold = new TH1F("h_pfIsoR04_sumPhotonEtHighThreshold", ";muon->pfIsolationR04().sumPhotonEtHighThreshold;", 20, 0, 20);
   h_pfIsoR04_sumPUPt = new TH1F("h_pfIsoR04_sumPUPt", ";muon->pfIsolationR04().sumPUPt;", 20, 0, 20);

   DisplacedToken_ = consumes<edm::View<pat::Muon> >  (parameters.getParameter<edm::InputTag>("DisplacedCollection"));

}



////////
//////// -- Destructor
////////
patValidator::~patValidator()
{

}

////////
//////// -- BeginJob
////////
void patValidator::beginJob()
{
  std::cout << "Begin Job" << std::endl;

  output_filename = parameters.getParameter<std::string>("nameOfOutput");
  file_out = new TFile(output_filename.c_str(), "RECREATE");

}

////////
//////// -- EndJob
////////
void patValidator::endJob()
{
  std::cout << "End Job" << std::endl;

  file_out->cd();

  h_mu_numberOfChambers->Write();
  h_mu_numberOfChambersCSCorDT->Write();
  h_mu_numberOfMatches->Write();
  h_mu_numberOfMatchedStations->Write();
  h_mu_numberOfMatchedRPCLayers->Write();
  h_mu_nDigisInStation->Write();
  h_mu_numberOfShowers->Write();
  h_dtr_numberOfChambers->Write();
  h_dtr_numberOfChambersCSCorDT->Write();
  h_dtr_numberOfMatches->Write();
  h_dtr_numberOfMatchedStations->Write();
  h_dtr_numberOfMatchedRPCLayers->Write();
  h_dtr_nDigisInStation->Write();
  h_dtr_numberOfShowers->Write();
  h_dgl_numberOfChambers->Write();
  h_dgl_numberOfChambersCSCorDT->Write();
  h_dgl_numberOfMatches->Write();
  h_dgl_numberOfMatchedStations->Write();
  h_dgl_numberOfMatchedRPCLayers->Write();
  h_dgl_nDigisInStation->Write();
  h_dgl_numberOfShowers->Write();
  h_dsa_numberOfChambers->Write();
  h_dsa_numberOfChambersCSCorDT->Write();
  h_dsa_numberOfMatches->Write();
  h_dsa_numberOfMatchedStations->Write();
  h_dsa_numberOfMatchedRPCLayers->Write();
  h_dsa_nDigisInStation->Write();
  h_dsa_numberOfShowers->Write();
  h_mu_type->Write();
  h_mu_numberOfSegments->Write();

  h_mu_pt->Write();
  h_dtr_pt->Write();
  h_dgl_pt->Write();
  h_dsa_pt->Write();
  h_mu_eta->Write();
  h_dtr_eta->Write();
  h_dgl_eta->Write();
  h_dsa_eta->Write();
  h_mu_phi->Write();
  h_dtr_phi->Write();
  h_dgl_phi->Write();
  h_dsa_phi->Write();

  h_mu_time->Write();
  h_mu_timeErr->Write();
  h_dtr_time->Write();
  h_dtr_timeErr->Write();
  h_dgl_time->Write();
  h_dgl_timeErr->Write();
  h_dsa_time->Write();
  h_dsa_timeErr->Write();

  h_inn_dxy->Write();
  h_inn_dxyErr->Write();
  h_inn_dz->Write();
  h_inn_dzErr->Write();
  h_inn_normalizedChi2->Write();
  h_glb_dxy->Write();
  h_glb_dxyErr->Write();
  h_glb_dz->Write();
  h_glb_dzErr->Write();
  h_glb_normalizedChi2->Write();
  h_out_dxy->Write();
  h_out_dxyErr->Write();
  h_out_dz->Write();
  h_out_dzErr->Write();
  h_out_normalizedChi2->Write();

  h_inn_numberOfValidHits->Write();
  h_inn_numberOfValidPixelHits->Write();
  h_inn_numberOfValidStripHits->Write();
  h_inn_numberOfValidMuonDTHits->Write();
  h_inn_numberOfValidMuonCSCHits->Write();
  h_inn_numberOfValidMuonRPCHits->Write();
  h_glb_numberOfValidHits->Write();
  h_glb_numberOfValidPixelHits->Write();
  h_glb_numberOfValidStripHits->Write();
  h_glb_numberOfValidMuonDTHits->Write();
  h_glb_numberOfValidMuonCSCHits->Write();
  h_glb_numberOfValidMuonRPCHits->Write();
  h_out_numberOfValidHits->Write();
  h_out_numberOfValidPixelHits->Write();
  h_out_numberOfValidStripHits->Write();
  h_out_numberOfValidMuonDTHits->Write();
  h_out_numberOfValidMuonCSCHits->Write();
  h_out_numberOfValidMuonRPCHits->Write();
  
  h_isoR03_sumPt->Write();
  h_isoR03_emEt->Write();
  h_isoR03_hadEt->Write();
  h_isoR03_hoEt->Write();
  h_isoR03_nTracks->Write();
  h_isoR03_nJets->Write();
  h_isoR03_trackerVetoPt->Write();
  h_isoR03_emVetoEt->Write();
  h_isoR03_hadVetoEt->Write();
  h_isoR03_hoVetoEt->Write();
  h_isoR05_sumPt->Write();
  h_isoR05_emEt->Write();
  h_isoR05_hadEt->Write();
  h_isoR05_hoEt->Write();
  h_isoR05_nTracks->Write();
  h_isoR05_nJets->Write();
  h_isoR05_trackerVetoPt->Write();
  h_isoR05_emVetoEt->Write();
  h_isoR05_hadVetoEt->Write();
  h_isoR05_hoVetoEt->Write();

  h_pfIsoR03_sumChargedHadronPt->Write();
  h_pfIsoR03_sumNeutralHadronEt->Write();
  h_pfIsoR03_sumPhotonEt->Write();
  h_pfIsoR03_sumNeutralHadronEtHighThreshold->Write();
  h_pfIsoR03_sumPhotonEtHighThreshold->Write();
  h_pfIsoR03_sumPUPt->Write();
  h_pfIsoR04_sumChargedHadronPt->Write();
  h_pfIsoR04_sumNeutralHadronEt->Write();
  h_pfIsoR04_sumPhotonEt->Write();
  h_pfIsoR04_sumNeutralHadronEtHighThreshold->Write();
  h_pfIsoR04_sumPhotonEtHighThreshold->Write();
  h_pfIsoR04_sumPUPt->Write();



  // here I write histograms
  file_out->Close();

}


////////
//////// -- fillDescriptions
////////
void patValidator::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}


////////
//////// -- Analyze
////////
void patValidator::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

   bool ValidDisplaced = iEvent.getByToken(DisplacedToken_, DisplacedCollection_);

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
   
   for (const auto& mu : *DisplacedCollection_)
   {

     h_mu_pt->Fill(mu.pt());
     h_mu_eta->Fill(mu.eta());
     h_mu_phi->Fill(mu.phi());
     h_mu_numberOfChambers->Fill(mu.numberOfChambers());
     h_mu_numberOfChambersCSCorDT->Fill(mu.numberOfChambersCSCorDT());
     h_mu_numberOfMatches->Fill(mu.numberOfMatches());
     h_mu_numberOfMatchedStations->Fill(mu.numberOfMatchedStations());
     h_mu_numberOfMatchedRPCLayers->Fill(mu.numberOfMatchedRPCLayers());
     h_mu_numberOfShowers->Fill(mu.numberOfShowers());

     h_mu_time->Fill(mu.time().timeAtIpInOut);
     h_mu_timeErr->Fill(mu.time().timeAtIpInOutErr);

     if (mu.isTrackerMuon()) {
       h_mu_type->Fill(0);
       h_dtr_pt->Fill(mu.pt());
       h_dtr_eta->Fill(mu.eta());
       h_dtr_phi->Fill(mu.phi());
       h_dtr_numberOfChambers->Fill(mu.numberOfChambers());
       h_dtr_numberOfChambersCSCorDT->Fill(mu.numberOfChambersCSCorDT());
       h_dtr_numberOfMatches->Fill(mu.numberOfMatches());
       h_dtr_numberOfMatchedStations->Fill(mu.numberOfMatchedStations());
       h_dtr_numberOfMatchedRPCLayers->Fill(mu.numberOfMatchedRPCLayers());
       h_dtr_numberOfShowers->Fill(mu.numberOfShowers());
       h_dtr_time->Fill(mu.time().timeAtIpInOut);
       h_dtr_timeErr->Fill(mu.time().timeAtIpInOutErr);
     }
     if (mu.isGlobalMuon()) {
       h_mu_type->Fill(1);
       h_dgl_pt->Fill(mu.pt());
       h_dgl_eta->Fill(mu.eta());
       h_dgl_phi->Fill(mu.phi());
       h_dgl_numberOfChambers->Fill(mu.numberOfChambers());
       h_dgl_numberOfChambersCSCorDT->Fill(mu.numberOfChambersCSCorDT());
       h_dgl_numberOfMatches->Fill(mu.numberOfMatches());
       h_dgl_numberOfMatchedStations->Fill(mu.numberOfMatchedStations());
       h_dgl_numberOfMatchedRPCLayers->Fill(mu.numberOfMatchedRPCLayers());
       h_dgl_numberOfShowers->Fill(mu.numberOfShowers());
       h_dgl_time->Fill(mu.time().timeAtIpInOut);
       h_dgl_timeErr->Fill(mu.time().timeAtIpInOutErr);
     }
     if (mu.isStandAloneMuon()) {
       h_mu_type->Fill(2);
       h_dsa_pt->Fill(mu.pt());
       h_dsa_eta->Fill(mu.eta());
       h_dsa_phi->Fill(mu.phi());
       h_dsa_numberOfChambers->Fill(mu.numberOfChambers());
       h_dsa_numberOfChambersCSCorDT->Fill(mu.numberOfChambersCSCorDT());
       h_dsa_numberOfMatches->Fill(mu.numberOfMatches());
       h_dsa_numberOfMatchedStations->Fill(mu.numberOfMatchedStations());
       h_dsa_numberOfMatchedRPCLayers->Fill(mu.numberOfMatchedRPCLayers());
       h_dsa_numberOfShowers->Fill(mu.numberOfShowers());
       h_dsa_time->Fill(mu.time().timeAtIpInOut);
       h_dsa_timeErr->Fill(mu.time().timeAtIpInOutErr);
     }

     reco::TrackRef iTrk = mu.innerTrack();
     reco::TrackRef gTrk = mu.globalTrack();
     reco::TrackRef oTrk = mu.outerTrack();

     if (iTrk.isNonnull()){
       h_inn_dxy->Fill(iTrk->dxy());
       h_inn_dxyErr->Fill(iTrk->dxyError());
       h_inn_dz->Fill(iTrk->dz());
       h_inn_dzErr->Fill(iTrk->dzError());
       h_inn_normalizedChi2->Fill(iTrk->normalizedChi2());
       const reco::HitPattern iHits = iTrk->hitPattern();
       h_inn_numberOfValidHits->Fill(iHits.numberOfValidHits());
       h_inn_numberOfValidPixelHits->Fill(iHits.numberOfValidPixelHits());
       h_inn_numberOfValidStripHits->Fill(iHits.numberOfValidStripHits());
       h_inn_numberOfValidMuonDTHits->Fill(iHits.numberOfValidMuonDTHits());
       h_inn_numberOfValidMuonCSCHits->Fill(iHits.numberOfValidMuonCSCHits());
       h_inn_numberOfValidMuonRPCHits->Fill(iHits.numberOfValidMuonRPCHits());
     }
     if (gTrk.isNonnull()){
       h_glb_dxy->Fill(gTrk->dxy());
       h_glb_dxyErr->Fill(gTrk->dxyError());
       h_glb_dz->Fill(gTrk->dz());
       h_glb_dzErr->Fill(gTrk->dzError());
       h_glb_normalizedChi2->Fill(gTrk->normalizedChi2());
       const reco::HitPattern gHits = gTrk->hitPattern();
       h_glb_numberOfValidHits->Fill(gHits.numberOfValidHits());
       h_glb_numberOfValidPixelHits->Fill(gHits.numberOfValidPixelHits());
       h_glb_numberOfValidStripHits->Fill(gHits.numberOfValidStripHits());
       h_glb_numberOfValidMuonDTHits->Fill(gHits.numberOfValidMuonDTHits());
       h_glb_numberOfValidMuonCSCHits->Fill(gHits.numberOfValidMuonCSCHits());
       h_glb_numberOfValidMuonRPCHits->Fill(gHits.numberOfValidMuonRPCHits());
     }
     if (oTrk.isNonnull()){
       h_out_dxy->Fill(oTrk->dxy());
       h_out_dxyErr->Fill(oTrk->dxyError());
       h_out_dz->Fill(oTrk->dz());
       h_out_dzErr->Fill(oTrk->dzError());
       h_out_normalizedChi2->Fill(oTrk->normalizedChi2());
       const reco::HitPattern oHits = oTrk->hitPattern();
       h_out_numberOfValidHits->Fill(oHits.numberOfValidHits());
       h_out_numberOfValidPixelHits->Fill(oHits.numberOfValidPixelHits());
       h_out_numberOfValidStripHits->Fill(oHits.numberOfValidStripHits());
       h_out_numberOfValidMuonDTHits->Fill(oHits.numberOfValidMuonDTHits());
       h_out_numberOfValidMuonCSCHits->Fill(oHits.numberOfValidMuonCSCHits());
       h_out_numberOfValidMuonRPCHits->Fill(oHits.numberOfValidMuonRPCHits());
     }

     if ( mu.isIsolationValid() ) {
     h_isoR03_sumPt->Fill(mu.isolationR03().sumPt);
     h_isoR03_emEt->Fill(mu.isolationR03().emEt);
     h_isoR03_hadEt->Fill(mu.isolationR03().hadEt);
     h_isoR03_hoEt->Fill(mu.isolationR03().hoEt);
     h_isoR03_nTracks->Fill(mu.isolationR03().nTracks);
     h_isoR03_nJets->Fill(mu.isolationR03().nJets);
     h_isoR03_trackerVetoPt->Fill(mu.isolationR03().trackerVetoPt);
     h_isoR03_emVetoEt->Fill(mu.isolationR03().emVetoEt);
     h_isoR03_hadVetoEt->Fill(mu.isolationR03().hadVetoEt);
     h_isoR03_hoVetoEt->Fill(mu.isolationR03().hoVetoEt);
     h_isoR05_sumPt->Fill(mu.isolationR05().sumPt);
     h_isoR05_emEt->Fill(mu.isolationR05().emEt);
     h_isoR05_hadEt->Fill(mu.isolationR05().hadEt);
     h_isoR05_hoEt->Fill(mu.isolationR05().hoEt);
     h_isoR05_nTracks->Fill(mu.isolationR05().nTracks);
     h_isoR05_nJets->Fill(mu.isolationR05().nJets);
     h_isoR05_trackerVetoPt->Fill(mu.isolationR05().trackerVetoPt);
     h_isoR05_emVetoEt->Fill(mu.isolationR05().emVetoEt);
     h_isoR05_hadVetoEt->Fill(mu.isolationR05().hadVetoEt);
     h_isoR05_hoVetoEt->Fill(mu.isolationR05().hoVetoEt);
     }

     if ( mu.isPFIsolationValid() ) {
     h_pfIsoR03_sumChargedHadronPt->Fill(mu.pfIsolationR03().sumChargedHadronPt);
     h_pfIsoR03_sumNeutralHadronEt->Fill(mu.pfIsolationR03().sumNeutralHadronEt);
     h_pfIsoR03_sumPhotonEt->Fill(mu.pfIsolationR03().sumPhotonEt);
     h_pfIsoR03_sumNeutralHadronEtHighThreshold->Fill(mu.pfIsolationR03().sumNeutralHadronEtHighThreshold);
     h_pfIsoR03_sumPhotonEtHighThreshold->Fill(mu.pfIsolationR03().sumPhotonEtHighThreshold);
     h_pfIsoR03_sumPUPt->Fill(mu.pfIsolationR03().sumPUPt);
     h_pfIsoR04_sumChargedHadronPt->Fill(mu.pfIsolationR04().sumChargedHadronPt);
     h_pfIsoR04_sumNeutralHadronEt->Fill(mu.pfIsolationR04().sumNeutralHadronEt);
     h_pfIsoR04_sumPhotonEt->Fill(mu.pfIsolationR04().sumPhotonEt);
     h_pfIsoR04_sumNeutralHadronEtHighThreshold->Fill(mu.pfIsolationR04().sumNeutralHadronEtHighThreshold);
     h_pfIsoR04_sumPhotonEtHighThreshold->Fill(mu.pfIsolationR04().sumPhotonEtHighThreshold);
     h_pfIsoR04_sumPUPt->Fill(mu.pfIsolationR04().sumPUPt);
     }

   }


}


