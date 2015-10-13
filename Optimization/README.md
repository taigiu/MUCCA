Training
====

source of root, needed for the GUI later

    cmsenv of a CMSSW release  CMSSW_5_3_11_patch6
    source /afs/cern.ch/sw/lcg/app/releases/ROOT/5.34.21/x86_64-slc5-gcc47-opt/root/bin/thisroot.sh

Train:

    r99t Train.cxx\(\"BDTG\"\)
    r99t TrainMulti.cxx\(\"BDTG\"\)
    r99t TrainMulti.cxx\(\"MLP\"\)

Test:

    r99t TMVAGui.C\(\"TMVA.root\"\)


where:

    /home/amassiro/Cern/Code/HIG/MUCCA/
