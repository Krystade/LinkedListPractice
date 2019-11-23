#include "LinkedLists2.h"

int main() {
	Header<Item> *h;
	Item *i1 = new Item();
	h = new Header<Item>(i1, i1, 1);
	h->first->header = h;
	h->print();
	h->appendItem();
	h->appendItem();
	h->appendItem();
	h->print();
	h->printItems();
	h->insertItem(2);
	h->print();
	h->printItems();

	return 0;
}

template <class T>
Header<T>::Header(T * f, T * l, int s){
	first = f;
	last = l;
	size = s;
}
Item::Item(Item *n, Item *p, Header<Item> *h){
	next = n;
	prev = p;
	header = h;
}

template <class T>
void Header<T>::appendItem(){
	last->next = new T(NULL, last, last->header);
	last->header->last = last->next;
	last->header->size += 1;
}

template <class T>
void Header<T>::printItems(){
	T *iptr = first;
	for(int i = 0; i < size; i++){
		cout << "\tItem " << i << endl;
		iptr->print();
		iptr = iptr->next;
	}
}

template <class T>
void Header<T>::insertItem(int pos){
	if(pos >= size){
		cout << "List not long enough, consider appendItem() instead.\n";
	}else{
		T * iptr = first;
		// Starting iptr at the first Item in the list move it right until it reaches
		// the requested Item infront of the position
		for(int i = 0; i < pos; i++){
			iptr = iptr->next;
		}
		// Add new Item andRe-order nexts and prevs
		// Make old Items next point to newly inserted Item and set new Items next and prev
		iptr->next = new T(iptr->next, iptr, iptr->header);
		iptr = iptr->next;
		iptr->next->prev = iptr;
		iptr->header->size += 1;
	}
}
