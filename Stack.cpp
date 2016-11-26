#include <iostream>
#include<stack>
#include<string.h>
using namespace std;
int opration(char opra)
{
    switch(opra)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 3;
        break;
    case'/':
        return 3;
        break;
    case '(':
        return 5;
        break;
    case')':
        return 0;
        break;
    default:
        return -1;
    }
}
int reopra(char opra)
{
    switch(opra)
    {
    case '+':
        return 2;
        break;
    case '-':
        return 2;
        break;
    case '*':
        return 4;
        break;
    case'/':
        return 4;
        break;
    case '(':
        return 0;
        break;
    case')':
        return 5;
        break;
    default:
        return -1;
    }
}
double calcul(char opra,double a1,double a2)
{
    switch(opra)
    {
    case '+':
        return a1+a2;
    case '-':
        return a1-a2;
    case '*':
        return a1*a2;
    case '/':
        return a1/a2;
    default:
        return 0;
    }
}
double cal(char *com)
{
    stack<double> *s = new stack<double>();
    stack<char> *op = new stack<char>();
    char ap[2] = "q";
    strcat(com, ap);
    int i=0,j=0;
    while(1)
    {
        if(com[i]=='\0') break;
        if((com[i]=='.')||((com[i]<='9')&&(com[i]>='0')))
            ++i;
        else
        {
            //把数字送入数字栈中
            double one = 0;
            int dot = 0;
            for(int k=0; k<i-j; k++)
            {
                if(com[j+k]=='.')
                    dot=i-j-k-1;
                else
                    one=one*10+(com[j+k]-48);
            }
            if(i>j)
            {
                for(int k =0; k<dot; k++) one /=10.00;
                s->push(one);
                dot=0;
                //cout<<one<<endl;
            }
            //把操作符送入栈
            if(op->size()==0)
                op->push(com[i]);
            else
            {
                if(opration(com[i])>=reopra(op->top()))
                    op->push(com[i]);
                else
                {
                    while((op->size()!=0)&&(op->top()!='(')&&(opration(com[i])<reopra(op->top()))){
                        double a1 = s->top();
                        s->pop();
                        double a2 = s->top();
                        s->pop();
                        double a3 = calcul(op->top(),a2,a1);
                        char oo = op->top();
                        op->pop();
                      //  if((op->size()!=0)&&(op->top()=='(') ) op->pop();
                        s->push(a3);
                         cout<<"过程："<<a2<<oo<<a1<<'='<<a3<<endl;

                    }
                     if((op->size()!=0)&&(op->top()=='(') ) op->pop();
                      if(com[i]!=')')
                            op->push(com[i]);
                }
            }
            j=++i;
        }
    }
    return s->top();
}
int main()
{
    char *com  = new char[100];
    cin>>com;
   double ss =  cal(com);
   cout<<"结果为："<<ss<<endl;
    return 0;
}
