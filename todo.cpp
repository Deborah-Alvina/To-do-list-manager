#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Task structure
struct Task
{
    string name;
    string description;
    bool status;
};

// Functions
void addTask(vector<Task>& tasks);
void viewTask(vector<Task>& tasks);
void markTask(vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void saveTasks(vector<Task>& tasks, string& filename);
void loadTasks(vector<Task>& tasks, string& filename);

int main()
{
    vector<Task> tasks;
    int option;
    string filename = "todo.txt";
    loadTasks(tasks, filename);

    do
    {
        // Display
        cout << endl << "To-do List:" << endl;
        viewTask(tasks);
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task Completed" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << endl << "Enter your choice: ";
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
                saveTasks(tasks, filename);
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, Please try again" << endl;
        }
    }
    while (option != 4);

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
    getline(cin, description);
    tasks.push_back({name, description, false});
    cout << name << " added to tasks." << endl;
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
        cout << tasks[num - 1].name << " completed." << endl;
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
        cout << name << " deleted." << endl;
    }
    else
    {
        cout << "Invalid task number." << endl;
    }
}

// Saves tasks to file
void saveTasks(vector<Task>& tasks, string& filename)
{
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    for (auto& task : tasks)
    {
        file << task.name << endl;
        file << task.description << endl;
        file << task.status << endl;
    }
    file.close();
}

// Loads tasks from file
void loadTasks(vector<Task>& tasks, string& filename)
{
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    string name;
    string description;
    bool status;
    while (getline(inFile, name))
    {
        getline(inFile, description);
        inFile >> status;
        inFile.ignore(); 
        tasks.push_back({name, description, status});
    }
    inFile.close();
}