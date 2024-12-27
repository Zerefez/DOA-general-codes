

#include <iostream>	
#include <queue>
#include <stack>
using namespace std;

bool trySort(queue<int>& q, queue<int>& result) {
	stack<int> s;
	int expected = 1;
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		cout << "Processing element: " << current << endl;

		// Hvis det nuværende element er det forventede, kan vi direkte putte det i result.
		if (current == expected) {
			result.push(current);
			cout << "Moved to result queue: " << current << endl;
			expected++;
		}
		else {
			// Hvis stacken ikke er tom og det øverste element i stacken er det forventede, flyt det til result.
			while (!s.empty() && s.top() == expected) {
				result.push(s.top());
				cout << "Moved from stack to result queue: " << s.top() << endl;
				s.pop();
				expected++;
			}

			// Hvis det nuværende element ikke kan behandles endnu, put det i stacken.
			if (!s.empty() && s.top() < current) {
				// Hvis elementet i stacken er mindre end det nuværende, kan vi ikke sortere.
				cout << "Cannot sort: stack top " << s.top() << " is smaller than current " << current << endl;
				return false;
			}
			s.push(current);
			cout << "Pushed to stack: " << current << endl;
		}
	}

	// Tøm resten af stacken til result.
	while (!s.empty()) {
		if (s.top() != expected) {
			cout << "Cannot sort: expected " << expected << ", but stack top is " << s.top() << endl;
			return false;
		}
		result.push(s.top());
		cout << "Moved from stack to result queue: " << s.top() << endl;
		s.pop();				
		expected++;
	}

	return true;
}

int main() {

	queue<int> q;
	queue<int> result;


	// Eksempel 1
	q.push(5);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	
	if (trySort(q, result)) {
		cout << "Output: True\nResult Queue: ";
		while (!result.empty()) {
			cout << result.front() << " ";
			result.pop();
		}
		cout << endl;
	}
	else {
		cout << "Output: False" << endl;
	}

	// Eksempel 2
	while (!q.empty()) q.pop(); 
	while (!result.empty()) result.pop();

	q.push(5);
	q.push(1);
	q.push(2);
	q.push(6);
	q.push(3);
	q.push(4);

	if (trySort(q, result)) {
		cout << "Output: True\nResult Queue: ";
		while (!result.empty()) {
			cout << result.front() << " ";
			result.pop();
		}
		cout << endl;
	}
	else {
		cout << "Output: False" << endl;
	}

	return 0;
}