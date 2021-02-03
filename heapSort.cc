#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void buildHeap(vector<int> &heap,int val) {
    int pos=heap.size();
    heap.push_back(val);
    while(pos) {
        if(heap[pos/2]>heap[pos]) {
            swap(heap[pos/2],heap[pos]);
        }
        pos=pos/2;
    }
}

int main()
{
    vector<int> heap;
    vector<int> vec({5,4,2,1,3});
    for(int &x:vec) {
        buildHeap(heap,x);
    }
    for(int &x:heap) {
        cout<<x<<" ";
    }
    cout<<endl;
}