//����һ�������������ĸ�λ����ƽ���͡� 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int x,sum;
    cin>>x;
    sum=0;
    while (x>0)
    {
        sum+=(x%10)*(x%10);
        x/=10;
    }
    cout<<sum<<endl;    
    system("pause");
    return 0;
}
