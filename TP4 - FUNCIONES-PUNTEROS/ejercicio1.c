#include <stdio.h>
#include <conio.h>
void imprimirserie(int inferior, int superior, int inc);
int main() {
    int limsup, liminf, incremento;
    do {
        printf("ingrese el valor del limite superior: ");
        scanf("%d", &limsup);
        printf("ingrese el valor del limite inferior: ");
        scanf("%d", &liminf);
        printf("ingrese el valor del incremento: ");
        scanf("%d", &incremento);
    if(limsup < liminf || limsup <= 0 || liminf <= 0 || incremento <= 0){
        printf("ERROR");
    }
}
while(limsup < liminf || limsup <= 0 || liminf <= 0 || incremento <= 0);
imprimirserie(liminf, limsup, incremento);
return 0;
}
void imprimirserie (int inferior, int superior, int inc) {
    int actual = inferior;

    while (actual <= superior)
    {
        printf("%d\n", actual);
        actual = actual + inc;
    }
}

