#include "operations.hpp"
#include <simlib.h>
#include <queue>

extern std::queue<int> itemsInProduction;

//cutting, zprofile, bending, enclosing, cutting2,completaion, planting, quality asurance, expedition

Facility employes[13];
Facility machines[13];

void CuttingOp::MyConstructor(){
    this->avgTime = 4;
    this->employe1 = employes[0];
    this->machine = machines[0];

    this->transportTime = 0.25f;

    itemsInProduction.push(Time);
}
void CuttingOp::MyEnd(){
     (new ZProfileOp)->Activate();
}


void ZProfileOp::MyConstructor(){
    this->avgTime = 1.5;
    this->employe1 = employes[1];
    this->employe1 = employes[2];
    this->machine = machines[1];

    this->transportTime = 0.25f;
}
void ZProfileOp::MyEnd(){
     (new BendingOp)->Activate();
}


void BendingOp::MyConstructor(){
    this->avgTime = 2;
    this->employe1 = employes[3];
    this->employe1 = employes[4];
    this->machine = machines[2];

    this->transportTime = 0.5f;
}
void BendingOp::MyEnd(){
     (new EnclosingOp)->Activate();
}


void EnclosingOp::MyConstructor(){
    this->avgTime = 2;
    this->employe1 = employes[5];
    this->employe1 = employes[6];
    this->machine = machines[3];

    this->transportTime = 1.0f;
}
void EnclosingOp::MyEnd(){
     (new Cutting2Op)->Activate();
}


void Cutting2Op::MyConstructor(){
    this->avgTime = 1;
    this->employe1 = employes[7];
    this->machine = machines[4];

    this->transportTime = 0;
}
void Cutting2Op::MyEnd(){
     (new CompletionOp)->Activate();
}


void CompletionOp::MyConstructor(){
    this->avgTime = 3;
    this->employe1 = employes[8];
    this->machine = machines[5];

    this->transportTime = 0;
}
void CompletionOp::MyEnd(){
     (new ZProfileOp)->Activate();
}


void PlantingOp::MyConstructor(){
    this->avgTime = 2;
    this->employe1 = employes[9];
    this->machine = machines[6];

    this->transportTime = 1;
}
void PlantingOp::MyEnd(){
    //TODO: Sklaodvani
}


void QualityAsOp::MyConstructor(){
    this->avgTime = 1;
    this->employe1 = employes[10];
    this->machine = machines[7];

    this->transportTime = 0.25f;
}
void QualityAsOp::MyEnd(){
     (new ExpeditionOp)->Activate();
}


void ExpeditionOp::MyConstructor(){
    this->avgTime = 30;
    this->employe1 = employes[11];
    this->machine = machines[8];

    this->transportTime = 0.25f;
}
void ExpeditionOp::MyEnd(){
    itemsInProduction.pop();
    //TODO: void
}
