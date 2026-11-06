#pragma once
#include <set>
#include <bitset>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_SUBJECTS = 32; // Максимальна кількість предметів для нашого бітсету
// Структура для зберігання інформації про предмет
struct Subject
{
    int id;
    string name;
    string category;
};
// Клас для керування операціями з множинами академічних предметів
class SubjectSetOperations
{
private:
    vector<Subject> allSubjects;
    map<string, set<int>> namedSets;
    map<string, bitset<MAX_SUBJECTS>> namedBitsets;
public:
    // Конструктор/Деструктор
    SubjectSetOperations();
    ~SubjectSetOperations() = default;
    // Ініціалізація бази даних предметів
    void initializeSubjects();
    // Функції відображення
    void displayAllSubjects() const;
    void displaySet(const string& setName) const;
    void displayAllSets() const;
    // Функції керування множинами
    void createSet(const string& setName);
    // Операції над множинами
    void unionSets(const string& set1Name, const string& set2Name, const string& resultName);
    void intersectionSets(const string& set1Name, const string& set2Name, const string& resultName);
    void symmetricDifference(const string& set1Name, const string& set2Name, const string& resultName);
    void xorSets(const string& set1Name, const string& set2Name, const string& resultName);
    void membershipTest(const string& setName, int subjectId);
};
