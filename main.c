/*----------------------Использование библиотек---------------------------*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------*/

int main(void)
{
    int raund; /*Целочисленная переменная раунд*/
    int hod_usera;/*Целочисленная переменная ход пользователя*/
    int hod_comp; /*Целочисленная переменная ход компьютера*/
/*--------------------Приветствие пользователя и подсказки для хода-----------*/
    printf("\t\t***Игра с компьютером камень, ножницы, бумага.***\n");
    printf("\nДля выбора используйте цифры: Камень = 1, бумага = 2, ножницы = 3\n");
    printf("\nКамень, ножницы, бумага!\n Раз, два, три!\n");
/*--------------------------------------------------------------------------*/
    for (raund = 0;++raund <= 3;)/*Цикл продолжается три раунда*/
{
        printf("\nВаш ход: \n");
        scanf("%d",&hod_usera);/*Начинаем ход*/
        srand(time(NULL));
        hod_comp = 1+(rand()%3);/*Случайное чсло от 1 до 3*/
        printf("Ход компьютера: %d \n",hod_comp);/*Ход компьютера*/

        if (hod_usera<0 || hod_usera>3)
        printf("Введено не корректное значение.\n");

        if (hod_usera == hod_comp)
        printf("Ничья!\n");

        if (hod_comp==1 && hod_usera==2)
        printf("Вы победили!\n");

        if (hod_comp==2 && hod_usera==3)
        printf("Вы победили!\n");

        if (hod_comp==3 && hod_usera==1)
        printf("Вы проиграли!\n");

        if (hod_comp==2 && hod_usera==1)
        printf("Вы проиграли!\n");

        if (hod_comp==3 && hod_usera==2)
        printf("Вы проиграли!\n");

        if (hod_comp==1 && hod_usera==3)
        printf("Вы проиграли!\n");

        if (hod_usera<0 || hod_usera>3)
        printf("Введено не корректное значение.\n");

        if (hod_usera<0 || hod_usera>3)
        printf("Введено не корректное значение.\n");
}
/*-----------------------------------------------------------------------------*/
    printf("Игра окончено.\n");

return 0;
}
