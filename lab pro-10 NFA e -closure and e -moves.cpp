#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 100
bool transition[MAX_STATES][MAX_STATES][2];
void addToEpsilonClosure(bool epsilonClosure[MAX_STATES], int state, int numStates) 
{
    if (!epsilonClosure[state]) 
	{
        epsilonClosure[state] = true;
        for (int i = 0; i < numStates; i++) 
		{
            if (transition[state][i][0]) 
			{
                addToEpsilonClosure(epsilonClosure, i, numStates);
            }
        }
    }
}
void calculateEpsilonClosure(bool epsilonClosure[MAX_STATES], int numStates, int state) 
{
    memset(epsilonClosure, false, sizeof(epsilonClosure));
    addToEpsilonClosure(epsilonClosure, state, numStates);
}

int main() 
{
    int numStates;
    printf("Enter the number of states in the NFA: ");
    scanf("%d", &numStates);

    printf("Enter the NFA transition table (0 or 1):\n");
    for (int i = 0; i < numStates; i++) 
	{
        for (int j = 0; j < numStates; j++) 
		{
            scanf("%d %d", &transition[i][j][0], &transition[i][j][1]);
        }
    }

    for (int state = 0; state < numStates; state++) 
	{
        bool epsilonClosure[MAX_STATES];

        calculateEpsilonClosure(epsilonClosure, numStates, state);

        printf("e-Closure(q%d): { ", state);
        for (int i = 0; i < numStates; i++) 
		{
            if (epsilonClosure[i]) 
			{
                printf("q%d ", i);
            }
        }
        printf("}\n");
    }

    return 0;
}

