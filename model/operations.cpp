 /*
  * project: "SHO ve výrobě"
  * course: IMS
  * authors: xmikul69, zpodes05
  *    @ VUT FIT, Brno
  * date: 2021
  */

#include "operations.hpp"
#include <simlib.h>
#include <queue>
#include "stats.hpp"

//cutting, zprofile, bending, enclosing, cutting2,completaion, planting, quality asurance, expedition

Facility machines[9];
int storages[9];

extern int posliceksCount;

extern int cuttingTrottlePercent;
int cuttingCycle = 0;

extern bool usingOptimizedTransport;

void CuttingOp::MyConstructor(){
    this->avgTime = 4;
    this->machine = machines[0];
    this->currentStorage = &storages[0];
    this->transportTime = (usingOptimizedTransport)? 0.2f : 0.25f;

}
void CuttingOp::MyStart(){
    itemsInProduction.push(Time);
    if (cuttingCycle < cuttingTrottlePercent)
        itemsInProduction.push(Time);
    cuttingCycle = (cuttingCycle+1)%100;
    (new CuttingOp)->Activate();
}
void CuttingOp::MyEnd(){
     (new ZProfileOp)->Activate();
     if (cuttingCycle < cuttingTrottlePercent)
        (new ZProfileOp)->Activate();
}


void ZProfileOp::MyConstructor(){
    this->avgTime = 1.5f;
    this->machine = machines[1];
    this->currentStorage = &storages[1];
    this->transportTime = (usingOptimizedTransport)? 0.2f : 0.25f;
}
void ZProfileOp::MyEnd(){
     (new BendingOp)->Activate();
}


void BendingOp::MyConstructor(){
    this->avgTime = 2;
    this->machine = machines[2];
    this->currentStorage = &storages[2];
    this->transportTime = (usingOptimizedTransport)? 0.7f : 0.5f;
}
void BendingOp::MyEnd(){
     (new EnclosingOp)->Activate();
}


void EnclosingOp::MyConstructor(){
    this->avgTime = 2;
    this->machine = machines[3];
    this->currentStorage = &storages[3];
    this->transportTime = (usingOptimizedTransport)? 0.2f : 1.0f;
}
void EnclosingOp::MyEnd(){
     (new Cutting2Op)->Activate();
}


void Cutting2Op::MyConstructor(){
    this->avgTime = 1;
    this->machine = machines[4];
    this->currentStorage = &storages[4];
    this->transportTime = 0;
}
void Cutting2Op::MyEnd(){
     (new CompletionOp)->Activate();
}


void CompletionOp::MyConstructor(){
    this->avgTime = 3;
    this->machine = machines[5];
    this->currentStorage = &storages[5];
    this->transportTime = 0;
}
void CompletionOp::MyEnd(){

     (new PlantingOp)->Activate();
}


void PlantingOp::MyConstructor(){
    this->avgTime = 2;
    this->machine = machines[6];
    this->currentStorage = &storages[6];
    this->transportTime = (usingOptimizedTransport)? 0.5f :1.0f;
}
void PlantingOp::MyEnd(){
    //TODO: product is completed. calculate the total time
    //TODO: Sklaodvani
    (new QualityAsOp)->Activate();
}




void QualityAsOp::MyConstructor(){
    this->avgTime = 1;
    this->machine = machines[7];
    this->currentStorage = &storages[7];
    this->transportTime = 0.25f;
}
void QualityAsOp::MyEnd(){
    dobaVProdukci(Time - itemsInProduction.front());
    itemsInProduction.pop();
 //    (new ExpeditionOp)->Activate();
}


void ExpeditionOp::MyConstructor(){
    this->avgTime = 30;
    this->machine = machines[8];
    this->currentStorage = &storages[8];
    this->transportTime = 0;
}
void ExpeditionOp::MyEnd(){
    dobaVProdukci(Time - itemsInProduction.front());
    itemsInProduction.pop();
    //TODO: void
}
