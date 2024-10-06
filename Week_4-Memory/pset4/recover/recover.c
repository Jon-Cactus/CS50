#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Accept command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open memory card
    FILE* memcard = fopen(argv[1], "r");
    if (memcard == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    BYTE buffer[512];
    int filenumber = -1;
    FILE* img = NULL;

    while (fread(buffer, 1, 512, memcard) == 512)
    {

        char filename[8];

        // Look for the beginning of a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            filenumber++;
            // Create file name
            snprintf(filename, sizeof(filename), "%03i.jpg", filenumber);
            // Open file
            img = fopen(filename, "w");

            if (img == NULL)
            {
                printf("Could not open file.\n");
                return 1;
            }
            fwrite(buffer, 1, 512, img);
        }
        else
        {
            if (img != NULL)
            {
                fwrite(buffer, 1, 512, img);
            }
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(memcard);
    return 0;
}