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
void playerMove(void);
int getInput(void);

int playerx = 0;
int playery = 4;

int main(void)
{
  int n;
  drawMap();
  n = getInput();
  // printf("%d/n", n);


  
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

void playerMove(void) {
  int n;
  n = getInput();

}

int getInput(void)
{
  int n;

  scanf("%d", &n);
  do {
    scanf("%d", &n);
    if (! (1 <= n && n <= 4)) {
      puts("try again.");
    }
  } while(! (1 <= n && n <= 4));

  return n;
}

