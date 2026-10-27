def apilar(pila, dato):
    pila.append(dato)
def desapilar(pila):
    return pila.pop()
def tope(pila):
    return pila[-1]
def pila_vacia(pila):
    return len(pila) == 0
pila = []
aux = []
n = int(input("Operación (1-Escribir, 2-Borrar, 3-Copiar, 4-Pegar, 0-Fin): "))
while n < 0 or n > 4:
    n = int(input("Código inválido. Ingrese 0, 1, 2, 3 o 4: "))
while n != 0:
    apilar(pila, n)
    n = int(input("Operación (1-Escribir, 2-Borrar, 3-Copiar, 4-Pegar, 0-Fin): "))
    while n < 0 or n > 4:
        n = int(input("Código inválido. Ingrese 0, 1, 2, 3 o 4: "))
if not pila_vacia(pila):
    print("La operación al tope de la pila es:", tope(pila))
else:
    print("No hay operaciones registradas")
if not pila_vacia(pila):
    codigo = int(input("Código a contar (1-Escribir, 2-Borrar, 3-Copiar, 4-Pegar): "))
    while codigo < 1 or codigo > 4:
        codigo = int(input("Código inválido. Ingrese 1, 2, 3 o 4: "))
    cont = 0
    while not pila_vacia(pila):
        dato = desapilar(pila)
        if dato == codigo:
            cont += 1
        apilar(aux, dato)
    while not pila_vacia(aux):
        dato = desapilar(aux)
        apilar(pila, dato)
    print("La operación se realizó", cont, "veces")
    codigo_eliminar = int(input("Código a eliminar (1-Escribir, 2-Borrar, 3-Copiar, 4-Pegar): "))
    while codigo_eliminar < 1 or codigo_eliminar > 4:
        codigo_eliminar = int(input("Código inválido. Ingrese 1, 2, 3 o 4: "))
    eliminadas = 0
    while not pila_vacia(pila):
        dato = desapilar(pila)
        if dato == codigo_eliminar:
            eliminadas += 1
        else:
            apilar(aux, dato)
    while not pila_vacia(aux):
        dato = desapilar(aux)
        apilar(pila, dato)
    print("Operaciones eliminadas:", eliminadas)
    if pila_vacia(pila):
        print("La pila quedó vacía")
    else:
        print("Pila resultante (de tope a base):")
        while not pila_vacia(pila):
            dato = desapilar(pila)
            print(dato)
            apilar(aux, dato)
        while not pila_vacia(aux):
            dato = desapilar(aux)
            apilar(pila, dato)