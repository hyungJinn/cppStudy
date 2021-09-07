// I refer to this site, https://reakwon.tistory.com/29.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct NODE {
	int data;
	struct NODE* next;
};

struct STACK {
	NODE* top;
	int len;
	STACK() {
		top = NULL;
		len = 0;
	}

	int size() {
		return len;
	}

	int isEmpty() {
		if (top == NULL) {
			return 1;
		}
		return 0;
	}

	void push(int data) {
		NODE* newNode = (NODE*)malloc(sizeof(NODE));
		newNode->data = data;
		newNode->next = top;

		top = newNode;
		len++;
	}

	int pop() {
		int ret = -1;
		if (!isEmpty()) {
			NODE* temp = top;
			ret = temp->data;
			top = temp->next;
			free(temp);
			len--;
			return ret;
		}
		return ret;
	}

	int peek() {
		int ret = -1;
		if (!isEmpty()) {
			NODE* cur = top;
			ret = cur->data;
			return ret;
		}
		return ret;
	}
};

int main()
{
	STACK st;

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		char str[10];
		scanf("%s", &str);
		if (strcmp(str, "push") == 0) {
			int x; scanf("%d", &x);
			st.push(x);
		}
		else if (strcmp(str, "top") == 0) {
			printf("%d\n", st.peek());
		}
		else if (strcmp(str, "pop") == 0) {
			printf("%d\n", st.pop());
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", st.size());
		}
		else if (strcmp(str, "empty") == 0) {
			printf("%d\n", st.isEmpty());
		}
	}
	return 0;
}