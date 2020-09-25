#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Count_sort(int a[], int n) {

	int i, j, count;
	count = 0;
    int* temp = malloc(n*sizeof(int));

    int threadNumber = omp_get_num_threads();
#pragma omp parallel for num_threads(threadNumber) private(count) shared(n)
    for (i = 0; i < n; i++) {
		count = 0;
		for (j = 0; j < n; j++)
			if (a[j] < a[i])
				count++;
			else if (a[j] == a[i] && j < i)
				count++;
		temp[count] = a[i];
    }
	memcpy(a, temp, n*sizeof(int));
	free(temp);
	 }


int main (int argc, char *argv[]) {

	int n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int A[n];


#pragma omp for
    for(int i=0;i<n;++i)
    {
     printf("\nEnter elements:");
     scanf("%d",&A[i]);
    }

#pragma omp barrier
    Count_sort(A,n);

 return 0;
}

