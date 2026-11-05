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
def generarpilaycola(n):
    pila = []
    cola = []
    for i in range(n):
        peso = float(input(f"Ingrese el peso del paquete {i+1}"))
        while peso <= 0:
            peso = float(input("Ingrese un peso válido: "))
        cod = int(input(f"Ingrese el código de zona del paquete {i+1} (4 dígitos): "))
        while cod < 1000 or cod > 9999:
            cod = int(input("Ingrese un código válido: "))
        encolar(cola, peso)
        apilar(pila, cod)
    return cola, pila
def generarnuevacola(pila, cola):
    nuevacola = []
    pilaaux = [] 
    cola_respaldo = []
    pila_respaldo = []
    while not cola_vacia(cola):
        peso = desencolar(cola)
        cod = desapilar(pila)
        encolar(cola_respaldo, peso)
        apilar(pila_respaldo, cod)
        unidad = cod % 10                 
        decena = (cod // 10) % 10          
        centena = (cod // 100) % 10        
        millar = cod // 1000
        if millar == unidad and centena == decena:
            encolar(nuevacola, peso)
        else:
            apilar(pilaaux, peso)
    while not cola_vacia(cola_respaldo):
        encolar(cola, desencolar(cola_respaldo))
    while not pila_vacia(pila_respaldo):
        apilar(pila, desapilar(pila_respaldo))
    return nuevacola, pilaaux
def procesoscola(nuevacola):
    cant1 = 0
    suma = 0
    cant2 = 0
    total = 0
    prom = 0
    porc = 0
    aux = []
    while not cola_vacia(nuevacola):
        dato = desencolar(nuevacola)
        total += 1
        if dato > 5.5:
            cant1 += 1
            suma += dato
        if dato <= 2:
            cant2 += 1
        encolar(aux,dato)
    while not cola_vacia(aux):
        dato = desencolar(aux)
        encolar(nuevacola, dato)
    if cant1 != 0:
        prom = suma / cant1
    if cant2 != 0:
        porc = (cant2 * 100) / total
    return prom, porc
def generarnuevapila(pilaaux):
    nuevapila = []
    aux = []
    cant = 0
    suma = 0
    prom = 0
    while not pila_vacia(pilaaux):
        dato = desapilar(pilaaux)
        cant += 1
        suma += dato
        apilar(aux, dato)
    if cant != 0:
        prom = suma/cant
    while not pila_vacia(aux):
        dato = desapilar(aux)
        if dato > prom:
            apilar(nuevapila, dato)
        else:
            apilar(pilaaux, dato)
    return nuevapila
n = int(input("Ingrese la cantidad de paquetes: "))
while n < 10 or n % 3 != 0:
    n = int(input("Ingrese una cantidad válida: "))
cola, pila = generarpilaycola(n)
nuevacola, pilaaux = generarnuevacola(pila, cola)
prom, porc = procesoscola(nuevacola)
print(f"Promedio de pesos (> 5.5 kg): {prom}")
print(f"Porcentaje de paquetes (<= 2.0 kg): {porc}%")
pila_final = generarnuevapila(pilaaux)
print(f"Pila resultante: ")
if pila_vacia(pila_final):
    print("La pila final quedó vacía.")
else:
    while not pila_vacia(pila_final):
        print(desapilar(pila_final))