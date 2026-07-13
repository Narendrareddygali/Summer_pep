class Solution {
public:
    int sum(vector<int>& arr, int mid) {
        int s = 0;
        for (int i = 0; i < arr.size(); i++) {
            s += ceil((double)arr[i] / mid);
        }
        return s;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (sum(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};