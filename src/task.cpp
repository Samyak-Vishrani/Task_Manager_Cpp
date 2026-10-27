#include "task.h"

Task::Task(int id, const std::string& title)
    : id(id), title(title), done(false) {}

int Task::getId() const {
    return id;
}

const std::string& Task::getTitle() const {
    return title;
}

bool Task::isDone() const {
    return done;
}

void Task::markDone() {
    done = true;
}
