#include "declaration.h"

void points_arythm(int n, int M);

int main() {
	
    int M, n;
    cout << "Enter the dimension value: ";
    cin >> M;
    cout << "Enter the number of input points: ";
    cin >> n;
    cout << endl;
    
    points_arythm(n, M); 
}

void points_arythm(int n, int M) {
		vector<vector<int>> a = vector<vector<int>>(n);
        	
    	for(int i = 0; i < n; i++) {
	        for(int j = 0; j < M; j++) {
	            int coord;
	            if(!((i >= 9) && (i <=19) && (j >= 9) && (j <=19)))
		            if(i%10 == 0)
		            	if(j%10 == 0)
				            cout << "Enter the " << j+1 << "-st coordinate of " << 
								i+1 << "-st point: ";
						else if(j%10 == 1)
							cout << "Enter the " << j+1 << "-nd coordinate of " << 
								i+1 << "-st point: ";
						else if(j%10 == 2)
							cout << "Enter the " << j+1 << "-rd coordinate of " << 
								i+1 << "-st point: ";
						else
							cout << "Enter the " << j+1 << "-th coordinate of " << 
								i+1 << "-st point: ";
					else if(i%10 == 1)
		            	if(j%10 == 0)
				            cout << "Enter the " << j+1 << "-st coordinate of " << 
								i+1 << "-nd point: ";
						else if(j%10 == 1)
							cout << "Enter the " << j+1 << "-nd coordinate of " << 
								i+1 << "-nd point: ";
						else if(j%10 == 2)
							cout << "Enter the " << j+1 << "-rd coordinate of " << 
								i+1 << "-nd point: ";
						else
							cout << "Enter the " << j+1 << "-th coordinate of " << 
								i+1 << "-nd point: ";
					else if(i%10 == 2)
		            	if(j%10 == 0)
				            cout << "Enter the " << j+1 << "-st coordinate of " << 
								i+1 << "-rd point: ";
						else if(j%10 == 1)
							cout << "Enter the " << j+1 << "-nd coordinate of " << 
								i+1 << "-rd point: ";
						else if(j%10 == 2)
							cout << "Enter the " << j+1 << "-rd coordinate of " << 
								i+1 << "-rd point: ";
						else
							cout << "Enter the " << j+1 << "-th coordinate of " << 
								i+1 << "-rd point: ";
					else
		            	if(j%10 == 0)
				            cout << "Enter the " << j+1 << "-st coordinate of " << 
								i+1 << "-th point: ";
						else if(j%10 == 1)
							cout << "Enter the " << j+1 << "-nd coordinate of " << 
								i+1 << "-th point: ";
						else if(j%10 == 2)
							cout << "Enter the " << j+1 << "-rd coordinate of " << 
								i+1 << "-th point: ";
						else
							cout << "Enter the " << j+1 << "-th coordinate of " << 
								i+1 << "-th point: ";
				else
					cout << "Enter the " << j+1 << "-th coordinate of " << 
							i+1 << "-th point: ";
							
				cin >> coord;
	            
	            a[i].push_back(coord);		            
	        }
	        cout << endl;
	    }
    cout << endl;
    
    polygon<int> poly(M, a);
    
    cout << "The perimeter is: " << poly.Perimeter() << endl;
    cout << "The square is: " << poly.Square() << endl;
    
    vector<int> test = vector<int>(M);
    cout << "Add the testing point of " << M << " coordinates: ";
    for(int i = 0; i < M; i++)
        cin >> test[i];
 
    poly.pushPoint(test);
    poly.show();
    cout << "The square is: " << poly.Square() << endl;
    
    poly.popPoint(2);
    poly.show();
    cout << poly.Perimeter() << endl; 
	}
