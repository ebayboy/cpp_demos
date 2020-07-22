/* 实现数学表达式计算：（中缀表达式转后缀表达式）
1. 基于二叉树

2. 基于堆栈
Pre order -> Post Order
PreOrder:5*(2+3-4)-1
PostOrder:5 2 3 4 - + * 1 -
2*(1+3)-5  -> 2 1 3 + * 5 -
result:
result  operator_stack 
5 *
5 *(
52 *(
52 *(+
523 *(+
523 *(+-
5234 *(+-  因为top +和比较的-为同一优先级， 不输出操作符
5234-+ * 
5234-+* -
5234-+*1 -
5234-+*1-
*/


#include <iostream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

stack<double> S; //存放操作数op1 op2

//Check if op1 priority > op2 priority
bool Prior(char op1, char op2)
{
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
    {
        return true;
    }

    return false;
}

bool IsOpera(char x) //操作符判断
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')')
        return true;
    else
        return false;
}

//Pre order -> Post Order
//PreOrder:5*(2+3-4)-1
//PostOrder:5 2 3 4 - + * 1 -
//2*(1+3)-5  -> 2 1 3 + * 5 -
//result:
// result  operator_stack
// 5 *
// 5 *(
// 52 *(
// 52 *(+
// 523 *(+
// 523 *(+-
// 5234 *(+-
// 5234-+ *
// 5234-+* -
// 5234-+*1 -
// 5234-+*1-
string PreToPost(string exp)
{
    string result;    //保存输出后缀表达式
    stack<char> optr; //存放操作符  +-*/()

    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == '(')
        {
            optr.push(exp[i]); //top (
        }
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
            //eg. (2*3+4）-> 23*4+
            //eg. (2+3-4）-> 23+4-
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
            if (IsOpera(exp[i + 1]) || exp[i + 1] == '\0') //next is operator or end
            {
                result += " ";
            }
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

double ExpressionCal(string str)
{
    string sub_str;

    cout << "PreOrder:" << str << endl;
    str = PreToPost(str);
    cout << "PostOrder:" << str << endl;

    double op1, op2, final_resl;
    int i = 0;

    while (i < str.size() - 1)
    {
        if (!IsOpera(str[i]))
        {
            //表达式入栈S
            for (; str[i] != ' '; i++)
            {
                if (!IsOpera(str[i]))
                    sub_str += str[i];
            }
            i++;
            S.push(std::atof(sub_str.c_str()));
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
    }

    return final_resl;
}
/*
PreOrder:5*(2+3-4)-1
PostOrder:5 2 3 4 - + * 1 -
final_resl:3
*/
int main()
{
    string str = "5*(2+3-4)-1";

    double final_resl = ExpressionCal(str);

    cout << "final_resl:" << final_resl << endl;

    return 0;
}