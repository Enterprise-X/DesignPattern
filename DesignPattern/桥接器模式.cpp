#include "�Ž���ģʽ.h"

#pragma region ��Ϸ��
//ʵ����Ϸ��ӿڻ���
class Game
{
public:
	Game() {}
	virtual void Play() = 0;
private:
};

//����ʵ����GameA
class GameA :public Game
{
public:
	GameA() {}
	void Play() {
		printf("��ϷA����!\n");
	}
};

//����ʵ����GameB
class GameB :public Game
{
public:
	GameB() {}
	void Play() {
		printf("��ϷB����!\n");
	}
};
#pragma  endregion

#pragma region ����ƽ̨��
//����������ƽ̨��
class Platform
{
public:
	Platform() {
	}
	//��װ��Ϸ
	virtual void SetupGame(Game* igame) = 0;
	//������Ϸ
	virtual void Play() = 0;
private:
	Game* game;
};

//����ƽ̨��:XBox
class XBox :public Platform
{
public:
	XBox() {
	}

	void SetupGame(Game* igame) {
		this->game = igame;
	}
	void Play() {
		printf("XBox������Ϸ:\n");
		this->game->Play();
	}
private:
	Game* game;
};

//����ƽ̨��:PS5
class PS5 :public Platform
{
public:
	PS5() {
	}
	//��װ��Ϸ
	void SetupGame(Game* igame) {
		this->game = igame;
	}
	void Play() {
		printf("PS5������Ϸ:\n");
		this->game->Play();
	}
private:
	Game* game;
};
#pragma  endregion

void �Ž���ģʽ::����()
{
	std::cout << "********************�Ž���ģʽ********************" << std::endl;
	Game* game;
	Platform* platform;

	//�û�����Xbox��������ϷA
	platform = new XBox();
	game = new GameA();
	platform->SetupGame(game);
	platform->Play();
	//����ϷB
	game = new GameB();
	platform->SetupGame(game);
	platform->Play();
	printf("========ƽ̨�л�========\n");
	platform = new PS5();
	game = new GameA();
	platform->SetupGame(game);
	platform->Play();
	std::cout << "**************************************************" << std::endl;
}
