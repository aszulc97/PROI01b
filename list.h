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
        node * next;
        node * prev;
    };
    class iter
    {
    public:
      node * refer;
      iter next(iter it);
    };
    mylist(int val); //constructor
    ~mylist(); //destructor
    void showContent(iter head);
    iter addNode(iter it, int newNode);
    //void addAtBack(int newNode);
    void deleteNode(iter it);
    void getNode(int val);
   // void copyNode();
   // void removeDuplicate();
    iter begin();
    iter end();
    iter head;
    iter tail;
    int size;
};

#endif // _LIST_H_
