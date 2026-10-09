total = 0
total_comida = 0
total_transporte = 0
total_entretenimiento = 0
importe = float(input("Ingrese el importe del gasto (0 para finalizar): "))
while importe < 0:
    print("El importe no puede ser negativo")
    importe = float(input("Ingrese el importe del gasto (0 para finalizar): "))
while importe != 0:
    categoria = int(input("Categoría (1-Comida, 2-Transporte, 3-Entretenimiento): "))
    while categoria < 1 or categoria > 3:
        print("Categoría inválida. Debe ser 1, 2 o 3")
        categoria = int(input("Categoría (1-Comida, 2-Transporte, 3-Entretenimiento): "))
    total += importe
    if categoria == 1:
        total_comida += importe
    elif categoria == 2:
        total_transporte += importe
    else:
        total_entretenimiento += importe
    importe = float(input("Ingrese el importe del gasto (0 para finalizar): "))
    while importe < 0:
        print("El importe no puede ser negativo")
        importe = float(input("Ingrese el importe del gasto (0 para finalizar): "))
print("----- Resumen de gastos -----")
print(f"Importe total gastado: ${total:.2f}")
print(f"Importe gastado en comida: ${total_comida:.2f}")
if total == 0:
    print("No se registraron gastos")
else:
    if total_comida >= total_transporte and total_comida >= total_entretenimiento:
        mayor = "Comida"
    elif total_transporte >= total_entretenimiento:
        mayor = "Transporte"
    else:
        mayor = "Entretenimiento"
    print(f"Categoría en la que se gastó más: {mayor}")
    porcentaje = total_entretenimiento * 100 / total
    print(f"Porcentaje de gastos en entretenimiento: {porcentaje:.2f}%")