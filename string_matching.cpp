#include <iostream>
#include<vector>
#include<string>
using namespace std;

// 1. Naive/Brute-Force approach
void bruteforce(const string &T,const string &P){
    int n = T.length();
    int m = P.length();
    if (m > n){ cout<<"Wrong lengths inputted"; return;}

    for (int s =0; s <= n-m; s++){
        bool match = true;
        for (int j = 0; j < m ; j++){
            if (T[s+j] != P[j]){
                match = false;
                break;
            }
        }
        if (match) {cout<< "Valid shift: "<<s<<endl;
            for (int i = s; i < m; i++) cout<<T[i];}
        
    }
}

// 2. Rabin-Karp Algorithm
void RabinKarp(const string &T,const string &P,int d, int q){
    int hashT= 0;
    int hashP= 0;
    int h= 0;

    for (int i =0; i< P.length()-1; i++){
        h = (h*d)%q;
    }
    for (int i = 0; i < P.length(); i++){
        hashP = (d*hashP + P[i] - 'a')%q;
        hashT = (d*hashT + T[i] - 'a')%q;
    }

    for (int s = 0; s <= T.length()-P.length(); s++){
        if (hashP == hashT){
            bool match =true;
            for (int i =0 ; i< T.length(); i++){
                if (T[s+i] != P[i]){
                        match = false;
                        break;
                }
            }
            if (match) cout<<s<<endl;
        }
    }
}

// KMP Algorithm
vector<int> computeLPS(string P){
    vector<int> result (P.size(), 0);
    int len = 0;

    for (int i=1; i <P.size(); ){
        if (P[i] == P[len]){
            len++;
            result[i] = len;
            i++;
        }
        else{
            if (len != 0){
                len = result[len-1];
            }
            else{
                result[i] = 0;
                i++;
            }
        }
    }
    return result;
}

void KMP(string T,string P){}

int main() {
    bruteforce("This is a test text","test");
    return 0;
}
