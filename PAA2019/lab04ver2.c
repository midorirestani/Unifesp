#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 1000

int minimo (int a, int b, int c){
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}
/*****************************************************************************************************************************
           01234        0123
Ex.: s1 = "gtgtc" s2 = "gtgt"
i=0 => results[0][j] = j, para todo 0<=j<=3
i=1, j=0 -> results[1][0] = i = 1
i=1, j=1 -> s1[0]==s2[0]? Y => results[1][1] = results[0][0] = 0
i=1, j=2 -> s1[0]==s2[1]? N => results[1][2] = 1 + minimo(results[1][1],results[0][2], results[0][1]) = 1 + minimo(0,2,1) = 1
i=1, j=3 -> s1[0]==s2[2]? Y => results[1][3] = results[0][2] = 2
i=2, j=0 -> results[2][0] = i = 2
i=2, j=1 -> s1[1]==s2[0]? N => results[2][1] = 1 + minimo(results[2][0],results[1][1], results[1][0]) = 1 + minimo(2,0,1) = 1
i=2, j=2 -> s1[1]==s2[1]? Y => results[2][2] = results[1][1] = 0
i=2, j=3 -> s1[1]==s2[2]? N => results[2][3] = 1 + minimo(results[2][2],results[1][3], results[1][2]) = 1 + minimo(0, 2, 1) = 1
i=3, j=0 -> results[3][0] = i = 3
i=3, j=1 -> s1[2]==s2[0]? Y => results[3][1] = results[2][0] = 2
i=3, j=2 -> s1[2]==s2[1]? N => results[3][2] = 1 + minimo(results[3][1],results[2][2], results[2][1]) = 1 + minimo(2, 0, 0) = 1
i=3, j=3 -> s1[2]==s2[2]? Y => results[3][3] = results[2][2] = 0
i=4, j=0 -> results[4][0] = i = 4
i=4, j=1 -> s1[3]==s2[0]? N => results[4][1] = 1 + minimo(results[4][0],results[3][1], results[2][0]) = 1 + minimo(4, 2, 2) = 3
i=4, j=2 -> s1[3]==s2[1]? Y => results[4][2] = results[3][1] = 2
i=4, j=3 -> s1[3]==s2[2]? N => results[4][3] = 1+minimo(results[4][2],results[3][3], results[3][2]) = 1 + minimo(2, 0, 1) = 1

  j
i 0 1 2 3       resultado final: results[n1][n2] => results[4][3] = 1 (verdadeiro)
  1 0 1 2
  2 0 0 1
  3 2 1 0
  4 3 2 1
*******************************************************************************************************************************/

int mindist(char s1[], char s2[], int n1, int n2){
  int results[n1+1][n2+1];
  int i, j;

  for(i=0; i<=n1; i++){
    for(j=0; j<=n2; j++){
      if(i==0) results[i][j]=j;
      else if(j==0) results[i][j]=i;
      else if(s1[i-1]==s2[j-1]) results[i][j]=results[i-1][j-1];
      else results[i][j] = 1 + minimo(results[i][j-1], results[i-1][j], results[i-1][j-1]);
    }
  }
  return results[n1][n2];
}
int main() {

  char seq1[LENGTH], seq2[LENGTH];

  scanf("%[^\n]", seq1);
  //printf("sequencia 1: %s\n", seq1);
  getchar();
  scanf("%[^\n]", seq2);
  getchar();
  //printf("sequencia 2: %s\n", seq2);
  int len1 = strlen(seq1), len2 = strlen(seq2);
  printf("%d\n", mindist(seq1, seq2, len1, len2));
  return 0;
}
