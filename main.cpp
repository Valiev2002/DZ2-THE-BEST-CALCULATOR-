
#include <iostream>
using namespace std;
int  main()
{
int a, b;
char rezult;
    cout<<"Enter something"<<endl;
cin>>a>>rezult>>b;
switch (rezult) {
    case '+':
        cout << a + b << endl;
        break;
    case '-':
        cout << a - b << endl;
        break;
    case '*':
        cout << a * b << endl;
        break;
    case '/':
        cout << (float) a / b << endl;
        break;
}
}
