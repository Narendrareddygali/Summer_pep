class Solution {
public:
    bool isValid(vector<int>& pos, int currPos, int m) {
        int ballCnt = 1;
        int lastPos = pos[0];

        for (int i = 1; i < pos.size(); i++) {
            if (pos[i] - lastPos >= currPos) {
                ballCnt++;
                lastPos = pos[i];
            }

            if (ballCnt >= m)
                return true;
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1;
        int high = position.back() - position.front();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValid(position, mid, m))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};