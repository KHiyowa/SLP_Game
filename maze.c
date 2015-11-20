#include <stdio.h>
#include <stdbool.h>

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
bool canMove(int n);
bool isGoal(void);

int playerx = 0;
int playery = 4;


int main(void)
{

  while ( ! isGoal() ) {
    drawMap();
    playerMove();
  }
  drawMap();
  puts("Goal!");

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

  do {
    printf("1: Up, 2: Down, 3: Left, 4: Right ... ");
    n = getInput();
  }while (!(canMove(n)));

  switch ( n ) {
  case 1 :
    playerx--;
    break;
  case 2 :
    playerx++;
    break;
  case 3 :
    playery--;
    break;
  case 4 :
    playery++;
    break;
  }
}

int getInput(void)
{
  int n;

  do {
    scanf("%d", &n);
    if (! (1 <= n && n <= 4)) {
      puts("try again.");
    }
  } while(! (1 <= n && n <= 4));

  return n;
}

bool canMove(int n)
{
  int x = playerx;
  int y = playery;

  switch ( n ) {
    case 1:
      x--;
      break;
    case 2:
      x++;
      break;
    case 3:
      y--;
      break;
    case 4:
      y++;
      break;
  }

  if ( x < 0 || y < 0 || SIZE <= x || SIZE <= y || a[x][y] == BLK ) {
    return false;
  }
  return true;
}

bool isGoal(void)
{
  if ( a[playerx][playery] == GL ) {
    return true;
  } else {
    return false;
  }
}

