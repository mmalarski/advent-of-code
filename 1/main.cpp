#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int CalculateDistanceBetweenLists(std::vector<int> list1, std::vector<int> list2)
{
  std::sort(list1.begin(), list1.end());
  std::sort(list2.begin(), list2.end());

  int sum = 0;
  for (int i = 0; i < list1.size(); i++) {
    sum += std::abs(list1[i] - list2[i]);
  }

  return sum;
}

int CalculateSimilarityScoreOfTwoLists(std::vector<int> list1, std::vector<int> list2)
{
  int similarityScore = 0;

  std::sort(list1.begin(), list1.end());
  for (int number : list1) {
    int numberCountInList2 = std::count(list2.begin(), list2.end(), number);
    similarityScore += number * numberCountInList2;
  }
  return similarityScore;
}

int main()
{
  // Open the file
  std::ifstream file("input.txt");
  // make two lists to store the numbers
  std::vector<int> list1;
  std::vector<int> list2;

  // read the tweo numbers from each line and add them to the lists
  int num1, num2;
  while (file >> num1 >> num2) {
    list1.push_back(num1);
    list2.push_back(num2);
  }

  int distance = CalculateDistanceBetweenLists(list1, list2);
  int similarityScore = CalculateSimilarityScoreOfTwoLists(list1, list2);

  std::cout << "The total distance: " << distance << std::endl;
  std::cout << "Similarity score: " << similarityScore << std::endl;
  return 0;
}