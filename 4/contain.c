// 524 is right
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* line_buf_nl;//[10];
    size_t line_buf_size = 0;
    ssize_t line_size = 0;

    // FILE* fp = fopen("./test", "r");
    FILE* fp = fopen("./input", "r");
    if (!fp)
    {
        fprintf(stderr, "Error opening file '%s'\n", "./input");
        return EXIT_FAILURE;
    }

    int cnt = 0;
    char delimiters[2] = "-,";
    int lim[4];
    while(line_size >= 0)
    {

        line_size = getline(&line_buf_nl, &line_buf_size, fp);
        if(line_size <= 0) break;
        printf("%s: ",line_buf_nl);

        int b =0;
        char *token = strtok(line_buf_nl, delimiters);
        while (token != NULL)
        {
            lim[b] = atoi(token);
            token = strtok(NULL, delimiters);
            b++;
        }
            
        char* first = (char*) calloc(400,sizeof(char));
        char* second =  (char*) calloc(400,sizeof(char));
        int i;
        int n=0;
        for(i=lim[0]; i<=lim[1]; i++)
        {
            char* tmp = (char*) calloc(5,sizeof(char));
            sprintf(tmp, "%d", i);
            strcat(first, tmp);
            strcat(first, ",");
            free(tmp);
            n++;
        }
        int m=0;
        for(i=lim[2]; i<=lim[3]; i++)
        {
            // second[m] = (char)i;
            char* tmp = (char*) calloc(5,sizeof(char));
            sprintf(tmp, "%d", i);
            strcat(second, tmp);
            strcat(second, ",");
            free(tmp);
            m++;
        }
        if( (strstr(first,second) != NULL) || (strstr(second,first) != NULL) )
        {
            cnt++;
            printf("1\n");
        }
        else {
            
            printf("0\n");
        }
        free(first);
        free(second);
    }

    printf("Cnt: %d", cnt);
    fclose(fp);
}
