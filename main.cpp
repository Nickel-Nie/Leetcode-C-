#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <deque>

typedef int arr[];

using namespace std;

struct X{

};

//X const x;
const X x;

template <typename T>
void Swap(T &,T &);

template <> void Swap<int>(int &a, int &b);

int func(const int& x){
    return x;
}

//template <> void swap(int& a, int &b){
//    a = 1;
//    b = 2;
//}

int main() {
//    map<int, vector<int>> map1;
//    cout << map1[0].size() << endl;
    string s = "123";
    s[1] += 1;
    cout << s << endl;
    map<int, int> m;
    if(m.find(1) != m.end()){
        cout << "find key" << endl;
    } else {
        cout << "not find key" << endl;
    }
    auto val = m[1];

    if(m.find(1) != m.end()){
        cout << "find key" << endl;
    } else {
        cout << "not find key" << endl;
    }

//    int arr[5] = {5,6,7,8,9};
//    list<int> list1(arr, arr+5);
//    auto ite = find(list1.begin(), list1.end(), 7);
////    list1.splice(ite, list1);
//
//    for(auto i = list1.begin(); i!=list1.end(); i++){
//        cout << *i << ' ' ;
//    }
//    cout << endl;


//    int arr[] = {1,2,3};
//    std::cout << arr << std::endl;
//    std::cout << &arr << std::endl;
//    std::cout << &arr[0] << std::endl;
//    int x = 1;

//    func(1);
//    Swap(arr[0], arr[1]);
//    cout << &"asd" << endl;
    return 0;
}

template <> void Swap<int>(int &a, int &b){

}
