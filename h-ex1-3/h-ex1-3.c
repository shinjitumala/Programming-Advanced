/* h-ex1-3.c
   hoshino.s.af
   Hoshino Shinjo */

#include<stdio.h>

void backYesterday(int *year, int *month, int *day);

int main(void){
  int days_back; //何日戻るかを保存する変数

  scanf("%d", &days_back); //入力を取り入れる

  int year, month, day; //必要な変数を用意
  scanf("%d/%d/%d", &year, &month, &day); //開始の日付を取り入れ

  int i; //n日前を計算
  for(i = 0; i < days_back; i++){
    backYesterday(&year, &month, &day);
  }

  if(year < 1970){
    fprintf(stderr, "NAN"); //1970/1/1以前にさかのぼった場合のエラー処理
    return 1;
  }else{
    printf("%d/%d/%d", year, month, day); //結果出力
  }

  return 0;
}

void backYesterday(int *year, int *month, int *day){ //昨日に戻る関数。
  int leap_year_month_days[13] = {31, 31, 29, 31, 30 ,31, 30 ,31 , 31, 30, 31, 30, 31}; //うるう年の月の日数
  int non_leap_year_month_days[13] = {31, 31, 28, 31, 30 ,31, 30 ,31 , 31, 30, 31, 30, 31}; //平年の月の日数

  --*day; //一日戻る
  if(*day == 0){ //日が０の場合は月を前に戻し、日を前の月の最後にする。この際に、うるう年かどうかの判定をしなければならない。
    --*month;
    if(*year % 100 == 0 && *year % 400 != 0){ //うるう年かどうかの判定。
      *day = non_leap_year_month_days[*month];
    }else if(*year % 4 == 0){
      *day = leap_year_month_days[*month];
    }else{
      *day = non_leap_year_month_days[*month];
    }
    if(*month == 0){ //月が０になった場合に、一年戻り、月を１２に戻す。
      --*year;
      *month = 12;
    }
  }
}
