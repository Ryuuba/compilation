# Análisis del proceso de compilación

Para realizar los siguientes pasos es necesario instalar el compilador cruzado de RISC-V en tu sistema operativo.

## Windows

1. Descarga MSYS2 y sigue las instrucciones de la página [https://www.msys2.org/](https://www.msys2.org/) y el asistente de instalación.
2. En la terminal MSYS2 MINGW64, ejecuta el siguiente comando `pacman -Syu mingw-w64-x86_64-riscv64-unknown-elf-gcc`. Sigue los pasos del asistente de instalación
3. Agrega la ruta donde se encuentra el compilador cruzado a la variable PATH. El valor de esta variable del sistema operativo se modifica en las «variables de entorno». Generalmente, el compilador cruzado se encuentra en la ruta `C:\msys64\mingw64\bin`. 
4. Verifica que el programa `riscv64-unknown-elf-gcc` se encuentre en el directorio mencionado en el punto anterior.
5. Para facilitar la invocación del compilador, abre PowerShell y ahí ejecuta el comando `code $PROFILE`. Este comando abre VS Code para editar el *script* de arranque de PowerShell. Al final de ese archivo, agrega los siguientes comandos.

```PowerShell
Set-Alias -Name riscv-gcc -Value riscv64-unknown-elf-gcc
Set-Alias -Name riscv-as -Value riscv64-unknown-elf-as
Set-Alias -Name riscv-objdump -Value riscv64-unknown-elf-objdump
``` 
6. Guarda los cambios hechos en el archivo $PROFILE.
7. En PowerShell, ejecuta el comando `. $PROFILE` para recargar la configuración de arranque de la terminal.
8. Si el comando anterior genera un error, investiga como habilitar PowerShell para ejecutar *scrips*.
9. En PowerShell ejecuta el comando `riscv-gcc -v`. Si los pasos anteriores se realizaron correctamente, entonces el comando imprimirá la configuración del compilador cruzado en la salida estándar.

## Ubuntu

1. Desde la terminal de comandos, ejecuta el comando `sudo apt update` para actualizar los repositorios de software. Se asume que el shell que empleas es Bash.
2. Ahora, en la misma terminal de comandos, ejecuta el comando `sudo apt install gcc-riscv64-unknown-elf`
3. Para facilitar la invocación del compilador cruzado, ejecuta el comando `nano $HOME/.bashrc` para modificar el *script* de arranque de Bash.
4. Al final del archivo `.bashrc` agrega los siguientes comandos

```
alias riscv-gcc=riscv64-unknown-elf-gcc
alias riscv-as=riscv64-unknown-elf-as
alias riscv-objdump=riscv64-unknown-elf-objdump
```

5. Guarda los cambios hechos al archivo `.bashrc`.
6. Desde la terminal de comandos, ejecuta el comando `source $HOME/.bashrc` para recargar la configuración inicial del intérprete de comandos.
7. Verificar que los cambios realizados son correctos ejecutando el comando `riscv-gcc -v`. Este comando debe imprimir en la salida estándar la versión del compilador cruzado.

## MacOS

1. Instala brew siguiente las instrucciones del sitio web [https://brew.sh/](https://brew.sh/).
2. Una vez instalado brew, abre una terminal de comandos. Se asume que el shell que la terminal ejecuta es ZSH.
3. Dentro de la terminal, ejecuta el comando `brew install riscv64-elf-gcc`.
4. Cierra la terminal de comandos.
3. Para facilitar la invocación del compilador cruzado, ejecuta el comando `nano $HOME/.zshrc` para modificar el *script* de arranque de Bash.
4. Al final del archivo `.zshrc` agrega los siguientes comandos

```
alias riscv-gcc=riscv64-elf-gcc
alias riscv-as=riscv64-elf-as
alias riscv-objdump=riscv64-elf-objdump
```

5. Guarda los cambios hechos al archivo `.zshrc`.
6. Desde la terminal, ejecuta el comando `source $HOME/.zshrc` para recargar la configuración inicial del intérprete de comandos.
7. Verificar que los cambios realizados son correctos ejecutando el comando `riscv-gcc -v`. Este comando debe imprimir en la salida estándar la versión del compilador cruzado.

## Metodología

1. Clona el repositorio https://github.com/Ryuuba/compilation.git.
2. Analiza los archivos `main_macro.c` y `arith_macro.h`. poniendo atención en las directivas `#define`.
3. Ejecuta el comando `riscv-gcc -E main_macro.cc -mabi=ilp32 -march=rv32i > main.txt`.
4. Analiza el contenido del archivo `main.txt` buscando cambios en el código.
5. Analiza los archivos `main_func.c` y `arith.h` poniendo atención en la declaración de las funciones.
6. Ejecuta el comando `riscv-gcc -E main_func.cc -mabi=ilp32 -march=rv32i > main.txt` buscando cambios en el código.
7. Analiza el archivo `main_if.cc` poniendo atención en las directivas `#if`.
8. Ejecuta el comando `riscv-gcc -E -DMACRO main_if.cc -mabi=ilp32 -march=rv32i > main`.
9. Analiza el resultado y dale una explicación.
10. Ejecuta el comando `riscv-gcc -E main_if.cc > main -mabi=ilp32 -march=rv32i`.
11. Analiza el resultado y dale una explicación.
12. Analiza el contenido del archivo `main_even.cc` poniendo atención en las operaciones en el se realizan.
13. Investiga cómo se implementa la función módulo en lenguaje ensamblador risc-v.
14. Ejecuta el comando `riscv-gcc -S main_even.cc -mabi=ilp32 -march=rv32i`.
15. Busca en el código ensamblador del programa la operación módulo.
16. Explica cómo se verifica en ensamblador que un número es par y qué ocurre con la suma de `4+3`.
17. Ejecuta el comando `riscv-gcc -c main_even.cc -mabi=ilp32 -march=rv32i`.
18. Explica qué ocurre si intentas abrir el archivo `main_even.o`.
19. Ejecuta el comando `riscv-objdump -o main_even.o > main.dump`.
20. Compara el contenido del archivo `main.dump` con el `main.s`.
21. Explica las diferencias entre los dos archivos.
22. Explica la estructura del archivo `main.dump`.
