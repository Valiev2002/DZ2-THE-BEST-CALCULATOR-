#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float a,b;
    int z;
    void Sine(float);
    void Square(float);
    void Cos(float);
    void Tan(float);
    void Log(float);
    void Baselog(float);
    cout<<"WHAT YOU WANT TO FIND: "<<endl;
    cout<<"Press '1' for Sin: "<<endl;
    cout<<"Press '2' for Square: "<<endl;
    cout<<"Press '3' for Cos: "<<endl;
    cout<<"Press '4' for Tan: "<<endl;
    cout<<"Press '5' for Log: "<<endl;
    cout<<"Press '6' for Base Log: "<<endl;
    cin>>z;
    switch(z)
    {
        case 1:
            cout<<"Enter the Number for Calculating SIN: "<<endl;
            cin>>a;
            Sine(a);
            break;

        case 2:
            cout<<"Enter the Number for Calculating Square: "<<endl;
            cin>>a;
            Square(a);
            break;

        case 3:
            cout<<"Enter the Number for Calculating COS: "<<endl;
            cin>>a;
            Cos(a);
            break;

        case 4:
            cout<<"Enter the Number for Calculating TAN: "<<endl;
            cin>>a;
            Tan(a);
            break;

        case 5:
            cout<<"Enter the Number for Calculating LOG: "<<endl;
            cin>>a;
            Log(a);
            break;

        case 6:
            cout<<"Enter the Number for Calculating LOG WITH BASE 10: "<<endl;
            cin>>a;
            Baselog(a);
            break;
    }
}

void Sine(float x)
{
    float s;
    s = sin(x);
    cout<<"Sin: "<<s;
}

void Square(float x)
{
    float sq;
    sq = sqrt(x);
    cout<<"Square of a Given Value is: "<<sq;
}

void Cos(float x)
{
    float c;
    c = cos(x);
    cout<<"COS: "<<c;
}

void Tan(float x)
{
    float t;
    t = tan(x);
    cout<<"TAN: "<<t;
}

void Log(float x)
{
    float l;
    l = log(x);
    cout<<"Natural Logarithm: "<<l;
}

void Baselog(float x)
{
    float bl;
    bl = log10(x);
    cout<<"LOG with Base 10: "<<bl;
}

