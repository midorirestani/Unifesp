
#include <stdio.h>
#include <stdlib.h>

typedef long long int llint;//tipo arquivos (quantidade de arquivos)

llint m0=1, mf=1, n=1;

void imprimeArqs(llint *arq, llint n){
    llint i;
      printf("arq = [" );
      for(i=0; i<n; i++){
        printf(" %lli", arq[i] );
      }
      printf("]\n");
}

void imprimeN(llint n){
  printf("valor de n é: %lli\n", n );
}

llint merge(llint *subarq, llint *aux, llint esq, llint meio, llint dir){
    llint i, j, p, cont;

    //imprimeArqs(subarq, dir+1);
    for(i = esq; i<=meio; i++){
      aux[i] = subarq[i];
    }

    for(j=meio+1;j<=dir; j++){
      aux[dir+(meio+1)-j] = subarq[j];
    }

    i = esq; j= dir; cont = 0;

    for(p=esq; p<=dir; p++){
      if(aux[i]<= aux[j]){
        subarq[p]=aux[i];
        i++;
      }
      else{
        subarq[p]=aux[j];
        j--;
        cont = cont+ (meio-i+1);
      }
      //imprimeArqs(subarq, dir+1);
    }

      return cont;
}
llint mergeSort(llint *arq, llint *aux, llint esq, llint dir){
    llint meio, cont = 0;

    //  imprimeArqs(arq, dir+1);
    if(esq < dir){
      meio = esq + (dir - esq)/2;
      cont = mergeSort(arq, aux, esq, meio) + mergeSort(arq, aux, (meio+1), dir) + merge(arq, aux, esq, meio, dir );

    }
    //imprimeArqs(arq, dir+1);
    return cont;
}





int main (){
    llint n, i,*arq, *aux;

    scanf("%lli",&n );
    //imprimeN(n);

    arq = (llint *)calloc(n, sizeof(llint));
    aux = (llint *)calloc(n, sizeof(llint));
    for(i=0; i<n; i++){
      scanf("%lli", &arq[i]);
    }
    llint trocas;
    trocas = mergeSort(arq, aux, 0, n-1);
    //imprimeArqs(arq, n);
    printf("%lli\n", trocas );

    free(arq);
    free(aux);
    return 0;
}
