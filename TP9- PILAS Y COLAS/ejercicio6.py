def encolar(cola, dato):
    cola.append(dato)
def desencolar(cola):
    return cola.pop(0)
def frente(cola):
    return cola[0]
def cola_vacia(cola):
    return len(cola) == 0
cola = []
disponibles = int(input("Ingrese la cantidad de entradas disponibles: "))
while disponibles <= 0:
    disponibles = int(input("Cantidad inválida. Ingrese un número mayor a 0: "))
precio = float(input("Ingrese el precio de cada entrada: "))
while precio <= 0:
    precio = float(input("Precio inválido. Ingrese un número mayor a 0: "))
pedido = int(input("Entradas que desea comprar (0 para terminar): "))
while pedido < 0:
    pedido = int(input("Cantidad inválida. Ingrese 0 o más: "))
while pedido != 0:
    encolar(cola, pedido)
    pedido = int(input("Entradas que desea comprar (0 para terminar): "))
    while pedido < 0:
        pedido = int(input("Cantidad inválida. Ingrese 0 o más: "))
personas = 0
vendidas = 0
recaudado = 0
while not cola_vacia(cola):
    cantidad = desencolar(cola)
    if cantidad <= disponibles:
        disponibles -= cantidad
        personas += 1
        vendidas += cantidad
        recaudado += cantidad * precio
    else:
        print(f"No se puede vender {cantidad} entradas: solo quedan {disponibles}")
print(f"Personas que compraron entradas: {personas}")
print(f"Entradas vendidas: {vendidas}")
print(f"Monto total recaudado: ${recaudado:.2f}")
print(f"Entradas disponibles: {disponibles}")