#include <iostream>
#include <string>
using namespace std;


class Engine //при помощи данного класса будет демонстрироваться агрегация
{
private:
	string engineType;
	int horsePowers;

public:
	Engine()
	{
		//пустой конструктор,чтобы компилятор не ругался
	}

	//работа сетеорв и гетеров

	void SetEngineType(string orderedEngineType)
	{
		engineType = orderedEngineType;
	}

	string GetEngineType()
	{
		return engineType;
	}
	

	void SetHorsePowers(int orderedHorsePowers)
	{
		horsePowers = orderedHorsePowers;
	}

	int GetHorsePowers()
	{
		return horsePowers;
	}



	//работа конструктора

	Engine(string orderedEngineType, int orderedHorsePowers) 
	{
		engineType = orderedEngineType;
		horsePowers = orderedHorsePowers;
	}

	//вывод заказанного двигателя

	void OrderedEngine() 
	{
		cout << "Тип двигателя: " + engineType + "\nМощность: " + to_string(horsePowers) + " л.с." << endl; 
	}
};

class Auto 
{
private:
	string autoBrand, bodyNumber;
	int mileage;
	bool roadAccident;
	Engine currentEngine;
	


	string Crash() //функция, строго определяющая была ли машина в аварии
	{
		if (roadAccident) return "да";
		else return "нет";
	}



	class Wheels  //при помощи данного класса будет демонстрироваться композиция
	{
	private:
		string wheelBrand;
		int wheelSize;

	public:
		Wheels(string orderedBrand, int orderedSize)
		{
			wheelBrand = orderedBrand;
			wheelSize = orderedSize;
		}
		
		
		string GetWheelBrand() 
		{
			return wheelBrand;
		}

		int GetWheelSize() 
		{
			return wheelSize;
		}

		void WheelsReview() 
		{
			cout << "Колёса от: " << wheelBrand << "\nДиаметр: " << to_string(wheelSize) << " дюймов" << endl;
		}

	};

	Wheels currentWheels = Wheels("Spin Tiers", 24);
	//Wheels currentWheels("BBS", 17) не понимаю,почему такая запсь не работает

public:
	Auto(string orderedBrand, string currentBodyNumber,bool wasInAccident, int currentMileage, Engine orderedEngine)
	{
		autoBrand = orderedBrand;
		bodyNumber = currentBodyNumber;
		mileage = currentMileage;
		roadAccident = wasInAccident;
		currentEngine = orderedEngine;
	}


	void AutoReview() 
	{
		cout << "Марка авто: " << autoBrand << "\nНомер кузова: " << bodyNumber << "\nПробег: " << to_string(mileage) << " км\nБыла в ДТП: " << Crash() << endl;
		cout << "Тип двигателя: " << currentEngine.GetEngineType() << "\nМощность двигателя: " << to_string(currentEngine.GetHorsePowers()) << " л.с." << endl;
		currentWheels.WheelsReview();
	}
};



int main()
{
	setlocale(LC_ALL, "Russian");
	

	Engine diesel; //пустой конструктор не имеет параметров и не ругается
	diesel.SetEngineType("Diesel");
	diesel.SetHorsePowers(450);

	Engine gas("Gas engine", 180); //переопределённый/перегруженный конструктор принял параметры и тоже не ругается
	
	
	Auto NewAuto("BMW", "EX-234-AA-56781-BW", false, 187000, gas); //примеры объектов класса с использованием агрегации и композиции
	NewAuto.AutoReview();

	cout << endl << endl;
	cout << endl << endl;

	Auto AnotherAuto("Kenworth", "ST-777-BD-90345", true, 345100, diesel);
	AnotherAuto.AutoReview();
	


}