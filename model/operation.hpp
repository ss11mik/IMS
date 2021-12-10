#ifndef OPERATION_H
#define OPERATION_H

#include <simlib.h>

class Operation: public simlib3::Process {

public:

    virtual void MyConstructor()=0;
    virtual void MyEnd()=0;
    virtual bool CanTransport()
    {
        return true;
    }
    void Behavior() {
        MyConstructor();

        //seize stroj & cloveka
        if(employe1!=NULL)
            employe1->Seize(this);
        if(employe2!=NULL)
            employe2->Seize(this);
        if(machine!=NULL)
            machine->Seize(this);

        //TODO exp or sth
        auto time = Normal(avgTime,sigma);
        Wait(time);

        //release stroj
        if(machine!=NULL)
            machine->Release(this);

        if(minTransportCount==*currentTransports)
        {
            //transport
            if(transportTime!=0)
            {
                Wait(transportTime);//todo: delta
            }
        }
        

        //release cloveka
        if(employe1!=NULL)
            employe1->Release(this);
        if(employe2!=NULL)
            employe2->Release(this);

        MyEnd();
    }
    protected:
        float avgTime;
        float sigma;
        Facility* employe1, *employe2 = NULL;
        Facility* machine = NULL;
        float transportTime = 0;

        int minTransportCount = 1;
        int *currentTransports = &minTransportCount;
};

#endif // OPERATION_H
