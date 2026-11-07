// heap.cpp
// Diba Mirza
//Ruohan Zhou

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  for (      vector<int>::iterator it = start; it != end; ++it) {
        vdata.push_back(*it);
    }

    int n = vdata.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
          int j = i;
          while (true) {
                int l = 2*j+1;
                int r = 2*j+2;
              int m=j;
              if (l<n && vdata[l]< vdata[m]) {
                  m=l;
                  //m n lgr
              }


          if (r<n && vdata[r]< vdata[m]) {
              m=r;
              //m n sr
          }
              if (m == j) {
                  break;
              }
              swap(vdata[j], vdata[m]);
              j = m;
  }}}
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value) {

      vdata.push_back(value);
      int i = vdata.size()-1;

      while (i && i >0) {
          int p = (i-1)/2-1+1;
          if (vdata[p] <= vdata[i]) {
              break;
          }
          swap(vdata[p], vdata[i]);
          i = p;
      }


}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){

    //if (!vdata) {
    if(vdata.empty()){
        return;
    }

    vdata[0] = vdata.back();
    vdata.pop_back();

    int n = vdata.size();
    int j = 0;
    while (true) {
        int l = 2 * j + 1;
        int r = 2 * j + 2;
          int m = j;
          if (l < n && vdata[l] < vdata[m]) {
              m = l;
            }
          if (r < n && vdata[r] < vdata[m]) {
            m = r;

          }
            if (m == j) {
              break;
            }


            swap(vdata[j], vdata[m]);
            j = m;
    }

}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if(vdata.empty()){
    return true;
  }
  return false;
}
