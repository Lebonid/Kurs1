#include "functions.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    string text_array[N];
    int array_length = 0;
    int selected_index = 0;
    int item = 0;
    do {
        cout << "\n1 - Считать текст из файла";
        cout << "\n2 - Смещение вверх";
        cout << "\n3 - Смещение вниз";
        cout << "\n4 - Буквы";
        cout << "\n5 - Вставить слово";
        cout << "\n6 - Заменить слово";
        cout << "\n7 - Удалить слово";
        cout << "\n8 - Сохранить текст в файл";
        cout << "\n0 - Выход из программы";
        cout << "\nВведите номер пункта меню:";
        cin >> item;

        switch (item) {
            case 0:
                break;
            case 1:
                readFile(text_array, array_length);
                break;
            case 2:
                selected_index = switchLine(selected_index, array_length, false);
                break;
            case 3:
                selected_index = switchLine(selected_index, array_length, true);
                break;
            case 4:
                cout << "буквы" << endl;
                break;
            case 5:
                cycleAdd(text_array, array_length, selected_index);
                break;
            case 6:
                cout << "Заменить слово" << endl;
                break;
            case 7:
                cout << "Удалить слово" << endl;
                break;
            case 8:
                saveFile(text_array, array_length);
                break;
            default:
                cout << "Ошибка!\n" << endl;
                continue;
        }
    } while (item != 0);
    return 0;
}
