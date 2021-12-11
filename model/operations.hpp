 /*
  * project: "SHO ve výrobě"
  * course: IMS
  * authors: xmikul69, zpodes05
  *    @ VUT FIT, Brno
  * date: 2021
  */

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "operation.hpp"
#include <simlib.h>

extern Store machines[9];
extern int storage[9];

//cutting, zprofile, bending, enclosing, cutting2,completaion, planting, quality asurance, expedition
class CuttingOp : public Operation{public: void MyConstructor();void MyEnd();void MyStart();};
class ZProfileOp : public Operation{public: void MyConstructor();void MyEnd();};
class BendingOp : public Operation{public: void MyConstructor();void MyEnd();};
class EnclosingOp : public Operation{public: void MyConstructor();void MyEnd();};
class Cutting2Op : public Operation{public: void MyConstructor();void MyEnd();};
class CompletionOp : public Operation{public: void MyConstructor();void MyEnd();};
class PlantingOp : public Operation{public: void MyConstructor();void MyEnd();};
class QualityAsOp : public Operation{public: void MyConstructor();void MyEnd();};
class ExpeditionOp : public Operation{public: void MyConstructor();void MyEnd();};

#endif
