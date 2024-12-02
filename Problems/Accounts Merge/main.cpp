class DSU {
private:
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n) : parent(n), size(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int root(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = root(parent[node]);
    }
    bool Union(int u, int v) {
        int rootU = root(u);
        int rootV = root(v);
        if (rootU == rootV)
            return false;
        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n + 9);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.find(accounts[i][j]) != mp.end()) {
                    dsu.Union(i, mp[accounts[i][j]]);
                } else {
                    mp[accounts[i][j]] = i;
                }
            }
        }
        unordered_map<int, vector<string>> dic;
        for (auto &it : mp) {
            int root = dsu.root(it.second);
            dic[root].push_back(it.first);
        }
        vector<vector<string>> output(dic.size());
        int index = 0;
        for (auto &it : dic) {
            output[index].push_back(accounts[it.first][0]);
            sort(it.second.begin(), it.second.end());
            for (string email : it.second)
                output[index].push_back(email);
            ++index;
        }
        return output;
    }
};
