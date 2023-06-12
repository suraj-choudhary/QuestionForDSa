//
//  main.cpp
//  dsa
//
//  Created by suraj kumar on 08/06/23.
//
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

//MARK: Started solving love bubber sheet
using namespace std;
//MARK: Value equal to index value 1--

vector<int> valueEqualToIndex(int arr[], int size) {
    
    vector<int>res;
    
    for(int i = 0; i < size; i++) {
        if(arr[i] == i + 1) {
            res.push_back(arr[i]);
        }
    }
    return res;
    
}

/*
 int main() {
     int arr[] = {15, 2, 45, 12, 7};
     int size = sizeof(arr) / sizeof(arr[0]);
     valueEqualToIndex(arr, size);
 }

 */


//MARK: Palindromic Array 2----

int PalinArray(int a[], int n) {
    
    for(int i = 0; i < n; i++) {
        int temp = a[i];
        int rev = 0;
        while (temp > 0) {
            int rem = temp % 10;
            rev = rev * 10 + rem;
            temp = temp / 10;
        }
        if(rev != a[i]) {
            return 0;
        }
    }
    return 1;
}

//MARK: Method 2 for Palindromic array:

bool isPalindromic(int n) {
   
    string str = to_string(n);
    
    long len = str.size();

    for(int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int isPalindromicArray(int arr[], int n) {

    for(int i = 0; i < n; i++) {
        bool ans = isPalindromic(arr[i]);
        if(ans == false ) {
            return 0;
        }
    }
    return 1;
}

/*
 int main() {
     int arr[] = {111, 222, 333, 444, 555};
     int size = sizeof(arr) / sizeof(arr[0]);
     isPalindromicArray(arr, size);
 }

 */
//MARK: Cyclically rotate an array by one


void Display(int arr[] , int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void roate(int arr[], int n) {
    int last = arr[n - 1];
    for(int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
    
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    roate(arr, size);
    Display(arr, size);
}



//MARK: First and last occurrences of x

