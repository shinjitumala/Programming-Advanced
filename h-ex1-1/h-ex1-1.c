/* h-ex1-1.c
   hoshino.s.af
   hoshino Shinji */

#include<stdio.h>

#define SIZE 3
#define DATA_COUNT 9

void squareMatrix(int *matrix);

int main(void){
  int data[DATA_COUNT];                                                       //入力される三次正方行列を保存する配列

  int i;                                                                      //入力データ取り入れ
  for(i = 0; i < DATA_COUNT; i++){
    scanf("%d", &data[i]);
  }

  int *matrix;                                                                //ポインタ変数を宣言
  matrix = &data[0];
  squareMatrix(matrix);                                                       //squareMatrix()にポインタ変数を引数として入れて、計算を行う。また、出力も合わせて行う。

  return 0;
}

void squareMatrix(int *matrix){                                               //行列の二乗計算及び結果出力
  int i, sum, row, column;
  for(i = 0; i < DATA_COUNT; i++){
    row = i / SIZE;                                                           //計算のための下準備
    column = i % SIZE;
                                                                              //そのマスの数を計算
    sum = *(matrix + (SIZE * row)) * *(matrix + (column)) + *(matrix + (SIZE * row + 1)) * *(matrix + (column + SIZE * 1)) + *(matrix + (SIZE * row + 2)) * *(matrix + (column + SIZE * 2));

    printf("%d", sum);                                              //結果出力
    if(i != DATA_COUNT - 1){
      printf(" ");
    }
  }
}
