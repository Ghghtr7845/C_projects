#ifndef queue_h
#define queue_h

namespace GT {

	template <typename T> 
	class Queue {
	public : 
		LinkedList <T> items; 

		Queue() = default; 
		~Queue() {
			while (!items.isempty()) {
				items.removeFirst();
			}
		}
		Queue(const Queue& aCopy) { *this = aCopy; }
		Queue& operator =  (const Queue& aCopy) { return *this; }

		// insert new element to end of queue 
		Queue& push(const T& aValue) { 
			items.append(aValue);
			return *this;
		}
		//reference the first or the oldest element of the queue container
		T& front() {
			if (items.isempty()) {
				throw std::out_of_range("Empty queue!");
			}
			return items.first()->value;
		}

		//reference the last or the newest element of the queue container
		T& back() {
			if (items.isempty()) {
				throw std::out_of_range("Empty queue!");
			}
			return items.getLast()->value;
		}

		//The element removed is the "oldest" element in the queue
		void pop() { 
			if (items.isempty()) {
				throw std::out_of_range("Empty queue!");
			}
			return items.removeFirst();
		}
	};

} // end of namespace 

#endif /* queue_h */
