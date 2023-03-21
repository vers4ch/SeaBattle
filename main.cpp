//
//  main.cpp
//  SeaBattle
//
//  Created by Versach on 23:45:47 14.03.2023.
//

#include <iostream>
#include <time.h>
using namespace std;

char fieldAI[10][10]; //BOT field
char fieldPOLYG[10][10]; //POLYGON field
char letter[11] = {'X', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'L', 'J'}; //Letter
char fieldUSER[10][10]; //USER field

//printing def
void printPLG_USR()
{
    cout << "\n\n      Ваше поле " << "\t\t\t\t" << "   Поле противника " << endl;
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<23; j++)
        {
            if(i == 0 && j<11)
                cout << j << " ";
            else if(j>0 && i>0 && j<11)
                cout<<fieldUSER[i-1][j-1]<<" ";
            else if(j==11)
                cout << "\t\t\t\t";
            else if(j==12 && i>0)
                cout << letter[i] << " ";
            else if(i == 0 && j>11)
                cout << j-12 << " ";
            else if(j>12 && i>0)
                cout<<fieldPOLYG[i-1][j-13]<<" ";
        }
        if(i == 10)
            break;
        cout << endl << letter[i+1] << " ";
    }
}

//reseting arrays
void reset(char arr[10][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            arr[i][j]='.';
        }
    }
}

//randing field
void rand_field(char arr[10][10])
{
    srand(unsigned (time(NULL)));
    int cordX, cordY, FcordX, FcordY, checker = 1;
    reset(arr);
    for(int i = 0; i < 1; i++) {
        //set smlShp
        short int stepSMLSHP = 4;
        for (int i = 0; i < stepSMLSHP; i++) {
            cordX = rand() % 10;
            cordY = rand() % 10;
            if (arr[cordX][cordY] != '#' &&
                arr[cordX + 1][cordY + 1] != '#' &&
                arr[cordX - 1][cordY - 1] != '#' &&
                arr[cordX - 1][cordY + 1] != '#' &&
                arr[cordX + 1][cordY - 1] != '#' &&
                arr[cordX][cordY + 1] != '#' &&
                arr[cordX + 1][cordY] != '#' &&
                arr[cordX - 1][cordY] != '#' &&
                arr[cordX][cordY - 1] != '#')
                arr[cordX][cordY] = '#';
            else
                stepSMLSHP++;
        }
        //set duoShp
        short int stepDUOSHP = 3;
        for (int i = 0; i < stepDUOSHP; i++) {
            int a = rand() % 2;
            //rotation
            switch (a) {
                //rotation Ver
                case 0:
                    cordX = rand() % 9;
                    cordY = rand() % 10;
                    if (arr[cordX][cordY] != '#' &&
                        arr[cordX + 1][cordY + 1] != '#' &&
                        arr[cordX - 1][cordY - 1] != '#' &&
                        arr[cordX - 1][cordY + 1] != '#' &&
                        arr[cordX + 1][cordY - 1] != '#' &&
                        arr[cordX][cordY + 1] != '#' &&
                        arr[cordX + 1][cordY] != '#' &&
                        arr[cordX - 1][cordY] != '#' &&
                        arr[cordX][cordY - 1] != '#' &&
                        arr[cordX + 2][cordY] != '#' &&
                        arr[cordX + 2][cordY + 1] != '#' &&
                        arr[cordX + 2][cordY - 1] != '#') {
                        arr[cordX][cordY] = '#';
                        arr[cordX + 1][cordY] = '#';
                    } else
                        stepDUOSHP++;
                    break;
                    //rotation Hor.
                case 1:
                    cordX = rand() % 10;
                    cordY = rand() % 9;
                    if (arr[cordX][cordY] != '#' &&
                        arr[cordX + 1][cordY + 1] != '#' &&
                        arr[cordX - 1][cordY - 1] != '#' &&
                        arr[cordX - 1][cordY + 1] != '#' &&
                        arr[cordX + 1][cordY - 1] != '#' &&
                        arr[cordX][cordY + 1] != '#' &&
                        arr[cordX + 1][cordY] != '#' &&
                        arr[cordX - 1][cordY] != '#' &&
                        arr[cordX][cordY - 1] != '#' &&
                        arr[cordX][cordY + 2] != '#' &&
                        arr[cordX + 1][cordY + 2] != '#' &&
                        arr[cordX - 1][cordY + 2] != '#') {
                        arr[cordX][cordY] = '#';
                        arr[cordX][cordY + 1] = '#';
                    } else
                        stepDUOSHP++;
                    break;
            }
        }
        //set trioShp
        short int stepTRSHP = 2;
        for (int i = 0; i < stepTRSHP; i++) {
            int a = rand() % 2;
            //rotation
            switch (a) {
                //rotation Ver
                case 0:
                    cordX = 1 + rand() % 8;
                    cordY = rand() % 10;
                    if (arr[cordX][cordY] != '#' &&
                        arr[cordX + 1][cordY + 1] != '#' &&
                        arr[cordX - 1][cordY - 1] != '#' &&
                        arr[cordX - 1][cordY + 1] != '#' &&
                        arr[cordX + 1][cordY - 1] != '#' &&
                        arr[cordX][cordY + 1] != '#' &&
                        arr[cordX + 1][cordY] != '#' &&
                        arr[cordX - 1][cordY] != '#' &&
                        arr[cordX][cordY - 1] != '#' &&
                        arr[cordX + 2][cordY] != '#' &&
                        arr[cordX + 2][cordY + 1] != '#' &&
                        arr[cordX + 2][cordY - 1] != '#' &&
                        arr[cordX - 2][cordY - 1] != '#' &&
                        arr[cordX - 2][cordY + 1] != '#' &&
                        arr[cordX - 2][cordY] != '#') {
                        arr[cordX][cordY] = '#';
                        arr[cordX + 1][cordY] = '#';
                        arr[cordX - 1][cordY] = '#';
                    } else
                        stepTRSHP++;
                    break;
                    //rotation Hor.
                case 1:
                    cordX = rand() % 10;
                    cordY = 1 + rand() % 8;
                    if (arr[cordX][cordY] != '#' &&
                        arr[cordX + 1][cordY + 1] != '#' &&
                        arr[cordX - 1][cordY - 1] != '#' &&
                        arr[cordX - 1][cordY + 1] != '#' &&
                        arr[cordX + 1][cordY - 1] != '#' &&
                        arr[cordX][cordY + 1] != '#' &&
                        arr[cordX + 1][cordY] != '#' &&
                        arr[cordX - 1][cordY] != '#' &&
                        arr[cordX][cordY - 1] != '#' &&
                        arr[cordX][cordY + 2] != '#' &&
                        arr[cordX + 1][cordY + 2] != '#' &&
                        arr[cordX - 1][cordY + 2] != '#' &&
                        arr[cordX][cordY - 2] != '#' &&
                        arr[cordX - 1][cordY - 2] != '#' &&
                        arr[cordX + 1][cordY - 2] != '#') {
                        arr[cordX][cordY - 1] = '#';
                        arr[cordX][cordY] = '#';
                        arr[cordX][cordY + 1] = '#';
                    } else
                        stepTRSHP++;
                    break;
            }
        }
        //set SqShp
        short int stepSQSHP = 1;
        for (int i = 0; i < stepSQSHP; i++) {
            int a = rand() % 2;
            //rotation
            switch (a) {
                //rotation Ver
                case 0:
                    cordX = 1 + rand() % 7;
                    cordY = rand() % 10;
                    if (arr[cordX][cordY] != '#' &&
                        arr[cordX + 1][cordY + 1] != '#' &&
                        arr[cordX - 1][cordY - 1] != '#' &&
                        arr[cordX - 1][cordY + 1] != '#' &&
                        arr[cordX + 1][cordY - 1] != '#' &&
                        arr[cordX][cordY + 1] != '#' &&
                        arr[cordX + 1][cordY] != '#' &&
                        arr[cordX - 1][cordY] != '#' &&
                        arr[cordX][cordY - 1] != '#' &&
                        arr[cordX + 2][cordY] != '#' &&
                        arr[cordX + 2][cordY + 1] != '#' &&
                        arr[cordX + 2][cordY - 1] != '#' &&
                        arr[cordX - 2][cordY - 1] != '#' &&
                        arr[cordX - 2][cordY + 1] != '#' &&
                        arr[cordX - 2][cordY] != '#' &&
                        arr[cordX + 3][cordY] != '#' &&
                        arr[cordX + 3][cordY + 1] != '#' &&
                        arr[cordX + 3][cordY - 1] != '#') {
                        arr[cordX - 1][cordY] = '#';
                        arr[cordX][cordY] = '#';
                        arr[cordX + 1][cordY] = '#';
                        arr[cordX + 2][cordY] = '#';
                    } else
                        stepSQSHP++;
                    break;
                    //rotation Hor.
                case 1:
                    cordX = rand() % 10;
                    cordY = 1 + rand() % 7;
                    if (arr[cordX][cordY] != '#' &&
                        arr[cordX + 1][cordY + 1] != '#' &&
                        arr[cordX - 1][cordY - 1] != '#' &&
                        arr[cordX - 1][cordY + 1] != '#' &&
                        arr[cordX + 1][cordY - 1] != '#' &&
                        arr[cordX][cordY + 1] != '#' &&
                        arr[cordX + 1][cordY] != '#' &&
                        arr[cordX - 1][cordY] != '#' &&
                        arr[cordX][cordY - 1] != '#' &&
                        arr[cordX][cordY + 2] != '#' &&
                        arr[cordX + 1][cordY + 2] != '#' &&
                        arr[cordX - 1][cordY + 2] != '#' &&
                        arr[cordX][cordY - 2] != '#' &&
                        arr[cordX - 1][cordY - 2] != '#' &&
                        arr[cordX + 1][cordY - 2] != '#' &&
                        arr[cordX][cordY + 3] != '#' &&
                        arr[cordX + 1][cordY + 3] != '#' &&
                        arr[cordX - 1][cordY + 3] != '#') {
                        arr[cordX][cordY - 1] = '#';
                        arr[cordX][cordY] = '#';
                        arr[cordX][cordY + 1] = '#';
                        arr[cordX][cordY + 2] = '#';
                    } else
                        stepSQSHP++;
                    break;
            }
        }
        //checking the number of ships
        int num = 0;
        for(int a = 0; a < 10; a++)
        {
            for(int b = 0; b < 10; b++)
            {
                if(arr[a][b] == '#')
                    num++;
            }
        }
        if(num < 20)
            checker++;
    }
}

void game()
{
    rand_field(fieldAI);
    rand_field(fieldUSER);
    reset(fieldPOLYG);
    int y, x, FcordX, FcordY;
    char l;
    while (1)
    {
        int n=0, r=0;
        for(int i = 0; i<10; i++)
        {
            for(int j = 0; j<10; j++)
            {
                if(fieldUSER[i][j] == '#')
                    n++;
                if(fieldPOLYG[i][j] == 'X')
                    r++;
            }
        }
        if(n == 0)
        {
            system("clear");
            cout << "\n\n\nИгра окончена, Вы проиграли!!!\n\n\n";
            break;
        }
        if(r == 20)
        {
            system("clear");
            cout << "\n\n\nИгра окончена, Вы выиграли!!!\n\n\n";
            break;
        }
        cout << endl;
        printPLG_USR();
        cout << "\n\nНаводка" << endl << "Координаты(первый символ-буква, второй-цифра): ";
        cin >> l >> y;
        for(int i=0; i<11; i++)
        {
            if(letter[i] == l)
                x = i;
        }
        if(fieldAI[x-1][y-1]=='#')
        {
            fieldPOLYG[x-1][y-1] = 'X';
            system("clear");
            cout << "\n\nПопадание!\n\n";
        }
        else
        {
            fieldPOLYG[x-1][y-1] = '@';
            system("clear");
            cout << "\n\nВы не попали по кораблю противника!\n\n";

            //def
            short int stepRandF=1;
            for(int i=0; i<stepRandF; i++)
            {
                FcordX = rand()%10;
                FcordY = rand()%10;
                if(fieldUSER[FcordX][FcordY] == '#')
                {
                    fieldUSER[FcordX][FcordY] = 'X';
                    cout << "Бот попал! ";
                    stepRandF++;
                }
                if(fieldUSER[FcordX][FcordY] == '@')
                    stepRandF++;
                if(fieldUSER[FcordX][FcordY] == '.')
                {
                    fieldUSER[FcordX][FcordY] = '@';
                    cout << "Бот промахнулся!";
                }
            }
        }
    }
}

int main()
{
    cout << "\n\t\t\t\t\t\tSeaBattle\n\n\n";
    game();
    return 0;
}
