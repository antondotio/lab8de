//hydro.h

#ifndef hydro_h
#define hydro_h

void displayHeader();
int readData(FlowList &list);
int menu();
void display(FlowList &list, int numrecords);
void addData();
void removeData();
double average(FlowList &list);
double median(FlowList &list);
void saveData();
void pressEnter();

#endif