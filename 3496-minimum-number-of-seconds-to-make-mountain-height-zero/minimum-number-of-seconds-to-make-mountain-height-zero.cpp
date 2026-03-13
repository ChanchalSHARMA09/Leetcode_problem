class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0, right = 1e18;

        while(left < right){
            long long mid = (left + right) / 2;
            long long removed = 0;

            for(long long t : workerTimes){
                long double val = (long double)1 + (long double)8 * mid / t;
                long long x = (sqrt(val) - 1) / 2;
                removed += x;

                if(removed >= mountainHeight) break;
            }

            if(removed >= mountainHeight) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};