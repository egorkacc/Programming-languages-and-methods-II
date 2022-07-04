#include <iterator>
#include <vector>
#include <set>

using namespace std;

class Iterator;

class Strings {
	private:
	    int n;
	    string* Array;
	    
	public:
	    Strings(int, string*);
	    typedef Iterator const_iterator;
	    const_iterator begin() const;
	    const_iterator end() const;
	};

class Iterator: public iterator<forward_iterator_tag, const string> {
    friend class Strings;
	private:
	    Iterator(vector<vector<string>> p);
	    vector<vector<string>> p;
	    
	public:
	    Iterator(const Iterator&);
	    bool operator!=(Iterator const&) const;
	    
	    vector<string> operator*() const;
	    Iterator& operator++();
};
