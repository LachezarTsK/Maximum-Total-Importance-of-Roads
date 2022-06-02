
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
    
public:
    long long maximumImportance(int numberOfCities, vector<vector<int>>& roads) {
        vector<long long> connections(numberOfCities);
        for (const auto& road : roads) {
            ++connections[road[0]];
            ++connections[road[1]];
        }
        sort(connections.begin(), connections.end());
        long long cityValue = 0;
        
        transform(begin(connections), end(connections), begin(connections), [&](long cityConnections) {return (cityConnections) * (++cityValue);});
        return accumulate(begin(connections), end(connections), static_cast<long long> (0));
    }
};
