#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct letter_class {
    char value;
    int is_opened;
};

void print_table(struct letter_class table[6][6]) {
    for(int i = 0;i<6;i++) {
        for(int j = 0;j<6;j++) {
            if(table[i][j].is_opened==0) {
                printf("| |   ");
            }
            else {
                printf("|%c|   ",table[i][j].value);
            }
        }
        printf("\n\n");
    }
}

int main()
{
    srand(time(0));

    struct letter_class table[6][6];
    int index_1,index_2;
    struct letter_class letter;

    int row1 = 0;
    int column1 = 0;

    int row2 = 0;
    int column2 = 0;

    int opened_card_count = 0;


    for(int i = 0;i<6;i++) {
        for(int j = 0;j<6;j++) {
            letter.value = 'K';
            letter.is_opened = 0;
            table[i][j] = letter;
        }
    }

    char letters[] = "AABBCCDDEEFFGGHHJJWWXXMMNNOOPPRRSSTT";

    for(int i = 0;i<36;i++) {
        while(1) {
            index_1 = rand()%6;
            index_2 = rand()%6;
            if(table[index_1][index_2].value!='K') {
                continue;
            }
            else {
                table[index_1][index_2].value = letters[i];
                break;
            }
        }
    }


    do {
        print_table(table);
        opened_card_count = 0;

        do {
            do {
                printf("Enter the first row and column:");
                scanf("%d%d",&row1,&column1);

                if(row1<0 || row1>6 || column1<0 || column2>6) {
                    printf("Row and column must be between 0 and 6\n");
                }
                else {
                    break;
                }
            } while(1);


            if(table[row1-1][column1-1].is_opened==1) {
                printf("Please enter a value that was not opened.\n");
                continue;
            }
            else {
                break;
            }

        } while(1);

        table[row1-1][column1-1].is_opened = 1;

        system("cls");

        print_table(table);

        do {
            do {
                printf("Enter the second row and column:");
                scanf("%d%d",&row2,&column2);

                if(row2<0 || row2>6 || column2<0 || column2>6) {
                    printf("Row and column must be between 0 and 6\n");
                }
                else {
                    break;
                }
            } while(1);

            if(table[row2-1][column2-1].is_opened==1) {
                printf("Please enter a value that was not opened.\n");
                continue;
            }
            else {
                break;
            }

        } while(1);

        table[row2-1][column2-1].is_opened = 1;

        system("cls");

        print_table(table);

        Sleep(500);

        system("cls");

        if(table[row1-1][column1-1].value != table[row2-1][column2-1].value) {
            table[row1-1][column1-1].is_opened = 0;
            table[row2-1][column2-1].is_opened = 0;
        }

        for(int i = 0;i<6;i++) {
            for(int j = 0;j<6;j++) {
                if(table[i][j].is_opened==1) {
                    opened_card_count++;
                }
            }
        }


        if(opened_card_count==36) {

            printf("\nYou have won the game!!\n");
            printf("\nHere is the table:\n\n");
            print_table(table);

            break;
        }


    } while(1);
    return 0;
}
