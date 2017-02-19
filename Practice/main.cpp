#include <cstdio>
#include <iostream>

using namespace std;

int main(){

	int nrows, ncols, l, h;

	/* read input data and allocate memory for pizza_array */
	scanf("%d", &nrows);
	scanf("%d", &ncols);
	scanf("%d", &l);
	scanf("%d", &h);

	/* allocate memory */
	char **pizza = new char*[nrows];
	for(int i = 0; i < nrows; i++){
		pizza[i] = new char[ncols];
	} 

	/* read pizza_array */
	for(int i = 0; i < nrows; i++){
		for(int j = 0; j < ncols; j++){
			scanf(" %c", &pizza[i][j]);
		}
	}
	/* *************************************************** */


	/* free memory */
	for(int i = 0; i < nrows; i++){
		delete[] pizza[i];
	}
	delete[] pizza;
	/* *********** */

	return 0;

}