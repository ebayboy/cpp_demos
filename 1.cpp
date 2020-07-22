#include <iostream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;
stack<double> S; //存放操作符

double strTodata(string data)
{
    if (data.find(".", 0) == string::npos)
    {
        double temp = 0;
        for (int i = 0; i < data.size(); i++)
        {
            temp = temp * 10 + data[i] - '0';
        }
        return temp;
    }
    else
    {
        int index = data.find(".", 0);
        double temp = 0;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] != '.')
                temp = temp * 10 + data[i] - '0';
        }
        return temp / pow(10, data.size() - 1 - index);
    }
}

bool Prior(char op1, char op2)
{
    bool p = false;
    if (op1 == '*' || op1 == '/')
        if (op2 == '+' || op2 == '-')
            p = true;
    return p;
}

bool Isopera(char x) //操作符判断
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')')
        return true;
    else
        return false;
}

string PreToPost(string exp)
{
    string result;
    stack<char> optr; //存放操作数

    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == '(')
            optr.push(exp[i]);
        else if (exp[i] == ')')
        {
            while (optr.top() != '(')
            {
                result += optr.top();
                result += " ";
                optr.pop();
            }
            optr.pop();
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            while (!optr.empty() && optr.top() != '(' && Prior(optr.top(), exp[i]))
            {
                result += optr.top();
                result += " ";
                optr.pop();
            }
            optr.push(exp[i]);
        }
        else
        {
            result += exp[i];
            if (Isopera(exp[i + 1]) || exp[i + 1] == '\0')
                result += " ";
        }
    }

    while (!optr.empty())
    {
        result += optr.top();
        result += " ";
        optr.pop();
    }

    return result;
}
double Calculate(double op1, double op2, char oper)
{
    switch (oper)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }

    return 0;
}
int main()
{
    string str = "(1.3+2.2)*3", sub_str;
    str = PreToPost(str);
    double op1, op2, final_resl;
    int i = 0;

    while (i < str.size() - 1)
    {
        if (!Isopera(str[i]))
        {
            //表达式入栈S
            for (; str[i] != ' '; i++)
            {
                if (!Isopera(str[i]))
                    sub_str += str[i];
            }
            i++;
            S.push(strTodata(sub_str));
            sub_str.erase(0, sub_str.size());
        }
        else
        {
            //操作数入栈
            op2 = S.top();
            S.pop();
            op1 = S.top();
            S.pop();
            final_resl = Calculate(op1, op2, str[i]);
            S.push(final_resl);
            i += 2;
        }
        cout << S.top() << endl;
    }
    return 0;
}
