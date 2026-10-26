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
n = int(input("Ingrese la cantidad de acciones realizadas: "))
while n <= 0:
    n = int(input("Ingrese una cantidad válida: "))
for i in range(n):
    accion = int(input("Ingrese el numero de accion: "))
    apilar(pila, accion)
x = int(input("Ingrese el valor de x: "))
y = int(input("Ingrese el valor de y: "))
reemplazo = 0
while not pila_vacia(pila):
    dato = desapilar(pila)
    if dato == x:
        apilar(aux, y)
        reemplazo = 1
    else:
        apilar(aux, dato)
while not pila_vacia(aux):
    dato = desapilar(aux)
    apilar(pila, dato)
print("Pila resultante:")
while not pila_vacia(pila):
    dato = desapilar(pila)
    print(dato)
if reemplazo == 1:
    print("Se realizaron reemplazos")
else:
    print("No se realizaron reemplazos")