#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 1000

int minimo (int a, int b, int c){
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}


int mindist(char s1[], char s2[], int n1, int n2){
  if(n1==0) return n2;
  if(n2==0) return n1;
  if(!strcmp(s1, s2)) return 0;
  if(s1[n1-1]==s2[n2-1]) return mindist(s1,s2, n1-1, n2-1);

  return 1 + minimo(mindist(s1, s2, n1, n2-1),mindist(s1, s2, n1-1, n2),mindist(s1, s2, n1-1, n2-1));
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
