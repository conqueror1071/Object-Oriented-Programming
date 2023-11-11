#include<iostream>
#include"bankAccount.h"
using namespace std;
int main() {
	int a; 
	int b;
	bankAccount acc1("Brett", "Becket", "05299114559", 0);
	bankAccount acc2("Warwick", "Brewer", "05722499344", 5000);
	cout << "-----------WELCOME TO BANK ACCOUNT MANEGEMENT SYSTEM-----------" << endl << endl;
	cout << "Type 1 if you want to choose an action. Type 0 if you want to exit." << endl;
	cin >> a;
	while (true) {
		if (a == 1) {
			cout << "Choose an action:\n1-)Display Account \n2-)Add Credit\n3-)Witdhdraw Credit\n4-)Set Info\n5-)Send money to another account" << endl;
			cin >> b;
			if (b == 1) {
				cout << acc1; 
				cout << "If you want to choose another action please type 1.\nType 0 if you want to exit the program. ";
				cin >> a;
			}
			else if (b == 2) {
				int c;
				cout << "Type what amount of money you want to add: ";
				cin >> c;
				acc1+c;
				cout << "If you want to choose another action please type 1.\nType 0 if you want to exit the program. ";
				cin >> a;
			}
			else if (b == 3) {
				int d;
				cout << "Type what amount of money you want to widthdraw: ";
				cin >> d;
				acc1-d;
				cout << "If you want to choose another action please type 1.\nType 0 if you want to exit the program. ";
				cin >> a;
			}
			else if (b == 4) {
				int e;
				cout << "Which information do you want to set? Please select the indicated number." << endl;
				cout << "1-)Set Name \n2-)Set Surname\n3-)Set Phone number\n4-)Set Balance\n5-)Go Main Menu" << endl;
				cin >> e;
				if (e == 1) {
					string name;
					cout << "Please type the name you want to set: ";
					cin >> name;
					acc1.setPersonName(name);
					cout << "Your name is setted succesfully." << endl;
					cout << "If you want to set another information please select the indicated number.\nOr you can select 5 if you want to go back Main Manu." << endl;
					cout << "1-)Set Name \n2-)Set Surname\n 3-)Set Phone number\n4-)Set Balance\n5-)Go Main Menu" << endl;
					cin >> e;
				}
				else if (e == 2) {
					string surname;
					cout << "Please type the surnname you want to set: ";
					cin >> surname;
					acc1.setPersonSurname(surname);
					cout << "Your surname is setted succesfully." << endl;
					cout << "If you want to set another information please select the indicated number.\nOr you can select 5 if you want to go back Main Manu." << endl;
					cout << "1-)Set Name \n2-)Set Surname\n 3-)Set Phone number\n4-)Set Balance\n5-)Go Main Menu" << endl;
					cin >> e;
				}
				else if (e == 3) {
					string pnumber;
					cout << "Please type the phone number you want to set: ";
					cin >> pnumber;
					acc1.setPnumber(pnumber);
					cout << "Your phone number is setted succesfully." << endl;
					cout << "If you want to set another information please select the indicated number.\nOr you can select 5 if you want to go back Main Manu." << endl;
					cout << "1-)Set Name \n2-)Set Surname\n 3-)Set Phone number\n4-)Set Balance\n5-)Go Main Menu" << endl;
					cin >> e;
				}
				else if (e == 4) {
					float balance;
					cout << "Please type the phone number you want to set: ";
					cin >> balance;
					acc1.setBalance(balance);
					cout << "Your new balance is setted succesfully." << endl;
					cout << "If you want to set another information please select the indicated number.\nOr you can select 5 if you want to go back Main Manu." << endl;
					cout << "1-)Set Name \n2-)Set Surname\n 3-)Set Phone number\n4-)Set Balance\n5-)Go Main Menu" << endl;
					cin >> e;
				}
				else if (e == 5) {
					cout << "Type 1 if you want to choose an action.\nType 0 if you want to exit." << endl;
					cin >> a;
				}
				else {
					cout << "Please type proper number in order to continue." << endl;
					cin >> e;
				}
			}
			else if (b == 5) {
				int f;
				cout << "Your balance: " << acc1.getBalance() << endl;
				if(acc1.getBalance()==0){
					cout<<"You can not send any money because you have not any!!"<<endl;
					cout<<"Please add credit into your bank account first!"<<endl;	
					cout << "Type 1 if you want to choose an action.\nType 0 if you want to exit." << endl;
					cin >> a;
				}
				else{
					cout << "How much money do you want to send?";
					cin >> f;
					acc1.sendMoney(acc2, f);
					cout << "Your account balance: " << acc1.getBalance() << "$" << endl;
					cout << "Gizem's account Balance: " << acc2.getBalance() << "$" << endl;
					cout << "Type 1 if you want to choose an action.\nType 0 if you want to exit." << endl;
					cin >> a;
				}
			}
			else {
				cout << "Please type 1-4 in order to choose an action" << endl;
				cout << "1-)Display Account \n2-)Add Credit\n3-)Witdhdraw Credit\n4-)Set Info" << endl;
				cin >> b;
			}
		} 
		else if (a == 0) {
			cout << "Program is shutting down...";
			return 0;
		}
		else {
			cout << "Please type 1 if you want to choose an action. Type 0 if you want to exit.";
		}
	}
}