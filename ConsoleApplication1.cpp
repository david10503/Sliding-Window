#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool hasDistinctSubarray(const vector<int>& nums, int k) {
    unordered_set<int> window;
    int left = 0;

    for (int right = 0; right < nums.size(); ++right) {
        // Enquanto o elemento já estiver no conjunto, removemos da esquerda
        while (window.count(nums[right])) {
            window.erase(nums[left]);
            ++left;
        }

        window.insert(nums[right]);

        // Verifica se a janela tem tamanho k
        if (right - left + 1 == k) {
            return true;
        }
    }

    return false;
}