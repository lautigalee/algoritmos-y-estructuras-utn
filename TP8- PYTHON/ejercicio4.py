lista = []
N = int(input("Ingrese la cantidad de partidas jugadas: "))
while N <= 0:
    N = int(input("Ingrese una cantidad valida: "))
for i in range(N):
    puntaje = float(input(f"Ingrese el puntaje de la partida {i + 1}: "))
    lista.append(puntaje)
total = 0
for puntaje in lista:
    total+=puntaje
promedio = total/N
print(f"El total de puntaje fue: {total}")
print(f"El promedio de puntaje sobre cada partida fue: {promedio:.2f}")
menor = lista[0]
posmenor = 0
for i in range (N):
    if (lista[i] < menor):
        menor = lista[i]
        posmenor = i
print(f"El menor puntaje fue {menor}, obtenido en la partida {posmenor + 1}")
Mayoresa500 = 0
Menoresa200 = 0
for puntaje in lista:
    if(puntaje > 500):
        Mayoresa500 = Mayoresa500 + 1
    if(puntaje < 200):
        Menoresa200 = Menoresa200 + 1
print(f"La cantidad de partidas con puntaje mayor a 500 fueron: {Mayoresa500}")
porc = Menoresa200 * 100 / N
print(f"El porcentaje de partidas con puntaje menor a 200 es: {porc:.2f}%")