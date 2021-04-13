
#include <iostream>
#include <vector>

using namespace std;

template<typename ptr_t>
void my_swap(ptr_t first,ptr_t second){

    typedef typename iterator_traits<ptr_t>::value_type  x;
    x temp(*first);
    *first = *second;
    *second = temp;


    // int temp = *first;
    // *first= *seocndl
    // *seocnd=*first;

}


int main(){

    int arr[5] = {11,22,33,44,55};
    my_swap(arr,arr+3);
    
    for(int i=0;i<5;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
    
}
