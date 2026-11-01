def encolar(cola, dato):
    cola.append(dato)
def desencolar(cola):
    return cola.pop(0)
def frente(cola):
    return cola[0]
def cola_vacia(cola):
    return len(cola) == 0
def cargar_cola(n):
    cola = []
    for i in range(n):
        peso = float(input("Ingrese el peso: "))
        while peso <= 0:
            peso = float(input("Ingrese un peso válido: "))
        encolar(cola, peso)
    return cola
def maximo(cola):
    aux = []
    maximo = frente(cola)
    while not cola_vacia(cola):
        dato = desencolar(cola)
        if dato > maximo:
            maximo = dato
        encolar(aux, dato)
    while not cola_vacia(aux):
        dato = desencolar(aux)
        encolar(cola, dato)
    return maximo
def promedio(cola, n):
    aux = []
    prom = 0
    suma = 0
    while not cola_vacia(cola):
        dato = desencolar(cola)
        suma += dato
        encolar(aux, dato)
    while not cola_vacia(aux):
        dato = desencolar(aux)
        encolar(cola, dato)
    prom = suma/n
    return prom
def filtrar_pesados(cola):
    aux = []
    cola_nueva = []
    while not cola_vacia(cola):
        dato = desencolar(cola)
        if dato > 10:
            encolar(cola_nueva, dato)
        encolar(aux, dato)
    while not cola_vacia(aux):
        dato = desencolar(aux)
        encolar(cola, dato)
    return cola_nueva
def mostrar_cola(cola):
    if cola_vacia(cola):
        print("La cola está vacía")
    else:
        aux = []
        print("Cola resultante:")
        while not cola_vacia(cola):
            dato = desencolar(cola)
            print(dato)
            encolar(aux, dato)
        while not cola_vacia(aux):
            dato = desencolar(aux)
            encolar(cola, dato)
def contar(cola):
    cant = 0
    aux = []
    while not cola_vacia(cola):
        dato = desencolar(cola)
        cant+=1
        encolar(aux, dato)
    while not cola_vacia(aux):
        dato = desencolar(aux)
        encolar(cola, dato)
    return cant
n = int(input("Ingrese la cantidad de pesos: "))
while n <= 0:
    n = int(input("Ingrese una cantidad válida: "))
cola = cargar_cola(n)
mayor = maximo(cola)
print("El máximo peso registrado fue: ", mayor)
prom = promedio(cola, n)
print(f"El promedio de pesos registrados fue: {prom:.2f} ")
pesados = filtrar_pesados(cola)
mostrar_cola(pesados)
cantidad = contar(pesados)
print("La cantidad de elementos en la segunda cola son: ", cantidad)