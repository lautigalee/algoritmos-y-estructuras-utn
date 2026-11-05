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
def cargarcola(n):
    cola = []
    pila = []
    for i in range(n):
        imp1 = float(input("Ingrese el importe del primer artículo: "))
        while imp1 <= 0:
            imp1 = float(input("Ingrese un valor válido: "))
        imp2 = float(input("Ingrese el importe del segundo artículo: "))
        while imp2 <= 0:
            imp2 = float(input("Ingrese un valor válido: "))
        imp3 = float(input("Ingrese el importe del tercer artículo: "))
        while imp3 <= 0:
            imp3 = float(input("Ingrese un valor válido: "))
        total = imp1 + imp2 + imp3
        encolar(cola, total)
        menor = imp1
        if imp2 < menor:
            menor = imp2
        if imp3 < menor:
            menor = imp3
        apilar(pila, menor)
    return cola, pila
def diasmasde15000(cola):
    aux = []
    cont = 0
    while not cola_vacia(cola):
        dato = desencolar(cola)
        if dato > 15000:
            cont += 1
        encolar(aux, dato)
    while not cola_vacia(aux):
        dato = desencolar(aux)
        encolar(cola, dato)
    return cont
n = int(input("Ingrese la cantidad de días: "))
while n <= 0:
    n = int(input("Ingrese una cantidad válida: "))
cola, pila = cargarcola(n)
cantidad = diasmasde15000(cola)
print("La cantidad de días que tuvieron importe mayor a 15000 fueron: ", cantidad)
print("Cola resultante: ")
while not cola_vacia(cola):
    dato = desencolar(cola)
    print(dato)
print("Pila resultante: ")
while not pila_vacia(pila):
    dato = desapilar(pila)
    print(dato)


