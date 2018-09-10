#pragma once

#include <string>

namespace Network{ 
	
// �l�b�g�ΐ�̒ʐM���Ǘ�����N���X
class Manager{
public:
	Manager();

	// �ΐ푊��Ƃ̒ʐM�o�H���m��
	Manager( std::string ipAddr, int portNum );

	~Manager();

	void SetOpponent( std::string ipAddr, int portNum );

	// �ΐ푊��Ƀ��b�Z�[�W���M
	void Send( std::string );

	// �ΐ푊�肩�烁�b�Z�[�W��M
	std::string Receive();

private:
	std::string opponentIPaddr;
	int opponentPortNum;
};

}