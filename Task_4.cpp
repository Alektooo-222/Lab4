#include <fstream>
#include <string>
#include <iostream>
#include <cmath>

// picture 13

using namespace std;

class Working
{
public:
    float m[19];
    const char ch = '\n';
    char mass[30][19];

    float line(int x)
    {
        float y = 0;
        if (x >= -5 && x < -3)
        {
            return x + 3;
        }
        if (x >= -3 && x < 0)
        {
            return sqrt(9 - (x * x));
        }
        if (x >= 0 && x < 6)
        {
            return -0.5 * (x - 6);
        }
        if (x >= 6 && x <= 9)
        {
            return x - 6;
        }
        return 0;
    }

    void write_to_massive()
    {
        for (int i = -5; i <= 9; i++)
        {
            m[i + 5] = line(i);
        }
    }

    void write()
    {
        ofstream fout("task_4.txt"); // создание текстового файла
        for (int i = -5; i <= 9; i++)
        {
            fout << "x = " << i << "   y = " << line(i) << endl; // запись значений в файл
        }
        fout.close(); // закрываем файл
    }
    void read()
    {

        int x = 0;
        ifstream fin("task_4.txt"); // открываем текстовый файл

        for (int r = 0; r <= 14; r++)
        {
            fin.getline(mass[r], 30 - 1, ch); // Считываем строки в массив
            cout << mass[r] << endl;          // Выводи строку из массива
        }
        fin.close(); // Закрываем файл
    }
};

float main()
{
    Working paulo;
    int x = 0;
    // cin >> x;
    // cout << paulo.line(x) << endl;
    paulo.write_to_massive();
    paulo.write();
    paulo.read();
}