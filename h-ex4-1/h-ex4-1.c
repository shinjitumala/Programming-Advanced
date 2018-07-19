/* h-ex4-1.c
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
    printf("Data missing!");
    exit(1);
  }
  pop_i = tmp->v; //データ処理
  *first = tmp->next;
  free(tmp); //メモリ解放
  return pop_i; //返り値
}

int main(void){
  Node *first = NULL; //リストの初期化

  while(1){
    char input_1[20] = "push", input_2[20] = "pop", input_3[20] = "printstack";
    char *input = malloc(sizeof(char) * 20); //入力は最大19文字になっている。

    if(scanf("%s", input) == EOF){ //ヌルな行で終了
      break;
    }else if(strcmp(input, input_3) == 0){ //printstackが入力された場合
      Node *tmp = first; //メモリ確保
      if (tmp == NULL){ //エラー処理
        printf("End of data or error allocating memory!");
        exit(1);
      }
      while(1){
        if(tmp->next == NULL){ //最後のデータ
          printf("%d\n", tmp->v);
          break;
        }else{ //最後以外
          printf("%d ", tmp->v);
          tmp = tmp->next;
        }
      }
    }else if(strcmp(input, input_2) == 0){ //popが入力されたとき
      printf("%d\n", pop(&first));
    }else if(strcmp(input, input_1) == 0){ //pushが入力されたとき
      int *i = malloc(sizeof(int));
      if (i == NULL){ //エラー処理
        printf("Error allocating memory!");
        exit(1);
      }

      scanf("%d", i); //データ取り入れ

      push(&first, *i); //データをプッシュ

      free(i); //メモリ解放
    }

    free(input); //メモリ解放
  }

  return 0;
}
