//�����100���ڵ�����������ÿ�����5�����ո������ 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int output(0),i,j; //iΪ��������jΪ������ 
    for (i=2;i<=100;i++)
    {
        for (j=2;j<=i/2;j++)
            if (i%j==0)
                break;
        if (j>i/2)
        {
            cout<<i<<" ";
            output++;
            if (output%5==0) cout<<endl;
        }
    }
    system("pause");
    return 0;
}
