#include "functions.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    string array_text[N];
    int array_length = 0;
    int selected_index = 0;
    int item;
    do
    {
        cout << "Текущая строчка - " << selected_index + 1;
        cout << "\n1 - Считать текст из файла";
        cout << "\n2 - Перейти на заданное число строк вверх/вниз относительно текущей строки";
        cout << "\n3 - вывести на экран заданное число строк, начиная с текущей строки";
        cout << "\n4 - Вставить новое слово в конец строки";
        cout << "\n5 - Заменить слово, находящееся в конце строки, на другое слово";
        cout << "\n6 - Удалить слово, находящееся в конце строки";
        cout << "\n7 - Записать текст в файл";
        cout << "\n0 - Выход из программы";
        cout << "\nВведите номер пункта меню: ";
        item = inputInt("" , 0, 7);
        cout << endl;
        switch(item)
        {
            case 1:
                readFile(array_text, array_length,selected_index);
                cout << endl;
                break;

            case 2:
                selected_index = switchLine(selected_index, array_length);
                cout << endl;
                break;

            case 3:
                outContext(array_text,array_length,selected_index);
                cout << endl;
                break;

            case 4:
                cycleAdd(array_text, array_length, selected_index);
                cout << endl;
                break;

            case 5:
                cycleReplace(array_text, array_length, selected_index);
                cout << endl;
                break;

            case 6:
                cycleDelete(array_text, array_length, selected_index);
                cout << endl;
                break;

            case 7:
                saveFile(array_text, array_length);
                cout << endl;
                break;

            case 0:
                break;

            default:
                cout << "Неверный пункт меню!\n";
                continue;
        }
    }
    while(item != 0);

    return 0;
}


//int main()
//{
//    for(char c = -128; c < 127; c++)
//    {
//        cout << int(c) << ": " << char(c) << endl;
//    }
//    cout << int(127) << ": " << char(127) << endl;
//    return 0;
//}
