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


//int capacities[] = {1, 1, 1, 1, 1, 1, 1, 1};
// helf production on Cutting2Op and QualityAsOp
int capacities[] = {2, 2, 2, 2, 1, 2, 2, 1};

//======== editablke simulation parameters ========


#include "stats.hpp"
#include "operations.hpp"
#include "poslicek.hpp"

extern Store machines[MACHINES_COUNT];
extern int zprofilesGened;
extern int cutsGenerated;

int main(int args, char* argv[]) {

    for(int i = 0; i < MACHINES_COUNT; i++)
    {
        machines[i].SetCapacity(capacities[i]);
    }

    machines[0].SetName("Cutting");
    machines[1].SetName("ZProfile");
    machines[2].SetName("Bending");
    machines[3].SetName("Enclosing");
    machines[4].SetName("Cutting2Op");
    machines[5].SetName("CompletionOp");
    machines[6].SetName("PlantingOp");    
    machines[7].SetName("QualityAsOp");


    Print("Zacatek simulace\n");

   // SetOutput("model.out");
    Init(0, SIM_TIME_SPAN);
    (new CuttingOp)->Activate();

    for (int i = 0; i < posliceksCount; i++)
        (new Poslicek)->Activate();

    Run();

    for (int i = 0; i < MACHINES_COUNT; i++) {
        machines[i].Output();
    }
    dobaVProdukci.Output();

    Print("zprofiles %d\n",zprofilesGened);
    Print("cuts %d\n",cutsGenerated);

    Print("Konec simulace\n");
    return 0;
}
