#include <stdio.h>

int main(void) {
    int current_time;
    printf("What is the current time: \n");
    scanf("%d", &current_time);

    int hours_wait_for_alarm;
    printf("How many hours to wait for the alarm: \n");
    scanf("%d", &hours_wait_for_alarm);

    int alarm_time = (current_time + hours_wait_for_alarm) % 24;

    printf("Your alarm is set as: %d.\n", alarm_time);
    return 0;
}
