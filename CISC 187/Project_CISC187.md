# CISC 187 - Project
## Task 1
```
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

struct Player {
    std::string first_name;
    std::string last_name;
    std::string team;
};

std::vector<std::string> playersInBothSports(
    const std::vector<Player>& basketball,
    const std::vector<Player>& football)
{
    // Build a hash set of basketball player full names — O(N)
    std::unordered_set<std::string> bball_names;
    for (const auto& p : basketball)
        bball_names.insert(p.first_name + " " + p.last_name);

    // Check each football player against the set — O(M)
    std::vector<std::string> both;
    for (const auto& p : football) {
        std::string full = p.first_name + " " + p.last_name;
        if (bball_names.count(full))
            both.push_back(full);
    }
    return both;
}

int main() {
    std::vector<Player> basketball = {
        {"Jill",  "Huang",     "Gators"},
        {"Janko", "Barton",    "Sharks"},
        {"Wanda", "Vakulskas", "Sharks"},
        {"Jill",  "Moloney",   "Gators"},
        {"Luuk",  "Watkins",   "Gators"}
    };
    std::vector<Player> football = {
        {"Hanzla", "Radosti",   "32ers"},
        {"Tina",   "Watkins",   "Barleycorns"},
        {"Alex",   "Patel",     "32ers"},
        {"Jill",   "Huang",     "Barleycorns"},
        {"Wanda",  "Vakulskas", "Barleycorns"}
    };

    auto result = playersInBothSports(basketball, football);
    std::cout << "Players in both sports:\n";
    for (const auto& name : result)
        std::cout << "  " << name << "\n";
    // Output: Jill Huang, Wanda Vakulskas
}
```

## Task #2
```
#include <iostream>
#include <vector>
#include <numeric>

int findMissing(const std::vector<int>& arr) {
    int n = (int)arr.size();          // array has N elements, range is 0..N
    long long expected = (long long)n * (n + 1) / 2;
    long long actual   = std::accumulate(arr.begin(), arr.end(), 0LL);
    return (int)(expected - actual);
}

int main() {
    std::vector<int> a = {2, 3, 0, 6, 1, 5};       // missing 4
    std::vector<int> b = {8, 2, 3, 9, 4, 7, 5, 0, 6}; // missing 1

    std::cout << "Missing from a: " << findMissing(a) << "\n"; // 4
    std::cout << "Missing from b: " << findMissing(b) << "\n"; // 1
}
```

## Task #3
```
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

int maxProfit(const std::vector<int>& prices) {
    if (prices.size() < 2)
        throw std::invalid_argument("Need at least two prices.");

    int lowest_so_far = prices[0];
    int best_profit   = prices[1] - prices[0];

    for (int i = 1; i < (int)prices.size(); ++i) {
        int profit = prices[i] - lowest_so_far;
        best_profit   = std::max(best_profit, profit);
        lowest_so_far = std::min(lowest_so_far, prices[i]);
    }
    return best_profit;
}

int main() {
    std::vector<int> prices = {10, 7, 5, 8, 11, 2, 6};
    std::cout << "Max profit: $" << maxProfit(prices) << "\n"; // 6
}
```

## Task #4
```
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

long long highestProduct(const std::vector<int>& nums) {
    if (nums.size() < 2)
        throw std::invalid_argument("Need at least two numbers.");

    int highest  = INT_MIN, second_highest = INT_MIN;
    int lowest   = INT_MAX, second_lowest  = INT_MAX;

    for (int n : nums) {
        // Update top two
        if (n >= highest) { second_highest = highest; highest = n; }
        else if (n > second_highest) { second_highest = n; }

        // Update bottom two
        if (n <= lowest) { second_lowest = lowest; lowest = n; }
        else if (n < second_lowest) { second_lowest = n; }
    }

    long long product_top    = (long long)highest  * second_highest;
    long long product_bottom = (long long)lowest   * second_lowest;
    return std::max(product_top, product_bottom);
}

int main() {
    std::vector<int> nums = {5, -10, -6, 9, 4};
    std::cout << "Highest product: " << highestProduct(nums) << "\n"; // 60  (-10 * -6)
}
```

## Task #5
```
#include <iostream>
#include <vector>

std::vector<double> sortTemperatures(const std::vector<double>& readings) {
    const int MIN_TEMP = 970; // 97.0 * 10
    const int MAX_TEMP = 990; // 99.0 * 10
    const int RANGE    = MAX_TEMP - MIN_TEMP + 1; // 21 buckets

    std::vector<int> counts(RANGE, 0);

    // Count each temperature — O(N)
    for (double t : readings)
        counts[(int)(t * 10 + 0.5) - MIN_TEMP]++;

    // Reconstruct sorted array — O(N + 21) = O(N)
    std::vector<double> sorted;
    sorted.reserve(readings.size());
    for (int i = 0; i < RANGE; ++i)
        for (int c = 0; c < counts[i]; ++c)
            sorted.push_back((MIN_TEMP + i) / 10.0);

    return sorted;
}

int main() {
    std::vector<double> temps = {98.6, 98.0, 97.1, 99.0, 98.9,
                                  97.8, 98.5, 98.2, 98.0, 97.1};
    auto sorted = sortTemperatures(temps);
    std::cout << "Sorted temperatures:\n";
    for (double t : sorted)
        std::cout << "  " << t << "\n";
    // 97.1 97.1 97.8 98.0 98.0 98.2 98.5 98.6 98.9 99.0
}
```

## Task #6
```
#include <iostream>
#include <vector>
#include <unordered_set>

int longestConsecutive(const std::vector<int>& nums) {
    std::unordered_set<int> numSet(nums.begin(), nums.end());
    int best = 0;

    for (int n : numSet) {
        // Only start counting from the beginning of a sequence
        if (numSet.count(n - 1)) continue;

        int length = 1;
        while (numSet.count(n + length))
            ++length;
        best = std::max(best, length);
    }
    return best;
}

int main() {
    std::vector<int> a = {10, 5, 12, 3, 55, 30, 4, 11, 2};
    std::vector<int> b = {19, 13, 15, 12, 18, 14, 17, 11};

    std::cout << "Longest sequence in a: " << longestConsecutive(a) << "\n"; // 4
    std::cout << "Longest sequence in b: " << longestConsecutive(b) << "\n"; // 5
}
```
