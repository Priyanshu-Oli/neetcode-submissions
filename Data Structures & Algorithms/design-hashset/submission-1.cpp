class MyHashSet {
public:
    bool Hash[1000001];
    MyHashSet() {
        int key;
        for(int i =0; i<=1000000;i++){
            Hash[i]=false;
        }

    }
    
    void add(int key) {
        Hash[key]=true;
    }
    
    void remove(int key) {
        Hash[key]= false;
    }
    
    bool contains(int key) {
        return Hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */