// Server.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Network.hpp>
#include <windows.h>

using namespace sf;
using namespace std;

int main()
{
		//setlocale(LC_ALL, "");							// ��������� ��������� � ������� Windows
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
 
	IpAddress ip = IpAddress::getPublicAddress();	//��������� ip ������ �������
	TcpSocket socket1,socket2;//����������� ��� 1-�� � 2-�� ����������
	char buffer[2000];
	size_t received;	//??
	string text = " ";


//***********�����������***************//
	//cout << ip << endl;
	//ip=IpAddress::getPublicAddress();
	cout<<ip<<endl;


			TcpListener listener1,listener2;
			listener1.
			listener1.listen(2000);
			listener1.accept(socket1);
			listener2.listen(2001);
			listener2.accept(socket2);//������� ����� ��������� ����� ����������
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
 		    //������ ������� �� � "���" ���������  	
	sleep(sf::milliseconds(10));//��������
	}//END
	return 0;
}

