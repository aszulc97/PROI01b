#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "list.h"
using namespace std;

int main()
{
  int first;
  char choice;

  cout<<"Podaj pierwszy element listy"<<endl;
  cin>>first;
  mylist list1(first);
  system("cls");

  do
  {
    system("cls");
    list1.showContent(list1.head);
    cout<<"MENU:"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"1. Dodaj element do listy"<<endl;
    cout<<"2. Usun element z listy"<<endl;
    cout<<"3. Pobierz element z listy"<<endl;
    cout<<"4. Zsumuj dwie listy"<<endl;
    cout<<"5. Roznica dwoch list"<<endl;
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
          char key, trig=0;
          int newValue, chosenValue;
          mylist::iter it1;
          while(trig==0)
          {
            cout<<"Podaj wartosc nowego elementu: ";
            cin>>newValue;
            cout<<"Chcesz wstawic nowy element na poczatek listy? [t/n] ";
            cin>>key;
            key=tolower(key);
            if (key=='t')
            {
              trig=1;
              list1.addAtFront(newValue);
            }
            else if (key=='n')
            {
              trig=1;
              cout<<"Podaj wartoœæ elementu, ZA ktorym chcesz wstawic nowy element: ";
              cin>>chosenValue;
              it1=list1.getNode(chosenValue);
              list1.addAfter(it1,newValue);
            }
            else cout<<"Sprobuj jeszcze raz"<<endl;
            cout<<key;
          }
        }break;
      case '2':
        {
          int chosenValue;
          mylist::iter it2;
          cout<<"Podaj wartosc elementu, ktory chcesz usunac: "; //obs³uga blêdów!
          cin>>chosenValue;
          it2=list1.getNode(chosenValue);
          list1.deleteNode(it2);
        }break;
      case '3':
        {
          int chosenValue;
          mylist::iter it3;
          cout<<"Podaj wartosc elementu, ktory chcesz zobaczyc: "; //obs³uga blêdów!
          cin>>chosenValue;
          it3=list1.getNode(chosenValue);
          cout<<it3.refer->value<<endl;
          Sleep(1000);
        }break;
   // case '4': sumOfTwo(); break;
  //  case '5': differenceOfTwo(); break;
  //  case '6': copyElement(); break;
  //  case '7': removeDuplicates(); break;
      case '8':
        {
          cout<<list1.size;
          Sleep(1000);
        }break;
  //  case '9': comparisonOfTwo(); break;
      case 'q':break;
      default: cout<<"Sprobuj ponownie"; break;
    }
  } while (choice!='q');
    return 0;
}
