
#ifndef KERNEL_H_
#define KERNEL_H_

#include <list>
#include "Task.h"


namespace pitomba {

    class Kernel {

    private:
        using TaskList = std::list<Task*>;

        TaskList tasks_;
        TaskList pausedTasks_;

        void priorityAdd(Task* pTask);

    public:
        Kernel() = default;
        virtual ~Kernel() = default;

        void execute();

        void addTask(Task* pTask);
        void suspendTask(Task* task);
        void resumeTask(Task* task);
        void removeTask(Task* task);
        void killAllTasks();

        bool hasTasks() const {
            return (tasks_.size() != 0);
        }
    };

}

#endif // KERNEL_H_