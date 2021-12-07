 /*
  * project: "SHO ve výrobě"
  * course: IMS
  * authors: xmikul69, zpodes05
  *    @ VUT FIT, Brno
  * date: 2021
  */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "simlib.h"

//using namespace std;
//using namespace simlib3;

int main(int args, char* argv[]) {

    //Print(" model2 - SIMLIB/C++ example\n");

    SetOutput("model.out");
    Init(0, 1000);

    Run();

    return 0;
}
