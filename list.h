#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>

class mylist
{
  public:
    class node
    {
      public:
        int value;
        int id;
        int access;
        node * nxt;
        node * prv;
    };

    mylist(); //constructor
    ~mylist(); //destructor
    void addAtFront(int newNode);
    void addAtBack(int newNode);
    void deleteNode();
    void getNode();
    void copyNode();
    void removeDuplicate();

  private:
    node * head;
    node * tail;
    int size;
};

#endif // _LIST_H_
