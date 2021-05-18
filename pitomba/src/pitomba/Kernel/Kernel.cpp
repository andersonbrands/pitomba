
#include "Kernel.h"
#include "../Utils/Logger.h"


namespace pitomba {

    void Kernel::priorityAdd(Task* pTask) {
        TaskList::iterator iter;
        for (iter = tasks_.begin(); iter != tasks_.end(); ++iter) {
            const Task* pCurrentTask = (*iter);
            if (pCurrentTask->getPriority() > pTask->getPriority()) {
                break;
            }
        }
        tasks_.insert(iter, pTask);
    }

    void Kernel::execute() {
        Logger::getInstancePtr()->debug("Kernel executing");

        for (auto& task : tasks_) {
            task->start();
        }

        while (tasks_.size()) {
            TaskList::iterator iter;
            for (iter = tasks_.begin(); iter != tasks_.end(); ++iter) {
                Task* pTask = (*iter);
                if (!pTask->isFinished()) {
                    pTask->update();
                }
            }

            for (iter = tasks_.begin(); iter != tasks_.end();) {
                Task* pTask = (*iter);
                ++iter;
                if (pTask->isFinished()) {
                    tasks_.remove(pTask);
                    pTask = nullptr;
                }
            }
        }
    }

    void Kernel::addTask(Task* pTask) {
        pTask->initialize();
        priorityAdd(pTask);
    }

    void Kernel::suspendTask(Task* pTask) {
        if (std::find(tasks_.begin(), tasks_.end(), pTask) != tasks_.end()) {
            pTask->pause();
            tasks_.remove(pTask);
            pausedTasks_.push_back(pTask);
        }
    }

    void Kernel::resumeTask(Task* pTask) {
        if (std::find(pausedTasks_.begin(), pausedTasks_.end(), pTask) != pausedTasks_.end()) {
            pTask->resume();
            pausedTasks_.remove(pTask);

            priorityAdd(pTask);
        }
    }

    void Kernel::removeTask(Task* pTask) {
        if (std::find(tasks_.begin(), tasks_.end(), pTask) != tasks_.end()) {
            pTask->stop();
        }
    }

    void Kernel::killAllTasks() {
        for (auto iter = tasks_.begin(); iter != tasks_.end(); ++iter) {
            (*iter)->stop();
        }
    }

}