#include <iostream>
#include <unordered_map>
#include <list>

template<typename K,typename V>//K和V代表类型
class LRUCache{
public:
    explicit LRUCache(size_t capacity):cap_(capacity){}
    //命中返回true,并将值赋值给out，同时将当前节点移动到链表头
    bool get(const K& key,V& out){
        auto it=index_.find(key);
        if(it==index_.end()){
            return false;
        }
        out=it->second->second;
        item_.splice(item_.begin(),item_,it->second);
        return true;
    }
    //插入或者更新：存在则更新并把当前更新的节点挪到标头；如果不存在可能需要淘汰尾部的节点
    void put(const K& key,V value){
        auto it=index_.find(key);
        if(it!=index_.end()){
            it->second->second=std::move(value);
            item_.splice(item_.begin(),item_,it->second);
            return;
        }
        if(item_.size()==cap_){
            auto& old=item_.back();
            index_.erase(old.first);
            item_.pop_back();
        }
        item_.emplace_front(key,std::move(value));
        index_[item_.front().first]=item_.begin();//关联索引
    }
    void debug_print(){
        std::cout<<"[MRU->LRU]";
        for(auto& p:item_){
            std::cout<<"("<<p.first<<","<<p.second<<")";
        }
        std::cout<<std::endl;
    }
private:
    size_t cap_;
    std::list<std::pair<K,V>> item_;
    //哈希表存储键值对到链表迭代器的映射，O(1)时间复杂度
    std::unordered_map<K,typename std::list<std::pair<K,V>>::iterator> index_;
};

int main(){
    LRUCache<int,std::string> cache(3);
    cache.put(1,"one");
    cache.put(2,"two");
    cache.put(3,"three");
    cache.debug_print();
    std::string out;
    if(cache.get(2,out)){
        std::cout<<"get 2:"<<out<<std::endl;
    }
    cache.debug_print();
    cache.put(4,"four");
    cache.debug_print();
}