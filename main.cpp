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
  cout<<"Podaj pierwszy element pierwszej listy: ";
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
    cout<<"7. Porownaj listy"<<endl;
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
                if (listNumber=='1') list1+newValue;
                else list2+newValue;
              }
              else if (key=='n')
              {
                cout<<"Podaj wartosc elementu, ZA ktorym chcesz wstawic nowy element: ";
                cin>>chosenValue;
                it1=list1>chosenValue;
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
                it2=list1>chosenValue;
                list1-it2;
              }
              else
              {
                it2=list2>chosenValue;
                list2-it2;
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
              if (listNumber=='1') it3=list1>chosenValue;
              else it3=list2>chosenValue;
              cout<<it3.refer->value<<endl;
            }
          Sleep(1000);
        }break;
      case '4':
        {
          mylist::iter it4;
          int first2;
          trig2=1;
          it4=list2>first;
          list2-it4;
          cout<<"Podaj wartosc pierwszego elementu drugiej listy: ";
          cin>>first2;
          list2+first2;
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
      case '6':
      {
        int chosenValue, elementBefore;
        char trig=0, key, key2;
        mylist::iter it1;
          //while(trig==0)
          //{
            cout<<"Chcesz skopiowac element z:"<<endl;
            cout<<"a. Pierwszej listy"<<endl;
            cout<<"b. Drugiej listy"<<endl;
            cout<<"Wpisz a lub b: ";
            cin>>key;
            key=tolower(key);

            cout<<"Podaj wartosc elementu, ktory chcesz skopiowac: "; //obs³uga blêdów!
            cin>>chosenValue;

            if (key=='a') list1>chosenValue;
            else if (key=='b') list2>chosenValue;
            else cout<<"Sprobuj jeszcze raz"<<endl;

            cout<<"A teraz chcesz go wkleic do..."<<endl;
            cout<<"a. Pierwszej listy"<<endl;
            cout<<"b. Drugiej listy"<<endl;
            cout<<"Wpisz a lub b: ";
            cin>>key;
            key=tolower(key);

            cout<<"Chcesz wstawic skopiowany element na poczatek listy? [t/n] ";
              cin>>key2;
              key2=tolower(key2);
              if (key2=='t')
              {
                if (key=='a') list1+chosenValue;
                else list2+chosenValue;
              }
              else if (key2=='n')
              {
                cout<<"Podaj wartosc elementu, ZA ktorym chcesz wstawic nowy element: ";
                cin>>elementBefore;
                if (key=='a')
                {
                  it1=list1>elementBefore;
                  list1.addAfter(it1,chosenValue);
                }
                else
                {
                  it1=list2>elementBefore;
                  list2.addAfter(it1,chosenValue);
                }
              }
              else cout<<"Sprobuj jeszcze raz"<<endl;
         // }
      }break;
      case '7':
        {
          list1.compareLists(list1.head, list2.head, list2.size);
        }break;
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
