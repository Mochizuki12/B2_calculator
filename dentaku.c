#include<stdio.h>
#include<math.h>

#define PI 3.14159265358979323846

int help();
int main(void){
  double a, x, ans;
  int mode, fg, input_error;
  char sign, fc, nan;
  
  ans = 0;
  a = 0;
  x = 0;
  mode = 1;
  input_error = 0;
  
  printf("初めに値を入力し,エンターを押してください。ヘルプは(h1)関数計算モード時は(fh1)\n(ヘルプや関数計算モードへの切り替えは二回目の入力以降)\n");
  scanf("%lf%*c",&ans);
  
  while(fg != 1){
  
  
  switch(mode){
  
  case 1:/*四則演算モード----------------------------------------------------------------------------------------------------------------*/
      scanf("%c%lf%*c", &sign, &a);
      
      switch(sign){
      
      case'+':
        ans = ans + a;
        break;
        
      case'-':
        ans = ans - a;
        break;
        
      case'*':
        ans = ans * a;
        break;
        
      case'/':
        ans = ans / a;
        break;
        
      case'h':
        help();
        break;
        
      case'f':
        break;
        
      case'q':
        break;
        
      case'c':
        a = 0;
        ans = 0;
        x = 0;
        break;
        
      default:
      printf("不正な符号またはコマンドです。ヘルプは(h1)、関数計算モード時は(fh1)\n");
      break;
      
      }
        
      if((sign == 'f') && (a == 1)){
        mode = 2;
        printf("fanction\n");
        break;
        }
        
      if(sign == 'q'){
        fg=1;
        break;
        }
        
      if(sign == '+' || sign == '-' || sign == '*' || sign == '/'){
        if(ceil(ans) == floor(ans)){
          printf("=%.lf\n", ans);
          }
        else{
        printf("=%lf\n", ans);
          }
        }
     break;
      
      
  case 2:/*関数モード--------------------------------------------------------------------------------------------------------------------------*/
   scanf(" %c%c%lf%*c", &sign, &fc, &x);
   switch(fc){
     case'h':
     help();
     break;
     case'a':
     break;
     case 's':
     x = sin(x*(PI/180));
     break;
     case 'c':
     if(sign == 'f'){
       a = 0;
       ans = 0;
       x = 0;
       }
     else{
       x = cos(x*(PI/180));
       }
     break;
     case 't':
     x = tan(x*(PI/180));
     break;
     case 'r':
     x = sqrt(x);
     break;
     case 'l':
     x = log10(x);
     break;
     default:
     printf("不正な符号または値です。ヘルプは(h1)、関数計算モードの場合(fh1)\n");
     input_error = 1;
     break;
    }
   switch(sign){
      
      case'+':
        ans = ans + x;
        break;
        
      case'-':
        ans = ans - x;
        break;
        
      case'*':
        ans = ans * x;
        break;
        
      case'/':
        ans = ans / x;
        break;
        
      case'f':
        break;
        
      case'q':
        break;
        
      default:
      printf("不正な符号または値です。ヘルプは(h1)、関数計算モード時は(fh1)\n");
      input_error = 1;
      break;
      
      }
      if(fc == 'a'){
        mode = 1;
        printf("artithmetic\n");
        break;
        }
      if(sign == 'q'){
        fg=1;
        break;
        }
      if(sign == '+' || sign == '-' || sign == '*' || sign == '/'){
        if(ceil(ans) == floor(ans)){
          printf("=%.lf\n", ans);
          }
        else{
        printf("=%lf\n", ans);
          }
        }
      else{
        input_error = 0;
        }
      break;
      
   default:
     printf("error");
  }
  }
}

int help(){
 printf("-----------------------------------------------------------------\n");
 printf("初期操作；初めに値を入力しエンター。次に符号と値を入力しエンターで計算ができます。\n");
 printf("入力例:20+20*80を計算したいとき；20(エンター)　→　+20(エンター)　→　*80(エンター)\n");
 printf("-----------------------------------------------------------------\n");
 printf("四則演算モード時のヘルプ\n");
 printf("入力方法；(符号)(値)\n入力例；+20 (+20の場合)\n");
 printf("f1 関数計算モードに切り替え\n");
 printf("quit 終了\n");
 printf("c0(関数計算モード時はfc0) すべての値を削除\n");
 printf("-----------------------------------------------------------------\n");
 printf("関数計算モード時のヘルプ\n");
 printf("入力方法；(符号)(関数の頭文字)(値)\n入力例；+s90 (+sin90°の場合)\n");
 printf("s sin\n");
 printf("c cos\n");
 printf("t tan\n");
 printf("l log(常用対数の計算)\n");
 printf("r ルート\n");
 printf("ar0 四則演算モードに切り替え\n");
 printf("quit 終了\n");
 printf("-----------------------------------------------------------------\n");
}
