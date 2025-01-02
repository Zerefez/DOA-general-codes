// Author: Martin Bisgaard Elmann Hansen, Date: 23. november 2024
#include "rodCutter.h"
#include <algorithm>
#include <queue>

//

/**
 * @brief Function to calculate the maximum revenue using the greedy approach
 * @param rodLength The total length of the rod to be cut.
 * @return int - The maximum revenue that can be obtained.
 */
int rodCutter::greedyRodCut(int rodLength)
{
    int n = lengthsPrices->size();
    // Priority queue to store {density, index} pairs in descending order of density
    priority_queue<pair<double, int>> pq;

    // Calculate density and store in the priority queue
    for (int i = 0; i < n; i++)
    {
        double density = (double)(*lengthsPrices)[i].second / (*lengthsPrices)[i].first;
        pq.push({ density, i });
    }

    int revenue = 0;

    // Apply greedy strategy
    while (!pq.empty() && rodLength > 0)
    {
        auto top = pq.top(); // Get the element with the highest density
        pq.pop();

        int index = top.second;

        // Cut as many pieces of this length as possible
        while (rodLength >= (*lengthsPrices)[index].first)
        {
            rodLength -= (*lengthsPrices)[index].first;
            revenue += (*lengthsPrices)[index].second;
        }
    }

    return revenue;
}

/**
 * @brief Calculates the maximum revenue using dynamic programming.
 * @param rodLength The total length of the rod to be cut.
 * @return int - The maximum revenue that can be obtained.
 */
int rodCutter::dpRodCut(int rodLength)
{
    vector<int> dp(rodLength + 1, 0);

    // Build the DP table
    for (int i = 1; i <= rodLength; i++)
    {
        for (int j = 0; j < lengthsPrices->size(); j++)
        {
            if ((*lengthsPrices)[j].first <= i)
            {
                dp[i] = max(dp[i], dp[i - (*lengthsPrices)[j].first] + (*lengthsPrices)[j].second);
            }
        }
    }

    return dp[rodLength];
}

/**
 * @brief Calculates the maximum revenue with a fixed cost for each cut using dynamic programming.
 * @param rodLength The total length of the rod to be cut.
 * @param fixedCutCost The fixed cost incurred for each cut.
 * @return int The maximum revenue that can be obtained after considering the fixed cut cost.
 */
int rodCutter::fixedCostBottomUp(int rodLength, int fixedCutCost)
{
    vector<int> dp(rodLength + 1, 0);

    // Build the DP table
    for (int j = 1; j <= rodLength; ++j)
    {
        int maxRevenue = INT_MIN; // Initialize max revenue for length j
        for (int i = 1; i <= j; ++i)
        {
            // Calculate revenue for cutting at length i
            int currentRevenue = (*lengthsPrices)[i - 1].second + dp[j - i];
            if (j != i)
            { // Add cut cost if there's a cut
                currentRevenue -= fixedCutCost;
            }
            maxRevenue = max(maxRevenue, currentRevenue);
        }
        dp[j] = maxRevenue; // Store the best revenue for length j
    }

    return dp[rodLength];
}
