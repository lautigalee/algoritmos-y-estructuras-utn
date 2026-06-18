#include <stdio.h>
void procesarViaje(float km, float rendimiento, float cargados, float *totKm, float *totCons, float *totCarg);
int main() {
	int N, i;
    float totCarg = 0, totKm = 0, totCons = 0, km, rendimiento, cargados, sobrante = 0, eficiencia = 0;
    printf("Ingrese la cantidad de viajes: ");
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        printf("Ingrese los kilometros: ");
        scanf("%f", &km);
        printf("Ingrese el rendimiento: ");
        scanf("%f", &rendimiento);
        printf("Ingrese los litros cargados: ");
        scanf("%f", &cargados);
        procesarViaje(km, rendimiento, cargados, &totKm, &totCons, &totCarg);
    }
    printf("\n el total de litros cargados fue de: %.2f", totCarg);
    printf("\n el total de litros consumidos fue de: %.2f", totCons);
    sobrante = totCarg - totCons;
    printf("\n el combustible sobrante fue: %.2f", sobrante);
    eficiencia = totKm / totCarg;
    printf("\n la eficiencia promedio fue de: %.2f", eficiencia);
	return 0;
}
void procesarViaje(float km, float rendimiento, float cargados, float *totKm, float *totCons, float *totCarg) {
    float consumoviaje;
    consumoviaje = km / rendimiento;
    printf("el consumo estimado del viaje es de: %.2f\n", consumoviaje);
    *totKm = *totKm + km;
    *totCons = *totCons + consumoviaje;
    *totCarg = *totCarg + cargados;
}