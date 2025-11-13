#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

const int SCORES[] = {
  1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,
  1,1,1,1,4,4,8,4,10
};

int compute_score(string phrase);

int main(void){
  string word1 = get_string("Player1: ");
  string word2 = get_string("Player2: ");

  int score1 = compute_score(word1);
  int score2 = compute_score(word2);

  if(score1 > score2){
    printf("Player 1 wins!\n");
  }else if(score1 == score2){
    printf("Tie!\n");
  }else{
    printf("Player 2 wins!\n");
  }

  return 0;
}

int compute_score(string phrase){
  int length = strlen(phrase);
  int score = 0;

  for(int i = 0;i < length; i++){
    if(isalpha(phrase[i])){
      score += SCORES[toupper(phrase[i]) - 65];
    }
  }

  return score;
}
