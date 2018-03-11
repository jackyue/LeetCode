/*************************************************************************************** 
 * 
 ***************************************************************************************/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        std::vector<int> bits;
        for (int i = 0 ; i < 32; ++i) {
            bits.push_back(n % 2);
            n = n / 2;
        }
        uint32_t result = 0;
        for (int i = 0 ; i < 32; ++i) {
            result += (bits[i] << (31 - i));
        }
        
        
        return result;
    }
};
