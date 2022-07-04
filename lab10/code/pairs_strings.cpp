#include "pairs_strings.h"

Strings::Strings(int n, string* Array) : n(n), Array(Array) {}

Iterator Strings::begin() const {
    vector<set<int>> dict = vector<set<int>>(28);
    
    int index;
    for(int i = 0; i < n; i++)
        for(char alph : Array[i]) {
            index = alph - 'a';
            
            if(dict[index].find(i) == dict[index].end())
                dict[index].insert(i);
        }

    vector<vector<string>> result;
    
    bool flag;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            flag = true;

            for(int k = 0; k < 28; k++)
                if((dict[k].find(i) != dict[k].end()) && (dict[k].find(j) != dict[k].end())) {
                    flag = false;
                    
                    break;
                }

            if(flag)
                result.push_back(vector<string> {Array[i], Array[j]});
        }

    return result;
}

Iterator Strings::end() const
{
    return vector<vector<string>> {};
}



Iterator::Iterator(vector<vector<string>> p) : p(p) {}

Iterator::Iterator(const Iterator& it) : p(it.p) {}

bool Iterator::operator!=(Iterator const& it) const
{
    return p.size() != 0;
}

vector<string> Iterator::operator*() const
{

    return p[0];
}

Iterator& Iterator::operator++() {
    vector<vector<string>> new_p;
    for(int i = 1; i < p.size(); i++)
        new_p.push_back(p[i]);      
    p = new_p;
    
    return *this;
}



