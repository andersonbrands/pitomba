
#include "Kernel.h"
#include "..\Utils\Logger.h"


namespace pitomba {

    Kernel::Kernel() {}

    Kernel::~Kernel() {}

    void Kernel::priorityAdd(Task* pTask) {
        TaskListIterator iter;
        for (iter = tasks_.begin(); iter != tasks_.end(); ++iter) {
            Task* pCurrentTask = (*iter);
            if (pCurrentTask->getPriority() > pTask->getPriority()) {
                break;
            }
        }
        tasks_.insert(iter, pTask);
    }

    void Kernel::execute() {
        Logger::getInstancePtr()->debug("Kernel executing");

        while (tasks_.size()) {

            TaskListIterator iter;
            for (iter = tasks_.begin(); iter != tasks_.end(); ++iter) {
                Task* pTask = (*iter);
                if (!pTask->canKill()) {
                    pTask->update();
                }
            }

            for (iter = tasks_.begin(); iter != tasks_.end();) {
                Task* pTask = (*iter);
                ++iter;
                if (pTask->canKill()) {
                    pTask->stop();
                    tasks_.remove(pTask);
                    pTask = 0;
                }
            }

        }

    }

    bool Kernel::addTask(Task* pTask) {
        bool started = pTask->start();

        if (started) {
            priorityAdd(pTask);
        }
        return started;
    }

    void Kernel::suspendTask(Task* pTask) {
        if (std::find(tasks_.begin(), tasks_.end(), pTask) != tasks_.end()) {
            pTask->onSuspend();
            tasks_.remove(pTask);
            pausedTasks_.push_back(pTask);
        }
    }

    void Kernel::resumeTask(Task* pTask) {
        if (std::find(pausedTasks_.begin(), pausedTasks_.end(), pTask) != pausedTasks_.end()) {
            pTask->onResume();
            pausedTasks_.remove(pTask);

            priorityAdd(pTask);
        }
    }

    void Kernel::removeTask(Task* pTask) {
        if (std::find(tasks_.begin(), tasks_.end(), pTask) != tasks_.end()) {
            pTask->setCanKill(true);
        }
    }

    void Kernel::killAllTasks() {
        for (TaskListIterator iter = tasks_.begin(); iter != tasks_.end(); ++iter) {
            (*iter)->setCanKill(true);
        }
    }

}