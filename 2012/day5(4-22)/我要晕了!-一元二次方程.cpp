#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    double a,b,c,d,x1,x2;
    cin>>a>>b>>c;
    d=b*b-4*a*c;
    if (d>=0)
        if (d==0)
            printf("x1=x2=%.2lf\n",-b/(2*a)); //��ʵ��������һ����~ 
        else {
                x1=(-b+sqrt(d))/(2*a);
                x2=(-b-sqrt(d))/(2*a);
                printf("x1=%.2lf x2=%.2lf\n",x1,x2); //��ѽ��ͦ���۸��ӵ���� 
             }
    else cout<<"�÷�����ʵ���⣡"<<endl; //�ð��������� ���� 
    system("pause");
    return 0;
}
