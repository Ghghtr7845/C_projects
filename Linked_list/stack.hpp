#ifndef stack_h
#define stack_h

#include"Linkedlist.hpp" // the one with template 
namespace GT {

	template <typename T>
	class Stack {
	public: 
		LinkedList<T> items; 

		Stack() = default; 
		~Stack() {
			while (!items.isempty()) {
				items.getLast();
			}
		}
		Stack(const Stack& aCopy) { *this = aCopy; }
		Stack& operator = (const Stack& aCopy) { 
			items = aCopy.items;
			return *this; 
		}


		//insert new elements at top of stack
		Stack& push(const T& anItem) {
			
			items.append(anItem);
			return *this;
		}

		// will throw an out of range exception when it is empty
		// return the top most element, the last element remember LIFO
		T& peek() {
			// also return the most recent added node
			if (items.isempty()) {
				throw std::out_of_range("Empty stack!");
			}
			
			return items.getLast()->value;
		}
		//remove elements from top of stack, last node of linked list
		void pop() {
			
			if (items.isempty()) {
				throw std::out_of_range("Empty stack!");
			}

			items.removeLast();
			
		}

	};// end of class stack
  
} // end of namespace 

#endif /* stack_h */
