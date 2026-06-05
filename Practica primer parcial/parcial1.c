#include <stdio.h>

int main() {
	int idventa, tipoprod, ventas1 = 0, ventas2 = 0, ventas3 = 0, ventastotales = 0, bandera = 1, mayoridventa = 0;
	float montoventa, mayormonto = 0, prom1, prom2, prom3;
	printf("ingrese el id de la venta (-1 para salir): ");
	scanf("%d", &idventa);
	while (idventa != -1) {
		printf("ingrese el tipo de producto vendido (1 para libros, 2 para apuntes, 3 para articulos de libreria): ");
		scanf("%d", &tipoprod);
		while(tipoprod < 1 || tipoprod > 3) {
			printf("ingrese un tipo de producto valido: ");
			scanf("%d", &tipoprod);
		}
		printf("ingrese el monto de la venta: ");
		scanf("%f", &montoventa);
		switch (tipoprod){
		case 1:
			ventas1 ++;
			break;
		case 2:
			ventas2 ++;
			break;
		case 3:
			ventas3 ++;
			break;
		}
		if(bandera == 1){
			mayoridventa = idventa;
			mayormonto = montoventa;
			bandera = 0;
		}
		else {
			if (montoventa > mayormonto){
				mayoridventa = idventa;
				mayormonto = montoventa;
			}
		}
		printf("ingrese el id de la venta (-1 para salir): ");
		scanf("%d", &idventa);
	}
	ventastotales = ventas1 + ventas2 + ventas3;
	if(ventastotales != 0){
		prom1 = ((float) ventas1 / ventastotales) * 100;
	}
	if (ventastotales != 0){
		prom2 = ((float) ventas2 / ventastotales) * 100;
		}
	if (ventastotales != 0){
		prom3 = ((float) ventas3/ ventastotales) * 100;
	}
	printf("\nel porcentaje de ventas de libros fue de %.2f", prom1);
	printf("\nel porcentaje de ventas de apuntes fue de %.2f", prom2);
	printf("\nel porcentaje de ventas de articulos de libreria fue de %.2f", prom3);
	printf("\nel id de la venta con mayor monto registrado fue %d", mayoridventa);
	printf("\neste monto fue de %.2f", mayormonto);
	return 0;
}