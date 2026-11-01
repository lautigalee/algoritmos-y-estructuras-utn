def apilar(pila, dato):
    pila.append(dato)
def desapilar(pila):
    return pila.pop()
def tope(pila):
    return pila[-1]
def pila_vacia(pila):
    return len(pila) == 0
def cargar_pila(n):
    pila = []
    for i in range(n):
        num = int(input("Ingrese un número: "))
        apilar(pila, num)
    return pila
def buscar(pila, x):
    aux = []
    encontrado = False
    while not pila_vacia(pila):
        dato = desapilar(pila)
        if x == dato:
            encontrado = True
        apilar(aux, dato)
    while not pila_vacia(aux):
        dato = desapilar(aux)
        apilar(pila, dato)
    return encontrado
def sumar(pila):
    aux = []
    suma = 0
    while not pila_vacia(pila):
        dato = desapilar(pila)
        suma += dato
        apilar(aux, dato)
    while not pila_vacia(aux):
        dato = desapilar(aux)
        apilar(pila, dato)
    return suma 
m = int(input("Ingrese la cantidad de clientes: "))
while m <= 0:
    m = int(input("Ingrese una cantidad válida: "))
for i in range(m):
    n = int(input("Ingrese la cantidad de números a cargar: "))
    while n <= 0:
        n = int(input("Ingrese un número válido: "))
    pila = cargar_pila(n)
    x = int(input("Ingrese el número X: "))
    if buscar(pila, x):
        clave = sumar(pila)
    else:
        clave = -1
    print("La clave del cliente es: ", clave)
