//
//  Theater.c
//
//
//  Created by Zeeshan Abidi on 4/26/18.
//


#include <stdio.h>

//Declare variables
int numOfRows = 15;
int numOfColumns = 30;
const char emptySeat = '#';
const char takenSeat = '*';


void printSeats(char array[numOfRows][numOfColumns]);

int main() {


    char seatingChart[numOfRows][numOfColumns];     // 2D array to hold rows and columns
    //Declare variables
    double prices[numOfRows];
    int userAnswer, row, column, column2;
    double total = 0;
    int seatCount = 0;
    double totalCost = 0;
    int totalSeats = 450;
    int quit = 0;

    //Ask user to set price for each row
    for (int i = 0; i < numOfRows; i++) {
        printf("Please enter the seat cost for row %i: ", i + 1);
        scanf("%lf", &prices[i]);
    }

    //Populate 2D array with emptySeat
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfColumns; j++) {
            seatingChart[i][j] = emptySeat;
        }
    }


    while (quit == 0) {
        printSeats(seatingChart);         //print seating chart
        printf("Menu.\n");
        printf("\t1. Purchase a ticket\n");
        printf("\t2. Check how many seats sold\n");
        printf("\t3. Check Seats that are available in each row\n");
        printf("\t4. Check total seats that are available in the entire auditorium\n");
        printf("\t5. View ticket sales\n");
        printf("\t6. Quit\n");
        printf("----------------------------------------\n");
        printf("Please enter your choice: ");
        scanf("%d", &userAnswer);

        //switch case to handle user input
        switch (userAnswer) {
            //Puchase a ticket
            case 1:
            do {
                printf("Please enter the row #: ");
                scanf("%i", &row);

                if (row < 1 || row > 15) {
                    printf("Error, invalid input\n");
                    break;
                }

                printf("Please enter the column #: ");
                scanf("%i", &column);

                if (column < 0 || column > 9) {
                    printf("Error, invalid input\n");
                    break;
                }

                printf("Please select a coulmn from the range 1-3 :");
                scanf("%i", &column2);

                if (column2 < 1 || column2 > 3) {
                    printf("Invalid input. Enter 1, 2 or 3.\n");
                    break;
                }

                if (seatingChart[row - 1][column + ((column2 - 1) * 10)] == '#') //the seat is available
                {
                    printf(
                           "Ticket cost $%.2f. Do you want to buy?  1 = YES, 0 = NO. ",
                           prices[row - 1]);
                    scanf("%i", &userAnswer);

                    if (userAnswer == 1) {
                        seatingChart[row - 1][column + ((column2 - 1) * 10)] =
                        takenSeat;
                        totalCost += prices[row - 1];
                        printf("Purchase confirmed.\nCurrent total is $%.2f.\n",
                               totalCost);
                        printf("Would you like to purchase another ticket? (1 = YES / 2 = NO): ");
                        scanf("%i", &userAnswer);
                        seatCount++;
                        totalSeats--;
                    } else {
                        break;
                    }
                } else {
                    printf("The seat is already taken.\n");
                }
            } while (userAnswer == 1);
            break;

            case 2:
            printf("Total amount of seats sold: %i\n", seatCount);

            break;

            case 3:
            printf("\nNumber of seats available in each row:");
            for (int i = 0; i < numOfRows; i++) {
                for (int j = 0; j < numOfColumns; j++) {
                    if (j == 0 && i < 9) {
                        printf("Row %i:  ", i + 1);
                    } else if (j == 0 && i >= 9) {
                        printf("Row %i: ", i + 1);
                    }

                    if (seatingChart[i][j] == '#') {
                        seatCount++;
                    }
                }
                printf("%i\n", seatCount);
            }

            break;

            case 4:
            printf("Number of seats available in the theater: %i\n", totalSeats);
            break;

            case 5:
            printf("\nTotal of all ticket sold: $%.2lf\n", totalCost);
            break;

            case 6:
            printf("Existing program, Goodbye!");
            quit = 1;
            break;

            default:
            printf("Error, invalid input.\n");
            break;
        }
    }

    return 0;
}

void printSeats(char array[numOfRows][numOfColumns]) {
    printf("\n\t\t\tSEATS\n");
    printf("\t012345678901234567890123456789\n");

    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfColumns; j++) {
            if (j == 0) {
                printf("Row %i\t", j + 1);
            }
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
