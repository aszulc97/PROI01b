#include <iostream>
#include "list.h"

using namespace std;

mylist::mylist()
{
  head=NULL;
  size=0;
}
mylist::~mylist() {};
void mylist::showContent()
{
  cout<<"Zawartosc listy:"<<endl;
  cout<<"---------------------------"<<endl;

  cout<<"---------------------------"<<endl;
}
void mylist::addAtFront(int newNode)
{
  node * temp = new node;
  temp->value=newNode;
  temp->access=0;
  temp->id=1;
  if (size==0)
  {
    head=temp;
    head->next=head;
    head->prev=head;
    size=1;
  }
  else if (size==1)
  {
    head->prev=temp;
    temp->next=head;
    head->next=temp;
    temp->prev=head;
    head=temp;
    size=2;
  }
  else
  {
    head->prev=temp;
    temp->next=head;
    temp->prev=head->prev;
    head=temp;
  }
};
void mylist::addAtBack(int newNode){};
void mylist::deleteNode(){};
void mylist::getNode(){};
void mylist::copyNode(){};
void mylist::removeDuplicate(){};

mylist::node::ostream& operator<< (ostream &out, node const& ex)
{
  out << ex.id << "   " << ex.value << "   " << ex.access;
  return out;
}
