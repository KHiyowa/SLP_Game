#include <stdio.h>

enum status {EMP, BLK, ST, GL};

#define SIZE 6
enum status a[SIZE][SIZE] = {{BLK, BLK, BLK, BLK, ST, BLK},
                             {BLK, EMP, EMP, BLK, EMP, BLK},
                             {BLK, EMP, EMP, BLK, EMP, BLK},
                             {BLK, EMP, BLK, BLK, EMP, BLK},
                             {BLK, EMP, EMP, EMP, EMP, BLK},
                             {BLK, GL, BLK, BLK, BLK, BLK}};
char *chip[] = {" ", "*", "S", "G"};

void drawMap(void);

int playerx = 0;
int playery = 4;

int main(void)
{
  drawMap();
  

  
  return 0;
}

void drawMap(void) {
  int i, j;
  
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      if ( playerx == i && playery == j ) {
        printf("X");
      } else {
        printf("%s", chip[a[i][j]]);
      }
    }
    puts("");
  }
}
