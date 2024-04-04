
#include <iostream>
using namespace std;

class BankAccount {
private:
	int accountNumber;
	double balance;
	double  interestRate;

public:
	void deposit();
	void withdraw();
	void getBalance();
	void getInterestRate();
	void setInterestRate();
	void getAccountNamber();

	BankAccount(int accountNumber, double balance, double  interestRate) {
		this->accountNumber = accountNumber;
		this->balance = 0;
		this->interestRate = 0;
	}

	friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

void BankAccount::deposit() {
	cout << "Введите номер счета: ";
	cin >> this->accountNumber;
	cout << "Внесите деньги: ";
	cin >> this->balance;
	cout << "Счет открыт!!!";
}

void BankAccount::getBalance() {
	cout << endl << "Текущее состояние счета: " << endl;
	cout << "Номер счета: " << this->accountNumber;
	cout << "Количество средств на счете: " << this->balance;
}

void BankAccount::withdraw() {
	long long int a;

	do {
		cout << "Сколько желаете снять?";
		cin >> a;
		if (a > this->balance) cout << "Недостаточно средств!!!" << endl;
	} while (a > this->balance);
	this->balance -= a;
	cout << "Деньги успешно сняты" << endl;
}

void BankAccount::getInterestRate() {
	double monthlyInterestRate = 1.0 / 12;
	cout << "Ваща процентная ставка пока что ноль";
	cin >> this->interestRate;
	double interestEarned = this->balance * this->interestRate * monthlyInterestRate;
	cout << "Теперь вы будете получать в год: " << interestEarned;

}

void BankAccount::setInterestRate() {
	double a = 1.0 / 12;
	int b = 5;
	this->interestRate = this->balance * a * b;
	cout << "Ваша процентная ставка обновлена до 5, теперь вы будете получать: " << this->interestRate;

}

void BankAccount::getAccountNamber() {
	cout << "Номер вашей банковской карточки: " << this->accountNumber;
}

bool transfer(BankAccount& from, BankAccount& to, double amount) {
	if (from.balance >= amount) {
		from.balance -= amount;
		to.balance += amount;
		cout << "Перевод успешно выполнен";
		return true;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	BankAccount account(0, 0, 0);
	BankAccount account1(123, 5000, 0);

	int choise;

	do {
		cout << "\n Добро пожаловать в банкТочка \n";
		cout << "Выберите операцию \n";
		cout << "1. Создать счет и внести сумму \n";
		cout << "2. Информация о счете \n";
		cout << "3. Снять деньги со счета \n";
		cout << "4. Рассчитать процентную ставку \n";
		cout << "5. Новая процентная ставка \n";
		cout << "6. Номер банковской карточки	 \n";
		cout << "7.Перевод средств \n";
		cout << "8. Выход. \n";
		cin >> choise;

		if (!(cin >> choise)) {
			cout << "Ошибка: неверный ввод. Пожалуйста введите номер.";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		switch (choise) {
		case 1:
			
			account.deposit();
			break;
		case 2:
			account.getBalance();
			break;
		case 3:
			account.withdraw();
			break;
		case 4:
			account.getInterestRate();
			break;
		case 5:
			account.setInterestRate();
			break;
		case 6:
			account.getAccountNamber();
			break;
		case 7:
			transfer(account, account1, 500);
			break;
		case 8:
			cout << "До свидания! Спасибо за посещение банкТочка.";
			break;
		default:
			cout << "Неверный выбор. Пожалуйста, выберите операцию от 1 до 8.";
			break;
		}
	} while (choise != 8);

	return 0;
}

	
	

