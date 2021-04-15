#ifndef STORE_HPP
#define STORE_HPP
#include <iostream>
using namespace std;

class Store{
  int cost;
  int year;
  string name;
  public:
    Store();
    ~Store();
    string getName();
    int getCost();
    int getYear();
    void set(string n,int c,int y);
    friend ostream & operator <<(ostream & out, const Store &st);
    friend istream & operator >>(istream & out, Store &st);
    
};
void print(Store *array, int size);
void input(Store *a, string name,int count);
Store* read(string name);
int getCount(string name);
Store* add(Store *a,int n);
Store* del(Store *a,int n);
Store* change(Store *a,int n);
void searchName(Store *a,int n);
#endif