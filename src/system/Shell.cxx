#include "Shell.hpp"

Shell::Shell(/* args */)
{
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
    string line;
    vector<string> v;
    do
    {
        string aux;
        commandTypes type;
        cout << "$ ";
        getline(cin, line);
        v = myStrTok(line);
        aux = v.at(0);
        v.erase(v.begin());

        setCommand(Command(str2CommandTypes(aux), v));
        evaluateCommand();
    } while (command.GetCommand() != commandTypes::quit);
}

void Shell::setCommands(queue<Command> commands)
{
    this->commands = commands;
}

void Shell::setElements(list<Element> elements)
{
    this->elements = elements;
}

Command Shell::getCommand() const
{
    return command;
}

void Shell::setCommand(Command command)
{
    this->command = command;
}

void Shell::evaluateCommand()
{
    vector<string> params = command.GetParams();

    switch (command.GetCommand())
    {
    case help:
        if (params.size() == 1)
        {
            helpMenu(params[0]);
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
    case quit:
        cout << "Saliendo" << endl;
        break;
    case avanzar:

        if (checkArgumentsNumber(params, 2))
        {
            if (checkInt(params[0]))
            {
                if (isMeasureType(params[1]))
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
    case girar:

        if (checkArgumentsNumber(params, 2))
        {
            if (checkInt(params[0]))
            {

                if (str2MeasureType(params[1]) == deg || str2MeasureType(params[1]) == rad)
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
    case fotografiar:

        if (checkArgumentsNumber(params, 3) || checkArgumentsNumber(params, 2))
        {
            cout << "Fotografiando" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case composicion:

        if (checkArgumentsNumber(params, 3) || checkArgumentsNumber(params, 2))
        {
            cout << "Composicionando" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case perforar:

        if (checkArgumentsNumber(params, 3) || checkArgumentsNumber(params, 2))
        {
            cout << "Perforando" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;

    case roca:

        if (checkArgumentsNumber(params, 5))
        {
            if (checkInt(params[1]) && checkInt(params[3]) && checkInt(params[4]))
            {
                if (isMeasureType(params.at(2)))
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
    case crater:

        if (checkArgumentsNumber(params, 5))
        {
            if (checkInt(params[1]) && checkInt(params[3]) && checkInt(params[4]))
            {
                if (isMeasureType(params.at(2)))
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
    case monticulo:

        if (checkArgumentsNumber(params, 5))
        {
            if (checkInt(params[1]) && checkInt(params[3]) && checkInt(params[4]))
            {
                if (isMeasureType(params.at(2)))
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
    case duna:

        if (checkArgumentsNumber(params, 5))
        {
            if (checkInt(params[1]) && checkInt(params[3]) && checkInt(params[4]))
            {
                if (isMeasureType(params.at(2)))
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
    case cargar_comandos:

        if (checkArgumentsNumber(params, 1))
        {
            readCommands(params.at(0));
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case cargar_elementos:

        if (checkArgumentsNumber(params, 1))
        {
            readElements(params.at(0));
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case agregar_movimiento:

        if (checkArgumentsNumber(params, 3))
        {
            if (isCommandType(params.at(0)))
            {
                if (checkInt(params[1]))
                {
                    addCommand(this->command);
                    cout << "El comando de movimiento ha sido agregado exitosamente." << endl;
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
    case agregar_analisis:

        if (checkArgumentsNumber(params, 2) || checkArgumentsNumber(params, 3))
        {
            if (isAnalysisTypes(params.at(0)))
            {
                if (isElementTypes(params.at(1)))
                {
                    if (params.size() == 2)
                    {

                        addAnalysis(Analysis(str2AnalysisTypes(params.at(0)), params.at(1)));
                        cout << "El comando de análisis ha sido agregado exitosamente" << endl;
                        break;
                    }
                    addAnalysis(Analysis(str2AnalysisTypes(params.at(0)), params.at(1), params.at(2)));
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
    case agregar_elemento:

        if (checkArgumentsNumber(params, 6))
        {
            if (checkInt(params[5]) && checkInt(params[4]) && checkInt(params[2]))
            {
                if (isElementTypes(params.at(1)))
                {
                    if (isMeasureType(params.at(3)))
                    {
                        addElement(Element(str2ElementType(params.at(1)), stoi(params.at(2)), str2MeasureType(params.at(3)), stoi(params.at(4)), stoi(params.at(5))));
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
    case guardar:

        if (checkArgumentsNumber(params, 2))
        {
            writeFile(params.at(0), (params.at(1)));
            break;
        }

        cout << "cantidad de argumentos incorrecta" << endl;

        break;

    case simular_comandos:

        if (checkArgumentsNumber(params, 2))
        {
            if (checkInt(params[0]) && checkInt(params[1]))
            {
                // Coordinate aux(stod(params.at(0), stod(params.at(1))))
                robot.SetCoordinate(Coordinate(stod(params.at(0)),
                                               stod(params.at(1))));
                simulateCommands();
            }
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case ubicar_elementos:
        if (checkArgumentsNumber(params, 1))
        {
            cout << "Ubicando elementos" << endl;
        }
        else
        {
            cout << "cantidad de argumentos incorrecta" << endl;
        }

        break;
    case en_cuadrante:
        cout << "Cuadranteando" << endl;
        if (checkArgumentsNumber(params, 5))
        {
            if (checkInt(params[1]) && checkInt(params[2]) && checkInt(params[3]) && checkInt(params[4]))
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
    case crear_mapa:
        cout << "Creando mapa" << endl;
        if (checkArgumentsNumber(params, 2))
        {
            if (is_valid_float(params[1]))
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
    case ruta_mas_larga:

        if (checkArgumentsNumber(params, 1))
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

bool Shell::checkArgumentsNumber(vector<string> params, int args)
{
    if (params.size() != args)
    {
        return false;
    }
    return true;
}

void Shell::writeFile(string fileType, string fileName)
{
    if (fileType == "txt")
    {
        try
        {

            ofstream file(fileName.append(".txt"));
            if (!file.is_open())
            {
                throw runtime_error("No se pudo abrir el archivo para escribir.");
            }

            file << "-Comandos-" << endl;

            queue<Command> cQ = this->commands;

            while (!cQ.empty())
            {
                file << "* " << cQ.front() << endl;
                cQ.pop();
            }

            file << "-Elementos-" << endl;
            for (auto &&element : elements)
            {
                file << "*****************************" << endl;
                file << element << endl;
            }

            file.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else if (fileType == "bin")
    {
        // TODO: Escritura de un archivo binario
        /* code */
    }
    else
    {
        cout << "Tipo de archivo no valido" << endl;
    }
}

/**
 * @brief Upload commands from a text plain file.
 * @param filename
 * @throw runtime_error if the file doesn't exist or is empty.
 */
void Shell::readCommands(string fileName)
{
    try
    {
        fstream file(fileName);

        if (!file)
        {
            throw runtime_error("El archivo no existe.");
        }

        if (!commands.empty())
        {
            setCommands(queue<Command>());
        }

        string line;
        string command;
        while (getline(file, line))
        {
            string aux;
            vector<string> v = myStrTok(line);
            aux = v.at(0);

            v.erase(v.begin());

            if ((str2CommandTypes(aux) == avanzar &&
                 (str2MeasureType(v.at(1)) == cm || str2MeasureType(v.at(1)) == m ||
                  str2MeasureType(v.at(1)) == km)))
            {
                addCommand(Command(str2CommandTypes(aux), v));
            }
            else if (str2CommandTypes(aux) == girar && str2MeasureType(v.at(1)) == deg)
            {
                addCommand(Command(str2CommandTypes(aux), v));
            }
            else
            {
                cout << "La información del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)." << endl;
            }
        }

        if (commands.size() == 0)
        {
            throw runtime_error("El archivo se encuentra vacio.");
        }
        else
        {
            cout << commands.size() << " Comandos cargados exitosamente desde " << fileName << "." << endl;
        }
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

/**
 * @brief Upload elements from a text plain file.
 * @param filename
 * @throw runtime_error if the file doesn't exist or is empty.
 */
void Shell::readElements(string fileName)
{
    try
    {
        fstream file(fileName);

        if (!file)
        {
            throw runtime_error("El archivo no existe.");
        }

        if (!commands.empty())
        {
            setElements(list<Element>());
        }

        string line;
        while (getline(file, line))
        {
            vector<string> v = myStrTok(line);
            addElement(Element(str2ElementType(v.at(0)), stoi(v.at(1)), str2MeasureType(v.at(2)),
                               stoi(v.at(3)), stoi(v.at(4))));
        }

        if (elements.size() == 0)
        {
            throw runtime_error("El archivo se encuentra vacio.");
        }
        else
        {
            cout << elements.size() << " Elementos cargados exitosamente desde " << fileName << "." << endl;
        }
        file.close();
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}

void Shell::simulateCommands()
{

    while (!commands.empty())
    {
        Command c = commands.front();

        if (c.GetCommand() == avanzar)
        {
            double d = 0;
            Coordinate aux;
            double posX = 0;
            double posY = 0;
            if (c.GetParams().at(1) == "m" || c.GetParams().at(1) == "cm" ||
                c.GetParams().at(1) == "km")
            {
                d = stod(c.GetParams().at(0));
                if (c.GetParams().at(1) == "cm")
                {
                    d = d * 0.01;
                }

                if (c.GetParams().at(1) == "km")
                {
                    d = d * 1000;
                }

                posX = d * cos(robot.GetOrientation() * M_PI / 180) + robot.GetCoordinate().GetPosX();
                aux.SetPosX(posX);
                posY = d * sin(robot.GetOrientation() * M_PI / 180) + robot.GetCoordinate().GetPosY();
                aux.SetPosY(posY);

                robot.SetCoordinate(aux);
            }
        }
        if (c.GetCommand() == girar)
        {
            double aux = 0;
            aux = stod(c.GetParams().at(0)) + robot.GetOrientation();
            robot.SetOrientation(aux);
        }

        commands.pop();
    }

    cout << "La posicion final es [ " << robot.GetCoordinate().GetPosX() << " ]"
         << " [ " << robot.GetCoordinate().GetPosY() << "] "
         << "(" << robot.GetOrientation() << "°)";
}

void Shell::addCommand(Command command)
{
    this->commands.push(command);
}

void Shell::addAnalysis(Analysis analysis)
{
    this->analysisList.push_back(analysis);
}

void Shell::addElement(Element element)
{
    this->elements.push_back(element);
}
