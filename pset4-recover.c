/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <string.h>

const int SIZE = 512;     //FAT buffer size

int main(void)
{
    
    // Open input file
    FILE* inptr = fopen("card.raw", "r");
    
    if (inptr == NULL)
    {
        printf("Could not open card.raw.\n");
        return 1;
    }
    
    
    FILE* outptr = NULL;                                  // output file ptr
    
    unsigned char buffer[SIZE];                           // array to store input file buffer
    unsigned char hdr0[4] = {0xFF, 0xD8, 0xFF, 0xE0};     // JPG header1
    unsigned char hdr1[4] = {0xFF, 0xD8, 0xFF, 0xE1};     // JPG header2
    
    int jpgno = 0;                                      // to keep count of jpg generation
    int open = 0;                                       // to track pending jpg file creation
    
    // Process CF dump into JPGs
    while (fread(&buffer, sizeof(buffer), 1, inptr) != 0)
    {
        // Checking for JPG headers
        if (memcmp(hdr0, buffer, 4) == 0 || memcmp(hdr1, buffer, 4) == 0)
        {
            if (open == 0)
            {
                char filename[8];                                   // array to store filename
                
                sprintf(filename, "%03d.jpg", jpgno);
                
                // Create new JPG            
                outptr = fopen(filename, "w");
                    
                if (outptr == NULL)
                {
                    fclose(inptr);
                    printf("Could not create a new jpg.\n");
                    return 1;
                }
                    
                fwrite(&buffer, sizeof(buffer), 1, outptr);
                    
                open = 1;
                    
                printf("writing header for %s\n",filename);    
            }
            
        }
        else
        {
            // write Buffers with header values
            if (open == 1)
            {
                fwrite(&buffer, sizeof(buffer), 1, outptr);
            }
            
            // Checking for JPG trailer values
            for (int i=0; i<SIZE-1; i++)
            {
                if (buffer[i] == 0xFF && buffer[i+1] == 0xD9)
                {
                    open = 0;
                    jpgno++;
                    
                    // Closing outptr
                    fclose(outptr);
                }
            }
            
        }
    }
    
    // Closing inptr
    fclose(inptr);
    
    return 0;
}
