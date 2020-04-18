#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#include "Scene.h"

void main()
{
	float timeDelta = 0.0f;		//�ѹ��� �������� ������ �ð�
	float lastTime = 0.0f;		//���������� ������ �Ϸ��� �ð�

	float Timer = 0.0f;			//Ÿ�̸�
	int FrameCount = 0;			//Frame ī��Ʈ
	int FPS = 0;				//Frame Per Second(�ʴ� ������ ��)

	//���� �õ尪 �ʱ�ȭ
	srand((unsigned int)time(NULL));
    //ȭ��ũ�� ����
	//system("mode con:cols=80 lines=28");
	ChangeConsoleSize(GetStdHandle(STD_OUTPUT_HANDLE), 64, 15);
	//Ŀ�������� ����
	removeCursor();

	//â �̸� ����
	SetConsoleTitle(TEXT("Find_Bombs 1.0"));
	while (true)
	{
		//���� �ð� ��������
		float currentTime = clock() * 0.001;
		//���� �ð��� ���� �ð��� ���� TimeDelta ���ϱ�
		timeDelta = currentTime - lastTime;

		//Ű���� �Է� ������Ʈ
		InputUpdate();

		//������(Rendering)
		if (!SceneRender(timeDelta)) break;

		//������ ��, Ű���� �Է� �� ������Ʈ
		InputLateUpdate();

		//ȭ�� �����
		//system("cls");
		//���� �ð��� ���� �ð����� �����ϱ�
		lastTime = currentTime;
		//Frame Per Second ����
		Timer += timeDelta;
		FrameCount++;			//Frame ī��Ʈ
								//1�ʰ� �� �� ���� ����
		if (Timer >= 1.0f)
		{
			//FPS ����
			FPS = FrameCount;
			//ī��Ʈ �ʱ�ȭ
			FrameCount = 0;
			//Ÿ�̸� �ʱ�ȭ(0�ʺ��� �ٽ� ����)
			Timer = 0.0f;
		}
	}
}

