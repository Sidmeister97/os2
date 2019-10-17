//Roll No : 33158

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
void merge(int A[50],int low,int mid,int high,int n);
void merge_sort(int A[50],int low,int high,int n);
int partition (int arr[], int low, int high); 
void quickSort(int arr[], int low, int high); 

int main()
{ 
     pid_t childpid;
    int a[50];
        int n,i,ch;
       // printf("THIS IS THE PARENT PROCESS-----PARENT ID   : %d\n",(int)getpid());
        printf("ENTER THE NUMBER OF INTEGERS TO BE ADDED");
        scanf("%d",&n);
     
        for(i=0;i<n;i++)
        {
                printf("\nENTER THE NUMBERS  : ");
                scanf("%d",&a[i]);
        
        }
        
        printf("\nINPUT PHASE DONE.... \n----DISPLAY NUMBERS ---");
        
        
        for(i=0;i<n;i++)
        {
                printf("\t%d",a[i]);
             
        }
        printf("\n1.ZOMBIE PROCESS\n2.ORPHAN PROCESS\nENTER METHOD  : ");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1:
                           childpid=fork();
                            if(childpid==0)
                             {
                                printf("THIS IS CHILD PROCESS------CHILD ID   : %d\n",getpid());
                                printf("MY PARENT IS %d  is my parent id \n",getppid());
                                printf("\n\n------CHILD PROCESS START-----\n\n");
                                 merge_sort(a,0,n-1,n);
                                printf("\n\nMerge sort :- \n");
	                        for(i=0;i<n;i++)
	                        {

		                printf("%d\t",a[i]);

	                        }
	                        sleep(5);
                                printf("\n------CHILD PROCESS ENDS-----\n");
                             }
                              
                             else if(childpid==-1)
                             {
                             
                                printf("FAILED TO FORK");
                             }  
                             else if(childpid>0)//INSIDE PARENT pROCESS
                             {
                             printf("\nIN THE PARENT PROCESS....\n");
                             printf("THIS IS THE PARENT PROCESS-----PARENT ID   : %d\n",(int)getpid());
                               printf("\n\n------PARENT PROCESS START-----\n\n");
                                quickSort(a, 0, n-1);
                                printf("\n\nQuick sort :- \n");
	                        for(i=0;i<n;i++)
	                        {
		                        printf("%d\t",a[i]);
	                        }
                             sleep(20);
                             system("ps -elf | grep a.out");//PARENT PROCEES SLEEPS AND IGNORES RETURN SIGNAL OF CHILD THERBY CREATING ZOMBIE PROCESS
                             printf("\n\n------PARENT PROCESS ENDS-----\n\n");
                             }
                    break;
                    
                 case 2:    childpid=fork();
                            if(childpid==0)
                             {
                                printf("THIS IS CHILD PROCESS------CHILD ID   : %d\n",getpid());
                                printf("MY PARENT IS %d  is my parent id \n",getppid());
                                printf("\n\n------CHILD PROCESS START-----\n\n");
                                 merge_sort(a,0,n-1,n);
                                printf("\n\nMerge sort :- \n");
	                        for(i=0;i<n;i++)
	                        {
		                printf("%d\t",a[i]);
	                        }
	                        system("wait");
	                        system("ps -elf | grep a.out");
                                printf("\n------CHILD PROCESS ENDS-----\n");
                             }
                              
                             else if(childpid==-1)
                             {
                             
                                printf("FAILED TO FORK");
                             }  
                             else if(childpid>0)//INSIDE PARENT pROCESS
                             {
                             printf("\nIN THE PARENT PROCESS....\n");
                             printf("THIS IS THE PARENT PROCESS-----PARENT ID   : %d\n",(int)getpid());
                               printf("\n\n------PARENT PROCESS START-----\n\n");
                                quickSort(a, 0, n-1);
                                printf("\n\nQuick sort :- \n");
	                        for(i=0;i<n;i++)
	                        {
		                        printf("%d\t",a[i]);
	                        }
                             
                             //PARENT PROCEES SLEEPS AND IGNORES RETURN SIGNAL OF CHILD THERBY CREATING ZOMBIE PROCESS
                             printf("\n\n------PARENT PROCESS ENDS-----\n\n");
                             }
                    break;
                             
              }     
}

void merge(int A[50],int low,int mid,int high,int n)
{
	int i=low,j=mid+1,k=low,m;
	int temp[50];
	
	while(i<=mid && j<=high)
	{
		if(A[i]<=A[j])
		{
			temp[k]=A[i];
			i++;
			k++;
		}
		else
		{
			temp[k]=A[j];
			j++;
			k++;
		}
	}
	while(j<=high)
	{
		temp[k]=A[j];
		j++;
		k++;
	}

	while(i<=mid)
	{
		temp[k]=A[i];
		i++;
		k++;
	}
	for(i=low;i<=high;i++)
	{
		A[i]=temp[i];
	}	
}

void merge_sort(int A[50],int low,int high,int n)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(A,low,mid,n);
		merge_sort(A,mid+1,high,n);
		merge(A,low,mid,high,n);
	}
}

void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
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
