#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int merge(string::iterator begin, string::iterator end) {
    size_t size = end - begin;
    string sorted;

    auto left = begin;
    auto right = begin + size / 2;
    auto mid = right;
    cout << string(begin,end) << ' ';

    while (left != mid && right != end) {
        if (*left == *right) {
            return 0;
        }
        else if (*left > *right) {
            sorted.push_back(*right);
            right++;
        }
        else {
            sorted.push_back(*left);
            left++;
        }
    }

    while (left != mid) {
        sorted.push_back(*left);
        left++;
    }
    while (right != end) {
        sorted.push_back(*right);
        right++;
    }

    /* original string = sorted string */
    //auto orig_it = begin;
    //auto sorted_it = sorted.begin();
    //while (orig_it != end) {
    //    *orig_it = *sorted_it;
    //    orig_it++;
    //    sorted_it++;
    //}
    copy(sorted.begin(), sorted.end(), begin);

    cout << string(begin, end) << endl;
    return 1;
}

int mergeSort(string::iterator begin, string::iterator end) {
    size_t size = end - begin;
    if (size <= 1) {
        return 1;
    }
    
    int result = 1;

    result = mergeSort(begin, begin + size / 2);
    if (result == 0)
        return 0;
    result = mergeSort(begin + size / 2, end);
    if (result == 0)
        return 0;

    return merge(begin, end);
}

int isUnique(string input) {
    return mergeSort(input.begin(), input.end());
}

void main() {
    cout << isUnique("abegfd") << endl;
    cout << isUnique("aegfd3tw2b") << endl;
}