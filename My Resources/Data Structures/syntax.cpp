//initialise a heap with most frequent elements at the top
auto comp = [&count_map](int n1, int n2) { return count_map[n1] > count_map[n2]; };
priority_queue<int, vector<int>, decltype(comp)> heap(comp);
