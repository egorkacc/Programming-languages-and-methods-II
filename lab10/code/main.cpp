#include "pairs_strings.cpp"
#include <iostream>

int main() {
    string* Arr = new string[10] {"arbuz", "kot", "sobaka", "povar", 
		"yaimpe", "bbbbbbb", "rarara", "rince", "furniture", "bully"};
				
    Strings newArr(10, Arr);
    
    for(auto element : newArr)
        cout << element[0] << ' ' << element[1] << endl;
        
    delete[] Arr;
    
    return 0;
}
