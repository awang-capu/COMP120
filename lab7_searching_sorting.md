# Lab 7: Binary Search and Sorting

## Objectives

By the end of this lab, students will be able to:

1. Implement binary search with a loop, using `low`, `high`, and `mid`.
2. Adapt binary search to return the position where a missing value should be inserted.
3. Describe and implement selection sort.
4. Write unit tests with `assert()`.
5. Design your own unit tests and write them in `main()`.


## How This Lab Works

In earlier labs, the tests were given to you. In this lab, **you write everything**: the functions, and the unit tests inside `main()`.

Create one file named `lab7.c`. For each function below:

1. Write the function above `main()`.
2. In `main()`, design your own test cases and check them with `assert()`. Note: if your function is wrong, a good test should fail.

When all tests pass, `main()` should print:

```
All tests passed!
```

## Part 1: Binary Search


### Task

Write the function `int binary_search(int nums[], int size, int target)`.

The array `nums` is sorted in increasing order. Return the index of `target` in the array, or `-1` if `target` is not in the array.


### Hints
- Keep two variables, `low` and `high`, for the search range that could still contain the target.
- Use a while loop to check if the search range is not empty.
- Look at the middle element, then move `low` or `high`.
- Stop when `low` is greater than `high`.
- Compute the middle as `low + (high - low) / 2`. Be ready to explain in the quiz why this is safer than `(low + high) / 2`.

### Examples

| Array | Target | Result |
|---|---|---|
| `{2, 3, 5, 7}` | 5 | 2 |
| `{2, 3, 5, 7}` | 4 | -1 |
| `{2}` | 2 | 0 |


### Part 1.1 (Optional Challenge): Recursive Binary Search

Implement `int binary_search_recursive(int nums[], int target, int low, int high)`. It does the same job, but calls itself on the left half or the right half instead of using a loop. To search a whole array of size `n`, call it as the code below with `low = 0` and `high = size - 1`.

```
int binary_search(int nums[], int size, int target) {
    return binary_search_recursive(nums, target, 0, size - 1);
}
```

Hint: what should the function return when `low` is greater than `high`?

---

## Part 2: Search Insert Position

### Task

Write the function `int search_insert(int nums[], int size, int target)`.

The array `nums` is sorted in increasing order and contains distinct integers. If `target` is found, return its index. If not, return the index where it would be if it were inserted in order.

Your algorithm must run in `O(log n)` time, so linear search is not allowed.

### Hints

- This is binary search again, with one small change at the end.
- When the loop ends and the target was not found, think about what `low` and `high` are, and where they sit relative to each other.

### Examples

| Array | Target | Result |
|---|---|---|
| `{1, 3, 5, 6}` | 5 | 2 |
| `{1, 3, 5, 6}` | 2 | 1 |
| `{1, 3, 5, 6}` | 7 | 4 |
| `{1, 3, 5, 6}` | 0 | 0 |



## Part 3: Selection Sort

### Task

Write the function `void selection_sort(int nums[], int size)`. It sorts the array in increasing order, in place, and returns nothing.

### How Selection Sort Works

Think of the array as two parts: a **sorted part** on the left (empty at the start) and an **unsorted part** on the right. In each round:

1. Find the smallest number in the unsorted part.
2. Swap it with the first number of the unsorted part.
3. The sorted part is now one element longer.

Repeat until only one element is left unsorted. That last element must already be in the right place.

### Examples

| Before | After |
|---|---|
| `{4, 2, 9, 1}` | `{1, 2, 4, 9}` |
| `{3, 1, 2}` | `{1, 2, 3}` |
| `{5}` | `{5}` |


### Part 3.1 (Optional Challenge): Bubble Sort

Write `void bubble_sort(int nums[], int size)`. It sorts the array in increasing order, in place.

**How bubble sort works:**

1. Walk through the array and compare each pair of neighbors.
2. If the left one is bigger than the right one, swap them.
3. After one full walk, the biggest number has "bubbled" to the end, so it is in its final place.
4. Walk again, but stop one position earlier each time.
5. Repeat until the whole array is sorted.

Add tests for it in `main()` as well. Reuse your sorting examples from Part 3.

---

Now complete your lab_quiz on e-Learn. And that's all. Congratulations!
