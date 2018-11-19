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
    /*FlowList(const FlowList& source);
    FlowList& operator=(const FlowList& rhs);
    ~FlowList();*/

    void insert(const ListItem& itemA);
    void remove(const ListItem& itemA);
    void print() const;

private:
    Node* headM;
    Node* read;

    void destroy();
    void copy(const FlowList& source);

};

#endif