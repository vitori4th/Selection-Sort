#include<stdio.h>
#include<stdlib.h>

typedef struct ponto{
  int x;
  int y;
}Ponto;

//Devolve -1 se a > b
//Devolve 0 se a == b
//Devolve 1 se a < b 
int compara(Ponto* a, Ponto* b){
     if(a->x > b->x){
        return -1;
     }
     if(a->x == b->x ){
        if(a->y > b->y)
            return -1;
        if(b->y > a->y)
            return 1;
     }
     return 0;
}

//Devolve o indice do maior elemento, obrigatoriamente 
//deve usar a função compara
int encontra_max(Ponto *v, int esq, int dir){
    int result = compara(&(v[esq]), &(v[dir]));
    if(dir==esq){
        return esq;
    }
    if(result== -1){
        return encontra_max(v, esq, dir-1);
    }
    else{
       return encontra_max(v, esq+1, dir);
    }
}

//Ordena os pontos, obrigatoriamente deve usar a função
//encontra_max
void selection_sort(Ponto *v, int tamanho){
    int indice_maior;
    for(int tam=tamanho-1;tam>0;tam--){
        indice_maior = encontra_max(v, 0, tam);
        Ponto temp = v[tam];
        v[tam]=v[indice_maior];
        v[indice_maior]=temp;
    }
}

int main(int argc, char * argv[]){
  int tamanho;  
  scanf("%d", &tamanho);
  Ponto * v = (Ponto *) malloc(sizeof(Ponto)*tamanho);
  
  srand(tamanho);
  for(int i = 0; i < tamanho; i++){
    v[i].x = rand()%tamanho;
    v[i].y = rand()%tamanho;
  }
  
  int indice_maior = encontra_max(v, 0, tamanho-1);

  printf("O maior é (%d, %d) ", v[indice_maior].x, v[indice_maior].y);
  printf("\n");
  
  selection_sort(v, tamanho);
  
  for(int i = 0; i < tamanho; i++){
    printf("(%d, %d) ", v[i].x, v[i].y);
  }
  printf("\n");
}