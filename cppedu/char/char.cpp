#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>


using namespace std;


int main(){
    
    // vector push_back pop_back back front 
    vector<int> a(10, 0);

    for(auto i:a) cout<<a[i]<<" ";
    cout<<endl;


    pair<int, string> p;
    //first, second

    p = make_pair(10, "scb");
    cout<< p.first<<endl;

    //string substr()
    string str = "scb";

    str += "def";
    str += "c";
    cout << str.substr(1, 2)<<endl;

    printf("%s\n", str.c_str());

    //queue, pop push front back

    queue<int> q;
    q = queue<int>();

    // heap,  push pop top 
    priority_queue<int, vector<int>, greater<int>> heap;
    //默认大根堆 小根堆定义如上

    // stack push top pop

    // deque 

    // set multiset   insert find count  
    // erase (1) delete every point == 1; O(k+logn)  
    // iterator delete the itertor

    // lowerbound() return min(i)>=x 
    // upperbound() return min(i)>x

    // map 二叉搜索树 insert<pair> erase<pair iterator>
    // multimap[]
    set<int> S;
    multiset<int> M; // 可重复
    
    map<string, int> map_edu;
    map_edu["xxx"] = 1;


    // unordered map set
    // 无lower upperbound
    unordered_map<int, string> om;


    // bitset 压位
    // 1024 bool array 1024 byte

    bitset<100000> S;
    // ~(not) &(and) |(OR) ^(XOR) >> << == != []
    // count() return 1 numbers;
    // any() judge has at least 1
    // none() judge has all 0
    // set(k, v) 将k位置v
    // reset  all 0
    // set   all 1
    // flip == ~
    // flip(k)  k ~


    return 0;
}

