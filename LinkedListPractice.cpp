#include "LinkedListPractice.h"
Item *watch;
int main() {
	Header<Item> *h;
	Item *i1 = new Item();
	h = new Header<Item>(i1, i1, 1);
	h->first->header = h;
	for(int i = 0; i < 10; i++){
		h->appendItem();
	}
	h->print();
	h->printItems();
	h->insertItem(0);
	h->insertItem(h->size/2);
	h->insertItem(h->size - 1);
	h->insertItem(h->size);
	h->print();
	h->printItems();
	h->deleteItem(1);
	h->deleteItem(0);
	h->deleteItem(h->size - 1);
	h->print();
	h->printItems();
	cout << "\n\nMake a copy\n\n";
	Header<Item> *hcpy;
	hcpy = new Header<Item>(*h);
	h->print();
	hcpy->print();
	return 0;
}


Item::Item(Item *n, Item *p, Header<Item> *h, Data *d){
	next = n;
	prev = p;
	header = h;
	data = d;
}

template <class T>
Header<T>::Header(T * f, T * l, int s){
	first = f;
	last = l;
	size = s;
}
template <class T>
Header<T>::Header(const T& oldHeader){
	first = oldHeader.first;
	last = oldHeader.last;
	size = oldHeader.size;
}

template <class T>
void Header<T>::appendItem(){
	last->next = new T(NULL, last, last->header, new Data());
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
	cout << "Inserting node at position " << pos << endl;
	if(pos >= size){
		cout << "List not long enough, consider appendItem() instead.\n";
	}else{
		T * iptr = first;
		// Starting iptr at the first Item in the list move it right until it reaches
		// the requested Item infront of the position
		int i = 0;
		while(i < pos){
			iptr = iptr->next;
			i++;
		}
		// Add new Item andRe-order nexts and prevs
		// Make old Items next point to newly inserted Item and set new Items next and prev
		iptr->prev = new T(iptr, iptr->prev, iptr->header, new Data());
		if(pos == 0){
			first = iptr->prev;
		}
		iptr = iptr->prev;
		if(iptr->prev != NULL){
			iptr->prev->next = iptr;
		}
		iptr->header->size += 1;
	}
}

template <class T>
void Header<T>::deleteItem(int pos){
	cout << "Deleting node at position " << pos << endl;
	T *iptr = first;
	if(pos == 0){
		first = first->next;
		delete first->prev->data;
		delete first->prev;
	}else if(pos == size - 1){
		last = last->prev;
		delete last->next->data;
		delete last->next;
	}else{
		// Loop so iptr points to the node we want to remove
		int i = 0;
		while(i < pos){
			iptr = iptr->next;
			i++;
		}
		// Linking together nodes on either side of node to be deleted

		iptr->next->prev = iptr->prev;
		iptr->prev->next = iptr->next;
		delete iptr->data;
		delete iptr;
	}
	first->header->size -= 1;
}
