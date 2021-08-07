#include <iostream>
#include <vector>

using namespace std;

int trappedWater(vector<int> heights) {
  int n = heights.size();
  int water = 0;

  if (n <= 2) return water;

  vector<int> left(n, 0);
  vector<int> right(n, 0);

  left[0] = heights[0];
  right[n - 1] = heights[n - 1];

  for (int i = 1; i < n - 1; i++) {
    left[i] = max(heights[i], left[i - 1]);
    right[n - i - 1] = max(heights[n - i - 1], right[n - i]);
  }

  for (int i = 0; i < n - 1; i++) {
    water += min(left[i], right[i]) - heights[i];
  }

  return water;
}

int main(void) {
  vector<int> water = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << trappedWater(water) << endl;

  return 0;
}
