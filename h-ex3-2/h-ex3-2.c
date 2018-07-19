/* h-ex3-1.c
   hoshino.s.af
   Hoshino Shinji */

#include<stdio.h>
#include<stdlib.h>

typedef struct { //複素数の構造体を宣言
  double re;
  double im;
} complex;

void multipleComplex(complex *); //二つの複素数の乗算を行う関数

int main(void){
  complex *com; //入力された複素数を保存する変数、答えの複素数を保存する変数


  com = malloc(sizeof(complex) * 3); //メモリ確保
  if(com == NULL){ //エラー処理
    printf("Error while allocating memory!");
    return 1;
  }
  //入力された複素数を取り入れる
  scanf("%lf %lf", &com[0].re, &com[0].im);
  scanf("%lf %lf", &com[1].re, &com[1].im);

  //答えを計算
  multipleComplex(com);

  //答えの表示
  printf("%.4lf %.4lf", com[2].re, com[2].im);

  free(com); //メモリ解放

  return 0; //正常終了
}

void multipleComplex(complex *com){ //二つの複素数の乗算を行う関数
//乗算を行う
  com[2].re = com[0].re * com[1].re - com[0].im * com[1].im;
  com[2].im = com[0].re * com[1].im + com[0].im * com[1].re;

}
