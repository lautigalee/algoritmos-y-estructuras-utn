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
def carga_pila(n):
    pila = []
    for i in range(n):
        entrada = int(input("Ingrese su numero de entrada: "))
        while entrada <= 0:
            entrada = int(input("Ingrese un numero válido: "))
        apilar(pila, entrada)
    return pila
def buscar(pila, x):
    aux = []
    encontrado = False
    while not pila_vacia(pila):
        dato = desapilar(pila)
        if dato == x:
            encontrado = True
        apilar(aux, dato)
    while not pila_vacia(aux):
        dato = desapilar(aux)
        apilar(pila, dato)
    return encontrado
def separar(pila, x):
    eliminados = 0
    encontrado = False
    aux = []
    cola = []
    while not pila_vacia(pila):
        dato = desapilar(pila)
        if dato == x:
            eliminados += 1
            encontrado = True
        elif encontrado == False:
            encolar(cola, dato)
        else:
            apilar(aux, dato)
    while not pila_vacia(aux):
            dato = desapilar(aux)
            apilar(pila, dato)
    return cola, eliminados
def mayor(cola):
    mayor = frente(cola)
    aux = []
    while not cola_vacia(cola):
        dato = desencolar(cola)
        if dato > mayor:
            mayor = dato
        encolar(aux, dato)
    while not cola_vacia(aux):
        dato = desencolar(aux)
        encolar(cola, dato)
    return mayor
def promedio(cola):
    suma = 0
    cant = 0
    aux = []
    while not cola_vacia(cola):
        dato = desencolar(cola)
        suma += dato
        cant += 1
        encolar(aux, dato)
    while not cola_vacia(aux):
        dato = desencolar(aux)
        encolar(cola, dato)
    prom = suma / cant
    return prom
def mostrar_pila(pila):
    if pila_vacia(pila):
        print("La pila quedó vacía")
    else:
        print("Pila resultante: ")
        while not pila_vacia(pila):
            dato = desapilar(pila)
            print(dato)
n = int(input("Ingrese la cantidad de asistentes: "))
while n <= 0:
    n = int(input("Ingrese una cantidad válida: "))
pila = carga_pila(n)
x = int(input("Ingrese un numero X: "))
while x <= 0:
    x = int(input("Ingrese un numero válido: "))
estaba = buscar(pila, x)
if estaba == True:
    print("El numero x estaba en la pila")
else:
    print("El numero x no estaba en la pila")
cola, eliminados = separar(pila, x)
print("La cantidad de eliminados fueron: ", eliminados)
if cola_vacia(cola):
    print("La cola quedó vacía!")
else:
    maximo = mayor(cola)
    print("El valor mayor de la cola fue: ", maximo)
    prom = promedio(cola)
    print(f"El promedio de los numeros de la cola fue {prom:.2f}")
mostrar_pila(pila)