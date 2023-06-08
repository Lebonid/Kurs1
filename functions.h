#include "header.h"

int inputInt(string message);
int inputInt(string message, int min,int max);
string inputString(string message);

int switchLine(int current_index, int array_length);
void outContext(string* mass, int array_length, int current);

string checkOpenInputFile(string message);
string checkOpenOutputFile(string message);

void readFile(string* mass, int& array_length, int& current);
void saveFile(string* mass, int array_length);

void addWord(string &input, string output);
void replaceWord(string &input, string output);
void deleteWord(string &input);

void cycleAdd(string* mass, int array_length, int current);
void cycleReplace(string* mass, int array_length, int current);
void cycleDelete(string* mass, int array_length, int current);
