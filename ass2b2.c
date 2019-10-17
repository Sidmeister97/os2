//Roll No : 33158

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
         int A[20];
           
         int n,i,j;
         n=argc;
          
         printf("The entered numbers are :: \t");
         for(i=0;argv[i+1]!=NULL;i++)
         {
         	A[i]=atoi(argv[i+1]);
         	printf("%d",A[i]);
         }
         
         printf("\n\nEnter key to be searched :: \n\n");
         scanf("%d",&j);
         binarysearch(A,0,n-1,j);
       
              
         return 0;
}

void binarySearch(int array[],int lb,int ub,int key)
{

	
	if(lb <= ub)
	{
		int middle = (ub+lb)/2;
	
		if(array[middle] == key)
		{
			printf("%d found at position %d\n",key,middle);
		}
		else if(array[middle] > key)
		{
			binarySearch(array,middle+1,ub,key);
		}
		else if(array[middle] < key)
		{
			binarySearch(array,lb,middle-1,key);
		}
	}	
}

