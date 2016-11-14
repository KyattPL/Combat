#include <iostream>   //Biblioteki.
#include <random>
#include <ctime>

using namespace std;   //Standaryzowanie komend.

int main()             //G³ówna funkcja.
{
	mt19937 generateEngine(time(NULL));    //Generowanie liczby.

	int numSurvivors = 0, numZombies = 0, survHealth = 100, zombHealth = 50, survDamage = 25, zombDamage = 25, total = 0;     //Zmienne.
	int numSurvivors2 = 0, numZombies2 = 0, zombHealth2 = 0, survHealth2 = 0, x = 0;

	char customStats;                                       //U¿ytkownik wpisuje y lub n zale¿nie od tego czy chcê modyfikowaæ statystyki.

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

	numSurvivors2 = numSurvivors;                   //Liczba zombie i survivorów przed bitw¹.
	numZombies2 = numZombies;

	total = numSurvivors + numZombies;              //Liczba wszystkich uczestników bitwy.

	for (int i = 0; i <= total; x++)                  //G³ówna pêtla programu.
	{
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

	system("PAUSE");         //Zatrzymanie konsoli.
	return 0;                //Zwrócenie poprawnej wartoœci do systemu.


}