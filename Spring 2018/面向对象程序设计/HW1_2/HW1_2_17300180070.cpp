#include <iostream>

int main()
{
	int n;
	std::cout << "�����������εı߳�: ";
	std::cin >> n;
	std::cout << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) std::cout << " *";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	int a, b;
	std::cout << "�����볤���εĳ��Ϳ�: ";
	std::cin >> a >> b;
	std::cout << std::endl;
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++) std::cout << " *";
		std::cout << std::endl; 
	}
	std::cout << std::endl;
	
	int l;
	do {
		std::cout << "��������������εĵױ߳�(����): "; std::cin >> l;
		if (l % 2 == 0) std::cout << "��������������������������ݡ�" << std::endl; 
	} while (l % 2 == 0);
	std::cout << std::endl;
	int h = l/2+1, st = 1, sp = h-1;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < sp; j++) std::cout << "  ";
		for (int j = 0; j < st; j++) std::cout << " *";
		std::cout << std::endl;
		st += 2; sp--;
	}
	
	//ϣ����һ�ε���ҵ������������˵����ǲ���ÿ�п�ͷ��һ���ո��ÿ�����Ǻ�֮��Ҫ�ӿո���Ϊֻ��ͼƬ���ղ��ø�ʽ��QAQ 
	
	return 0; 
}

