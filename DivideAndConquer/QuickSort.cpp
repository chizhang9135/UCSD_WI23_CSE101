#include <iostream>
#include <vector>
#include <string>

void quickSort(std::vector<int> &arr, int left, int right) {
  int i = left, j = right;
  int pivot = arr[(left + right) / 2];
  while (i <= j) {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i <= j) {
      std::swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }
  if (left < j) {
    quickSort(arr, left, j);
  }
  if (i < right) {
    quickSort(arr, i, right);
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
  quickSort(arr, 0, n - 1);

  std::cout << "Sorted list:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}

