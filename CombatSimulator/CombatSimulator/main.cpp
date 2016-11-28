#include <iostream>   //Biblioteki.
#include <random>
#include <ctime>
#include <windows.h>

using namespace std;   //Standaryzowanie komend.

int number1();
int number2();
int customStatsFUN();
void mainLoop(int zombHit, int zombHealth, int survDamage, int total, int numZombies, int zombHealth2, int numSurivors, int numZombies2, int numSurvivors2,int survHit,int zombDamage,int survHealth,int survHealth2);

int main()             //G³ówna funkcja.
{

	int numSurvivors, numZombies, survHealth, zombHealth = 50, survDamage = 25, zombDamage = 25;     //Zmienne.
	int numSurvivors2, numZombies2, zombHealth2, survHealth2, total;

	float survHit = 75, zombHit = 25;

	numSurvivors = number1();
	numZombies = number2();

	if (numSurvivors <= 0 || numZombies <= 0)
	{
		cout << "Please provide correct value.\n";

		system("PAUSE");
		return 0;
	}

	zombHealth, zombDamage, zombHit, survHit, survDamage, survHealth = customStatsFUN();

	survHealth2 = survHealth;
	zombHealth2 = zombHealth;

	cout << endl;

	numSurvivors2 = numSurvivors;                   //Liczba zombie i survivorów przed bitw¹.
	numZombies2 = numZombies;

	total = numSurvivors + numZombies;	//Liczba wszystkich uczestników bitwy.

	system("cls");

	mainLoop(zombHit, zombHealth, survDamage, total, numZombies, zombHealth2, numSurvivors, numZombies2, numSurvivors2, survHit, zombDamage, survHealth, survHealth2);

	system("PAUSE");         //Zatrzymanie konsoli.
	return 0;                //Zwrócenie poprawnej wartoœci do systemu.

}
int number1()
{
	int numSurvivors;

	cout << "** Combat Simulator v.2.0 **\n";

	cout << "Type how many survivors will take part in a combat\n";
	cin >> numSurvivors;

	return numSurvivors;
}
int number2()
{
	int numZombies;

	cout << "Type how many zombies will take part in a combat\n";
	cin >> numZombies;

	return numZombies;
}

int customStatsFUN()
{
	int zombHealth, zombDamage, zombHit, survHealth, survDamage, survHit;
	char customStats;

	cout << "Type 'y' if u want to change survivors and zombie stats, and 'n' if you would like to stick to original.\n";

	cin >> customStats;

	if (customStats == 'y')
	{
		cout << "Zombie health:\n";
		cin >> zombHealth;

		cout << "Zombie Damage:\n";
		cin >> zombDamage;

		cout << "Zombie attack chance:\n";
		cin >> zombHit;

		cout << "Survivor health:\n";
		cin >> survHealth;

		cout << "Survivor Damage:\n";
		cin >> survDamage;

		cout << "Survivor attack chance:\n";
		cin >> survHit;

	}
	else
	{
		zombHealth = 50;
		zombDamage = 25;
		zombHit = 25;
		survHealth = 100;
		survDamage = 25;
		survHit = 75;
	}

	return zombHealth, zombDamage, zombHit, survHealth, survDamage, survHit;
}

void mainLoop(int zombHit, int zombHealth, int survDamage, int total, int numZombies, int zombHealth2, int numSurvivors, int numZombies2, int numSurvivors2, int survHit, int zombDamage, int survHealth, int survHealth2)
{
	int x = 0;

	for (int i = 0; i <= total; x++)                  //G³ówna pêtla programu.
	{
		static mt19937 generateEngine(time(NULL));    //Generowanie liczby.

		uniform_real_distribution<float> survChance(0, 100);    //Szansa na trafienie przez cz³owieka i zombiego  (od 0-100).
		uniform_real_distribution<float> zombChance(0, 100);

		if (survChance(generateEngine) > zombHit)                      //Jeœli wylosuje coœ powy¿ej szans na atak cz³owieka, to zaatakuje on
		{															  //za iloœæ obra¿eñ cz³owieka.
			zombHealth = zombHealth - survDamage;


			if (zombHealth <= 0)                                       //Jeœli zombie bêdzie mieæ 0hp to znaczy, ¿e umar³ i trzeba wstawiæ nowego na jego miejsce
			{														  //oraz daæ mu pocz¹tkow¹ iloœæ zdrowia.
				numZombies--;
				zombHealth = zombHealth2;

				i++;
			}

		}

		if (numZombies == 0)                                        //Jeœli ¿aden zombie nie pozosta³ przy ¿yciu to zakoñcz walkê.
		{
			cout << "Humans won!\n";
			cout << "There are " << numSurvivors << " humans left.\n";
			cout << numZombies2 << " zombies and " << numSurvivors2 - numSurvivors << " survivors lost their lives." << endl << endl;
			cout << "Battle ended in " << x << " turns\n";

			break;           //Przerwanie pêtli.
		}

		if (zombChance(generateEngine) > survHit)					  //Jeœli wylosuje coœ powy¿ej szans na atak zombiego zaatakuje on
		{															  //za iloœæ obra¿eñ zombie.

			survHealth = survHealth - zombDamage;

			if (survHealth <= 0)										  //Jeœli cz³owiek bêdzie mieæ 0hp to znaczy, ¿e umar³ i trzeba wstawiæ nowego na jego miejsce
			{														  //oraz daæ mu pocz¹tkow¹ iloœæ zdrowia.
				numSurvivors--;
				survHealth = survHealth2;

				i++;
			}

		}

		if (numSurvivors == 0)                                      //Jeœli ¿aden cz³owiek nie pozosta³ przy ¿yciu to zakoñcz walkê.
		{
			cout << "Zombies won!\n";
			cout << "There are " << numZombies << " zombies left.\n";
			cout << numSurvivors2 << " survivors and " << numZombies2 - numZombies << " zombies lost their lives.\n";
			cout << "Battle ended in " << x << " turns\n";

			break;            //Przerwanie pêtli.
		}

	}
}