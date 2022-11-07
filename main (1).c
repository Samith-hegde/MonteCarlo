#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

int i         = 0;	
int n = 0;
int totalPts  = 0;

void *count(void *X)
{ 
    /* initialize random numbers */
    for (i=0; i < n; i++)
    {	
        double X = (double)rand() / RAND_MAX;
        double Y = (double)rand() / RAND_MAX;
        
        if (((X * X) + (Y * Y)) <= 1)
        {
            totalPts++;
        }
    }
    return NULL;
}

int main()
{
    srand(time(NULL));
    pthread_t thread;

    do
	{
        printf("Enter the number of points you would like to generate: \n");
        scanf("%d", &n);  	
	}while (n <= 0);
  
    pthread_create(&thread, NULL, &count, NULL);
    pthread_join(thread, NULL);
    
    double points = 4.0 * totalPts;
    double pi = points / n;
    printf("The approximate value of pi for the (%d) points is: %f \n", n, pi);  
    return 0;
}