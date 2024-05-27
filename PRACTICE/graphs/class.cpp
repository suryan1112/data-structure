#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
private:
    int a = 34;

public:
    Vehicle()
    {
        cout << "default vehicle contr" << endl;
    }
    ~Vehicle()
    {
        cout << "default vehicle decontr" << endl;
    }
    friend void Honda ::print();
};
class Car : public Vehicle
{
public:
    Car()
    {
        cout << "default car contr" << endl;
    }
    ~Car()
    {
        cout << "default car decontr" << endl;
    }
};
class Honda
{
public:
    Honda()
    {
        cout << "default Honda contr" << endl;
    }
    ~Honda()
    {
        cout << "default Honda decontr" << endl;
    }
    void print()
    {
        Vehicle v;
        cout << v.a;
    }
};

int main()
{
    Honda h;
    h.print();
}