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
        Seize(*machine);
        MyStart();

        //TODO exp or sth
        auto time = abs(Normal(avgTime, sigma));
        Wait(time);

        //release stroj
        if(!isTransportedByWorker)
        {
            Release(*machine);
            //seize the transport worker
        }

        (*currentStorage)++;

        if(minTransportCount== *currentStorage)
        {
            //transport
            if(transportTime!=0)
            {
                Wait(transportTime);//todo: delta
            }
        }

        if(isTransportedByWorker)
        {
            Release(*machine);
        }
        else
        {
            //release the transport worker
        }


        if(transportTime==0)
            MyEnd();
        else if(minTransportCount== *currentStorage )
        {
            for(int i = 0;i<minTransportCount;i++)
            {
                MyEnd();
            }
            *currentStorage = 0;
        }

    }
    protected:
        double avgTime;
        double sigma = .3;
        Facility* machine = NULL;
        float transportTime = 0;

        int minTransportCount = 1;
        int *currentStorage;
        bool isTransportedByWorker = true;
};



#endif // OPERATION_H
