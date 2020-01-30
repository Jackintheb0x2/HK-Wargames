


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void AICalculation()
{
	srand(static_cast<unsigned int>(time(0)));

	int random[63];
	
	//this will be where the target is located
	int targetLocation = rand() % 64 + 1;
	int	AI_binary_searchGridLowNumber = 1;
	int AI_binary_searchGridHighNumber = 64;
	int AI_random_searchGridLowNumber = 1;
	int AI_random_searchGridHighNumber = 64;

	int AI_random_tries = 0;
	int AI_random_prediction = 0;
	int AI_binary_tries = 0;
	int AI_binary_prediction = 0;
	int AI_linear_tries = 0;
	int AI_linear_prediction = 0;
	int human_tries = 0;
	int human_prediction = 0;

	cout << "\n\n\t\t WELCOME TO DRONE HUNTER 3000!\n\n";

	//*******************************Human Calculation ************************************
	do
	{
		human_tries++;
		//this is where the AI takes a guess
		cout << "\n******************************************************************\n";
		cout << "Where do you think the enemy is? :>";
		cin >> human_prediction;

		//human_prediction = ((human_searchGridHighNumber - human_searchGridLowNumber) / 2) + human_searchGridLowNumber;

		if (human_prediction > targetLocation)
		{
			cout << "\nToo high!\n";
			//human_searchGridHighNumber = human_prediction - 1; 
		}
		else if (human_prediction < targetLocation)
		{
			cout << "\nToo low!\n";
			//human_searchGridLowNumber = human_prediction + 1;
		}
		else
		{
			cout << "\nYou got it! It took you " << human_tries << " tries\n";
			break;
		}

	} while (human_prediction != targetLocation);


	cout << "\nLaunch Random AI ";
	system("Pause");

	//*******************************Random Calculation ************************************
	do
	{
		AI_random_tries++;
		//this is where the AI takes a guess
		cout << "\n******************************************************************\n";
		cout << "The real target location is at: " << targetLocation << "\n";
		//this is where the AI takes a guess
		cout << "The AI thinks the target is at: " << AI_random_prediction;

		AI_random_prediction = rand() % 64 + 1;
		//AI_random_prediction = ((AI_random_searchGridHighNumber - AI_random_searchGridLowNumber) / 2) + AI_random_searchGridLowNumber;

		if (AI_random_prediction > targetLocation)
		{
			cout << "\nToo high!\n";
			//AI_random_searchGridHighNumber = AI_random_prediction - 1; 
		}
		else if (AI_random_prediction < targetLocation)
		{
			cout << "\nToo low!\n";
			//AI_random_searchGridLowNumber = AI_random_prediction + 1;
		}
		else
		{
			cout << "\nYou got it! It took you " << AI_random_tries << " tries\n";
			break;
		}

	} while (AI_random_prediction != targetLocation);


	cout << "\nLaunch Linear AI ";
	system("Pause");
	
	//********************Linear Calculation********************************

	cout << "\n\n";
	do
	{
		AI_linear_tries++;
		cout << "\n******************************************************************\n";
		cout << "The real target location is at: " << targetLocation << "\n";
		//this is where the AI takes a guess
		AI_linear_prediction++;
		cout << "The AI thinks the target is at: " << AI_linear_prediction;



		if (AI_linear_prediction > targetLocation)
		{
			cout << "\nToo high!\n";
			
		}
		else if (AI_linear_prediction < targetLocation)
		{
			cout << "\nToo low!\n";
			
		}
		else
		{
			cout << "\nYou got it! It took the AI " << AI_linear_tries << " tries\n";
			break;
		}

	} while (AI_linear_prediction != targetLocation);


	cout << "\nLaunch Binary AI ";
	system("Pause");
	//********************Binary Calculation********************************
	cout << "\n\n";
	do
	{
		AI_binary_tries++;
		cout << "\n******************************************************************\n";
		cout << "The real target location is at: " << targetLocation << "\n";
		//this is where the AI takes a guess
		AI_binary_prediction = ((AI_binary_searchGridHighNumber - AI_binary_searchGridLowNumber) / 2) + AI_binary_searchGridLowNumber;
		cout << "The AI thinks the target is at: " << AI_binary_prediction;

		

		if (AI_binary_prediction > targetLocation)
		{
			cout << "\nToo high!\n";
			AI_binary_searchGridHighNumber = AI_binary_prediction - 1;
		}
		else if (AI_binary_prediction < targetLocation)
		{
			cout << "\nToo low!\n";
			AI_binary_searchGridLowNumber = AI_binary_prediction + 1;
		}
		else
		{
			cout << "\nYou got it! It took the AI " << AI_binary_tries << " tries\n";
			break;
		}

	} while (AI_binary_prediction != targetLocation);

	
}
int menu()
{
	int userChoice;
	cout << "\n\nEnter 1 for playing the game\n";
	cout << "Enter 2 for exiting the program\n";
	cin >> userChoice;
	return userChoice;
}
int main()
{
	int choice = menu();
	do
	{
		
		if (choice == 1)
		{
			AICalculation();
		}
		else
		{
			cout << "Try Again!\n\n";
			choice = menu();
		}
	} while (choice != 2);
	
	return 0;
}