#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(void)
{
    char* line_buf;
    size_t line_buf_size = 0;
    ssize_t line_size = 0;

    // FILE* fp = fopen("./test", "r");
    FILE* fp = fopen("./input", "r");
    if (!fp)
    {
        fprintf(stderr, "Error opening file '%s'\n", "./input");
        return EXIT_FAILURE;
    }

    line_size = getline(&line_buf, &line_buf_size, fp);
    char* ptr_buf = &line_buf[0];
    char win[14];
    int cnt=0;
    int found = 0;
    int four = 14;

    while(1)
    {
        strncpy(win,ptr_buf,14);
        four = 14;
        for (size_t i = 0; i < 14; i++) {
            char tmp = win[i];
            win[i] = '0';
            if( strchr(win,tmp)==NULL)
            {
                if (!(--four)) 
                {
                    found=1;
                    break;
                } 
            }
            else{
                four = 14;
            }
            win[i] = tmp;
        }
        if(found) break;
        cnt++;
        ptr_buf++;

    }
    cnt += 14;
    printf("%d\n", cnt);
    fclose(fp);
}
