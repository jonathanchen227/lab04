// heap.cpp
// Jonathan Chen

#include "heap.h"
#include <iostream>
using std::cout;
#include <vector>

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
	vector<int> vdata;
	for ( auto i = start ; i != end; i ++ ) {
		vdata.push_back(*i);
	}
	for ( int i = (vdata.size()-1)/2 ; i >= 0 ; i-- ) {
		while ( true ) {
			int index = i;
			int left_child = 2*index + 1;
			int right_child =2*index + 2;
			if (left_child < n && vdata[left_child] < vdata[index] ) {
				swap(vdata[index],vdata[left_child]);
				index = left_child;
			} 
			if (right_child < n && vdata[right_child] < vdata[index]) {
				swap(vdata[index],vdata[right_child]);
				index = right_child;
			}
			else {
				break;
			}
		}
	}
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
	vdata.push_back(value);
	int index = vdata.size() - 1;
	while ( vdata[index] < vdata[(index-1)/2] ) {
		swap(vdata[index],vdata[(index-1)/2];
		index = (index-1)/2;
	} 
	
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
	if ( vdata.empty() ) {return;}
	vdata.erase(vdata.begin());
	for ( int i = (vdata.size() - 1)/2; i >= 0 ; i ++ ) {
		while (true ) {
			int index = i;
			int left_child = 2*index + 1;
			int right_child = 2*index + 2;
			if ( left_child < n && vdata[index] > vdata[left_child] ) {
				swap(vdata[index],vdata[left_child]);
				index = left_child;
			}
			if ( right_child < n && vdata[index] > vdata[right_child] ) {
				swap(vdata[index],vdata[right_child]);
				index = right_child;
			}
			else {
				break;
			}
		}
	}	
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata.begin();
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if ( vdata.empty() ) {
	return true;
 }
 else {
return false;
}
}
    
