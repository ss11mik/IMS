 /*
  * project: "SHO ve výrobě"
  * course: IMS
  * authors: xmikul69, zpodes05
  *    @ VUT FIT, Brno
  * date: 2021
  */

#ifndef POST_H
#define POST_H

#include <simlib.h>

class Operation;

class CuttingOp;
class ZProfileOp;
class BendingOp;
class EnclosingOp;
class Cutting2Op;
class CompletionOp;
class PlantingOp;
class QualityAsOp;
class ExpeditionOp;


extern int posliceksCount;
extern int storages[9];

//TODO
int transportTime= 1;

class Poslicek: public simlib3::Process {

public:

    void Behavior() {
        do {
            didSth = false;
            int maxWaiting = 0, maxWaitingIndex;
            //check each  storasge
            for (int i = 0; i < 9; i++) {
                //najit kde jich je nejvic
                if (storages[i] > maxWaiting) {
                    maxWaiting = storages[i];
                    maxWaitingIndex = i;
                }
            }

            if (maxWaiting > 0) {
                //ma co prenest

                // presun na dalsi pracoviste
                auto presun = abs(Normal(.1, .05));
                Wait(presun);

                //TODO koef na pocet prenasenych
                Wait(transportTime);//todo: delta

                for(int j = 0; j < storages[maxWaitingIndex]; j++) {
                    switch(maxWaitingIndex) {
                        case 0:
                            (new CuttingOp)->MyEnd();
                            break;
                        case 1:
                            (new ZProfileOp)->MyEnd();
                            break;
                        case 2:
                            (new BendingOp)->MyEnd();
                            break;
                        case 3:
                            (new EnclosingOp)->MyEnd();
                            break;
                        case 4:
                            (new Cutting2Op)->MyEnd();
                            break;
                        case 5:
                            (new CompletionOp)->MyEnd();
                            break;
                        case 6:
                            (new PlantingOp)->MyEnd();
                            break;
                        case 7:
                            (new QualityAsOp)->MyEnd();
                            break;
                        case 8:
                            (new ExpeditionOp)->MyEnd();
                            break;
                    }
                }
                storages[maxWaitingIndex] = 0;

                didSth = true;
            }
        } while (didSth);
        //TODO dowo si prervu. Idzie palic
        //pls . hilfe. rutunku.
        Wait(10);
        (new Poslicek)->Activate();
    }

protected:
    bool didSth = true;
};


#endif
