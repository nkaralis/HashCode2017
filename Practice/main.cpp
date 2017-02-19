#include <stdio.h>
using namespace std;

#define ROWS 50
#define COLUMNS 50

int main()
{
	
	char pizza[ROWS,COLUMNS];
	char less_ingridient;				
	int L,Lcounter_Tomato=0,Lcounter_Mushroom=0;

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

	return 0;
}