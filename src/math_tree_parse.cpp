#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lch[1010], rch[1010];        //每个叶子结点的左右子结点编号；
char op[1010];                   //每个结点的字符；
int cnt = 0;                     //结点数
char s[1010];                    //字符串

int build(char *s, int x, int y) //x表示字符串的起始地址，y表示结束地址；
{
    int i, c1 = -1, c2 = -1, p = 0, u; //c1记录“最右”出现的加减号，c2记录“最右”出现的乘除号，p记录完整的括号，u代表根节点的位置
    if (y - x == 1)                    //仅一个字符，建立单独结点
    {
        u = ++cnt;
        lch[u] = rch[u] = 0;
        op[u] = s[x];
        return u;
    }
    
    /*寻找最后一个运算符，只有当p=0的时候才考虑，因为括号里的运算符一定不是最后计算的，由于加减和乘除是左结合性
    所以括号外的最后一个运算符才是最后计算的*/
    for (i = x; i < y; i++)
    {
        switch (s[i])
        {
        case '(':
            p++;
            break;
        case ')':
            p--;
            break;
        case '+':
        case '-':
            if (!p)
                c1 = i;
            break;
        case '*':
        case '/':
            if (!p)
                c2 = i;
            break;
        }
    }
    if (c1 < 0) //找不到括号外的加减号就用乘除号；
        c1 = c2;
    if (c1 < 0)                        //连乘除号都找不到证明整个式子被一个大括号给括起来了
        return build(s, x + 1, y - 1); //把大括号去掉然后递归调用，最后找到最后计算的运算符s[c1]
    //u - 局部变量记录当前节点； cnt - 全局变量记录节点数量
    u = ++cnt;
    lch[u] = build(s, x, c1);     //左子树为[x，c1]；
    rch[u] = build(s, c1 + 1, y); //右子树为[c1+1，y]；
    op[u] = s[c1];
    printf("u:%d op:%c lch:%d rch:%d\n", u, op[u],lch[u], rch[u]);
    return u;
}
void qianxu(int u)
{
    //root -> left -> right
    if (u)
    {
        printf("%c", op[u]);
        qianxu(lch[u]);
        qianxu(rch[u]);
    }
}
void zhongxu(int u)
{
    //left -> root -> right
    if (u)
    {
        zhongxu(lch[u]);
        printf("%c", op[u]);
        zhongxu(rch[u]);
    }
}
void houxu(int u)
{
    // left -> right -> root
    if (u)
    {
        houxu(lch[u]);
        houxu(rch[u]);
        printf("%c", op[u]);
    }
}
int main()
{
    //scanf("%s", s);
    strcpy(s, "3*(1+2)-2*(1+3)-4#");
    printf("intput:%s\n", s);
    int len = strlen(s);
    int u = build(s, 0, len - 1);

#if 0
    qianxu(u);
    printf("\n");
#endif

#if 0
    zhongxu(u);
    printf("\n");
#endif

#if 1
    houxu(u);
    printf("\n");
#endif
    return 0;
}

/* result:
intput:3*(1+2)-2*(1+3)-4#
u:5 op:+ lch:6 rch:7
u:3 op:* lch:4 rch:5
u:10 op:+ lch:11 rch:12
u:8 op:* lch:9 rch:10
u:2 op:- lch:3 rch:8
u:1 op:- lch:2 rch:13
312+*213+*-4-
*/