#include "SubjectSetOperations.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
// Конструктор
SubjectSetOperations::SubjectSetOperations()
{
    // Ініціалізація предметами
    initializeSubjects();
}
void SubjectSetOperations::initializeSubjects()
{
    // Заповнюємо наш список предметів різними академічними дисциплінами
    allSubjects = {
        {0, "Алгебра", "ТОЧНІ НАУКИ"},
        {1, "Геометрія", "ТОЧНІ НАУКИ"},
        {2, "Фізика", "ТОЧНІ НАУКИ"},
        {3, "Дискретна математика", "ТОЧНІ НАУКИ"},
        {4, "Програмування", "ТОЧНІ НАУКИ"},
        {5, "Математичний аналіз", "ТОЧНІ НАУКИ"},
        {6, "Українська література", "ГУМАНІТАРНІ"},
        {7, "Історія", "ГУМАНІТАРНІ"},
        {8, "Філософія", "ГУМАНІТАРНІ"},
        {9, "Психологія", "СУСПІЛЬНІ НАУКИ"},
        {10, "Соціологія", "СУСПІЛЬНІ НАУКИ"},
        {11, "Економіка", "СУСПІЛЬНІ НАУКИ"},
        {12, "Мистецтво", "МИСТЕЦТВО"},
        {13, "Музичне мистецтво", "МИСТЕЦТВО"},
        {14, "Театральне мистецтво", "МИСТЕЦТВО"},
        {15, "Фізкультура", "ФІЗИЧНЕ"},
        {16, "Статистика", "ТОЧНІ НАУКИ"},
        {17, "Англійська мова", "ГУМАНІТАРНІ"},
        {18, "Географія", "СУСПІЛЬНІ НАУКИ"},
        {19, "Політологія", "СУСПІЛЬНІ НАУКИ"}
    };
}
// Відображення всіх доступних предметів
void SubjectSetOperations::displayAllSubjects() const
{
    cout << "\n=== Доступні предмети ===\n";
    cout << left << setw(3) << "ID" << " | "
        << setw(22) << "Предмет" << " | "
        << "Категорія" << endl;
    cout << "-------------------------------------\n";
    for (const auto& subject : allSubjects)
    {
        cout << left << setw(3) << subject.id << " | "
            << setw(22) << subject.name << " | "
            << subject.category << endl;
    }
    cout << endl;
}
// Створення нової множини із введення користувача
void SubjectSetOperations::createSet(const string& setName)
{
    set<int> newSet;
    bitset<MAX_SUBJECTS> newBitset;
    cout << "\nСтворення множини '" << setName << "'\n";
    cout << "Введіть ID предметів (по одному, -1 для завершення):\n";
    while (true)
    {
        int id;
        cout << "> ";
        if (!(cin >> id)) {
            if (cin.eof()) return;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (id == -1) break;
        // Перевірка ID
        if (id < 0 || id >= static_cast<int>(allSubjects.size()))
        {
            cout << "Неправильний ID предмета. Будь ласка, введіть дійсний ID.\n";
            continue;
        }
        newSet.insert(id);
        newBitset.set(id);
    }
    namedSets[setName] = newSet;
    namedBitsets[setName] = newBitset;
    cout << "Множину '" << setName << "' успішно створено з "
        << newSet.size() << " предметів.\n";
}
// Відображення конкретної множини
void SubjectSetOperations::displaySet(const string& setName) const
{
    if (namedSets.find(setName) == namedSets.end())
    {
        cout << "Множини '" << setName << "' не існує.\n";
        return;
    }
    const auto& subjectSet = namedSets.at(setName);
    const auto& bitset = namedBitsets.at(setName);
    cout << "\n=== Множина: " << setName << " ===\n";
    if (subjectSet.empty())
    {
        cout << "Порожня множина\n";
        return;
    }
    cout << "Використання std::set: ";
    for (const auto& id : subjectSet)
    {
        cout << allSubjects[id].name << ", ";
    }
    cout << "\b\b \n";
    cout << "Використання bitset: " << bitset << "\n";
    cout << "Кількість предметів: " << subjectSet.size() << "\n\n";
}
// Відображення всіх множин
void SubjectSetOperations::displayAllSets() const
{
    cout << "\n=== Всі множини ===\n";
    if (namedSets.empty())
    {
        cout << "Поки що множин не визначено.\n";
        return;
    }
    for (const auto& pair : namedSets)
    {
        cout << "- " << pair.first << " (" << pair.second.size() << " предметів)\n";
    }
    cout << endl;
}
// Об'єднання двох множин
void SubjectSetOperations::unionSets(const string& set1Name, const string& set2Name, const string& resultName)
{
    if (namedSets.find(set1Name) == namedSets.end() || namedSets.find(set2Name) == namedSets.end())
    {
        cout << "Одна або обидві множини не існують.\n";
        return;
    }
    const auto& set1 = namedSets[set1Name];
    const auto& set2 = namedSets[set2Name];
    const auto& bitset1 = namedBitsets[set1Name];
    const auto& bitset2 = namedBitsets[set2Name];
    // Використання std::set та алгоритму
    set<int> resultSet;
    set_union(set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        inserter(resultSet, resultSet.begin()));
    // Використання bitset
    bitset<MAX_SUBJECTS> resultBitset = bitset1 | bitset2;
    // Зберігаємо результати
    namedSets[resultName] = resultSet;
    namedBitsets[resultName] = resultBitset;
    cout << "Об'єднання множин '" << set1Name << "' та '" << set2Name
        << "' збережено як '" << resultName << "'.\n";
    displaySet(resultName);
}
// Перетин двох множин
void SubjectSetOperations::intersectionSets(const string& set1Name, const string& set2Name, const string& resultName)
{
    if (namedSets.find(set1Name) == namedSets.end() || namedSets.find(set2Name) == namedSets.end())
    {
        cout << "Одна або обидві множини не існують.\n";
        return;
    }
    const auto& set1 = namedSets[set1Name];
    const auto& set2 = namedSets[set2Name];
    const auto& bitset1 = namedBitsets[set1Name];
    const auto& bitset2 = namedBitsets[set2Name];
    // Використання std::set та алгоритму
    set<int> resultSet;
    set_intersection(set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        inserter(resultSet, resultSet.begin()));
    // Використання bitset
    bitset<MAX_SUBJECTS> resultBitset = bitset1 & bitset2;
    // Зберігаємо результати
    namedSets[resultName] = resultSet;
    namedBitsets[resultName] = resultBitset;
    cout << "Перетин множин '" << set1Name << "' та '" << set2Name
        << "' збережено як '" << resultName << "'.\n";
    displaySet(resultName);
}
// Симетрична різниця двох множин
void SubjectSetOperations::symmetricDifference(const string& set1Name, const string& set2Name, const string& resultName)
{
    if (namedSets.find(set1Name) == namedSets.end() || namedSets.find(set2Name) == namedSets.end())
    {
        cout << "Одна або обидві множини не існують.\n";
        return;
    }
    const auto& set1 = namedSets[set1Name];
    const auto& set2 = namedSets[set2Name];
    const auto& bitset1 = namedBitsets[set1Name];
    const auto& bitset2 = namedBitsets[set2Name];
    // Використання std::set та алгоритму
    set<int> resultSet;
    set_symmetric_difference(set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        inserter(resultSet, resultSet.begin()));
    // Використання bitset
    bitset<MAX_SUBJECTS> resultBitset = bitset1 ^ bitset2;
    // Зберігаємо результати
    namedSets[resultName] = resultSet;
    namedBitsets[resultName] = resultBitset;
    cout << "Симетрична різниця множин '" << set1Name << "' та '" << set2Name
        << "' збережено як '" << resultName << "'.\n";
    displaySet(resultName);
}
// Операція XOR з використанням бітсетів (те саме, що й симетрична різниця)
void SubjectSetOperations::xorSets(const string& set1Name, const string& set2Name, const string& resultName)
{
    // Для бітсетів, XOR - це те саме, що й симетрична різниця
    symmetricDifference(set1Name, set2Name, resultName);
}
// Перевірка членства
void SubjectSetOperations::membershipTest(const string& setName, int subjectId)
{
    if (namedSets.find(setName) == namedSets.end())
    {
        cout << "Множини '" << setName << "' не існує.\n";
        return;
    }
    if (subjectId < 0 || subjectId >= static_cast<int>(allSubjects.size()))
    {
        cout << "Неправильний ID предмета. Будь ласка, введіть дійсний ID.\n";
        return;
    }
    const auto& set = namedSets[setName];
    const auto& bitset = namedBitsets[setName];
    // Перевіряємо наявність елемента за допомогою бібліотеки алгоритмів
    bool isMemberStdSet = binary_search(set.begin(), set.end(), subjectId);
    // Альтернатива: bool isMemberStdSet = set.find(subjectId) != set.end();
    bool isMemberBitset = bitset.test(subjectId);
    cout << "Предмет '" << allSubjects[subjectId].name
        << "' " << (isMemberStdSet ? "є" : "не є")
        << " членом множини '" << setName << "'\n";
    // Обидва методи повинні давати один і той самий результат
    if (isMemberStdSet != isMemberBitset)
    {
        cout << "Увага: Невідповідність між результатами std::set та bitset!\n";
    }
}