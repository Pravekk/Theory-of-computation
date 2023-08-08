#include <stdio.h>
#include <stdbool.h>

bool isAccepted(char str[]) 
{
    int state = 0; 
    

    for (int i = 0; str[i] != '\0'; i++) 
	{
        switch (state) 
		{
            case 0:
                if (str[i] == 'a') state = 1;
                else return false;
                break;
            case 1:
                if (str[i] == 'a') state = 1;
                else if (str[i] == 'b') state = 2;
                else return false;
                break;
            case 2:
                if (str[i] == 'a') state = 1;
                else return false;
                break;
        }
    }

    return state == 1;
}

int main() 
{
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    if (isAccepted(str)) 
	{
        printf("String is accepted.\n");
    } else 
	{
        printf("String is not accepted.\n");
    }
    
    return 0;
}
