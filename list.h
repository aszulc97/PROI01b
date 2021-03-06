#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>

void gotoxy(int x,int y);

class mylist
{
  public:
    class node
    {
      public:
        int value;
        int id;
        int access=0;
        node * next;
        node * prev;
    };
    class iter //contains reference to an element
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
    void sumOfTwo(iter tail, iter head, int sizeOfAddedList); //TODO:jesli funkcja jest czescia klasy lista to chyba nie potrzebuje miec wskazanego taila tej listy
    void difference(iter head1, iter head2, int sizeOfAddedList);
    void compareLists(iter head1, iter head2, int sizeOfSecondList);
   // void removeDuplicate();
    iter head;
    iter tail;
    int size;

    iter operator+ (const int value);
   // iter operator+= (const iter it, const int value);
    iter operator- (const iter it);
    iter operator> (const int value);
};


#endif // _LIST_H_
