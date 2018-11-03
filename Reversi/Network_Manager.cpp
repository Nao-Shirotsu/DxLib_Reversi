#include "Network_Manager.h"

namespace Network{

Manager::Manager(){}

Manager::Manager( std::string ipAddr, int portNum ){
	opponentIPaddr = ipAddr;
	opponentPortNum = portNum;
}

Manager::~Manager(){}

void Manager::SetOpponent( std::string ipAddr, int portNum ){
	opponentIPaddr = ipAddr;
	opponentPortNum = portNum;
}

void Manager::Send( std::string ){}

std::string Manager::Receive(){
	return "";
}

}