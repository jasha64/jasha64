//������������е��ۼӺͣ��ۼ�n�������n�Ӽ������롣 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,b,c,n;  //aΪ���ӣ�bΪ��ĸ��c������ʱ��������� 
    double sum;
    while (cin>>n)
    {
        sum=0; a=2; b=1;
        for (int i=1;i<=n;i++)
        {
            sum+=a/(double)b;
            c=a+b; b=a; a=c;
        }
        printf("%.6lf\n",sum);
    }
    system("pause");
    return 0;
}
