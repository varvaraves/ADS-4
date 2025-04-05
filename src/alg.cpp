// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      } else if (arr[i] + arr[j] > value) {
        break;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      int l = 1, r = 1;
      while (left + l < right && arr[left + l] == arr[left]) ++l;
      while (right - r > left && arr[right - r] == arr[right]) ++r;
      count += l * r;
      left += l;
      right -= r;
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}

int binarySearchCount(int *arr, int left, int right, int target) {
  int count = 0;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      int l = mid;
      int r = mid + 1;
      while (l >= left && arr[l] == target) {
        ++count;
        --l;
      }
      while (r <= right && arr[r] == target) {
        ++count;
        ++r;
      }
      break;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    int complement = value - arr[i];
    count += binarySearchCount(arr, i + 1, len - 1, complement);
  }
  return count;
}
