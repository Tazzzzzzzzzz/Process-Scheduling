#include <stdio.h>
#include <stdlib.h>

int get_menu_choice(void);

int main()
{
int choice;
// Call get_menu_choice() function
choice = get_menu_choice();
//Displays choice
printf("You have chosen Menu #%d\n", choice);
printf("\n");

if(choice == 1){
	/*
 *Author: Mohammad Tasbeel Arif
 * StudentID:17067738
 *  Purpose: First come first serve is a algorithim that allocates the CPU's resources
 * 	based on when the process arived. 
 * 	Explanation: In FCSFS the first process that arrives is the first process that is completed.
 * 	It will run the first process that comes into it from the queue until it is finished. 
 * 	It will keep running the process until it is complete, and than the next one that comes
 *  first will be ran until completed.
 * 	Parameters: Parameters include integers such as Wait Time[wt],Total Completion Time[ctt]
 * 	Completion Time[ct],Arrival Time[at],Burst Time[bt],Turn Around Time[tat],Process ID[pid],
 * 	Number of processes[n],i,j,n are variables for the loops used.
 * 	Returns: It returns the burst time, wait time,arrival time, average waiting time, average turn around time
 * and completion time.
 * 	Advantages:The main advantage is the code is simple and easy to understand.
 * 	It is first come first served, so there is not alot of extra thought needed.
 * 	Disadvantages: The waiting time can be very long becuase it will wait until each process is complete
 * becuase it is non preemptive
 * It isn't very efficent. This is because small processes will take longer to complete if a longer
 * process comes first.
 */
	FILE*output_file;
	output_file=fopen("file.txt","w");
	//Sets all variables used
	int wt[10];
	int i,n,ctt=0,j,bt[10],at[10],ct[10];
	float awt, atat;
	int tat[10];
	int pid[10];
	//User input for number of processes. Sets 'n' as process number.
	printf("Enter the number of process: ");
	scanf("%d",&n);
	//User input for PID. Sets 'pid' as process id.
	printf("Enter Process ID ");
	for(i=0;i<n;i++){
		scanf("%d",&pid[i]);
	}
	//User input for burst time of each processes. Sets 'bt' as burst time.
	printf("Enter the burst time of the process: ");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
	}
	//User input for arrival time of each processes. Sets 'at' as burst time.
	printf("Enter the arrival time for each process: ");
	for(i=0;i<n;i++){
		scanf("%d",&at[i]);
	}
	ctt+=at[0];//Adds first arrival time to completion time total
	//Calculation for Completion Time(ct)
	for(i=0;i<n;i++){
		ct[i]=0; //Initalise array
		ctt+=bt[i];//Total completion time is burst time added on "n" times.
		ct[i]+=ctt;//completion time is first arrival time than every burst time after.
	}
	//Creates table heading for results.
	printf("PID\tAT\tBT\tTaT\tWT\tCT\n");
	//Calculation for Turn Around Time(tat)
	for(i=0;i<n;i++){
		tat[i]=0;//Intialise array
		tat[i]=ct[i]-at[i];//Turn around time = Completion time - Arrival time
	}
	//Calculation for Wait Time
	for(i=0;i<n;i++){
		wt[i]=0;
		for(j=0;j<i;j++){
			wt[i]=tat[i]-bt[i]; //Wait time = Turn around time - Burst time
		}
		//Adds all wait times
		awt+=wt[i];
		//Adds all turn around times
		atat+=tat[i];
		printf("%3d\t%3d\t%3d\t%3d\t%3d\t%3d\n",pid[i],at[i],bt[i],tat[i],wt[i],ct[i]);          
	}
	//Divides total turn around times by number of processes(n). Calculates Average. 
	atat/=n;
	//Divides total wait time by number of processes(n). Calculates Average.
	awt/=n;
	//Displays Average wait time and turn around time.
	printf("Average Turn Around Time: %f\nAverage WaitTime:%f",atat,awt);
	fprintf(output_file,"FCFSOutput\n");
	//Writes to output file the headers for output
	fprintf(output_file,"PID\tAT\tBT\tTaT\tWT\tCT\n");
	//Writes to outputfile data within a loop
	for(i=0;i<n;i++){
		fprintf(output_file,"%3d\t%3d\t%3d\t%3d\t%3d\t%3d\n",pid[i],at[i],bt[i],tat[i],wt[i],ct[i]);          
	}
	//Writes averages to file
	fprintf(output_file,"Average Turn Around Time: %f\nAverage WaitTime:%f",atat,awt);
	
}else if(choice == 2){
	/*
 *Author: Mohammad Tasbeel Arif
 * StudentID:17067738
 *  Purpose:To complete the shortest job first based on burst time.
 * 	Explanation: The code takes in all values needed. It than sorts the burst time with a bubble sort
 * 	in accending order. It takes into account the arrival time. If it is 0 it will be done first.
 * 	The code also adds the inital arrival time and the rest of the burst times. This is done to 
 * 	calculate completion time. This is than used to calculate the wait time, the turn around time,
 * 	and the averages.
 * 	Parameters: Parameters include integers such as Wait Time[wt],Total Completion Time[ctt]
 * 	Completion Time[ct],Arrival Time[at],Burst Time[bt],Turn Around Time[tat],Process ID[pid],
 * 	Number of processes[n],i,j,n are variables for the loops used. Temp can be used to sort the array
 * 	in the buble sort. It will hold the values temporarly.
 * 	Returns: It returns the burst time, wait time,arrival time, average waiting time, average turn around time
 * and completion time.
 * 	Advantages: It does the job with the shortest burst time first. This means smaller processes are done quickly.
 * 	Disadvantages: Processes with large burst time will have a longer wait time. This can lead to starvation.
 * 
 */
	FILE*output_file;
	output_file=fopen("file.txt","w");
	//Set all variables used
	int wt[10];
	int i,n,temp,j,bt[10],at[10],ct[10],pid[10];
	int ctt = 0;
	float awt, atat;
	int tat[10];
	//User input for number of processes. Sets 'n' as process number.
	printf("Enter the number of process: ");
	scanf("%d",&n);
	//User input for the process id of each process. Sets 'pid' as process id.
	printf("Enter process id: ");
	for(i=0;i<n;i++){
		scanf("%d",&pid[i]);
	}
	//User input for burst time of each processes. Sets 'bt' as burst time.
	printf("Enter the burst time of the process: ");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
	}
	//User input for arrival time of each processes. Sets 'at' as burst time.
	printf("Enter the arrival time for each process: ");
	for(i=0;i<n;i++){
		scanf("%d",&at[i]);
	}
	ctt+=at[0];//Adds first arrival time to completion time total
	//Calculation for Completion Time(ct)
	for(i=0;i<n;i++){
		ct[i]=0; //Initalise array
		ctt+=bt[i];//Total completion time is burst time added on "n" times.
		ct[i]+=ctt;//completion time is first arrival time than every burst time after.
	}
	//Creates a nested loop.
	for(i=0;i<n;i++){
		for(j=1;j<n-i-1;j++){
			//Bubble sort based on burst time.
			if(bt[j]>bt[j+1])
			{
				//Swaps if order isn't correct
				temp = bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				//Swaps arrival time so they are in order with burst times.
				temp = at[j];
				at[j]=at[j+1];
				at[j+1]=temp;
				//Swaps process id so they are in order with burst times.
				temp=pid[j];
				pid[j]=pid[j+1];
				pid[j+1]=temp;
			}
		}
	}
	//Creates table heading for results.
	printf("PID\tAT\tBT\tTaT\tWT\tCT\n");
	//Calculation for Turn Around Time(tat)
	for(i=0;i<n;i++){
		tat[i]=0;//Intialise array
		tat[i]=ct[i]-at[i];//Turn around time = Completion time - Arrival time
	}
	//Calculation for Wait Time
	for(i=0;i<n;i++){
		wt[i]=0;
		for(j=0;j<i;j++){
			wt[i]=tat[i]-bt[i]; //Wait time = Turn around time - Burst time
		}
		//Adds all wait times
		awt+=wt[i];
		//Adds all turn around times
		atat+=tat[i];
		printf("%3d\t%3d\t%3d\t%3d\t%3d\t%3d\n",pid[i],at[i],bt[i],tat[i],wt[i],ct[i]);          
	}
	//Divides total turn around times by number of processes(n). Calculates Average. 
	atat/=n;
	//Divides total wait time by number of processes(n). Calculates Average.
	awt/=n;
	//Displays Average wait time and turn around time.
	printf("Average Turn Around Time: %f\nAverage WaitTime:%f",atat,awt);
	fprintf(output_file,"RROutput\n");
	//Writes to output file the headers for output
	fprintf(output_file,"PID\tAT\tBT\tTaT\tWT\tCT\n");
	//Writes to outputfile data within a loop
	for(i=0;i<n;i++){
		fprintf(output_file,"%3d\t%3d\t%3d\t%3d\t%3d\t%3d\n",pid[i],at[i],bt[i],tat[i],wt[i],ct[i]);          
	}
	//Writes averages to file
	fprintf(output_file,"Average Turn Around Time: %f\nAverage WaitTime:%f",atat,awt);
}else if(choice == 3){
		/*
 *Author: Mohammad Tasbeel Arif
 * StudentID:17067738
 *  Purpose:The purpose of this code is to implement the round robin secheduling alogrithim.
 * 	Explanation: Round Robin gives every processes a fair share of cpu resources. Its preemptive processes
 *	where each processes is assigned a fixed slice of time.
 * 	Parameters: Parameters include integers such as Wait Time[wt],Total Completion Time[ctt]
 * 	Completion Time[ct],Arrival Time[at],Burst Time[bt],Turn Around Time[tat],Process ID[pid],
 * 	Number of processes[n],i,j,n are variables for the loops used. Temp can be used to sort the array
 * 	in the buble sort. It will hold the values temporarly. The time quantam is set by 'TQ'.
 * 	Returns: It returns the burst time, wait time,arrival time, average waiting time, average turn around time
 * and completion time.
 * 	Advantages: All the proccesses are given same priority. This is becuase of the time quantum.
 * 	There wont be starvation becuase no process is left behind. They all run when they arrive.
 * 	Disadvantages: Incorrect time quantams can lead to the cpu not being used efficently.
 * 	If the time quantam is shorter than the arrival times of some processes it can pretty much output
 *  like the FCFS.
 */
	FILE*output_file;
	output_file=fopen("file.txt","w");
	//Set all variables used
	int i,j,n,bt[10],at[10],pid[10],tq,wt[10],ct[10],tat[10],counter=0,total=0;
	float awt,atat;
	
	//User input for number of processes. Sets 'n' as process number.
	printf("Enter the number of process: ");
	scanf("%d",&n);
	//User input for the process id of each process. Sets 'pid' as process id.
	printf("Enter process id: ");
	for(i=0;i<n;i++){
		scanf("%d",&pid[i]);
	}
	//User input for burst time of each processes. Sets 'bt' as burst time.
	printf("Enter the burst time of the process: ");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
	}
	//User input for arrival time of each processes. Sets 'at' as burst time.
	printf("Enter the arrival time for each process: ");
	for(i=0;i<n;i++){
		scanf("%d",&at[i]);
	}
	//User input for time quantam. Sets "tq" as time quantam.
	printf("Enter the time quantam: ");
	scanf("%d",&tq);
	
	counter = 0;
	printf("%d",counter);
	
	if(at[i] <= tq && at[i]>0){
		total = total + at[i];
		at[i]=0;
		counter=1;
		
	}else if(at[i]>0){
		at[i]=at[i]-tq;
		total = total+tq;
	}
	//Creates table heading for results.
	printf("PID\tAT\tBT\tTaT\tWT\tCT\n");
	//Calculation for Turn Around Time(tat)
	for(i=0;i<n;i++){
		tat[i]=0;//Intialise array
		tat[i]=ct[i]-at[i];//Turn around time = Completion time - Arrival time
	}
	//Calculation for Wait Time
	for(i=0;i<n;i++){
		wt[i]=0;
		for(j=0;j<i;j++){
			wt[i]=tat[i]-bt[i]; //Wait time = Turn around time - Burst time
		}
		//Adds all wait times
		awt+=wt[i];
		//Adds all turn around times
		atat+=tat[i];
		printf("%3d\t%3d\t%3d\t%3d\t%3d\t%3d\n",pid[i],at[i],bt[i],tat[i],wt[i],ct[i]);          
	}
	//Divides total turn around times by number of processes(n). Calculates Average. 
	atat/=n;
	//Divides total wait time by number of processes(n). Calculates Average.
	awt/=n;
	//Displays Average wait time and turn around time.
	printf("Average Turn Around Time: %f\nAverage WaitTime:%f",atat,awt);
	//Writes headers to output file
	fprintf(output_file,"RoundRobinOutput\n");
	fprintf(output_file,"PID\tAT\tBT\tTaT\tWT\tCT\n");
	for(i=0;i<n;i++){
		fprintf(output_file,"%3d\t%3d\t%3d\t%3d\t%3d\t%3d\n",pid[i],at[i],bt[i],tat[i],wt[i],ct[i]);          

	}
}else if(choice == 4){
	exit(0);
}else{
	printf("error");
}
}


int get_menu_choice(void){
int selection = 0;
do
{
	//Displays menu in order of functions
printf("1 - First Come First Served (FCFS) Scheduler");
printf("\n2 - Shortest Job First (SJF) Secheduler");
printf("\n3 - Round Robin (RR) Scheduler");
printf("\n4 - Quit");
printf("\nEnter a selection: ");
//Checks for selection user input
scanf("%d", &selection );
} while ((selection < 1) || (selection > 4));
//returns selction choice
return selection;
}

 

