#include <stdio.h>

struct Process {
    int processID;
    int burstTime;
    int remainingTime;
};

void roundRobinScheduling(struct Process processes[], int n, int timeQuantum) {
    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                
                int executionTime = (processes[i].remainingTime < timeQuantum) ? processes[i].remainingTime : timeQuantum;

                printf("Time %d: Process %d (Executed for %d units)\n", currentTime, processes[i].processID, executionTime);

                processes[i].remainingTime -= executionTime;
                currentTime += executionTime;

               
                if (processes[i].remainingTime == 0) {
                    completedProcesses++;
                }
            }
        }
    }
}

int main() {
   
    struct Process processes[] = {
        {1, 10, 10},
        {2, 5, 5},
        {3, 8, 8},
        {4, 2, 2}
    };

    int n = sizeof(processes) / sizeof(processes[0]);
    int timeQuantum = 2; 

    
    roundRobinScheduling(processes, n, timeQuantum);

    return 0;
}
