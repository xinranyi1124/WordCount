#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
  
int main(int argc, char *argv[]) {  
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s [-c|-w] <input_file_name>\n", argv[0]);  
        return 1;  
    }  
    char *parameter = argv[1];  
    char *filename = argv[2];  
  
    FILE *file = fopen(filename, "r");  
    if (!file) {  
        perror("Error opening file");  
        return 1;  
    }  
  
    int char_count = 0;  
    int word_count = 0;  
    int in_word = 0; 
    char ch;  
    while ((ch = fgetc(file)) != EOF) {  
        if (!isspace(ch) && ch != ',') {
            char_count++;  
            if (!in_word) {  
                word_count++;  
                in_word = 1;  
            }  
        } else {  
            in_word = 0; 
        }  
    }  
  
    if (strcmp(parameter, "-c") == 0) {  
        printf("×Ö·ûÊý£º%d\n", char_count);  
    } else if (strcmp(parameter, "-w") == 0) {  
        printf("µ¥´ÊÊý£º%d\n", word_count);  
    } else {  
        fprintf(stderr, "Invalid parameter: %s\n", parameter);  
        fclose(file);  
        return 1;  
    }  
  
    fclose(file);  
    return 0;  
}
