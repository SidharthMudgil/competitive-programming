// USER: SIDHARTH MUDGIL
// DATE: Monday 16, Jan 2023
// TASK: 383. Ransom Note

#include <iostream>
#include <map>
#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
        map<char, int> to;
        map<char, int> from;

        for (auto x: ransomNote) {
            to[x]++;
        }

        for (auto x: magazine) {
            from[x]++;
        }

        for (auto x: to) {
            if (from[x.first]) {
                if (from[x.first] < x.second)
                    return false;
            }
            else
                return false;
        }

        return true;        
    }

int main()
{
    cout << canConstruct("fas", "asfagad");
    return 0;
}