#include <iostream>

using namespace std;

template<class T>
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};

template<class T>
class Print 
{
public:
	void operator() (T value)
	{
		cout << value << endl;
	}
};

template<class T>
class Negative : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};

template<class T>
void binoperate(T* begin, T* end, T* begin_2, T* end_2 ,T* Arr, Print<T>& p)
{
	for (T* from = begin; from < end; from++) 
	{ 
		*from=777;
		p(*from);
	}

	for (T* from = begin_2; from < end_2; from++) 
	{
		*from=228;
		p(*from);
	}
}

template<class T>
void binoperate_if(T* begin, T* end, T* begin_2, T* end_2, T* Arr, Negative<T>& predicate)
{
	

	for (T* from = begin; from < end; from++)
	{
		if (predicate(*begin))
		{
			*from = -76;
		}
	}
	for (T* from = begin_2; from < end_2; from++)
	{
		if (predicate(*begin_2))
		{
			*from = -26;
		}
	}
}

int main()
{
	int a[6] = { 2,3, 5, -1, -4, -5 }; 
	int b[6] = { -2,-3, -5, -1, -4, -5 };
	
	for (int i = 0; i < 6; i++)
		cout << a[i] << ' '; 
	cout << endl << "Modified array" << endl;

	cout << endl << "binoperate" << endl;
	
	Print<int> *print = new Print<int>();
	binoperate(&a[0], &a[3], &a[3], &a[6], &a[0],*print); 
	
	cout << endl << "binoperate_if" << endl;
	Negative<int> *pop = new Negative<int>();
	binoperate_if(&b[0], &b[3], &b[3], &b[6], &b[0], *pop);

	for (int l = 0; l < 6; l++)
		cout << b[l] << endl;
	
	system("pause");
	return 0;
}