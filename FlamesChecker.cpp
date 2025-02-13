#include<bits/stdc++.h>

using namespace std;
int main()
{
    string name1,name2;
    getline(cin,name1);
    getline(cin,name2);
    int freq[26];
    for(int i=0;i<26;i++)
    {
        freq[i]=0;
    }
    for(int i=0;i<name1.size();i++)
    {
        int c=(name1[i]-'a');
        freq[c]++;
    }
    for(int i=0;i<name2.size();i++)
    {
        int c=(name2[i]-'a');
        freq[c]--;
    }
    int count=0;
    for(int i=0;i<26;i++)
    {
        count+=abs(freq[i]);
    }
    int pos=0;
    vector<string> l={"F","L","A","M","E","S"};
     while (l.size() > 1) 
     {
         pos = (pos + count - 1) % l.size(); 
        l.erase(l.begin() + pos);
     }
 if (l[0] == "F") cout << "Friends";
    else if (l[0] == "L") cout << "Lovers";
    else if (l[0] == "A") cout << "Affectionate";
    else if (l[0] == "M") cout << "Marriage";
    else if (l[0] == "E") cout << "Enemies";
    else if (l[0] == "S") cout << "Siblings";
}
