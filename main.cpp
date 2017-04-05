#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
#include "list.h"
using namespace std;

int main()
{
  int first;
  char choice, trig1=1, trig2=0;
  cout<<"Podaj pierwszy element pierwszej listy"<<endl;
  cin>>first;
  mylist list1(first);
  mylist list2(first);
  system("cls");

  do
  {
    system("cls");
    if(trig1) list1.showContent(list1.head);
    if(trig2) list2.showContent (list2.head);
    cout<<"MENU:"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"1. Dodaj element do listy"<<endl;
    cout<<"2. Usun element z listy"<<endl;
    cout<<"3. Pobierz element z listy"<<endl;
    cout<<"4. Dodaj nowa liste"<<endl;
    cout<<"5. Zsumuj listy"<<endl;
    cout<<"6. Skopiuj element"<<endl;
    cout<<"7. Sprawdz rozmiar listy"<<endl;
    cout<<"8. Sprawdz rozmiar listy"<<endl;
    cout<<"Wcisnij q, aby zakonczyc"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Twoj wybor: ";
    cin>>choice;

    switch(choice)
    {
      case '1':
        {
          char key='o', listNumber;
          int newValue, chosenValue;
          mylist::iter it1;
          while(listNumber!='1' && listNumber!='2')
          {
            cout<<"Chcesz dodac element do listy 1 czy 2? Wpisz numer: ";
            cin>>listNumber;
            if (listNumber!='1' && listNumber!='2') cout<<"Nie ma takiego numeru!"<<endl;
            else while(key!='t' && key!='n')
            {
              cout<<"Podaj wartosc nowego elementu: ";
              cin>>newValue;
              cout<<"Chcesz wstawic nowy element na poczatek listy? [t/n] ";
              cin>>key;
              key=tolower(key);
              if (key=='t')
              {
                if (listNumber=='1') list1.addAtFront(newValue);
                else list2.addAtFront(newValue);
              }
              else if (key=='n')
              {
                cout<<"Podaj wartoœæ elementu, ZA ktorym chcesz wstawic nowy element: ";
                cin>>chosenValue;
                it1=list1.getNode(chosenValue);
                if (listNumber=='1') list1.addAfter(it1,newValue);
                else list2.addAfter(it1,newValue);
              }
              else cout<<"Sprobuj jeszcze raz"<<endl;
            }
          } listNumber='0';
        }break;
        //TODO: usuwanie kilku elementow z zakresu
      case '2':  //TODO: usuwanie z zakresu
        {
          char listNumber;
          int chosenValue;
          mylist::iter it2;
          cout<<"Chcesz usunac element z listy 1 czy 2? Wpisz numer: ";
          cin>>listNumber;
          if (listNumber!='1' && listNumber!='2') cout<<"Nie ma takiego numeru!"<<endl;
            else
            {
              cout<<"Podaj wartosc elementu, ktory chcesz usunac: "; //obs³uga blêdów!
              cin>>chosenValue;
              if (listNumber=='1')
              {
                it2=list1.getNode(chosenValue);
                list1.deleteNode(it2);
              }
              else
              {
                it2=list2.getNode(chosenValue);
                list2.deleteNode(it2);
              }
            }
        }break;
//TODO: cout "Chcesz" when there's no second list
      case '3':
        {
          char listNumber;
          int chosenValue;
          mylist::iter it3;
          cout<<"Chcesz zobaczyc element z listy 1 czy 2? Wpisz numer: ";
          cin>>listNumber;
            if (listNumber!='1' && listNumber!='2') cout<<"Nie ma takiego numeru!"<<endl;
            else
            {
              cout<<"Podaj wartosc elementu, ktory chcesz zobaczyc: "; //obs³uga blêdów!
              cin>>chosenValue;
              if (listNumber=='1') it3=list1.getNode(chosenValue);
              else it3=list2.getNode(chosenValue);
              cout<<it3.refer->value<<endl;
            }
          Sleep(1000);
        }break;
      case '4':
        {
          mylist::iter it4;
          int first2;
          trig2=1;
          it4=list2.getNode(first);
          list2.deleteNode(it4);
          cout<<"Podaj wartosc pierwszego elementu drugiej listy: ";
          cin>>first2;
          list2.addAtFront(first2);
        }break;
      case '5': //TODO: dodawanie nie tylko na koniec
        {
          char trig=0, key;
          while(trig==0)
          {
            cout<<"Chcesz dodac:"<<endl;
            cout<<"a. Pierwsza liste do drugiej"<<endl;
            cout<<"b. Druga liste do pierwszej"<<endl;
            cout<<"Wpisz a lub b: ";
            cin>>key;
            key=tolower(key);
            if (key=='a')
            {
              trig=1;
              trig1=0;
              list2.sumOfTwo(list2.tail, list1.head, list1.size);
              //~list1();
            }
            else if (key=='b')
            {
              trig=1;
              trig2=0;
              list1.sumOfTwo(list1.tail, list2.head, list2.size);
              //~list2();
            }
            else cout<<"Sprobuj jeszcze raz"<<endl;
          }
        }break;
  //  case '6': copyElement(); break;
  //  case '7': removeDuplicates(); break;
      case '8':
        {
          if (trig1) cout<<"Rozmiar listy pierwszej: "<<list1.size<<endl;
          if (trig2) cout<<"Rozmiar listy drugiej: "<<list2.size<<endl;
          Sleep(2000);
        }break;
  //  case '9': comparisonOfTwo(); break;
      case 'q': break;
      default: cout<<"Sprobuj ponownie"; break;
    }
  } while (choice!='q');
    return 0;
}
