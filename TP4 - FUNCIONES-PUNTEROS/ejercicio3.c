#include <stdio.h>

char calcularCondicion(int par1, int par2);

int main() {
    int n1, n2, nlib;
    int cantP = 0, cantR = 0, cantL = 0;
    char condicion;

    printf("Ingrese el numero de libreta universitaria (0 para salir): ");
    scanf("%d", &nlib);
    while(nlib != 0) {
        printf("Ingrese la nota del primer parcial: ");
        scanf("%d", &n1);
        printf("Ingrese la nota del segundo parcial: ");
        scanf("%d", &n2);
        condicion = calcularCondicion(n1, n2);
        printf("El alumno con libreta %d quedo: %c\n\n", nlib, condicion);
        switch(condicion) {
            case 'P': cantP++; break;
            case 'R': cantR++; break;
            case 'L': cantL++; break;
        }
        printf("Ingrese el numero de libreta universitaria (0 para salir): ");
        scanf("%d", &nlib);
    }

    printf("\n--- TOTALES DEL CURSO ---\n");
    printf("Cantidad de Promocionados: %d\n", cantP);
    printf("Cantidad de Regulares: %d\n", cantR);
    printf("Cantidad de Libres: %d\n", cantL);

    return 0;
}

char calcularCondicion(int par1, int par2) {
    float prom = (par1 + par2) / 2.0; 
    if (par1 >= 6 && par2 >= 6 && prom >= 7.0) {
        return 'P'; 
    }
    else if (par1 >= 6 && par2 >= 6) { 
        return 'R'; 
    }
    else {
        return 'L'; 
    }
}