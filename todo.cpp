#include <iostream>
#include <string>
#include <vector>

// Task structure
struct Task
{
    int id;
    std::string description;
    bool completed;
};

// Features
void addTask(std::vector<Task>& tasks);
void viewTask(std::vector<Task>& tasks);
void markTask(std::vector<Task>& tasks);
void deleteTask(std::vector<Task>& tasks);

int main()
{
    
    return 0;
}