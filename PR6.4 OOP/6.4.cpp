
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

template <class T>

class Matrix
{
	T* m;
	int size;
public:
	Matrix(int newsize);
	Matrix(Matrix&);
	~Matrix();

	T findmaxel();
	
	T& operator [] (int index);
	Matrix& operator = (const Matrix &);

	friend ostream& operator << <>(ostream&, Matrix&);
	friend istream& operator >> <>(istream&, Matrix&);
	
	int find(T key);
	int count(T key);
	
};

template <class T>
Matrix <T>::Matrix(int newsize)
{
	m = new T[size = newsize]; 
	for (int i = 0; i < size; i++) 
		m[i] = T();

}

template <class T>
Matrix<T>::~Matrix()
{
	delete[] m;
}

template <class T>
T Matrix<T>::findmaxel()
{
	T max = m[0];
	for (int i = 0; i < size; i++)
		if (m[i] > max)
			max = m[i];
	return max;
}

template <class T>
T& Matrix<T>::operator [] (int index)
{
	return m[index];
}

template <class T>
Matrix<T>& Matrix<T>::operator = (const Matrix &m1)
{
	if (this != &m1)
	{
		delete[] m;
		m = new T[size = m1.size];
		for (int i = 0; i < size; i++)
			m[i] = m1.m[i];
	}
	return *this;
}

template <class T>
ostream& operator << (ostream& os, Matrix <T>& m1)
{
	for (int i = 0; i < m1.size; i++)
		os << m1.m[i] << " ";
	return os;
}


template <class T>
istream & operator >> (istream& is, Matrix<T>& m1)
{
	cout << "Enter the size of the matrix "; cout << endl;
	cin >> m1.size;
 for (int i = 0; i < m1.size; i++)
		is >> m1.m[i];
return is;
}

template <class T>
Matrix<T> ::Matrix (Matrix<T> &m1)
{
	m = new T[size = m1.size];
	for (int i = 0; i < size; i++)
		m[i] = m1.m[i];
}

template <class T>
int Matrix<T>::find(T key)
{
	for (int i = 0; i < size; i++)
		if (m[i] == key)
			return i;
	return 0;
}

template <class T>
int Matrix<T>::count(T key)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (m[i] == key)
			count++;
	return count;
}

int main()
{

	Matrix<int> m1(5);
	cin >> m1;
	cout << "The matrix is "<< m1 << endl;
	cout << "The maxe elementd is " << m1.findmaxel() << endl;
	cout << "The index of the element is " << m1.find(5) << endl;
	cout << "The count of the element is " << m1.count(5) << endl;

}
