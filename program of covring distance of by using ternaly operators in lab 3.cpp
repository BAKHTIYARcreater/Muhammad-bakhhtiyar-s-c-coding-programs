#include <stdio.h>

int main() {
    int hours, i;
    float distance, totalDistance = 0.0, avgSpeed;

    // Take hours input
    printf("Enter the number of hours the car traveled (1 to 5): ");
    scanf("%d", &hours);

    if (hours < 1 || hours > 5) {
        printf("Error: Time must be between 1 and 5 hours.\n");
        return 0; // Exit program
    }

    // Take distance input for each hour
    for (i = 1; i <= hours; i++) {
        printf("Enter distance covered in hour %d (miles): ", i);
        scanf("%f", &distance);

        if (distance < 0) {
            printf("Error: Distance cannot be negative.\n");
            return 0;
        }

        totalDistance += distance;
    }

    avgSpeed = totalDistance / hours;

    printf("\nTotal Distance: %.2f miles\n", totalDistance);
    printf("Average Speed: %.2f miles/hour\n", avgSpeed);

    return 0;
}
