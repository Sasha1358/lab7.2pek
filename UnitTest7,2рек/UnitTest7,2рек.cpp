#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.2pek/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72рек
{
    TEST_CLASS(UnitTest72рек)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int n = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; i++) {
                a[i] = new int[n];
            }

            // Ініціалізація масиву для сортування
            a[0][0] = 5; a[0][1] = 3; a[0][2] = 1;
            a[1][0] = 6; a[1][1] = 4; a[1][2] = 2;
            a[2][0] = 9; a[2][1] = 8; a[2][2] = 7;

            Sort(a, n);

            // Очікуваний результат після сортування
            int expected[n][n] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                Assert:
                    (a[i][j] == expected[i][j]);
                }
            }

            for (int i = 0; i < n; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
    };
}
