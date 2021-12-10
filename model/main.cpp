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
// 60 * 8 * 7 minutes = 1 week
#define SIM_TIME_SPAN 3360

// number of actual employees available in company
#define EMPLOYEES 13

//using namespace std;
using namespace simlib3;

#include "stats.cpp"
#include "operations.hpp"





int main(int args, char* argv[]) {


    //Operation cutting(4, 1), z_profile(1.5, 2), bending(2, 2), enclosing(2, 2), cutting2(1, 1), completation(3, 1), planting(2, 1);
    //Storage storage;
   // Operation qa(1, 1), expedition(30, 1);

    Print("Zacatek simulace\n");

   // SetOutput("model.out");
    Init(0, SIM_TIME_SPAN);
    (new CuttingOp)->Activate();
    (new mStat)->Activate();

    Run();

    Print("Konec simulace\n");

    return 0;
}
