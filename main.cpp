#include <fstream>
#include <iostream>
#include "store.hpp"
using namespace std;
int main(int argc, char *argv[]){  
  if (argc<=1){
    cout<<"Не задано имя файла"<<endl;
    return 0;
  }
  
  Store *a=read(argv[1]);
  int n=getCount(argv[1]);
  int k=1;
  while (k!=0){
    cout<<"=====WELCOME IN THE STORE====="<<endl;
    cout<<"1.Добавить товар"<<endl;
    cout<<"2.Просмотреть ассортимент"<<endl;
    cout<<"3.Продать/удалить товар"<<endl;
    cout<<"4.Изменить товар"<<endl;
    cout<<"5.Найти товар по названию"<<endl;
    cout<<"0.Выйти"<<endl;
    cout<<"================="<<endl;
    cout<<"Выберите пункт с клавиатуры: ";
    cin>>k;
    switch (k){
      case 1:
        a=add(a,n);
        n++;
        break;
      case 2:
        print(a,n);
        break;
      case 3:
        a=del(a,n);
        n--;
        break;
      case 4:
        a=change(a, n);
        break;
      case 5:
        searchName(a, n);
        break;
      default:
        input(a, argv[1], n);
        n=0;
        break;

    }
  }
  delete []a;
  return 0;
}
