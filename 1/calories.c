#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char line_buf[6];
  char* line_buf_nl;//[10];
  size_t line_buf_size = 0;
  int line_count = 0;
  ssize_t line_size = 0;

  FILE* fp = fopen("./input", "r");
  if (!fp)
  {
    fprintf(stderr, "Error opening file '%s'\n", "./input");
    return EXIT_FAILURE;
  }

  int elv_cnt = 1;
  int cal_sum = 0;
  int cal_most = 0;
  while(line_size >= 0)
  {

    line_size = getline(&line_buf_nl, &line_buf_size, fp);
    line_count++;

    if(line_size == 1)
    {
      elv_cnt++;
      if(cal_sum > cal_most) cal_most = cal_sum;
      cal_sum = 0;

    }
    cal_sum += atoi(line_buf_nl);

  }
  printf("Most: : %d", cal_most);

  fclose(fp);
}
