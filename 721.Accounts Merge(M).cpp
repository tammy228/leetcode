#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
/*
 * Optimize
 * 要用union find 的方法
 * 由於名字有可能會一樣，所以這裡先把名字替代成ID , 之後再轉成名字
 * 最終要得到各個不同的account 且其email 要sorted
 *   - emailToId<string, int> //每個email 屬於哪個ID
 *       1. 先假設每一個name 都是不同人(即便with same name), 每個人都有一個ID，找出每個email 屬於誰
 *       2. 如果有common email(已就是再map 已出現過), 則更新parent Ex:( parent 1 號, 跟parent 2 號 是同一個人)
 *       3. 根據上面的map 建立一個新的account(map<int, vector<string>>) , 此時的account 就已經把有common email 都merge 再一起了
 *           1. 透過find(x) 知道每個email 最終是屬於誰，去做新account 的建立
 *       4. iterate 新account 把ID 轉成 name 放進ans 裡面
 *   Time: find-> O(1), make_union-> O(1), iterate account-> O(NM), iterate map-> O(M),
 *   where N is how many names, M is how many emails
 *   Total O(NM)
 *   Space: O(M)
 */
int find(int x, vector<int>& parent)
{
    if(parent[x] != x)
        return parent[x] = find(parent[x], parent);
    else
        return x;
}
void make_union(int x, int y, vector<int>& parent)
{
    int p1 = find(x, parent);
    int p2 = find(y, parent);

    if (p1 != p2)
        parent[p1] = p2;
}
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    // init length of account, and set each element as its own parent
    vector<int>parent(accounts.size());
    for(int i=0;i<accounts.size();i++)
        parent[i]=i;

    unordered_map<string, int> emailToId;
    for(int i=0; i<accounts.size(); i++)
    {
        for(int j=1; j<accounts[i].size(); j++)
        {
            if(emailToId.count(accounts[i][j]))
                make_union(i, emailToId[accounts[i][j]], parent);
            else
                emailToId[accounts[i][j]] = i;
        }
    }

    unordered_map<int, vector<string>> newAccounts;
    for(auto it : emailToId)
    {
        int leader = find(it.second, parent);
        newAccounts[leader].push_back(it.first);
    }

    vector<vector<string>> ans;
    for(auto it: newAccounts)
    {
        string name = accounts[it.first][0];
        vector<string> emails = it.second;
        sort(emails.begin(), emails.end());
        emails.insert(emails.begin(), name);
        ans.push_back(emails);
    }
    return ans;
}