#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int x,i;
    cin>>x;
    for (i=2;i<x;i++)
        if (x%i==0)
            break;
    if (x!=1&&x!=0)
        if (i>=x) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    else cout<<"�Ȳ�������Ҳ���Ǻ���"<<endl; 
    system("pause");
    return 0;
}
