#include "functions.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int item;
    string array_text[N];
    int array_length = 0;
    int selected_index = 0;
    do{
        cout << "Текущая строчка - " << selected_index + 1 ;
        cout << "\n1 - Считать текст из файла";
        cout << "\n2 - Вставить слово";
        cout << "\n3 - Заменить слово";
        cout << "\n4 - Удалить слово";
        cout << "\n5 - Вывести n строк из файла";
        cout << "\n6 - Сохранить файл";
        cout << "\n7 - Смещение вверх";
        cout << "\n8 - Смещение вниз";
        cout << "\n0 - Выход";
        cout << "\nВведите номер пункта меню  : ";
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
                cout << "Ошибка\n";
                continue;
        }
    }while(item != 0);
    return 0;
}


