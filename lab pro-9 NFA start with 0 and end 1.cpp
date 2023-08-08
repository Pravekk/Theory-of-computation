#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool transition(int state, char symbol) 
{
    if (state == 0 && symbol == '0') 
	{
        return true;
    } 
	else if (state == 1 && symbol == '1') 
	{
        return true;
    } 
	else 
	{
        return false;
    }
}
bool simulateNFA(char *input) 
{
    int currentState = 0; 
    for (int i = 0; input[i] != '\0'; i++) 
	{
        char symbol = input[i];
        if (transition(currentState, symbol)) 
		{
            currentState++; 
        }
    }
    
    return currentState == 2;
}

int main() 
{
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    
    if (simulateNFA(input)) 
	{
        printf("Accepted: The string starts with '0' and ends with '1'.\n");
    } 
	else 
	{
        printf("Rejected: The string does not meet the language criteria.\n");
    }
    
    return 0;
}

