class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;

        while(left < right){
            int comp = target - (numbers[left] + numbers[right]);
            if(comp == 0) return {left+1, right+1};

            if(comp > 0){
                left++;
            }else{
                right--;
            }
        }

        return {};
    }
};
