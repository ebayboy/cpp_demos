
/* template class */

#include <iostream>
#include <vector>

using namespace std;


template <class T>
class Stack {
	private:
		vector <T> elems;

	public:
		void push(T const & e) {
			this->elems.push_back(e);
		}

		void pop() {
			if (elems.empty()) {
				throw out_of_range("Stack<>::top empty stack!");
			} 

			this->elems.pop_back();
		}

		T const top() {
			if (this->elems.empty()) {
				throw out_of_range("Stack<>::top empty stack!");
			}

			return this->elems.back();
		}

		bool empty() {
			return elems.empty();
		}
};


int main()
{
	try {
		/* int template */
		Stack <int> s;

		s.push(12);
		s.push(13);

		cout << "top:" << s.top() <<endl;
		s.pop();
		cout << "top:" << s.top() <<endl;
		s.pop();
		cout << "top:" << s.top() <<endl;

		/* string template */
		Stack <string> s1;
		s1.push("hello");
		s1.push("world");

		cout << "top:" << s1.top() <<endl;
		s1.pop();
		cout << "top:" << s1.top() <<endl;
	} catch(exception const &ex) {
		cerr << "Exception:" << ex.what() << endl;
		return -1;
	}

	return 0;
}
