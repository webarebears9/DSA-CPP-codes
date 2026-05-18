class Solution {
public:

    bool f(const vector<int>& bloomDay, int m, int k, int timeLimit) {

        // check if you can make 'm' bouquets of 'k' adj. flowers within the timeLimit

        int pickCnt = 0;
        int bouquetCnt = 0;

        for (int cur_flower_bloom_day : bloomDay) {

            if (cur_flower_bloom_day <= timeLimit) {

                // cur_flower has bloomed so lets pick it

                pickCnt++;
                if (pickCnt == k) {

                    // you've made a bouquet
                    bouquetCnt++;
                    pickCnt = 0;

                }

            } else {

                pickCnt = 0;

            }

        }

        // return bouquetCnt >= m;

        if (bouquetCnt >= m) {
            // you can also make m bouquets in timeLimit
            return true;
        } else {
            // you cannot make m bouquets in timeLimit
            return false;
        }

    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        // time : O(log(e-s).n)

        while (s <= e) { // # iterations = log(e-s)

            int mid = s + (e - s) / 2;

            // can I make 'm' bouquets of 'k' adj. flowers in 'mid' no. of days

            if (f(bloomDay, m, k, mid)) { // f(...) takes linear time O(n)

                // you can make 'm' bouquets of 'k' adj. flowers in 'mid' no. of days

                ans = mid;
                e = mid - 1;

            } else {

                // you cannot make 'm' bouquets of 'k' adj. flowers. in 'mid' no. of days

                s = mid + 1;

            }

        }

        return ans;

    }
};