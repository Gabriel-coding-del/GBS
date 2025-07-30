#include <stdio.h>
#include <string.h>

char filename[100];

int ends_with_pxlt(const char *filename) {
    size_t len = strlen(filename);
    if (len < 5) return 0; // too short to be ".pxlt"

    // Compare the last 5 characters
    return strcmp(filename + len - 5, ".pxlt") == 0;
}

int main() {
    printf("Enter the filename: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Remove trailing newline
    filename[strcspn(filename, "\n")] = '\0';

    FILE *fp = fopen(filename, "r");
    if (ends_with_pxlt(filename)) {
            FILE *fp = fopen(filename, "r");
    } else {
		printf("\033[1;31mERROR: \033[0mFilename does not end with .pxlt. Abort\n");
        return 1;
	}
    if (fp == NULL) {
        fprintf(stderr, "GBS: cannot open '%s': no such file or directory\n", filename);
        return 1;
    }

    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        switch (ch) {
            case 'r':
            	printf("\033[1;31m#\033[0m"); 
            	break; // Red
            case 'g': 
            	printf("\033[1;32m#\033[0m"); 
            	break; // Green
            case 'b': 
            	printf("\033[1;34m#\033[0m"); 
            	break; // Blue
            case 'y': 
            	printf("\033[1;33m#\033[0m"); 
            	break; // Yellow
            case 'm': 
            	printf("\033[1;35m#\033[0m"); 
            	break; // Magenta
            case 'c': 
            	printf("\033[1;36m#\033[0m"); 
            	break; // Cyan
            case 'w': 
            	printf("\033[1;37m#\033[0m"); 
            	break; // White
            case 'k': 
            	printf("\033[1;30m#\033[0m"); 
            	break; // Black
            case 'o': 
            	printf("\033[38;5;208m#\033[0m"); 
            	break; // Orange
            case 'p': 
            	printf("\033[95m#\033[0m"); 
            	break; // Purple
            case 'l': 
            	printf("\033[37m#\033[0m"); 
            	break; // Light gray
            case 'd': 
            	printf("\033[90m#\033[0m"); 
            	break; // Dark gray
            case '.': 
            	printf(" "); 
            	break;                 // Blank
            case '\n':
            	 putchar('\n'); 
            	 break;              // Newline
            default: putchar(ch); break;                  // Anything else
        }
    }

    fclose(fp);
    return 0;
}
