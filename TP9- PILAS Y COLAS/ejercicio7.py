def encolar(cola, dato):
    cola.append(dato)
def desencolar(cola):
    return cola.pop(0)
def frente(cola):
    return cola[0]
def cola_vacia(cola):
    return len(cola) == 0
cola = []
aux = []
n = int(input("Ingrese la cantidad de pacientes: "))
while n <= 0:
    n = int(input("Ingrese una cantidad válida: "))
for i in range(n):
    nivel = int(input("Ingrese el nivel de urgencia (entre 1 y 100): "))
    while nivel <= 0 or nivel > 100:
        nivel = int(input("Ingrese un nivel válido: "))
    encolar(cola, nivel)
maxima = frente(cola)
suma = 0
cantidad = 0
while not cola_vacia(cola):
    dato = desencolar(cola)
    if dato > maxima:
        maxima = dato
    suma += dato
    cantidad += 1
    encolar(aux, dato)
while not cola_vacia(aux):
    dato = desencolar(aux)
    encolar(cola, dato)
print("El numero más alto de urgencia fue: ", maxima)
prom = suma/cantidad
print(f"El promedio de urgencias fue: {prom:.2f}")
nuevo = int(input("Ingrese el nivel de urgencia (entre 1 y 100): "))
while nuevo <= 0 or nuevo > 100:
    nuevo = int(input("Ingrese un nivel válido: "))
encolar(cola, nuevo)
k = int(input("Ingrese el valor K: "))
while k <= 0 or k > 100:
    k = int(input("Ingrese un valor válido para K: "))
eliminados = 0
while not cola_vacia(cola):
    dato = desencolar(cola)
    if dato == k:
        eliminados += 1
    else:
        encolar(aux, dato)
while not cola_vacia(aux):
    dato = desencolar(aux)
    encolar(cola, dato)
print("La cantidad de pacientes dados de alta fueron: ", eliminados)
