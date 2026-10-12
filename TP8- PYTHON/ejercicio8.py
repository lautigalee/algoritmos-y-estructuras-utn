meses = ["Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio"]
sueldos = []
for i in range(6):
    sueldo = float(input(f"Ingrese el sueldo de {meses[i]}: "))
    sueldos.append(sueldo)
mayorsueldo = sueldos[0]
posmayor = 0
for i in range(6):
    if sueldos[i] > mayorsueldo:
        mayorsueldo = sueldos[i]
        posmayor = i
print()
print(f"El sueldo más alto fue ${mayorsueldo:.2f}, recibido en {meses[posmayor]}")
total = 0
for i in range(6):
    total += sueldos[i]
promedio = total / 6
print(f"El sueldo promedio del semestre fue ${promedio:.2f}")
aguinaldo = mayorsueldo / 2
print(f"El aguinaldo es de ${aguinaldo:.2f}")
diferencias = []
for i in range(6):
    diferencias.append(sueldos[i] - promedio)
for i in range(6):
    print(f"{meses[i]}: {diferencias[i]:.2f}")