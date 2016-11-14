#include <iostream>   //Biblioteki.
#include <random>
#include <ctime>

using namespace std;   //Standaryzowanie komend.

int main()             //G��wna funkcja.
{
	mt19937 generateEngine(time(NULL));    //Generowanie liczby.

	int numSurvivors = 0, numZombies = 0, survHealth = 100, zombHealth = 50, survDamage = 25, zombDamage = 25, total = 0;     //Zmienne.
	int numSurvivors2 = 0, numZombies2 = 0, zombHealth2 = 0, survHealth2 = 0, x = 0;

	char customStats;                                       //U�ytkownik wpisuje y lub n zale�nie od tego czy chc� modyfikowa� statystyki.

	float survHit = 75, zombHit = 25;

	cout << "** Combat Simulator v.2.0 **\n";

	cout << "Type how many survivors will take part in a combat\n";
	cin >> numSurvivors;

	cout << "Type how many zombies will take part in a combat\n";
	cin >> numZombies;

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

	survHealth2 = survHealth;
	zombHealth2 = zombHealth;

	cout << endl;

	numSurvivors2 = numSurvivors;                   //Liczba zombie i survivor�w przed bitw�.
	numZombies2 = numZombies;

	total = numSurvivors + numZombies;              //Liczba wszystkich uczestnik�w bitwy.

	for (int i = 0; i <= total; x++)                  //G��wna p�tla programu.
	{
		uniform_real_distribution<float> survChance(0, 100);    //Szansa na trafienie przez cz�owieka i zombiego  (od 0-100).
		uniform_real_distribution<float> zombChance(0, 100);

		if (survChance(generateEngine) > zombHit)                      //Je�li wylosuje co� powy�ej szans na atak cz�owieka, to zaatakuje on
		{															  //za ilo�� obra�e� cz�owieka.
			zombHealth = zombHealth - survDamage;


			if (zombHealth <= 0)                                       //Je�li zombie b�dzie mie� 0hp to znaczy, �e umar� i trzeba wstawi� nowego na jego miejsce
			{														  //oraz da� mu pocz�tkow� ilo�� zdrowia.
				numZombies--;
				zombHealth = zombHealth2;

				i++;
			}

		}

		if (numZombies == 0)                                        //Je�li �aden zombie nie pozosta� przy �yciu to zako�cz walk�.
		{
			cout << "Humans won!\n";
			cout << "There are " << numSurvivors << " humans left.\n";
			cout << numZombies2 << " zombies and " << numSurvivors2 - numSurvivors << " survivors lost their lives." << endl << endl;
			cout << "Battle ended in " << x << " turns\n";

			break;           //Przerwanie p�tli.
		}

		if (zombChance(generateEngine) > survHit)					  //Je�li wylosuje co� powy�ej szans na atak zombiego zaatakuje on
		{															  //za ilo�� obra�e� zombie.

			survHealth = survHealth - zombDamage;

			if (survHealth <= 0)										  //Je�li cz�owiek b�dzie mie� 0hp to znaczy, �e umar� i trzeba wstawi� nowego na jego miejsce
			{														  //oraz da� mu pocz�tkow� ilo�� zdrowia.
				numSurvivors--;
				survHealth = survHealth2;

				i++;
			}

		}

		if (numSurvivors == 0)                                      //Je�li �aden cz�owiek nie pozosta� przy �yciu to zako�cz walk�.
		{
			cout << "Zombies won!\n";
			cout << "There are " << numZombies << " zombies left.\n";
			cout << numSurvivors2 << " survivors and " << numZombies2 - numZombies << " zombies lost their lives.\n";
			cout << "Battle ended in " << x << " turns\n";

			break;            //Przerwanie p�tli.
		}
		
	}

	system("PAUSE");         //Zatrzymanie konsoli.
	return 0;                //Zwr�cenie poprawnej warto�ci do systemu.


}