/*************************************************************************************** 
 *
 * 初始时，变量i,j分别为第一条和最后一条线段下标。如果第i条线段长度小于第j条线段长度，
 * 则说明短板在第i条线段，向左移动j只能让面积更小，所以此时需向右移动i；同理，如果第
 * j条线段长度小于第i条线段长度，则说明短板在第j条线段，向右移动i只能让面积更小，所以
 * 此时需向左移动j。
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        int max_area = 0;
        
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int area = (j - i) * min(height[i], height[j]);
            if (area > max_area) {
                max_area = area;
            }
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return max_area;
    }
};
