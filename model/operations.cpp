#include "operations.hpp"
#include <simlib.h>

//cutting, zprofile, bending, enclosing, cutting2,completaion, planting, quality asurance, expedition

void CuttingOp::MyConstructor(){
    this->avgTime = 4;
    this->employees = 1;
    this->employesStartIndex = 0;
    this->transportTime = 0.25f;
}
void CuttingOp::MyEnd(){
    Operation* op;
    op->Activate();
    // (ZProfileOp())->Activate();
}