#include <stdio.h>
#include <cs50.h>

void print_pyramid(int );
void print_right_row(int );
void print_left_row(int , int);

int main(int argc, char *argv[])
{
  int height;

  do{
      height = get_int("Height : ");

  }while (height <= 0 || height > 8);

  print_pyramid(height);
  return 0;
}

void print_pyramid(int h){
  /*
   * ..#  #
   * .##  ##
   * ###  ###
   */

  for (int row = 0; row < h; row++){
    print_left_row(h, row);
    printf("  ");
    print_right_row(row);
    printf("\n");
  }
}

void print_right_row(int row){
    for(int col = 0; col <=  row; col++){
      printf("#");
    }
}

void print_left_row(int h , int row){
  for(int s = row; s  < h; s++){
    printf(" ");
  }
  print_right_row(row);
}
