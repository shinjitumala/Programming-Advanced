/* h-ex2-2.c
   hoshino.s.af
   Hoshino Shinji */

#include<stdio.h>

#define MAX_LENGTH 16

int string_same(char *s1, char *s2);

int main(void){
  char string_1[MAX_LENGTH], string_2[MAX_LENGTH]; //二つの文字列を保存する配列を用意

  scanf("%s %s", string_1, string_2); //二つの文字列入力を読み込む

  int answer; //二つの文字列に基づいて答えを出す
  answer = string_same(&string_1[0], &string_2[0]);

  if(answer == 0){ //結果表示
    printf("False");
  }else{
    printf("True");
  }

  return 0;
}

int string_same(char *s1, char *s2){
  int i = 0;
  while(*(s1 + i) != '\0' || *(s2 + i) != '\0'){
    if(*(s1 + i) > 96 && *(s1 + i) < 123){ //小文字を大文字に直す
      *(s1 + i) = *(s1 + i) - 32;
    }
    if(*(s2 + i) > 96 && *(s2 + i) < 123){ //小文字を大文字に直す
      *(s2 + i) = *(s2 + i) - 32;
    }

    if(*(s1 + i) == *(s2 + i)){
      i++;
    }else{
      return 0; //一致しない文字があれば、0を返す
    }
  }
  return 1; //完全一致であれば、1を返す
}
