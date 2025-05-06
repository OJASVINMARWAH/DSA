#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. activity selection 
bool compare(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}
vector<pair<int,int>> ActivitySelection(vector<pair<int,int>> inp){
    //  sort the activities by their finish time 
    sort(inp.begin(),inp.end(),compare);
    int currtime = 0;
    vector<pair<int,int>> result; // answer with sequence
    for (int i = 0; i< inp.size(); i++){
        if (inp[i].first >= currtime){
            currtime = inp[i].second;
            result.push_back(inp[i]);
        }
    }
    return result;
}

// 2. Fractional Knapsack
class item{
    public:
    int profit;
    int wt;
};

bool compare2(item a, item b){
    return ((double) a.profit / a.wt) > ((double) b.profit / b.wt);
}

int FractionalKS(vector<item> input, int capacity){
    sort(input.begin(), input.end(), compare2);
    int remaining = capacity;
    int profitSoFar = 0;

    for (int i = 0; i < input.size(); i++){
        if (remaining >= input[i].wt){
            remaining -= input[i].wt;
            profitSoFar += input[i].profit;
            continue;
        }
        profitSoFar += (input[i].profit * remaining) / (double)input[i].wt;
        break; //once the bag is full, exit the loop otherwise it will keep on adding the profit for the subsequent items
    }
    return profitSoFar;
}

// 3. JOB SEQUENCING PROBLEM
typedef struct job{
    int profit;
    int deadline;
}job;

bool compare3(job j1, job j2){
    return (j1.profit > j2.profit);
}

int JobSelection(vector<job> input){  // returns the maxm profit
    sort(input.begin(), input.end(), compare3);
    int maxm = 0;
    for (auto i : input){
        if (maxm < i.deadline){
            maxm = i.deadline;
        }
    }
    vector<bool> occupied (maxm,0);

    int ProfitSoFar = 0;

    for (int i = 0; i < input.size(); i++){
        if (occupied[input[i].deadline] == 0){
            occupied[input[i].deadline]  = 1;
            ProfitSoFar += input[i].profit;
            continue;
        }
        int indx = i;
        while (occupied[input[indx].deadline] != 0){
            indx -- ;
        }
        if (indx <= -1) continue;
        else{
            occupied[input[indx].deadline]  = 1;
            ProfitSoFar += input[indx].profit;
        }
    }
    return ProfitSoFar;
}



// minimum number of platforms problem
int minPlatforms(vector<int> arrival,vector<int> departure){
    int maxP = 0;
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(),departure.end());
    int p =0;
    for (int i = 0, j =0; i < arrival.size() and j < departure.size();){
        if (arrival[i] <= departure[j]){
            p++;
            maxP = max(p, maxP);
            i++;
        }
        else{
            p--;
            j++;
        }
    }
    return maxP;
}

// coin exchange problem
vector<int> coinExchange(vector<int> input, int amount){
    sort(input.begin(), input.end(), greater<int>());  // sorted in descending order
    vector<int> result;
    int i =0;
    while (amount>0 and i < input.size()){
        if (amount >= input[i]){
            amount-= input[i];
            result.push_back(input[i]);
        }
        else{
            i++;
        }
    }
    return result;
}

// Gas Station / Circular Tour Problem
// Greedy Strategy: Find a starting point that completes the loop.

int main() {
    return 0;
}
