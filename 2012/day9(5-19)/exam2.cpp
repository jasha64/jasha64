#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    while (cin>>n)
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n-i;j++) cout<<" ";    //�����1����������߿ո� 
            for (j=1;j<=2*i-1;j++) cout<<"*";  //�����1���������Ǻ� 
            for (j=1;j<=2*(n-i);j++) cout<<" ";//�����2����������߿ո�
            for (j=1;j<=2*i-1;j++) cout<<"*";  //�����2���������Ǻ�
            for (j=1;j<=2*(n-i);j++) cout<<" ";//�����3����������߿ո�
            for (j=1;j<=2*i-1;j++) cout<<"*";  //�����3���������Ǻ�
            cout<<endl;  //���� 
        }
    
    return 0;
}
