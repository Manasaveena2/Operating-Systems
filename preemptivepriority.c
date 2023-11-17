#include<stdio.h>

struct Process {
    int processID;
    int burstTime;
    int priority;
};

void priorityScheduling(struct Process processes[], int n) {
    // Sorting processes based on priority
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(processes[j].priority > processes[j + 1].priority) {
                // Swap the processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Displaying the schedule
    printf("Process\tBurst Time\tPriority\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].processID, processes[i].burstTime, processes[i].priority);
    }
}

int main() {
    // Example processes
    struct Process processes[] = {
        {1, 10, 3},
        {2, 6, 1},
        {3, 8, 2},
        {4, 7, 4}
    };

    int n = sizeof(processes) / sizeof(processes[0]);
    priorityScheduling(processes, n);

    return 0;
}
