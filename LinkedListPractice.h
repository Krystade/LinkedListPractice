#ifndef LINKEDLISTS2_H_
#define LINKEDLISTS2_H_


#include <iostream>
using namespace std;

class Item;

template <class T> class Header{
public:
	T * first;
	T * last;
	int size;
	Header(){first = NULL, last = NULL, size = 0;};
	Header(T * f, T * l, int s);
	Header(const T& oldHeader){first = oldHeader.first, last = oldHeader.last, size = oldHeader.size;};
	~Header(){};
	void print(){cout << "\tHeader" << "\naddress: " << this << "\nfirst: " << first << "\nlast: " << last << "\nsize: " << size << endl << endl;}
	void appendItem();
	void insertItem(int pos);
	void printItems();
};

class Item{
public:
	Item * next;
	Item * prev;
	Header<Item> * header;
	Item(){next = NULL, prev = NULL, header = NULL;};
	Item(Item *n, Item *p, Header<Item> *h);
	~Item(){};
	void print(){cout << "\tItem" << "\naddress: " << this << "\nprev: " << prev << "\nnext: " << next << "\nheader: " << header << endl << endl;}
};

#endif /* LINKEDLISTS2_H_ */
