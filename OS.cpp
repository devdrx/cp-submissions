#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Process {
    int id, arrival, burst, completion = 0, waiting = 0, turnaround = 0, remaining = 0;
    bool done = false;
};

void hrrnScheduling(vector<Process> p) {
    cout << "\n========== HRRN (Non-Preemptive) ==========\n";
    int n = p.size(), completed = 0, time = 0;

    while (completed < n) {
        int idx = -1;
        double maxRR = -1;

        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].arrival <= time) {
                double rr = (double)(time - p[i].arrival + p[i].burst) / p[i].burst;
                if (rr > maxRR) {
                    maxRR = rr;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        time += p[idx].burst;
        p[idx].completion = time;
        p[idx].turnaround = p[idx].completion - p[idx].arrival;
        p[idx].waiting = p[idx].turnaround - p[idx].burst;
        p[idx].done = true;
        completed++;
    }

    cout << "Process\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &proc : p)
        cout << "P" << proc.id << "\t" << proc.arrival << "\t" << proc.burst << "\t"
             << proc.completion << "\t" << proc.turnaround << "\t" << proc.waiting << "\n";
}

void ljfNonPreemptive(vector<Process> p) {
    cout << "\n========== LJF (Non-Preemptive) ==========\n";
    int n = p.size(), completed = 0, time = 0;

    while (completed < n) {
        int idx = -1, maxBurst = -1;

        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].arrival <= time && p[i].burst > maxBurst) {
                maxBurst = p[i].burst;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        time += p[idx].burst;
        p[idx].completion = time;
        p[idx].turnaround = p[idx].completion - p[idx].arrival;
        p[idx].waiting = p[idx].turnaround - p[idx].burst;
        p[idx].done = true;
        completed++;
    }

    cout << "Process\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &proc : p)
        cout << "P" << proc.id << "\t" << proc.arrival << "\t" << proc.burst << "\t"
             << proc.completion << "\t" << proc.turnaround << "\t" << proc.waiting << "\n";
}

void ljfPreemptive(vector<Process> p) {
    cout << "\n========== LJF (Preemptive) ==========\n";
    int n = p.size(), completed = 0, time = 0;

    for (int i = 0; i < n; i++)
        p[i].remaining = p[i].burst;

    while (completed < n) {
        int idx = -1, maxRem = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0 && p[i].remaining > maxRem) {
                maxRem = p[i].remaining;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        p[idx].remaining--;

        if (p[idx].remaining == 0) {
            completed++;
            p[idx].completion = time + 1;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
        }

        time++;
    }

    cout << "Process\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &proc : p)
        cout << "P" << proc.id << "\t" << proc.arrival << "\t" << proc.burst << "\t"
             << proc.completion << "\t" << proc.turnaround << "\t" << proc.waiting << "\n";
}

int main() {
    // HRRN Test Case
    vector<Process> hrrnProcesses = {
        {0, 0, 8}, {1, 1, 4}, {2, 2, 2}, {3, 3, 1}
    };
    hrrnScheduling(hrrnProcesses);

    // LJF Non-Preemptive Test Case
    vector<Process> ljfNPProcesses = {
        {0, 0, 5}, {1, 2, 3}, {2, 3, 8}, {3, 4, 6}
    };
    ljfNonPreemptive(ljfNPProcesses);

    // LJF Preemptive Test Case
    vector<Process> ljfPProcesses = {
        {0, 0, 7}, {1, 2, 4}, {2, 4, 6}
    };
    ljfPreemptive(ljfPProcesses);

    return 0;
}
