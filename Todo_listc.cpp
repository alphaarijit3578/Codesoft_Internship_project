#include <iostream>
#include <vector>
#include <string>
class Task {
public:
    std::string description;
    bool completed;

    Task(std::string desc) : description(desc), completed(false) {}
};
class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& taskDescription) {
        tasks.emplace_back(taskDescription);
        std::cout << "Task added: " << taskDescription << std::endl;
        
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }
        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description 
                      << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << std::endl;
        }
    }

    void markTaskAsCompleted(int index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
            return;
        }
        tasks[index - 1].completed = true;
        std::cout << "Task marked as completed: " << tasks[index - 1].description << std::endl;
    }

    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
            return;
        }
        std::cout << "Task removed: " << tasks[index - 1].description << std::endl;
        tasks.erase(tasks.begin() + (index - 1));
    }
};

int main() {
    ToDoList todoList;
    int choice;
    std::string taskDescription;

    do {
        std::cout << "\nTo-Do List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Clear the newline character from the input buffer
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                int completeIndex;
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> completeIndex;
                todoList.markTaskAsCompleted(completeIndex);
                break;
            case 4:
                int removeIndex;
                std::cout << "Enter task number to remove: ";
                std::cin >> removeIndex;
                todoList.removeTask(removeIndex);
                break;
            case 5:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);
    return 0;
}