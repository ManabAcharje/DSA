class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        int MAX_VAL = 100000;
        vector<bool> is_prime(MAX_VAL + 1, true);
        is_prime[0] = is_prime[1] = false;
        vector<int> primes;
        
        for (int p = 2; p <= MAX_VAL; p++) {
            if (is_prime[p]) {
                primes.push_back(p);
            
                for (long long mult = (long long)p * p; mult <= MAX_VAL; mult += p) {
                    is_prime[mult] = false;
                }
            }
        }

        int n = nums.size();
        int i = 0;
        int j = 0;
        int unique_factors = 0;
        int max_len = 0;
        unordered_map<int, int> prime_count;

     
        while (j < n) {
            int curr_no = nums[j];
            
           
            for (int p : primes) {
                if (p * p > curr_no) break;  
                
                if (curr_no % p == 0) {
                    if (prime_count[p] == 0) {
                        unique_factors++;
                    }
                    prime_count[p]++;

                    while (curr_no % p == 0) {
                        curr_no /= p;
                    }
                }
            }
    
            if (curr_no > 1) {
                if (prime_count[curr_no] == 0) {
                    unique_factors++;
                }
                prime_count[curr_no]++;
            }


            while (unique_factors > k) {
                int left_no = nums[i];
            
                for (int p : primes) {
                    if (p * p > left_no) break;
                    
                    if (left_no % p == 0) {
                        prime_count[p]--;
                        if (prime_count[p] == 0) {
                            unique_factors--;
                        }
                        
                        while (left_no % p == 0) {
                            left_no /= p;
                        }
                    }
                }
                if (left_no > 1) {
                    prime_count[left_no]--;
                    if (prime_count[left_no] == 0) {
                        unique_factors--;
                    }
                }
                
                i++; 
            }

            int curr_len = j - i + 1;
            max_len = max(max_len, curr_len);
            j++;
        }

        return max_len;
    }
};