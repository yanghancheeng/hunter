#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Singleton {
private:
	static Singleton* m_pObject;

	Singleton() {
		cout << "Singleton_构造" << endl;
	}
	
public:

	static Singleton* CreateObject() {
		if (m_pObject == nullptr) {
			m_pObject = new Singleton();//指针不为空，则创建这个对象
		}
		return new Singleton();
	}

	~Singleton() {
		cout << "Singleton_析构" << endl;
	}
};
Singleton* Singleton::m_pObject = nullptr;

void singleton() {
	Singleton* pObj = Singleton::CreateObject();
}