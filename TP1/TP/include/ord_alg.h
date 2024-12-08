#ifndef ORD_ALG_H
#define ORD_ALG_H

void swap(int &a, int &b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void bubbleSort(int arr[], int n);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

#endif // ORD_ALG_H
