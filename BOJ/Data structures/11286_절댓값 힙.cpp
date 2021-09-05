//I referred to this site, https://yabmoons.tistory.com/374.

#include <iostream>
#include <cmath>

#define endl '\n'
#define MAX 100010

using namespace std;

int N, Heap_Idx;
int Heap_Array[MAX];

bool Compare(int A, int B) {
  int dA = abs(A);
  int dB = abs(B);
  if(dA <= dB) {
    if(dA == dB) {
      if(A < B) {
        return true;
      }
      return false;
    }
    return true;
  }
  return false;
}

void Swap(int &A, int &B) { int temp = A; A = B; B = temp;}

void Heap_push(int data) {
  int Idx = ++Heap_Idx;
  Heap_Array[Idx] = data;

  while((Idx != 1) && Compare(data, Heap_Array[Idx / 2]) == true) {
    Swap(Heap_Array[Idx], Heap_Array[Idx / 2]);
    Idx = Idx / 2;
  }
}

int Heap_pop() {
  if(Heap_Idx == 0) return 0;
  int result = Heap_Array[1];
  Heap_Array[1] = Heap_Array[Heap_Idx--];

  int parent = 1;
  int child;
  while(1) {
    child = parent * 2;
    if(child + 1 <= Heap_Idx && Compare(Heap_Array[child+1], Heap_Array[child]) == true) child++;
    if(child > Heap_Idx || Compare(Heap_Array[parent], Heap_Array[child]) == true) break;
    Swap(Heap_Array[parent], Heap_Array[child]);
    parent = child;
  }
  return result;
}

void Solution() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    int a; cin >> a;
    if(a==0) cout << Heap_pop() << endl;
    else Heap_push(a);
  }
}

void Solve() {
  Solution();
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  Solve();

  return 0;
}
