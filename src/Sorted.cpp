#include "Sorted.h"
#include <iostream>
#include <cstring>
#include <string>
#include <bits/stdc++.h>

using namespace std;

Sorted::Sorted()
{

}

Sorted::~Sorted()
{

}

//συναρτηση που υλοποιει την ταξινομηση του πινακα.

void Sorted::sortw(string arr[], int n)
{
    int i, j;
    string key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


//Απλη αναζητη στοιχειου στον πινακα ο οποιος ειναι ταξινομημενος.
int Sorted::Search(string d)
{
    counter=0;
    for(int j=0;j<i;j++)
    {

        if(d==p[j])
            counter++;
    }
    return counter;
}


/*επιστρεφει την τοποθεσια που βρισκεται το στοιχειο που αναζητουμε.*/
int Sorted::binarySearch(string arr[], int l, int r, string x)
{
    if (r < l)
        return -1;

    int mid = l + (r - l) / 2;

    //αν το στοιχειο υπαρχει στην θεση το επιστρεφουμε
    if (arr[mid] == x)
        return mid;

    //διαφορετικα θα ειναι μικροτερο η μεγαλυτερο και κανουμε τους ελεγχους διαδοχηκα για να παρουμε την θεση.
    if (arr[mid] > x)
        return binarySearch(arr, l, mid - 1, x);

    return binarySearch(arr, mid + 1, r, x);
}

/*συναρτηση που υλοποιει την διαδικη αναζητηση.Καλοντας την binarySearch για να παρει την θεση του στοιχειου που αναζητουμε.*/
int Sorted::countOccurrences(string arr[], int n, string x)
{
    int ind = binarySearch(arr, 0, n - 1, x);

    if (ind == -1)
        return 0;


    //Μετραμε το πληθος απο τα στοιχεια αριστερα.
    int count = 1;
    int left = ind - 1;
    while (left >= 0 && arr[left] == x)
        count++, left--;


    //Μετραμε το πληθος απο τα στοιχεια Δεξια.
    int right = ind + 1;
    while (right < n && arr[right] == x)
        count++, right++;

    return count;
}
















