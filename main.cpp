#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, vector<int>> numIndexMap;

        int count = nums.size();
        for(int i = 0; i<count; i++){
            numIndexMap[nums[i]].push_back(i);
        }

        sort(nums.begin(),nums.end());

        int p1 = 0, p2 = 1;
        do{
            if (nums[p1] + nums[p2] == target)
                break;
            else if (p2 < count-1 ) {
                p2++;
            }

            else if (p2 == count-1 || nums[p1] + nums[p2] > target) {
                p1++;
                p2 = p1 +1;
            }

        }while(true);

        result.resize(2);

        if(nums[p1] - nums[p2] == 0){
            result[0] = numIndexMap[nums[p1]][0];
            result[1] = numIndexMap[nums[p1]][1];
        }
        else{
            result[0] = numIndexMap[nums[p1]][0];
            result[1] = numIndexMap[nums[p2]][0];
        }

        return result;
    }

    void quickSort(vector<int>& nums, int s, int t){
        int i, j;

        if (s < t) {
            i = s;
            j = t+1;
            while(1){
                do i++;
                while (!(nums[s] <= nums[i] || i == t));

                do j--;
                while(!(nums[s] >= nums[j] || j==s) );

                if(i<j)
                    swap(nums[i],nums[j]);
                else
                    break;
            }

            swap(nums[s],nums[j]);
            quickSort(nums, s, j-1);
            quickSort(nums, j+1, t);
        }
    }

    void swap(int& a, int &b){
        int temp = a;
        a = b;
        b = a;
    }
};

int main() {
    Solution * solution = new Solution();
    vector<int> nums={2,1,9,4,4,56,90,3};


    vector<int> result = solution->twoSum(nums, 8);

    cout<< result[0]<<";"<<result[1]<<endl;
    return 0;
}
