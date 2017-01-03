/*******************************************************************************************************************************
Pset2 - vigenere.c
********************************************************************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

void encipher(char txt, int k, int Aora);

int main(int argc, string argv[])
{
    //checking for no argument
    if (argc < 2)
    {
        printf("Please specify cipher key\n");
        return 1;
    }
    //checking for too many arguments
    else if (argc > 2)
    {
        printf("There are more than one argument\n");
        return 1;
    }
    else
    {
        string key = argv[1]; 
        //variable declarations for key processing
        int klen = strlen(key), i=0,upper='A', lower='a';     
        
        for (i=0; i<klen; i++)
        {
        
            //checking for non-alphabet in argument
            if (isalpha(key[i]))
            {
                if (isupper(key[i]))
                    key[i] -= 'A';
                else if (islower(key[i]))
                    key[i] -= 'a';
            }
            else
            {
                //argument contains non-alphabet
                printf("Key must be only alphabetical\n");  //argument contains non-alphabet letter
                return 1;
            }
        }
        
        string txt = GetString();
        
        //additional variable declarations for encryption
        int tlen = strlen(txt), j=0; 
        
        for (i=0; i<tlen; i++)
        {
            //recycling key when necessary
            if (j >= klen)
                j = 0;
            
            if (isalpha(txt[i]))
            {
                //encryption for uppercase
                if (isupper(txt[i]))
                {
                    encipher(txt[i], key[j], upper);
                    j++;
                }
                //encryption for lowercase
                else if (islower(txt[i]))
                {
                    encipher(txt[i], key[j], lower);
                    j++;
                }
            }
            //printing non-alphabet unchanged
            else
                printf("%c",txt[i]);
        }
        
        printf("\n");
        
        //End of main
        return 0;
    }
}

void encipher(char txt, int k, int Aora)
{
   char result = ((txt - Aora + k)%26) + Aora; 
   printf("%c", result);
   //printf("plain: %c - key: %d - cipher: %c\n",txt[i], key[j], ciphertext); 
}
