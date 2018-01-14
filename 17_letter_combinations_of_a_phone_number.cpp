/*************************************************************************************** 
 *
 * 时间复杂度O(m*n)
 *
 ***************************************************************************************/

class Solution {
public:
    void combinLetter(const std::string& digits, const std::string digit[],
        int level, std::string& out, std::vector<std::string>& result) {
      if (level == digits.length()) {
        result.push_back(out);
      } else {
        std::string num_dig = digit[digits[level] - '2'];
        for (int j = 0; j < num_dig.length(); ++j) {
          out.push_back(num_dig[j]);
          combinLetter(digits, digit, level + 1, out, result);
          out.pop_back();
        }
      }
    }

    std::vector<std::string> letterCombinations(std::string digits) {
      std::vector<std::string> result;
      if (digits.empty()) {
        return result;
      }
      std::string digit[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      int level = 0;
      std::string out = "";
      combinLetter(digits, digit, level, out, result);
      return result;
    }

};
