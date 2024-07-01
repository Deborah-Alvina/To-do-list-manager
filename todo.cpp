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

    do
    {
        // Display
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

        // Menu
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

// Displays current tasks
void viewTask(vector<Task>& tasks)
{
    for (int i = 0; i < tasks.size(); i++)
        {
            cout << i + 1 << ") " << tasks[i].name << " - " << (tasks[i].status ? "Completed" : "Pending") << endl;
            cout << "   " << tasks[i].description << endl;
        }
}

// Adds a task
void addTask(vector<Task>& tasks)
{
    string name;
    string description;
    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, description);
    tasks.push_back({name, description, false});
    cout << name << "added to tasks." << endl;
}

// Marks a task as completed
void markTask(vector<Task>& tasks)
{
    int num;
    cout << "Enter the task number to be marked as completed: ";
    cin >> num;
    if (num > 0 && num <= tasks.size())
    {
        tasks[num - 1].status = true;
        cout << tasks[num - 1].name << "completed." << endl;
    }
    else
    {
        cout << "Invalid task number." << endl;
    }
}

// Deletes a task 
void deleteTask(vector<Task>& tasks)
{
    int num;
    cout << "Enter the task number to be deleted: ";
    cin >> num;
    if (num > 0 && num <= tasks.size())
    {
        string name = tasks[num - 1].name;
        tasks.erase(tasks.begin() + num - 1);
        cout << name << "deleted." << endl;
    }
    else
    {
        cout << "Invalid task number." << endl;
    }
}