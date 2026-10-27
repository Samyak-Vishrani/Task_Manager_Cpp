#include <iostream>
#include <limits>
#include <string>

#include "task_manager.h"

int main() {
    TaskManager manager;

    while (true) {
        std::cout << "\n=== Mini Task Manager ===\n"
                  << "1. Add task\n"
                  << "2. List tasks\n"
                  << "3. Complete task\n"
                  << "4. Remove task\n"
                  << "5. Quit\n"
                  << "Choose: ";

        int choice;
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            std::cout << "Task title: ";
            std::string title;
            std::getline(std::cin, title);
            manager.addTask(title);
        } else if (choice == 2) {
            manager.printTasks();
        } else if (choice == 3 || choice == 4) {
            std::cout << "Task id: ";
            int id = 0;
            std::cin >> id;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            bool ok = (choice == 3) ? manager.completeTask(id) : manager.removeTask(id);
            if (!ok) std::cout << "No task with id " << id << ".\n";
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Unknown option.\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
