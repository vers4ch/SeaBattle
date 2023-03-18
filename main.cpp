//
//  main.cpp
//  SeaBattle
//
//  Created by Versach on 23:45:47 14.03.2023.
//

#include <iostream>
#include <time.h>
using namespace std;

void ai_field()
{
    srand(time(NULL));
    char field[10][10];
    int cordX, cordY, FcordX, FcordY;
    //reset field(.)
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            field[i][j]='.';
        }
    }

    //set smlShp
    short int stepSMLSHP=4;
    //def
    for(int i=0; i<stepSMLSHP; i++)
    {
        cordX = rand()%10;
        cordY = rand()%10;
        if(field[cordX][cordY]!='#' &&
           field[cordX+1][cordY+1]!='#' &&
           field[cordX-1][cordY-1]!='#' &&
           field[cordX-1][cordY+1]!='#' &&
           field[cordX+1][cordY-1]!='#' &&
           field[cordX][cordY+1]!='#' &&
           field[cordX+1][cordY]!='#' &&
           field[cordX-1][cordY]!='#' &&
           field[cordX][cordY-1]!='#')
            field[cordX][cordY] = '#';
        else
            stepSMLSHP++;
    }

    //set duoShp
    short int stepDUOSHP=3;
    for(int i=0; i<stepDUOSHP; i++)
    {
        int a = rand()%2;
        //rotation
        switch (a)
        {
            //rotation Ver
            case 0:
                cordX = rand()%9;
                cordY = rand()%10;
                if(field[cordX][cordY]!='#' &&
                   field[cordX+1][cordY+1]!='#' &&
                   field[cordX-1][cordY-1]!='#' &&
                   field[cordX-1][cordY+1]!='#' &&
                   field[cordX+1][cordY-1]!='#' &&
                   field[cordX][cordY+1]!='#' &&
                   field[cordX+1][cordY]!='#' &&
                   field[cordX-1][cordY]!='#' &&
                   field[cordX][cordY-1]!='#' &&
                   field[cordX+2][cordY]!='#' &&
                   field[cordX+2][cordY+1]!='#' &&
                   field[cordX+2][cordY-1]!='#')
                {
                    field[cordX][cordY] = '#';
                    field[cordX+1][cordY] = '#';
                }
                else
                    stepDUOSHP++;
                break;
                //rotation Hor.
            case 1:
                cordX = rand()%10;
                cordY = rand()%9;
                if(field[cordX][cordY]!='#' &&
                   field[cordX+1][cordY+1]!='#' &&
                   field[cordX-1][cordY-1]!='#' &&
                   field[cordX-1][cordY+1]!='#' &&
                   field[cordX+1][cordY-1]!='#' &&
                   field[cordX][cordY+1]!='#' &&
                   field[cordX+1][cordY]!='#' &&
                   field[cordX-1][cordY]!='#' &&
                   field[cordX][cordY-1]!='#' &&
                   field[cordX][cordY+2]!='#' &&
                   field[cordX+1][cordY+2]!='#' &&
                   field[cordX-1][cordY+2]!='#')
                {
                    field[cordX][cordY] = '#';
                    field[cordX][cordY+1] = '#';
                }
                else
                    stepDUOSHP++;
                break;
        }
    }

    //set trioShp
    short int stepTRSHP=2;
    for(int i=0; i<stepTRSHP; i++)
    {
        int a = rand()%2;
        //rotation
        switch (a)
        {
            //rotation Ver
            case 0:
                cordX = 1+rand()%8;
                cordY = rand()%10;
                if(field[cordX][cordY]!='#' &&
                   field[cordX+1][cordY+1]!='#' &&
                   field[cordX-1][cordY-1]!='#' &&
                   field[cordX-1][cordY+1]!='#' &&
                   field[cordX+1][cordY-1]!='#' &&
                   field[cordX][cordY+1]!='#' &&
                   field[cordX+1][cordY]!='#' &&
                   field[cordX-1][cordY]!='#' &&
                   field[cordX][cordY-1]!='#' &&
                   field[cordX+2][cordY]!='#' &&
                   field[cordX+2][cordY+1]!='#' &&
                   field[cordX+2][cordY-1]!='#' &&
                   field[cordX-2][cordY-1]!='#' &&
                   field[cordX-2][cordY+1]!='#' &&
                   field[cordX-2][cordY]!='#')
                {
                    field[cordX][cordY] = '#';
                    field[cordX+1][cordY] = '#';
                    field[cordX-1][cordY] = '#';
                }
                else
                    stepTRSHP++;
                break;
                //rotation Hor.
            case 1:
                cordX = rand()%10;
                cordY = 1+rand()%8;
                if(field[cordX][cordY]!='#' &&
                   field[cordX+1][cordY+1]!='#' &&
                   field[cordX-1][cordY-1]!='#' &&
                   field[cordX-1][cordY+1]!='#' &&
                   field[cordX+1][cordY-1]!='#' &&
                   field[cordX][cordY+1]!='#' &&
                   field[cordX+1][cordY]!='#' &&
                   field[cordX-1][cordY]!='#' &&
                   field[cordX][cordY-1]!='#' &&
                   field[cordX][cordY+2]!='#' &&
                   field[cordX+1][cordY+2]!='#' &&
                   field[cordX-1][cordY+2]!='#' &&
                   field[cordX][cordY-2]!='#' &&
                   field[cordX-1][cordY-2]!='#' &&
                   field[cordX+1][cordY-2]!='#')
                {
                    field[cordX][cordY-1] = '#';
                    field[cordX][cordY] = '#';
                    field[cordX][cordY+1] = '#';
                }
                else
                    stepTRSHP++;
                break;
        }
    }

    //set SqShp
    short int stepSQSHP=1;
    for(int i=0; i<stepSQSHP; i++)
    {
        int a = rand()%2;
        //rotation
        switch (a)
        {
            //rotation Ver
            case 0:
                cordX = 1+rand()%7;
                cordY = rand()%10;
                if(field[cordX][cordY]!='#' &&
                   field[cordX+1][cordY+1]!='#' &&
                   field[cordX-1][cordY-1]!='#' &&
                   field[cordX-1][cordY+1]!='#' &&
                   field[cordX+1][cordY-1]!='#' &&
                   field[cordX][cordY+1]!='#' &&
                   field[cordX+1][cordY]!='#' &&
                   field[cordX-1][cordY]!='#' &&
                   field[cordX][cordY-1]!='#' &&
                   field[cordX+2][cordY]!='#' &&
                   field[cordX+2][cordY+1]!='#' &&
                   field[cordX+2][cordY-1]!='#' &&
                   field[cordX-2][cordY-1]!='#' &&
                   field[cordX-2][cordY+1]!='#' &&
                   field[cordX-2][cordY]!='#' &&
                   field[cordX+3][cordY]!='#' &&
                   field[cordX+3][cordY+1]!='#' &&
                   field[cordX+3][cordY-1]!='#')
                {
                    field[cordX-1][cordY] = '#';
                    field[cordX][cordY] = '#';
                    field[cordX+1][cordY] = '#';
                    field[cordX+2][cordY] = '#';
                }
                else
                    stepSQSHP++;
                break;
                //rotation Hor.
            case 1:
                cordX = rand()%10;
                cordY = 1+rand()%7;
                if(field[cordX][cordY]!='#' &&
                   field[cordX+1][cordY+1]!='#' &&
                   field[cordX-1][cordY-1]!='#' &&
                   field[cordX-1][cordY+1]!='#' &&
                   field[cordX+1][cordY-1]!='#' &&
                   field[cordX][cordY+1]!='#' &&
                   field[cordX+1][cordY]!='#' &&
                   field[cordX-1][cordY]!='#' &&
                   field[cordX][cordY-1]!='#' &&
                   field[cordX][cordY+2]!='#' &&
                   field[cordX+1][cordY+2]!='#' &&
                   field[cordX-1][cordY+2]!='#' &&
                   field[cordX][cordY-2]!='#' &&
                   field[cordX-1][cordY-2]!='#' &&
                   field[cordX+1][cordY-2]!='#' &&
                   field[cordX][cordY+3]!='#' &&
                   field[cordX+1][cordY+3]!='#' &&
                   field[cordX-1][cordY+3]!='#')
                {
                    field[cordX][cordY-1] = '#';
                    field[cordX][cordY] = '#';
                    field[cordX][cordY+1] = '#';
                    field[cordX][cordY+2] = '#';
                }
                else
                    stepSQSHP++;
                break;
        }
    }

    //printing field
    cout << "FieldBOT: \n";
    char letter[11] = {'X', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'L', 'J'};
    //def
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<11; j++)
        {
            if(i == 0)
                cout << j << " ";
            else if(j>0 && i>0)
                cout<<field[i-1][j-1]<<" ";
        }
        if(i == 10)
            break;
        cout << endl << letter[i+1] << " ";
    }

    int y, x;
    char l;

    char fieldPOLYG[10][10];
    //def
    for(int i=0; i<10; i++){
        for(int g=0; g<10; g++){
            fieldPOLYG[i][g] = '.';
        }
    }

    char fieldUSER[10][10];
    //def
    for(int i=0; i<10; i++){
        for(int g=0; g<10; g++){
            fieldUSER[i][g] = '.';
        }
    }
    //def
    stepSMLSHP=4;
    for(int i=0; i<stepSMLSHP; i++)
    {
        cordX = rand()%10;
        cordY = rand()%10;
        if(fieldUSER[cordX][cordY]!='#' &&
           fieldUSER[cordX+1][cordY+1]!='#' &&
           fieldUSER[cordX-1][cordY-1]!='#' &&
           fieldUSER[cordX-1][cordY+1]!='#' &&
           fieldUSER[cordX+1][cordY-1]!='#' &&
           fieldUSER[cordX][cordY+1]!='#' &&
           fieldUSER[cordX+1][cordY]!='#' &&
           fieldUSER[cordX-1][cordY]!='#' &&
           fieldUSER[cordX][cordY-1]!='#')
            fieldUSER[cordX][cordY] = '#';
        else
            stepSMLSHP++;
    }

    //set duoShp
    stepDUOSHP=3;
    for(int i=0; i<stepDUOSHP; i++)
    {
        int a = rand()%2;
        //rotation
        switch (a)
        {
            //rotation Ver
            case 0:
                cordX = rand()%9;
                cordY = rand()%10;
                if(fieldUSER[cordX][cordY]!='#' &&
                   fieldUSER[cordX+1][cordY+1]!='#' &&
                   fieldUSER[cordX-1][cordY-1]!='#' &&
                   fieldUSER[cordX-1][cordY+1]!='#' &&
                   fieldUSER[cordX+1][cordY-1]!='#' &&
                   fieldUSER[cordX][cordY+1]!='#' &&
                   fieldUSER[cordX+1][cordY]!='#' &&
                   fieldUSER[cordX-1][cordY]!='#' &&
                   fieldUSER[cordX][cordY-1]!='#' &&
                   fieldUSER[cordX+2][cordY]!='#' &&
                   fieldUSER[cordX+2][cordY+1]!='#' &&
                   fieldUSER[cordX+2][cordY-1]!='#')
                {
                    fieldUSER[cordX][cordY] = '#';
                    fieldUSER[cordX+1][cordY] = '#';
                }
                else
                    stepDUOSHP++;
                break;
                //rotation Hor.
            case 1:
                cordX = rand()%10;
                cordY = rand()%9;
                if(fieldUSER[cordX][cordY]!='#' &&
                   fieldUSER[cordX+1][cordY+1]!='#' &&
                   fieldUSER[cordX-1][cordY-1]!='#' &&
                   fieldUSER[cordX-1][cordY+1]!='#' &&
                   fieldUSER[cordX+1][cordY-1]!='#' &&
                   fieldUSER[cordX][cordY+1]!='#' &&
                   fieldUSER[cordX+1][cordY]!='#' &&
                   fieldUSER[cordX-1][cordY]!='#' &&
                   fieldUSER[cordX][cordY-1]!='#' &&
                   fieldUSER[cordX][cordY+2]!='#' &&
                   fieldUSER[cordX+1][cordY+2]!='#' &&
                   fieldUSER[cordX-1][cordY+2]!='#')
                {
                    fieldUSER[cordX][cordY] = '#';
                    fieldUSER[cordX][cordY+1] = '#';
                }
                else
                    stepDUOSHP++;
                break;
        }
    }

    //set trioShp
    stepTRSHP=2;
    for(int i=0; i<stepTRSHP; i++)
    {
        int a = rand()%2;
        //rotation
        switch (a)
        {
            //rotation Ver
            case 0:
                cordX = 1+rand()%8;
                cordY = rand()%10;
                if(fieldUSER[cordX][cordY]!='#' &&
                   fieldUSER[cordX+1][cordY+1]!='#' &&
                   fieldUSER[cordX-1][cordY-1]!='#' &&
                   fieldUSER[cordX-1][cordY+1]!='#' &&
                   fieldUSER[cordX+1][cordY-1]!='#' &&
                   fieldUSER[cordX][cordY+1]!='#' &&
                   fieldUSER[cordX+1][cordY]!='#' &&
                   fieldUSER[cordX-1][cordY]!='#' &&
                   fieldUSER[cordX][cordY-1]!='#' &&
                   fieldUSER[cordX+2][cordY]!='#' &&
                   fieldUSER[cordX+2][cordY+1]!='#' &&
                   fieldUSER[cordX+2][cordY-1]!='#' &&
                   fieldUSER[cordX-2][cordY-1]!='#' &&
                   fieldUSER[cordX-2][cordY+1]!='#' &&
                   fieldUSER[cordX-2][cordY]!='#')
                {
                    fieldUSER[cordX][cordY] = '#';
                    fieldUSER[cordX+1][cordY] = '#';
                    fieldUSER[cordX-1][cordY] = '#';
                }
                else
                    stepTRSHP++;
                break;
                //rotation Hor.
            case 1:
                cordX = rand()%10;
                cordY = 1+rand()%8;
                if(fieldUSER[cordX][cordY]!='#' &&
                   fieldUSER[cordX+1][cordY+1]!='#' &&
                   fieldUSER[cordX-1][cordY-1]!='#' &&
                   fieldUSER[cordX-1][cordY+1]!='#' &&
                   fieldUSER[cordX+1][cordY-1]!='#' &&
                   fieldUSER[cordX][cordY+1]!='#' &&
                   fieldUSER[cordX+1][cordY]!='#' &&
                   fieldUSER[cordX-1][cordY]!='#' &&
                   fieldUSER[cordX][cordY-1]!='#' &&
                   fieldUSER[cordX][cordY+2]!='#' &&
                   fieldUSER[cordX+1][cordY+2]!='#' &&
                   fieldUSER[cordX-1][cordY+2]!='#' &&
                   fieldUSER[cordX][cordY-2]!='#' &&
                   fieldUSER[cordX-1][cordY-2]!='#' &&
                   fieldUSER[cordX+1][cordY-2]!='#')
                {
                    fieldUSER[cordX][cordY-1] = '#';
                    fieldUSER[cordX][cordY] = '#';
                    fieldUSER[cordX][cordY+1] = '#';
                }
                else
                    stepTRSHP++;
                break;
        }
    }

    //set SqShp
    stepSQSHP=1;
    for(int i=0; i<stepSQSHP; i++)
    {
        int a = rand()%2;
        //rotation
        switch (a)
        {
            //rotation Ver
            case 0:
                cordX = 1+rand()%7;
                cordY = rand()%10;
                if(fieldUSER[cordX][cordY]!='#' &&
                   fieldUSER[cordX+1][cordY+1]!='#' &&
                   fieldUSER[cordX-1][cordY-1]!='#' &&
                   fieldUSER[cordX-1][cordY+1]!='#' &&
                   fieldUSER[cordX+1][cordY-1]!='#' &&
                   fieldUSER[cordX][cordY+1]!='#' &&
                   fieldUSER[cordX+1][cordY]!='#' &&
                   fieldUSER[cordX-1][cordY]!='#' &&
                   fieldUSER[cordX][cordY-1]!='#' &&
                   fieldUSER[cordX+2][cordY]!='#' &&
                   fieldUSER[cordX+2][cordY+1]!='#' &&
                   fieldUSER[cordX+2][cordY-1]!='#' &&
                   fieldUSER[cordX-2][cordY-1]!='#' &&
                   fieldUSER[cordX-2][cordY+1]!='#' &&
                   fieldUSER[cordX-2][cordY]!='#' &&
                   fieldUSER[cordX+3][cordY]!='#' &&
                   fieldUSER[cordX+3][cordY+1]!='#' &&
                   fieldUSER[cordX+3][cordY-1]!='#')
                {
                    fieldUSER[cordX-1][cordY] = '#';
                    fieldUSER[cordX][cordY] = '#';
                    fieldUSER[cordX+1][cordY] = '#';
                    fieldUSER[cordX+2][cordY] = '#';
                }
                else
                    stepSQSHP++;
                break;
                //rotation Hor.
            case 1:
                cordX = rand()%10;
                cordY = 1+rand()%7;
                if(fieldUSER[cordX][cordY]!='#' &&
                   fieldUSER[cordX+1][cordY+1]!='#' &&
                   fieldUSER[cordX-1][cordY-1]!='#' &&
                   fieldUSER[cordX-1][cordY+1]!='#' &&
                   fieldUSER[cordX+1][cordY-1]!='#' &&
                   fieldUSER[cordX][cordY+1]!='#' &&
                   fieldUSER[cordX+1][cordY]!='#' &&
                   fieldUSER[cordX-1][cordY]!='#' &&
                   fieldUSER[cordX][cordY-1]!='#' &&
                   fieldUSER[cordX][cordY+2]!='#' &&
                   fieldUSER[cordX+1][cordY+2]!='#' &&
                   fieldUSER[cordX-1][cordY+2]!='#' &&
                   fieldUSER[cordX][cordY-2]!='#' &&
                   fieldUSER[cordX-1][cordY-2]!='#' &&
                   fieldUSER[cordX+1][cordY-2]!='#' &&
                   fieldUSER[cordX][cordY+3]!='#' &&
                   fieldUSER[cordX+1][cordY+3]!='#' &&
                   fieldUSER[cordX-1][cordY+3]!='#')
                {
                    fieldUSER[cordX][cordY-1] = '#';
                    fieldUSER[cordX][cordY] = '#';
                    fieldUSER[cordX][cordY+1] = '#';
                    fieldUSER[cordX][cordY+2] = '#';
                }
                else
                    stepSQSHP++;
                break;
        }
    }
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
        cout << "\nКоличество # у Вас: " << n << endl;
        cout << "Количество # у Бота: " << 20-r << endl;
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

        //printing PlayerField
        cout << "\n\nYou field: \n";
        char letter[11] = {'X', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'L', 'J'};
        for(int i=0; i<11; i++)
        {
            for(int j=0; j<11; j++)
            {
                if(i == 0)
                    cout << j << " ";
                else if(j>0 && i>0)
                    cout<<fieldUSER[i-1][j-1]<<" ";
            }
            if(i == 10)
                break;
            cout << endl << letter[i+1] << " ";
        }

        cout << "\n\nНаводка" << endl;
        cout << "Буква: ";
        cin >> l;
        for(int i=0; i<11; i++)
        {
            if(letter[i] == l)
                x = i;
        }
        cout << "Цифра: ";
        cin >> y;
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        if(field[x-1][y-1]=='#')
        {
            fieldPOLYG[x-1][y-1] = 'X';
            system("clear");
            cout << "\nПопадание!\n";
            cout << endl << "Map: \n";
            for(int i=0; i<11; i++)
            {
                for(int j=0; j<11; j++)
                {
                    if(i == 0)
                        cout << j << " ";
                    else if(j>0 && i>0)
                        cout<<fieldPOLYG[i-1][j-1]<<" ";
                }
                if(i == 10)
                    break;
                cout << endl << letter[i+1] << " ";
            }
        }
        else
        {
            fieldPOLYG[x-1][y-1] = '@';
            system("clear");
            cout << "\nПромах!\n";
            cout << endl;
            for(int i=0; i<11; i++)
            {
                for(int j=0; j<11; j++)
                {
                    if(i == 0)
                        cout << j << " ";
                    else if(j>0 && i>0)
                        cout<<fieldPOLYG[i-1][j-1]<<" ";
                }
                if(i == 10)
                    break;
                cout << endl << letter[i+1] << " ";
            }


            //def
            short int stepRandF=1;
            for(int i=0; i<stepRandF; i++)
            {
                FcordX = rand()%10;
                FcordY = rand()%10;
                if(fieldUSER[FcordX][FcordY] == '#')
                {
                    fieldUSER[FcordX][FcordY] = 'X';
                    cout << "\n\nБот попал!";
                    stepRandF++;
                }
                if(fieldUSER[FcordX][FcordY] == '@')
                    stepRandF++;
                if(fieldUSER[FcordX][FcordY] == '.')
                {
                    fieldUSER[FcordX][FcordY] = '@';
                    cout << "\n\nБот промахнулся!";
                }
            }
        }
    }
}

int main()
{
    //точка возрата
    cout << "\t\tSeaBattle\n\n";
    ai_field();
    return 0;
}
