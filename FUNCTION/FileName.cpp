#include <Windows.h>
#include <iostream>

int vis(int y)
{
    if (y % 400 == 0) return 1;
    if (y % 4 == 0 && y % 100 != 0) return 1;
    return 0;
}

int days(int d1, int m1, int y1, int d2, int m2, int y2)
{
    int md[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int t1 = 0;
    int t2 = 0;
    int i;

    t1 = (y1 - 1) * 365 + (y1 - 1) / 4 - (y1 - 1) / 100 + (y1 - 1) / 400;
    for (i = 1; i < m1; i++)
    {
        t1 = t1 + md[i];
        if (i == 2 && vis(y1) == 1) t1 = t1 + 1;
    }
    t1 = t1 + d1;

    t2 = (y2 - 1) * 365 + (y2 - 1) / 4 - (y2 - 1) / 100 + (y2 - 1) / 400;
    for (i = 1; i < m2; i++)
    {
        t2 = t2 + md[i];
        if (i == 2 && vis(y2) == 1) t2 = t2 + 1;
    }
    t2 = t2 + d2;

    if (t2 > t1) return t2 - t1;
    return t1 - t2;
}

double avg(int a[], int n)
{
    int i;
    int s = 0;
    for (i = 0; i < n; i++)
    {
        s = s + a[i];
    }
    return (double)s / n;
}

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int a[100];
    int c, n, i;
    int p, m, z;
    int d1, m1, y1, d2, m2, y2;
    int r;

    while (1)
    {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Days between dates\n";
        std::cout << "2. Average of array\n";
        std::cout << "3. Count positive/negative/zero\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";
        std::cin >> c;

        if (c == 0)
        {
            std::cout << "Exit.\n";
            return 0;
        }

        if (c == 1)
        {
            std::cout << "Enter first date (day month year): ";
            std::cin >> d1 >> m1 >> y1;
            std::cout << "Enter second date (day month year): ";
            std::cin >> d2 >> m2 >> y2;
            r = days(d1, m1, y1, d2, m2, y2);
            std::cout << "Days between: " << r << "\n";
        }

        if (c == 2)
        {
            std::cout << "Enter array size: ";
            std::cin >> n;
            if (n <= 0 || n > 100)
            {
                std::cout << "Bad size.\n";
            }
            else
            {
                std::cout << "Enter elements: ";
                for (i = 0; i < n; i++) std::cin >> a[i];
                std::cout << "Average: " << avg(a, n) << "\n";
            }
        }

        if (c == 3)
        {
            std::cout << "Enter array size: ";
            std::cin >> n;
            if (n <= 0 || n > 100) {
                std::cout << "Bad size.\n";
            }
            else {
                std::cout << "Enter elements: ";
                for (i = 0; i < n; i++) std::cin >> a[i];

                p = 0;
                m = 0;
                z = 0;
                for (i = 0; i < n; i++)
                {
                    if (a[i] > 0) p = p + 1;
                    if (a[i] < 0) m = m + 1;
                    if (a[i] == 0) z = z + 1;
                }

                std::cout << "Positive: " << p << "\n";
                std::cout << "Negative: " << m << "\n";
                std::cout << "Zero: " << z << "\n";
            }
        }

        if (c < 0 || c > 3)
        {
            std::cout << "Wrong input.\n";
        }
    }

    return 0;
}