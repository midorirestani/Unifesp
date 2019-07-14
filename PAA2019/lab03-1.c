#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int tam, unsigned int *vet ){
    int i;
    printf("[ ");
    for( i =0; i<tam; i++){
      if(i < tam-1){
        printf("%d, ", vet[i]);
      }
      else{
        printf("%d ]\n", vet[i] );
      }
    }
}

int comparaVetor(int n, int m, unsigned int *vet1, unsigned int *vet2){
    int i, j, cont=0; //0-> vet2 não está contido em vet1, 1->vet2 está contido em vet1
    i=0;j=0;
    if(n!= m)return 0;

    for(i=0; i<m; i++){
      if(vet1[i]!=vet2[i]) return 0;
    }

    return 1;
}

unsigned int* dobraVet(int p, int n, unsigned int *vet, int *new_size){
    unsigned int* aux;
    int i, j;
    /*apenas inverte o vetor*/
    if(p == 0 || p == n){
      *new_size = n;
      aux = (unsigned int*)calloc(*new_size, sizeof(unsigned int));
      for(i=0; i<n; i++){
        aux[i] = vet[n-i-1];
      }
    }
    /*parte dos últimos elementos passam a ocupar as primeiras posições e os demais são somados*/
    else if(p<(n+1)/2){
      *new_size=n-p;
      j=0;
      int k=0;
      aux = (unsigned int*)calloc(*new_size, sizeof(unsigned int));
      for (i=n-1; i>= p; i--) {
          if((p-(i- p))>0){
            aux[k] = vet[i]+vet[j];
            j++;
          }
          else{
            aux[k] = vet[i];
          }
          k++;
      }
    }
    else{
      *new_size=p;
      aux = (unsigned int*) calloc (*new_size, sizeof(unsigned int));

      for (i = 0; i<p;i++ ) {
          if(p+i>=n) aux[p-i-1]=vet[p-i-1];
          else{
            aux[p-i-1]=vet[p+i]+vet[p-i-1];
          }
      }
    }
    //imprimeVetor(tam, aux);
    return aux;
}

int flag = 0;
int backtracking(int n, unsigned int *vet1, int m, unsigned int *vet2){
  unsigned int *aux;
  int tam = n, i;
  if(n<m) return 0;
  if(n==m){
    if(comparaVetor(n, m, vet1, vet2)==0){
      aux = dobraVet(0, n, vet1, &tam);
    }
    else{
      flag = 1;
      return 1;
    }
    return comparaVetor(tam,m,aux,vet2);
  }
  if(n>m){
      //testando as n posições
      i=0;
      while(flag == 0 && i<n){
        aux = dobraVet(i, n,vet1, &tam);
        if(comparaVetor(tam,m,aux, vet2) == 1){
          flag = 1;
          return flag;
        }
        i++;
      }
      flag = backtracking(tam, aux, m, vet2);

  }
}

int main() {
  int n, m;

/********* sequência original*********/
  scanf("%d", &n);

  unsigned int *seq0 = (unsigned int*)calloc(n, sizeof(unsigned int));
  int i;

  for(i=0; i<n; i++){
    scanf("%d", &seq0[i]);
  }

/********* sequência modificada *********/
  scanf("%d", &m);
  unsigned int *seqm = (unsigned int*)calloc(m, sizeof(unsigned int));

 for(i=0; i<m; i++){
    scanf("%d", &seqm[i]);
  }

 int status = backtracking(n, seq0, m, seqm);
  //imprimeVetor(n, seq0);
  //imprimeVetor(m, seqm);
  if (status == 1) {
    printf("S\n");
  }
  else{
      printf("N\n");
    }
  return 0;
}
