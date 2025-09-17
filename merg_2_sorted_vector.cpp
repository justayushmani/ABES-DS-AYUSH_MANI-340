#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 3, 5, 7, 9};
    vector<int> v2 = {2, 4, 6, 8, 10};
    int i=0, j=0;
    vector<int> merged_vector;
    while(i < v.size() && j < v2.size()) {
        if(v[i] < v2[j]) {
            merged_vector.push_back(v[i]);
            i++;
        } else {
            merged_vector.push_back(v2[j]);
            j++;
        }
    }
      while(i < v.size()) {
        if(v[i] < v2[j]) {
            merged_vector.push_back(v[i]);
            i++;
    } }
      while(j < v2.size()) {
        if(v[i] < v2[j]) {
            merged_vector.push_back(v[i]);
            i++;
    }}
    for(auto k: merged_vector) {
        cout << k << " ";
    }
    
}
 