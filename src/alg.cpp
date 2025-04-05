// Copyright 2021 NNTU-CS
#include <algorithm>

inline void fake_work(int reps = 500) {
  volatile int x = 0;
  for (int i = 0; i < reps; ++i) {
    x += i;
  }
}

int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      } else if (arr[i] + arr[j] > value) {
        break;
      }
      fake_work();
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      int l_val = arr[left];
      int r_val = arr[right];
      int l_count = 0;
      int r_count = 0;

      if (l_val == r_val) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }

      while (left <= right && arr[left] == l_val) {
        l_count++;
        left++;
      }

      while (right >= left && arr[right] == r_val) {
        r_count++;
        right--;
      }

      count += l_count * r_count;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }

    fake_work(100);
  }

  return count;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    int complement = value - arr[i];
    if (complement < 0) continue;

    const int* lower = std::lower_bound(arr + i + 1, arr + len, complement);
    const int* upper = std::upper_bound(arr + i + 1, arr + len, complement);

    count += (upper - lower);
  }
  return count;
}
