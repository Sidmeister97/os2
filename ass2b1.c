//Roll No : 33158
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int partition (int arr[], int low, int high); 
void quickSort(int arr[], int low, int high); 
void swap(int* a, int* b); 
int main(int argc, char *argv[])
{
           int A[20];
           int n,i,j,k,t;
           int pipefd[2];
           pid_t cpid;
           char *buf[20];

           printf("Enetr the no of elements in array :\t");
           scanf("%d",&n);						//Take the number of elements from user
           printf("Enter the elements :\t");
           for(i=0;i<n;i++)
           {
                scanf("%d",&A[i]);				//Take elements one by one
           }
           printf("Elements are :\t");
           for(int i=0;i<n;i++)
           {
               printf("%d\t",A[i]);
           }
           for(i=0;i<=(n+1);i++)
           {
               buf[i]=(char*)malloc(10);		
           }
               
           cpid = fork();					
  		   if(cpid==0)				//this is child process
           {
           		printf("THIS IS CHILD PROCESS------CHILD ID   : %d\n",getpid());	//shows child id
                printf("MY PARENT ID IS %d\n",getppid());			//shows parent id
                printf("\n\n------CHILD PROCESS START-----\n\n");
                buf[0]="./2b";						//to store filename at 0th location
                for(i=1;i<=n;i++)
                {
                	sprintf(buf[i],"%d",A[i-1]);
                }
                printf("CONVERSION DONE");
                buf[n+1]=NULL;    			//terminate that arrray
                execv("./2b",buf);			//send that array to the new process
                printf("\n------CHILD PROCESS ENDS-----\n");
            }
            else if(cpid==-1)
            {
                             
            	printf("FAILED TO FORK");
            }  
            else if(cpid>0)   //this is parent process
            {
                             
                 printf("\nIN THE PARENT PROCESS....\n");
                 printf("THIS IS THE PARENT PROCESS-----PARENT ID   : %d\n",(int)getpid());
                 printf("\n\n------PARENT PROCESS START-----\n\n");
                 quickSort(A, 0, n-1);
                 printf("\n\nEntered integers in sorted manner are :- \n");
	             for(i=0;i<n;i++)
	             {
		              printf("%d\n",A[i]);
	             }
	             wait(NULL);		//wait for the parent process
             }
                  
            return 0;               
}   

            
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high- 1; j++) 
	{ 
		
		if (arr[j] <= pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 


void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
	
		int pi = partition(arr, low, high); 

		
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
}   

void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
}
