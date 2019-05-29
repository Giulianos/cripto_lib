# Cripto lib

En este documento se explica como compilar el código, también se describen los módulos presentes en la biblioteca y las funciones que ofrece cada uno.

Para contribuir al codigo y/o entender la estructura de archivos del proyecto, ver el archivo `CONTRIBUTE.md`(aun no disponible).

## Compilación

### Requisitos

Para compilar se necesita **CMake** version >= 3.7 y un **compilador de C99**.

### Pasos

Se incluye un script para compilar (`compile.sh`). Este realiza los pasos "standard" para compilar un proyecto de CMake:
 - Crea un directorio `build`
 - Genera los makefile dentro de éste
 - Compila

Por defecto los artifacts quedan en `build/target`.

## Modulos

### mod

Es una abstracción para operar con aritmética modular. Ofrece funciones como:

- Sumar dos numeros
- Restar dos numeros
- Multiplicar dos numeros
- Dividir dos numeros

### mod_matrix

Implementa aritmética modular para matrices y permite:

- Sumar dos matrices
- Restar dos matrices
- Multiplicar dos matrices
- Multiplicar una matriz por un escalar *(presente en el contrato, pero todavia no implementado)*
- Transponer una matriz

Además provee macros para facilitar el uso:

- **NEW_MATRIX**: para reservar la memoria requerida por una matriz
- **ELEM**: para acceder a un elemento de la matriz

### algorithms

Provee algoritmo~s~ útiles para el tp de criptografía. Los implementados hasta ahora son:

- **Método de Gauss** para escalonar matrices

## Ejemplos

Los tests que incluye cada módulo sirven de ejemplo ya que muestran como se usa cada función de manera simple. Estos estan en:

- **mod**: `src/mod/test.c`
- **mod_matrix**: `src/mod_matrix/test.c`
- **algorithms**: `src/algorithms/test.c`
