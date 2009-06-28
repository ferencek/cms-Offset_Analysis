#include "TRandom.h"
#include <iostream>

using namespace std;

void jetEnergy(Double_t fRMS, Double_t fTowerE, Double_t fZSThreshold, Int_t fIter)
{ 
 Double_t jetEnergySum = 0;
 Int_t counter = 0;
 Int_t sumCounter = 0;

 TRandom *noise = new TRandom;
 
 for(Int_t i = 0; i < fIter; i++){
  counter++;
  
  for(Int_t j = 0; j < 20; j++){
   Double_t energy = fTowerE + noise->Gaus(0., fRMS);
   
   if(energy > fZSThreshold){
    sumCounter++;
    jetEnergySum += energy;
   }
  }
  
  if(counter%1000 == 0) cout<<">> Iteration: "<<counter<<", Jet energy = "<<jetEnergySum/counter<<" MeV\n";
 }
 cout<<">> Sum counter = "<<sumCounter<<"\n";
} 
