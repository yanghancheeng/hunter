#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
* �������ܲ����У���Meyersʵ�ֵ���������ģʽ��
* ���Զ��̰߳�ȫ�����׶��������󱣴��ھ�̬�����������е㲻ϰ��
* meyers singlton
* class MySingleton{
* public:
*	static MySingleton& getInstance(){
*		static MySington instance;
*		return instance;
*	}
* private:
*	MySingleton() = default;
*	~MySingleton() = default;
*	MySingleton(const MySingleton&) = delete;
*	MySingleton operator=(const MySingleton&) = delete;
* };
*/



class Singleton {
private:
	static Singleton* m_pObject;

	Singleton() {
		cout << "Singleton_����" << endl;
	}
	
public:
	//Singleton(Singleton& s) = delete;
	Singleton* operator=(Singleton& s) = delete;
	static Singleton& CreateObject() {
		static Singleton obj;
		return obj;
	}

	~Singleton() {
		cout << "Singleton_����" << endl;
	}
};
//Singleton* Singleton::m_pObject = nullptr;

void singleton() {
	Singleton& pObj1 = Singleton::CreateObject();
	Singleton& pObj2 = Singleton::CreateObject();
	Singleton s = Singleton::CreateObject();
}