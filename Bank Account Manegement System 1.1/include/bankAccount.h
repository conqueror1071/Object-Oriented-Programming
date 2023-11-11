#include<iostream>
#include <string>
using namespace std;
class bankAccount {
private:
	float accountBalance;
	string user_name, user_surname, user_pnumber;
public:
	bankAccount(string name, string surname, string phone, float balance = 0);
	~bankAccount();
	bool controlNameSurname(string nameOrSurname);
	bool controlPnumber(string pnumber);
	void operator+(int balance); 
	void operator-(int balance);
	friend ostream& operator<<(ostream& osObject, const bankAccount& bankAccount_); 
	void setPersonName(string name); 
	void setPersonSurname(string surname);
	void setPnumber(string pnumber);  
	float setBalance(float balance); 
	void sendMoney(bankAccount& othAcc, float money);
	string getPersonName() {
		return user_name;
	}
	string getPersonSurname() {
		return user_surname;
	}
	string getPnumber() {
		return user_pnumber;
	}
	float getBalance() {
		return accountBalance;
	}
};
bankAccount::bankAccount(string name, string surname, string pnumber, float balance) {
	setPersonName(name);
	setPersonSurname(surname);
	setPnumber(pnumber);
	setBalance(balance);
}
bankAccount::~bankAccount() {}
bool bankAccount::controlNameSurname(string nameOrSurname) {
	for (unsigned i = 0; i < nameOrSurname.length(); i++) {
		if (!((nameOrSurname.at(i) >= 'A' && nameOrSurname.at(i) <= 'Z') || (nameOrSurname.at(i) >= 'a' && nameOrSurname.at(i) <= 'z'))) {
			return false;
		}
	}
	return true;
}
bool bankAccount::controlPnumber(string pnumber) {
	if (pnumber.length() != 11) { 
		return false;
	}
	if (pnumber.at(0) != '0') {
		return false;
	} 
	if (pnumber.empty()) {
		return false;
	}
	for (unsigned i = 0; i < pnumber.length(); i++) {
		if (!(pnumber.at(i) >= '0' && pnumber.at(i) <= '9')) {
			return false;
		}
	}
	return true;
}
void bankAccount::operator+(int balance) {
	if (balance >= 0 && balance <= 2000) {
		accountBalance += balance;
		cout << balance << "$ added into your bank account" << endl;	
	} 
	else if (balance > 2000) { 
		cout << "You can credit at most 2000$ in once. Please try again: ";
		cin >> balance;	
	}
	else if (balance < 0) {
		cout << "Invalid amount you input. Please try again: ";
		cin >> balance;
	}
	else {
		cout << "You input invalid variable. Please try again: ";
		cin >> balance;
	}
}
void bankAccount::operator-(int balance) {
	if (accountBalance < balance) {
		cout << "You have not own enough money for this action. Please try again." << endl;
		cin >> balance;
	}
	if (balance <= accountBalance && balance >= 0) {
		accountBalance -= balance;
		cout << balance << "$ widthdrawed from your bank account" << endl;
	}
	else {
		cout << "Your request cannot be performed for some reason. Try different amount" << endl;
	}
}
void bankAccount::setPersonName(string name) {
	while (!controlNameSurname(name)) {
		cout << "Error! Invalid name. Please enter a proper name: " << endl;
		cout << "Name must included 'A-Z' or 'a-z'";
		getline(cin, name);
	}
	user_name = name; 
}
void bankAccount::setPersonSurname(string surname) {
	while (!(controlNameSurname(surname))) {
		cout << "Error! Invalid surname. Please enter a proper surname: ";
		getline(cin, surname);
	} 
	user_surname = surname;
}
void bankAccount::setPnumber(string pnumber) {
	while (!(controlPnumber(pnumber))) { 
		cout << "Error! Invalid phone number. Please enter a proper phone number:" << endl;
		cout << "(number must include 11 characters, number must begin with 0)" << endl;
		getline(cin, pnumber);  
	}
	user_pnumber = pnumber;  
}
float bankAccount::setBalance(float balance) {
	while(true){   
		if (balance < 0) {
			cout << "ERROR! Your balance can not be less than 0. Please enter a new balance: ";
			cin >> balance;
		}
		else { 
			return accountBalance = balance;
		}
	}
}
ostream& operator<<(ostream& osObject, const bankAccount& bankAccount_) {
	osObject << "Name: " << bankAccount_.user_name << endl
		<< "Surname: " << bankAccount_.user_surname << endl
		<< "Phone number: " << bankAccount_.user_pnumber << endl
		<< "Account Balance: " << bankAccount_.accountBalance << "$" << endl;
	return osObject; 
}
void bankAccount::sendMoney(bankAccount& othAcc, float money) {
	while (money < 0 || money > accountBalance) {
		cout << "ERROR: You can not send money less than 0 or more than you own." << endl;
		cin >> money;
	} 
	accountBalance -= money; 
	othAcc.accountBalance += money;
	cout << "You're sending request carried out succesfully" << endl;
}