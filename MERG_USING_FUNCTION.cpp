#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> v={1,2,3,4,5};
    vector<int> v2={6,7,8,9,10};
    vector<int> merged_vector;
    merge(v.begin(), v.end(), v2.begin(), v2.end(), back_inserter(merged_vector));
    cout << "Merged vector: ";
    for(auto k: merged_vector){
        cout << k << " ";
    
    }
}