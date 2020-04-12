
vector<int> ARR;
void sliding_window_minimum(int K) {    // Sub-array size of K
  // pair<int, int> represents the pair (ARR[i], i)
  deque<pair<int, int> > window;  // keep value & position
  for (int i = 0; i < ARR.size(); i++) {
     while (!window.empty() && window.back().first >= ARR[i])
       window.pop_back();
     window.push_back(make_pair(ARR[i], i));
     while(window.front().second <= i - K)
       window.pop_front();
     cout << (window.front().first) << ' ';
  }
}
