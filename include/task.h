#ifndef TASK_H
#define TASK_H

#include <string>

// A single to-do item.
class Task {
public:
    Task(int id, const std::string& title);

    int getId() const;
    const std::string& getTitle() const;
    bool isDone() const;
    void markDone();

private:
    int id;
    std::string title;
    bool done;
};

#endif // TASK_H
