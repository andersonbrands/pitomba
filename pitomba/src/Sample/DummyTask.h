#ifndef DUMMY_TASK_H_
#define DUMMY_TASK_H_


#include "..\pitomba\Kernel\Task.h"


using namespace pitomba;

class DummyTask : public Task {

private:
    unsigned int count = 0;

public:
    DummyTask(const unsigned int priority);
    virtual ~DummyTask();

    virtual bool	start();
    virtual void 	onSuspend();
    virtual void 	update();
    virtual void 	onResume();
    virtual void 	stop();
};

#endif // DUMMY_TASK_H_