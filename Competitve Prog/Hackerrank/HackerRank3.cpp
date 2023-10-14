#include <iostream>
#include <string>
using namespace std;

// int main()
// {
//     string s1, s2, s3;
//     char temp;
//     cin >> s1 >> s2;
//     cout << s1.size() << " " << s2.size() << endl;
//     s3 = s1 + s2;
//     cout << s3 << endl;
//     temp = s1[0];
//     s1[0] = s2[0];
//     s2[0] = temp;
//     cout << s1 << " " << s2;

//     return 0;
// }
//////////////////////////////////////////////////////////////////////////////////////

// class Student
// {
//     int marks[5];

// public:
//     void input()
//     {
//         for (int i = 0; i < 5; i++)
//         {
//             cin >> marks[i];
//         }
//     }

//     int calculatetotalscore(void)
//     {
//         int count = 0;
//         for (int i = 0; i < 5; i++)
//         {
//             count += marks[i];
//         }
//         return count;
//     }
// };

// int main()
// {
//     int n; // no of student
//     cin >> n;
//     Student *s = new Student[n]; // array of students
//     for (int i = 0; i < n; i++)
//     {
//         s[i].input();
//     }

//     int Kristen_score = s[0].calculatetotalscore();

//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int total = s[i].calculatetotalscore();
//         if (total > Kristen_score)
//         {
//             count++;
//         }
//     }

//     cout << count << endl;

//     return 0;
// }