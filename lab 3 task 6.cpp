#include<stdio.h>

int main(void)
{
	float totalCalories,fatGrams,caloriesFromFat,fatPercentage;
	printf("Enter total calories: ");
	scanf("%f",&totalCalories);
	printf("Enter fat grams: ");
	scanf("%f",&fatGrams);
	if(totalCalories<0||fatGrams<0)
	{
		printf("Error: Calories and fat grams cannot be negative.\n");
		return 0;
	}
	caloriesFromFat=fatGrams*9;
	if(caloriesFromFat>totalCalories)
	{
		printf("Error: Calories or fat grams were incorrectly entered.\n");
		return 0;
	}
	fatPercentage=(caloriesFromFat/totalCalories)*100;
	printf("Percentage of calories from fat: %.2f%%\n",fatPercentage);
	if(fatPercentage<30)
		printf("This food is low in fat.\n");
}

