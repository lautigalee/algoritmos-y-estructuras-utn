#include <stdio.h>
#include <conio.h>
char sign (float numero);
int main() {
    float n;
    char signo;
    printf("Ingrese un numero: ");
    scanf("%f", &n);
    signo = sign(n);
    printf("el signo de %f es %c", n, signo);
}
char sign (float numero) {
char S;
if (numero > 0) S = '+';
if (numero < 0) S = '-';
if (numero == 0) S = ' ';
return S;
}