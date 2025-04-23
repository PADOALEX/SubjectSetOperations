#include "SubjectSetOperations.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "Windows.h"
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    SubjectSetOperations setOps;
    int choice;
    cout << "=== Операції над множинами академічних предметів ===\n";
    while (true)
    {
        cout << "\nМеню:\n";
        cout << "1. Показати всі доступні предмети\n";
        cout << "2. Створити нову множину\n";
        cout << "3. Показати множину\n";
        cout << "4. Показати всі множини\n";
        cout << "5. Об'єднання двох множин\n";
        cout << "6. Перетин двох множин\n";
        cout << "7. Симетрична різниця двох множин\n";
        cout << "8. XOR двох множин (використовуючи бітсети)\n";
        cout << "9. Перевірка приналежності елемента\n";
        cout << "0. Вихід\n";
        cout << "Введіть ваш вибір: ";
        cin >> choice;
		if (!cin) // Перевірка на помилку вводу
		{
			cin.clear(); // Скидаємо помилку
			cin.ignore(1000, '\n'); // Ігноруємо залишок рядка
			cout << "Будь ласка, введіть число.\n";
			continue;
		}
		if (cin.fail()) // Перевірка на помилку вводу
		{
			cin.clear(); // Скидаємо помилку
			cin.ignore(1000, '\n'); // Ігноруємо залишок рядка
			cout << "Будь ласка, введіть число.\n";
			continue;
		}
        if (choice == 0)
        {
            cout << "Виходимо з програми. До побачення!\n";
            break;
        }
        string setName1, setName2, resultName;
        int subjectId;
        switch (choice)
        {
        case 1:
            setOps.displayAllSubjects();
            break;
        case 2:
            cout << "Введіть назву для нової множини: ";
            cin >> setName1;
            // Перетворення на нижній регістр для узгодженості
            transform(setName1.begin(), setName1.end(), setName1.begin(), ::tolower);
            setOps.createSet(setName1);
            break;
        case 3:
            cout << "Введіть назву множини для відображення: ";
            cin >> setName1;
            transform(setName1.begin(), setName1.end(), setName1.begin(), ::tolower);
            setOps.displaySet(setName1);
            break;
        case 4:
            setOps.displayAllSets();
            break;
        case 5:
            cout << "Введіть назву першої множини: ";
            cin >> setName1;
            transform(setName1.begin(), setName1.end(), setName1.begin(), ::tolower);
            cout << "Введіть назву другої множини: ";
            cin >> setName2;
            transform(setName2.begin(), setName2.end(), setName2.begin(), ::tolower);
            cout << "Введіть назву для результуючої множини: ";
            cin >> resultName;
            transform(resultName.begin(), resultName.end(), resultName.begin(), ::tolower);
            setOps.unionSets(setName1, setName2, resultName);
            break;
        case 6:
            cout << "Введіть назву першої множини: ";
            cin >> setName1;
            transform(setName1.begin(), setName1.end(), setName1.begin(), ::tolower);
            cout << "Введіть назву другої множини: ";
            cin >> setName2;
            transform(setName2.begin(), setName2.end(), setName2.begin(), ::tolower);
            cout << "Введіть назву для результуючої множини: ";
            cin >> resultName;
            transform(resultName.begin(), resultName.end(), resultName.begin(), ::tolower);
            setOps.intersectionSets(setName1, setName2, resultName);
            break;
        case 7:
            cout << "Введіть назву першої множини: ";
            cin >> setName1;
            transform(setName1.begin(), setName1.end(), setName1.begin(), ::tolower);
            cout << "Введіть назву другої множини: ";
            cin >> setName2;
            transform(setName2.begin(), setName2.end(), setName2.begin(), ::tolower);
            cout << "Введіть назву для результуючої множини: ";
            cin >> resultName;
            transform(resultName.begin(), resultName.end(), resultName.begin(), ::tolower);
            setOps.symmetricDifference(setName1, setName2, resultName);
            break;
        case 8:
            cout << "Введіть назву першої множини: ";
            cin >> setName1;
            transform(setName1.begin(), setName1.end(), setName1.begin(), ::tolower);
            cout << "Введіть назву другої множини: ";
            cin >> setName2;
            transform(setName2.begin(), setName2.end(), setName2.begin(), ::tolower);
            cout << "Введіть назву для результуючої множини: ";
            cin >> resultName;
            transform(resultName.begin(), resultName.end(), resultName.begin(), ::tolower);
            setOps.xorSets(setName1, setName2, resultName);
            break;
        case 9:
            cout << "Введіть назву множини: ";
            cin >> setName1;
            transform(setName1.begin(), setName1.end(), setName1.begin(), ::tolower);
            cout << "Введіть ID предмета для перевірки: ";
            cin >> subjectId;
            setOps.membershipTest(setName1, subjectId);
            break;
        default:
            cout << "Недійсний вибір. Спробуйте ще раз.\n";
        }
    }
    return 0;
}