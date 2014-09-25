#ifndef _SSLL_H_
#define _SSLL_H_


/*
Skeleton created by Dave Small

Methods and Logic Written by Joshua Kegley
*/ 

#include <iostream>



template <typename T>
class SSLL {
private:
	struct Node {
		T data;
		Node *next;

	}; // end struct Node
	Node *head;
	Node *tail;
	int amount;


public:

	//--------------------------------------------------
	// Constructors/destructor/assignment operator
	//--------------------------------------------------

	SSLL() {
		amount = 0;
		tail = new Node();
		head = tail;
	}

	//--------------------------------------------------
	SSLL(const SSLL& src):this(src){}

	//--------------------------------------------------
	~SSLL() {
		// safely dispose of this SSLL's contents
		clear();
		delete head;
	}

	//--------------------------------------------------
	SSLL& operator=(const SSLL& src) {
		if (&src == this) // check for self-assignment
			return *this;     // do nothing

		// safely dispose of this SSLL's contents
		// populate this SSLL with copies of the other SSLL's contents
		clear();
		for (int i = 0; i < src.size(); i++){
			push_back(src.item_at(i));
		}
	}


	//Replaces orginal element with specified element, returns orginal
	T replace(const T& element, int position) {	

	}
	//#done

	//inserts elemenet, and shifts all elements after to the "left"
	void insert(const T& element, int position) {
		Node * next = head;
		Node * temp = new Node;
		temp->data = element;

		if (amount == 0){
			head->data = element;
		}
		else if (position == 0){
			temp->next = head;
			head = temp;
		}
		else if (position == amount){
			tail->next = temp;
			tail = temp;
		}
		else{
			for (int i = 0; i < position - 1; ++i){
				next = next->next;
			}
			temp->next = next->next;
			next->next = temp;
		}
		++amount;
	}


	void push_front(const T& element) {
		insert(element, 0);
	}


	void push_back(const T& element) {
		insert(element, tail)
	}


	T pop_front() {
		return remove(0);
	}


	T pop_back() {
		return remove(amount - 1);
	}



	//Removes an element from the list, from specified location
	T remove(int position) {
		Node * next = head;
		Node * prev = head;
		T data;
		if (position == 0){
			data = next->data;
			next = next->next;
			delete head;
			head = next;
		}
		else if(position == amount - 1){
			for (int i = 0; i < position - 1; ++i){
				next = next->next;
				std::cout << next->data;
			
			}
			data = next->next->data;
			delete tail;
			tail = next;

		}
		else{
			for (int i = 0; i < position - 1; ++i){
				next = next->next;
				std::cout << next->data;

			}
			data = next->next->data;
			Node * temp = next->next;
			next->next = temp->next;
			delete temp;
		}

		--amount;
		return data;
	}
	//#done

	//Looks at item at position
	T item_at(int position) const {
		Node * select = head;
		T data;
		for (int i = 0; i < position; i++){
			select = select->next;
		}
		data = select->data;
		return data;
	}
	//#done

	//Checks for emptiness
	bool is_empty() const {
		return (amount == 0 ? true : false);
	}
	//#done

	//checks for size
	int size() const { return amount; }
	//#done

	//clears list
	void clear() {
		Node * temp = head;
		for (int i = 0; i < amount; i++){
			tail = temp;
			temp = temp->next;
			delete tail;
		}
		head = new Node;
		tail = head;
		amount = 0;
	
	}
	//done

	bool contains(const T& element,
		bool equals(const T& a, const T& b)) const {

		Node* temp = head;
		for (int i = 0; i < amount; i++){
			if (temp->data == element){
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	std::ostream& print(std::ostream& out) const {
		Node * temp = head;
		if (this->is_empty()){
			out << "<empty list>";
		}
		else{
			out << "[";
			for (int i = 0; i < amount; i++){
				if (i == amount - 1){
					out << temp->data;

					
				}
				else{
				out << temp->data << ",";

				}
				temp = temp->next;
			}
			out << "]";
		}
		
		return out;
	
	}

}; 
 
#endif