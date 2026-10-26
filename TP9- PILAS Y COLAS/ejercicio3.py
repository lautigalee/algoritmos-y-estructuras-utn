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
n = int(input("Ingrese la cantidad de temperaturas: "))
while n <= 0:
    n = int(input("Ingrese una cantidad válida: "))
for i in range(n):
    temp = float(input("Ingrese la temperatura expresada en grados: "))
    apilar(pila, temp)
print("Temperatura: ")
while not pila_vacia(pila):
    temp = desapilar(pila)
    print(temp)
    apilar(aux, temp)
while not pila_vacia(aux):
    dato = desapilar(aux)
    apilar(pila, dato)
print("La temperatura que se encuentra en el tope es: ", tope(pila))
nuevatemp = float(input("Ingrese la temperatura expresada en grados: "))
pos = int(input("Ingrese la posicion en la que quiere colocar la temperatura: "))
while pos <= 0 or pos > n+1:
    pos = int(input("Ingrese una posicion válida: "))
for i in range(pos - 1):
    dato = desapilar(pila)
    apilar(aux, dato)
apilar(pila, nuevatemp)
while not pila_vacia(aux):
    dato = desapilar(aux)
    apilar(pila, dato)
mayores = 0
minima = tope(pila)
print("Pila resultante: ")
while not pila_vacia(pila):
    dato = desapilar(pila)
    if dato > nuevatemp:
        mayores += 1
    if dato < minima:
        minima = dato
    print(dato)
    apilar(aux, dato)
while not pila_vacia(aux):
    dato = desapilar(aux)
    apilar(pila, dato)
print("La cantidad de temperaturas mayores a la ingresada son: ", mayores)
print("La temperatura mínima registrada fue: ", minima)
