usuario = input("Ingrese su nombre de usuario: ")
contrasena = input("Ingrese su contraseña: ")
contrasena_repetida = input("Reingrese su contraseña: ")
if len(contrasena) < 6:
    print("La contraseña debe tener al menos 6 caracteres")
elif contrasena != contrasena_repetida:
    print("Las contraseñas no coinciden. Intente nuevamente")
else:
    print("Registro realizado correctamente")
    print(f"Nombre de usuario: {usuario}")