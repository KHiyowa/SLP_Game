#include <stdio.h>

enum status {EMP, BLK, ST, GL};

define SIZE 6
enum status a[SIZE][SIZE] = {{BLK, BLK, BLK, BLK, ST, BLK},
                             {BLK, EMP, EMP, BLK, EMP, BLK},
                             {BLK, BLK, BLK, BLK, EMP, BLK},
                             {BLK, EMP, BLK, BLK, EMP, BLK},
                             {BLK, EMP, BLK, BLK, EMP, BLK},
                             {BLK, GL, BLK}}

  int main(void)
{
  a[SIZE][SIZE] = {{}}
}
