#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // FILE* fp = fopen("./test", "r");
    FILE* fp = fopen("./input", "r");
    if (!fp)
    {
        fprintf(stderr, "Error opening file '%s'\n", "./input");
        return EXIT_FAILURE;
    }
    char* line_buf;
    size_t line_buf_size;
    ssize_t line_size = 0;
    char same[300];
    int cnt=0;

    while(1)
    {
        for (size_t i = 0; i < 10000; i++) {
            
        }
        line_size = getline(&line_buf, &line_buf_size, fp);
        if (line_size <= 0) break;

        char* first = (char*) malloc(40*sizeof(char));
        char* second = (char*) malloc(40*sizeof(char));
        first = strncpy(first, line_buf, (line_size-1)/2);
        second = strncpy(second, &line_buf[(line_size-1)/2], (line_size-1)/2);

        char* same_part = (char*) calloc(40,sizeof(char));
        int place = 0;

        int j,n;
        for(j=0; j<(line_size-1)/2 ;j++)
        {
            for(n=0; n<(line_size-1)/2 ;n++)
            {
                if(first[j] == second[n])
                {
                    if(strchr(same_part, first[j]) == NULL)
                    {
                        same_part[place] = first[j];
                        place++;
                        cnt++;
                    }
                }
            }
        }
        strcat(same, same_part);
        free(first);
        free(second);
        free(same_part);
    }

    int sum = 0;
    for (size_t i = 0; i < cnt; i++) {
        if (islower(same[i]))
        {
            sum += (int)same[i] - 96;
        }
        else {
            sum += (int)same[i] - 64+26;
        }
    }
    printf("sum: %d\n", sum);
}
