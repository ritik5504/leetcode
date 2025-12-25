class RandomizedSet {
public:
    vector<int>arr;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;

        arr.push_back(val);
        int idx=arr.size()-1;
        mp[val]=idx;

        return true;
        
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int last=arr.back();
        int idx=mp[val];
        arr.back()=val;
        arr[idx]=last;
        mp[last]=idx;
        arr.pop_back();
        mp.erase(val);
        return true;


        
    }
    
    int getRandom() {
        
        int n=arr.size();
        int random=rand()%n;
        return arr[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */