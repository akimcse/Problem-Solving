class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1, tmp = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != tmp) {
                tmp = nums[i];
                nums[idx++] = tmp;
            }
        }
        return idx;
    }
};


/*
runtime 0ms 나오는 코드
- 되도록이면 라이브러리를 쓰지 말아보자

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1, tmp = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != tmp) {
                tmp = nums[i];
                nums[idx++] = tmp;
            }
        }
        return idx;
    }
};
*/
