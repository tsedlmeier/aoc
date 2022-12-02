#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
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

  int array[3][3] =   // R P S <- him
                  /*R*/{{3,0,6},
                  /*P*/ {6,3,0},
                  /*S*/ {0,6,3}};
                 /*me*/
  char him,me;
  int him_n, me_n;
  int points = 0;
  while(line_size >= 0)
  {

    line_size = getline(&line_buf_nl, &line_buf_size, fp);

    him = line_buf_nl[0];
    me = line_buf_nl[2];

    switch (him) {
        case 'A' :
          him_n = 0; // Rock
          break;
        case 'B' :
          him_n = 1; // Paper
         break;
        case 'C' :
          him_n = 2; // Sciss
         break;
      default:
          him_n = -1;
          printf("-1 !\n");
        break;
      }

    switch (me) {
        case 'X' :
          me_n = 0; // Rock
          break;
        case 'Y' :
          me_n = 1; // Paper
          break;
        case 'Z' :
          me_n = 2; // Sciss
         break;
      default:
          me_n = -1;
          printf("-1 !\n");
        break;
    }

    if(me_n>2 || him_n>2 ) printf("Ne kann ned sein\n");
    points += (array[me_n][him_n] + me_n+1); 

    line_count++;
  }
  printf("Points: : %d", points);
  fclose(fp);
}
