/*******************************************************************
Projete um algoritmo que retorne o troco de 'n' centavos com o
número mínimo de moedas.

moedas:
1 cent, 5 cent, 10 cent, 25 cent, 50 cent, 1 real.
*******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#define INT_MAX 99999


int min(int a, int b){
  if(a >= b) return a;
  else return b;
}
int moedaDP(int troco, int moedas[], int n){
  // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[troco+1];

    // Base case (If given value V is 0)
    table[0] = 0;

    // Initialize all table values as Infinite
    for (int i=1; i<=troco; i++)
        table[i] = INT_MAX;

    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=troco; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<n; j++)
          if (moedas[j] <= i)
          {
              int sub_res = table[i-moedas[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    return table[troco];
}

int main(int argc, char const *argv[]) {
  int moedas[]={1, 5, 10, 25};
  int n = sizeof(moedas)/sizeof(moedas[0]);
  int qtd, troco;
  scanf("%d", &troco);

  printf("%d\n",moedaDP(troco, moedas, n));
  return 0;
}
