#include "store.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Store::Store(){
  
}
Store::~Store(){
  
}
ostream& operator<<(ostream &stream,const Store &st){
  stream<<"Название: "<<st.name<<endl;
  stream<<"Стоимость: "<<st.cost<<endl;
  stream<<"Век: "<<st.year<<endl;
  return stream;
}

istream & operator >>(istream & in, Store &st) {
  in >> st.name;
  in >> st.cost;
  in >> st.year;
  return in;
}
void print(Store *array, int size){
  for (int i = 0; i<size; i++){
    cout<<"<====Номинант====>"<<endl;
    cout<<"Номер товара: "<<i+1<<endl;
    cout<<array[i]<<endl;
  }
}


void Store::set(string n,int c,int y){
  name=n;
  cost=c;
  year=y;
}

string Store:: getName(){
  return name;
}

int Store:: getCost(){
  return cost;
}

int Store:: getYear(){
  return year;
}

int getCount(string name){
  int n=0;
  ifstream f(name, ios::binary);
  f.read((char*)&n,sizeof(n));
  f.close();
  return n;
}
Store* read(string name){
  Store *a;
  ifstream f(name, ios::binary);
  int c=0,y=0,count=0;
  f.read((char*)&count,sizeof(count));
  a=new Store[count];
  for (int j=0;j<count;j++){
    string::size_type n = 0;
    f.read((char*)&n, sizeof(string::size_type));
    string s(n,0);
    for (int i = 0; i < n; ++i)
      f.read(&s[i], sizeof(s[0]));
    f.read((char *)&c, sizeof(c));
    f.read((char *)&y, sizeof(y));
    a[j].set(s,c,y);
  }
  return a;
}
void input(Store *a,string name,int count){
  ofstream f(name, ios::binary);
  f.write((char*)&count,sizeof(count));
  for (int i=0;i<count;i++){
    Store b=a[i];
    string name=b.getName();
    int cost=b.getCost();
    int year=b.getYear();
    string::size_type n = name.size(); 
    f.write((char*)&n, sizeof(string::size_type));
    f.write(name.c_str(), name.size());
    f.write((char*)&cost,sizeof(cost));
    f.write((char*)&year,sizeof(year));
    
  }
  f.close();

}

Store* add(Store *a,int n){
  Store *b=new Store[n+1];
  string name;
  int cost,year;
  for (int i=0;i<n;i++)
    b[i]=a[i];
  cout<<"Название: ";
  cin>>name;
  cout<<"Стоимость: ";
  cin>>cost;
  cout<<"Век: ";
  cin>>year;
  b[n].set(name,cost,year);
  return b;
}



Store* del(Store *a,int n){
  int c,j=0;
  cout<<"Номер товара: ";
  cin>>c;
  Store *b=new Store[n-1];
  for (int i=0;i<n;i++)
    if ((c-1)!=i){
      //cout<<a[i].getName()<<endl;
      b[j]=a[i];
      j++;
    }
  return b;
}

void searchName(Store *a,int n){
  string s;
  cout<<"Название товара: ";
  cin>>s;
  for (int i=0;i<n;i++)
    if (a[i].getName()==s){
      cout<<"<====Товар====>"<<endl;
	    cout<<"Номер товара: "<<i+1<<endl;
	    cout<<"Товар: "<< a[i].getName()<<endl;
	    cout<<"Стоимость: "<< a[i].getCost()<<endl;
	    cout<<"Год создания: "<< a[i].getYear()<<endl;
    }
}

Store* change(Store *a,int n){
  cout<<"Номер товара: ";
  string name;
  int cost,year,c;
  cin>>c;
  if(c-1<n){
    cout<<"------------"<<endl;
    cout<<"Новое имя: ";
    cin>>name;
    cout<<"Новая цена: ";
    cin>>cost;
    cout<<"Новый век: ";
    cin>>year;
    a[c-1].set(name,cost,year);
  }
  
  return a;
}