//hydro.h

#ifndef hydro_h
#define hydro_h

void displayHeader();
int readData(FlowList &list);
int menu();
void display(FlowList &list, int numrecords);
void addData(FlowList &list, int *numrecords);
void removeData(FlowList &list, int *numrecords);
double average(FlowList &list, int numrecords);
double median(FlowList &list, int numrecords);
void saveData(FlowList &list);
void pressEnter();

#endif