#include <bits/stdc++.h>
using namespace std;

class Car
{
    int price;

public:
    // Constuctor
    // The constructor which runs when there are not parameters passed to object
    Car()
    {
        cout << "Hello! From Constructor" << endl;
    }

    // The constructor which is called when object is instantiated with all the mentioned parameters
    Car(int price)
    {
        this->price = price;
    }

    // Copy Constructor --> This is present by default and we can override it like this
    Car(Car &X)
    {
        this->price = X.price;
    }
    // Setters
    void setPrice(int price)
    {
        this->price = price;
    }
    // Getters
    int getPrice()
    {
        return price;
    }
};

int main()
{
    Car bugati; // Normal constructor
    bugati.setPrice(100);
    Car veyron(bugati); // Copy constructor copies the values of bugati into veyron
    cout << "Bugati Price: " << bugati.getPrice() << endl;
    cout << "Veyron Price: " << veyron.getPrice() << endl;
}