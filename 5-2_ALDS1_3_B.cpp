#include<iostream>
#include<queue>

using namespace std;

struct process
{
    string name;
    int process_time;
    int finish_time = 0;
};

int main()
{
    int process_num;
    int quantum;
    queue<process> processes;
    cin >> process_num >> quantum;
    for (int i = 0; i < process_num; i++)
    {
        process tmp;
        cin >> tmp.name >> tmp.process_time;
        processes.push(tmp);
    }
    
    int current_time = 0;
    queue<process> finished_processes;
    while (!processes.empty())
    {
        if (quantum >= processes.front().process_time)
        {
            current_time += processes.front().process_time;
            processes.front().finish_time = current_time;
            finished_processes.push(processes.front());
            processes.pop();
        }
        else
        {
            current_time += quantum;
            processes.front().process_time -= quantum;
            processes.push(processes.front());
            processes.pop();
        }
    }
    
    while (!finished_processes.empty())
    {
        cout << finished_processes.front().name << " " << finished_processes.front().finish_time << endl;
        finished_processes.pop();
    }
}