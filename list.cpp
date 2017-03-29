#include <iostream>
#include "list.h"

using namespace std;

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

mylist::~mylist() {};

void mylist::showContent(iter head)
{
  iter current=head;

  cout<<"Zawartosc listy:"<<endl;
  cout<<"---------------------------"<<endl;
  for (int i=0; i<size; i++)
  {
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
/*void mylist::addAtBack(int newNode){};
void mylist::deleteNode(){};
void mylist::getNode(){};
void mylist::copyNode(){};
void mylist::removeDuplicate(){};

mylist::node::ostream& operator<< (ostream &out, node const& ex)
{
  out << ex.id << "   " << ex.value << "   " << ex.access;
  return out;
}*/
