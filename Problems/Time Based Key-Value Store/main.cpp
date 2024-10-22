class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string answer;
        if (mp.find(key) == mp.end())
            return answer;
        int l = 0;
        int r = mp[key].size() - 1;
        int mid = 0;

        while (l <= r) {
            mid = (l + r) / 2;
            if (mp[key][mid].second <= timestamp) {
                answer = mp[key][mid].first;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return answer;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
