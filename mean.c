#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void operate(FILE* f);

int main(int argc, char* argv[]) {
    FILE* f;

    if ((argc == 1) || !strcmp(argv[1], "-")) {
        f = stdin;
    }
    else {
        f = fopen(argv[1], "r");
    }

    if (!f) {
        fprintf(stderr, "File not found: \"%s\"\n", argv[1]);
        return 1;
    }

    operate(f);
}

void operate(FILE* f) {
    int grade;
    int retval;
    double sum = 0;
    int line = 0;

    while (1) {
        retval = fscanf(f, "%d", &grade);

        if (retval == EOF)
            break;
        else if (retval != 1) {
            fprintf(stderr, "Error at line %d: not a number\n", line);
            exit(1);
        }
        if (grade < 0 || grade > 100) {
            fprintf(stderr, "Error at line %d: grade %d invalid\n", line, grade);
            exit(1);
        }
        sum += grade;
        line++;
    }

        printf("%.2lf\n", sum / line);    
}


