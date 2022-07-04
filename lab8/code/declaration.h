#include <iostream>
#include <vector>
#include <math.h>
 
using namespace std;
 
template<typename T>
class polygon {
    private:
        T M;
        vector<vector<T>> poly;
        
    public:
        polygon(T M, vector<vector<T>> poly) {
            this->M = M;
            this->poly = poly;
        }
 
        T getM() {
            return this->M;
        }
 
        void pushPoint(vector<T> a) {
            poly.push_back(a);
        }
 
        void popPoint(T index) {
            for(int i = index; i < (poly.size() - 1); i++)
                poly[i] = poly[i + 1];
            
            poly.pop_back();
        }
 
        double makeLen(vector<T> a) {
            double res;
            int sum = 0;
            
            for(int i = 0; i < a.size(); i++)
                sum += pow(a[i], 2);

            res = sqrt(sum);
            
            return res;
        }
 
        T Square() {
        	if(poly.size() == 4) {
	            T res = 0;
	            vector<T> a = poly[0];
	            vector<T> b = poly[1];
	            vector<T> c = poly[2];
	            
	            vector<T> buf = vector<T>(M);
	            vector<T> buf2 = vector<T>(M);
	            
	            for(int j = 0; j < M; j++)
	                buf[j] = b[j] - a[j];
	            
	            for(int j = 0; j < M; j++)
	                buf2[j] = c[j] - b[j];
	            
	            res = makeLen(buf) * makeLen(buf2);
	            
	            if((poly.size() == 4) && (M == 2) && 
					((a[0] == b[0]) && (b[1] == c[1]) || 
						((a[1] == b[1]) && (b[0] == c[0]))))
	                return res;
	            else {
	                cout << "Can't calculate, so: ";
	                
	                return 0;
	            }
	        }
	        else {
                cout << "Can't calculate, so: ";
                
                return 0;
	        }
        }
 
        double Perimeter() {
            double res = 0;
            if(poly.size() - 1 >= 2) {
	            for(int i = 0; i < (poly.size() - 1); i++) {
	                vector<T> a = poly[i];
	                vector<T> b = poly[i + 1];
	                
	                vector<T> buf = vector<T>(M);
	                
	                for(int j = 0; j < M; j++)
	                    buf[j] = b[j] - a[j];
	                
	                res += makeLen(buf);
	            }
	            
	            vector<T> a = poly[poly.size()-1];
	            vector<T> b = poly[0];
	            vector<T> buf = vector<T>(M);
	            
	            for(int j = 0; j < M; j++)
	                buf[j] = b[j] - a[j];
	            
	            res += makeLen(buf);
	            return res;
	    	}
	        else
	        	return 0;
        }
        
        void show() {
            for(int i = 0; i < poly.size(); i++) {
                for(int j = 0; j < M; j++)
                    cout << poly[i][j] << " ";
                
                cout << endl;
            }
            
            cout << "==============" << endl;
        }
        
};
