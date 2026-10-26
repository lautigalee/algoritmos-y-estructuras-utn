def apilar(pila, dato):
    pila.append(dato)
def desapilar(pila):
    return pila.pop()
def tope(pila):
    return pila[-1]
def pila_vacia(pila):
    return len(pila) == 0
pila = []
cantidad = int(input("Ingrese la cantidad de productos: "))
while cantidad <= 0 or cantidad >= 30:
    cantidad = int(input("Ingrese una cantidad válida: "))
for i in range(cantidad):
    codigo = int(input("Ingrese el codigo del producto: "))
    apilar(pila, codigo)
print("Cantidad de productos almacenados:", cantidad)
print("Código en el tope:", tope(pila))
while not pila_vacia(pila):
    codigo = desapilar(pila)
    print("Producto retirado:", codigo)