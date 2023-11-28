#include <vector>
#include <string>
using namespace std;


int strStr(string haystack, string needle) {
    int i, j;
    for (i = 0; i < haystack.size(); i++) {
        int counter;
        j = i;
        for (counter = 0; counter < needle.size(); counter++) {
            if (haystack[j] == needle[counter])
                j++;
            else
                break;
        }
        if (counter == needle.size())
            return i;
    }
    return -1;
}