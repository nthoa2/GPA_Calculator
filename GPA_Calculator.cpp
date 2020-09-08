#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
using namespace std;

struct Subjects
{
    string nameSub;
    int numsCredits;
    double grade;
};

void inputSubject(Subjects sub[], size_t size);
double GPA10(Subjects sub[], size_t size);
double GPA4(Subjects sub[], size_t size);

void input(Subjects &subjects)
{
    cin.ignore();
    cout << "Name's Subjects: ";
    getline(cin, subjects.nameSub);
    cout << "Number of Credits: ";
    cin >> subjects.numsCredits;
    cout << "Grade's Subjects of 10: ";
    cin >> subjects.grade;
}
void inputSubject(Subjects sub[], size_t size)
{

    for (size_t i = 0; i < size; i++)
    {

        while (true)
        {
            system("cls");
            cout << "Subjects Number: " << i + 1 << endl;
            input(sub[i]);
            if (sub[i].grade > 10 || sub[i].grade < 0)
            {
                cout << "Enter failed!!" << endl
                     << "Press any key to Try Again!" << endl;
                getch();
            }
            else
            {
                cout << "Enter successfully!!" << endl
                     << "Press any key to continue!" << endl;
                getch();
                break;
            }
        }
    }
}

double GPA10(Subjects sub[], size_t size)
{
    double result = 0;
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        result += sub[i].grade * sub[i].numsCredits;
        count += sub[i].numsCredits;
    }
    return result / count;
}

double GPA4(Subjects sub[], size_t size)
{
    double result = 0;
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (sub[i].grade >= 8.5)
        {
            result += 4 * sub[i].numsCredits;
            count += sub[i].numsCredits;
        }
        else if (sub[i].grade >= 7 && sub[i].grade < 8.5)
        {
            result += 3 * sub[i].numsCredits;
            count += sub[i].numsCredits;
        }
        else if (sub[i].grade >= 5.5 && sub[i].grade < 7)
        {
            result += 2 * sub[i].numsCredits;
            count += sub[i].numsCredits;
        }
        else if (sub[i].grade >= 5 && sub[i].grade < 5.5)
        {
            result += 1.5 * sub[i].numsCredits;
            count += sub[i].numsCredits;
        }
        else if (sub[i].grade >= 4 && sub[i].grade < 5)
        {
            result += 1 * sub[i].numsCredits;
            count += sub[i].numsCredits;
        }
        else if (sub[i].grade >= 3 && sub[i].grade < 4)
        {
            result += 0.5 * sub[i].numsCredits;
            count += sub[i].numsCredits;
        }
        else
        {
            count += sub[i].numsCredits;
        }
    }
    return result / count;
}

int main(int argc, char const *argv[])
{
    Subjects sub[20];
    size_t n;
    cout << "Number of Subjects Studied: ";
    cin >> n;
    inputSubject(sub, n);
    cout << "GPA out of 10: " << GPA10(sub, n) << endl;
    cout << "============================================================================" << endl;
    cout << "GPA out of 4: " << GPA4(sub, n) << endl;
    getch();
    return 0;
}