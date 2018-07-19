/* h-ex2-1.c
   hoshino.s.af
   Hoshino Shinji */

#include<stdio.h>

#define MAX_LENGTH 16

int string_length(int *s);

int main(void){
  char string_1[MAX_LENGTH], string_2[MAX_LENGTH]; //二つの文字列を保存する配列を用意

  scanf("%s %s", string_1, string_2); //二つの文字列入力を読み込む

  int string_length_1, string_length_2; //二つの文字列の長さを調べる
  string_length_1 = string_length(&string_1[0]);
  string_length_2 = string_length(&string_2[0]);

  int answer; //二つの文字列の長さに基づいて答えを出す
  if(string_length_1 == string_length_2){ //同じ長さならば、0
    answer = 0;
  }else if(string_length_1 > string_length_2){ //一番目の文字列の方が長ければ、1
    answer = 1;
  }else{ //それ以外、つまり二番目の文字列の方が長いならば、2
    answer = 2;
  }

  printf("%d", answer); //結果表示

  return 0;
}

int string_length(int *s){ //ヌル文字か来るまで変数iをインクリメントし、最後にiの値を返す
  int i;
  for(i = 0; *(s + i) != '\0'; i++){ //ヌル文字が来たら終了
  }

  return i; //返り値
}
