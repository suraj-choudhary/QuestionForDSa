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

/*
 int main() {
 int arr[] = {1, 2, 3, 4, 5};
 int size = sizeof(arr) / sizeof(arr[0]);
 roate(arr, size);
 Display(arr, size);
 }
 */


//MARK: First and last occurrences of x(method 1)

vector<int> find(int arr[], int n, int x) {
    int first = -1;
    int last = -1;
    for(int i = 0; i < n; i++) {
        
        if(x != arr[i]) {
            continue;
        }
        if(first == -1) {
            first = i;
        }
        last = i;
    }
    return {first, last};
}

//MARK: First and last occurrences of x(using Binary search):
vector<int>findM(int arr[], int n, int target, bool findStartElement) {
    
    int ans = -1;
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if(target < arr[mid]) {
            end = mid -1;
        } else if(target > arr[mid]) {
            start = mid + 1;
        } else {
            ans = mid;
            if(findStartElement) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    return {ans};
}

/*
 int main() {
     int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
     int size = sizeof(arr) / sizeof(arr[0]);
     findM(arr, size, 5, true);
     
 }

 */


int Maximize(int a[], int n) {
    
    for(int i = 0; i < n - 1; i++) {
        if(a[i] > a[i + 1]) {
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
            i = - 1;
        }
    }
    int sum = -1;
        for(int i = 0; i < n - 1; i++) {
            printf("%d", a[i]);
            sum = sum + a[i];
    }
    printf("%d", sum);
    return 0;
}

/*
 int main() {
     int arr[] = {5, 3, 2, 4, 1};
     int size = sizeof(arr) / sizeof(arr[0]);
     Maximize(arr, size);
     
 }
 */


//MARK: Stack Tutorial:
struct Stack {
    int size;
    int top;
    int *S;
};
void Create(struct Stack *st) {
    printf("Enter size:");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size*sizeof(int));
}

void DisplayStack(struct Stack st) {
    int i;
    for(i = st.top; i >= 0; i--) {
        printf("%d ", st.S[i]);
    }
}

void Push(struct Stack *st, int x) {
    if(st->top == st->size - 1) {
        printf("Stack Overflow\n");
    } else {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st) {
    int x = -1;
    if(st->top == -1) {
        printf("Stack UnderFlow");
    } else {
        x = st->S[st->top--];
    }
    return x;
}


int main() {
    struct Stack st;
    Create(&st);
    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    DisplayStack(st);
    
}
