class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < min) min = prices[i]; // 일단 최솟값은 그대로 찾기

            int profit = prices[i] - min;
            maxProfit = maxProfit + profit; // 수익은 무조건 나는거니까 계속 더하고
            min = prices[i]; // 수익이 난 시점으로 최솟값 업데이트
        }

        return maxProfit;
    }
};


// 오늘 처음으로 코테 문제 풀며 늘었다는 걸 느낌
// 문제 딱 보고 이렇게 하면 될 것 같은데? 하는 직감이 들어서 제출했더니 바로 맞음
// 논리적으로 접근하기도 전에 바로 풀이가 떠오르다니 신기하다.
