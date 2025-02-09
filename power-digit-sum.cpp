//Author: Geoffrey Duan
//Date: Feb 1, 2025
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <string> 
#include <cassert>
using namespace std;

unsigned long long pow(int a,int b){
    // if both numbers are valid, initial result is 1, the power of two digits is the product of two digits. 
    long long result = 1;
    while(b != 0){
    result = result * a;
    b--; 
    }
    return result;
}


int digitSum(long long num){
    int digit;
    if (num == 0){
        return 0;
    }
    else{
        /*
         https://stackoverflow.com/questions/5590381/how-to-convert-int-to-string-in-c
         https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
         I got help from these two websites to learn how to convert integer to string and character to digits.
         This program iterates through digits of a string number and sums the digits. 
         */
         int sum = 0;
        string str = to_string(num);
        int len = str.length();
        for (int i = 0; i < len; i++){
            digit = str[i] - '0';
            sum = sum + digit;
        }
        return sum;
    }
}

bool isInteger(string num) {
    for(int i = 0; i < num.length(); i++){
        if(!isdigit(num[i])){
            if(num[i] == '.'){
                cout << "input is floating point number" << endl;
                return false;
            }
            if(isalpha(num[i])){
                cout << "input contains a character" << endl;
                return false;
            }
        }
    }
    return true;
}

int bail(string a, string b){
	cout << "Invalid inputs  a: " << a << "   b: " << b << endl;
	cout << "a and b must be non-negative integers." << endl;
	return 1;
}

vector<int> vectorize_digits(unsigned long long n){
    int digit = 0;
    string strNum = to_string(n);
    vector<int> digitVector;
    for (int i = 0; i < strNum.length(); i++){
        digitVector.push_back(strNum[i] - '0');
    }
    return digitVector;
}

int sum_vector(vector<int> v){
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum = sum + v[i];
    }
    return sum;
}

string vec_to_string(vector<int> vec){
    string result = ""; 
    for (int i = 0; i < vec.size(); i++){
        result += to_string(vec[i]);
    }
    return result;
}

void tests(){
    assert(pow(3, 4) == 81);
    assert(digitSum(81) == 9);
    assert(pow(5, 0) == 1);
    assert(pow(0, 0) == 1);  
    assert(static_cast<unsigned long long>(pow(1, 100000) == 1)); 
    assert(isInteger("134314134") == true);
    assert(isInteger("5.5") == false);
    assert(isInteger("faega") == false);
    assert(digitSum(5555555) == 35);  

    
	cout << "All Tests Passed!" << endl;
}



int main(){
    tests();
    string a,b;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    int base, exp;
    if(isInteger(a) && isInteger(b)){
        try{
		int base = stoi(a);
		int exp = stoi(b);
        cou