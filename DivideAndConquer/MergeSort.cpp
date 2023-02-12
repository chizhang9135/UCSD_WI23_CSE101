#include <iostream>
#include <vector>
#include <string>

void mergeSort(std::vector<int> &arr, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    int i = left;
    int j = mid + 1;
    int k = left;
    std::vector<int> temp(arr.size());
    while (i <= mid && j <= right) {
      if (arr[i] < arr[j]) {
        temp[k++] = arr[i++];
      } else {
        temp[k++] = arr[j++];
      }
    }
    while (i <= mid) {
      temp[k++] = arr[i++];
    }
    while (j <= right) {
      temp[k++] = arr[j++];
    }
    for (int i = left; i <= right; i++) {
      arr[i] = temp[i];
    }
  }
}

int main() {
  std::vector<int> arr;
  std::string input;
  std::cout << "Enter a list of numbers, separated by spaces. To end the list, enter 'end':" << std::endl;
  while (std::cin >> input) {
    if (input == "end") break;
    arr.push_back(std::stoi(input));
  }

  int n = arr.size();
  mergeSort(arr, 0, n - 1);

  std::cout << "Sorted list:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}

