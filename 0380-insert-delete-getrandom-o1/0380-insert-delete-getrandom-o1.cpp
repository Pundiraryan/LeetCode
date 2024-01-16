class RandomizedSet {
    private:
    vector<int>nums;
    unordered_map<int,int>fre;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(fre.find(val)!=fre.end())return false;
        nums.push_back(val);
        fre[val]=nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(fre.find(val)==fre.end())return false;
        int idx=fre[val];
        fre[nums.back()]=idx;
        nums[idx]=nums.back();
        fre.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */