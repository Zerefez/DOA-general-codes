// Author: Martin Bisgaard Elmann Hansen, Date: 23. november 2024
#include <iostream>
#include "rodCutter.h"

int main()
{
    // Lengths and prices (counterexample)
    vector<pair<int, int>> lengthsPrices = { {1, 1}, {2, 7}, {3, 8}, {4, 9} };
    rodCutter cutter(lengthsPrices);
    int rodLength = 4;

    // Calculate revenue using greedy approach
    int greedyRevenue = cutter.greedyRodCut(rodLength);
    cout << "Greedy Revenue: " << greedyRevenue << endl;

    // Calculate revenue using dynamic programming (optimal solution)
    int optimalRevenue = cutter.dpRodCut(rodLength);
    cout << "Optimal Revenue: " << optimalRevenue << endl;

    // Calculate revenue using dynamic programming with fixed cost
    int fixedCost = 1;
    int fixedCostRevenue = cutter.fixedCostBottomUp(rodLength, fixedCost);
    cout << "Fixed Cost Revenue: " << fixedCostRevenue << endl;

    return 0;
}