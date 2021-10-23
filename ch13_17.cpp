//
//  main.cpp
//  ch13_ex17
//
//  Created by Phil Huffman on 8/29/21.
//

#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<string> results;
    unsigned long seed = chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen (static_cast<unsigned>(seed));
    uniform_real_distribution<double> distr(10.0, 100.0);
    stringstream sst;
    sst.fill('0');
    
    while (results.size() < 25) {
        sst.seekp(0) << fixed << setprecision(2) << setw(5) << distr(gen);
        results.push_back(sst.str());
    }
    
    cout << endl;
    sort(results.begin(), results.end());
    int cntr(0);
    
    for (auto result : results) {
        cout << result << (++cntr % 5 == 0 ? '\n' : ' ');
    }
    cout << endl;
    return 0;
}
