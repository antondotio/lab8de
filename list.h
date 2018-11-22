//list.h

#ifndef list_h
#define list_h

struct ListItem{
    int year;
    double flow;
};

struct Node{
    ListItem item;
    Node *next;
};

class FlowList{
public:
    FlowList();

    Node* get_headM() const;
    void insert(const ListItem& data);
    void remove(const int year);
    void print() const;

private:
    Node* headM;

};

#endif