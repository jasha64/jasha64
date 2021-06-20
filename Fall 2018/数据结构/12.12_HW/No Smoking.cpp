//Ural 1469 No Smoking
//ɨ�����㷨 + ƽ���� 
#include <iostream>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <cmath>
using namespace std;

const int N = 100001;
const double eps = 1e-6, C = acos(-1) / 60;
double xnow; //ɨ���ߵĵ�ǰ���� 

//�߶Ρ�ƽ���� 
struct Segment
{
	int id;
	double x1, y1, x2, y2;
	double k, b;
	void Rotate(double& x, double& y)
	{
		double p = x, q = y;
		x = cos(C) * p - sin(C) * q; y = sin(C) * p + cos(C) * q;
	}
	void init()
	{
		cin >> x1 >> y1 >> x2 >> y2;
		Rotate(x1, y1); Rotate(x2, y2); //��ֹ������ֱ�߶Σ����߶���תһ��С�Ƕ� 
		if (x1 > x2) {swap(x1, x2); swap(y1, y2);}
		k = (y2 - y1) / (x2 - x1);
		b = y1 - k * x1;
	}
	//�����ֱ�߶ε���һ���������ǰѷ�ĸ��Ϊx2 - x1 + eps��������һЩ�ط�Ҳ��Ҫ��Ӧ�޸� 
	//����һ�������ǣ�if (x1 == x2) k = 1e9; 
	double y() const {return k * xnow + b;}
	friend bool operator < (const Segment& a, const Segment& b) {return a.y() < b.y() || (a.y() == b.y() && a.id < b.id);}
	//��pb_ds��tree�У��ж�Ԫ���Ƿ������ͨ��!(a < b) && !(b < a)�����еģ����Ԫ�ػ����ʧ�� 
	//�༴����ֵ��ȵ�ʵ�ʲ��ȵ�Ԫ��Ҳ�����ʧ�� 
	//set�����ϵ��"Ψһ"ʱ��Ҳ����������ֵֹ����� 
	//������������಻�����ظ�Ԫ�صı�׼��������������Ҫ����һ��"Ψһ"�����ϵ��ʹ����������Ԫ�ض��ܱȽϴ�С 
} sg[N];
set<Segment> T;

//�߶�sg��ƽ�����ϵ�ǰһ������һ��id 
inline int Prev(const Segment& sg)
{
	if (T.empty()) return -1;
	auto I = T.lower_bound(sg); //C++11�п���ֱ����auto������������ͣ��Ͳ���дһ��tree<Type, null_type, ...>::iterator�� 
	return I == T.begin() ? -1 : (--I) -> id;
	//lower_bound(val)���ز�С��val�ĵ�һ��Ԫ�صĵ����������val�������У��򷵻�end()��
	//����õĽ��ǰ��һλ����ǰ��������val�ڲ���ƽ�����У� 
	//ԭʼ���壺lower_bound()����һ��iterator����ָ����[first,last)��ǵ����������п��Բ���value�����ƻ�����˳��ĵ�һ��λ�� 
	//ע�⣺�������Լ�������漰��һ�����⣬������Ѿ�ָ��begin�������Լ��õ��������Լ������Դ˴�Ҫ���Լ�֮ǰ���С� 
}
inline int Next(const Segment& sg)
{
	if (T.empty()) return -1;
	auto I = T.upper_bound(sg);
	return I == T.end() ? -1 : I -> id;
	//upper_bound(val)���ش���val�ĵ�һ��Ԫ�صĵ����������val��С�����У��򷵻�end()������Ϊ��̣�����val�ڲ���ƽ�����У� 
	//ԭʼ���壺upper_bound()����һ��iterator����ָ����[first,last)��ǵ����������п��Բ���value�����ƻ�����˳������һ��λ�� 
}
//��Ȼ��Ҳ������findʵ�� 
//pb_ds��tree�������������������ܣ������ⲻ��Ҫ�õ�������ֻ��Ҫ��ǰ����̣�������set�Ѿ���ȫ���������� 

//�¼���idΪ��Ӧ�߶α�ţ�opΪ���ͣ�op == 1��ʾ�߶ο�ʼ��op == 0��ʾ�߶ν��� 
struct Event
{
	double x;
	int id, op;
	friend bool operator < (const Event& a, const Event& b)
	{
		if (a.x != b.x) return a.x < b.x;
		return a.op > b.op; //�Ȳ��룬��ɾ������Ϊ�����ڶ˵㴦�ཻ�� 
	}
} ev[N+N];

//�߶��ཻ�ж� 
inline int dcmp(double x) //���������ǰ���µķ��ź��� 
{
	if (fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}
inline double Dot(double x1, double y1, double x2, double y2) {return x1 * x2 + y1 * y2;}
inline double Cross(double x1, double y1, double x2, double y2) {return x1 * y2 - x2 * y1;}
bool SegmentIntersect(int id1, int id2)
{
	if (id1 == -1 || id2 == -1 || id1 == id2) return false;
	const Segment& s1 = sg[id1]; //AB
	const Segment& s2 = sg[id2]; //CD
	int c1 = dcmp(Cross(s2.x1-s1.x1, s2.y1-s1.y1, s2.x1-s1.x2, s2.y1-s1.y2)), //CA ��CB�ķ��� 
		c2 = dcmp(Cross(s2.x2-s1.x1, s2.y2-s1.y1, s2.x2-s1.x2, s2.y2-s1.y2)), //DA ��DB�� 
		c3 = dcmp(Cross(s1.x1-s2.x1, s1.y1-s2.y1, s1.x1-s2.x2, s1.y1-s2.y2)), //AC ��AD
		c4 = dcmp(Cross(s1.x2-s2.x1, s1.y2-s2.y1, s1.x2-s2.x2, s1.y2-s2.y2)), //BC ��BD
		d1 = dcmp(Dot(s2.x1-s1.x1, s2.y1-s1.y1, s2.x1-s1.x2, s2.y1-s1.y2)), //CA ��CB
		d2 = dcmp(Dot(s2.x2-s1.x1, s2.y2-s1.y1, s2.x2-s1.x2, s2.y2-s1.y2)), //DA ��DB 
		d3 = dcmp(Dot(s1.x1-s2.x1, s1.y1-s2.y1, s1.x1-s2.x2, s1.y1-s2.y2)), //AC ��AD 
		d4 = dcmp(Dot(s1.x2-s2.x1, s1.y2-s2.y1, s1.x2-s2.x2, s1.y2-s2.y2)); //BC ��BD 
	if (c1 * c2 < 0 && c3 * c4 < 0) return true; //�߶ι淶�ཻ��ÿ���߶ε����˵�ǡ����һ�߶����� 
	return (c1 == 0 && d1 <= 0) || (c2 == 0 && d2 <= 0) ||
		(c3 == 0 && d3 <= 0) || (c4 == 0 && d4 <= 0); //���������ֻ���ж�һ���߶εĶ˵��ڲ�����һ�߶��ϼ��� 
}

inline void PrintY(int id1, int id2) {cout << "YES" << endl << id1 << ' ' << id2 << endl;}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		sg[i].init(); sg[i].id = i;
		ev[i] = (Event){sg[i].x1, i, 1}; ev[i+n] = (Event){sg[i].x2, i, 0};
	}
	
	sort(ev + 1, ev + n + n + 1);
	for (int i = 1; i <= n + n; i++)
	{
		xnow = ev[i].x;
		if (ev[i].op == 1)
		{
			int id = ev[i].id;
			T.insert(sg[id]);
			int pr = Prev(sg[id]), ne = Next(sg[id]);
			if (SegmentIntersect(pr, id)) {PrintY(id, pr); return 0;}
			if (SegmentIntersect(id, ne)) {PrintY(id, ne); return 0;}
		}
		else {
			int id = ev[i].id, pr = Prev(sg[id]), ne = Next(sg[id]);
			if (SegmentIntersect(pr, ne)) {PrintY(pr, ne); return 0;}
			T.erase(T.find(sg[id]));
		}
	}
	cout << "NO" << endl;
	return 0;
}
//�ο����ϣ����㷨�������ž���ѵ��ָ�ϡ������㷨���ۡ����ߴ�ү��vjudge�ϵı�� 

