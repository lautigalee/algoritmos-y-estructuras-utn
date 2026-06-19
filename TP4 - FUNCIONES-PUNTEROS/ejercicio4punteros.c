#include <stdio.h>
void tiempo (int segundos, int *horas, int *min, int *seg);
int main() {
	int segundostotales, h, m, s;
    printf("ingrese la cantidad total de segundos a convertir: ");
    scanf("%d", &segundostotales);
    tiempo (segundostotales, &h, &m, &s);
    printf("el equivalente es %d horas, %d minutos y %d segundos", h, m, s);
	return 0;
}
void tiempo (int segundos, int *horas, int *min, int *seg) {
int restosegundos;
*horas = segundos/3600;
restosegundos = segundos % 3600;
*min = restosegundos/60;
*seg = restosegundos % 60;
}


