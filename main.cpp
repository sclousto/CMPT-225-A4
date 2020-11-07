#include <iostream>
#include <queue>

using namespace std;

int main (void) {

int L1[9] = {0, 1, 2, 3, 4, 5, 6, 7, 9};
int L2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

priority_queue <int> q1;
priority_queue <int> q2;

for(int i= 0; i<9; i++) {
  q1.push(L1[i]);
}
for(int i= 0; i<10; i++) {
  q2.push(L2[i]);
}

int max1 = q1.top();
int max2 = q2.top();

while(true) {
  if(max1 == max2) {
    q1.pop();
    if(q1.empty()) {
      max1 = -1;
      break;
    }
    max1 = q1.top();
  }
  q2.pop();
  if(q2.empty() || max2 < max1) {
    break;
  }
  max2 = q2.top(); 
}

if(max1 == -1) {
  cout << "NONE";
}
else{
  cout << max1;
}
cout << "\n";

}
