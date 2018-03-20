#include <stdio.h>

/**********************************************************************************/
//最初に成績順ソートせず、ペア同士の差を求めてしまった後、それの最小値を見つけるパターン
/**********************************************************************************/

int main(void){
  int n, x, i, j, k;
  int z,w;
  int tensu[50][50]; //入力された点数格納用
  int diff[50][50];  //差を入れておく配列
  int min[50];   //最小値格納用
  int jun = 0;   //ループごとに配列を使い分ける用  

  while(1){
    scanf("%d", &n);
    if(n == 0)
      break; //入力終了
    if(n < 2 || n > 1000){
      printf("number of people error! Please 2~1000\n");
      continue;
    }
    
    for(i=0; i<n; i++){
      scanf("%d", &x); 
      tensu[jun][i] = x;
      if(tensu[jun][i] < 0 || tensu[jun][i] > 1000000){   //成績エラー（1,000,000以下の正整数を入力）
	printf("score error! Please 0~1000000\n");
	//break;
      }
    }
    
    int d = 0;
    for(z = 0; z < n-1; z++){
      for(w = 0; w < n-1-z; w++){
	diff[jun][d] = abs(tensu[jun][z]-tensu[jun][w+1+z]);
	d++;
      }
    }
    
    min[jun] = diff[jun][0];
    
    for(j=1; j<d; j++){
      if(min[jun] > diff[jun][j]){
	min[jun] = diff[jun][j];
      }
    }
    
    jun++;  
  }
  
  printf("\n");
  for(k=0; k<jun; k++){
    if(min[k] < 1000000)
      printf("%d\n", min[k]);  //答えの出力
  }
  return 0;
}

