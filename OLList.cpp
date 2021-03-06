// OLList.cpp
// ENSF 337  Lab 8 Exercise C and D

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

OLList::OLList()
: headM(0)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      
        Node *after = headM->next; 
        while(after != 0 && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
}

void OLList::remove(const ListItem& itemA)
{
    if (headM == 0 || itemA < headM->item)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        delete doomed_node;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        doomed_node = maybe_doomed;
        before->next = maybe_doomed->next;
        delete doomed_node;
    }
}

void OLList::destroy()
{ 
    if(headM == 0){
        return;
    }
    else{
        Node *after = headM->next;
        while(after != nullptr){ 
            headM->next = nullptr;
            headM = after;
            after = after->next;
        }
        headM = nullptr;
    }
}

void OLList::copy(const OLList& source)
{
    Node *copy = source.headM;
    headM = new Node;
    headM->item = copy->item;
    Node *move = headM;
    copy = copy->next;

    while(copy != nullptr){
    move->next = new Node;
    move = move->next;
    move->item = copy->item;
    copy = copy->next;
    }
    move->next = 0;
}

