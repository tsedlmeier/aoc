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
    char* line_buf[3];
    size_t line_buf_size;
    ssize_t line_size = 0;
    char same[300];
    int cnt=0;
    int quit=0;

    while(1)
    {
        for (size_t i = 0; i < 3; i++) {
            line_size = getline(&line_buf[i], &line_buf_size, fp);
            if (line_size <= 0) {
                quit = 1;
                break;
            }
        }
        if(quit) break;

        char* first = (char*) malloc(60*sizeof(char));
        char* second = (char*) malloc(60*sizeof(char));
        char* third = (char*) malloc(60*sizeof(char));
        first = strcpy(first, line_buf[0]);
        second = strcpy(second, line_buf[1]);
        third = strcpy(third, line_buf[2]);

        char* same_part = (char*) calloc(40,sizeof(char));
        int place = 0;

        size_t f,s,t;
        for(f=0; f<strlen(first)-1 ;f++)
        {
            for(s=0; s<strlen(second)-1 ;s++)
            {
                for(t=0; t<strlen(third)-1 ;t++)
                {
                    if(first[f] == second[s] && second[s] == third[t])
                    {
                        if(strchr(same_part, first[f]) == NULL)
                        {
                            same_part[place] = first[f];
                            place++;
                            cnt++;
                        }
                    }
                }
            }
        }
        strcat(same, same_part);
        free(first);
        free(second);
        free(third);
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
