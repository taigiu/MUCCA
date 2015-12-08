/**********************************************************************************
 * Project   : TMVA - a Root-integrated toolkit for multivariate data analysis    *
 * Package   : TMVA                                                               *
 * Root Macro: TMVAMulticlass                                                     *
 *                                                                                *
 * This macro provides a simple example for the training and testing of the TMVA  *
 * multiclass classification                                                      *
 **********************************************************************************/

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"


#include "TMVA/Tools.h"
#include "TMVA/Factory.h"
#include "TMVA/TMVAMultiClassGui.h"

// #include "Tools.h"
// #include "Factory.h"
// #include "TMVAMultiClassGui.h"


using namespace TMVA;

void TrainMulti( TString myMethodList = "" ) {
 
 // This loads the library
 TMVA::Tools::Instance();
 
 // to get access to the GUI and all tmva macros
 // TString tmva_dir(TString(gRootDir) + "/tmva");
 // if(gSystem->Getenv("TMVASYS"))
 //    tmva_dir = TString(gSystem->Getenv("TMVASYS"));
 // gROOT->SetMacroPath(tmva_dir + "/test/:" + gROOT->GetMacroPath() );
 // gROOT->ProcessLine(".L TMVAMultiClassGui.C");
 
 
 //---------------------------------------------------------------
 // default MVA methods to be trained + tested
 std::map<std::string,int> Use;
 Use["MLP"]             = 1;
 Use["BDTG"]            = 1;
 Use["FDA_GA"]          = 0;
 Use["PDEFoam"]         = 0;
 //---------------------------------------------------------------
 
 std::cout << std::endl;
 std::cout << "==> Start TMVAMulticlass" << std::endl;
 
 if (myMethodList != "") {
  for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;
  
  std::vector<TString> mlist = TMVA::gTools().SplitString( myMethodList, ',' );
  for (UInt_t i=0; i<mlist.size(); i++) {
   std::string regMethod(mlist[i]);
   
   if (Use.find(regMethod) == Use.end()) {
    std::cout << "Method \"" << regMethod << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
    for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) std::cout << it->first << " ";
    std::cout << std::endl;
    return;
   }
   Use[regMethod] = 1;
  }
 }
 
 // Create a new root output file.
 TString outfileName = "TMVAMulticlass.root";
 TFile* outputFile = TFile::Open( outfileName, "RECREATE" );
 
 TMVA::Factory *factory = new TMVA::Factory( "TMVAMulticlass", outputFile,
                                             "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=multiclass" );

 factory->AddVariable( "std_vector_lepton_pt[0]", 'F' );
 factory->AddVariable( "std_vector_lepton_pt[1]", 'F' );
 factory->AddVariable( "mll", 'F' );
 factory->AddVariable( "dphill", 'F' );
 factory->AddVariable( "yll", 'F' );
 factory->AddVariable( "ptll", 'F' );
//  factory->AddVariable( "pfType1Met", 'F' );
 
//  factory->AddVariable( "bvetoMY :=  (std_vector_jet_pt.at(0) > 15) * std_vector_jet_csvv2ivf.at(0)", 'F' );
//  factory->AddVariable( "bvetoMY :=  (std_vector_jet_pt[0] > 15) * std_vector_jet_csvv2ivf[0]", 'F' );
//  factory->AddVariable( "bvetoMY :=  (std_vector_jet_pt[0] > 15) ", 'F' );
//   factory->AddVariable( "bvetoMY :=  std_vector_jet_csvv2ivf[0]", 'F' );
//  factory->AddVariable( "bvetoMY :=  (std_vector_jet_pt[0] > 15) * (std_vector_jet_csvv2ivf[0])", 'F' );
 
 //  
//  factory->AddVariable( "bvetoMY :=  mll * pt2", 'F' );
//  factory->AddVariable( "bvetoMY :=  (mll>20) * pt2", 'F' );
 
 //  factory->AddVariable( "bveto0 :=  std_vector_jet_pt[0] + std_vector_jet_pt[1]", 'F' );
//  factory->AddVariable( "std_vector_jet_pt[0]", 'F' );
//  factory->AddVariable( "std_vector_jet_pt[1]", 'F' );
 

 
 
 
 TString fname;
 
 fname = Form ("/media/data/amassiro/LatinoTrees/25ns/21Oct2015/mcwghtcount__MC__l2sel/latino_GluGluHToTauTau_M125.root");
 TFile *inputS1 = TFile::Open( fname );
 TTree *signal1 = (TTree*) inputS1->Get("latino");

 fname = Form ("/media/data/amassiro/LatinoTrees/25ns/21Oct2015/mcwghtcount__MC__l2sel/latino_WWTo2L2Nu.root");
 TFile *inputB1 = TFile::Open( fname );
 TTree *background1 = (TTree*) inputB1->Get("latino");
 
 fname = Form ("/media/data/amassiro/LatinoTrees/25ns/21Oct2015/mcwghtcount__MC__l2sel/latino_DYJetsToLL_M-10to50.root");
//  fname = Form ("/media/data/amassiro/LatinoTrees/25ns/21Oct2015/mcwghtcount__MC__l2sel/latino_DYJetsToLL_M-5to50-LO.root");
 TChain *background2 = new TChain("latino");
 background2->Add(fname);
//  fname = Form ("/media/data/amassiro/LatinoTrees/25ns/21Oct2015/mcwghtcount__MC__l2sel/latino_DYJetsToLL_M-50.root");
//  background2->Add(fname);
 
//  fname = Form ("/media/data/amassiro/LatinoTrees/25ns/21Oct2015/mcwghtcount__MC__l2sel/latino_TTJets.root");
 fname = Form ("/media/data/amassiro/LatinoTrees/25ns/21Oct2015/mcwghtcount__MC__l2sel/latino_TTTo2L2Nu.root");
 TFile *inputB3 = TFile::Open( fname );
 TTree *background3 = (TTree*) inputB3->Get("latino");
 
 gROOT->cd( outfileName+TString(":/") );
 factory->AddTree    (signal1,"Signal");
 factory->AddTree    (background1,"WW");
 factory->AddTree    (background2,"DY");
 factory->AddTree    (background3,"Top");
 
 //---- global weight
//  factory->SetWeightExpression("baseW*puW*GEN_weight_SM/abs(GEN_weight_SM)");
 factory->SetWeightExpression("baseW*puW");
 
 TCut mycut = "mll>10 && std_vector_lepton_pt[0]>20 \
               && std_vector_lepton_pt[1]>10 && (channel==2 || channel==3) \
               && njet==0 \
               && ( std_vector_jet_pt[0] < 15 || std_vector_jet_csvv2ivf[0] < 0.605 ) \
              "; 
 factory->PrepareTrainingAndTestTree( mycut, "SplitMode=Random:NormMode=NumEvents:!V" );
 
 if (Use["BDTG"]) // gradient boosted decision trees
  factory->BookMethod( TMVA::Types::kBDT, "BDTG", "!H:!V:NTrees=1000:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=20:MaxDepth=2");
 if (Use["MLP"]) // neural network
  factory->BookMethod( TMVA::Types::kMLP, "MLP", "!H:!V:NeuronType=tanh:NCycles=100:HiddenLayers=N+5,5:TestRate=5:EstimatorType=MSE");
//  if (Use["FDA_GA"]) // functional discriminant with GA minimizer
//   factory->BookMethod( TMVA::Types::kFDA, "FDA_GA", "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=GA:PopSize=300:Cycles=3:Steps=20:Trim=True:SaveBestGen=1" );
//  if (Use["PDEFoam"]) // PDE-Foam approach
//   factory->BookMethod( TMVA::Types::kPDEFoam, "PDEFoam", "!H:!V:TailCut=0.001:VolFrac=0.0666:nActiveCells=500:nSampl=2000:nBin=5:Nmin=100:Kernel=None:Compress=T" );
 
 // Train MVAs using the set of training events
 factory->TrainAllMethods();
 
 // ---- Evaluate all MVAs using the set of test events
 factory->TestAllMethods();
 
 // ----- Evaluate and compare performance of all configured MVAs
 factory->EvaluateAllMethods();
 
 // --------------------------------------------------------------
 
 // Save the output
 outputFile->Close();
 
 std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
 std::cout << "==> TMVAClassification is done!" << std::endl;
 
 delete factory;
 
 // Launch the GUI for the root macros
 if (!gROOT->IsBatch()) TMVAMultiClassGui( outfileName );
 
 
}

int main( int argc, char** argv )
{
 // Select methods (don't look at this code - not of interest)
 TString methodList; 
 for (int i=1; i<argc; i++) {
  TString regMethod(argv[i]);
  if(regMethod=="-b" || regMethod=="--batch") continue;
  if (!methodList.IsNull()) methodList += TString(","); 
  methodList += regMethod;
 }
 TrainMulti(methodList);
 return 0;
}

