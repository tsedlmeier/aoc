#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    FILE* fp = fopen("./test", "r");
    if (!fp)
    {
        fprintf(stderr, "Error opening file '%s'\n", "./input");
        return EXIT_FAILURE;
    }
    char* line_buf;
    size_t line_buf_size;
    ssize_t line_size = 0;
    char stacks[100][3] = { {"NZ"},{"DCM"},{"P"}};
    
    // char stacks[100][9] = {
    //                         {CSGB},
    //                         {GVNJHWMT},
    //                         {SQM},
    //                         {MNWTLSB},
    //                         {PWGVTFZJ},
    //                         {SHQGBTC},
    //                         {WBPJT},
    //                         {MQTFZCDG},
    //                         {FPBHSN},
    //                         };
    int cnt=0;
    char delimiters[1] = " ";
    int crane[3];

    while(1)
    {
        line_size = getline(&line_buf, &line_buf_size, fp);
        if (line_size <= 0) break;

        int b =0;
        char *token = strtok(line_buf, delimiters);
        while (token != NULL)
        {
            crane[b] = atoi(token);
            token = strtok(NULL, delimiters);
            b++;
        }
        int move = crane[0];
        int from = crane[1]-1;
        int to = crane[2]-1;
        for(int i=0; i<move; i++)
        {
            char *tmp = strdup(&stacks[to][i]);
            strcpy(&stacks[to][i], &stacks[from][i]); //Put str2 or anyother string that you want at the begining
            strcat(&stacks[to][i], tmp);  //concatenate previous str1
            strcpy(&stacks[from][i], &stacks[from][i+1]);//del char
            free(tmp); //free the memory
        }
            // memmove((char*)stacks[to][strlen(stacks[to])], (char*)stacks[from][i],1);

    }
}
