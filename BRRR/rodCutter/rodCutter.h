// Author: Martin Bisgaard Elmann Hansen, Date: 23. november 2024
#pragma once
#include <vector>
using namespace std;

class rodCutter
{
private:
    vector<pair<int, int>>* lengthsPrices;

public:
    rodCutter(vector<pair<int, int>>& lengthsPrices) : lengthsPrices(&lengthsPrices) {}
    int greedyRodCut(int rodLength);
    int dpRodCut(int rodLength);
    int fixedCostBottomUp(int rodLength, int fixedCutCost);
};
