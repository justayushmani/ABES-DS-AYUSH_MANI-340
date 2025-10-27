#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(1);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(2);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(6);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(8);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(9);
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    for (auto value : v)
        cout << value << " ";
    cout << endl;

    v.pop_back();
    for (auto value : v)
        cout << value << " ";
    cout << endl;
    cout << "Front:" << v.front() << " " << "Last Value:" << v.back() << endl;

    v.insert(v.begin(), 2);
    for (auto value : v)
        cout << value << " ";
    cout << endl;

    v.insert(v.begin() + 2, 10);
    for (auto value : v)
        cout << value << " ";
    cout << endl;

    cout << "size of vector 1:" << v.size() << endl;
    cout << "the capacity of vector 1:" << v.capacity() << endl;

    v.insert(v.begin() + 4, 3, 10);
    for (auto value : v)
        cout << value << " ";
    cout << endl;

    v.erase(v.begin());
     for (auto value : v)
        cout << value << " ";
    cout << endl;

     v.erase(v.begin(),v.begin()+3);
     for (auto value : v)
        cout << value << " ";
    cout << endl;

    vector<int>v1={1,2,3,4,5};
      for (auto value : v1)
        cout << value << " ";
    cout << endl;

    vector<int>_V2(2,5);
      for (auto value : _V2)
        cout << value << " ";

        vector<int>::iterator it;
        for(auto it=v1.begin();it!=v1.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    vector<int>::iterator reverse_it;
    for(auto reverse_it=v1.end()-1;reverse_it!=v1.begin()-1;reverse_it--){
        cout<<*reverse_it<<" ";
    }


<<<<<<< HEAD
}
=======
}
>>>>>>> dd48dfe643df5dda8ab40eb666f620f9a49f4a48
