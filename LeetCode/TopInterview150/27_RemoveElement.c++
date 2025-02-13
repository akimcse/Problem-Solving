class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }

        return nums.size();
    }
};

/*
nums = [0,1,2,2,3,0,4,2]인 경우

위 함수의 output이 [0,1,3,0,4]로 나오는데
문제의 expected는 [0,1,4,0,3] 이다.

왜 다를까?

---

erase vs remove
*/
