 /*
  * project: "SHO ve výrobě"
  * course: IMS
  * authors: xmikul69, zpodes05
  *    @ VUT FIT, Brno
  * date: 2021
  */

#ifndef OPERATION_H
#define OPERATION_H

#include <simlib.h>
#include <queue>

extern int minTransports;
extern int posliceksCount;

class Operation: public simlib3::Process {

public:

    virtual void MyConstructor()=0;
    virtual void MyEnd()=0;
    virtual void MyStart(){};
    virtual bool CanTransport()
    {
        return true;
    }
    void Behavior() {
        this->minTransportCount = minTransports;
        MyConstructor();

        //seize stroj & cloveka
        machine->Enter(this, 1);
        // Seize(*machine);
        MyStart();

        //TODO exp or sth
        //auto time = abs(Normal(avgTime, sigma));
        Wait(avgTime);

        (*currentStorage)++;

        //release stroj
        if(posliceksCount > 0)
        {
            machine->Leave(1);
            //seize the transport worker
        }
        else
        {
        
            if (minTransportCount <= (*currentStorage)) {
                //transport
                if(transportTime != 0)
                {
                    Wait(transportTime);
                }

                for(int i = 0; i <(*currentStorage); i++)
                {
                    MyEnd();
                }
                *currentStorage = 0;

                // go back
                if(transportTime != 0)
                {
                    Wait(transportTime);
                }
            }
            machine->Leave(1);
        }

    }

    protected:
        double avgTime;
        double sigma = .3;
        Store* machine = NULL;
        float transportTime = 0;

        int minTransportCount = 1;
        int *currentStorage;
};



#endif // OPERATION_H
