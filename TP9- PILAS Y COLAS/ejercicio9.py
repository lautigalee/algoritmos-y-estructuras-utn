def encolar(cola, dato):
    cola.append(dato)
def desencolar(cola):
    return cola.pop(0)
def frente(cola):
    return cola[0]
def cola_vacia(cola):
    return len(cola) == 0
def unir(cola_a, cola_b, cola_ab):
    while not cola_vacia(cola_a):
        dato = desencolar(cola_a)
        encolar(cola_ab, dato)
    while not cola_vacia(cola_b):
        dato = desencolar(cola_b)
        encolar(cola_ab, dato)
cola_a = []
cola_b = []
cola_ab = []
na = int(input("Cantidad de elementos de COLA: "))
while na < 0:
    na = int(input("Cantidad inválida. Ingrese 0 o más: "))
for i in range(na):
    dato = int(input("Ingrese un elemento de COLA: "))
    encolar(cola_a, dato)
nb = int(input("Cantidad de elementos de COLB: "))
while nb < 0:
    nb = int(input("Cantidad inválida. Ingrese 0 o más: "))
for i in range(nb):
    dato = int(input("Ingrese un elemento de COLB: "))
    encolar(cola_b, dato)
unir(cola_a, cola_b, cola_ab)
if cola_vacia(cola_ab):
    print("COLAB está vacía")
else:
    print("COLAB:")
    while not cola_vacia(cola_ab):
        dato = desencolar(cola_ab)
        print(dato)