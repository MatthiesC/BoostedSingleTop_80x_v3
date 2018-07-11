#include "TLorentzVector.h"
#include "TGenPhaseSpace.h"
#include "TRandom.h"
#include "TF1.h"
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"

#include <fstream>

using namespace std;

void makeTree(){

  // a text and a root file
  fstream infile;
  //infile.open("Top-QCD-Events-NoBTag.txt",ios::in);
  //infile.open("Top-QCD-Events-NoBTag-Reduced.txt",ios::in);
  infile.open("Top-QCD-TauVariables.txt",ios::in);
  //infile.open("TestOutputData.txt",ios::in);
  cout<<" OPENED "<<endl;
    
  //TFile outroot("TopJetsForTMVA-DetectorLevel.root","RECREATE");
  //TFile outroot("QCDEvents700-1000.root","RECREATE");
  TFile outroot("TopEventsForTMVA-DetectorLevel-Tau.root","RECREATE");
  TTree* tSignal = new TTree("treeSignal","");
  TTree* tBackground = new TTree("treeBackground","");
  TTree* tBackground1 = new TTree("treeBackground1","");
  TTree* tBackground2 = new TTree("treeBackground2","");
  TTree* tBackground3 = new TTree("treeBackground3","");
  TTree* tBackground4 = new TTree("treeBackground4","");
  
  // the signal is filled first
  
  double var1, var2,var3,var4,var5,var6,var7,var8,var9,var10,var11,var12,var13,var14,var15,var16,var17,var20,var21,var22;
  int label;

  tSignal->Branch("label",&var1);
  //tSignal->Branch("ptLeading",&var2);
  //tSignal->Branch("SDmassLeading",&var3);
  //tSignal->Branch("MassLeading",&var2);
  //tSignal->Branch("MassSubJet0Leading",&var3);
  //tSignal->Branch("MassSubJet1Leading",&var4);
  tSignal->Branch("jettau1Leading",&var7);
  tSignal->Branch("jettau2Leading",&var8);
  tSignal->Branch("jettau3Leading",&var9);
  //tSignal->Branch("tau31Leading",&var5);
  //tSignal->Branch("tau32Leading",&var6);
  //tSignal->Branch("jetSubJetpt0Leading",&var7);
  //tSignal->Branch("jetSubJetpt1Leading",&var8);
  //tSignal->Branch("DeltaRSubJetsLeading",&var9);
  //tSignal->Branch("ptSubLeading",&var15);
  //tSignal->Branch("SDmassSubLeading",&var16);
  //tSignal->Branch("MassSubLeading",&var10);
  //tSignal->Branch("MassSubJet0SubLeading",&var11);
  //tSignal->Branch("MassSubJet1SubLeading",&var12);
  tSignal->Branch("jettau1SubLeading",&var20);
  tSignal->Branch("jettau2SubLeading",&var21);
  tSignal->Branch("jettau3SubLeading",&var22);
  //tSignal->Branch("tau31SubLeading",&var13);
  //tSignal->Branch("tau32SubLeading",&var14);
  //tSignal->Branch("jetSubJetpt0SubLeading",&var15);
  //tSignal->Branch("jetSubJetpt1SubLeading",&var16);
  //tSignal->Branch("DeltaRSubJetsSubLeading",&var17);
  
  tBackground->Branch("label",&var1);
  //tBackground->Branch("ptLeading",&var2);
  //tBackground->Branch("SDmassLeading",&var3);
  //tBackground->Branch("MassLeading",&var2);
  //tBackground->Branch("MassSubJet0Leading",&var3);
  //tBackground->Branch("MassSubJet1Leading",&var4);
  tBackground->Branch("jettau1Leading",&var7);
  tBackground->Branch("jettau2Leading",&var8);
  tBackground->Branch("jettau3Leading",&var9);
  //tBackground->Branch("tau31Leading",&var5);
  //tBackground->Branch("tau32Leading",&var6);
  //tBackground->Branch("jetSubJetpt0Leading",&var7);
  //tBackground->Branch("jetSubJetpt1Leading",&var8);
  //tBackground->Branch("DeltaRSubJetsLeading",&var9);
  //tBackground->Branch("ptSubLeading",&var15);
  //tBackground->Branch("SDmassSubLeading",&var16);
  //tBackground->Branch("MassSubLeading",&var10);
  //tBackground->Branch("MassSubJet0SubLeading",&var11);
  //tBackground->Branch("MassSubJet1SubLeading",&var12);
  tBackground->Branch("jettau1SubLeading",&var20);
  tBackground->Branch("jettau2SubLeading",&var21);
  tBackground->Branch("jettau3SubLeading",&var22);
  //tBackground->Branch("tau31SubLeading",&var13);
  //tBackground->Branch("tau32SubLeading",&var14);
  //tBackground->Branch("jetSubJetpt0SubLeading",&var15);
  //tBackground->Branch("jetSubJetpt1SubLeading",&var16);
  //tBackground->Branch("DeltaRSubJetsSubLeading",&var17);

  tBackground1->Branch("label",&var1);
  //tBackground1->Branch("ptLeading",&var2);
  //tBackground1->Branch("SDmassLeading",&var3);
  //tBackground1->Branch("MassLeading",&var2);
  //tBackground1->Branch("MassSubJet0Leading",&var3);
  //tBackground1->Branch("MassSubJet1Leading",&var4);
  tBackground1->Branch("jettau1Leading",&var7);
  tBackground1->Branch("jettau2Leading",&var8);
  tBackground1->Branch("jettau3Leading",&var9);
  //tBackground1->Branch("tau31Leading",&var5);
  //tBackground1->Branch("tau32Leading",&var6);
  //tBackground1->Branch("jetSubJetpt0Leading",&var7);
  //tBackground1->Branch("jetSubJetpt1Leading",&var8);
  //tBackground1->Branch("DeltaRSubJetsLeading",&var9);
  //tBackground1->Branch("ptSubLeading",&var15);
  //tBackground1->Branch("SDmassSubLeading",&var16);
  //tBackground1->Branch("MassSubLeading",&var10);
  //tBackground1->Branch("MassSubJet0SubLeading",&var11);
  //tBackground1->Branch("MassSubJet1SubLeading",&var12);
  tBackground1->Branch("jettau1SubLeading",&var20);
  tBackground1->Branch("jettau2SubLeading",&var21);
  tBackground1->Branch("jettau3SubLeading",&var22);
  //tBackground1->Branch("tau31SubLeading",&var13);
  //tBackground1->Branch("tau32SubLeading",&var14);
  //tBackground1->Branch("jetSubJetpt0SubLeading",&var15);
  //tBackground1->Branch("jetSubJetpt1SubLeading",&var16);
  //tBackground1->Branch("DeltaRSubJetsSubLeading",&var17);

  tBackground2->Branch("label",&var1);
  //tBackground2->Branch("ptLeading",&var2);
  //tBackground2->Branch("SDmassLeading",&var3);
  //tBackground2->Branch("MassLeading",&var2);
  //tBackground2->Branch("MassSubJet0Leading",&var3);
  //tBackground2->Branch("MassSubJet1Leading",&var4);
  tBackground2->Branch("jettau1Leading",&var7);
  tBackground2->Branch("jettau2Leading",&var8);
  tBackground2->Branch("jettau3Leading",&var9);
  //tBackground2->Branch("tau31Leading",&var5);
  //tBackground2->Branch("tau32Leading",&var6);
  //tBackground2->Branch("jetSubJetpt0Leading",&var7);
  //tBackground2->Branch("jetSubJetpt1Leading",&var8);
  //tBackground2->Branch("DeltaRSubJetsLeading",&var9);
  //tBackground2->Branch("ptSubLeading",&var15);
  //tBackground2->Branch("SDmassSubLeading",&var16);
  //tBackground2->Branch("MassSubLeading",&var10);
  //tBackground2->Branch("MassSubJet0SubLeading",&var11);
  //tBackground2->Branch("MassSubJet1SubLeading",&var12);
  tBackground2->Branch("jettau1SubLeading",&var20);
  tBackground2->Branch("jettau2SubLeading",&var21);
  tBackground2->Branch("jettau3SubLeading",&var22);
  //tBackground2->Branch("tau31SubLeading",&var13);
  //tBackground2->Branch("tau32SubLeading",&var14);
  //tBackground2->Branch("jetSubJetpt0SubLeading",&var15);
  //tBackground2->Branch("jetSubJetpt1SubLeading",&var16);
  //tBackground2->Branch("DeltaRSubJetsSubLeading",&var17);
 
  tBackground3->Branch("label",&var1);
  //tBackground3->Branch("ptLeading",&var2);
  //tBackground3->Branch("SDmassLeading",&var3);
  //tBackground3->Branch("MassLeading",&var2);
  //tBackground3->Branch("MassSubJet0Leading",&var3);
  //tBackground3->Branch("MassSubJet1Leading",&var4);
  tBackground3->Branch("jettau1Leading",&var7);
  tBackground3->Branch("jettau2Leading",&var8);
  tBackground3->Branch("jettau3Leading",&var9);
  //tBackground3->Branch("tau31Leading",&var5);
  //tBackground3->Branch("tau32Leading",&var6);
  //tBackground3->Branch("jetSubJetpt0Leading",&var7);
  //tBackground3->Branch("jetSubJetpt1Leading",&var8);
  //tBackground3->Branch("DeltaRSubJetsLeading",&var9);
  //tBackground3->Branch("ptSubLeading",&var15);
  //tBackground3->Branch("SDmassSubLeading",&var16);
  //tBackground3->Branch("MassSubLeading",&var10);
  //tBackground3->Branch("MassSubJet0SubLeading",&var11);
  //tBackground3->Branch("MassSubJet1SubLeading",&var12);
  tBackground3->Branch("jettau1SubLeading",&var20);
  tBackground3->Branch("jettau2SubLeading",&var21);
  tBackground3->Branch("jettau3SubLeading",&var22);
  //tBackground3->Branch("tau31SubLeading",&var13);
  //tBackground3->Branch("tau32SubLeading",&var14);
  //tBackground3->Branch("jetSubJetpt0SubLeading",&var15);
  //tBackground3->Branch("jetSubJetpt1SubLeading",&var16);
  //tBackground3->Branch("DeltaRSubJetsSubLeading",&var17);

  tBackground4->Branch("label",&var1);
  //tBackground4->Branch("ptLeading",&var2);
  //tBackground4->Branch("SDmassLeading",&var3);
  //tBackground4->Branch("MassLeading",&var2);
  //tBackground4->Branch("MassSubJet0Leading",&var3);
  //tBackground4->Branch("MassSubJet1Leading",&var4);
  tBackground4->Branch("jettau1Leading",&var7);
  tBackground4->Branch("jettau2Leading",&var8);
  tBackground4->Branch("jettau3Leading",&var9);
  //tBackground4->Branch("tau31Leading",&var5);
  //tBackground4->Branch("tau32Leading",&var6);
  //tBackground4->Branch("jetSubJetpt0Leading",&var7);
  //tBackground4->Branch("jetSubJetpt1Leading",&var8);
  //tBackground4->Branch("DeltaRSubJetsLeading",&var9);
  //tBackground4->Branch("ptSubLeading",&var15);
  //tBackground4->Branch("SDmassSubLeading",&var16);
  //tBackground4->Branch("MassSubLeading",&var10);
  //tBackground4->Branch("MassSubJet0SubLeading",&var11);
  //tBackground4->Branch("MassSubJet1SubLeading",&var12);
  tBackground4->Branch("jettau1SubLeading",&var20);
  tBackground4->Branch("jettau2SubLeading",&var21);
  tBackground4->Branch("jettau3SubLeading",&var22);
  //tBackground4->Branch("tau31SubLeading",&var13);
  //tBackground4->Branch("tau32SubLeading",&var14);
  //tBackground4->Branch("jetSubJetpt0SubLeading",&var15);
  //tBackground4->Branch("jetSubJetpt1SubLeading",&var16);
  //tBackground4->Branch("DeltaRSubJetsSubLeading",&var17);

  if (infile.is_open()){

    //for (int i=0;i<751392;i++){
    //for (int i=0;i<101392;i++){
    for (int i=0;i<4328863;i++){
    
      //infile>>var1>>var2>>var3>>var4>>var5>>var6>>var7>>var8>>var9>>var10>>var11>>var12>>var13>>var14>>var15>>var16>>var17>>var20>>var21>>var22;
      infile>>var1>>var7>>var8>>var9>>var20>>var21>>var22;

      if(var1==1) tSignal->Fill();
      if(var1==-1) tBackground->Fill();
      if(var1==-2) tBackground1->Fill();
      if(var1==-3) tBackground2->Fill();
      if(var1==-4) tBackground3->Fill();
      if(var1==-5) tBackground4->Fill();
    }
  }    

  tSignal->Write();
  tBackground->Write();
  tBackground1->Write();
  tBackground2->Write();
  tBackground3->Write();
  tBackground4->Write();
  infile.close();
  outroot.Close();

}
