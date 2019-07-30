template <typename T>
struct Node {
	T info;
	Node *next;
};

template <typename T> class lista {
private:
	Node<T> *head;
public:
	lista() {
		head = nullptr;
	}

	void push_back(T val) {
		Node<T> *n = new Node<T>();
		n->info = val;
		n->next = head;
		head = n;
	}

	T pop() {
		if (head) {
			T p = head->info;
			head = head->next;
			return p;
		}
	}

	bool search(T val) {
		Node<T> *temp = head;
		while (temp->next) {
			if (temp->info == val) return true;
			else temp = temp->next;
		}
		delete temp;
		return false;
	}

	T &operator [](int i) const {
		Node<T>*temp = head;
		int contor = 0;
		while (contor != i) {
			temp = temp->next;
			contor++;
		}
		return temp->info;
	}

	size_t size() {
		Node<T>*temp = head;
		int contor = 0;
		while (temp != nullptr) {
			temp = temp->next;
			contor++;
		}
		return contor;
	}

};
