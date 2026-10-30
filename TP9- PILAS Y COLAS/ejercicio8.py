def encolar(cola, dato):
    cola.append(dato)
def desencolar(cola):
    return cola.pop(0)
def frente(cola):
    return cola[0]
def cola_vacia(cola):
    return len(cola) == 0
def depurar(cola, valor):
    aux = []
    while not cola_vacia(cola):
        dato = desencolar(cola)
        if dato > valor:
            encolar(aux, dato)
    while not cola_vacia(aux):
        dato = desencolar(aux)
        encolar(cola, dato)
cola = []
n = int(input("Ingrese la cantidad de datos: "))
while n <= 0:
    n = int(input("Cantidad inválida. Ingrese un número mayor a 0: "))
for i in range(n):
    numero = float(input("Ingrese un número (entero o real): "))
    encolar(cola, numero)
valor = float(input("Ingrese el valor de corte: "))
depurar(cola, valor)
if cola_vacia(cola):
    print("La cola quedó vacía")
else:
    print("Cola resultante:")
    while not cola_vacia(cola):
        dato = desencolar(cola)
        print(dato)