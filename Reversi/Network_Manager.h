#pragma once

#include <string>

namespace Network{ 
	
// ネット対戦の通信を管理するクラス
class Manager{
public:
	Manager();

	// 対戦相手との通信経路を確立
	Manager( std::string ipAddr, int portNum );

	~Manager();

	// 通信を確立する
	void SetOpponent( std::string ipAddr, int portNum );

	// 対戦相手にメッセージ送信
	void Send( std::string message ) const;

	// 対戦相手からメッセージ受信
	std::string Receive() const;

private:
	std::string opponentIPaddr;
	int opponentPortNum;
};

}