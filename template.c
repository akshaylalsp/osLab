#include <stdio.h>

struct process_details{
    char name[10];
    int arr;
    int bur;
    int wait;
    int ta;
}processes[50],temp;//processes is array for storing [50] process_details
                    //temp is for swapping purpose

void read(int n){
    printf("\nenter process id, arrival time, burst time : \n");
    for(int i=0;i<n;i++){
        scanf("\n%s%d%d",&processes[i].name,&processes[i].arr,&processes[i].bur);
    }

    //sorting with its arrival time
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(processes[j].arr>processes[j+1].arr){
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
            //sort again based on lowest burst time
            else if(processes[j].arr == processes[j+1].arr && processes[j].bur > processes[j+1].bur){
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

void display(int n){
    printf("\n   process id\tarr_time\tburst _time\twait_time\tta_time");
    for(int i=0;i<n;i++){
        printf("\n\t%s\t\t%d\t\t%d\t\t%d\t\t%d",processes[i].name,processes[i].arr,processes[i].bur,processes[i].wait,processes[i].ta);
    }
}

void calc_wt_ta(int n){
    processes[0].wait = 0;
    for(int i=1;i<n;i++){
        processes[i].wait = processes[i-1].wait + processes[i-1].bur;
    }
    for(int i=0;i<n;i++){
        processes[i].ta = processes[i].wait + processes[i].bur;
    }
}

void main(){
    int n;
    printf("enter no of process : ");
    scanf("%d",&n);
    read(n);
    calc_wt_ta(n);
    display(n);

    printf("\n");
}
