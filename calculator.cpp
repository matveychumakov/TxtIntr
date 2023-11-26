#include <iostream>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cout << "Калькулятор" << endl
             << "Чтобы выбрать действие, введите один из параметров:" << endl
             << "-s — сложение всех введённых значений (от 2 до 4 включительно)" << endl
             << "-m — вычитание первого значения из всех последующих введенных значений (от 2 до 4 включительно)" << endl
             << "Для того чтобы продолжить, запустите программу еще раз с нужным параметром и введите значения через пробел" << endl;
        return 0;
    }

    if (argc < 4 || argc > 6)
    {
        cout << "Неверное количество операндов. Введите от 2 до 4 значений." << endl;
        return 1;
    }

    int opt, i, result = 0, x;
    while ((opt = getopt(argc, argv, "m:s:")) != -1)
    {
        switch (opt)
        {
        case 's':
            for (i = 2; i < argc; i++)
            {
                x = strtol(argv[i], NULL, 10);
                result = result + x;
            }
            cout << "Результат: " << result << endl;
            break;

        case 'm':
            result = strtol(argv[2], NULL, 10);
            for (i = 3; i < argc; i++)
            {
                x = strtol(argv[i], NULL, 10);
                result = result - x;
            }
            cout << "Результат: " << result << endl;
            break;
        }
    }

    return 0;
}
