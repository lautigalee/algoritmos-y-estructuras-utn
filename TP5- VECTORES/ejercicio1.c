#include <stdio.h>
void cargarVector(int vector[50]);
void mostrarVector(int vector[50]);
int main() {
	int productos[50];
    cargarVector(productos);
    mostrarVector(productos);
	return 0;
}
void cargarVector(int vector[50]) {
    int i;
    for (i = 0; i < 50; i++) {
        vector[i] = (i+1) * 2;
    }
}
void mostrarVector(int vector[50]) {
    int i;
    for(i = 0; i < 50; i++){
        printf("\n%d", vector[i]);
}
}