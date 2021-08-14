//I referred to this site, https://velog.io/@daeho-park/C-연결-리스트로-구현한-덱Deque.

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

class Node
{
public:
	Node(const int data, Node* prev = nullptr, Node* next = nullptr);

	int getData() const;
	Node* getPrev() const;
	Node* getNext() const;
	void setData(const int data);
	void setPrev(Node* node);
	void setNext(Node* node);
	
private:
	int data;
	Node* prev;
	Node* next;
};

Node::Node(const int data, Node* prev, Node* next) {
	this->data = data;
	this->prev = prev;
	this->next = next;
}

int Node::getData() const {
	return data;
}

Node* Node::getPrev() const {
	return prev;
}

Node* Node::getNext() const {
	return next;
}

void Node::setData(const int data) {
	this->data = data;
}

void Node::setPrev(Node* node) {
	this->prev = node;
}
void Node::setNext(Node* node) {
	this->next = node;
}

class Deque
{
public:
	Deque();
	~Deque();

	bool empty() const;
	int size() const;
	int front() const;
	int back() const;
	void pushFront(const int data);
	void pushBack(const int data);
	int popFront();
	int popBack();

private:
	Node* headNode;
	Node* tailNode;
	int dataSize;
};

Deque::Deque() {
	headNode = nullptr;
	tailNode = nullptr;
	dataSize = 0;
}

inline void error(const char* message) {
	puts(message);
	exit(EXIT_FAILURE);
}

Deque::~Deque() {
	while (!empty()) {
		popFront();
	}
}

bool Deque::empty() const {
	return dataSize == 0;
}

int Deque::size() const {
	return dataSize;
}

int Deque::front() const {
	if (empty()) {
		error("Deque is empty!");
	}
	return headNode->getData();
}

int Deque::back() const {
	if (empty()) {
		error("Deque is empty!");
	}
	return tailNode->getData();
}

void Deque::pushFront(const int data) {
	if (empty()) {
		headNode = tailNode = new Node(data);
		dataSize++;
		return;
	}
	Node* node = new Node(data, nullptr, headNode);
	headNode->setPrev(node);
	headNode = node;
	dataSize++;
}

void Deque::pushBack(const int data) {
	if (empty()) {
		tailNode = headNode = new Node(data);
		dataSize++;
		return;
	}
	Node* node = new Node(data, tailNode, nullptr);
	tailNode->setNext(node);
	tailNode = node;
	dataSize++;
}

int Deque::popFront() {
	int frontData = front();
	Node* node = headNode;
	headNode = headNode->getNext();
	if (headNode != nullptr) {
		headNode->setPrev(nullptr);
	}
	delete node;
	dataSize--;
	return frontData;
}

int Deque::popBack() {
	int backData = back();
	Node* node = tailNode;
	tailNode = tailNode->getPrev();
	if (tailNode != nullptr) {
		tailNode->setNext(nullptr);
	}
	delete node;
	dataSize--;
	return backData;
}

int N;

void input() {
	cin >> N;
}

void solution() {
	Deque deque;

	for (int i = 0; i < N; i++) {
		string text;
		cin >> text;
		if (text == "push_front") {
			int x;
			cin >> x;
			deque.pushFront(x);
		}
		else if (text == "push_back") {
			int x;
			cin >> x;
			deque.pushBack(x);
		}
		else if (text == "pop_front") {
			if (!deque.empty()) {
				cout << deque.front() << endl;
				deque.popFront();
			}
			else cout << "-1\n";
		}
		else if (text == "pop_back") {
			if (!deque.empty()) {
				cout << deque.back() << endl;
				deque.popBack();
			}
			else cout << "-1\n";
		}
		else if (text == "size") {
			cout << deque.size() << endl;
		}
		else if (text == "empty") {
			if (!deque.empty()) cout << "0\n";
			else cout << deque.empty() << endl;
		}
		else if (text == "front") {
			if (!deque.empty()) {
				cout << deque.front() << endl;
			}
			else
				cout << "-1\n";
		}
		else if (text == "back") {
			if (!deque.empty()) {
				cout << deque.back() << endl;
			}
			else
				cout << "-1\n";
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	solution();

	return 0;
}