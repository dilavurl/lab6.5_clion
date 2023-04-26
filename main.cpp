#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

int* findCommonElements(int arr1[], int n1, int arr2[], int n2, int& nResult) {

    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);

    int* result = new int[n1];

    int i = 0;
    int j = 0;
    nResult = 0;

    while (i < n1 && j < n2) {

        if (arr1[i] == arr2[j]) {
            result[nResult] = arr1[i];
            nResult++;
            i++;
            j++;
        }

        else if (arr1[i] < arr2[j]) {
            i++;
        }

        else {
            j++;
        }
    }

    result = (int*) realloc(result, nResult * sizeof(int));

    return result;
}

//q2

bool isPalindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

void palindromeFilter(string arr[], int size) {
    for (int i = 0; i < size; i++) {
        string s = arr[i];
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (isPalindrome(s)) {
            cout << arr[i] << " ";
        }
    }
}

//q3

void sieveOfEratosthenes(int arr[], int size) {

    bool isPrime[size];
    for (int i = 0; i < size; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i * i <= size; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= size; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (isPrime[i] && arr[i] > 1) {
            cout << arr[i] << " ";
        }
    }
}

//q4

bool areAnagrams(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}
list<string> findAnagrams(string word, list<string> word_list) {
    list<string> anagrams;
    string sorted_word = word;
    transform(sorted_word.begin(), sorted_word.end(), sorted_word.begin(), ::tolower);
    sort(sorted_word.begin(), sorted_word.end());
    for (string w : word_list) {
        string sorted_w = w;
        transform(sorted_w.begin(), sorted_w.end(), sorted_w.begin(), ::tolower);
        sort(sorted_w.begin(), sorted_w.end());
        if (areAnagrams(sorted_word, sorted_w)) {
            anagrams.push_back(w);
        }
    }
    return anagrams;
}


int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = 5;
    int arr2[] = {3, 4, 5, 6, 7};
    int n2 = 5;
    int nResult = 0;
    int* common = findCommonElements(arr1, n1, arr2, n2, nResult);
    for (int i = 0; i < nResult; i++) {
        cout << common[i] << " ";
    }
    cout << endl;

    delete[] common;

    //q2

    string arr[] = {"racecar", "hello", "deified", "world"};
    int size = sizeof(arr) / sizeof(arr[0]);
    palindromeFilter(arr, size);

    //q3

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size1 = sizeof(arr) / sizeof(arr[0]);
    sieveOfEratosthenes(array, size1);

    //q4

    string word = "listen";
    list<string> word_list = {"enlists", "google", "inlets", "banana"};
    list<string> anagrams = findAnagrams(word, word_list);
    for (string s : anagrams) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
