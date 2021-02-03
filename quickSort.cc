#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// void swap(int a, int b, vector<int>& nums) {
//     int k ;
//     k =nums[a];
//     nums[a] = nums[b];
//     nums[b] = k;
// }

// int partition(vector<int>& nums, int l, int r){
//     int lt = l + 1; //[l+1...lt-1] > p ; [lt..i) < p
//     for( int i = l + 1 ; i <= r ; i ++ )
//         if( nums[i] > nums[l] )
//             swap(i, lt++,nums);
//     swap(l, lt-1,nums);
//     return lt-1;
// }



int partition(vector<int> &vec,int low,int high) {
    int pivot = vec[low];
    while(low<high) {
        while(low<high&&vec[high]>pivot) high--;
        vec[low] = vec[high];
        while(low<high&&vec[low]<pivot) low++;
        vec[high] = vec[low];
    }
    vec[low] = pivot;
    return low;
} 
void qsort(vector<int> &vec,int low,int high) {
    if(low<high) {
        int pos = partition(vec,low,high);
        qsort(vec,low,pos-1);
        qsort(vec,pos+1,high);
    }
}


int main() {
    vector<int> vec({
        1,2,3,4,5
    });
    qsort(vec,0,4);
    for(int &x:vec) {
        cout<<x<<"\t";
    }
    cout<<endl;

}

