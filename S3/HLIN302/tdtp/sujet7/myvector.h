#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>

template<typename T>
class MyVector{
private:
	T* _donnees;
	size_t _n;
	size_t _alloc;

	void extend();
public:
	//Constructeur
	MyVector();
	MyVector(size_t n);
	MyVector(const MyVector&);
	~MyVector();
	//Méthodes
	T& at(size_t i);
	const T& at(size_t i)const;

	const T& operator[](const size_t &n) const;
	T& operator[](const size_t &n);

	void push_back(const T&);
	void erase(int);
	const size_t size() const;
	int find(const T&) const;
};
// ===============================
// = Constructeur & Destructeurs =
// ===============================
template<typename T>
MyVector<T>::MyVector(): _donnees(new T[1]), _n(0), _alloc(1){}
template<typename T>
MyVector<T>::MyVector(size_t n): _donnees(new T[n]), _n(n), _alloc(n){}
template<typename T>
MyVector<T>::MyVector(const MyVector& A): _donnees(new T[A._n]), _n(A._n), _alloc(_n){
  for(size_t i=0;i<_n;i++){
    _donnees[i]=A._donnees[i];
  }
}
template<typename T>
MyVector<T>::~MyVector(){
	delete[] _donnees;
}
// ===========
// = at & [] =
// ===========
template<typename T>
T& MyVector<T>::at(size_t i){ return _donnees[i]; }

template<typename T>
T& MyVector<T>::operator[](const size_t &i){ return _donnees[i]; }

template<typename T>
const T& MyVector<T>::at(size_t i)const{ return _donnees[i]; }

template<typename T>
const T& MyVector<T>::operator[](const size_t &i) const{return _donnees[i]; }
// ============
// = Méthodes =
// ============
template<typename T>
const size_t MyVector<T>::size() const{ return _n; }

template<typename T>
void MyVector<T>::extend(){
	if( !( _n < _alloc ) ){
		_alloc = 2 * _alloc;
		T* temp = new T[_alloc];
		for (size_t i = 0; i < _n; i++) {
			temp[i] = _donnees[i];
		}
		delete[] _donnees;
		_donnees = temp;
	}
}
template<typename T>
void MyVector<T>::push_back(const T& Val){
	extend();
	_donnees[_n] = Val;
	_n++;
}
template<typename T>
void MyVector<T>::erase(int index){
	if (index >= 0 && index < (int)_n ){
		for(size_t i = index ; i < _n - 1 ;i++)
			_donnees[i]=_donnees[i+1];
		_n--;
	}  
}

template<typename T>
int MyVector<T>::find(const T& Val) const{
	for (size_t i = 0 ; i < _n ;i++){
		if (Val == _donnees[i]){
			return i;
		}
	}
	return -1;
}
#endif