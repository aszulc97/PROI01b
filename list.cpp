#include <iostream>
#include <windows.h>
#include "list.h"

using namespace std;

/*void gotoxy( int x, int y )
{
  COORD p = { x, y };
  SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p ); //decyzja
}*/

mylist::mylist(int val)
{
  node * temp = new node;
  temp->value=val;
  temp->id=1;
  temp->next=temp;
  temp->prev=temp;
  head.refer=temp;
  tail.refer=temp;
  size=1;
}

mylist::~mylist()
{
  node* temp;
  while (head.refer != NULL)
    {
      temp = head.refer->next;
      delete head.refer;
      head.refer = temp;
    }
} //TODO: czy nie powinnam usuwac tez itera??

void mylist::showContent(iter head)
{
  //TODO: obok siebie
  iter current=head;
  cout<<"Zawartosc listy:"<<endl;
  cout<<"---------------------------"<<endl;
  for (int i=0; i<size; i++)
  {
    //gotoxy(300,200);
    cout << "Id:\t" << current.refer->id << "\nLiczba:\t" << current.refer->value << "\n\n";
    current.refer=current.refer->next;
  }
  cout<<"---------------------------"<<endl;
}

mylist::iter mylist::getNode(int val)
{
  iter it = head;
  for (int i=0; i<size; i++)
  {
    int x = it.refer->value;
    if (x==val) break;
    else it.refer = it.refer->next;
  }
  return it;
};
mylist::iter mylist::addAtFront(int newNode)
{
  node * temp2 = new node;
  node * temp3 = head.refer;
  temp2->id=2;
  temp2->value=newNode;
  temp2->next=temp3;
  temp2->prev=temp2;
  temp3->prev=temp2;
  head.refer=temp2;
  size++;
}
mylist::iter mylist::addAfter(iter it, int newNode)
{
  node * temp1 = it.refer;
  node * temp2 = new node;
  node * temp3 = temp1->next;
  temp2->id=2;
  temp2->value=newNode;
  temp2->next=temp3;
  temp2->prev=temp1;
  temp3->prev=temp2;
  temp1->next=temp2;
  if (temp2->next==temp2) tail.refer=temp2; //coment
  size++;
  return it;
};

mylist::iter mylist::deleteNode(iter it)
{
  node * temp2 = it.refer;
  node * temp1 = temp2->prev;
  node * temp3 = temp2->next;
  temp1->next=temp3;
  temp3->prev=temp2;
  if(head.refer == temp2) head.refer = temp3; //comment
  if(tail.refer == temp2) tail.refer = temp1;
  delete temp2;
  it.refer=temp1;
  size--;
  return it;
}

void mylist::sumOfTwo(mylist::iter tail, mylist::iter head, int sizeOfAddedList)
{
  #warning TODO: sumowanie list petla
  int i;
  node * temp1 = tail.refer;
  node * temp2 = head.refer;
  for(i=0; i<sizeOfAddedList; i++)
  {
    temp1->next=temp2;
    temp2->prev=temp1;
    temp1=temp2;
    temp2=temp2->next;
    size++;
  } //while(temp2->next!=temp2);
}
/*

mylist::node::ostream& operator<< (ostream &out, node const& ex)
{
  out << ex.id << "   " << ex.value << "   " << ex.access;
  return out;
}*/
