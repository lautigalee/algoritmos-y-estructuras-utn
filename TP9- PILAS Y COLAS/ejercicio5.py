def apilar(pila, dato):
    pila.append(dato)
def desapilar(pila):
    return pila.pop()
def tope(pila):
    return pila[-1]
def pila_vacia(pila):
    return len(pila) == 0
pila = []
aux1 = []
aux2 = []
digitos = int(input("Ingrese la cantidad de dígitos del número: "))
while digitos <= 0:
    digitos = int(input("Ingrese una cantidad válida: "))
for i in range(digitos):
    num = int(input("Ingrese un dígito (0 a 9): "))
    while num < 0 or num > 9:
        num = int(input("Dígito inválido. Ingrese un dígito (0 a 9): "))
    apilar(pila, num)
while not pila_vacia(pila):
    dato = desapilar(pila)
    apilar(aux1, dato)
    apilar(aux2, dato)
while not pila_vacia(aux2):
    dato = desapilar(aux2)
    apilar(pila, dato)
capicua = True
while not pila_vacia(pila):
    d1 = desapilar(pila)
    d2 = desapilar(aux1)
    if d1 != d2:
        capicua = False
if capicua:
    print("el número es capicúa")
else:
    print("el número no es capicúa")