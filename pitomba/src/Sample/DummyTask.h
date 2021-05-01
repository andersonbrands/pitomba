#ifndef DUMMY_TASK_H_
#define DUMMY_TASK_H_


#include "../pitomba/Kernel/Task.h"


using namespace pitomba;

class DummyTask : public Task {

protected:
    void onUpdate() final;

public:
    explicit DummyTask(const unsigned int priority);
    ~DummyTask() final = default;

};

#endif // DUMMY_TASK_H_