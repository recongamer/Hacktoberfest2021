#include<iostream> 
using namespace std; 

void calcTimes(int processID[], int n, int burstTime[], int timeSlice);
void calcWaitingTime(int n, int bt[], int wt[], int quantum);
void calcTurnAroundTime(int n, int bt[], int wt[], int tat[]);

int main() { 
    int n;
    cout << "Enter number of processes: "; 
    cin >> n; 
    int processID[n];
    int burstTime[n];
    for(int i = 0; i < n; ++i) {
        processID[i] = i + 1;
        cout << "Enter burst time of process " << i + 1 << ": "; 
        cin >> burstTime[i];
    }

    cout << "Enter time slice: ";  
    int timeSlice;
    cin >> timeSlice;
    calcTimes(processID, n, burstTime, timeSlice); 
} 

void calcTimes(int processID[], int n, int burstTime[], int timeSlice) { 
    int wt[n], tat[n], totalWT = 0, totalTAT = 0;   
    calcWaitingTime(n, burstTime, wt, timeSlice);   
    calcTurnAroundTime(n, burstTime, wt, tat); 
  
    cout << "\nRound Robin Scheduling Information:\n\n";

    cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time" << "\tCompletion Time\n"; 
  
    for (int i = 0; i < n; i++) { 
        totalWT = totalWT + wt[i]; 
        totalTAT = totalTAT + tat[i]; 
        cout << " " << i+1 << "\t\t" << burstTime[i] << "\t " << wt[i] << "\t\t " << tat[i] << "\t\t\t" << tat[i] << endl; 
    } 
  
    cout << "\n";
    cout << "Average Waiting Time = " << (float)totalWT / (float)n << "\n"; 
    cout << "Average Turn Around Time = " << (float)totalTAT / (float)n << "\n"; 
} 

void calcWaitingTime(int n, int burstTime[], int wt[], int timeSlice) { 
    int bt[n]; 
    for (int i = 0 ; i < n ; i++) {
        bt[i] =  burstTime[i]; 
    }
  
    int t = 0;    
    while (true) { 
        bool done = true; 
        for (int i = 0 ; i < n; i++) { 
            if (bt[i] > 0) { 
                done = false;   
                if (bt[i] > timeSlice) { 
                    t += timeSlice; 
                    bt[i] -= timeSlice; 
                } else {
                    t = t + bt[i];   
                    wt[i] = t - burstTime[i];   
                    bt[i] = 0; 
                } 
            } 
        } 
  
        if (done) {
          break; 
        }
    } 
} 
  
void calcTurnAroundTime(int n, int burstTime[], int wt[], int tat[]) { 
    for (int i = 0; i < n ; i++) {
        tat[i] = burstTime[i] + wt[i]; 
    }
} 
