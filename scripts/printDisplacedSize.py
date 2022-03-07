import ROOT as r
from ROOT import gROOT

gROOT.LoadMacro('printSizes.C')
gROOT.SetBatch(1)

verbose = True

### Load tree
_file = r.TFile("/eos/user/f/fernance/Muon-POG/displacedCollection-implementation/11834.21/RECO/output_14.root")
_tree = _file.Get("Events")
tree_size = r.sizeOnDisk(_tree)
print(">>> Tree size: {0} bytes".format(tree_size))

### Branch definition
branches = []
# muons
branches.append( ["recoMuons_displacedMuons__RECO.", 0.0, 0.0] )
# value maps (PF iso)
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValueCharged03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValueCharged04_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValueChargedAll03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValueChargedAll04_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValueGamma03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValueGamma04_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValueGammaHighThreshold03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValueGammaHighThreshold04_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValueNeutral03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValueNeutral04_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValueNeutralHighThreshold03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValueNeutralHighThreshold04_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValuePU03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFMeanDRIsoValuePU04_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValueCharged03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValueCharged04_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValueChargedAll03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValueChargedAll04_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValueGamma03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValueGamma04_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValueGammaHighThreshold03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValueGammaHighThreshold04_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValueNeutral03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValueNeutral04_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValueNeutralHighThreshold03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValueNeutralHighThreshold04_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValuePU03_RECO.", 0.0, 0.0] )
branches.append( ["doubleedmValueMap_displacedMuons_dispMuPFSumDRIsoValuePU04_RECO.", 0.0, 0.0] )
# time branches
branches.append( ["recoMuonTimeExtraedmValueMap_displacedMuons_combined_RECO.", 0.0, 0.0] )
branches.append( ["recoMuonTimeExtraedmValueMap_displacedMuons_csc_RECO.", 0.0, 0.0] )
branches.append( ["recoMuonTimeExtraedmValueMap_displacedMuons_dt_RECO.", 0.0, 0.0] )
# Muon reduced track extras
branches.append( ["recoTrackExtras_displacedMuonReducedTrackExtras__RECO.", 0.0, 0.0] )
branches.append( ["TrackingRecHitsOwned_displacedMuonReducedTrackExtras__RECO.", 0.0, 0.0] )
branches.append( ["recoTrackExtrasedmAssociation_displacedMuonReducedTrackExtras__RECO.", 0.0, 0.0] )
branches.append( ["SiPixelClusteredmNewDetSetVector_displacedMuonReducedTrackExtras__RECO.", 0.0, 0.0] )
branches.append( ["SiStripClusteredmNewDetSetVector_displacedMuonReducedTrackExtras__RECO.", 0.0, 0.0] )

if verbose: ">> Reading size of {0} branches".format(len(branches))

# Compute the size:
total_size = 0.0
for branch in branches:
    branch[1] = r.sizeOnDisk(_tree.GetBranch(branch[0]), True)
    branch[2] = r.sizeOnDisk(_tree.GetBranch(branch[0]), True)/tree_size
    total_size += r.sizeOnDisk(_tree.GetBranch(branch[0]), True)
    print(">> Branch {0} takes {1} bytes in disk, {2} fraction of total size".format(branch[0], branch[1], branch[2]))

print("-- The total space taken by displaced branches is {0} bytes, fraction {1}% --".format(total_size, total_size/tree_size*100.))

