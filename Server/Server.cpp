// Server.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Network.hpp>
#include <windows.h>

using namespace sf;
using namespace std;

int _tmain()
{
		//setlocale(LC_ALL, "");							// Поддержка кириллицы в консоли Windows
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
 
	IpAddress ip = IpAddress::getPublicAddress();	//Локальный ip Адресс сервера
	TcpSocket socket1,socket2;//подключения для 1-го и 2-го компьютера
	char buffer[2000];
	size_t received;	//??
	string text = " ";


//***********Подключение***************//
	//cout << ip << endl;
	//ip=IpAddress::getPublicAddress();
	cout<<ip<<endl;


			TcpListener listener1,listener2;
			listener1.
			listener1.listen(2000);
			listener1.accept(socket1);
			listener2.listen(2001);
			listener2.accept(socket2);//который будет содержать новое соединение
			cout<<"Col tow!"<<endl;
		
	
    bool faze=true;
	while(true)
	{
		if(faze==true)
		{
			socket1.receive(buffer, sizeof(buffer), received);

			socket2.send(buffer, strlen(buffer)+1);

			faze=false;
		}
		else
		{
			socket2.receive(buffer, sizeof(buffer), received);

			socket1.send(buffer, strlen(buffer)+1);

			faze=true;
		}
 		    //меняет местами моё и "его" сообщение  	
	sleep(sf::milliseconds(10));//Задержка
	}//END
	return 0;
}

