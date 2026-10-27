#include "task_manager.h"

#include <iostream>

void TaskManager::addTask(const std::string& title) {
    tasks.emplace_back(nextId++, title);
}

bool TaskManager::completeTask(int id) {
    for (Task& task : tasks) {
        if (task.getId() == id) {
            task.markDone();
            return true;
        }
    }
    return false;
}

bool TaskManager::removeTask(int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getId() == id) {
            tasks.erase(it);
            return true;
        }
    }
    return false;
}

void TaskManager::printTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks yet.\n";
        return;
    }
    for (const Task& task : tasks) {
        std::cout << "[" << (task.isDone() ? "x" : " ") << "] "
                  << task.getId() << ". " << task.getTitle() << "\n";
    }
}
