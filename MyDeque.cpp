#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int maxN = 150000;

struct elem {
  elem* next;
  elem* prev;
  int v_;
  elem(int v = 0) : prev(0), next(0), v_(v)
  {}
};

struct myDeque
{
  elem* head;
  elem* tail;
  myDeque() : head(0), tail(0)
  {}
  void push_front(int v) {
    if (head == 0 || tail == 0) {
      head = tail = new elem(v);
    } else {
        elem * t = new elem(v);
        t->next = head;
        head->prev = t;
        head = t;
      }
  }	
  
  void push_back(int v) {
    if (head == 0 || tail == 0) {
      head = tail = new elem(v);
    } else {
        elem * t = new elem(v);
  	tail->next = t;
  	t->prev = tail;
  	tail = t;
      }
  }
  
  int pop_front() {
    int ans = head->v_;
    if (head == tail) {		
      head = tail = 0;
    } else {
        head = head->next;	
        delete head->prev;
	head->prev = 0;
      }
    return ans;
  }

  int pop_back() {
    int ans = tail->v_;
    if (head == tail) {
      head = tail = 0;
    } else {
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
      }
    return ans;
  }
} dq[maxN];

char s[200];
int zq;

int main() 
{
  freopen("deques.in", "r", stdin);
  freopen("deques.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int tn;
    cin >> s >> tn;
    tn--;
    if (s[2] == 's') {
      int v;
      cin >> v;
      if (s[4] != 'b') {
	dq[tn].push_front(v);
      }
      if (s[4] == 'b') {
	dq[tn].push_back(v);
      }
    } else {
	if (s[3] == 'f') {
	  cout << dq[tn].pop_front() << endl;
	} 
	if (s[3] != 'f') {
	  cout << dq[tn].pop_back() << endl;
	}
      }
  }
  return 0;
}