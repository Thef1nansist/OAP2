#include <iostream>
#include <limits>
#include <clocale>

#define ArrSize 100

void output();
void add();
void del();
void change();
void stat();

struct Students
{
    char name[255];
    int numExams;
    int examScore[10];
};

struct Students listOfStudents[ArrSize];
struct Students eraser;

int size = 0;

int main() {
    setlocale(LC_ALL, "ru");
    int choice;
    while (true) {
               printf("\n\t\tСтудентны:\n\t\t1 - Добавить информацию\n\t\t2 - Вывод статистики\n\t\t3 - Добавить нового студента\n\t\t4 - Изменить информацию\n\t\t5 -Удалить студента\n\t\t6 - Выход\n\t\tВыберите:\t");
        std::cin >> choice;
        switch (choice) {
        case 1: output(); break;
        case 2: stat(); break;
        case 3: add(); break;
        case 4: change(); break;
        case 5: del(); break;
        case 6: exit(0); break;
        default: printf("\n\t\tНекоректоно знаечние!"); break;
        }
    }
}

void output() {
    int choice;
    printf("\n\n\t\t\tГЛАВНОЕ МЕНЯ:\n\t\t1 - Получить информацию об 1 студенте\n\t\t2 - Получить информацию о всех студентах\n\t\tCHOICE:\t");
    std::cin >> choice;
    switch (choice) {
    case 1: {
        char NChoice[255];
        printf("\n\n\t\tВведите ФИО студента:\t");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        gets_s(NChoice);
        for (int i = 0; i < size; i++) {
            if (strcmp(NChoice, listOfStudents[i].name) == 0) {
                printf("\n\t\t........ВЫВОД........\n\t\t  Номер студента: %d\n\t\tФИО студента: %s\n\t\tКоличесвто экзаменов: %d\n\t\tОценки за экзамены:\n\t\t", i + 1, listOfStudents[i].name, listOfStudents[i].numExams);
                for (int j = 0; j < listOfStudents[i].numExams; j++)
                    printf("%d ", listOfStudents[i].examScore[j]);
                printf("\n\t\t......................\n\n");
            }
        }
    } break;
    case 2: {
        for (int i = 0; i < size; i++) {
            printf("\n\n\t\t........ВЫВОД........\n\t\tНомер студента: %d\n\t\tФИО студента: %s\n\t\tКоличесвто экзаменов: %d\n\t\tОценки за экзамены: ", i + 1, listOfStudents[i].name, listOfStudents[i].numExams);
            for (int j = 0; j < listOfStudents[i].numExams; j++)
                printf("%d ", listOfStudents[i].examScore[j]);
            printf("\n\t\t......................\n\n");
        }
    } break;
    default: printf("Некорректное значение "); break;
    }
}

void add() {
    printf("\n\t\tВведите информацию:");
    if (size < ArrSize) {
        printf("\n\t\tНомер студента: %d", size + 1);
        printf("\n\t\tФИО студента:\t");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        gets_s(listOfStudents[size].name, 255);
        printf("\t\tВведите количество экзаменов:\t");
        std::cin >> listOfStudents[size].numExams;
        printf("\t\tВведите оценки за экзамены:\t\n");
        for (int i = 0; i < listOfStudents[size].numExams; i++) {
            printf("\t\t%d: ", i + 1);
            std::cin >> listOfStudents[size].examScore[i];
        }
        size++;
    }
    else {
        printf("\n\n\t\t...........Перемолнен!!!...........\n\n");
    }
}

void del() {
    char choice[255];
    printf("\n\t\tВведите ФИО:\t");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gets_s(choice, 255);
    if (strcmp(choice, "ALL") != 0) {
        for (int i = 0; i < size; i++)
            if (strcmp(choice, listOfStudents[i].name) == 0) {
                for (int j = i; j < size; j++)
                    listOfStudents[j] = listOfStudents[j + 1];
                size--;
            }
    }
    else {
        for (int i = 0; i < size; i++)
            listOfStudents[i] = eraser;
        size = 0;
    }
    printf("\n\t\tГОТОВО\n\t\t");
}

void change() {
    char choice[255];
    int ParChoice;
    printf("\n\t\tВведите ФИО:\t");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gets_s(choice);
    for (int i = 0; i < size; i++) {
        if (strcmp(listOfStudents[i].name, choice) == 0) {
            do
            {
                printf("\n\t\tВВедите:\n\t\t1 - Изменить ФИО\n\t\t2 - Изменить количество экзаменов\n\t\t3 - Изменить сами оценки\n\t\t4 - Конец изменений\n\t\tChoice:\t");
                std::cin >> ParChoice;
                switch (ParChoice) {

                case 1: {
                    printf("\n\t\tВведите новое имя: ");
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    gets_s(listOfStudents[i].name);
                } break;

                case 2: {
                    printf("\n\t\tВведите новое кол-во экзаменов: ");
                    std::cin >> listOfStudents[i].numExams;
                } break;

                case 3:
                {
                    printf("\n\t\tВведиет новые знаечния:\n");
                    for (int j = 0; j < listOfStudents[i].numExams; j++) {
                        printf("\t\t%d: ", j + 1);
                        std::cin >> listOfStudents[i].examScore[j];
                    }

                }break;
                case 4: break;
                default: printf("Некорректное значение!"); break;
                }
            } while (ParChoice != 4);
        }
    }
}

void stat() {
    float count = 0;
    float countStudents = 0;
    for (int i = 0; i < size; i++) {
        count = 0;
        for (int j = 0; j < listOfStudents[i].numExams; j++) {
            if (listOfStudents[i].examScore[j] >= 5)
                count++;
            if (j + 1 == listOfStudents[i].numExams && count == listOfStudents[i].numExams)
                countStudents++;
        }
    }
    printf("\n\t\t.....Статистика....\n\t\tУспеваемость студентов: %10.2f %%\n\t\t....................\n\n", (countStudents / (size)) * 100);
}