#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>

using namespace std;

struct Student
{
    string id;
    string name;
    float resultAverage;
};

const int MAX = 100;

time_t now = time(0);
tm *localt = localtime(&now);

Student students[MAX];
int pupils = 0;

Student undo[MAX];
int top = -1;

void push(Student s)
{
    if (top < MAX - 1)
    {
        undo[++top] = s;
    }
}

Student pop()
{
    if (top >= 0)
    {
        return undo[top--];
    }
    return Student();
}

void Add()
{
    if (pupils == MAX)
    {
        cout << "Student list full!\n";
        return;
    }

    Student s;
    cout << "Enter Student Name: \n";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter resultAverage: \n";
    cin >> s.resultAverage;

    s.id = to_string(1900 + localt->tm_year) + "-" +
           to_string(1 + localt->tm_mon) + "-" +
           to_string(localt->tm_mday) + "-" +
           to_string(pupils + 1);
    students[pupils++] = s;
    push(s);

    cout << "\nStudent registered successfully!\n";
}

void Last()
{
    if (top < 0)
    {
        cout << "Nothing to undo!\n";
        return;
    }
    Student last = pop();
    for (int i = 0; i < pupils; i++)
    {
        if (students[i].id == last.id)
        {
            for (int j = i; j < pupils - 1; j++)
            {
                students[j] = students[j + 1];
            }
            pupils--;
            cout << "Undo successful! Removed student: " << last.name << "\n";
            return;
        }
    }
}

void Sort(int a)
{
    if (a == 3)
    {
        for (int i = 0; i < pupils - 1; i++)
        {
            for (int j = 0; j < pupils - i - 1; j++)
            {
                if (students[j].id > students[j + 1].id)
                {
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
        cout << "\nStudents sorted by ID!\n";
    }
    else if (a == 5)
    {
        for (int i = 0; i < pupils - 1; i++)
        {
            for (int j = 0; j < pupils - i - 1; j++)
            {
                if (students[j].resultAverage > students[j + 1].resultAverage)
                {
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
        cout << "\nStudents sorted by resultAverage!\n";
    }
    else if (a == 4)
    {
        for (int i = 0; i < pupils - 1; i++)
        {
            for (int j = 0; j < pupils - i - 1; j++)
            {
                if (students[j].name > students[j + 1].name)
                {
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
        cout << "\nStudents sorted by name!\n";
    }
}

void Display()
{
    if (pupils == 0)
    {
        cout << "No students registered.\n";
        return;
    }
    cout << "\n--- Student List ---\n";
    for (int i = 0; i < pupils; i++)
    {
        cout << students[i].id << " - " << students[i].name << " - " << students[i].resultAverage << endl;
    }
}

void SaveToCSVFile()
{
    string filename = to_string(1900 + localt->tm_year) + "-" +
                      to_string(1 + localt->tm_mon) + "-" +
                      to_string(localt->tm_mday) + "-";
    ofstream file(filename + "applicants.csv");
    if (!file.is_open())
        return;
    sort(students, students + pupils, [](const Student &a, const Student &b)
         { return a.id < b.id; });
    for (int i = 0; i < pupils; ++i)
    {
        auto &s = students[i];
        file << s.id << "," << s.name << "," << s.resultAverage << "\n";
    }
}

void LoadFromCSVFile()
{
    string filename = to_string(1900 + localt->tm_year) + "-" +
                      to_string(1 + localt->tm_mon) + "-" +
                      to_string(localt->tm_mday) + "-";
    ifstream file(filename + "applicants.csv");
    if (!file.is_open())
        return;
    string line;
    while (getline(file, line))
    {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        if (pos1 == string::npos || pos2 == string::npos)
            continue;
        Student s;
        s.id = line.substr(0, pos1);
        s.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        s.resultAverage = stof(line.substr(pos2 + 1));
        students[pupils++] = s;
        push(s);
    }
}

void ShortlistPasser()
{
    cout << "Passing grade threshold: ";
    float passingGrade;
    cin >> passingGrade;

    cout << "\n--- Passer Students ---\n";
    for (int i = 0; i < pupils; i++)
    {
        if (students[i].resultAverage >= passingGrade)
        {
            cout << students[i].id << " - " << students[i].name << " - " << students[i].resultAverage << endl;
        }
    }

    // remove non-passers
    int writeIndex = 0;
    for (int i = 0; i < pupils; i++)
    {
        if (students[i].resultAverage >= passingGrade)
        {
            students[writeIndex++] = students[i];
        }
    }
    pupils = writeIndex;
    cout << "\nNon-passer students removed from the list.\n";
}

int main()
{
    LoadFromCSVFile();
    int choice;
    do
    {
        cout << "\nSTUDENT REGISTRATION SORTING SYSTEM \n";
        cout << "1. Register Student\n";
        cout << "2. Undo Last Registration\n";
        cout << "3. Sort Students by Student ID\n";
        cout << "4. Sort Students by Name\n";
        cout << "5. Sort Students by Result Average\n";
        cout << "6. Display Students\n";
        cout << "7. Shortlist Passer\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add();
            SaveToCSVFile();
            break;
        case 2:
            Last();
            SaveToCSVFile();
            break;
        case 3:
        case 4:
        case 5:
            Sort(choice);
            break;
        case 6:
            Display();
            break;
        case 7:
            ShortlistPasser();
            SaveToCSVFile();
            break;
        case 8:
            cout << "Exiting program\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 8);
    return 0;
}