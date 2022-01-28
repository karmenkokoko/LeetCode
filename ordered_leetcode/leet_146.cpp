#include <bits/stdc++.h>
// LRU 缓存
using namespace std;

// 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
// 实现 LRUCache 类：
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。
// 如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。


// 双向链表，存储key和alue
// 哈希表, 存储key和node

class LRUCache{
private:
    // 双向key value链表的声明 struct
    struct DelistNode{
        int value, key;
        DelistNode *prev, *next;
        DelistNode(): key(0), value(0), prev(nullptr), next(nullptr){}
        DelistNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr){}   
    };
    // key, node
    unordered_map<int, DelistNode *> map;
    int cache_num;
    int cur_num;

    // dummy head操作
    DelistNode *forward, *backward;

public:
    LRUCache(int capacity): cache_num(capacity), cur_num(0){
        this->forward = new DelistNode();
        this->backward = new DelistNode();
        this->forward->next = this->backward;
        this->backward->prev = this->forward;
    }

    void put(int key, int value)
    {
        // 存在key 则修改value即可
        if(map.count(key))
        {
            auto node = map[key];
            node->value = value;
            move_to_head(node);
        }
        else{
        // 不存在, 则创建新的节点
        // 统计当前大小
        // 如果大于capacity 则删除最后的节点
            DelistNode *new_node = new DelistNode(key, value);
            map.insert({key, new_node});
            add_to_head(new_node);
            this->cur_num++;
            if(this->cur_num > this->cache_num)
            {
                DelistNode *removed = delete_node();
                map.erase(removed->key);
                delete (removed);
                this->cur_num--;
            }
        }
    }

    int get(int key)
    {
        if(!map.count(key))
        {
            return -1;
        }
        auto node = map[key];
        int value = node->value;
        move_to_head(node);
        return value;
    }

    // LRU的操作， 双向链表的前段表示最近使用，删除后端
    // 加入头
    void add_to_head(DelistNode* Node)
    {
        Node->prev = forward;
        Node->next = forward->next;
        forward->next->prev = Node;
        forward->next = Node;
    }
    // 删除中间节点
    void remove_node(DelistNode* Node)
    {
        Node->next->prev = Node->prev;
        Node->prev->next = Node->next;
    }
    // 删除并移向链表头
    void move_to_head(DelistNode* Node)
    {
        remove_node(Node);
        add_to_head(Node);
    }
    // 删除最后节点
    DelistNode* delete_node()
    {
        DelistNode *node = backward->prev;
        remove_node(node);
        return node;
    }
};
