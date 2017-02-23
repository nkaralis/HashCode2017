#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int comp (const void* elem1, const void* elem2) {
  const int *a = *(const int **)elem1;
  const int *b = *(const int **)elem2;
  if(a[2] < b[2])
    return 1;
  if(a[2] > b[2])
    return -1;
  return 0;
}

void print_results(int32_t** vid_per_cache, int32_t n_caches, int32_t n_vids) {
  for(int32_t cache_cand = 0; cache_cand < n_caches; cache_cand++) {
    bool used_last_cache = false;
    int32_t vid_cand;
    for(vid_cand = 0; vid_cand < n_vids; vid_cand++) {
      if(vid_per_cache[cache_cand][vid_cand] == 1) {
        printf("%d", cache_cand);
        printf(" %d", vid_cand); vid_cand++;
        used_last_cache = true;
        break;
      }
    }
    for(vid_cand; vid_cand < n_vids; vid_cand++) {
      if(vid_per_cache[cache_cand][vid_cand] == 1) {
        printf(" %d", vid_cand);
      }
    }
    if(used_last_cache) {
      printf("\n");
    }
  }

  return;
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

  qsort(requests, nrequestsDisc, sizeof(requests[0]), comp);

	/* free memory */



	return 0;
}
