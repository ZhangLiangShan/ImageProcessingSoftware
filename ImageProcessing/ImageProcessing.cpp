#pragma execution_character_set("utf-8")

#include "ImageProcessing.h"
#include <qmainwindow.h>
#include<QtGui>
#include<QtWidgets>



ImageProcessing::ImageProcessing(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	/*connect(this, SIGNAL(iSignal(int)), this, SLOT(iSlot(int)));
	emit iSignal(5);*/

	//�����ı�
	setWindowTitle("����CV��ͼ�����Ա���� by ZLS");
	//���ͼ��
	setWindowIcon(QIcon("../ConfigPicture/icon/ImageProcessing.png"));

	//�����С
	resize(QApplication::desktop()->width*0.8, QApplication::desktop()->height()*0.9);
	move(QApplication::desktop()->width()*0.05, QApplication::desktop()->height()*0.01);
}

ImageProcessing::~ImageProcessing(){}
