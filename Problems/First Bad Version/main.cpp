// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, h = n,
        mid = 0, out = 0;
        while (l <= h) {
            mid = l + (h - l) / 2;
            if (isBadVersion(mid))
                out = mid,
                h = mid - 1;
            else
                l = mid + 1;
        }
        return out;
    }
};
