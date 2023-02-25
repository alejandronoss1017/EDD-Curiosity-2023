#include "./commonFunctions.hpp"

using namespace std;

vector<string> myStrTok(const string str)
{
    vector<string> tokens;
    bool flag = false;
    string temp;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' && !flag)
        {
            tokens.push_back(temp);
            temp.clear();
        }
        else if (flag)
        {
            temp += str[i];
            if (str[i] == '\'')
            {
                tokens.push_back(temp);
                temp.clear();
                flag = false;
            }
        }
        else
        {
            temp += str[i];
            if (str[i] == '\'')
            {
                flag = true;
            }
        }
    }
    if (temp != "")
    {
        tokens.push_back(temp);
    }
    return tokens;
}

bool checkInt(string arg)
{
    try
    {
        return stoi(arg) != 0;
    }
    catch (invalid_argument const &e)
    {
        return false;
    }
    catch (out_of_range const &e)
    {
        return false;
    }
}

bool is_valid_float(const string &str)
{
    istringstream iss(str);
    float f;
    iss >> noskipws >> f; // Lee el float desde la cadena, respetando los espacios en blanco

    // Verifica si se han leído correctamente los datos y si no queda más en la cadena
    return iss.eof() && !iss.fail();
}