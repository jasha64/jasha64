#pragma once
#include <cstddef>
#include <memory>

template <class T>
class Vec
{
public:
	//���Ͷ���
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;

	//���캯��
	Vec() { create(); }
	explicit Vec(size_type n, const T& t = T()) { create(n, t);	}
	//explicit�ؼ��ֵ����ã���ֹ��ʽ���ù��캯������ֹ����Ȼ����ʽ����ת�����ǵȺų�ʼ��ʱ�Ķ����ͻ
	//���������������ĳ���ض����ݽṹ�Ĵ�С��ʱ��Ӧʹ�ø����ݽṹ����Ӧ����

	//���ơ���ֵ����������
	Vec(const Vec& v) { create(v.begin(), v.end()); } //��Ϊ���ƺ������Ѿ������˲������������Ĺ��̣�����Ĳ�������������
	Vec& operator = (const Vec&);
	~Vec() { uncreate(); }

	//�������������
	T& operator [] (size_type i) { return data[i]; }
	const T& operator [] (size_type i) const { return data[i]; }
	//���������������ĳ���ض����ݽṹ�Ĵ�С��ʱ��Ӧʹ�ø����ݽṹ����Ӧ����
	//Ӧ���������࣬����һ����const���ͣ��Ա���ೣ�����Ե���

	//��Ա���������Ԫ��
	void push_back(const T& t)
	{
		if (avail == limit) grow();
		unchecked_append(t);
	}
	//�����������������ͣ���Ϊ����T���ͷǳ����ӵ�ʱ���ֹ��ʱ�临��

	//��Ա��������С
	size_type size() const { return avail - data; }
	//ԭ���ϣ����ı�����ڲ�״̬�ĳ�Ա������Ӧ��const�޶����Ա���ೣ��������Ե���

	//��Ա�������Ƿ�Ϊ��
	bool empty() const { return data == NULL; }

	//��Ա�����������ǰ��Vec���ָ�����ʼ״̬
	void clear() { uncreate(); create(); }

	//��Ա�������׵�ַ��Խ���ַ
	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }

private:
	//��Ա�������׵�ַ��Ԫ��Խ�硢�ڴ�Խ��
	iterator data, avail, limit;

	//��Ա�������ڴ����
	std::allocator<T> alloc;

	//˽�г�Ա���������ʵ��ϸ�ڣ�
	//�����ڴ�ͳ�ʼ������
	void create() { data = avail = limit = NULL; }
	void create(size_type n, const T& val)
	{
		data = alloc.allocate(n); //�������ҽ�������n��T���ͱ����Ŀռ䣨δ��ʼ���ģ��������׵�ַ
		limit = avail = data + n;
		std::uninitialized_fill(data, limit, val); //�ø�����ֵ���δ��ʼ����һ�θ����Ϳռ䣬û�з���ֵ
	}
	void create(const_iterator b, const_iterator e)
	{
		data = alloc.allocate(e - b);
		limit = avail = std::uninitialized_copy(b, e, data);
		//��������һ�����临����䵽�������׵�ַ�������һ�οռ䣬���غ�һ�οռ��Խ��ָ��
	}
	//��ȥ�����Ԫ�أ�Ȼ���ͷ��ڴ�
	void uncreate();
	//support functions for push_back
	void grow();
	void unchecked_append(const T& val)
	{
		alloc.construct(avail++, val); //�ڸ�����δ��ʼ���ռ��н���ֵΪval����Ӧ���ͱ���
	} //������Ƿ��п��ÿռ䣬ֱ�Ӱ�Ԫ����ӵ�ĩβ
};
//�ṹ���������Ҫ�ӷֺţ�����ṹ��ø���ʱ�������ǣ�

//ģ����Ķ����ʵ�־�������ͷ�ļ��������������������ʶ���ģ��������
template <class T>
Vec<T>& Vec<T>::operator= (const Vec& rhs)
{
	if (&rhs == this) return *this; //���Ҹ�ֵ�ж�
	uncreate(); //�������ֵ����
	create(rhs.begin(), rhs.end()); //���Ⱥ��ұ߶����ֵ���Ƹ��Ⱥ���߶���
	return *this; //���ر���ֵ�������������
}
//���������ռ䣬����ʡ��ģ�����Ͳ���T����ʽ�����������������ռ��⣬������ʽ˵��
//�˺��������б��У�����ǰ��ĺ������Ѿ����������޶������Բ�����Ҫ��<T>
template <class T>
void Vec<T>::uncreate()
{
	if (data) //����deallocate����Ҫ����������Ƿǿ�ָ�룬����Ҫ�ж�data�Ƿ�Ϊ��
	{
		iterator i = avail;
		while (i != data) alloc.destroy(--i); //��ȥ������ָ��ĸ����ͱ���������δ��ʼ���Ŀռ�
		//�����ԣ��˴�Ҳ���������ͷ��ڴ档ѡ��������Ϊ�˺������create��������ֱ�۵��෴Ч����
		alloc.deallocate(data, limit - data); //�ͷŸ�����һ�ε�ַָ��Ŀռ�
	}
	//����ָ�룬��ʾ����Vec�Ѿ��ǿյ���
	data = avail = limit = NULL;
}
template <class T>
void Vec<T>::grow()
{
	//Ϊ����߹���Ч�ʣ�����ռ�ʱ���������뵱ǰ��С2���Ŀռ䱸�ã�������ÿ�ζ�����պ���Ҫ�������Ŀռ�
	size_type new_size = std::max(2 * (limit - data), (ptrdiff_t)1);

	//�����µ�һ�οռ䣬�ѵ�ǰ���������ݸ��Ƶ��¿ռ�
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	//�ͷžɵĿռ�
	uncreate();

	//��ָ���Ϊָ��������Ŀռ�
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}
