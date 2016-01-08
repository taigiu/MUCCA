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
    
    
    r99t TrainMulti.cxx\(\"BDTG\"\)
    r99t TrainMulti.cxx\(\"MLP\"\)

Test:

    r99t TMVAGui.C\(\"TMVA-1.root\"\)
    r99t TMVAGui.C\(\"TMVA-2.root\"\)
    r99t TMVAGui.C\(\"TMVA-3.root\"\)


where:

    /home/amassiro/Cern/Code/HIG/MUCCA/
    /afs/cern.ch/user/a/amassiro/work/Latinos/Framework/MUCCA/
