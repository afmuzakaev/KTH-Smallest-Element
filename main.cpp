#include <iostream>
#include <algorithm>

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    std::swap(arr[i + 1], arr[r]);
    return i + 1;
}

int kthSmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int pos = partition(arr, l, r);
        
        if (pos - l == k - 1) {
            return arr[pos];
        }
        
        if (pos - l > k - 1) {
            return kthSmallest(arr, l, pos - 1, k);
        }
        
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
    
    return -1; // Invalid input
}

int main() {
    int N;
    std::cout << "Enter the size of the array: ";
    std::cin >> N;
    
    int arr[N];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    
    int K;
    std::cout << "Enter the value of K: ";
    std::cin >> K;
    
    if (K >= 1 && K <= N) {
        int result = kthSmallest(arr, 0, N - 1, K);
        std::cout << "The " << K << "th smallest element is: " << result << std::endl;
    } else {
        std::cout << "Invalid value of K." << std::endl;
    }
    
    return 0;
}
