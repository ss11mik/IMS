#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "operation.hpp"
#include <simlib.h>

//cutting, zprofile, bending, enclosing, cutting2,completaion, planting, quality asurance, expedition
class CuttingOp : Operation{public: void MyConstructor();void MyEnd();};
class ZProfileOp : Operation{public: void MyConstructor();void MyEnd();};
class BendingOp : Operation{public: void MyConstructor();void MyEnd();};
class EnclosingOp : Operation{public: void MyConstructor();void MyEnd();};
class Cutting2Op : Operation{public: void MyConstructor();void MyEnd();};
class CompletionOp : Operation{public: void MyConstructor();void MyEnd();};
class PlantingOp : Operation{public: void MyConstructor();void MyEnd();};
class QualityAsOp : Operation{public: void MyConstructor();void MyEnd();};
class ExpeditionOp : Operation{public: void MyConstructor();void MyEnd();};

#endif