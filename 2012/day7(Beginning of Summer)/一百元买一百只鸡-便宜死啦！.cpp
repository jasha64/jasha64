//��Ǯ�ټ����⣺����5Ǯһֻ��ĸ��3Ǯһֻ��С��һǮ3ֻ��������100ֻ������100Ǯ��
//�����ּ������˶���ֻ�� 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int cock,hen,chicken;
    printf("cock hen chicken\n");
    for (cock=0;cock<=20;cock++)
        for (hen=0;hen<=33;hen++)
        {
            chicken=100-cock-hen;
            if (chicken%3==0 && 5*cock+3*hen+chicken/3==100)
                printf ("%4d%4d%6d\n",cock,hen,chicken);
        }
    system("pause");
    return 0;
}
