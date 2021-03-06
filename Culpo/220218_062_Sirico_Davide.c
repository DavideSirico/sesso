//220218_062_Sirico_Davide.c
/*
62> dato una matrice numerica quadrata m dimensionato DIM=10 con caricamento contestuale a piacere [10..90].
visualizzare la matrice.
Riga dispari ordinata in modo crescente
Riga pari ordinata in modo decrescente
visualizzare la matrice.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10

void visualizza(int [][DIM]);
void sort(int [][DIM]);
void carica(int [][DIM]);
int main(){
    srand(time(NULL));
    int m[DIM][DIM];
    carica(m);
    visualizza(m);
    sort(m);
    visualizza(m);
    return 0;
}

void visualizza(int m[DIM][DIM]){
    int i,j;
    for(i=0;i<DIM;i++){
       for(j=0;j<DIM;j++){
            printf("%3d ",m[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

void carica(int m[DIM][DIM]){
    int i,j;
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            m[i][j]=rand()%80+10; 
        }
    }
}

void sort(int m[DIM][DIM]){
    int i,j,k;
    int temp;
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM-1;j++){
            for(k=j+1;k<DIM;k++){
                if(m[i][j]>m[i][k] && i%2==0){
                    temp=m[i][j];
                    m[i][j]=m[i][k];
                    m[i][k]=temp;
                } else if(m[i][j]<m[i][k] && i%2==1){
                    temp=m[i][j];
                    m[i][j]=m[i][k];
                    m[i][k]=temp;
                }
            }
        }
    }
}