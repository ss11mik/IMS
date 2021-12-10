#include "operations.hpp"
#include <simlib.h>
#include <queue>

extern std::queue<int> itemsInProduction;
extern Histogram dobaVProdukci;

//cutting, zprofile, bending, enclosing, cutting2,completaion, planting, quality asurance, expedition

Facility machines[9];

void CuttingOp::MyConstructor(){
    this->avgTime = 4;
    this->machine = machines[0];

    this->transportTime = 0.25f;
}
void CuttingOp::MyStart(){
    itemsInProduction.push(Time);
}
void CuttingOp::MyEnd(){
     (new ZProfileOp)->Activate();
     (new CuttingOp)->Activate();
}


void ZProfileOp::MyConstructor(){
    this->avgTime = 1.5f;
    this->machine = machines[1];

    this->transportTime = 0.25f;
}
void ZProfileOp::MyEnd(){
     (new BendingOp)->Activate();
}


void BendingOp::MyConstructor(){
    this->avgTime = 2;
    this->machine = machines[2];

    this->transportTime = 0.5f;
}
void BendingOp::MyEnd(){
     (new EnclosingOp)->Activate();
}


void EnclosingOp::MyConstructor(){
    this->avgTime = 2;
    this->machine = machines[3];

    this->transportTime = 1.0f;
}
void EnclosingOp::MyEnd(){
     (new Cutting2Op)->Activate();
}


void Cutting2Op::MyConstructor(){
    this->avgTime = 1;
    this->machine = machines[4];

    this->transportTime = 0;
}
void Cutting2Op::MyEnd(){
     (new CompletionOp)->Activate();
}


void CompletionOp::MyConstructor(){
    this->avgTime = 3;
    this->machine = machines[5];

    this->transportTime = 0;
}
void CompletionOp::MyEnd(){

     (new PlantingOp)->Activate();
}


void PlantingOp::MyConstructor(){
    this->avgTime = 2;
    this->machine = machines[6];

    this->transportTime = 1;
}
void PlantingOp::MyEnd(){
    //TODO: product is completed. calculate the total time
    //TODO: Sklaodvani
    (new QualityAsOp)->Activate();
}




void QualityAsOp::MyConstructor(){
    this->avgTime = 1;
    this->machine = machines[7];

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

    this->transportTime = 0;
}
void ExpeditionOp::MyEnd(){
    Print("pop\n");
    dobaVProdukci(Time - itemsInProduction.front());
    itemsInProduction.pop();
    //TODO: void
}
