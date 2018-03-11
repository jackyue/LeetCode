class RandomizedSet {
public:
  /** Initialize your data structure here. */
  RandomizedSet() {
  }
  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (val_pos_map.find(val) != val_pos_map.end()) {
      return false;
    } else {
      val_vec.push_back(val);
      val_pos_map[val] = val_vec.size() - 1;
      return true;
    }
  }
  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if (val_pos_map.find(val) == val_pos_map.end()) {
      return false;
    } else {
      int pos = val_pos_map[val];
      int last_val = val_vec[val_vec.size() - 1];
      val_vec[pos] = last_val;
      val_pos_map[last_val] = pos;
      val_vec.pop_back();
      val_pos_map.erase(val);
      return true;
    }
  }
  /** Get a random element from the set. */
  int getRandom() {
    int pos = rand() % val_vec.size();
    return val_vec[pos];
  }
private:
  std::vector<int> val_vec;
  std::unordered_map<int, int> val_pos_map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */