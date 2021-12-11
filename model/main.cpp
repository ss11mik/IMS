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

// the time span of simulation
// 60 * 8 * 7 minutes * 100 = 100 weeks
#define SIM_TIME_SPAN 33600

// number of actual employees available in company
#define EMPLOYEES 13

//using namespace std;
using namespace simlib3;

int minTransports = 1;
int cuttingTrottlePercent = 0;
bool usingOptimizedTransport = false;
int posliceksCount = 0;

int capacities[] = {1, 1, 1, 1, 1, 1, 1, 1};

#include "stats.hpp"
#include "operations.hpp"
#include "poslicek.hpp"

extern Store machines[9];
extern int zprofilesGened;
extern int cutsGenerated;

int main(int args, char* argv[]) {

    for(int i = 0;i<9;i++)
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

    for (int i = 0; i < 9; i++) {
        machines[i].Output();
    }
    dobaVProdukci.Output();
    Print("Konec simulace\n");
Print("zprofiles %d\n",zprofilesGened);
Print("cuts %d\n",cutsGenerated);
    return 0;
}
