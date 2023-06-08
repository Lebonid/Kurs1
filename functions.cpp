#include "functions.h"

int inputInt(string message)
{
    int n;
    cout << message << endl;
    while(!(cin >> n)){
        cout << "Ошибка! Введено неверное значение" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');;
        cout << message;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');;
    return n;
}

int inputInt(string message, int min, int max)
{
    int n = min;

    while (true)
    {
        cout << message;
        cin >> n;
        if ((cin.fail()) || (n < min) || (n > max))
        {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "Неверное введено число! Оно должно быть в диапазоне от " << min << " до " << max << ". Введите число ещё раз.\n";
        }
        else
        {
            cin.ignore(1024, '\n');
            break;
        }
    };

    return n;
};

string inputString(string message)
{
    string str = "";
   // while(str.empty()){
        cout << message << endl;
        getline(cin, str, '\n');
    //}
    return str;
}

bool is_letter(char c)
{
    bool flag = false;
    if((c >= -128) && (c <= -97))
    {
        flag = true;
    }
    if((c >= -96) && (c <= -81))
    {
        flag = true;
    }
    if((c >= -32) && (c <= -15))
    {
        flag = true;
    }
    if((c >= 65) && (c <= 90))
    {
        flag = true;
    }
    if((c >= 97) && (c <= 122))
    {
        flag = true;
    }
    return flag;
}

bool is_word(string word)
{
    bool flag = true;
    for(int i = 0; i < word.length(); i++)
    {
        if(is_letter(word[i]) == false)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

string inputWord(string message)
{
    string word;
    do
    {
        word = inputString(message);
        if(is_word(word) == false)
        {
            cout << "Неправильно введенное слово!" << endl;
        }

    }
    while(is_word(word) == false);
    return word;
}

//******************************************************************************************
//Проверка на файл

string checkOpenInputFile(string message)
{
    string filename;
    bool is_open = false;
    while(!is_open)
    {
        filename = inputString(message);
        ifstream ifs(filename, ios::in);
        if(!ifs.is_open())
        {
            cout << "Ошибка! Путь файла введен некорректно" << endl;
            is_open = false;
        }
        else
        {
            ifs.close();
            is_open = true;
        }
    }
    return filename;
}

string checkOpenOutputFile(string message)
{
    string filename;
    bool is_open = false;
    while(!is_open)
    {
        filename = inputString(message);
        ofstream ofs(filename, ios::out);
        if(!ofs.is_open())
        {
            cout << "Ошибка! Путь файла введен некорректно";
            is_open = false;
        }
        else
        {
            ofs.close();
            is_open = true;
        }
    }
    return filename;
}

//******************************************************************

//Смена Сторок

int switchLine(int current_index, int array_length)
{
    int count = 0;
    int direction = inputInt("Введите направление передвижения (1 - Вверх, 0 - Вниз): ", 0, 1);
    if(direction == 1)
    {
        count = inputInt("На сколько строк подняться вверх?: ", 0,current_index);
        return current_index - count;
    }
    else
    {
        count = inputInt("На сколько строк опуститься вниз?: ", 0, array_length - current_index - 1);
        return current_index + count;
    }
}

void outContext(string* mass, int array_length, int current)
{
    int lines_count = inputInt("Введите количество строк, выводимых на экран: ", 0, array_length - current);
    for(int i = current; i < (current + lines_count); i++)
    {
        cout << "Строка " << i + 1 << ": " << mass[i] << endl;
    }
}

//Операций

//Добавление слова
void addWord(string &line, string word)
{
//    int i = line.length();
//    if(i == string::npos){
//        return;
//    }
    line.insert(line.length(), word);
}

void cycleAdd(string* mass, int array_length, int current)
{
   // bool under = false;
    int direction = inputInt("Где меняются строки? (1 - До текущей строки, 0 - Ниже текущей строки): ", 0, 1);
    string str = " " + inputWord("Введите слово для вставик: ");
    if(direction == 1)
    {
        for(int i = 0; i <= current; i++)
        {
            addWord(mass[i], str);
        }
    }
    else
    {
        for(int i = current; i <= array_length; i++)
        {
            addWord(mass[i], str);
        }
    }
}

//Замена слова
void replaceWord(string &line, string word)
{
    int ib, ie;
    if(line.length() == 0)
    {
        return;
    }
    ie = line.length() - 1;
    while((ie > 0) && (is_letter(line[ie]) == false))
    {
        ie--;
    }
    ib = ie;
    while((ib > 0) && (is_letter(line[ib]) == true))
    {
        ib--;
    }
    if((ib >= 0) && (is_letter(line[ib]) == false))
    {
        ib++;
    }
    if((ib <= ie) && (is_letter(line[ib]) == true) && (is_letter(line[ie]) == true))
    {
        line.replace(ib, ie - ib + 1, word);
    }


/*
    int i = input.length();
    int ib = 0; // index of first letter in word
    int ie = 0; // index of last letter in word



    int out = input.find_last_of('\n');
    int in = input.find_last_of(" ");
//    cout << in << " " << out ;
    if(i < out){
        i = out;
    }if(in == -1){
        in = 0;
    }
    deleteWord(input);
    input.replace(in, i, output);
*/
}

void cycleReplace(string *mass, int array_length, int current)
{
//    string ptr;
//    ptr = ptr.append(" ") + inputWord("Введите новое слово ");
//    for(int i = current; i<=current; i++){
//        replaceWord(mass[i], ptr);
//    }
//    cout << "Слово Изменено! "<< endl;

    int direction = inputInt("Где меняются строки? (1 - До текущей строки, 0 - Ниже текущей строки): ", 0, 1);
    string word = inputWord("Введите слово для замены: ");
    if(direction == 1)
    {
        for(int i = 0; i <= current; i++)
        {
            replaceWord(mass[i], word);
        }
    }
    else
    {
        for(int i = current; i <= array_length; i++)
        {
            replaceWord(mass[i], word);
        }
    }

}

// Удаление слова
void deleteWord(string &line)
{

    int ib, ie;
    if(line.length() == 0)
    {
        return;
    }
    ie = line.length() - 1;
    while((ie > 0) && (is_letter(line[ie]) == false))
    {
        ie--;
    }
    ib = ie;
    while((ib > 0) && (is_letter(line[ib]) == true))
    {
        ib--;
    }
    /*
    if((ib >= 0) && (is_letter(line[ib]) == false))
    {
        ib++;
    }
  * */
    if((ib <= ie) && (is_letter(line[ie]) == true))
    {
        line.erase(ib, ie - ib + 1);
    }

    /*
    int out = input.find_last_of('\n');
    int in = input.find_last_of(" ");
    size_t i = input.length();
    if(i == string::npos){
        return;
    }
    if(i<out){
        i = out;
    }if(in == -1){
        in = 0;
    }
    input.erase(in, out);
    return;
*/
}

void cycleDelete(string* mass, int array_length, int current)
{
//    for(int i = current; i <= current; i++){
//        deleteWord(mass[i]);
//    }
//    cout << "Слово Удалено! "<< endl;

    int direction = inputInt("Где меняются строки? (1 - До текущей строки, 0 - Ниже текущей строки): ", 0, 1);
    if(direction == 1)
    {
        for(int i = 0; i <= current; i++)
        {
            deleteWord(mass[i]);
        }
    }
    else
    {
        for(int i = current; i <= array_length; i++)
        {
            deleteWord(mass[i]);
        }
    }

}

//************************************************************************

//Операций обращения к файлу
//Чтение файла

void readFile(string* mass, int &array_length, int &current)
{
    string filename;
    filename = checkOpenInputFile("Введите название файла для чтения: ");
    ifstream ifs(filename, ios::in);
    array_length = 0;
    current = 0;
    while((!ifs.eof()) && (array_length < N))
    {
        getline(ifs, mass[array_length]);
        //cout << mass[array_length] << endl;
        array_length++;
    }
    ifs.close();
    cout << "Файл прочитан." << endl;
}

//Сохрание файла
void saveFile(string* mass, int array_length)
{
    string filename;
    filename = checkOpenOutputFile("Введите название файла для записи: ");
    ofstream ofs(filename, ios::out);
    for(int i = 0; i < array_length; i++)
    {
        ofs << mass[i] << endl;
    }
    ofs.close();
    cout << "Файл сохранен." << endl;
}
