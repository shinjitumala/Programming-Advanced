/* h-ex4-3.c
   hoshino.s.af
   Hoshino Shinji */

#include<stdio.h>
#include<stdlib.h>

typedef struct Customer {
  int i; //Customer ID
  int k; //Customer buy count
  struct Customer *next;
} Customer;

void enqueue(Customer **first, Customer **last, int id, int buy_count){ //リストの末尾にデータを追加する関数
  Customer *tmp = malloc(sizeof(Customer)); //メモリ確保
  if(tmp == NULL){ //エラー処理
    fprintf(stderr, "Error allocating memory!");
    exit(1);
  }

  //客のデータを追加
  tmp->i = id;
  tmp->k = buy_count;
  tmp->next = NULL;

  if(*first == NULL){ //データがまだない時はfirstとして入れる
    *first = tmp;
  }else{ //それ以外の時は末尾につける
    (*last)->next = tmp;
  }
  *last = tmp;

  return;
}

void dequeue(Customer **first, Customer **last, int *id, int *buy_count){ //リストの頭からデータを取り出す
  Customer *tmp = *first; //firstが指しているデータを取り出し
  if(tmp == NULL){ //データがもうない場合はエラーを返す
    fprintf(stderr, "Error finding data!");
    exit(1);
    return;
  }

  //データ処理
  *id = tmp->i;
  *buy_count = tmp->k;
  *first = tmp->next;

  free(tmp); //メモリ解放

  return;
}

void print_line(Customer **first){
  Customer *tmp = *first; //メモリ確保

  //客の列を表示
  while(1){
    if(tmp->next == NULL){
      printf("C%d\n", tmp->i);
      break;
    }else{
      printf("C%d ", tmp->i);
      tmp = tmp->next;
    }
  }
}

int main(void){
  Customer *first = NULL, *last = NULL; //リストの初期化

  int customer_count, max_per_buy; //客の人数、一度の会計で買える最大の数を保存する変数
  //パラメーター取り入れ
  scanf("%d", &customer_count);
  scanf("%d", &max_per_buy);
  //客データ取り入れ
  int i, temp;
  for(i = 0; i < customer_count; i++){
    scanf("%d", &temp);
    enqueue(&first, &last, i + 1, temp);
  }
  //初期化完了


  //会計処理開始
  int temp_id, temp_count; //客のデータを処理するときに使う変数
  while(1){
    print_line(&first); //客の列を表示
    dequeue(&first, &last, &temp_id, &temp_count); //先頭の会計
    temp_count = temp_count - max_per_buy;

    if(temp_count > 0){ //欲しい文がまだ買えていないときは並び直し
      enqueue(&first, &last, temp_id, temp_count);
    }else{
      customer_count--; //満足して帰った人を数える
    }

    if(customer_count == 0){ //客がいなくなったら終了
      break;
    }
  }

  return 0;
}
