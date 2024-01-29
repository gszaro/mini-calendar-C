#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add) {
    int days_left_in_month;

    while (days_left_to_add > 0) {
        days_left_in_month = days_in_month[*mm] - *dd;

        if (*mm == 2 && is_leap_year(*yy)) {
            days_left_in_month += 1;
        }

        if (days_left_to_add > days_left_in_month) {
            // Move to the first day of the next month
            days_left_to_add -= (days_left_in_month + 1);
            *dd = 1;

            // If the last month was December, cycle back to January and increase the year
            if (*mm == 12) {
                *mm = 1;
                *yy += 1;
            } else {
                // Otherwise, increase the current month by 1
                *mm += 1;
            }
        } else {
            // Otherwise, increase the current day by days_left_to_add
            *dd += days_left_to_add;
            days_left_to_add = 0;  // Exit the loop since all days are added
        }
    }
}

int main() {
    int mm, dd, yy, days_left_to_add;

    printf("Please enter a date between the years 1800 and 10000 in the format mm dd yy and provide the number of days to add to this date: ");
    scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add);

    add_days_to_date(&mm, &dd, &yy, days_left_to_add);

    printf("Updated date: %d-%02d-%02d\n", yy, mm, dd);

    return 0;
}
