
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time = 0;
    int finish_time = 0;
    int waiting_time = 0;
    int turnaround_time = 0;
    int remaining_time = 0; // used for preemptive SJF
    bool completed = false;
    bool started = false;
};

// Utility function to print scheduling results
void printSchedule(const string& algorithmName, const vector<Process>& processes) {
    cout << "\n--- " << algorithmName << " Scheduling ---\n";
    cout << "PID\tArrival\tBurst\tStart\tFinish\tWaiting\tTurnaround\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t" 
             << p.arrival_time << "\t" 
             << p.burst_time << "\t" 
             << p.start_time << "\t" 
             << p.finish_time << "\t" 
             << p.waiting_time << "\t" 
             << p.turnaround_time << "\n";
    }
}

// FCFS Scheduling
vector<Process> fcfsScheduling(vector<Process> processes) {
    // Sort processes by arrival time.
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrival_time < b.arrival_time;
    });
    
    int time = 0;
    for (auto &p : processes) {
        if (time < p.arrival_time)
            time = p.arrival_time;
        p.start_time = time;
        p.finish_time = time + p.burst_time;
        p.waiting_time = p.start_time - p.arrival_time;
        p.turnaround_time = p.finish_time - p.arrival_time;
        time = p.finish_time;
    }
    // Optionally sort back by PID for output consistency.
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.pid < b.pid;
    });
    return processes;
}

// SJF Non-preemptive Scheduling
vector<Process> sjfNonPreemptive(vector<Process> processes) {
    int n = processes.size();
    // Mark all processes as not completed.
    for (auto &p : processes)
        p.completed = false;
    
    int complete = 0, time = 0;
    while (complete < n) {
        // Find all processes that have arrived and are not completed.
        vector<Process*> readyQueue;
        for (auto &p : processes) {
            if (p.arrival_time <= time && !p.completed)
                readyQueue.push_back(&p);
        }
        
        if (!readyQueue.empty()) {
            // Pick the process with the smallest burst time.
            auto currentIt = min_element(readyQueue.begin(), readyQueue.end(), [](Process* a, Process* b) {
                return a->burst_time < b->burst_time;
            });
            Process* current = *currentIt;
            current->start_time = time;
            current->finish_time = time + current->burst_time;
            current->waiting_time = current->start_time - current->arrival_time;
            current->turnaround_time = current->finish_time - current->arrival_time;
            current->completed = true;
            complete++;
            time = current->finish_time;
        } else {
            // If no process has arrived, increment time.
            time++;
        }
    }
    
    // Sort processes back by PID for printing.
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.pid < b.pid;
    });
    return processes;
}

// SJF Preemptive Scheduling (Shortest Remaining Time First)
vector<Process> sjfPreemptive(vector<Process> processes) {
    int n = processes.size();
    // Initialize each process's remaining time and flags.
    for (auto &p : processes) {
        p.remaining_time = p.burst_time;
        p.started = false;
        p.completed = false;
    }
    
    int complete = 0, time = 0;
    while (complete < n) {
        // Get all processes that have arrived and are still incomplete.
        vector<Process*> readyQueue;
        for (auto &p : processes) {
            if (p.arrival_time <= time && p.remaining_time > 0)
                readyQueue.push_back(&p);
        }
        
        if (!readyQueue.empty()) {
            // Select process with the smallest remaining time.
            auto currentIt = min_element(readyQueue.begin(), readyQueue.end(), [](Process* a, Process* b) {
                return a->remaining_time < b->remaining_time;
            });
            Process* current = *currentIt;
            if (!current->started) {
                current->start_time = time;
                current->started = true;
            }
            // Execute process for one time unit.
            current->remaining_time--;
            time++;
            // If the process is finished, record finish time and compute waiting/turnaround.
            if (current->remaining_time == 0) {
                current->finish_time = time;
                current->turnaround_time = current->finish_time - current->arrival_time;
                current->waiting_time = current->turnaround_time - current->burst_time;
                current->completed = true;
                complete++;
            }
        } else {
            // If no process is ready, simply increment time.
            time++;
        }
    }
    
    // Sort processes by PID for final output.
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.pid < b.pid;
    });
    return processes;
}

int main() {
    // Example process list
    vector<Process> processes_data = {
        {1, 0, 8},
        {2, 1, 4},
        {3, 2, 9},
        {4, 3, 5}
    };

    // FCFS Scheduling
    vector<Process> processes_fcfs = fcfsScheduling(processes_data);
    printSchedule("FCFS", processes_fcfs);

    // SJF Non-preemptive Scheduling
    vector<Process> processes_sjf_np = sjfNonPreemptive(processes_data);
    printSchedule("SJF Non-preemptive", processes_sjf_np);

    // SJF Preemptive Scheduling
    vector<Process> processes_sjf_p = sjfPreemptive(processes_data);
    printSchedule("SJF Preemptive", processes_sjf_p);

    return 0;
}
