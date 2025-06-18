#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Task {
    string description;
    bool completed;
};


void displayMenu() {
    cout << "\n==============================\n";
    cout << "       TO-DO LIST MANAGER      \n";
    cout << "==============================\n";
    cout << "1 Add Task\n";
    cout << "2 View Tasks\n";
    cout << "3 Mark Completed \n";
    cout << "4 Remove Task \n";
    cout << "5 Exit \n";
    cout << "==============================\n";
    cout << "Choose an option: ";
}
void viewTasks(const vector<Task>& tasks) {
    cout << "\n CURRENT TASKS \n";
    if (tasks.empty()) {
        cout << " No tasks yet! Add some. \n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << setw(20) << left << tasks[i].description
             << " [" << (tasks[i].completed ? " Completed" : " Pending") << "]\n";
    }
}

void addTask(vector<Task>& tasks, const string& desc) {
    tasks.push_back({desc, false});
    cout << " Task added: " << desc << endl;
}

void completeTask(vector<Task>& tasks, int index) {
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << " Task marked as completed: " << tasks[index - 1].description << endl;
    } else {
        cout << " Invalid task number.\n";
    }
}

void removeTask(vector<Task>& tasks, int index) {
    if (index > 0 && index <= tasks.size()) {
        cout << " Task removed: " << tasks[index - 1].description << endl;
        tasks.erase(tasks.begin() + index - 1);
    } else {
        cout << " Invalid task number.\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice, index;
    string desc;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << " Enter task description: ";
                getline(cin, desc);
                addTask(tasks, desc);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                cout << " Enter task number to mark as completed: ";
                cin >> index;
                completeTask(tasks, index);
                break;
            case 4:
                cout << " Enter task number to remove: ";
                cin >> index;
                removeTask(tasks, index);
                break;
            case 5:
                cout << " Exiting... Have a productive day!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}