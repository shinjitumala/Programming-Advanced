/* h-ex3-3.c
   hoshino.s.af
   Hoshino Shinji */

#include<stdio.h>
#include<stdlib.h>

#define MAX_LINES 1000
#define MAX_PER_LINE 201
#define MAX_S 16

int string_length(char *s);

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

  //長さを調べるために仮読み込み
  char *sp_t1, *sp1;
  sp_t1 = malloc(sizeof(char) * MAX_S); //メモリ確保
  if(sp_t1 == NULL){ //エラー処理
    printf("Error while allocating memory!");
    return 1;
  }
  scanf("%s", sp_t1); //探す文字列の入力を取り入れる
  int string_l_1 = string_length(sp_t1);
  //メモリを適切に確保して再度取り入れ
  sp1 = malloc(sizeof(char) * (string_l_1 + 1));
  int l;
  for(l = 0; l < string_l_1; l++){
    *(sp1 + l) = *(sp_t1 + l);
  }
  *(sp1 + l) = '\0'; //後ろにヌル文字を入れる
  free(sp_t1);

  int i = 0;
  while(*(sp1 + i) != '\0'){
    if(*(sp1 + i) > 96 && *(sp1 + i) < 123){ //小文字を大文字に直す
      *(sp1 + i) = *(sp1 + i) - 32;
    }
    i++;
  }

  char *read_line = NULL; //今読んでいる行の文字列
  int read_num, b_match, string_num = 0, count = 0; //行番号、読んでいる文字の前からの番号、文字列一致の判定に使う変数、探す文字列の何文字目かを保存
  char *sp2; //あとでread_lineを書き換えるときに使うポインタ
  while(1){ //sと一致する文字列を探す

    read_line = malloc(sizeof(char) * MAX_PER_LINE); //メモリ確保
    if(read_line == NULL){ //エラー処理
      printf("Error while allocating memory!");
      return 1;
    }


    if(fgets(read_line, MAX_PER_LINE, fp) == NULL){ //ヌルな行を読み込んだら、終了
      free(read_line);
      break;
    }

    int string_l_2 = string_length(read_line);
    //メモリを適切に確保して再度取り入れ
    sp2 = malloc(sizeof(char) * (string_l_2 + 1));

    for(l = 0; l < string_l_2; l++){
      *(sp2 + l) = *(read_line + l);
    }
    *(sp2 + l) = '\0'; //後ろにヌル文字を入れる
    free(read_line); //メモリ解放

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
        if(*(sp2 + read_num) == *(sp1 + string_l_1 - 1)){ //頭の文字が一致したら、検知するモードに入る
          b_match = 1;
          string_num++;
          read_num++;
        }else{
          read_num++;
        }

      }else if(b_match == 1){ //頭からstring_numまでが一致しているとき
        if(*(sp2 + (read_num + string_num - 1)) == *(sp1 + string_l_1 - 1 - string_num)){ //文字が一致したら次の文字もチェック
          string_num++;
        }else{
          b_match = 0;
          string_num = 0;
        }
      }

      if(string_num == string_l_1){ //チェックで最後まで達したらその時点で探す文字列が含まれているので行番号を出力
        string_num = 0;

        count++;
        break;
      }

    }
    free(sp2); //メモリ解放
  }

  printf("%d", count); //結果を表示

  free(sp1); //メモリ解放

  return 0;
}

int string_length(char *s){ //ヌル文字か来るまで変数iをインクリメントし、最後にiの値を返す
  int i;
  for(i = 0; *(s + i) != '\0'; i++){ //ヌル文字が来たら終了
  }

  return i; //返り値
}
