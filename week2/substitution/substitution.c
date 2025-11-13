#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int check_duplicate(string);
void encrypt(string , string);
int test_input(string);


int main(int argc, string argv[]){
  if(argc == 2){
    if(test_input(argv[1])){
      string plain_text = get_string("Plain text : ");
      encrypt(plain_text, argv[1]);
      return 0;
    }
    return 1;
    
  }
  else{
    printf("USAGE : %s key\n",argv[0]);
    return 1;
  }
  
}

int test_input(string text){
  int has_duplicate = check_duplicate(text);

  if(has_duplicate){
    printf("Key must not be contain duplicate character!\n");
    return 0;
  }
  else if(strlen(text) != 26){
    printf("Key must be 26 characters long\n");
    return 0;
  }

  return 1;
 
}

int check_duplicate(string text){
  int length = strlen(text);
  
  for(int i = 0; i < length ; i++){
    for (int j = 0; j < length ; j++){
      if(text[i] == text[j] && i != j){
        return 1;
      }
    }
  }

  return 0;
}


void encrypt(string plain_text, string key){
  int length = strlen(plain_text);
  char c;

  printf("Ciper Text : ");

  for(int i = 0; i < length ; i++){
    if(islower(plain_text[i])){
      c = key[toupper(plain_text[i]) - 65];
      printf("%c",tolower(c));
    }
    else if(!isalpha(plain_text[i])){
      printf("%c",plain_text[i]);
    }
    else{
      c = key[plain_text[i] - 65];
      printf("%c",c);
    }
  }
  printf("\n");

}
