/* 实现数学表达式计算：（中缀表达式转后缀表达式）
1. 基于二叉树

2. 基于堆栈
使用两个栈 O 和 N， 一个存算符， 一个存操作数， 根据算符优先级出入栈。

线性扫描表达式， 比较当前算符 和栈顶算符的优先级（还要考虑结合性），如果后者优先级高， 则从数值栈顶取出元素并计算，然后把返回值入栈。 
否则 操作符/操作数依次入栈

实例: 计算 1*2+3 具体过程
依次入栈
push 1; push *; push 2     
此时栈内元素如下, 下一个算符为'+'
N |1|2| 
O |*|
由于栈顶端算符为*, 优先级高于+, 所以先计算*， 从数值栈顶取出两个操作数1和2， 相乘得返回值2，入栈
pop 1; pop 2; pop *; push 1*2
N |2| 
O |
然后再处理后面的‘+’
N |2|3| 
O |+|
-->
N |5| 
O |

大致思路如上述

3. 实现  
1. 实现一个函数 tokenize  把表达式拆解为一个一个独立的token  忽略空格等
此处的token指 数值/算符/变量
2. 实现一个函数evaluate 根据上述原理扫描已经过预处理的token序列， 实现计算。
3.对左值的处理也考虑了， 具体见源码。
*/
#include <iostream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;
stack<double> S; //存放操作符

double strTodata(string data)
{
    if (data.find(".", 0) == string::npos)
    {
        double temp = 0;
        for (int i = 0; i < data.size(); i++)
        {
            temp = temp * 10 + data[i] - '0';
        }
        return temp;
    }
    else
    {
        int index = data.find(".", 0);
        double temp = 0;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] != '.')
                temp = temp * 10 + data[i] - '0';
        }
        return temp / pow(10, data.size() - 1 - index);
    }
}

bool Prior(char op1, char op2)
{
    bool p = false;
    if (op1 == '*' || op1 == '/')
        if (op2 == '+' || op2 == '-')
            p = true;
    return p;
}

bool Isopera(char x) //操作符判断
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')')
        return true;
    else
        return false;
}

string PreToPost(string exp)
{
    string result;
    stack<char> optr; //存放操作数

    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == '(')
            optr.push(exp[i]);
        else if (exp[i] == ')')
        {
            while (optr.top() != '(')
            {
                result += optr.top();
                result += " ";
                optr.pop();
            }
            optr.pop();
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            while (!optr.empty() && optr.top() != '(' && Prior(optr.top(), exp[i]))
            {
                result += optr.top();
                result += " ";
                optr.pop();
            }
            optr.push(exp[i]);
        }
        else
        {
            result += exp[i];
            if (Isopera(exp[i + 1]) || exp[i + 1] == '\0')
                result += " ";
        }
    }

    while (!optr.empty())
    {
        result += optr.top();
        result += " ";
        optr.pop();
    }

    return result;
}
double Calculate(double op1, double op2, char oper)
{
    switch (oper)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }

    return 0;
}
int main()
{
    string str = "(1.3+2.2)*3", sub_str;
    str = PreToPost(str);
    double op1, op2, final_resl;
    int i = 0;

    while (i < str.size() - 1)
    {
        if (!Isopera(str[i]))
        {
            //表达式入栈S
            for (; str[i] != ' '; i++)
            {
                if (!Isopera(str[i]))
                    sub_str += str[i];
            }
            i++;
            S.push(strTodata(sub_str));
            sub_str.erase(0, sub_str.size());
        }
        else
        {
            //操作数入栈
            op2 = S.top();
            S.pop();
            op1 = S.top();
            S.pop();
            final_resl = Calculate(op1, op2, str[i]);
            S.push(final_resl);
            i += 2;
        }
        cout << S.top() << endl;
    }
    return 0;
}