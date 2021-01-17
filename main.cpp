#include <iostream>
#include <string>
#include <stack>
#include <cmath>
char Priority(char& action) //приоритет действий
{
    switch (action)
    {
        case '+':
        case '-':
        {
            return 1;
        }
        case '*':
        case '/':
        {
            return 2;
        }
        case '^':
        {
            return 3;
        }
    }
}

void simbols(std::string& s, std::stack <char>& signs, std::string& s_function)
{
    if (s_function == "pi")
    {
        s += std::to_string(3.141593);
        char backspace = 32; // пробел - разграничитель, чтобы не сливались числа (в дальнейшем всё аналогично)
        s += backspace;
    }
    else if (s_function == "e")
    {
        s += std::to_string(2.718282);//e
        char backspace = 3;
        s += backspace;
    }
    else if (s_function == "x")
    {
        std::cout << "Enter the x argument: ";
        double x;
        std::cin >> x;
        s += std::to_string(x);
        char backspace = 3;
        s += backspace;
    }
    else if (s_function == "sin")
    {
        signs.push('s');
    }
    else if (s_function == "cos")
    {
        signs.push('c');
    }
    else if (s_function == "tg")
    {
        signs.push('T');
    }
    else if (s_function == "ctg")
    {
        signs.push('C');
    }
    else if (s_function == "sqrt")
    {
        signs.push('S');
    }//еще е^
    else if (s_function == "exp")
    {
        s += std::to_string(2.718282);
        signs.push('^');
        char backspace = 3;
        s += backspace;
    }
    s_function.clear();
}

void Exit(std::string& s, std::string& number, std::stack <char>& signs, std::string& s_function, char action)
{
    if (isdigit(action) != 0) // если цифра, то записывается в number
    {
        number += action;
    }
    else
    {
        if (isalpha(action) != 0) // если буква то в строку
        {
            s_function += action;
        }
        else
        {
            if (action == '.') //точка
            {
                number += action;
            }
            else
            {
                if (number.length() != 0)
                {
                    s += number;
                    number.clear();
                    char backspace = 3;
                    s += backspace;
                }
                if (s_function.length() != 0)
                {
                    simbols(reinterpret_cast<std::string &>(exit), signs, s_function);
                }
                if (signs.empty()) // если пуст добавить знак
                {
                    signs.push(action);
                }
                else
                {
                    if (action == '(') // добавление открывающейся скобки в стек
                    {
                        signs.push(action);
                    }
                    else
                    {
                        if (action == ')')
                        {
                            while (signs.top() != '(')
                            {
                                s += signs.top();
                                signs.pop();
                                char backspace = 3;
                                s += backspace;
                            }
                            signs.pop(); // удаление из стека
                            if (!signs.empty())
                            {
                                if (isalpha(signs.top()) != 0)
                                {
                                    s += signs.top();
                                    signs.pop();
                                    char backspace =3;
                                    s += backspace;
                                }
                            }
                        }
                        else
                        {
                            if (signs.top() == '(')
                            {
                                signs.push(action);
                            }
                            else // добавление знака в стек знаков по приоритету
                            {
                                if (Priority(action) > Priority(signs.top()))
                                {
                                    signs.push(action);
                                }
                                else
                                {

                                    while ((!signs.empty()) && (Priority(action) <= Priority(signs.top())))
                                    {
                                        s += signs.top();
                                        signs.pop();
                                        char backspace = 32;
                                        s += backspace;
                                    }
                                    signs.push(action);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void solve (std::stack <double>& double_numbers, std::string& s_function)
{
    if (s_function == "s") // синус
    {
        double a;
        a = double_numbers.top();
        double_numbers.pop();
        a = sin(a);
        double_numbers.push(a); // обратно в стэк
    }
    else if (s_function == "c") // косинус
    {
        double a;
        a = double_numbers.top();
        double_numbers.pop();
        a = cos(a);
        double_numbers.push(a);
    }
    else if (s_function == "T") // тангенс
    {
        double a;
        a = double_numbers.top();
        double_numbers.pop();
        a = tan(a);
        double_numbers.push(a);
    }
    else if (s_function == "C") // котангенс
    {
        double a;
        a = double_numbers.top();
        double_numbers.pop();
        a = 1 / tan(a);
        double_numbers.push(a);
    }
    else if (s_function == "S") // корень
    {
        double a;
        a = double_numbers.top();
        double_numbers.pop();
        a = sqrt(a);
        double_numbers.push(a);
    }
    else if (s_function == "+")
    {
        double a;
        double b;
        b = double_numbers.top();
        double_numbers.pop();
        a = double_numbers.top();
        double_numbers.pop();
        a += b;
        double_numbers.push(a);
    }
    else if (s_function == "-")
    {
        double a;
        double b;
        b = double_numbers.top();
        double_numbers.pop();
        a = double_numbers.top();
        double_numbers.pop();
        a -= b;
        double_numbers.push(a);
    }
    else if (s_function == "*")
    {
        double a;
        double b;
        b = double_numbers.top();
        double_numbers.pop();
        a = double_numbers.top();
        double_numbers.pop();
        a = a * b;
        double_numbers.push(a);
    }
    else if (s_function == "/")
    {
        double a;
        double b;
        b = double_numbers.top();
        double_numbers.pop();
        a = double_numbers.top();
        double_numbers.pop();
        a = a / b;
        double_numbers.push(a);
    }
    else if (s_function == "^")
    {
        double a;
        double b;
        b = double_numbers.top();
        double_numbers.pop();
        a = double_numbers.top();
        double_numbers.pop();
        a = pow(a, b);
        double_numbers.push(a);
    }
}

void Calculate (std::stack <double>& double_numbers, std::string& number, std::string& s_function, char action)
{
    if (isdigit(action) != 0)
    {
        number += action;
    }
    else
    {
        if (action == '.') // точка для double
        {
            number += action;
        }
        else
        {
            if (number.length() != 0)
            {
                double stack_number = std::stod(number);
                double_numbers.push(stack_number);
                number.clear();
            }
            if (action != ' ') // если символ не пробел
            {
                s_function += action;
                solve(double_numbers, s_function);
                s_function.clear();
            }
        }
    }
}

int main()
{
    std::string s;
    std::string number;
    std::stack <char> signs;
    std::string s_function;
    std::string expression;
    std::cout << "Enter your expression: ";
    std::getline(std::cin, expression);
    int expression_size = expression.length();
    for (int h = 0; h < expression_size; h++)
    {
        char action;
        action = expression[h];
        Exit(s, number, signs, s_function, action); // обратная польская запись
        if (h == (expression_size - 1))
        {
            if (number.length() != 0)
            {
                s += number;
                number.clear();
                char backspace = 32;
                s += backspace;
            }
            if (s_function.length() != 0)
            {
                simbols(reinterpret_cast<std::string &>(exit), signs, s_function);
            }
            while (!signs.empty()) // запись из стека знаков оставшихся знаков
            {
                s += signs.top();
                signs.pop();
                char probel = 32;
                s += probel;
            }
        }
    } // конец обратной польской записи
    std::stack <double> double_numbers; // стек double чисел
    int exit_size = s.length();
    for (int h = 0; h < exit_size; h++)
    {
        char action;
        action = s[h];
        Calculate(double_numbers, number, s_function, action); // вычисление
    }
    std::cout << "\n";
    std::cout << " result  " << double_numbers.top(); // ответ
    std::cout << "\n";
}