#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// Part 1
int binary_search(int nums[], int size, int target) {
    //return binary_search_r(nums, target, 0, size - 1);
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        else if (nums[mid] > target)
            high = mid - 1;
        else 
            return mid;
    }
    return -1;
}

// Part 1.1 (Optional Challenge)
int binary_search_r(int nums[], int target, int low, int high) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (nums[mid] > target) return binary_search_r(nums, target, low, mid - 1);
    else if (nums[mid] < target) return binary_search_r(nums, target, mid + 1, high);
    else return mid;
}
int binary_search_recursive(int nums[], int size, int target) {
    return binary_search_r(nums, target, 0, size - 1);
}


// Part 2
int search_insert(int nums[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        else if (nums[mid] > target)
            high = mid - 1;
        else 
            return mid;
    }
    return low; // Only the change to the binary search algorithm
}


// Part 3
void swap(int nums[], int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void selection_sort(int nums[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < size; j++) 
            if (nums[j] < nums[min_i])
                min_i = j;
        swap(nums, i, min_i);
        // int tmp = nums[i];
        // nums[i] = nums[index_smallest];
        // nums[index_smallest] = tmp;
    }
}

// Part 3.3 (Optional Challenge)
void bubble_sort(int nums[], int n) { // swap neighbors that out of order, which naturally moves biggest to the end
    for (int i = 0; i < n - 1; i++) { // Why n times - each pass will make the largest element in the unsorted part to the right end.
        bool flag_swap = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums, j, j + 1);
                flag_swap = 1;
            }
        }
        if (!flag_swap) break;
    }
}



//////////////////////////// Unit tests below /////////////////////

// Helper for the tests: returns 1 if two int arrays are equal.
int arrays_equal(int a[], int b[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

void test_binary_search(void) {
    int a[] = {2, 3, 5, 7, 11, 13, 17, 19};
    int b[] = {2};
    int c[] = {-10, -3, 0, 4, 9};
    int empty[1] = {0};

    assert(binary_search(a, 8, 2) == 0);     // first element
    assert(binary_search(a, 8, 19) == 7);    // last element
    assert(binary_search(a, 8, 7) == 3);     // middle element
    assert(binary_search(a, 8, 4) == -1);    // missing, inside the range
    assert(binary_search(a, 8, 1) == -1);    // smaller than everything
    assert(binary_search(a, 8, 99) == -1);   // larger than everything
    assert(binary_search(b, 1, 2) == 0);
    assert(binary_search(b, 1, 3) == -1);
    assert(binary_search(c, 5, -3) == 1);
    assert(binary_search(c, 5, 0) == 2);
    assert(binary_search(c, 5, 5) == -1);
    assert(binary_search(empty, 0, 0) == -1);
}

void test_binary_search_recursive(void) {
    int a[] = {2, 3, 5, 7, 11, 13, 17, 19};
    int b[] = {2};
    int c[] = {-10, -3, 0, 4, 9};
    int empty[1] = {0};

    assert(binary_search_recursive(a, 8, 2) == 0);     // first element
    assert(binary_search_recursive(a, 8, 19) == 7);    // last element
    assert(binary_search_recursive(a, 8, 7) == 3);     // middle element
    assert(binary_search_recursive(a, 8, 4) == -1);    // missing, inside the range
    assert(binary_search_recursive(a, 8, 1) == -1);    // smaller than everything
    assert(binary_search_recursive(a, 8, 99) == -1);   // larger than everything
    assert(binary_search_recursive(b, 1, 2) == 0);
    assert(binary_search_recursive(b, 1, 3) == -1);
    assert(binary_search_recursive(c, 5, -3) == 1);
    assert(binary_search_recursive(c, 5, 0) == 2);
    assert(binary_search_recursive(c, 5, 5) == -1);
    assert(binary_search_recursive(empty, 0, 0) == -1);
}

void test_search_insert(void) {
    int a[] = {1, 3, 5, 6};
    int b[] = {10};
    int c[] = {-5, -1, 3};
    int empty[1] = {0};

    assert(search_insert(a, 4, 5) == 2);     // the three examples
    assert(search_insert(a, 4, 2) == 1);
    assert(search_insert(a, 4, 7) == 4);
    assert(search_insert(a, 4, 0) == 0);     // before the first element
    assert(search_insert(a, 4, 1) == 0);     // equal to the first element
    assert(search_insert(a, 4, 6) == 3);     // equal to the last element
    assert(search_insert(a, 4, 4) == 2);     // between two elements
    assert(search_insert(b, 1, 5) == 0);
    assert(search_insert(b, 1, 10) == 0);
    assert(search_insert(b, 1, 20) == 1);
    assert(search_insert(c, 3, -9) == 0);
    assert(search_insert(c, 3, -2) == 1);
    assert(search_insert(c, 3, 3) == 2);
    assert(search_insert(empty, 0, 8) == 0);
}


void test_selection_sort(void) {
    int a[] = {4, 2, 9, 1};
    int b[] = {3, 1, 2};
    int c[] = {5};
    int d[] = {1, 2, 3, 4};
    int e[] = {9, 7, 5, 3, 1};
    int f[] = {-3, 8, -10, 0};
    int g[] = {2, 2, 1, 1};
    int h[] = {6, 5};

    selection_sort(a, 4);
    selection_sort(b, 3);
    selection_sort(c, 1);
    selection_sort(d, 4);
    selection_sort(e, 5);
    selection_sort(f, 4);
    selection_sort(g, 4);
    selection_sort(h, 2);

    int exp_a[] = {1, 2, 4, 9};
    int exp_b[] = {1, 2, 3};
    int exp_c[] = {5};
    int exp_d[] = {1, 2, 3, 4};
    int exp_e[] = {1, 3, 5, 7, 9};
    int exp_f[] = {-10, -3, 0, 8};
    int exp_g[] = {1, 1, 2, 2};
    int exp_h[] = {5, 6};

    assert(arrays_equal(a, exp_a, 4));
    assert(arrays_equal(b, exp_b, 3));
    assert(arrays_equal(c, exp_c, 1));
    assert(arrays_equal(d, exp_d, 4));   // already sorted
    assert(arrays_equal(e, exp_e, 5));   // reverse order
    assert(arrays_equal(f, exp_f, 4));   // negative numbers
    assert(arrays_equal(g, exp_g, 4));   // repeated numbers
    assert(arrays_equal(h, exp_h, 2));
}

void test_bubble_sort(void) {
    int a[] = {4, 2, 9, 1};
    int b[] = {5, 4, 3};
    int c[] = {7};
    int d[] = {1, 2, 3, 4};
    int e[] = {9, 7, 5, 3, 1};
    int f[] = {-3, 8, -10, 0};
    int g[] = {2, 2, 1, 1};

    bubble_sort(a, 4);
    bubble_sort(b, 3);
    bubble_sort(c, 1);
    bubble_sort(d, 4);
    bubble_sort(e, 5);
    bubble_sort(f, 4);
    bubble_sort(g, 4);

    int exp_a[] = {1, 2, 4, 9};
    int exp_b[] = {3, 4, 5};
    int exp_c[] = {7};
    int exp_d[] = {1, 2, 3, 4};
    int exp_e[] = {1, 3, 5, 7, 9};
    int exp_f[] = {-10, -3, 0, 8};
    int exp_g[] = {1, 1, 2, 2};

    assert(arrays_equal(a, exp_a, 4));
    assert(arrays_equal(b, exp_b, 3));
    assert(arrays_equal(c, exp_c, 1));
    assert(arrays_equal(d, exp_d, 4));
    assert(arrays_equal(e, exp_e, 5));
    assert(arrays_equal(f, exp_f, 4));
    assert(arrays_equal(g, exp_g, 4));
}

int main() {
    test_binary_search();
    test_binary_search_recursive();  // Optional Challenge 1.1
    test_search_insert();

    test_selection_sort();
    test_bubble_sort();               // Optional Challenge 3.1

    printf("All tests passed!\n");

    return 0;
    
}
