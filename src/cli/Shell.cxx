#include "Shell.hpp"

Shell::Shell(/* args */)
{
    this->command = "";
    showMenu();
}

Shell::~Shell()
{
}

void Shell::showMenu()
{
    cout << R"(
              ___           ___           ___                       ___           ___                       ___           ___     
             /\  \         /\__\         /\  \          ___        /\  \         /\  \          ___        /\  \         |\__\    
            /::\  \       /:/  /        /::\  \        /\  \      /::\  \       /::\  \        /\  \       \:\  \        |:|  |   
           /:/\:\  \     /:/  /        /:/\:\  \       \:\  \    /:/\:\  \     /:/\ \  \       \:\  \       \:\  \       |:|  |   
          /:/  \:\  \   /:/  /  ___   /::\~\:\  \      /::\__\  /:/  \:\  \   _\:\~\ \  \      /::\__\      /::\  \      |:|__|__ 
         /:/__/ \:\__\ /:/__/  /\__\ /:/\:\ \:\__\  __/:/\/__/ /:/__/ \:\__\ /\ \:\ \ \__\  __/:/\/__/     /:/\:\__\     /::::\__\
         \:\  \  \/__/ \:\  \ /:/  / \/_|::\/:/  / /\/:/  /    \:\  \ /:/  / \:\ \:\ \/__/ /\/:/  /       /:/  \/__/    /:/~~/~   
          \:\  \        \:\  /:/  /     |:|::/  /  \::/__/      \:\  /:/  /   \:\ \:\__\   \::/__/       /:/  /        /:/  /     
           \:\  \        \:\/:/  /      |:|\/__/    \:\__\       \:\/:/  /     \:\/:/  /    \:\__\       \/__/         \/__/      
            \:\__\        \::/  /       |:|  |       \/__/        \::/  /       \::/  /      \/__/                                
             \/__/         \/__/         \|__|                     \/__/         \/__/                                            
    )" << endl;
}

void Shell::helpMenu(const string command)
{
    switch (str2int(command.c_str()))
    {
    case str2int("avanzar"):
        cout << "Parametros: ~magnitud ~unidad_medida" << endl;
        break;
    case str2int("girar"):
        cout << "Parametros: ~magnitud ~unidad_medida" << endl;

        break;
    case str2int("fotografiar"):
        cout << "Parametros: ~objeto ~comentario" << endl;

        break;
    case str2int("composicion"):
        cout << "Parametros: ~objeto ~comentario" << endl;

        break;
    case str2int("perforar"):
        cout << "Parametros: ~objeto ~comentario" << endl;

        break;
    case str2int("roca"):
        cout << "Parametros: ~tamaño ~unidad_medida ~coordenada_x ~coordenada_y" << endl;

        break;
    case str2int("crater"):
        cout << "Parametros: ~tamaño ~unidad_medida ~coordenada_x ~coordenada_y" << endl;

        break;
    case str2int("monticulo"):
        cout << "Parametros: ~tamaño ~unidad_medida ~coordenada_x ~coordenada_y" << endl;

        break;
    case str2int("duna"):
        cout << "Parametros: ~tamaño ~unidad_medida ~coordenada_x ~coordenada_y" << endl;

        break;
    case str2int("cargar_comandos"):
        cout << "Parametros: ~nombre_archivo" << endl;

        break;
    case str2int("cargar_elementos"):
        cout << "Parametros: ~nombre_archivo" << endl;

        break;
    case str2int("agregar_movimiento"):
        cout << "Parametros: ~tipo_mov ~magnitud ~unidad_med" << endl;

        break;
    case str2int("agregar_analisis"):
        cout << "Parametros: ~tipo_analisis ~objeto ~comentario" << endl;

        break;
    case str2int("agregar_elemento"):
        cout << "Parametros:  ~tipo_comp ~tamaño ~unidad_med ~coordX ~coordY" << endl;

        break;
    case str2int("guardar"):
        cout << "Parametros: ~tipo_archivo ~nombre_archivo" << endl;

        break;
    case str2int("simular_comandos"):
        cout << "Parametros: ~coordX ~coordY" << endl;

        break;
    case str2int("ubicar_elementos"):
        cout << "Parametros: ~coordX1 ~coordX2 ~coordY1" << endl;

        break;
    case str2int("en_cuadrante"):
        cout << "No requiere parametros" << endl;

        break;
    case str2int("crear_mapa"):
        cout << "Parametros: ~coeficiente_conectividad" << endl;

        break;
    case str2int("ruta_mas_larga"):
        cout << "No requiere parametros" << endl;

        break;
    default:
        break;
    }
}

void Shell::begin()
{
    string command;
    do
    {
        cout << "$ ";
        getline(cin, command);
        setCommand(command);
        evaluateCommand();
    } while (getCommand() != "quit");
}

string Shell::getCommand() const
{
    return command;
}

void Shell::setCommand(string command)
{
    this->command = command;
}

void Shell::evaluateCommand()
{
    vector<string> commands = myStrTok(getCommand());

    switch (str2int(commands[0].c_str()))
    {
    case str2int("help"):
        if (commands.size() == 2)
        {
            helpMenu(commands[1]);
        }
        else
        {
            cout << R"(
            avanzar: Permiten al robot desplazarse sobre la superficie de Marte. 
            girar: Permiten al robot desplazarse sobre la superficie de Marte. 
            fotografiar: Permiten al robot investigar la superficie de Marte para
                        analizar los elementos que va encontrando en su desplazamiento.
            composicion: Permiten al robot investigar la superficie de Marte para
                        analizar los elementos que va encontrando en su desplazamiento.
            perforar: Permiten al robot investigar la superficie de Marte para
                        analizar los elementos que va encontrando en su desplazamiento.
            roca: Identifica la complejidad del terreno sobre el cual debe moverse el vehículo, se almacena de forma
                    adicional la información de elementos o componentes previamente hallados en el terreno.
            crater: Identifica la complejidad del terreno sobre el cual debe moverse el vehículo, se almacena de forma
                    adicional la información de elementos o componentes previamente hallados en el terreno.
            monticulo: Identifica la complejidad del terreno sobre el cual debe moverse el vehículo, se almacena de forma
                    adicional la información de elementos o componentes previamente hallados en el terreno.
            duna: Identifica la complejidad del terreno sobre el cual debe moverse el vehículo, se almacena de forma
                    adicional la información de elementos o componentes previamente hallados en el terreno.
            cargar_comandos: Carga en memoria los comandos de desplazamiento contenidos en el archivo enviado por parametro.
            cargar_elementos: Carga en memoria los datos de puntos de interés o elementos contenidos en el archivo enviado por parametro.
            agregar_movimiento: Agrega el comando de movimiento descrito a la lista de comandos del robot “Curiosity”.
            agregar_analisis: Agrega el comando de análisis descrito a la lista de comandos del robot “Curiosity”.
            agregar_elemento: tipo_comp tamaño unidad_med coordX coordY
            guardar: Guarda en un archivo la información solicitada de acuerdo al tipo de archivo.
            simular_comandos: Permite simular el resultado de los comandos de movimiento que se enviarán al robot
                    “Curiosity” desde la Tierra, facilitando asi la validación de la nueva posición en la que podría ubicarse.
            ubicar_elementos: Utilizar la información de puntos de interés almacenada en memoria para ubicarlos en una estructura
                     de datos jerárquica adecuada, que permita luego realizar consultas geográficas sobre estos elementos.
            en_cuadrante: Retorna una lista de los componentes o elementos que están dentro del cuadrante geográfico descrito
                     por los límites de coordenadas en x y y. 
            crear_mapa: El comando debe utilizar la información de puntos de interés almacenada en memoria para ubicarlos en una
                    estructura no lineal y conectarlos entre sí teniendo en cuenta el coeficiente de conectividad dado.
            ruta_mas_larga: Con el mapa ya creado, el comando permite identificar los dos componentes más alejados entre sí
                    de acuerdo a las conexiones generadas.
        )" << endl;
        }
        break;
    case str2int("quit"):
        cout << "Saliendo" << endl;
        break;
    case str2int("avanzar"):

        if (checkArgumentsNumber(commands, 3))
        {
            if (checkInt(commands[1]))
            {
                if (commands[2] == "cm")
                {
                    cout << "Avanzando el robot" << endl;
                }
                else if (commands[2] == "m")
                {
                    cout << "Avanzando el robot" << endl;
                }
                else
                    cout << "Unidad de medida incorrecta" << endl;
            }
            else
                cout << "El segundo argumento debe ser un entero válido" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("girar"):

        if (checkArgumentsNumber(commands, 3))
        {
            if (checkInt(commands[1]))
            {
                if (commands[2] == "deg")
                {
                    cout << "Girando el robot" << endl;
                }
                else if (commands[2] == "rad")
                {
                    cout << "Girando el robot" << endl;
                }
                else
                    cout << "Unidad de medida incorrecta" << endl;
            }
            else
                cout << "El segundo argumento debe ser un entero válido" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("fotografiar"):

        if (checkArgumentsNumber(commands, 3) || checkArgumentsNumber(commands, 2))
        {
            cout << "Fotografiando" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("composicion"):

        if (checkArgumentsNumber(commands, 3) || checkArgumentsNumber(commands, 2))
        {
            cout << "Composicionando" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("perforar"):

        if (checkArgumentsNumber(commands, 3) || checkArgumentsNumber(commands, 2))
        {
            cout << "Perforando" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;

    case str2int("roca"):

        if (checkArgumentsNumber(commands, 5))
        {
            if (checkInt(commands[1]) && checkInt(commands[3]) && checkInt(commands[4]))
            {
                if (commands[2] == "cm" || commands[2] == "m")
                {
                    cout << "roqueando" << endl;
                }
                else
                    cout << "Unidad de medida invalida" << endl;
            }
            else
                cout << "alguno de los argumento 2, 4 o 5 no es un entero válido" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("crater"):

        if (checkArgumentsNumber(commands, 5))
        {
            if (checkInt(commands[1]) && checkInt(commands[3]) && checkInt(commands[4]))
            {
                if (commands[2] == "cm" || commands[2] == "m")
                {
                    cout << "cratereando" << endl;
                }
                else
                    cout << "Unidad de medida invalida" << endl;
            }
            else
                cout << "alguno de los argumento 2, 4 o 5 no es un entero válido" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("monticulo"):

        if (checkArgumentsNumber(commands, 5))
        {
            if (checkInt(commands[1]) && checkInt(commands[3]) && checkInt(commands[4]))
            {
                if (commands[2] == "cm" || commands[2] == "m")
                {
                    cout << "monticuleando" << endl;
                }
                else
                    cout << "Unidad de medida invalida" << endl;
            }
            else
                cout << "alguno de los argumento 2, 4 o 5 no es un entero válido" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("duna"):

        if (checkArgumentsNumber(commands, 5))
        {
            if (checkInt(commands[1]) && checkInt(commands[3]) && checkInt(commands[4]))
            {
                if (commands[2] == "cm" || commands[2] == "m")
                {
                    cout << "Duneando" << endl;
                }
                else
                    cout << "Unidad de medida invalida" << endl;
            }
            else
                cout << "alguno de los argumento 2, 4 o 5 no es un entero válido" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("cargar_comandos"):

        if (checkArgumentsNumber(commands, 2))
        {
            uploadCommands(commands.at(1));
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("cargar_elementos"):

        if (checkArgumentsNumber(commands, 2))
        {
            vector<string> archivo = readfile(commands[1]);
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("agregar_movimiento"):

        if (checkArgumentsNumber(commands, 4))
        {
            if (commands[1] == "girar" || commands[1] == "avanzar")
            {
                if (checkInt(commands[2]) || checkInt(commands[3]))
                {
                    cout << " El comando de movimiento ha sido agregado exitosamente." << endl;
                    break;
                }
            }
            cout << "La información del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)." << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("agregar_analisis"):

        if (checkArgumentsNumber(commands, 3) || checkArgumentsNumber(commands, 4))
        {
            if (commands[1] == "fotografiar" || commands[1] == "composicion" || commands[1] == "perforar")
            {
                if (commands[2] == "roca" || commands[2] == "monticulo" || commands[2] == "arena" || commands[2] == "duna")
                {
                    cout << "El comando de análisis ha sido agregado exitosamente" << endl;

                    break;
                }
            }
            cout << " La información del análisis no corresponde a los datos esperados (tipo, objeto, comentario)." << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("agregar_elemento"):

        if (checkArgumentsNumber(commands, 6))
        {
            if (checkInt(commands[5]) && checkInt(commands[4]) && checkInt(commands[2]))
            {
                if (commands[1] == "roca" || commands[1] == "crater" || commands[1] == "monticulo" || commands[1] == "duna")
                {
                    if (commands[3] == "cm" || commands[3] == "m")
                    {
                        cout << "El elemento ha sido agregado exitosamente." << endl;
                        break;
                    }
                }
            }
            cout << "La información del elemento no corresponde a los datos esperados(tipo, tamaño, unidad, x, y)." << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("guardar"):

        if (checkArgumentsNumber(commands, 3))
        {
            cout << "Guardando" << endl;
            break;
        }

        cout << "cantidad de argumentos incorrecta" << endl;

        break;

    case str2int("simular_comandos"):

        if (checkArgumentsNumber(commands, 3))
        {
            if (checkInt(commands[1]) && checkInt(commands[2]))
            {
                cout << " La simulación de los comandos, a partir de la posición (coordX,coordY ), deja al robot en la nueva posición (nuevoX ,nuevoY )." << endl;
                break;
            }
            cout << " La información requerida no está almacenada en memoria." << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("ubicar_elementos"):
        if (checkArgumentsNumber(commands, 1))
        {
            cout << "Ubicando elementos" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("en_cuadrante"):
        cout << "Cuadranteando" << endl;
        if (checkArgumentsNumber(commands, 5))
        {
            if (checkInt(commands[1]) && checkInt(commands[2]) && checkInt(commands[3]) && checkInt(commands[4]))
            {
                cout << " Los elementos ubicados en el cuadrante solicitado son:" << endl;
                break;
            }
            cout << "La información del cuadrante no corresponde a los datos esperados (x_min, x_max, y_min, y_max)." << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("crear_mapa"):
        cout << "Creando mapa" << endl;
        if (checkArgumentsNumber(commands, 2))
        {
            if (is_valid_float(commands[1]))
            {
                cout << "El mapa se ha generado exitosamente." << endl;
                break;
            }
            cout << " La información requerida no está almacenada en memoria" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case str2int("ruta_mas_larga"):

        if (checkArgumentsNumber(commands, 1))
        {
            cout << "Verificando la ruta más larga" << endl;
        }
        else

        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    default:
        cout << "Comando no identificado" << endl;
        cout << "Escribe 'help' para mostrar un listado de los" << endl;
        cout << "comandos disponibles y su funcionalidades." << endl;
        break;
    }
}

bool Shell::checkArgumentsNumber(vector<string> commands, int args)
{
    if (commands.size() != args)
    {
        return false;
    }
    return true;
}

vector<string> Shell::readfile(string filename)
{
    vector<string> lines;
    ifstream file(filename.c_str());
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo " << filename << endl;
    }
    return lines;
}

void Shell::uploadCommands(string filename)
{
    try
    {
        // Lectura de archivos utilizando paths
        fstream file(filename);

        if (!file)
        {
            throw runtime_error("No se pudo abrir el archivo.");
        }

        string line;
        while (getline(file, line))
        {
            file >> line;

            addCommand(line);
        }

        cout << commands.size() << " comandos cargados exitosamente desde " << filename << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}

void Shell::addCommand(string command)
{
    this->commands.push(command);
}
