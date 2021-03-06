//220107_058_Sirico_Davide.c
/*
Ci sono 2 gare di 10 atleti con punteggio [1..50] 
ordinate gara1 e gara2 in modo decrescente
scrivere gli atleti che hanno realizzato i 3 migliori tempi tenendo conto delle due gare

es di 2 gare tra 5 atleti: (1 7 sta per atleta1 con punteggio 7)
gara1: 1  7, 2 21, 3 12, 4 45, 5 13
gara2: 1 17, 2 20, 3 12, 4 41,	5 18

ordinamento gara 1
4 45, 2 21, 5 13, 3 12, 1 7

ordinamento gara 2
4 41, 2 20, 5 18, 1 17, 3 12

3 migliori tempi:
4 45, 4 41, 2 21 
(cioè l'atleta4 si piazza al primo posto con 45 e al secondo posto con 41, terzo l'atleta2 con 21)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10

void trova_max(int [][DIM], int [][DIM], int [][3]);
void sort(int [][DIM]);
void visualizza(int [][DIM]);
void carica(int [][DIM]);
int main(){
    srand(time(NULL));
    int m1[2][DIM],m2[2][DIM];
    int max[2][3];
    int i;
    
    carica(m1);
    carica(m2);
    printf("Gara 1:\n");
    visualizza(m1);
    printf("Gara 2:\n");
    visualizza(m2);
    sort(m1);
    sort(m2);
    printf("Gara 1:\n");
    visualizza(m1);
    printf("Gara 2:\n");
    visualizza(m2);
    trova_max(m1,m2,max);
    
    printf("I massimi 3 valori sono: ");
    for(i=0;i<3;i++){
        printf("%d nella posizione %d\n",max[0][i],max[1][i]);
    }
    return 0;
}

void trova_max(int m1[2][DIM], int m2[2][DIM], int max[2][3]){
    int c1,c2,i;
    c1=c2=0;
    i=0;
    while((c1+c2)<3){
        if(m1[0][c1]>m2[0][c2]){
            max[0][i]=m1[0][c1];
            max[1][i]=m1[1][c1];
            c1++;
        } else {
            max[0][i]=m2[0][c2];
            max[1][i]=m2[1][c2];
            c2++;
        }
        i++;
    }
}

void sort(int m[2][DIM]){
    int i,j,temp;
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM-i-1;j++){
            if(m[0][j]<m[0][j+1]){
                temp=m[0][j];
                m[0][j]=m[0][j+1];
                m[0][j+1]=temp;
                temp=m[1][j];
                m[1][j]=m[1][j+1];
                m[1][j+1]=temp;
                
            }
        }
    }

}

void carica(int m[2][DIM]){
    int i;
    for(i=0;i<DIM;i++){
        m[1][i]=i+1;
        m[0][i]=rand()%49+1;
    }
}

void visualizza(int m[2][DIM]){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<DIM;j++){
            printf("%3d",m[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}