#include <bits/stdc++.h>
#include "trieClass.h"
using namespace std;

// 1 IMPLIMENT suffix tries
// 2 IMPLIMENT compress tries
//  int main()
//  {
//      Tries trie;
//      string arr[] = {"cat", "dog", "bat", "car", "cart", "carton", "apple", "orange", "banana", "a","b","c", "be", "bee", "beer", "share", "shire", "shore"};

//     for (int i = 0; i < 18; i++)
//     {
//         trie.insert(arr[i]);
//     }
//     cout << trie.search("dog") << endl;
//     cout << trie.search("car") << endl;
//     cout << trie.search("apple") << endl;
//     cout << trie.search("a") << endl;
//     trie.deleta("car");
//     cout << trie.search("shire") << endl;
//     cout << trie.search("bee") << endl;
//     cout << trie.search("fucking") << endl;
//     cout << trie.search("car") << endl;

// }

// int main()
// {
//     Tries trie;
//     trie.insertFORCE("abc");
//     trie.insertFORCE("def");
//     trie.insertFORCE("ghi");
//     trie.insertFORCE("cba");

//     cout << trie.pattern("hif");
// }

// Problem Statement: Auto complete
int main()
{
    Tries trie;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        trie.insert(s);
    }
    cin >> s;
    vector<string> vc=trie.autoComplete(s);
    for (int i = 0; i < vc.size(); i++)
        cout<<vc[i]<<endl;
    // cout << trie.search("dont") << trie.search("no") << trie.search("not") << trie.search("notes") << trie.search("den");
}

// 7
// do dont no not note notes den
// no