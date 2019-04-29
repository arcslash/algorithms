#include <iostream>
#include <cmath>
#include <string>


using namespace std;


int karatsuba(string x, string y);
string add(string v1, string v2);

int main(int argc, char *argv[]){
    string num1 = "3141592653589793238462643383279502884197169399375105820974944592";
    string num2 = "2718281828459045235360287471352662497757247093699959574966967627";
    // int size_num1 = sizeof(num1) - 1;
    // int size_num2 = sizeof(num2) - 1;

    // char xm[(size_num1 + size_num2)/2];
    // char ym[(size_num1 + size_num2) - (sizeof(xm) - 1)];
    num1 = "2532";
    num2 = "4499";
    cout << "len num1:" << num1.length() << endl;
    cout << "len num2:" << num2.length() << endl;
    //cout<<"Karatsuba:"<<karatsuba(num1,num2)<<endl;
    cout <<"eeeeee:" <<add("50","55")<< endl;
   
    
    return 0;
}
string add(string v1, string v2){
    char ret[] = 'aa';
    for(int i=0;i < max(v1.length(), v2.length());i++){       
        ret[i] = atoi(v1[i]) + atoi(v2[i]);

    }
    return ret;

}

int karatsuba(string x, string y){
    
    //cout << "len_x:" << x.length() << "    len_y:" << y.length() << endl;
    string xl = x.substr(0, x.length()/2);
    string xr = x.substr(x.length()/2, x.length());
    string yl = y.substr(0, y.length()/2);
    string yr = y.substr(y.length()/2, y.length());

    int len_max = max(x.length(),y.length());
    if(len_max != 2){
        
        int a = karatsuba(xl, yl);
        int d = karatsuba(xr, yr);
        int e = karatsuba(add(xl , xr) , add(yl , yr)) - a - d;
        int ans = a * pow(10, len_max) + e * pow(10, len_max/2) + d;
        return ans;
        

    }else{
        //end case here
        int a = stoi(xl) * stoi(yl);
        int d = stoi(xr) * stoi(yr);
        int e = (stoi(xl) + stoi(xr)) * (stoi(yl) + stoi(yr)) - a - d;
        int ans = a * pow(10, len_max) + e * pow(10, len_max/2) + d;
        return ans;
    }

    


    

}
