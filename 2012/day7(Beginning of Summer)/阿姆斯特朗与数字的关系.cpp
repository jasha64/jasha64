//���һ���������ĸ�λ���ֵ������͵��������������Ϊ��ķ˹����������1000���ڵ�
//���а�ķ˹�������� 
#include<iostream>
using namespace std;
int main()
{
    int x,i,sum;
    for (i=1;i<1000;i++)
    {
        sum=0;
        x=i;
        while (x>0)
        {
            sum+=(x%10)*(x%10)*(x%10);
            x/=10;
        }
        if (sum==i) cout<<i<<endl;
    }
    system("pause");
    return 0;
}
