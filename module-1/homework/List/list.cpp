#include "list.h"
#include <iostream>
class List {
private:
	struct Element {
		int data;
		Element* prev;
		Element* next;
		
	};
		Element* first;
public:
	void swap(Element* a, Element* b) {
		if (a == nullptr) {
			a = b;
			b = nullptr;
		}
		else if (b == nullptr) {
			b = a;
			a = nullptr;
		}
		else if (a == nullptr && b == nullptr)
		{
			return;
		}
		else {
			Element* temp;
			temp = a->prev;
			a->prev = b->prev;
			b->prev = temp;
			temp = a->next;
			a->next = b->next;
			b->next = temp;
			int t = a->data;
			a->data = b->data;
			b->data = t;
		}
		}
	void swap(int& a, int& b) {
		int c = a;
		a = b;
		b = c;
	}
	List() {
		first = nullptr;
	}
	int& front() {
		//if (first == nullptr)return;
		return first->data;
	}
	int& back() {
		Element* e = first;
		//if (e == nullptr)return ;
		while (e->next != nullptr)
			e = e->next;
		return e->data;
	}
	bool empty() {
		return(first == nullptr);
	}
	int size() {
		int i = 1;
		Element* e = first;
		if (e == nullptr)return 0;
		while (e->next != nullptr)
		{
			e = e->next;
			i++;
		}
		return i;
	}
	void push_back(int data_) {
		Element* e = first;
		while (e->next != nullptr)
			e = e->next;
		Element* newone;
		e->next = newone;
		newone->prev = e;
		newone->data = data_;
	}
	void pop_back() {
		Element* e = first;
		if (e == nullptr)return;
		while (e->next != nullptr)
			e = e->next;
		e->prev->next = nullptr;
		delete e;
	}
	void push_front(int data) {
		if (first == nullptr) {
			first = new Element();
			first->prev = nullptr;
			first->next = nullptr;
			first->data = data;
		}
		else {
			Element* e = new Element();
			e->data = data;
			e->prev = nullptr;
			e->next = first;
			first->prev = e;
			first = e;
		}
	}
	void pop_front() {
		if (first == nullptr)return;
		first->next->prev = nullptr;
		delete first;
	}
	void resize(int new_size) {
		int i = 0;
		Element* e = first;
		Element*e1=nullptr;
		Element* temp;
		if (new_size == 0)first = nullptr;
		if (e == nullptr)return;
		while (e!= nullptr)
		{
			if (i == new_size)
			{
				if(e->prev!=nullptr)e->prev->next = nullptr;	
				temp = e;
				e = e->next;
				delete temp;
				i++;
				continue;
			}
			if (e->next == nullptr)e1 = e;
			e = e->next;
			i++;
		}
		for (int j = i; j < new_size; j++) {
			temp = new Element();
			temp->prev = e1;
			temp->next = nullptr;
			if(e1!=nullptr)e1->next = temp;
			e1 = temp;
		}
	}
	void Print() {
		if (first != nullptr) {
			Element* e = first;
			while (e) {
				std::cout << e->data << ' ';
				e = e->next;
			}
		}
	}
	void clear() {
		while (first) {
			Element* temp = first->next;
			delete first;
			first = temp;
		}
	}
	void swap(List &b) {
		List temp;
		temp.first = first;
		first = b.first;
		b.first = temp.first;
	}
	void remove(int data_) {
		Element* e = first;
		Element* temp;
		while (e != nullptr) {
			if (e->data == data_) {
				if (e->prev != nullptr) {
					e->prev->next = e->next;
				}
				if (e->next != nullptr) {
					e->next->prev = e->prev;
				}	
				temp = e;
				e = e->next;
				if (temp == first)
				{
					first = first->next;
				}
				delete temp;
			}
			else e = e->next;
		}
	}
	void sort() {
		Element* e = first;
		Element* temp;
		Element* temp1;
		int n=this->size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n-1; j++) {
				if (e->data > e->next->data)            
				{
					swap(e->data, e->next->data); 
				}
				e = e->next;
			}
			e = first;
		}
	}
	void unique() {
		Element* e = first->next;
		Element* temp = first->next;
		while (e != nullptr) {
			if (e->prev->data == e->data) {
				e->prev->next = e->next;
				if (e->next != nullptr)
				{
					e->next->prev = e->prev;
				}
				temp = e;
				e = e->next;
				delete temp;
			}
			else e = e->next;
		}
	}
};
int main()
{
	return 0;
}
