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

//��������� ��� �������� ��� ���������� ��� ������.

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


//���� ������� ��������� ���� ������ � ������ ����� �������������.
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


/*���������� ��� ��������� ��� ��������� �� �������� ��� ����������.*/
int Sorted::binarySearch(string arr[], int l, int r, string x)
{
    if (r < l)
        return -1;

    int mid = l + (r - l) / 2;

    //�� �� �������� ������� ���� ���� �� ������������
    if (arr[mid] == x)
        return mid;

    //����������� �� ����� ��������� � ���������� ��� ������� ���� �������� ��������� ��� �� ������� ��� ����.
    if (arr[mid] > x)
        return binarySearch(arr, l, mid - 1, x);

    return binarySearch(arr, mid + 1, r, x);
}

/*��������� ��� �������� ��� ������� ���������.�������� ��� binarySearch ��� �� ����� ��� ���� ��� ��������� ��� ����������.*/
int Sorted::countOccurrences(string arr[], int n, string x)
{
    int ind = binarySearch(arr, 0, n - 1, x);

    if (ind == -1)
        return 0;


    //������� �� ������ ��� �� �������� ��������.
    int count = 1;
    int left = ind - 1;
    while (left >= 0 && arr[left] == x)
        count++, left--;


    //������� �� ������ ��� �� �������� �����.
    int right = ind + 1;
    while (right < n && arr[right] == x)
        count++, right++;

    return count;
}
















