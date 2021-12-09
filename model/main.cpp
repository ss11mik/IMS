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
//using namespace simlib3;


// number of employees not doing anything at the moment
int availableEmployees = EMPLOYEES;



class Transport: public Process {
public:
    Transport(float avgTime, int employees) {
        this->avgTime = avgTime;
        this->employees = employees;
    };

    float avgTime;
    int employees;

    void Behavior() {
        Wait(avgTime);
    }
};

class Operation: public Process {
public:
    Operation(float avgTime, int employees) {
        this->avgTime = avgTime;
        this->employees = employees;
    };

    float avgTime;
    int employees;

    void Behavior() {
        availableEmployees -= employees;
        //TODO exp or sth
        Wait(avgTime);
        (new Transport(avgTime, employees))->Activate();
        availableEmployees += employees;
    }
};


class Storage: public Process {
   void Behavior() {

   }
};





Facility stacirna;

int main(int args, char* argv[]) {


    Operation cutting(4, 1), z_profile(1.5, 2), bending(2, 2), enclosing(2, 2), cutting2(1, 1), completation(3, 1), planting(2, 1);
    Storage storage;
    Operation qa(1, 1), expedition(30, 1);

    //Print(" model2 - SIMLIB/C++ example\n");
    Print("Zacatek simulace\n");

    SetOutput("model.out");
    Init(0, SIM_TIME_SPAN);

  //  (new Tyden)->Activate();

    Run();

    Print("Konec simulace\n");

    return 0;
}
