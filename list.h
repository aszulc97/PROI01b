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
        //iter next(iter it);
    };
    mylist(int val); //constructor
    ~mylist(); //destructor
    void showContent(iter head);
    iter getNode(int val);
    iter addAtFront(int newNode);
    iter addAfter(iter it, int newNode);
    iter deleteNode(iter it);
   // void copyNode();
   // void removeDuplicate();
   //iter begin();
   // iter end();
    iter head;
    iter tail;
    int size;
};

void sumOfTwo(mylist::iter tail1, mylist::iter head, mylist::iter tail2);
#endif // _LIST_H_
