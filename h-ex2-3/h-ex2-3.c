/* h-ex2-3
   hoshino.s.af
   Hoshino Shinji */

#include<stdio.h>

#define MAX_LINES 1000
#define MAX_PER_LINE 201
#define MAX_S 16

int main(int argc, char **argv){
  if(argc != 2){ //引数の数が想定と異なる時
    fprintf(stderr, "Usage: %s prob_file\n", argv[0]);
  }

  char *fname; //ファイル名
  FILE *fp; //ファイルポインタ

  fname = argv[1];
  fp = fopen(fname, "r");
  if(fp == NULL){ //エラー処理
    fprintf(stderr, "Error reading file: %s", fname);
    return 1;
  }

  char string[MAX_S];
  char *sp1 = string; //のちのアクセスのために設定
  scanf("%s", string); //探す文字列の入力を取り入れる

  int i = 0;
  while(*(sp1 + i) != '\0'){
    if(*(sp1 + i) > 96 && *(sp1 + i) < 123){ //小文字を大文字に直す
      *(sp1 + i) = *(sp1 + i) - 32;
    }
    i++;
  }

  char read_line[MAX_PER_LINE]; //今読んでいる行の文字列
  int line_num = 1, read_num, b_match, string_num = 0, first_output = 0; //行番号、読んでいる文字の前からの番号、文字列一致の判定に使う変数、探す文字列の何文字目かを保存、出力をしたかどうかの判定
  char *sp2 = read_line; //あとでread_lineを書き換えるときに使うポインタ
  while(fgets(read_line, 201, fp) != NULL){ //sと一致する文字列を探す
    read_num = 0, b_match = 0, string_num = 0;

    while(*(sp2 + read_num) != '\0'){
      if(*(sp2 + read_num) > 96 && *(sp2 + read_num) < 123){ //小文字を大文字に直す
        *(sp2 + read_num) = *(sp2 + read_num) - 32;
      }
      read_num++;
    }

    read_num = 0;

    while(*(sp2 + read_num) != '\0'){ //ヌル文字にたどり着くまで検索

      if(b_match == 0){ //まだ何も検知していない場合
        if(*(sp2 + read_num) == *(sp1)){ //頭の文字が一致したら、検知するモードに入る
          b_match = 1;
          string_num++;
          read_num++;
        }else{
          read_num++;
        }

      }else if(b_match == 1){ //頭からstring_numまでが一致しているとき
        if(*(sp2 + (read_num + string_num - 1)) == *(sp1 + string_num)){ //文字が一致したら次の文字もチェック
          string_num++;
        }else{
          b_match = 0;
          string_num = 0;
        }
      }

      if(*(sp1 + string_num) == '\0'){ //チェックで最後まで達したらその時点で探す文字列が含まれているので行番号を出力
        string_num = 0;
        if(first_output == 0){
          printf("%d", line_num);
          first_output = 1;
          break;
        }else{
          printf(" %d", line_num);
          break;
        }

      }

    }
    line_num++;
  }

  if(first_output == 0){ //文字列が見つからない場合の処理
    printf("Not found");
  }

  return 0;
}
