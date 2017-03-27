#include <iostream>
#include "list.h"
using namespace std;

int main()
{
  int first;
  cout<<"Podaj pierwszy element listy"<<endl;
  cin>>first;
  mylist list1(first) ;
  char choice;
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
  cout<<"8. Porownaj dwie listy"<<endl;
  cout<<"--------------------"<<endl;
  cout<<"Twoj wybor: ";
  cin>>choice;

 /* switch(choice)
  {
    case 1: addElement(); break;
    case 2: removeElement(); break;
    case 3: readElement(); break;
    case 4: sumOfTwo(); break;
    case 5: differenceOfTwo(); break;
    case 6: copyElement(); break;
    case 7: removeDuplicates(); break;
    case 8: size(); break;
    case 9: comparisonOfTwo(); break;
  }*/

    return 0;
}
