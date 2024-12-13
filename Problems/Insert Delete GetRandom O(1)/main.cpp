class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> vec;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end())
            return false;
        vec.push_back(val);
        mp[val] = vec.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end())
            return false;

        int index = mp[val];
        int last = vec.size() - 1;
        mp[vec[last]] = index;

        int num = vec[index];
        vec[index] = vec[last];
        vec[last] = num;

        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        if (vec.empty())
            return false;
        int random = rand() % vec.size();
        return vec[random];
    }
};
