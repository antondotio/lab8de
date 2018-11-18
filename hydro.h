//hydro.h

#ifndef hydro_h
#define hydro_h

void displayHeader();
int readData(const char* filename);
int menu();
void display();
void addData();
void removeData();
double average();
double median();
void saveData();
void pressEnter();

#endif