#ifndef DUMMY_TASK_H_
#define DUMMY_TASK_H_


#include "..\pitomba\Kernel\Task.h"
#include "..\pitomba\Utils\Timer.h"


using namespace pitomba;

class DummyTask : public Task {

private:
    unsigned int count = 0;

public:
    DummyTask(const unsigned int priority);
    virtual ~DummyTask();

    virtual void update();

};

#endif // DUMMY_TASK_H_