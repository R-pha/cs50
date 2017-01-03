/*******************************************************************************************************************************
Pset2 - caesar.c
********************************************************************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encipher(char txt, int k, int Aora);

int main(int argc, string argv[])
{
    
    //validating user input for key size
    if (argc < 2)
    {
        printf("Please specify key size\n");
        return 1;
    }
    //ensuring key size is postive integer
    else if (atoi(argv[1]) < 0)
    {
        printf("Key size must be a positive number\n");
        return 1;
    }
    else 
    {
        //prompting for user input
        string txt = GetString();
        //variable declaration
        int k = atoi(argv[1]), len = strlen(txt), upper='A', lower='a';
        
        for (int i=0; i<len; i++)
            
            //for uppercase
            if (isupper(txt[i]))
            {
                encipher(txt[i],k,upper);
                
            }
            //for lowercase
            else if (islower(txt[i]))
            {
                encipher(txt[i],k,lower);
            }
            else 
                printf("%c",txt[i]);
    
        printf("\n");

    return 0;
    }
}

//Encryption function
void encipher(char txt, int k, int Aora)
{
    printf("%c", ((txt - Aora + k)%26) + Aora);
}