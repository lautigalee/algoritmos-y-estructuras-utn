sexo = input("Ingrese su sexo (F-para femenino, M-para masculino): ")
cantf = 0
cantm = 0
cantf_escolar = 0
encontrado = 0
while(sexo == 'M' or sexo == 'F'):
    edad = int(input("Ingrese su edad: "))
    if(sexo == 'M'):
        cantm = cantm + 1
    elif(sexo == 'F'):
        cantf = cantf + 1
    if(sexo == 'F' and edad >= 4 and edad <= 18):
        cantf_escolar = cantf_escolar + 1
    if(sexo == 'M' and edad > 85):
        encontrado = 1
    sexo = input("Ingrese su sexo (F-para femenino, M-para masculino): ")
if (cantf > cantm):
    print("Hay mayor cantidad de mujeres ")
elif(cantm > cantf):
    print("Hay mayor cantidad de hombres")
else:
    print("Hay igual cantidad de hombres que de mujeres ")
print(f"La cantidad de mujeres en edad escolar es {cantf_escolar}")
if(encontrado == 1):
    print("Existe al menos un varon mayor a 85 años ")