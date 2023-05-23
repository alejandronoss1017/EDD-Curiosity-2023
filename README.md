# Taller 4 (ED - Grafos)

Este programa tiene como objetivo aplicar la teoria de grafos vista en las clases durante el tercer corte de la materia de Estructuras de Datos.

Se nos plantea el problema de un sistema de aeropuertos y vuelos, en los cuales es necesario hallar la ruta mas rapida, la ruta mas barata y finalmente la ruta mas corta de los diferente vuelos.

## 💻 Software utilizado

- [C++ 11](https://en.cppreference.com/w/cpp/11)
- [CMake](https://cmake.org/) >= 3.22



# 🪟 Instalacion en Windows

Para la instalacion de [C++ 11](https://en.cppreference.com/w/cpp/11) en windows, recomendamos el compilador de [CGG](https://gcc.gnu.org/) el cual puede ser instalado mendiante [MinGW](https://www.mingw-w64.org/) a traves de [MSYS2](https://www.msys2.org/).

Se recomienda seguir la guia plateada por [MSYS2](https://www.msys2.org/) para la instalacion del compilador de GCC en windows.

Para [CMake](https://cmake.org/) se puede hacer a travez de un gestor de paquete como [Winget](https://learn.microsoft.com/en-us/windows/package-manager/winget/#install-winget) o [Chocolatey](https://chocolatey.org/).

__Chocolatey__
```powershell
  choco install cmake
```

__Winget__
```powershell
  winget install cmake
```

Tambien se puede obtener un archivo de instalacion desde la pagina web de Cmake en este [Link](https://cmake.org/download/)

# 🐧 Instalacion en Linux

En Linux por defecto ya trae el compilador de [CGG](https://gcc.gnu.org/) por defecto.

Para [CMake](https://cmake.org/) utiliza el gestor de paquetes de la distribucion donde se va a ejecutar el programa.

__Ubuntu/Debian__
```powershell
  sudo apt install cmake
```

__Fedora__
```powershell
  sudo rpm install cmake
```

__Arch__
```powershell
  sudo pacman install cmake
```

Tambien se puede obtener los binarios desde la pagina web de Cmake en este [Link](https://cmake.org/download/).
# 🛠️ Compilacion y ejecucion

Entra en la carpeta del proyecto:

__Bash/PowerShell__
```bash
  cd Taller4
```

__cmd__
```bash
  dir Taller4
```

Compilacion del programa:

```bash
  cmake -S . -B ./build -G "Unix Makefiles"
```
El anterior comando generara una carpeta con el nombre "__build__" donde se encontrar varios archivos, entre ellos un "__makefile__" y carpetas de la compilacion a traves de [CMake](https://cmake.org/), necesitaremos entrar a dicha carpeta:

__Bash/PowerShell__
```bash
  cd Taller4/build
```

__cmd__
```bash
  dir Taller4/build
```

Ahora necesitaremos ejecutar dicho archivo "__makefile__" para ello utilizaremos el siguiente comando estando en la misma carpeta del archivo:

```bash
  make
```

Finalmente se nos generar un archivo ejecutable, este puede variar dependiendo de sistema operativo, en el caso de Windows un archivo `Taller4.exe` mientras que el Linux un archivo binario `Taller4`. Solo nos queda ejecutar el programa con el siguiente comando:

__Bash__
```bash
  ./Taller4
```

__PowerShell__
```bash
  ./Taller4.exe
```

__cmd__
```bash
  start ./Taller4.exe
```
## 📖 Referencia de los metodos

#### Cargar informacion de aeropuertos

```cpp
  void loadAirports(string airportsFilePath)
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `airportsFilePath `| `string` | **Requerido** ruta del archivo.|

#### Cargar informacion de vuelos

```cpp
  void loadFlights(string flightsFilePath)
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `flightsFilePath `| `string` | **Requerido** ruta del archivo.|

#### Mostrar aeropuertos

```cpp
  void showAirports()
```

#### Mostrar vuelos

```cpp
  void showFlights()
```

#### Mostrar el camino mas rapido

```cpp
  void fastestPath(string sourceAirportID, string destinationAirportID)
```

| Parameters             | Type   | Description                                           |
| ---------------------- | ------ | ----------------------------------------------------- |
| `sourceAirportID`      | string | **Requerido** Identificador del aeropuerto de partida.       |
| `destinationAirportID` | string | **Requerido** Identificador del aeropuerto de llegada.  |

#### Mostrar el camino mas barato

```cpp
  void cheapestPath(string sourceAirportID, string destinationAirportID)
```

| Parameters             | Type   | Description                                           |
| ---------------------- | ------ | ----------------------------------------------------- |
| `sourceAirportID`      | string | **Requerido** Identificador del aeropuerto de partida.       |
| `destinationAirportID` | string | **Requerido** Identificador del aeropuerto de llegada.  |

#### Mostrar el camino mas corto en distacia

```cpp
  void shortestPath(string sourceAirportID, string destinationAirportID)
```

| Parameters             | Type   | Description                                           |
| ---------------------- | ------ | ----------------------------------------------------- |
| `sourceAirportID`      | string | **Requerido** Identificador del aeropuerto de partida.       |
| `destinationAirportID` | string | **Requerido** Identificador del aeropuerto de llegada.  |

## 🏛️ Diagrama de clases

![Diagrama de clases]()

## ⛩️ Estructura de carpeta

```
.
└── Taller4/
    ├── build/
    │   ├── cmakefiles/
    │   ├── cmake_install.cmake
    │   ├── MakeCache.txt
    │   ├── Makefile
    │   └── Taller4
    ├── data/
    │   ├── aeropuertos.csv
    │   └── vuelos.csv
    ├── images/
    │   ├── testCase.png
    │   └── classDiagram.png
    ├── include/
    │   ├── Edge.hpp
    │   ├── Edge.tpp
    │   ├── Graph.hpp
    │   ├── Graph.tpp
    │   ├── Node.hpp
    │   └── Node.tpp
    ├── src/
    │   ├── airport/
    │   │   ├── Airport.cpp
    │   │   └── Airport.hpp
    │   ├── flight/
    │   │   ├── Flight.cpp
    │   │   └── Flight.hpp
    │   ├── shell/
    │   │   ├── Shell.cpp
    │   │   └── Shell.hpp
    │   └── utils/
    │       └── filesOperations.hpp
    ├── CMakeList.txt
    ├── main.cpp
    ├── README.md
    └── TallerGrafos.pdf
```

## 🔍 Resultados obtenidos

![Evidencias de ejecucion](./images/testCase.png)
  > Al momento de utilizar una ruta de archivo, cabe resaltar que la ruta es relativa al archivo, por ende si se ejecuta desde `./buil/Taller4` la ruta de los datos seria `../data/*.csv`

## ✒️ Autores

- [Camilo Nossa](https://github.com/alejandronoss1017)
- [Gianluca Gramegna](https://github.com/GianlucaGav)
- [Lara Salcedo](https://github.com/Larasalcedof)