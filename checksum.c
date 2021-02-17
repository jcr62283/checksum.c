/********************************/
/* Program Name:                */
/* Author:                      */
/* Date:                        */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"

#define max_int (255)
#define byte unsigned char

int read(int fildes, void* buf, size_t nbyte);

int main(int argc, char* argv[], char** envp) {

    int count = 10;
    int checksumpos = 5;
    int sum = 0;
    byte checksum;
    byte complement;

    byte header[count];
    int numRead = read(0, &header, 10);

    if (numRead > 0)
    {
        for (int i = 0; i < count; i++)
        {
            if (i == checksumpos)
            {
                checksum = header[i];
                header[i] = 0;
            }

            sum += header[i];
        }
    }

    int quo = sum / (max_int + 1);
    int rem = sum % (max_int + 1);
    sum = quo + rem;
    complement = (byte)(max_int - sum);
    
    fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
    if (checksum != complement) {
        fprintf(stderr, "Error Detected!\n");
        return 1;
    }
    return 0;
}