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
#define SIM_TIME_SPAN 336000

// number of actual employees available in company
#define EMPLOYEES 13

//using namespace std;
using namespace simlib3;

int minTransports = 1;
int cuttingTrottlePercent = 0;
bool usingOptimizedTransport = false;

#include "stats.hpp"
#include "operations.hpp"


int main(int args, char* argv[]) {

    Print("Zacatek simulace\n");

   // SetOutput("model.out");
    Init(0, SIM_TIME_SPAN);
    (new CuttingOp)->Activate();

    Run();

    for (int i = 0; i < 9; i++) {
        machines[i].Output();
    }
    dobaVProdukci.Output();
    Print("Konec simulace\n");

    return 0;
}
