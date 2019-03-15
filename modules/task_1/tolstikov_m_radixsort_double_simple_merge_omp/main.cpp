// Copyright 2019 Tolstikov Maksim
// RadixSort with simple merge (double)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <climits>

void CountingSort(double *inp, double *out, int byteNum, int size) {
    unsigned char *mas = (unsigned char *)inp;
    int counter[256];
    int tem;
    memset(counter, 0, sizeof(int) * 256);
    for (int i = 0; i < size; i++)
        counter[mas[8 * i + byteNum]]++;
    int j = 0;
    for (; j < 256; j++) {
        if (counter[j] != 0)
            break;
    }
    tem = counter[j];
    counter[j] = 0;
    j++;
    for (; j < 256; j++) {
        int b = counter[j];
        counter[j] = tem;
        tem += b;
    }
    for (int i = 0; i < size; i++) {
        out[counter[mas[8 * i + byteNum]]] = inp[i];
        counter[mas[8 * i + byteNum]]++;
    }
}

void LSDSortDouble(double *inp, int size) {
    double *out = new double[size];
    for (int i = 0; i < 8; i += 2) {
        CountingSort(inp, out, i, size);
        CountingSort(out, inp, i + 1, size);
    }
    delete[] out;
}

void MSDSortDouble(double *inp, int size) {
    double *out = new double[size];
    for (int i = 7; i >= 0; i -= 2) {
        CountingSort(inp, out, i, size);
        CountingSort(out, inp, i - 1, size);
    }
    delete[] out;
}

void CheckingSort(double *mas, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (mas[i] > mas[i + 1]) {
            std::cout << "Sort is incorrecrtly" << std::endl;
            break;
        }
    }
    std::cout << "Sort is correcrtly" << std::endl;
}

void PrintArray(double *array, int size) {
    if (size < 10) {
        for (int i = 0; i < size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}

void GenerateArray(double *mas, int size) {
    int b = 100;
    int a = 0;
    for (int i = 0; i < size; i++) {
<<<<<<< HEAD
        mas[i] = static_cast<double>(std::rand())*(b - a + 1) / RAND_MAX + a;
=======
        mas[i] = static_cast<double>(rand_r())*(b - a + 1) / RAND_MAX + a;
>>>>>>> fix styles code
    }
}

void CopyArray(double *mas, int size, double *tmpmas) {
    for (int i = 0; i < size; i++)
        tmpmas[i] = mas[i];
}

int main(int argc, char *argv[]) {
    double time_lsd = 0;
    double time_msd = 0;
    int size = 9;
    std::srand((unsigned)time(NULL));
    double *mas, *tmpmas;
    if (argc == 3)
        if (strcmp(argv[1], "-size") == 0)
            size = atoi(argv[2]);
    mas = new double[size];
    tmpmas = new double[size];
    GenerateArray(mas, size);

    if (mas == NULL) {
        std::cout << "Error! Incorrect input data for array";
        return -1;
    }

    CopyArray(mas, size, tmpmas);
    PrintArray(mas, size);
    time_lsd = clock();
    LSDSortDouble(mas, size);
    time_lsd = (clock() - time_lsd) / static_cast<double>(CLOCKS_PER_SEC);
    time_msd = clock();
    MSDSortDouble(tmpmas, size);
    time_msd = (clock() - time_msd) / static_cast<double>(CLOCKS_PER_SEC);
    PrintArray(mas, size);
    PrintArray(tmpmas, size);
    std::cout << "LSD ";
    CheckingSort(mas, size);
    std::cout << "MSD ";
    CheckingSort(tmpmas, size);
    std::cout << "Execution time LSD sort: " << time_lsd << std::endl;
    std::cout << "Execution time MSD sort: " << time_msd << std::endl;

    delete[] mas;
    return 0;
}
