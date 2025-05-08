#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;

// FIFO Page Replacement
int fifoPageReplacement(const vector<int>& pages, int capacity) {
    unordered_set<int> s;
    queue<int> q;
    int pageFaults = 0;

    for (int page : pages) {
        if (s.find(page) == s.end()) {
            if (s.size() == capacity) {
                int oldest = q.front();
                q.pop();
                s.erase(oldest);
            }
            s.insert(page);
            q.push(page);
            pageFaults++;
        }
    }
    return pageFaults;
}

// LRU Page Replacement
int lruPageReplacement(const vector<int>& pages, int capacity) {
    list<int> lruList;
    unordered_map<int, list<int>::iterator> pageMap;
    int pageFaults = 0;

    for (int page : pages) {
        if (pageMap.find(page) == pageMap.end()) {
            if ((int)lruList.size() == capacity) {
                int last = lruList.back();
                lruList.pop_back();
                pageMap.erase(last);
            }
            pageFaults++;
        } else {
            lruList.erase(pageMap[page]);
        }
        lruList.push_front(page);
        pageMap[page] = lruList.begin();
    }
    return pageFaults;
}

// Optimal Page Replacement
int optimalPageReplacement(const vector<int>& pages, int capacity) {
    unordered_set<int> s;
    int pageFaults = 0;

    for (size_t i = 0; i < pages.size(); i++) {
        int page = pages[i];

        if (s.find(page) == s.end()) {
            if (s.size() < capacity) {
                s.insert(page);
            } else {
                int farthest = i + 1;
                int victim = -1;

                for (int p : s) {
                    size_t j;
                    for (j = i + 1; j < pages.size(); j++) {
                        if (pages[j] == p) break;
                    }
                    if (j > farthest) {
                        farthest = j;
                        victim = p;
                    }
                }

                if (victim == -1) victim = *s.begin();
                s.erase(victim);
                s.insert(page);
            }
            pageFaults++;
        }
    }
    return pageFaults;
}

// Test all three algorithms
int main() {
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int capacity = 4;

    cout << "FIFO Page Faults: " << fifoPageReplacement(pages, capacity) << endl;
    cout << "LRU Page Faults: " << lruPageReplacement(pages, capacity) << endl;
    cout << "Optimal Page Faults: " << optimalPageReplacement(pages, capacity) << endl;

    return 0;
}
