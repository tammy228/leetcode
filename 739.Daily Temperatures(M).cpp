#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int stack[250] = { 0 };
    int pos = 0;
    vector<int> ans (temperatures.size(), 0);
    stack[pos] = temperatures.size() - 1;
    for (int i = temperatures.size()- 2; i >= 0; i--)
    {
        while(pos >= 0 && temperatures[stack[pos]] <= temperatures[i])
        {
            pos--;
        }
        if (pos > -1) ans[i] = stack[pos] - i;
        stack[++pos] = i;
    }
    return ans;
}