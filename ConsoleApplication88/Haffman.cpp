#include <iostream>
#include <string>
using  namespace std;

void Encode() {
	string message;
	string code;
	string a = "01";
	string b = "110";
	string c = "111";
	string d = "00";
	string e = "10";
	cout << "Enter message to encode using [abcde](0 - Exit): ";
	cin >> message;
	if (message == "0")
		return;

	int index = message.find_first_not_of("abcde");
	if (index != -1)
	{
		cout << "\nWrong format! Try again" << endl;
		system("pause");
		system("cls");
		Encode();
		return;
	}

	for (int i = 0; i < message.length(); i++) 
	{
		if (message.at(i) == 'a') 
			code.append(a);
		else if (message.at(i) == 'b') 
			code.append(b);
		else if (message.at(i) == 'c') 
			code.append(c);
		else if (message.at(i) == 'd') 
			code.append(d);
		else if (message.at(i) == 'e') 
			code.append(e);
	}
	cout << "\nMessage \"" << message << "\" was encoded to \"" << code << "\"" << endl;
}

void Decode() {
	string message;
	string code;
	string a = "01";
	string b = "110";
	string c = "111";
	string d = "00";
	string e = "10";
	cout << "a  =  " << a << endl;
	cout << "b  =  " << b << endl;
	cout << "c  =  " << c << endl;
	cout << "d  =  " << d << endl;
	cout << "e  =  " << e << endl;
	cout << "\nEnter code to decode: ";
	cin >> code;

	int index = code.find_first_not_of("01");
	if (index != -1)
	{
		cout << "\nWrong format! Try again" << endl;
		system("pause");
		system("cls");
		Decode();
		return;
	}

	int pos = 0;
	while (pos != code.length()) 
	{
		if (code.compare(pos, a.length(), a) == 0) 
		{
			message.append("a");
			pos += a.length();
		}
		else if (code.compare(pos, b.length(), b) == 0) 
		{
			message.append("b");
			pos += b.length();
		}
		else if (code.compare(pos, c.length(), c) == 0) 
		{
			message.append("c");
			pos += c.length();
		}
		else if (code.compare(pos, d.length(), d) == 0) 
		{
			message.append("d");
			pos += d.length();
		}
		else if (code.compare(pos, e.length(), e) == 0) 
		{
			message.append("e");
			pos += e.length();
		}
		else 
		{
			cout << "\nWrong format! Try again" << endl;
			system("pause");
			system("cls");
			Decode();
			return;
		}
	}
	cout << endl << "Code \"" << code << "\" was decoded to \"" << message << "\"" << endl;
}

int main1()
{
	while (true) {
		system("cls");
		cout << "1 <- Encode message" << endl;
		cout << "2 <- Decode" << endl;
		cout << "0 <- Exit" << endl;
		cout << "Enter your choice -> ";
		int choice;
		cin >> choice;

		if (choice == 0)
			break;

		switch (choice) 
		{
		case 1: 
			system("cls");
			Encode();
			system("pause");
			break;
		case 2:
			system("cls");
			Decode();
			system("pause");
			break;
		}
	}
	return 0;
}