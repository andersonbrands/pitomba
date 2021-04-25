#ifndef DUMMY_TASK_H_
#define DUMMY_TASK_H_


#include "../pitomba/Kernel/Task.h"


using namespace pitomba;

class DummyTask : public Task {

private:
    unsigned int count = 0;

protected:
    void onUpdate() final;

public:
    DummyTask(const unsigned int priority);
    virtual ~DummyTask();

};

#endif // DUMMY_TASK_H_