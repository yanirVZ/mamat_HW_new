#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static FILE* f;
static int nbins = 10;

void parse_arg(int argc, char* argv[]);
void operate(int* bins);

int main(int argc, char* argv[]) {

    parse_arg(argc, argv);

    // Checking errors
    if (!f) {
        fprintf(stderr, "File not found: \"%s\"\n", argv[1]);
        return 1;
    }
    int* bins = (int*)calloc(nbins, sizeof(int));

    operate(bins);

    free(bins);
    return 0;
}

void parse_arg(int argc, char* argv[])
{
    f = stdin;
    for (int i = 0; i < argc; ++i)
    {
        if (!strcmp(argv[i], "-"))
        {
            f = stdin;
        }
        else if (!strcmp(argv[i], "-nbins"))
        {
            nbins = i < argc - 1 ? atoi(argv[i + 1]) : 10;
            i++;
        }
        else
        {
            f = fopen(argv[i], "r");
        }
    }
}

void operate(int* bins)
{
    int grade;
    int retval;
    int line = 0;

    while (1) {
        retval = fscanf(f, "%d", &grade);
        line++;

        if (retval == EOF)
            break;

        if (retval != 1) {
            fprintf(stderr, "Error at line %d: not a number\n", line);
            exit(1);
        }

        if (grade < 0 || grade > 100) {
            fprintf(stderr, "Error at line %d: grade %d invalid\n", line, grade);
            exit(1);
        }
        int n = (grade == 100) ? nbins - 1 : grade / (100 / nbins);
        bins[n]++;
    }

    double lower_bound, upper_bound;
    for (int i = 0; i < nbins; ++i)
    {
        lower_bound = i * (100 / nbins);
        upper_bound = (i < nbins - 1) ? ((i + 1) * (100 / nbins) - 1) : 100;

        printf("%.0lf-%.0lf\t%d\n", lower_bound, upper_bound, bins[i]);
    }
}
