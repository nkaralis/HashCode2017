
#include <stdio.h>
#include <cstdio>
#include <iostream>
using namespace std;

#define ROWS 50
#define COLUMNS 50



int main(){

	int nrows, ncols, l, h;

	char less_ingridient;				
	int L,Lcounter_Tomato=0,Lcounter_Mushroom=0;

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

	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			if(pizza[i,j] == less_ingridient)
			{	
				if(less_ingridient == 'T')      // Keep counters for L
				{
					Lcounter_Tomato++;
				}
				else
				{
					Lcounter_Mushroom++;
				}

				if(i-1 >= 0)  	        // Left		
				{
					if(less_ingridient == 'T')      // Search for the less ingridient
					{
						if(Lcounter_Tomato < L)
						{
							cout<<"Geia sou Giorgo"<<endl;
						}
					}
					else
					{
						if(Lcounter_Mushroom < L)
						{
							
						}
					}
				}
				else if(j-1 >= 0)      // Up
				{

				}
				else if(j+1 < ROWS)  // Down
				{

				}
				else if(i+1 < COLUMNS)    // Right
				{

				}
			}
		}
	}
	
	/* free memory */
 	for(int i = 0; i < nrows; i++){
 		delete[] pizza[i];
 	}
 	delete[] pizza;

	return 0;


}