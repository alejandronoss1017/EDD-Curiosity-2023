# EDD-Curiosity-2023

Este programa tiene como objetivo aplicar la teoria de grafos vista en las clases durante el tercer corte de la materia de Estructuras de Datos.

Se nos plantea el problema de un sistema de aeropuertos y vuelos, en los cuales es necesario hallar la ruta mas rapida, la ruta mas barata y finalmente la ruta mas corta de los diferente vuelos.

## 💻 Software utilizado

- [C++ 11](https://en.cppreference.com/w/cpp/11)
- [CMake](https://cmake.org/) >= 3.22

# 🪟 Instalacion en Windows

Para la instalacion de [C++ 11](https://en.cppreference.com/w/cpp/11) en windows, recomendamos el compilador de [CGG](https://gcc.gnu.org/) el cual puede ser instalado mendiante [MinGW](https://www.mingw-w64.org/) a traves de [MSYS2](https://www.msys2.org/).

Se recomienda seguir la guia plateada por [MSYS2](https://www.msys2.org/) para la instalacion del compilador de GCC en windows.

Para [CMake](https://cmake.org/) se puede hacer a travez de un gestor de paquete como [Winget](https://learn.microsoft.com/en-us/windows/package-manager/winget/#install-winget) o [Chocolatey](https://chocolatey.org/).

**Chocolatey**

```powershell
  choco install cmake
```

**Winget**

```powershell
  winget install cmake
```

Tambien se puede obtener un archivo de instalacion desde la pagina web de Cmake en este [Link](https://cmake.org/download/)

# 🐧 Instalacion en Linux

En Linux por defecto ya trae el compilador de [CGG](https://gcc.gnu.org/) por defecto.

Para [CMake](https://cmake.org/) utiliza el gestor de paquetes de la distribucion donde se va a ejecutar el programa.

**Ubuntu/Debian**

```powershell
  sudo apt install cmake
```

**Fedora**

```powershell
  sudo rpm install cmake
```

**Arch**

```powershell
  sudo pacman install cmake
```

Tambien se puede obtener los binarios desde la pagina web de Cmake en este [Link](https://cmake.org/download/).

# 🛠️ Compilacion y ejecucion

Entra en la carpeta del proyecto:

**Bash/PowerShell**

```bash
  cd EDD-Curiosity-2023
```

**cmd**

```bash
  dir EDD-Curiosity-2023
```

Compilacion del programa:

```bash
  cmake -S . -B ./build -G "Unix Makefiles"
```

El anterior comando generara una carpeta con el nombre "**build**" donde se encontrar varios archivos, entre ellos un "**makefile**" y carpetas de la compilacion a traves de [CMake](https://cmake.org/), necesitaremos entrar a dicha carpeta:

**Bash/PowerShell**

```bash
  cd EDD-Curiosity-2023/build
```

**cmd**

```bash
  dir EDD-Curiosity-2023/build
```

Ahora necesitaremos ejecutar dicho archivo "**makefile**" para ello utilizaremos el siguiente comando estando en la misma carpeta del archivo:

```bash
  make
```

Finalmente se nos generar un archivo ejecutable, este puede variar dependiendo de sistema operativo, en el caso de Windows un archivo `main.exe` mientras que el Linux un archivo binario `main`. Solo nos queda ejecutar el programa con el siguiente comando:

**Bash**

```bash
  ./main
```

**PowerShell**

```bash
  ./main.exe
```

**cmd**

```bash
  start ./main.exe
```

> Al momento de utilizar una ruta de archivo, cabe resaltar que la ruta es relativa al archivo, por ende si se ejecuta desde `./build/main` la ruta de los datos seria `../*.txt`

# 🪟 Diagrama de clases

![Diagrama de clases](/images/Diagrama%20EDD%20Curiosity.png)



## ✒️ Autores

- [Camilo Nossa](https://github.com/alejandronoss1017)
- [Gianluca Gramegna](https://github.com/GianlucaGav)
- [Lara Salcedo](https://github.com/Larasalcedof)
