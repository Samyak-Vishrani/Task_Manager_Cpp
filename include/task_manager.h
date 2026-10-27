#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <string>
#include <vector>

#include "task.h"

// Owns the list of tasks and the operations on it.
class TaskManager {
public:
    void addTask(const std::string& title);
    bool completeTask(int id);
    bool removeTask(int id);
    void printTasks() const;

private:
    std::vector<Task> tasks;
    int nextId = 1;
};

#endif // TASK_MANAGER_H
