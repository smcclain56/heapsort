/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author: 
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"


/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void heapSort(struct Employee *A, int n)
{
	//BuildHeap on the list
	buildHeap(A,n);
	
	//while n > 0 swap A[n-1] with A[0], since A[0] is the smallest number.
	int i;
	for(i=n-1; i>= 0; i--){
		swap(&A[i], &A[0]);
		//heapify elements from A[0] to A[n-1]
		heapify(A,0,i);
	}
}


/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void buildHeap(struct Employee *A, int n)
{
	//heapify() every element from A[n/2] to A[0]
	int i;
    for(i = n/2 ; i >= 0; i--){
        heapify(A,i,n);
    }
}


/**
 * We want to start with A[i] and trickle it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the list
 */
void heapify(struct Employee *A, int i, int n)
{
	int smaller = i;
	int leftChild = 2*(i+1)-1;
	int rightChild = 2*(i+1);
	//base case for recursion
	if( i<0 || i>=n || leftChild >= n ){
		return;
	}

	//if leftChild is smaller than parent
	if (A[leftChild].salary < A[smaller].salary){
		smaller = leftChild;
	} 
	//if right child is smallest so far
	if(rightChild < n && A[rightChild].salary < A[smaller].salary ){
		smaller = rightChild;
	}		
	//if parent is not smaller than its children, swap parent and child and recurse
	if(i != smaller){			
		swap(&A[smaller], &A[i]);
		heapify(A, smaller, n);
	}

}

/**
 * Gets the minimally paid employee. Assumes the given list is a min-heap.
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
struct Employee *getMinPaidEmployee(struct Employee *A, int n)
{
	//TODO
	return &A[n-1];
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(struct Employee *e1, struct Employee *e2)
{
	//TODO 
	struct Employee temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(struct Employee *A, int n)
{
	//TODO
	int i;
	for(i=0; i<n; i++){
		printf("[id = %s sal = %d], ", A[i].name, A[i].salary);
	}
	printf("\n");
}
