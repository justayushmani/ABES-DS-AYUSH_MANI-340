#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int main() {

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    if(binary_search(v.begin(), v.end(), 5)) {
        cout << "Element found in the vector." << endl;
    } else {
        cout << "Element not found in the vector." << endl;
    }

    return 0;
}

