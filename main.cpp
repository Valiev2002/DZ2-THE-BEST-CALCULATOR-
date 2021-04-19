#include <iostream>
#include <stack>
#include <sstream>
using namespace std;
int main() {
    std::string str;
    std::getline(std::cin, str);
    std::istringstream s(str);
    stack<int> opz;
    int value;
    char sign;
    while (!s.eof())
    {
        while (s >> value) {
            opz.push(value);
        }
        if (!s.eof())
        {
            s.clear();
            s.unget();
            s >> sign;
            if (opz.size() < 2)
            {
                cout << "Error"<< endl;
                return 0;
            }
            int right = opz.top();
            opz.pop();
            int left = opz.top();
            opz.pop();
            switch (sign) {
                case '+':
                    opz.push(right + left);
                    break;
                case '-':
                    opz.push(right - left);
                    break;
                case '*':
                    opz.push(right * left);
                    break;
                case '/':
                    opz.push(right / left);
                    break;
            }
        }
    }
    cout << "result value is " << opz.top()<<endl;
    return 0;
}