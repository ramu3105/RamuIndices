#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept> 

using namespace std;

// Function to find two indices in the array that sum up to the target
vector<int> twoSum(vector<int>& nums, int target) {
    // Creating an unordered map to store the value and its index
    unordered_map<int, int> num_map;

    // Iterate through the array
    for (int i = 0; i < nums.size(); i++) {
        // Calculate the difference needed to reach the target
        int complement = target - nums[i];

        // Check if the complement is already in the map
        if (num_map.find(complement) != num_map.end()) {
            // If found, return the current index and the index of the complement
            return {num_map[complement], i};
        }

        // Otherwise, add the current number and its index to the map
        num_map[nums[i]] = i;
    }

    // If no valid pair is found, return an empty vector
    return {};
}

int main() {
    try {
        int n;
        cout << "Enter the number of elements in the array (at least 3): ";
        cin >> n;

        // Validate the length of the array
        if (n < 3 || n > 10000) {
            throw invalid_argument("Array length must be between 3 and 10^4.");
        }

        vector<int> nums(n);
        cout << "Enter the elements of the array:\n";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            // Validate each array element
            if (nums[i] < -1000000000 || nums[i] > 1000000000) {
                throw invalid_argument("Array elements must be between -10^9 and 10^9.");
            }
        }

        int target;
        cout << "Enter the target value: ";
        cin >> target;

        // Validate the target value
        if (target < -1000000000 || target > 1000000000) {
            throw invalid_argument("Target value must be between -10^9 and 10^9.");
        }

        // Get the indices of the two elements that sum to the target
        vector<int> result = twoSum(nums, target);

        // Check if a valid pair was found
        if (result.empty()) {
            cout << "No valid pair found that adds up to the target value." << endl;
        } else {
            cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
        }

    } catch (const exception& e) {
        // Catch and display any validation errors
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
