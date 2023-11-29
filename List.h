#pragma once
#include <iostream>
using namespace std;

template<class T>
struct elem
{
	T info;
	elem<T>* next;
};

template<class T>
class List
{
protected:
	elem<T>* head, * prv, * cur;
	void deleteList()
	{
		while (head)
			removeFirst();
		cur = nullptr;
		prv = nullptr;
	}
	friend istream& operator>>(istream& in, List& a)
	{
		int n;
		in >> n;
		cout << "Enter " << n << " elements:" << endl;
		T x;
		for (int i = 0; i < n; i++)
		{
			in >> x;
			a.addElem(x);
		}
		return in;
	};
	friend ostream& operator<<(ostream& out, List& a)
	{
		if (a.isEmpty())
		{
			out << "List is empty!" << endl;
			return out;
		}
		a.toHead();
		out << "[" << a.cur->info;
		a.next();
		while (a.cur)
		{
			out << ", " << a.cur->info;
			a.next();
		}
		out << "]" << endl;
		a.toHead();
		return out;
	};
public:
	List<T>()
	{
		head = prv = cur = nullptr;
	};
	List<T>(List<T>& other)
	{
		if (other.isEmpty())
			return;
		other.toHead();
		while (other.cur)
		{
			addElem(other.cur->info);
			other.next();
		}
	};
	~List<T>()
	{
		deleteList();
	};
	void removeFirst()
	{
		if (isEmpty())
			return;

		elem<T>* t = head;
		head = head->next;
		delete t;
	};
	T value()
	{
		return cur->info;
	};
	void next()
	{
		if (cur)
		{
			if (!prv) {
				prv = cur;
				cur = cur->next;
				return;
			}
			prv = cur;
			cur = cur->next;
		}
	};
	bool isEnd()
	{
		if (!cur)
			cur = prv;
		return cur->next == nullptr;
	};
	void toHead()
	{
		cur = head;
		prv = nullptr;
	};
	void addElem(T info)
	{
		// 1. Создать новый элемент и заполнить его данными
		elem<T>* q = new elem<T>;
		q->info = info;
		q->next = nullptr; // последний элемент в списке
		// 2. Добавить элемент
		// Определить, первый ли элемент
		if (head == nullptr)
		{
			head = cur = q;
		}
		else
		{
			while (!isEnd())
				next();
			cur->next = q;
		}
	};
	bool isEmpty()
	{
		return head == nullptr;
	};
	bool operator==(List& list2)
	{
		toHead();
		list2.toHead();
		if (!isEmpty() && !list2.isEmpty())
		{
			while ((cur && list2.cur) && (cur->info == list2.cur->info))
			{
				next();
				list2.next();
			}
			if ((cur && !list2.cur) || (!cur && list2.cur))
				return false;
			return true;
		}
		else
			return false;
	}
	bool operator!=(List& list2)
	{
		return !((*this) == list2);
	}
	List& operator=(List& source)
	{
		if (this == &source)
			return *this;
		if (!isEmpty())
			deleteList();
		source.toHead();
		while (source.cur)
		{
			addElem(source.cur->info);
			source.next();
		}
		return *this;
	}
	void removeCur()
	{
		elem<T>* q = cur;
		cur = cur->next;
		if (prv) {
			prv->next = cur;
			delete q;
		}
		else {
			elem<T>* q = head->next;
			delete head;
			head = q;
		}
	}
	void addAfterCur(T info)
	{
		elem<T>* q = new elem<T>;
		q->info = info;
		q->next = cur->next;
		cur->next = q;
	}
	void addBeforeCur(T info)
	{
		elem<T>* q = new elem<T>;
		q->info = info;
		if (prv) {
			q->next = prv->next;
			prv->next = q;
		}
		else {
			q->next = head;
			head = q;
		}
	}
	bool contains(T x)
	{
		toHead();
		while (cur)
		{
			if (cur->info == x)
				return true;
			next();
		}
		return false;
	}
};
