#include "header.h"

int inputInt(string message);
int inputInt(string message, int min, int max);
string inputString(string message);

string checkOpenInputFile(string message);
string checkOpenOutputFile(string message);

int switchLine(int current_index, int array_length, bool under);

void addWord(string& input, string output); // вставить слово
void replaceWord(); // заменить слово
void deleteWord(); // удалить слово
void cycleAdd(string* mass, int& array_length, int current);


void readFile(string* mass, int& array_length); //читать файл
void saveFile(string* mass, int& array_length); // сохранить файл
