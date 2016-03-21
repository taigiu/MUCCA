Training
====

source of root, needed for the GUI later

    NOT NEEDED
    cmsenv of a CMSSW release  CMSSW_5_3_11_patch6
    source /afs/cern.ch/sw/lcg/app/releases/ROOT/5.34.21/x86_64-slc5-gcc47-opt/root/bin/thisroot.sh

    
    NEEDED
    . /afs/cern.ch/sw/lcg/external/gcc/4.9/x86_64-slc6-gcc49-opt/setup.sh
    . /afs/cern.ch/sw/lcg/app/releases/ROOT/6.04.10/x86_64-slc6-gcc49-opt/root/bin/thisroot.sh
 
 

Train:

    r99t -q Train.cxx\(1,\"BDTG\"\)
    r99t -q Train.cxx\(2,\"BDTG\"\)
    r99t -q Train.cxx\(3,\"BDTG\"\)
    r99t -q Train.cxx\(4,\"BDTG\"\)
    r99t -q Train.cxx\(5,\"BDTG\"\)
    
    r99t -q Train.cxx\(1\)
    r99t -q Train.cxx\(2\)
    r99t -q Train.cxx\(3\)
    r99t -q Train.cxx\(4\)
    r99t -q Train.cxx\(5\)

    
    r99t TrainMulti.cxx\(\"BDTG\"\)
    r99t TrainMulti.cxx\(\"MLP\"\)

Test:

    r99t TMVAGui.C\(\"TMVA-1.root\"\)
    r99t TMVAGui.C\(\"TMVA-2.root\"\)
    r99t TMVAGui.C\(\"TMVA-3.root\"\)
    r99t TMVAGui.C\(\"TMVA-4.root\"\)
    r99t TMVAGui.C\(\"TMVA-5.root\"\)

    r99t TMVAGui.C\(\"TMVA-1-variables.root\"\)
    r99t TMVAGui.C\(\"TMVA-2-variables.root\"\)
    r99t TMVAGui.C\(\"TMVA-3-variables.root\"\)
    r99t TMVAGui.C\(\"TMVA-4-variables.root\"\)
    r99t TMVAGui.C\(\"TMVA-5-variables.root\"\)

    
To run gardener:

    cp Weights-1/TMVAClassification_BDTG.weights.xml   /afs/cern.ch/user/a/amassiro/Framework/CMSSW_7_6_3/src/LatinoAnalysis/Gardener/python/data/mucca/TMVAClassification_BDTG.weights.bkg1.xml
    cp Weights-2/TMVAClassification_BDTG.weights.xml   /afs/cern.ch/user/a/amassiro/Framework/CMSSW_7_6_3/src/LatinoAnalysis/Gardener/python/data/mucca/TMVAClassification_BDTG.weights.bkg2.xml
    cp Weights-3/TMVAClassification_BDTG.weights.xml   /afs/cern.ch/user/a/amassiro/Framework/CMSSW_7_6_3/src/LatinoAnalysis/Gardener/python/data/mucca/TMVAClassification_BDTG.weights.bkg3.xml
    cp Weights-4/TMVAClassification_BDTG.weights.xml   /afs/cern.ch/user/a/amassiro/Framework/CMSSW_7_6_3/src/LatinoAnalysis/Gardener/python/data/mucca/TMVAClassification_BDTG.weights.bkg4.xml
    cp Weights-5/TMVAClassification_BDTG.weights.xml   /afs/cern.ch/user/a/amassiro/Framework/CMSSW_7_6_3/src/LatinoAnalysis/Gardener/python/data/mucca/TMVAClassification_BDTG.weights.bkg5.xml
    
    
where:

    /home/amassiro/Cern/Code/HIG/MUCCA/
    /afs/cern.ch/user/a/amassiro/work/Latinos/Framework/MUCCA/
