# -*- coding: utf-8 -*-
"""
Created on Sun Apr 15 14:20:55 2018

@author: chema
"""

def read_integers(filename):
    with open(filename) as f:
        return [int(x) for x in f]

#Returns the list A where A[i] < p where i < idx(p) and A[j] > p where j > idx(p)
def partition(A, lo, hi):
    #Implementation with pivot = first element (Worst case in case of already sorted array O(n^2))
    #TODO: Compare and change with random pivot.
    p = A[lo]
    i = lo + 1
    for j in range(lo+1,hi):
        if A[j] < p:
            #Swap A[i] with A[j]
            tmp = A[i]
            A[i] = A[j]
            A[j] = tmp
            #Increment i (the "fence")
            i = i + 1
    
    #Swap element of pivot for i-1 element
    tmp = A[i-1]
    A[i-1] = p
    A[lo] = tmp
    
    return i-1 #return idx of Pivot element

def quicksort(A, lo, hi):
    if lo < hi:
        global comparisons
        comparisons = comparisons + hi - lo - 1
        idxPivot = partition(A, lo, hi)
        quicksort(A, lo, idxPivot)
        quicksort(A, idxPivot+1, hi)

vector = read_integers("D:/Stanford-Algorithms/QuickSort/QuickSort.txt")
print(vector)

comparisons = 0
quicksort(vector, 0, len(vector))
print(comparisons)