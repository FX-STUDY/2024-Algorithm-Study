#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  struct Student {
    std::string name;
    int koreanScore;
    int englishScore;
    int mathScore;

    Student(std::string name, int koreanScore, int englishScore, int mathScore) : name(name), koreanScore(koreanScore), englishScore(englishScore), mathScore(mathScore) {}
  };

  int studentNum;
  std::cin >> studentNum;

  std::vector<Student> students;
  students.reserve(studentNum);
  for (int i = 0; i < studentNum; i++) {
    std::string name;
    int koreanScore;
    int englishScore;
    int mathScore;
    std::cin >> name >> koreanScore >> englishScore >> mathScore;
    students.emplace_back(Student(name, koreanScore, englishScore, mathScore));
  }

  std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
    if (a.koreanScore != b.koreanScore) {
      return a.koreanScore > b.koreanScore;
    }
    if (a.englishScore != b.englishScore) {
      return a.englishScore < b.englishScore;
    }
    if (a.mathScore != b.mathScore) {
      return a.mathScore > b.mathScore;
    }
    return a.name < b.name;
  });

  for (auto &student : students) {
    std::cout << student.name << "\n";
  }
}