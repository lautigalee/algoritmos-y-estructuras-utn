lluvias = []
for i in range(6):
    lluvia = float(input(f"Ingrese la cantidad de lluvia (en mm) caída en el mes {i + 1}: "))
    lluvias.append(lluvia)
suma = 0
for lluvia in lluvias:
    suma += lluvia
prom = suma/6
cont = 0
for i in range(6):
    if(lluvias[i] >= prom):
        cont = cont + 1
cantmil = lluvias[0]
menor = 0
for i in range(6):
    if(lluvias[i] < cantmil):
        cantmil = lluvias[i]
        menor = i
if(cantmil == 0):
    print(f"El mes {menor + 1} no registró lluvias (0 mm)")
sumaprimersem = 0
for i in range(3):
    sumaprimersem += lluvias[i]
print(f"El promedio de lluvia caida durante el semestre fue {prom:.2f}")
print(f"la cantidad de meses en los que la lluvia caida fue mayor o igual al promedio fueron {cont}")
print(f"El numero de mes que registro la menor cantidad de lluvia fue {menor + 1}, con una lluvia de {cantmil} MM")
print(f"La cantidad de milimetros caidos durante los primeros tres meses fue de {sumaprimersem} MM")

