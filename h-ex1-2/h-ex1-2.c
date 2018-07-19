/* h-ex1-2.c
   hoshino.s.af
   Hoshino Shinji */

#include<stdio.h>

void calcFib(int n, int *array);

int main(void){
  int num;
  scanf("%d", &num);                                                          //フィボナッチ数列の何項目までが欲しいかという入力を取り入れる。

  int fib[num + 1];                                                           //必要な分の配列を用意

  int *p_fib;                                                                 //ポインタ変数の用意
  p_fib = &fib[0];

  calcFib(num, p_fib);                                                        //配列のポインタと欲しい項の数を入れてcalcFibを呼び出し

  int i;
  for(i = 0; i <= num; i++){                                                  //結果出力
    printf("%d", fib[i]);
    if(i != num){
      printf(" ");
    }
  }

  return 0;
}

void calcFib(int n, int *array){                                              //フィボナッチ数列の第n項までをポインタを頼りに書き換える。
  if(n == 0){                                                                 //フィボナッチ数列の再帰的定義に従って計算
    *(array + n) = 0;
  }else if(n == 1){
    calcFib(0, array);                                                        //n=1が入力された時のために、これを入れる
    *(array + n) = 1;
  }else{
    calcFib(n - 1, array);
    *(array + n) = *(array + (n - 2)) + *(array + (n - 1));
  }
}
