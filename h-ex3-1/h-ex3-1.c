/* h-ex3-1.c
   hoshino.s.af
   Hoshino Shinji */

#include<stdio.h>

typedef struct complex { //複素数の構造体を宣言
  double re;
  double im;
} complex;

struct complex multipleComplex(struct complex,struct complex); //二つの複素数の乗算を行う関数

int main(void){
  complex com_1, com_2, answer; //入力された複素数を保存する変数、答えの複素数を保存する変数

  //入力された複素数を取り入れる
  scanf("%lf %lf", &com_1.re, &com_1.im);
  scanf("%lf %lf", &com_2.re, &com_2.im);

  //答えを計算
  answer = multipleComplex(com_1, com_2);

  //答えの表示
  printf("%.4lf %.4lf", answer.re, answer.im);

  return 0; //正常終了
}

struct complex multipleComplex(struct complex com_1, struct complex com_2){ //二つの複素数の乗算を行う関数
  double a_re, a_im; //答えの実数部分と虚数部分を保存する変数

  //乗算を行う
  a_re = com_1.re * com_2.re - com_1.im * com_2.im;
  a_im = com_1.re * com_2.im + com_1.im * com_2.re;

  //答え
  complex answer = {
    a_re, a_im
  };

  return answer; //答えを返り値として返す
}
