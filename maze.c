//====  ヘッダ
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//====  定数マクロ
#define SIZE 6
#define STR  256

//====  グローバル宣言
enum status {EMP, BLK, ST, GL};
enum status a[SIZE][SIZE] = {{BLK, BLK, BLK, BLK, ST, BLK},
                             {BLK, EMP, EMP, BLK, EMP, BLK},
                             {BLK, EMP, EMP, BLK, EMP, BLK},
                             {BLK, EMP, BLK, BLK, EMP, BLK},
                             {BLK, EMP, EMP, EMP, EMP, BLK},
                             {BLK, GL, BLK, BLK, BLK, BLK}};
char *chip[] = {" ", "*", "S", "G"};
int playerx = 0;
int playery = 4;

//====  プロトタイプ宣言
void drawMap(void);
void playerMove(void);
int getInput(void);
bool canMove(int n);
bool isGoal(void);

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

//====  マップを描画する関数
void drawMap(void)
{
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

//====  プレイヤーを移動する関数
void playerMove(void)
{
  int n;
  
  do {
    n = getInput();
    if (!(canMove(n))) {
      printf("Can't move!! Try again!\n");
    }
  } while (!(canMove(n)));

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

//====  入力を受け取って返却する関数
int getInput(void)
{
  char s[STR];
  char *e;
  int n;
  
  do {
    printf("1: Up, 2: Down, 3: Left, 4: Right ... ");
    scanf("%s", s);
    n = strtod(s, &e);
    if (! (1 <= n && n <= 4)) {
      puts("try again.");
    }
  } while(! (1 <= n && n <= 4) || (n == 0 && e == s) );

  return n;
}

//====  移動できるか確認する関数
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

//====  ゴール判定関数
bool isGoal(void)
{
  return a[playerx][playery] == GL;
}

