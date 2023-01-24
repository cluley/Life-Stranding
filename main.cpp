#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>

bool** arrayCreator(const int rows, const int cols) {
    bool** arr = new bool* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new bool[cols];
    }

    return arr;
}

void printer(bool** arr, const int rows, const int cols) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!arr[i][j])
            {
                std::cout << "-" << '\t';
            }
            else
            {
                std::cout << "*" << '\t';
            }
        }
        std::cout << '\n';
    }

}


void cellChanger(bool** arr, int i, int j, int ctr) {
    if ((ctr < 2 || ctr > 3) && arr[i][j])
    {
        arr[i][j] = false;
    }
    else if (ctr == 3 && !arr[i][j])
    {
        arr[i][j] = true;
    }

}

bool** genChanger(bool** arr, const int rows, const int cols) {
    bool** newArr = arrayCreator(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            newArr[i][j] = arr[i][j];
        }
    }

    int ctr = 0;
    int verge = cols - 1;
    int edge = rows - 1;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 && j == 0)
            {
                ctr = 0;
                if (arr[i][j + 1]) { ++ctr; }
                if (arr[i + 1][j]) { ++ctr; }
                if (arr[i + 1][j + 1]) { ++ctr; }
                cellChanger(newArr, i, j, ctr);
            }
            if (i == 0 && ((j < verge) && (j != 0)))
            {
                ctr = 0;
                if (arr[i][j - 1]) { ++ctr; }
                if (arr[i][j + 1]) { ++ctr; }
                if (arr[i + 1][j - 1]) { ++ctr; }
                if (arr[i + 1][j]) { ++ctr; }
                if (arr[i + 1][j + 1]) { ++ctr; }
                cellChanger(newArr, i, j, ctr);
            }
            if (i == 0 && j == verge)
            {
                ctr = 0;
                if (arr[i][j - 1]) { ++ctr; }
                if (arr[i + 1][j - 1]) { ++ctr; }
                if (arr[i + 1][j]) { ++ctr; }
                cellChanger(newArr, i, j, ctr);
            }
            if (((i != 0) && (i < edge)) && j == 0)
            {
                ctr = 0;
                if (arr[i - 1][j]) { ++ctr; }
                if (arr[i - 1][j + 1]) { ++ctr; }
                if (arr[i][j + 1]) { ++ctr; }
                if (arr[i + 1][j]) { ++ctr; }
                if (arr[i + 1][j + 1]) { ++ctr; }
                cellChanger(newArr, i, j, ctr);
            }
            if (i == edge && j == 0)
            {
                ctr = 0;
                if (arr[i - 1][j]) { ++ctr; }
                if (arr[i - 1][j + 1]) { ++ctr; }
                if (arr[i][j + 1]) { ++ctr; }
                cellChanger(newArr, i, j, ctr);
            }
            if (i == edge && ((j < verge) && (j != 0)))
            {
                ctr = 0;
                if (arr[i - 1][j - 1]) { ++ctr; }
                if (arr[i - 1][j]) { ++ctr; }
                if (arr[i - 1][j + 1]) { ++ctr; }
                if (arr[i][j - 1]) { ++ctr; }
                if (arr[i][j + 1]) { ++ctr; }
                cellChanger(newArr, i, j, ctr);
            }
            if (i == edge && j == verge)
            {
                ctr = 0;
                if (arr[i - 1][j - 1]) { ++ctr; }
                if (arr[i - 1][j]) { ++ctr; }
                if (arr[i][j - 1]) { ++ctr; }
                cellChanger(newArr, i, j, ctr);
            }
            if (((i != 0) && (i < edge)) && j == verge)
            {
                ctr = 0;
                if (arr[i + 1][j - 1]) { ++ctr; }
                if (arr[i + 1][j]) { ++ctr; }
                if (arr[i][j - 1]) { ++ctr; }
                if (arr[i - 1][j - 1]) { ++ctr; }
                if (arr[i - 1][j]) { ++ctr; }
                cellChanger(newArr, i, j, ctr);
            }
            if (i != 0 && j != 0 && i != edge && j != verge)
            {
                ctr = 0;
                if (arr[i - 1][j - 1]) { ++ctr; }
                if (arr[i - 1][j]) { ++ctr; }
                if (arr[i - 1][j + 1]) { ++ctr; }
                if (arr[i][j - 1]) { ++ctr; }
                if (arr[i][j + 1]) { ++ctr; }
                if (arr[i + 1][j - 1]) { ++ctr; }
                if (arr[i + 1][j]) { ++ctr; }
                if (arr[i + 1][j + 1]) { ++ctr; }
                cellChanger(newArr, i, j, ctr);
            }
        }
    }

    return newArr;
}

void arrayAnnihilator(bool**& arr, const int rows, const int cols) {
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
}

int main(int argc, char** argv) {
    std::cout << "Select the cassette(enter number):\n1.Fumarole\n2.R-pentomino" << std::endl;
    std::ifstream idxs;
    int cst;
    std::cin >> cst;
    if(cst == 1)
    {
        idxs.open("Fumarole.txt");
    }
    else if (cst == 2)
    {
        idxs.open("R-pentomino.txt");
    }
    else
    {
        std::cout << "There's no such cassette!" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!idxs.is_open())
    {
        std::cout << "Cassette is broken:(" << std::endl;
        exit(EXIT_FAILURE);
    }

    int rows, cols;
    idxs >> rows >> cols;

    bool** arr = arrayCreator(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = false;
        }
    }

    int idx1; int idx2;
    while (idxs >> idx1 >> idx2)
    {
        arr[idx1][idx2] = true;
    }

    idxs.close();

    printer(arr, rows, cols);

    int clsCtr = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j]) { ++clsCtr; }
        }
    }

    std::cout << "Generation: 1" << ". Alive cells: " << clsCtr << std::endl;

    int area = rows * cols;
    int genCtr = 1;
    int ctr = 0;
    do {
        Sleep(1000);
        bool** newArr = genChanger(arr, rows, cols);

        clsCtr = 0;
        ctr = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (arr[i][j] == newArr[i][j]) { ++ctr; }
                if (newArr[i][j]) { ++clsCtr; }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                arr[i][j] = newArr[i][j];
            }
        }

        std::system("cls");
        printer(newArr, rows, cols);

        ++genCtr;

        std::cout << "Generation: " << genCtr << ". Alive cells: " << clsCtr << std::endl;

        if (ctr == area)
        {
            arrayAnnihilator(newArr, rows, cols);
            std::cout << "The world has stagnated. Game over!" << std::endl;
            break;
        }
        else if (clsCtr == 0)
        {
            arrayAnnihilator(newArr, rows, cols);
            std::cout << "All cells are dead. Game over!" << std::endl;
            break;
        }

    } while (true);

    arrayAnnihilator(arr, rows, cols);

    return 0;
}