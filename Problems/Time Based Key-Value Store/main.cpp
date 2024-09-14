class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> mp;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end())
            return "";        
        int l = 0;
        int h = mp[key].size() - 1;
        int mid;
        int index = -1;
        while (l <= h) {
            mid = (l + h) / 2;
            if (mp[key][mid].second <= timestamp) {
                index = mid;
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        if (index == -1)
            return "";
        return mp[key][index].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
