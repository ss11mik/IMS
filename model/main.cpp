 /*
  * project: "SHO ve výrobě"
  * course: IMS
  * authors: xmikul69, zpodes05
  *    @ VUT FIT, Brno
  * date: 2021
  */

#include "stdio.h"
#include "stdlib.h"
#include <string>

#include <simlib.h>

// number of actual employees available in company
#define EMPLOYEES 13
#define MACHINES_COUNT 9

//using namespace std;
using namespace simlib3;

//======== editablke simulation parameters ========

// the time span of simulation
// 60 * 8 * 7 minutes * 10 = 10 weeks
#define SIM_TIME_SPAN 33600

int minTransports = 1;


int cuttingTrottlePercent = 0;
// the threshold before clogging
//int cuttingTrottlePercent = 41;


bool usingOptimizedTransport = false;


int posliceksCount = 0;


int capacities[] = {1, 1, 1, 1, 1, 1, 1, 1};
// half production on Cutting2Op and QualityAsOp
//int capacities[] = {2, 2, 2, 2, 1, 2, 2, 1};

//======== editablke simulation parameters ========


#include "stats.hpp"
#include "operations.hpp"
#include "poslicek.hpp"

extern Store machines[MACHINES_COUNT];
extern int zprofilesGened;
extern int cutsGenerated;

int experiment = 0;


void mRun () {

    for(int i = 0; i < MACHINES_COUNT; i++)
    {
        machines[i].Clear();
        machines[i].SetCapacity(capacities[i]);
    }

    Init(0, SIM_TIME_SPAN);

    (new CuttingOp)->Activate();

    for (int i = 0; i < posliceksCount; i++)
        (new Poslicek)->Activate();

    Run();

    for (int i = 0; i < MACHINES_COUNT; i++) {
        machines[i].Output();
    }
    dobaVProdukci.Output();
    dobaVProdukci.Clear();
}

void setup_experiments() {
    SetOutput("model.out");
    switch (experiment) {
        case 0:
        case 1:
            //default

            mRun();
            break;
        case 2:
            //Úzká místa
            capacities[0] = 2;

            mRun();
            break;
        case 3:
            //Nevyužitá práce
            //int capacities[] = {2, 2, 2, 2, 1, 2, 2, 1};
            capacities[0] = 2;
            capacities[1] = 2;
            capacities[2] = 2;
            capacities[3] = 2;
            capacities[4] = 1;
            capacities[5] = 2;
            capacities[6] = 2;
            capacities[7] = 1;

            mRun();
            break;
        case 4:
            //Navrhovaná úprava rozmístění

            usingOptimizedTransport = true;
            mRun();
            break;
        case 5:
            //Dávkové předávání
            minTransports = 1;
            SetOutput("batchModel1.out");
            mRun();

            minTransports = 2;
            SetOutput("batchModel2.out");
            mRun();

            minTransports = 5;
            SetOutput("batchModel5.out");
            mRun();

            minTransports = 10;
            SetOutput("batchModel10.out");
            mRun();
            break;
        case 6:
            //Vyhrazený zaměstnanec pro přenos mezi pracovišti

            posliceksCount = 0;
            SetOutput("poslicekModel0.out");
            mRun();

            posliceksCount = 1;
            SetOutput("poslicekModel1.out");
            mRun();

            posliceksCount = 2;
            SetOutput("poslicekModel2.out");
            mRun();

            posliceksCount = 5;
            SetOutput("poslicekModel5.out");
            mRun();
            break;

    }
}

int main(int argc, char* argv[]) {

    if (argc > 1)
        experiment = atoi(argv[1]);

    machines[0].SetName("Cutting");
    machines[1].SetName("ZProfile");
    machines[2].SetName("Bending");
    machines[3].SetName("Enclosing");
    machines[4].SetName("Cutting2Op");
    machines[5].SetName("CompletionOp");
    machines[6].SetName("PlantingOp");
    machines[7].SetName("QualityAsOp");



    setup_experiments();


    Print("Konec simulace\n");
    return 0;
}
