//���һ�������������е�����������������֮�ͣ����������������ȫ��������1000
//�������е���ȫ���� 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int i,j,sum; //jΪi������
    for (i=1;i<=1000;i++)
    {
        sum=0;
        for (j=1;j<=i/2;j++)
            if (i%j==0)
                sum+=j;
        if (i==sum) cout<<i<<endl;
    }
    system("pause");
    return 0;
}
