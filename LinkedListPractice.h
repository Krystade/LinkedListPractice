#ifndef LINKEDLISTS2_H_
#define LINKEDLISTS2_H_


#include <iostream>
using namespace std;

class Item;
class Data;

template <class T> class Header{
public:
	T * first;
	T * last;
	int size;
	Header(){first = NULL, last = NULL, size = 0;};
	Header(T * f, T * l, int s);
	Header(const T& oldHeader){first = oldHeader.first, last = oldHeader.last, size = oldHeader.size;};
	~Header(){cout << "Deleting Header object\n";};
	void print(){cout << "\tHeader" << "\naddress: " << this << "\nfirst: " << first << "\nlast: " << last << "\nsize: " << size << endl << endl;}
	void appendItem();
	void insertItem(int pos);
	void printItems();
	void deleteItem(int pos);
};

class Item{
public:
	Item * next;
	Item * prev;
	Header<Item> * header;
	Data *data;
	Item(){next = NULL, prev = NULL, header = NULL, data = NULL;};
	Item(Item *n, Item *p, Header<Item> *h, Data *data);
	~Item(){cout << "Deleting Item object\n";};
	void print(){cout << "\tItem" << "\naddress: " << this << "\nprev: " << prev << "\nnext: " << next << "\nheader: " << header << endl << endl;}
};

class Data{
public:
	int x;
	int y;
	int z;
	Data(){x = 0, y = 0, z = 0;};
	Data(int x, int y, int z);
	~Data(){cout << "Deleting Data object\n";};
};

#endif /* LINKEDLISTS2_H_ */
