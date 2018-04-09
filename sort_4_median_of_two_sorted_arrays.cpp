/*************************************************************************************** 
 *
 * 若两个数组长度之和为偶数，则用两个变量记录归并排序后中间两个数的下标，否则用一个变量
 * 记录归并排序后中间数的下标。归并排序过程中记录中间两个数或中间的一个数。归并排序后输
 * 出中间两个数的平均值或者中间的一个数。
 * 时间复杂度O(m+n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        int nums_size = nums1_size + nums2_size;
        int index_median1 = -1;
        int index_median2 = -1;
        bool is_dual = (nums_size % 2 == 0) ? true : false;
        if (is_dual) {
            index_median1 = nums_size / 2;
            index_median2 = index_median1 - 1;
        } else {
            index_median1 = (nums_size-1) / 2;
        }
        int index1 = 0;
        int index2 = 0;
        int median1 = 0;
        int median2 = 0;
        for (int i = 0; i < nums_size; ++i) {
            int min_num = 0;
            if (index1 < nums1_size && index2 < nums2_size) {
                if (nums1[index1] < nums2[index2]) {
                    min_num = nums1[index1];
                    index1++;
                } else {
                    min_num = nums2[index2];
                    index2++;
                }
            } else if (index1 < nums1_size && index2 >= nums2_size) {
                min_num = nums1[index1];
                index1++;
            } else if (index1 >= nums1_size && index2 < nums2_size) {
                min_num = nums2[index2];
                index2++;
            }

            if (is_dual) {
                if (i == index_median1) {
                    median1 = min_num;
                } else if (i == index_median2) {
                    median2 = min_num;
                }
            } else {
                if (i == index_median1) {
                    median1 = min_num;
                }
            }
        }
        if (is_dual) {
            return (median1 + median2) * 1.0 / 2;
        } else {
            return median1;
        }   
    }
};
