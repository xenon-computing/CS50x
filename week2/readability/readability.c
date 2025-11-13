#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int colman_liau_index(double L , double S);
int compute_grade(string text);

int main(void){

  string text = get_string("Text : ");
  int grade = compute_grade(text);

  if(grade < 1){
    printf("Before Grade 1\n");
  }else if (grade >= 16){
    printf("Grade 16+\n");
  }else{
    printf("Grade %d\n", grade);
  }
  

  return 0;
}

int colman_liau_index(double L , double S){
  double index = 0.0588 * L - 0.296 * S - 15.8;
  return round(index);
}

int compute_grade(string text){

  int length = strlen(text);
  int words , sentences , letters;
  words = sentences = letters = 0;

  for(int i = 0; i < length; i++){
    if(isalpha(text[i])){
      letters++;

    }else if(isspace(text[i])){
      words++;

    }else if(text[i] == '?' || text[i] == '!' || text[i] == '.'){
      sentences++;

    }
  }
  words++;

  //Computing L & S
  float L = (float)letters / words * 100;
  float S = (float)sentences / words * 100;

  return colman_liau_index(L, S);
}
