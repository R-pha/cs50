#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //use do while?
    /*
    create half pyramid using # as block
    prompt user for integer no greater than 23
    range checking for non-negative integer above 24 0 < int < 24
    output:
        height: 8
               ##
              ###
             ####
            #####
           ######
          #######
         ########
        #########
*/
    int num, ctr = 0, ctr_ =0;
    char space = ' ';
    
    do {
        printf("height: ");
        num = GetInt();
    } 
    while (0 > num || num > 23);
    
    for (ctr = 0; ctr < num; ctr ++)
    {
        for (ctr_ = 0; ctr_<num-1-ctr;ctr_++)
            printf("%c",space);
        
        for (ctr_ = 0; ctr_<ctr+2;ctr_++)
            printf("#");
            
        printf("\n");
    }

}