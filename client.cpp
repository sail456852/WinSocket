//Client 
#include <WinSock2.h>
#include <iostream>

#pragma comment (lib,"WS2_32.lib")


int main ()
{
	//Winsock Startup 
	WSAData wsaData; 
	WORD DllVersion = MAKEWORD (2, 1);
	if (WSAStartup (DllVersion, &wsaData) != 0)
		//If WSAStartup returns anything other than 0 , then that means an error 
		//has occured . 
	{
		MessageBoxA (NULL, "Winsock startup failed ", "Error", MB_OK | MB_ICONERROR);
		exit (1);
	}

	SOCKADDR_IN addr; //Address that we will bind our listening socket to 
	int sizeofaddr = sizeof (addr);//length of the address (required for accept call) 
	addr.sin_addr.s_addr = inet_addr ("127.0.0.1"); //Broadcast locally 
	addr.sin_port = htons (1111); //port 
	addr.sin_family = AF_INET; //IPV4 Socket  

	SOCKET Connection = socket (AF_INET, SOCK_STREAM, NULL); 
	if (connect(Connection ,(SOCKADDR*)&addr,sizeofaddr) != 0 ) //if we are unable to connect 
	{
		MessageBoxA (NULL, "Unable to connect", "Error", MB_OK | MB_ICONERROR);
		return 0;  //failed to connect 
	}
	std::cout << "Client is connected!" << std::endl; 


	system ("pause");

	return 0; 
}