#ifndef OPERATION_H
#define OPERATION_H

#include <simlib.h>

class Operation: public simlib3::Process {

public:

    virtual void MyConstructor()=0;
    virtual void MyEnd()=0;
    void Activate();
    void Behavior() {
        MyConstructor();
        //seize stroj & cloveka
        //TODO exp or sth
        Wait(avgTime);
        //release stroj
        if(transportTime!=0)
        {
            Wait(transportTime);//todo: delta
        }
        //release cloveka
        MyEnd();
    }
    protected:
        float avgTime;
        float delta;
        int employesStartIndex = 0;
        int employees = 1;
        float transportTime = 0;
};

#endif // OPERATION_H