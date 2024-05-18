#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c|-w] [input_file_name]", argv[0]);
        return 1;
    }

    char *parameter = argv[1];
    char *input_file_name = argv[2];
    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    int count = 0;
    char line[1024];
    while (fgets(line, sizeof(line), input_file)) {
        if (strcmp(parameter, "-c") == 0) {
            count += strlen(line);
        } else if (strcmp(parameter, "-w") == 0) {
            char *token = strtok(line, " ,");
            while (token != NULL) {
                count++;
                token = strtok(NULL, " ,");
            }
        } else {
            printf("Invalid parameter. Use -c for character count or -w for word count.");
            fclose(input_file);
            return 1;
        }
    }

    printf("%s: %d", parameter, count);
    fclose(input_file);
    return 0;
}

