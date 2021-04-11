#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
* 若对性能不敏感，则Meyers实现单例（懒汉模式）
* 其自动线程安全，简单易懂。但对象保存在静态数据区，会有点不习惯
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
		cout << "Singleton_构造" << endl;
	}
	
public:
	//Singleton(Singleton& s) = delete;
	Singleton* operator=(Singleton& s) = delete;
	static Singleton& CreateObject() {
		static Singleton obj;
		return obj;
	}

	~Singleton() {
		cout << "Singleton_析构" << endl;
	}
};
//Singleton* Singleton::m_pObject = nullptr;

void singleton() {
	Singleton& pObj1 = Singleton::CreateObject();
	Singleton& pObj2 = Singleton::CreateObject();
	Singleton s = Singleton::CreateObject();
}