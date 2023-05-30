class MyHashSet {
public:
    vector<int> arr;
    int siz;
    MyHashSet() {
       siz=1e6+1;
        arr.resize(siz);
    }
    
    void add(int key) {
        arr[key]=1;
        
    }
    
    void remove(int key) {
        arr[key]=0;
        
    }
    
    bool contains(int key) {
        return arr[key];
        
    }
};