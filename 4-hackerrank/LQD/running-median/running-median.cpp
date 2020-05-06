#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int oo = 1e9 + 7;

int query;
priority_queue < double > MaxHeap;
priority_queue < double, vector < double >, greater < double > > MinHeap;

void Setup() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("running-median.inp", "r", stdin);
	freopen ("running-median.out", "w", stdout);
}

void Show(priority_queue < double > MaxHeap, priority_queue < double, vector < double >, greater < double > > MinHeap) {
	cout << "MaxHeap: ";
	while (MaxHeap.size() != 0) {
		cout << MaxHeap.top() << " ";
		MaxHeap.pop();
	}
	cout << endl;
	cout << "MinHeap: ";
	while (MinHeap.size() != 0) {
		cout << MinHeap.top() << " ";
		MinHeap.pop();
	}
	cout << endl;
	return;
}

void Push(double X, priority_queue < double > &MaxHeap, priority_queue < double, vector < double >, greater < double > > &MinHeap) {
	double x = X;
	if (MaxHeap.size() == 0 || MinHeap.size() == 0) {
		int n = MaxHeap.size();
		int m = MinHeap.size();
		if (n == 0 && m == 0) {
			MaxHeap.push(x);
			return;
		} else if (n == 0 && m != 0) {
			int Right = MinHeap.top();
			if (x < Right) {
				MaxHeap.push(x);
				return;
			} else {
				MinHeap.push(x);
				return;
			}
		} else if (n != 0 && m == 0) {
			int Left = MaxHeap.top();
			if (Left <= x) {
				MinHeap.push(x);
				return;
			} else {
				MaxHeap.push(x);
				return;
			}
		}
	}
	double Left = MaxHeap.top();
	double Right = MinHeap.top();
	if (Left <= x && x <= Right) {
		MaxHeap.push(x);
	} else if (Left < x && Right <= x) {
		MinHeap.push(x);
	} else if (x <= Left && x < Right) {
		MaxHeap.push(x);
	}
	return;
}

void Balance(priority_queue < double > &MaxHeap, priority_queue < double, vector < double >, greater < double > > &MinHeap) {
	double n = MaxHeap.size();
	double m = MinHeap.size();
	if (0 <= abs(n - m) && abs(n - m) <= 1) {
		return;
	} else {
		if (n > m) {
			double tmp = MaxHeap.top();
			MaxHeap.pop();
			MinHeap.push(tmp);
		} else {
			double tmp = MinHeap.top();
			MinHeap.pop();
			MaxHeap.push(tmp);
		}
	}
	return;
}

double GetAnswer(priority_queue < double > &MaxHeap, priority_queue < double, vector < double >, greater < double > > &MinHeap) {
	int n = MaxHeap.size();
	int m = MinHeap.size();
	if ((n + m) % 2 == 0) {
		double a = MaxHeap.top();
		int b = MinHeap.top();
		return ((a + b) / 2);
	} else {
		if (n < m) {
			return (MinHeap.top());
		} else {
			return (MaxHeap.top());
		}
	}
}

int main() {
	Setup();
	cin >> query;
	for (int qq = 1; qq <= query; qq++) {
		double x;
		cin >> x;
		Push(x, MaxHeap, MinHeap);
		Balance(MaxHeap, MinHeap);
		//Show(MaxHeap, MinHeap);
		cout << fixed << setprecision(1) << GetAnswer(MaxHeap, MinHeap) << endl;
	}
}
