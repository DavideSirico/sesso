//strcat.c
#include <stdio.h>
#define DIM 80

void my_strcat(char [], char []);
int main(){
    char s1[DIM],s2[DIM];

    printf("Inserire la 1 stringa: ");
    gets(s1);
    fflush(stdin);
    printf("Inserire la 2 stringa: ");
    gets(s2);
    fflush(stdin);
    my_strcat(s1,s2);
    puts(s1);
    puts(s2);
    return 0;
}

void my_strcat(char s1[DIM], char s2[DIM]){
    int i,l_dest,l_orig;
    for(i=0;s1[i]!='\0';i++);
    l_dest=i;
    for(i=0;s2[i]!='\0';i++);
    l_orig=i;

    for(i=0;i<l_orig;i++){
        s1[l_dest+i]=s2[i];
    }
    s1[l_dest+i]='\0';
}