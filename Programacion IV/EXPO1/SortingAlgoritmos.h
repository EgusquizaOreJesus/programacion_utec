//
// Created by USER on 08/04/2023.
//

#ifndef EXPOSICION_SORTINGALGORITHM_H
#include <vector>
#define ll long long ;
void counting_sort(std::vector<int> & a )
{
    int max=a[0];
    int size=a.size();
    for (int i = 1; i < size; ++i) { //O(n)
        if(max < a[i])
            max=a[i];
    }
    //Parte Principal Counting Sort
    std::vector<int> frequency_array(max + 1);
    for (int i = 0; i < max+1; ++i) {//O(k)
        frequency_array[i]=0;
    }
    for (int i = 0; i < size; ++i) { //O(n)
        frequency_array[a[i]]++;
    }
    std::vector<int> ord_array(size);
    for (int i = 1; i < max+1; ++i) //O(k)
        frequency_array[i]= frequency_array[i] + frequency_array[i - 1];
    for (int i = 0; i < size; ++i) { //O(n)
        ord_array[frequency_array[a[i]] - 1]=a[i];
        frequency_array[a[i]]--;
    }

    std::copy(ord_array.begin(), ord_array.end(), a.begin()); //O(n)

}
void selection_sort(std::vector<int> & arr )
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        std::swap(arr[i], arr[min_idx]);

    }

}


#endif //EXPOSICION_SORTINGALGORITHM_H
