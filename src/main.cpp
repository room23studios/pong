#include <SFML/Network.hpp>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using namespace sf;

TcpSocket socket;

Uint16 ballX;
Uint16 ballY;
Uint16 left;
Uint16 right;
bool isServer;

void sync();

int main() {

	char isServerChar;
	unsigned short port;
	string ipString;

	TcpListener listener;
	IpAddress address;
	                                                                            //Asking about settings
	cout << "Hello, there. Welcome in pong. Would you like to host server? y/n" << endl;
	cin >> isServerChar;
	isServer = (isServerChar == 'y') ? true : false;

	if (isServer) {
		cout << "What port do you want to host on?" << endl;
		cin >> port;

		address = IpAddress::getLocalAddress();

		cout << "Hosting on: " << address.toString() << ":" << port << endl;

		if (listener.listen(port) != sf::Socket::Done) {                           //Setting up a server
			cout << "Nobody connect" << endl;;
			return 0;
		}

		if (listener.accept(socket) != sf::Socket::Done) {
			cout << "Problem here";
			return 0;
		}

		cout << "Client connected";
	}

	else {
		cout << "What ip should I connect to?" << endl;                             //Connecting to server
		cin >> ipString;

		address = IpAddress(ipString);

		cout << "What port should I connect to?" << endl;
		cin >> port;
		cout << "Connecting to: " << address.toString() << ":" << port << " ..." << endl;

		Socket::Status status = socket.connect(address, port);

		if (status != Socket::Done) {
			cout << "Cannot connect" << endl;
			return 0;
		}
		cout << "Connected" << endl;
	}

	if(isServer)
		cin >> ballX >> ballY >> right;                                   //Code for testing
	else
		cin >> left;

	while(true)
		sync();
}

void sync() {                                                                   //Synchronization function
	Packet packetS;
	Packet packetR;

	if (isServer) {                                                             //Synchronization on server side
		packetS << ballX << ballY << right;
		socket.send(packetS);

		socket.receive(packetR);
		if (packetR >> left) {
			cout << left;
		}
	}
	else {
		socket.receive(packetR);                                                    //Synchronization on client side
		if (packetR >> ballX >> ballY >> right) {
			cout << ballX << " " << ballY << " " << right;
		}

		packetS << left;
		socket.send(packetS);
	}
}
