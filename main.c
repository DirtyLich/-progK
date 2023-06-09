#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lz77.h"

#define BUFFER_SIZE 4096

int compress(FILE *input_file, FILE *output_file);
int decompress(FILE *input_file, FILE *output_file);

int main(int argc, char *argv[]) {
    char *input_filename, *output_filename;
    FILE *input_file, *output_file;
    int mode;

    // Check the number of arguments
    if (argc < 4) {
        fprintf(stderr, "Usage: %s -c/-d input_file output_file\n", argv[0]);
        return 1;
    }

    // Determine the mode of operation
    if (strcmp(argv[1], "-c") == 0) {
        mode = 1;
    } else if (strcmp(argv[1], "-d") == 0) {
        mode = 0;
    } else {
        fprintf(stderr, "Error: Invalid mode.\n");
        return 1;
    }

    // Open the input file
    input_filename = argv[2];
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Failed to open input file '%s'.\n", input_filename);
        return 1;
    }

    // Open the output file
    output_filename = argv[3];
    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Failed to open output file '%s'.\n", output_filename);
        return 1;
    }

    // Perform the selected operation
    if (mode) {
        if (compress(input_file, output_file)) {
            fprintf(stderr, "Error: Failed to compress the input file.\n");
            return 1;
        }
    } else {
        if (decompress(input_file, output_file)) {
            fprintf(stderr, "Error: Failed to decompress the input file.\n");
            return 1;
        }
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    return 0;
}


// 
#include <stdio.h>

int main() {
    printf("| %10s | %10s | %10s |\n", "Заголовок 1", "Заголовок 2", "Заголовок 3");
    printf("|------------|------------|------------|\n");
    printf("| %10d | %10d | %10d |\n", 1, 2, 3);
    printf("| %10d | %10d | %10d |\n", 4, 5, 6);
    printf("| %10d | %10d | %10d |\n", 7, 8, 9);
    printf("|------------|------------|------------|\n");

    return 0;
}



printf("| %10s | %10s | %15s | %10s | %10s |\n", "Milimeters", "Centimeters", "Decimeters", "Meters", "Kilometers");
printf("------------|------------|----------------|------------|------------|\n");
printf("| %10s | %10s | %15s | %10s | %10s |\n", "Centimeters", "Milimeters", "Milimeters", "Milimeters", "Milimeters");
printf("| %10s | %10s | %15s | %10s | %10s |\n", "Decimeters", "Decimeters", "Centimeters", "Centimeters", "Centimeters");
printf("| %10s | %10s | %15s | %10s | %10s |\n", "Meters", "Meters", "Meters", "Decimeters", "Decimeters");
printf("| %10s | %10s | %15s | %10s | %10s |\n", "Kilometers", "Kilometers", "Kilometers", "Kilometers", "Meters");
printf("------------|------------|----------------|------------|------------|\n");

