#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int comp (const void* elem1, const void* elem2) {
  printf("Comparing: %d with %d\n", elem1, elem2);
  const int *a = *(const int **)elem1;
  const int *b = *(const int **)elem2;
  printf("Comparing: %d with %d\n", a[2], b[2]);
  if(a[2] < b[2])
    return 1;
  if(a[2] > b[2])
    return -1;
  return 0;
}

int main(void){

	int i, j;
	int nvideos, nepoints, nrequestsDisc, ncaches, capacity;
	/* read data from file */
	scanf("%d", &nvideos);
	scanf("%d", &nepoints);
	scanf("%d", &nrequestsDisc);
	scanf("%d", &ncaches);
	scanf("%d", &capacity);

	int *vsizes = malloc(sizeof(int)*nvideos);
	for(i = 0; i < nvideos; i++){
		scanf("%d", &vsizes[i]);
	}

	int **eplatency = malloc(sizeof(int *)*nepoints);
	for(i = 0; i < nepoints; i++){
		eplatency[i] = calloc((ncaches + 1), sizeof(int));
	}

	/* latency = 0 => not connected */
	for(i = 0; i < nepoints; i++){
		int temp; //caches conntected to epoint
		int cacheId;
		scanf("%d", &eplatency[i][0]);
		scanf("%d", &temp);
		for(j = 0; j < temp; j++){
			scanf("%d", &cacheId);
			scanf("%d", &eplatency[i][cacheId+1]);
		}
	}

	int **requests = malloc(sizeof(int *)*nrequestsDisc);
	for(i = 0; i < nrequestsDisc; i++){
		requests[i] = malloc(sizeof(int)*3);
	}

	/* video | endpoint | number of requests */
	for(i = 0; i < nrequestsDisc; i++){
		scanf("%d", &requests[i][0]);
		scanf("%d", &requests[i][1]);
		scanf("%d", &requests[i][2]);
	}

  printf("The pointers of requests are:\n");
  printf("The request is: %d\n", requests);
  for(int32_t counter = 0; counter < nrequestsDisc; counter++) {
    printf("The requests[%d] is: %d\n", counter, requests[counter]);
  }

  qsort(requests, nrequestsDisc, sizeof(requests[0]), comp);

  for(int32_t counter = 0; counter < nrequestsDisc; counter++) {
    printf("%d, %d, %d\n", requests[counter][0], requests[counter][1], requests[counter][2]);
  }

	/* free memory */



	return 0;
}
