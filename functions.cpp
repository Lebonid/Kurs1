#include "functions.h"

int inputInt(string message){
    int n;
    cout << message << endl;
    while(!(cin >> n)){
        cout << "Error don't number" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');;
        cout << message;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');;
    return n;
}

string checkOpenInputFile(string message){
    string filename;
    bool is_open = false;
    while(!is_open){
        filename = inputString(message);
        ifstream ifs(filename, ios::in);
        if(!ifs.is_open()){
            cout << "Error. Path File is Not Corrected";
            is_open = false;
        }else{
            ifs.close();
            is_open = true;
        }
    }
    return filename;
}

string checkOpenOutputFile(string message){
    string filename;
    bool is_open = false;
    while(!is_open){
        filename = inputString(message);
        ofstream ofs(filename, ios::out);
        if(!ofs.is_open()){
            cout << "Error. Path File is Not Corrected";
            is_open = false;
        }else{
            ofs.close();
            is_open = true;
        }
    }
    return filename;
}

void readFile(string* mass, int& array_length){
    string filename;
    filename = checkOpenInputFile("Enter name File (Reading): ");
    ifstream ifs(filename, ios::in);
    array_length = 0;
    while((!ifs.eof())&& (array_length < N)){
        getline(ifs, mass[array_length]);
        cout << mass[array_length] << endl;
        array_length++;
    }
    ifs.close();
    cout << "File Readied" << endl;
}

void saveFile(string* mass, int array_length){
    string filename;
    filename = checkOpenOutputFile("Enter name File (Saving): ");
    ofstream ofs(filename, ios::out);
    for(int i = 0; i < array_length; i++){
        ofs << mass[i] << endl;
    }
    ofs.close();
    cout << "File Saving" << endl;
};

void addWord(string& input, string output){
    size_t i = input.length();
    if(i == string::npos){
        return;
    }
    input.insert(i, output);
}

void cycleAdd(string* mass, int array_length, int current){
    string str;
    bool under = false;
    str = str.append(" ") + inputString("Enter Word");
    for(int i = current; i <= current; i++) {
        addWord(mass[i], str);
    }
}

string inputString(string message){
    string str = "";
    while(str.empty()){
        cout << message << endl;
        getline(cin, str, '\n');
    }
    return str;
}

int switchLine(int current_index, int array_length, bool under) {
    int count = 0;
    if(under){
        count = inputInt("Switch Down");
        return current_index +  count;
    }else{
        count = inputInt("Switch Up");
        return current_index - count;
    }
}

void outContext(string *mass, int array_length, int current) {
    int lines_count;
    lines_count = inputInt("Enter number Line");
    for(int i = current; i < (current + lines_count); i++){
        cout << "Line number" << i + 1 << " = " << *(mass + i) << endl;
    }
}

void deleteWord(string &input, string output) {
    size_t i = input.find(output);
    int count = output.length();
    if(i == string::npos){
        return;
    }
    if(i < count){
        count = i;
    }
    input.erase(i, count);
    return;

}

void cycleDelete(string* mass, int array_length, int current) {
    string str;
    str = inputString("Enter word: ");
    for(int i = current; i <= current; i++){
        deleteWord(*mass, str);
    }

}

void replaceWord(string &input, string output) {
    size_t i = input.find(output);
    int count = output.length();
    if(i==string::npos) {
        return;
    }
    if(i < count){
        count = i;
    }
    input.replace(i, count, output);
}

void cycleReplace(string *mass, int array_length, int current) {
    string str;
    string ptr;
    str = inputString("Enter String 1: ");
    ptr = inputString("Enter String 2: ");
    replaceWord(str, ptr);

}
