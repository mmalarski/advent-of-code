#include <iostream>
#include <fstream>  
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
  std::ifstream file("input.txt");

  int safeLevelsNumber = 0;
  // for each line in the file
  for (std::string line; std::getline(file, line); ) {
    std::vector<int> levels;

    // split the line by spaces
    std::istringstream splittedLine(line);
    for (std::string level; splittedLine >> level; ) {
      levels.push_back(std::stoi(level));
    }

    bool isLevelSafe = true;
    int monotonicity = levels[1] > levels[0] ? 1 : -1;

    // for each level
    for (int i = 1; i < levels.size(); i++) {
      bool isLevelDifferentByLessThanOne = std::abs(levels[i] - levels[i - 1]) < 1;
      bool isLevelDifferentByMoreThanThree = std::abs(levels[i] - levels[i - 1]) > 3;
      int currentMonotonicity = levels[i] > levels[i - 1] ? 1 : -1;
      bool hasMonotonicityChanged = currentMonotonicity != monotonicity;

      if (isLevelDifferentByLessThanOne || isLevelDifferentByMoreThanThree || hasMonotonicityChanged) {
        isLevelSafe = false;
      }
    }
    safeLevelsNumber = isLevelSafe ? safeLevelsNumber + 1 : safeLevelsNumber;
  }
  std::cout << "Safe levels number: " << safeLevelsNumber << std::endl;
}