nombreusuario = input("Ingrese su nombre de usuario: ")
nombreenmayus = nombreusuario.upper()
print(f"Su nombre de usuario en mayuscula es: {nombreenmayus}")
cantcarac = len(nombreusuario)
print(f"La cantidad de caracteres del nombre de usuario es: {cantcarac}")
cantvocales = 0
for letra in nombreenmayus:
    if(letra == 'A' or letra == 'E' or letra == 'I' or letra == 'O' or letra == 'U'):
        cantvocales += 1
print(f"La cantidad de letras vocales que contiene la palabra son: {cantvocales}")
tiene_espacios = " " in nombreusuario
if tiene_espacios:
    print("El nombre de usuario contiene espacios")
else:
    print("El nombre de usuario no contiene espacios")
if (cantcarac >= 5 and cantcarac <= 15 and not tiene_espacios):
    print("El nombre de usuario es valido")
else:
    print("El nombre de usuario es invalido")