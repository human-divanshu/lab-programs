template <class T>
class Vector {
	T *arr;
	int vectorSize;
	int maxSize;
	public:
		Vector() {
			maxSize = 2;
			vectorSize = 0;
			arr = new T(maxSize);
		}
		
		void push(T val) {
			if(vectorSize == maxSize) {
				int newSize = maxSize * 2;
				T *newarr = new T(newSize);
				for(int i = 0; i < vectorSize; i++)
					newarr[i] = arr[i];
				delete[] arr;
				arr = newarr;
				maxSize = newSize;
			}
			arr[vectorSize++] = val;
		}

		T pop() {
			T val;
			val = arr[vectorSize - 1];
			vectorSize--;
			return val;
		}		

		T back() {
			return arr[vectorSize - 1];
		}

		T front() {
			return arr[0];
		}
		
		
		T at(int i) {
			return arr[i];
		}
		
		int size() {
			return vectorSize;
		}

		// insert in the front
		void shift(T val) {
			if(this->size() != 0) {
				T temp = this->back();
				this->push(temp);
				for(int i = this->size() - 1; i > 0; i--) {
					arr[i] = arr[i - 1];
				}
			} else {
				vectorSize++;
			}
			arr[0] = val;
		}

		T unshift() {
			T val = arr[0];
			if(this->size() >= 2) {
				for(int i = 0; i < this->size() - 1; i++) {
					arr[i] = arr[i + 1];
				}
			}
			vectorSize--;
			return val;
		}

		// quick sort
		void sort() {

		}
};
