// Server.cpp: ���������� ����� ����� ��� ����������� ����������.
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
			//socket1.receive(buffer, sizeof(buffer), received);
			//text=buffer;
		//	cout<<faze<<":"<<text<<endl;
			//socket2.send(text.c_str(), text.length() + 1);
			socket2.send(buffer, strlen(buffer)+1);
			//text.clear();
			//socket2.send(buffer, sizeof(buffer));
			
			//socket1.receive(packet);	
			//socket2.send(packet);
			//packet.clear();
			faze=false;
		}
		else
		{
			socket2.receive(buffer, sizeof(buffer), received);
			//text=buffer;
		//	cout<<faze<<":"<<text<<endl;
			//cout<<faze<<":"<<buffer<<endl;
			//socket1.send(text.c_str(), text.length() + 1);
			socket1.send(buffer, strlen(buffer)+1);
			//text.clear();
			//socket1.send(buffer, sizeof(buffer));
			//socket2.receive(packet);
			//socket1.send(packet);
			//packet.clear();
			faze=true;
		}
 		    //������ ������� �� � "���" ���������  	
	sleep(sf::milliseconds(10));//��������
	}//END
	return 0;
}

