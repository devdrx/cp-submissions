#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int priority;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

// Priority Scheduling (Preemptive)
void priorityPreemptive(vector<Process> processes) {
    int time = 0, completed = 0;
    int n = processes.size();
    for (auto &p : processes) p.remainingTime = p.burstTime;

    cout << "\n--- Priority Scheduling (Preemptive) ---\n";
    while (completed < n) {
        int idx = -1, highest = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && processes[i].remainingTime > 0) {
                if (processes[i].priority < highest || (processes[i].priority == highest && processes[i].arrivalTime < processes[idx].arrivalTime)) {
                    highest = processes[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            processes[idx].remainingTime--;
            if (processes[idx].remainingTime == 0) {
                processes[idx].completionTime = time + 1;
                processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
                processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;
                completed++;
            }
        }
        time++;
    }

    for (auto p : processes) {
        cout << "P" << p.pid << ": CT=" << p.completionTime << ", TAT=" << p.turnaroundTime << ", WT=" << p.waitingTime << "\n";
    }
}

// Priority Scheduling (Non-Preemptive)
void priorityNonPreemptive(vector<Process> processes) {
    int time = 0, completed = 0;
    int n = processes.size();
    vector<bool> isDone(n, false);

    cout << "\n--- Priority Scheduling (Non-Preemptive) ---\n";
    while (completed < n) {
        int idx = -1, highest = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!isDone[i] && processes[i].arrivalTime <= time) {
                if (processes[i].priority < highest || (processes[i].priority == highest && processes[i].arrivalTime < processes[idx].arrivalTime)) {
                    highest = processes[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            time = max(time, processes[idx].arrivalTime);
            time += processes[idx].burstTime;
            processes[idx].completionTime = time;
            processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
            processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;
            isDone[idx] = true;
            completed++;
        } else {
            time++;
        }
    }

    for (auto p : processes) {
        cout << "P" << p.pid << ": CT=" << p.completionTime << ", TAT=" << p.turnaroundTime << ", WT=" << p.waitingTime << "\n";
    }
}

// Round Robin Scheduling
void roundRobin(vector<Process> processes, int quantum) {
    int time = 0;
    int n = processes.size();
    queue<int> q;
    vector<bool> inQueue(n, false);

    for (auto &p : processes) p.remainingTime = p.burstTime;

    cout << "\n--- Round Robin Scheduling (Quantum = " << quantum << ") ---\n";

    int completed = 0;
    while (completed < n) {
        for (int i = 0; i < n; ++i)
            if (processes[i].arrivalTime <= time && !inQueue[i] && processes[i].remainingTime > 0)
                q.push(i), inQueue[i] = true;

        if (!q.empty()) {
            int idx = q.front();
            q.pop();
            int execTime = min(quantum, processes[idx].remainingTime);
            time = max(time, processes[idx].arrivalTime);
            time += execTime;
            processes[idx].remainingTime -= execTime;

            // Add newly arrived processes
            for (int i = 0; i < n; ++i)
                if (processes[i].arrivalTime <= time && !inQueue[i] && processes[i].remainingTime > 0)
                    q.push(i), inQueue[i] = true;

            if (processes[idx].remainingTime == 0) {
                processes[idx].completionTime = time;
                processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
                processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;
                completed++;
            } else {
                q.push(idx);
            }
        } else {
            time++;
        }
    }

    for (auto p : processes) {
        cout << "P" << p.pid << ": CT=" << p.completionTime << ", TAT=" << p.turnaroundTime << ", WT=" << p.waitingTime << "\n";
    }
}

// Main function
int main() {
    vector<Process> processes = {
        {1, 0, 5, 0, 2},
        {2, 1, 3, 0, 1},
        {3, 2, 8, 0, 4},
        {4, 3, 6, 0, 3}
    };

    priorityPreemptive(processes);
    priorityNonPreemptive(processes);
    roundRobin(processes, 2); // Quantum = 2

    return 0;
}
