#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Task structure
struct Task
{
    string name;
    string description;
    bool status;
};

// Features
void addTask(vector<Task>& tasks);
void viewTask(vector<Task>& tasks);
void markTask(vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);

int main()
{
    vector<Task> tasks;
    int option;

    // Display
    do
    {
        cout << "To-do List:" << endl;
        viewTask(tasks);
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task Completed" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
            case 1:
                addTask(tasks);
                break;
            case 2:
                markTask(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting..." << endl;
            default:
                cout << "Invalid choice, Please try again" << endl;
        }
    }
    while (option != 5);

    return 0;
}

void viewTask(vector<Task>& tasks)
{
    for (int i = 0; i < tasks.size(); i++)
        {
            cout << i + 1 << ") " << tasks[i].name << " - " << (tasks[i].status ? "Completed" : "Pending") << endl;
            cout << "   " << tasks[i].description << endl;
        }
}