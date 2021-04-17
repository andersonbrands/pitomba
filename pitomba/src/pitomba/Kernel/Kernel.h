
#ifndef KERNEL_H_
#define KERNEL_H_

#include <list>
#include "Task.h"


namespace pitomba {

    class Kernel {

    private:
        typedef std::list<Task*> TaskList;
        typedef std::list<Task*>::iterator TaskListIterator;

        TaskList tasks_;
        TaskList pausedTasks_;

        void priorityAdd(Task* pTask);
    protected:

    public:
        Kernel();
        virtual ~Kernel();

        void execute();

        void addTask(Task* pTask);
        void suspendTask(Task* task);
        void resumeTask(Task* task);
        void removeTask(Task* task);
        void killAllTasks();

        bool hasTasks() {
            return (tasks_.size() != 0);
        }
    };

}

#endif // KERNEL_H_