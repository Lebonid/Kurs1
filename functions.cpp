#include "functions.h"

int inputInt(string message) {
    int n;
    cout << message << endl;
    while(!(cin >> n)){
        cout << "" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout <<  message;
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    return n;
}

int inputInt(string message, int min, int max) {
    int n;
    do{
        cout << message << endl;
        if(!(cin >> n) || (n < min)||(n > max)){
            cout << "Размер должен быть больше" << min << " и меньше" << max << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while((n < min)||(n > max));
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;
}

string inputString(string message) {
    string str = "";
    while(str.empty()){
        cout << message << endl;
        getline(cin, str, '\n');
    };
    return str;
}

string checkOpenInputFile(string message) {
    string fileName;
    bool isOpen = false;
    while(!isOpen){
        fileName = inputString(message);
        ifstream fs(fileName, ios::in);
        if(!fs.is_open()){
            cout << "Ошибка. Имя или путь к файлу неправильный.\\n";
            isOpen = false;
        }else{
            fs.close();
            isOpen = true;
        }
    }
    return fileName;
}

string checkOpenOutputFile(string message) {
    string fileName;
    bool is_open = false;
    while (!is_open) {
        fileName = inputString(message);
        ofstream fs(fileName, ios::out);

        if (!fs.is_open()) // fs.is_open()
        {
            cout << "Ошибка. Имя или путь к файлу неправильный.\n";
            is_open = false;
        }
        else {
            fs.close();
            is_open = true;
        }
    }
    return fileName;
}

int switchLine(int current_index, int array_length, bool under) {
    int count = 0;
    if(under){
        count = inputInt("Введите смещение вниз: ", 0 , (array_length-current_index-1));
        return current_index + count;
    }else{
        count = inputInt("Введите смещение вверх ", 0, current_index);
        return current_index - count;
    }
}

void readFile(string *mass, int &array_length) {
    string filename;
    filename = checkOpenInputFile("Введите название файла для чтения:");
    ifstream fin(filename, ios::in);

    array_length = 0;
    while ((!fin.eof()) && (array_length < N))
    {
        getline(fin, mass[array_length]);
        cout<<mass[array_length]<<endl;
        array_length++;
    }
    fin.close();
    cout << "Файл был считан." << endl;
}

void saveFile(string *mass, int &array_length) {
    string filename;
    filename = checkOpenOutputFile("Введите название файла для сохранения:");
    ofstream fout(filename, ios::out);
    for (int i = 0; i < array_length; i++) {
        fout << mass[i] << endl;
    }
    fout.close();
    cout << "Файл был сохранен." << endl;
}

void addWord(string &input, string output) {
    size_t i = input.length();
    if(i == string::npos){
        return;
    }
    input.insert(i, output);
    return;
}

void cycleAdd(string* mass, int &array_length, int current) {
    string str;
    int under = 0;
    str = str.append(" ") + inputString("Введите слово");
    cout << "Enter String" << endl;
    cin >> under;
    if(under == 0){
        for(int i = 0; i <= current; i++){
            addWord(mass[i], str);
            cout << mass[i] << endl;
        }
    }else if(under == 1){
        for(int i = 0; i < array_length; i++){
            addWord(mass[i], str);
            cout << mass[i] << endl;
        }
    }
}





