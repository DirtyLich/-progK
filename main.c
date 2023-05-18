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

