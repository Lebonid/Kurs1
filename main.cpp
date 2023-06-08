#include "functions.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int item;
    string array_text[N];
    int array_length = 0;
    int selected_index = 0;
    do{
        cout << "Current Line - " << selected_index + 1 ;
        cout << "\n1 - ReadFile";
        cout << "\n2 - AddWord";
        cout << "\n3 - ReplaceWord";
        cout << "\n4 - DeleteWord";
        cout << "\n5 - Output Text N line";
        cout << "\n6 - SaveFile";
        cout << "\n7 - Up line";
        cout << "\n8 - Down line";
        cout << "\n0 - Exit";
        cout << "\nChoice point : ";
        cin >> item;
        switch(item){
            case 1 :
                readFile(array_text, array_length);
                break;
            case 2:
                cycleAdd(array_text, array_length, selected_index);
                break;
            case 3:
                cycleReplace(array_text, array_length, selected_index);
                break;
            case 4:
                cycleDelete(array_text, array_length, selected_index);
                break;
            case 5:
                outContext(array_text,array_length,selected_index);
                break;
            case 6:
                saveFile(array_text, array_length);
                break;
            case 7:
                selected_index = switchLine(selected_index, array_length,false);
                break;
            case 8:
                selected_index = switchLine(selected_index, array_length,true);
                break;
            case 0:
                break;
            default:
                cout << "Error!!!\n";
                continue;
        }
    }while(item != 0);
    return 0;
}


