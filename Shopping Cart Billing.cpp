#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int findLowestPrice(vector<vector<string>> products, vector<vector<string>> discounts){
    int total = 0;
    unordered_map<string, pair<int, int>> map;
    unordered_map<string, pair<int, int>>::iterator it;
    for(int i=0; i<discounts.size(); i++){
        map[discounts[i][0]] = {stoi(discounts[i][1]), stoi(discounts[i][2])};
    }
    for(int i=0; i<products.size(); i++){
        int money = stoi(products[i][0]);
        vector<string> dis;
        for(int k=1; k<products[i].size(); k++){
            dis.insert(dis.end(), products[i][k]);
        }
        vector<int> dis_moneys;
        for (int j = 0; j < dis.size(); j++) {
            it = map.find(dis[j]);
            if (it != map.end()) {
                pair<int, int> value = it->second;
                if (value.first == 0)
                    dis_moneys.push_back(value.second);
                if (value.first == 1)
                    dis_moneys.push_back(round(money - money * value.second / 100));
                if (value.first == 2)
                    dis_moneys.push_back(money - value.second);
            }
        }

        if(dis_moneys.empty())
            total += money;
        else
            total += *min_element(dis_moneys.begin(), dis_moneys.end());
    }
    return total;
}
//int main(){
//    vector<vector<string>> products = {{"10", "sale", "january-sale"}, {"15", "EMPTY", "EMPTY"}, {"20", "january-sale", "EMPTY"}};
//    vector<vector<string>> discounts = {{"sale", "1", "27"}, {"january-sale", "2", "5"}};
//    int ans = findLowestPrice(products, discounts);
//    cout << ans << endl;
//}


