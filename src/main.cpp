#include <SFML/Network.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main(){
  char x;
  unsigned short port;
  string ipString;

  TcpListener listener;
  TcpSocket client;
  TcpSocket socket;
  IpAddress address;

  cout<<"Hello, there. Welcome in pong. Would you like to host server? y/n" <<endl;
  cin>>x;
  if(x == 'y'){
    cout<<"What port do you want to host on?" <<endl;
    cin>>port;
    address = IpAddress::getLocalAddress();
    cout<<"Hosting on: " << address.toString() << ":" << port <<endl;
    if (listener.listen(25565) != sf::Socket::Done)
    {
      cout<<"Nobody connect"<<endl;;
      return 0;
    }

    if (listener.accept(client) != sf::Socket::Done)
    {
      cout<<"Problem here";
      return 0;
    }
    cout<<"Client connected";
  }
  else{
    cout<<"What ip should I connect to?"<<endl;
    cin>>ipString;
    address = IpAddress(ipString);
    cout<<"What port should I connect to?"<<endl;
    cin>>port;
    cout<<"Connecting to: " <<  address.toString() << ":" << port <<" ..."<<endl;
    Socket::Status status = socket.connect(address, port);
    if(status != Socket::Done)
    {
      cout<<"Cannot connect"<<endl;;
      return 0;
    }
    cout<<"Connected"<<endl;;
  }
}
