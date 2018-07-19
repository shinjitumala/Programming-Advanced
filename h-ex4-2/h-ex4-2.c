/* h-ex4-2.c
   hoshino.s.af
   Hoshino Shinji */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node { //構造体を宣言
  int v; //データ
  struct Node *next; //次のデータのポインタ
} Node;

void push(Node **first, int push_i){ //新しいデータを末尾にプッシュ
  Node *tmp = malloc(sizeof(Node)); //メモリ確保
  if (tmp == NULL){ //エラー処理
    printf("Error allocating memory!");
    exit(1);
  }

  tmp->v = push_i; //データを頭につける
  tmp->next = *first;
  *first = tmp;
}

int pop(Node **first){ //頭からデータをポップ
  int pop_i;
  Node *tmp = *first; //メモリ確保
  if (tmp == NULL){ //エラー処理
    return -1; //データがもうない場合は、マイナス１を返す。ASCIIにマイナス１はない。
  }

  pop_i = tmp->v; //データ処理
  *first = tmp->next;

  free(tmp); //メモリ解放

  return pop_i; //返り値
}

int main(void){
  Node *first = NULL; //リスト初期化
  int paren = 0; //かっこが対応しているかどうかの判定を保存する変数

  char *temp_c = malloc(sizeof(char)); //メモリ確保
  while(scanf("%c",temp_c) != EOF){ //EOFまで読み込み続ける
    //かっこの始まりを見つけた場合はリストにプッシュする
    if(*temp_c == '('){
      push(&first, (int) *temp_c);
    }else if(*temp_c == '{'){
      push(&first, (int) *temp_c);
    }else if(*temp_c == '['){
      push(&first, (int) *temp_c);
    }
    //かっこの終わりを見つけた場合はデータをポップし、かっこが対応していなければ、その判定を出す
    if(*temp_c == ')') {
      if(pop(&first) != 40){
        paren = 1;
        break;
      }
    }else if(*temp_c == '}') {
      if(pop(&first) != 123){
        paren = 1;
        break;
      }
    }else if(*temp_c == ']') {
      if(pop(&first) != 91){
        paren = 1;
        break;
      }
    }
  }
  free(temp_c); //メモリ解放

  if(pop(&first) != -1){ //対応するかっこがないかっこが残っていても１を返す
    paren = 1;
  }

  printf("%d", paren); //結果表示

  return 0;
}
