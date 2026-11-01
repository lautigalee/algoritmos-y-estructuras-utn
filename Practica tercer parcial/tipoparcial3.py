def apilar(pila, dato):
    pila.append(dato)
def desapilar(pila):
    return pila.pop()
def tope(pila):
    return pila[-1]
def pila_vacia(pila):
    return len(pila) == 0
def encolar(cola, dato):
    cola.append(dato)
def desencolar(cola):
    return cola.pop(0)
def frente(cola):
    return cola[0]
def cola_vacia(cola):
    return len(cola) == 0
def cargar_pila(n):
    pila = []
    for i in range(n):
        peso = float(input("Ingrese el peso: "))
        while peso <= 0:
            peso = float(input("Ingrese un valor válido: "))
        apilar(pila, peso)
    return pila
def generar_colas(pila):
    colaliv = []
    colapes = []
    while not pila_vacia(pila):
        dato = desapilar(pila)
        if dato <= 5:
            encolar(colaliv, dato)
        else:
            encolar(colapes, dato)
    return colaliv, colapes
def maximo(cola):
    aux = []
    mayor = frente(cola)
    while not cola_vacia(cola):
        dato = desencolar(cola)
        if dato > mayor:
            mayor = dato
        encolar(aux, dato)
    while not cola_vacia(aux):
        dat = desencolar(aux)
        encolar(cola, dat)
    return mayor
def promedio(cola):
    aux = []
    suma = 0
    cant = 0
    while not cola_vacia(cola):
        dato = desencolar(cola)
        suma += dato
        cant += 1
        encolar(aux, dato)
    while not cola_vacia(aux):
        dat = desencolar(aux)
        encolar(cola, dat)
    prom = suma / cant
    return prom
def porcentaje(cola, n):
    aux = []
    cant = 0
    porc = 0
    while not cola_vacia(cola):
        dato = desencolar(cola)
        cant += 1
        encolar(aux, dato)
    while not cola_vacia(aux):
        dat = desencolar(aux)
        encolar(cola, dat)
    porc = (cant / n) * 100
    return porc
def cantidad(cola):
    aux = []
    cant = 0
    while not cola_vacia(cola):
        dato = desencolar(cola)
        if dato < 1:
            cant += 1
        encolar(aux, dato)
    while not cola_vacia(aux):
        dat = desencolar(aux)
        encolar(cola, dat)
    return cant
n = int(input("Ingrese la cantidad de pesos: "))
while n <= 0:
    n = int(input("Ingrese una cantidad válida: "))
pila = cargar_pila(n)
liviana, pesada = generar_colas(pila)
if cola_vacia(pesada):
    print("La cola pesada quedó vacia! ")
else:
    mayor = maximo(pesada)
    print("El máximo peso de la cola pesada fue: ", mayor)
porc = porcentaje(pesada, n)
print("El porcentaje de pesos pesados sobre el total fue: ", porc)
if cola_vacia(liviana):
    print("La cola liviana quedó vacía! ")
else:
    prom = promedio(liviana)
    cant = cantidad(liviana)
    print(f"El promedio de pesos livianos fue {prom:.2f}")
    print("La cantidad de livianos menores a 1 kg fueron: ", cant)