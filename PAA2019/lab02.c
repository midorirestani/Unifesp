#include <stdio.h>
#include <stdlib.h>
#define N_MAX 1001
#define K_MAX 999

void imprimeMatriz(int nl, int nc, int **matriz){
  int i, j;

  for(i=0; i<nl; i++){
    for(j=0; j<nc; j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void removeAresta(int p, int n, int **matriz){
  int i,j;

//  printf("cont[%d] = %d\n",p, matriz[p][0] );
  for(i=0; i<n; i++){
      matriz[p][0]=0;
      matriz[p][i+1]=0;
      if(matriz[i][p+1]==1){
        matriz[i][0]--;
        matriz[i][p+1]=0;
      }
  }
}
int numConvidados(int n, int p,int k, int **convidados){
  int cont=0, i, j;

  //imprimeMatriz(n, n+1, convidados);

  if(p<k) return 0;
  else{
      for(i=0; i<n; i++){
        if(convidados[i][0]<k){
          removeAresta(i, n, convidados);
          //imprimeMatriz(n, n+1, convidados);
        }
      }
      for(i=0; i<n; i++){
        if(convidados[i][0]<k){
          removeAresta(i, n, convidados);
          //imprimeMatriz(n, n+1, convidados);
        }
      }
    }


  for(i=0; i<n; i++){
    if(convidados[i][0] >= k) cont++;
  }

  return cont;
}

int main(void) {
  int n, p, k, r1, r2;

  scanf("%d", &n);

  if(n<N_MAX){
    int **comunidade;
    comunidade = (int**)calloc(n,sizeof(int*));
    int i, j;

    for(i=0; i<n; i++){
      comunidade[i] = (int*)calloc(n+1, sizeof(int)); //coluna 0 é a coluna de contadores
    }
    //imprimeMatriz(n,n+1,comunidade);
    scanf("%d %d", &p, &k);

    for (i=0; i<p; i++){
      scanf("%d %d", &r1, &r2);
      if(r1!=r2 && comunidade[r1-1][r2]!= 1 && comunidade[r2-1][r1] != 1){
        comunidade[r1-1][r2]++;
        comunidade[r2-1][r1]++;
        comunidade[r1-1][0]++;
        comunidade[r2-1][0]++;
      }
    }
    //imprimeMatriz(n,n+1,comunidade);
    int convidados = numConvidados(n, p, k, comunidade);
    printf("%d\n", convidados);
  }
  return 0;
}
