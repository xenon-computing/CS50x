#include <stdio.h>
#include <cs50.h>
#include <math.h>
/*
 * In this credit card validation problem , we're going to use 
 * popular Luhn's algorithm to validate mathmatical relationships
 * or simply speaking checksum calculation of credit card numbers
 * without explicitly requiring resource intensive database query
 * to syntactically validate the numbers*/

int get_last_digit(long unsigned int );
int get_sum_digit(long unsigned int , int );
int get_digits_from_first(long unsigned int , int ,int );
int checksum(long unsigned int);
void check_vendor(long unsigned int );

int main(){
  long unsigned int credit_card_number;
  do{
    credit_card_number = get_long("Number : ");
  }while(!credit_card_number);

  check_vendor(credit_card_number);
  //printf("Checksum result is : %d", checksum(credit_card_number));
  return 0;
}

int get_last_digit(long unsigned int n)
{
  return n % 10;
}

int get_sum_digit(long unsigned int n , int p)
{
  if(n < 10){
    return p+= n;
  }
  int d;

  do{
    d = get_last_digit(n);
    p += d;
    n -= d;
    n /= 10;
  }while(n > 0);

  return p;
}

int checksum(long unsigned int credit_card_number){

  //long unsigned int credit_card_number;
  int digit, sum_digit_f = 0 , sum_digit_s = 0, pos = 1,temp=0;  
  do {
    digit = get_last_digit(credit_card_number);

    if(pos % 2 == 0){

      temp = digit*2;
      sum_digit_f = get_sum_digit(temp , sum_digit_f);

    }else{
      sum_digit_s += digit;
    }
    credit_card_number -= digit;
    credit_card_number /= 10;
    pos += 1;
  }while (credit_card_number > 0);

  int sum = sum_digit_s + sum_digit_f;
  if (sum % 10 == 0){
    return 1;
  }
  return 0;
}

void check_vendor(long unsigned int credit_card_number){
  int is_valid = checksum(credit_card_number);

  if (is_valid){
    int digit13 = get_digits_from_first(credit_card_number, 13, 1);
    int digit15 = get_digits_from_first(credit_card_number, 15, 2);
    int digit16 = get_digits_from_first(credit_card_number, 16,2);
    
    if(digit13 == 4){
      printf("VISA\n");
    }else if(digit15 == 34 || digit15 == 37){
      printf("AMEX\n");
    }else if(digit16 >= 51 && digit16 <= 55){
      printf("MASTERCARD\n");
    }else if(get_digits_from_first(digit16, 2, 1) == 4){
      printf("VISA\n");
    }

  }else{
    printf("INVALID\n");
  }
}

int get_digits_from_first(long unsigned int n , int r, int d){
  int digit = n / pow(10,r-d);
  return digit;
}
