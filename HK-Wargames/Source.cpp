


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void AICalculation()
{
	

	int random[64];//this array will be used for the random AI 
	int const length = (sizeof(random) / sizeof(*random));//this is the length of the array for the random Array
	
	//this will be where the target is located
	int const targetLocation = rand() % 64 + 1;
	int	AI_binary_searchGridLowNumber = 1;//this is the lowest number the AI can choose for the Binary AI
	int AI_binary_searchGridHighNumber = 64;//this is the highest number the AI can choose for the Binary AI

	int AI_random_tries = 0;//this is for the amount of tries the random AI has taken
	int AI_random_prediction = 0;//the is the guess for the random AI
	int AI_binary_tries = 0;//this is for the amount of tries the binary AI has taken
	int AI_binary_prediction = 0;//the is the guess for the binary AI
	int AI_linear_tries = 0;//this is for the amount of tries the linear AI has taken
	int AI_linear_prediction = 0;//the is the guess for the linear AI
	int human_tries = 0;//this is for the amount of tries the human has taken
	int human_prediction = 0;//the is the guess for the human

	cout << "\n\n\t\t WELCOME TO DRONE HUNTER 3000!\n\n";

	//*******************************Human Calculation ************************************
	do
	{
		human_tries++;//increases the amount of tries the human takes by one
		//this is where the AI takes a guess
		cout << "\n******************************************************************\n";
		cout << "Where do you think the enemy is? :>";
		cin >> human_prediction;//input human prediction

		if (human_prediction > targetLocation)//says too high if the human guess is higher than the target location
		{
			cout << "\nToo high!\n";
		}
		else if (human_prediction < targetLocation)//says too low if the human guess is higher than the target location
		{
			cout << "\nToo low!\n";
		}
		else//says you got it if the guess is neither higher or lower
		{
			cout << "\nYou got it! It took you " << human_tries << " tries\n";
			break;//breaks the loop and moves onto the next AI
		}

	} while (human_prediction != targetLocation);


	cout << "\nLaunch Random AI ";
	system("Pause");//waits for any key to be pressed to start the next part of the program

	//*******************************Random Calculation ************************************
	do
	{
		loop://this is a label for the program to go back to
		
		//this is where the AI takes a guess
		AI_random_prediction = rand() % 64 + 1;
		
		cout << "\n******************************************************************\n";
		cout << "The real target location is at: " << targetLocation << "\n";
		cout << "The AI thinks the target is at: " << AI_random_prediction;

		for(int i = 0; i < length; i++)//for loop that runs until it goes through the whole array
		{
			if(random[i] == AI_random_prediction)//if the number was used previously, it goes back to the loop label and picks another number
			{
				cout << "\nYou already tried that number!\n";
				goto loop;//goes to the loop label
				
			}
		}
		//if it gets passed here, it has found a new number
		
		AI_random_tries++;//increases the tries variable by one
		random[AI_random_tries - 1] = AI_random_prediction;//adds the new number into the array
		
		if (AI_random_prediction > targetLocation)//if the guess is too high
		{
			cout << "\nToo high!\n";
		}
		else if (AI_random_prediction < targetLocation)//if the guess is too low
		{
			cout << "\nToo low!\n";
		}
		else if(AI_random_prediction == targetLocation)//checks to see if the new number equals the target location
		{
			cout << "\nYou got it! It took you " << AI_random_tries << " tries\n";
			break;//if it does, it stops the loop
		}
		cout << "Number of tries: " << AI_random_tries;
		
		

	} while (AI_random_prediction != targetLocation);


	cout << "\nLaunch Linear AI ";
	system("Pause");//waits for any key to be pressed to start the next part of the program
	
	//********************Linear Calculation********************************

	cout << "\n\n";
	do
	{
		AI_linear_tries++;//increases the amount of tries the linear AI takes by one
		cout << "\n******************************************************************\n";
		cout << "The real target location is at: " << targetLocation << "\n";
		//this is where the AI takes a guess
		AI_linear_prediction++;
		cout << "The AI thinks the target is at: " << AI_linear_prediction;



		if (AI_linear_prediction > targetLocation)//if the guess is too high
		{
			cout << "\nToo high!\n";
			
		}
		else if (AI_linear_prediction < targetLocation)//if the guess is too low
		{
			cout << "\nToo low!\n";
			
		}
		else//if neither than it guesses correctly
		{
			cout << "\nYou got it! It took the AI " << AI_linear_tries << " tries\n";
			break;//stops the loop
		}

	} while (AI_linear_prediction != targetLocation);


	cout << "\nLaunch Binary AI ";
	system("Pause");//waits for a key to be pressed before moving onto the next part
	//********************Binary Calculation********************************
	cout << "\n\n";
	do
	{
		AI_binary_tries++;//increases the tries the binary AI takes by one
		cout << "\n******************************************************************\n";
		cout << "The real target location is at: " << targetLocation << "\n";
		//this is where the AI takes a guess
		//it picks between it's highest possible guess and lowest possible guess
		AI_binary_prediction = ((AI_binary_searchGridHighNumber - AI_binary_searchGridLowNumber) / 2) + AI_binary_searchGridLowNumber;
		cout << "The AI thinks the target is at: " << AI_binary_prediction;

		

		if (AI_binary_prediction > targetLocation)//if the guess was too high
		{
			cout << "\nToo high!\n";
			AI_binary_searchGridHighNumber = AI_binary_prediction - 1;//the prediction becomes it's newest high number
		}
		else if (AI_binary_prediction < targetLocation)//if the guess was too low
		{
			cout << "\nToo low!\n";
			AI_binary_searchGridLowNumber = AI_binary_prediction + 1;//the prediction becomes it's newest low number
		}
		else//if neither than the AI guessed correctly
		{
			cout << "\nYou got it! It took the AI " << AI_binary_tries << " tries\n";
			break;//stops the loop
		}

	} while (AI_binary_prediction != targetLocation);


	//prints the results
	cout << "\n\nThe human took " << human_tries << " tries\nThe Random AI took " << AI_random_tries << " tries\nThe Linear AI took " << AI_linear_tries << " tries\nThe Binary AI took " << AI_binary_tries << " tries\n\n";
	if(human_tries < AI_random_tries && human_tries < AI_linear_tries && human_tries < AI_binary_tries)//if the player has the least amount of tries
	{
		cout << "The human has the least amount of tries";
	}
	else if (AI_random_tries < human_tries && AI_random_tries < AI_linear_tries && AI_random_tries < AI_binary_tries)//if the Random AI has the least amount of tries
	{
		cout << "The Random AI has the least amount of tries";
	}
	else if (AI_linear_tries < AI_random_tries && AI_linear_tries < human_tries && AI_linear_tries < AI_binary_tries)//if the Linear AI has the least amount of tries
	{
		cout << "The Linear AI has the least amount of tries";
	}
	else if (AI_binary_tries < AI_random_tries && AI_binary_tries < AI_linear_tries && AI_binary_tries < human_tries)//if the Binary AI has the least amount of tries
	{
		cout << "The Binary AI has the least amount of tries";
	}else//if there is a tie
	{
		cout << "There was a tie!\n";
	}
	
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	bool gameOn = true;
	while(gameOn)//runs if game is on
	{
		loop://loop label for the default option
		char userChoice;//variable that hols the user choice
		cout << "\n\nEnter 1 to play the game\n";
		cout << "Enter 2 to exit the program\n";
		cin >> userChoice;

		switch (userChoice)//switch for menu
		{
			case '1'://if the user enters 1
			{
				AICalculation();
			}
			default:
			{
				cout << "\nTry Again!\n\n";
				goto loop;//goes back up to the top
			}
			case '2'://if the user enters 2
			{
				gameOn = false;
			}
			
		}
		
	}
	
	return 0;
}