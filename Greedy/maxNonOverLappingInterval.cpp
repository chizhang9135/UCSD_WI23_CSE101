#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
  int start;
  int end;
};

bool compareIntervals(Interval a, Interval b) {
  if (a.end < b.end) return true;
  else return false;
}

vector<Interval> maxNonOverlappingIntervals(vector<Interval> intervals) {
  vector<Interval> result;
  sort(intervals.begin(), intervals.end(), compareIntervals);
  int last_end = INT_MIN;
  for (int i = 0; i < intervals.size(); i++) {
    if (intervals[i].start > last_end) {
      result.push_back(intervals[i]);
      last_end = intervals[i].end;
    }
  }
  return result;
}

int main() {
  vector<Interval> intervals = {{-1, 2}, {-2, 3}, {3, 4}, {1, -3}};
  vector<Interval> result = maxNonOverlappingIntervals(intervals);
  for (int i = 0; i < result.size(); i++) {
    cout << "[" << result[i].start << "," << result[i].end << "]" << endl;
  }
  return 0;
}

