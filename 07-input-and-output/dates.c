#include <stdio.h>
#include <stdlib.h>

/* read dates in the 'form day month year' or 'month/day/year' */
int main(void) {
    size_t linesize = 1000;
    char *line = (char *)malloc(linesize * sizeof(char));

    int day, month, year;
    char monthname[20];

    while (getline(&line, &linesize, stdin) > 0) {
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("Valid: %s\n", line);
        else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
            printf("Valid: %s\n", line);
        else
            fprintf(stderr, "Invalid format: %s\n", line);
            return 1;
    }

    return 0;
}
