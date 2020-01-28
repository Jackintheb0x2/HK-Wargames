


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void AICalculation()
{
	srand(static_cast<unsigned int>(time(0)));

	//this will be where the target is located
	int targetLocation = rand() % 64 + 1;
	int	AI_binary_searchGridLowNumber = 1;
	int AI_binary_searchGridHighNumber = 64;
	int	human_searchGridLowNumber = 1;
	int human_searchGridHighNumber = 64;

	int AI_binary_tries = 0;
	int AI_binary_prediction = 0;
	int human_tries = 0;
	int human_prediction = 0;

	cout << "\n\n\t\t WELCOME TO DRONE HUNTER 3000!\n\n";

	//********************Binary Calculation********************************
	do
	{
		AI_binary_tries++;
		cout << "The real target location is at: " << targetLocation << "\n";
		//this is where the AI takes a guess
		cout << "The AI thinks the target is at: " << AI_binary_prediction << "\n";

		AI_binary_prediction = ((AI_binary_searchGridHighNumber - AI_binary_searchGridLowNumber) / 2) + AI_binary_searchGridLowNumber;

		if (AI_binary_prediction > targetLocation)
		{
			cout << "Too high!\n";
			AI_binary_searchGridHighNumber = AI_binary_prediction - 1;
		}
		else if (AI_binary_prediction < targetLocation)
		{
			cout << "Too low!\n";
			AI_binary_searchGridLowNumber = AI_binary_prediction + 1;
		}
		else
		{
			cout << "You got it! It took the AI " << AI_binary_tries << " tries\n";
			break;
		}

	} while (AI_binary_prediction != targetLocation);

	//*******************************Human Calculation ************************************
	do
	{
		human_tries++;
		cout << "The real target location is at: " << targetLocation << "\n";
		//this is where the AI takes a guess
		cout << "Where do you think the enemy is?\n";
		cin >> human_prediction;

		//human_prediction = ((human_searchGridHighNumber - human_searchGridLowNumber) / 2) + human_searchGridLowNumber;

		if (human_prediction > targetLocation)
		{
			cout << "Too high!\n";
			human_searchGridHighNumber = human_prediction - 1;
		}
		else if (AI_binary_prediction < targetLocation)
		{
			cout << "Too low!\n";
			human_searchGridLowNumber = human_prediction + 1;
		}
		else
		{
			cout << "You got it! It took you " << human_tries << " tries\n";
			break;
		}

	} while (human_prediction != targetLocation);
}

void HumanCalculation()
{
	
}

int main()
{
	int choice;
	do
	{
		
		cout << "Enter 1 for playing the game\n";
		cout << "Enter 2 for exiting the program\n";
		cin >> choice;
		if (choice == 1)
		{
			AICalculation();
		}
		else
		{
			cout << "Try Again!\n\n";
		}
	} while (choice != 2);
	
	return 0;
}