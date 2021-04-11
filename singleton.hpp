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
		cout << "Singleton_����" << endl;
	}
	
public:

	static Singleton* CreateObject() {
		if (m_pObject == nullptr) {
			m_pObject = new Singleton();//ָ�벻Ϊ�գ��򴴽��������
		}
		return new Singleton();
	}

	~Singleton() {
		cout << "Singleton_����" << endl;
	}
};
Singleton* Singleton::m_pObject = nullptr;

void singleton() {
	Singleton* pObj = Singleton::CreateObject();
}