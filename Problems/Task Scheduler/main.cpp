class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        priority_queue<int> pq;
        queue<pair<int, int>> cooldown;
        for (char task : tasks)
            freq[task - 'A']++;
        for (int f : freq)
            if (f)
                pq.push(f);
        int time = 0;
        while (!pq.empty() || !cooldown.empty()) {
            time += 1;
            if (!pq.empty()) {
                int remaining = pq.top() - 1;
                pq.pop();
                if (remaining)
                    cooldown.push({remaining, time + n});
            }
            if (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return time;
    }
};
