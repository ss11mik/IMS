#ifndef OPERATION_H
#define OPERATION_H

#include <simlib.h>
#include <queue>


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

        if(minTransportCount==*currentTransports)
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

        MyEnd();
    }
    protected:
        double avgTime;
        double sigma = .3;
        Facility* machine = NULL;
        float transportTime = 0;

        int minTransportCount = 1;
        int *currentTransports = &minTransportCount;
        bool isTransportedByWorker = true;
};



#endif // OPERATION_H
