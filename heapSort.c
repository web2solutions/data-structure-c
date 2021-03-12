#include <stdio.h>

// #define troca (A, B) {int t = A; A = B; B = t;}

void 
troca (int A, int B) {
  int t = A; A = B; B = t;
}

static void 
constroiHeap (int m, int arr[])
{
   for (int k = 1; k < m; ++k) {                   
      int child = k+1;
      while (child > 1 && arr[child/2] < arr[child]) {  // 5
         troca (arr[child/2], arr[child]);          // 6
         child /= 2;                        // 7
      }
   }
}

static void 
peneira (int m, int v[]) {
   int f = 2;
   while (f <= m) {
      if (f < m && v[f] < v[f+1]) ++f;
      if (v[f/2] >= v[f]) break;
      troca (v[f/2], v[f]);
      f *= 2;
   }
}

void
heapsort (int n, int v[])
{
   constroiHeap (n, v);
   for (int m = n; m >= 2; --m) {
      troca (v[1], v[m]);
      peneira (m-1, v);
   }
}