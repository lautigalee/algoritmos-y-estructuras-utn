#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int numeroguia, categoriacontenedor, cont1 = 0, cont2 = 0, cont3 = 0, bandera = 1, menorcat = 0, menor_guia = 0, esprimo = 1, i;
    float peso, pesocont1 = 0, pesocont2 = 0, pesocont3 = 0, menorpeso = 0, prom1 = 0, prom2 = 0, prom3 = 0;
    
    printf("ingrese el numero de guia: ");
    scanf("%d", &numeroguia);
    
    while (numeroguia != 0) {
        printf("ingrese la categoria del contenedor: ");
        scanf("%d", &categoriacontenedor);
        while (categoriacontenedor < 1 || categoriacontenedor > 3) {
            printf("ingrese una categoria valida: ");
            scanf("%d", &categoriacontenedor);
        }
        
        printf("ingrese el peso registrado: ");
        scanf("%f", &peso);
        
        switch (categoriacontenedor) {
            case 1:
                pesocont1 += peso;
                cont1++;
                break;
            case 2:
                pesocont2 += peso;
                cont2++;
                break;
            case 3:
                pesocont3 += peso;
                cont3++;
                break;
        }
        
        if (bandera == 1) {
            menorpeso = peso;
            menorcat = categoriacontenedor;
            menor_guia = numeroguia; 
            bandera = 0;
        }
        else {
            if (peso < menorpeso) {
                menorpeso = peso;
                menorcat = categoriacontenedor;
                menor_guia = numeroguia; 
            }
        }
        
        printf("ingrese el nuevo numero de guia (0 para salir): ");
        scanf("%d", &numeroguia);
    }

    if (cont1 != 0) { prom1 = (float)pesocont1 / cont1; }
    if (cont2 != 0) { prom2 = (float)pesocont2 / cont2; }
    if (cont3 != 0) { prom3 = (float)pesocont3 / cont3; }
    
    int total_entero = (int)pesocont1;

    if (total_entero <= 1) {
        esprimo = 0; 
    } else {
        esprimo = 1; 
        for (i = 2; i <= total_entero - 1; i++) {
            if (total_entero % i == 0) {
                esprimo = 0; 
                break;       
            }
        }
    }
    
    printf("\n============ REPORTES FINALES ============\n");
    printf("1. Promedio peso Categoria 1: %.2f toneladas\n", prom1);
    printf("1. Promedio peso Categoria 2: %.2f toneladas\n", prom2);
    printf("1. Promedio peso Categoria 3: %.2f toneladas\n", prom3);
    printf("------------------------------------------\n");
    
    if (bandera == 0) {
        printf("2. El contenedor mas liviano fue de la guia %d (Categoria %d) con %.2f toneladas\n", menor_guia, menorcat, menorpeso);
    } else {
        printf("2. No se registraron camiones.\n");
    }
    printf("------------------------------------------\n");

    if (esprimo == 1 && total_entero > 1) {
        printf("3. El total de peso de la Categoria 1 (%d) es un numero primo\n", total_entero);
    } else {
        printf("3. El total de peso de la Categoria 1 (%d) no es un numero primo\n", total_entero);
    }
    printf("==========================================\n");
    
    return 0;
}