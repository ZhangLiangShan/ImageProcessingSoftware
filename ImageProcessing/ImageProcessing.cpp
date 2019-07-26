#pragma execution_character_set("utf-8")

#include "ImageProcessing.h"
#include <qmainwindow.h>
#include<QtGui>
#include<QtWidgets>



ImageProcessing::ImageProcessing(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	Menu_File();			//�ļ��˵�
	//init();					//��ʼ��ͼ��QLabel
	InitImage();			//��ʼ��ͼ��QLabel
}

ImageProcessing::~ImageProcessing(){}

//�ļ��˵�
void ImageProcessing::Menu_File()
{
	//�˵���
	QMenu *file = menuBar()->addMenu(tr("�ļ�"));

	//�˵�����
	QAction *Act_file_new = new QAction(QIcon("../ConfigPicture/file/New.png"), tr("�½�"), this);
	Act_file_new->setShortcuts(QKeySequence::New);//��ݼ�Ctrl +N
	connect(Act_file_new, SIGNAL(triggered()), this, SLOT(File_new()));

	QAction *Act_file_open = new QAction(QIcon("../ConfigPicture/file/Open.png"), tr("��"), this);
	Act_file_open->setShortcuts(QKeySequence::Open);// ��ݼ� Ctrl+O
	connect(Act_file_open, SIGNAL(triggered()), this, SLOT(File_open()));

	QAction *Act_file_save = new QAction(QIcon("../ConfigPicture/file/Save.png"), tr("����"), this);
	Act_file_save->setShortcuts(QKeySequence::Save);// ��ݼ� Ctrl+S
	connect(Act_file_save, SIGNAL(triggered()), this, SLOT(File_save()));

	QAction *Act_file_saveas = new QAction(QIcon("../ConfigPicture/file/SaveAs.png"), tr("���Ϊ"), this);
	Act_file_saveas->setShortcuts(QKeySequence::SaveAs);// ��ݼ� 
	connect(Act_file_saveas, SIGNAL(triggered()), this, SLOT(File_saveas()));

	QAction *Act_file_close = new QAction(QIcon("../ConfigPicture/file/Close.png"), tr("�ر�"), this);
	Act_file_close->setShortcuts(QKeySequence::Close);// ��ݼ� Ctrl+F4
	connect(Act_file_close, SIGNAL(triggered()), this, SLOT(close()));

	//��������ӵ��˵���
	file->addAction(Act_file_new);
	file->addAction(Act_file_open);
	file->addAction(Act_file_save);
	file->addAction(Act_file_saveas);
	file->addSeparator();                       //��ӷָ���
	file->addAction(Act_file_close);

	//������
	ui.mainToolBar->addAction(Act_file_new);
	ui.mainToolBar->addAction(Act_file_open);
	ui.mainToolBar->addAction(Act_file_save);

	//������
	Act_file_new->setStatusTip(tr("�½�ͼ��"));
	Act_file_open->setStatusTip(tr("��ͼ��"));
	Act_file_save->setStatusTip(tr("����ͼ��"));
	Act_file_saveas->setStatusTip(tr("ͼ�����Ϊ"));
	Act_file_close->setStatusTip(tr("�ر����"));
	
}



//��ʼ������
void ImageProcessing::init()
{
	imgVector.resize(2);

	//���ͼ��
	setWindowIcon(QIcon("../ConfigPicture/icon/ImageProcessing.png"));
}

//��ʾ����
void ImageProcessing::Show()
{
	//�����ı�
	setWindowTitle("����CV��ͼ�����Ա���� by ZLS");
	//�����С
	resize(QApplication::desktop()->width()*0.8, QApplication::desktop()->height()*0.9);
	move(QApplication::desktop()->width()*0.05, QApplication::desktop()->height()*0.01);
}

//��ʼ��ͼ��
void ImageProcessing::InitImage()
{
	// ��ʼ��QDockWidget.���Ժ�ὲ�����ǿ��ƶ����ص�С���ڣ�
	// ����ʵ��PS��VSͣ�����ڵ�Ч����Ŀǰֻ���˽�
	dock_Image = new QDockWidget(tr("ͼ��"), this);
	setCentralWidget(dock_Image);

	// ��ʼ��QLabel
	imgLabel = new QLabel(dock_Image);
	imgLabel->setScaledContents(true);// ����QLabel�Զ���Ӧͼ���С

	// ��ʼͼ��
	QImage image = QImage(500, 500, QImage::Format_RGB32);  // �½�ͼ��
	image.fill(qRgb(255, 255, 255));                        // ȫ��
	imgLabel->setPixmap(QPixmap::fromImage(image));         // ��ʾͼ��
	imgLabel->resize(image.width(), image.height());        // ͼ����imgLabelͬ��С

															// ���ӹ�����,���ͼ���imgLabel�󣬾ͻ���ֹ�����
	QScrollArea* scrollArea = new QScrollArea(this);
	scrollArea->setBackgroundRole(QPalette::Dark);
	scrollArea->setAlignment(Qt::AlignCenter);
	scrollArea->setWidget(imgLabel);
	dock_Image->setWidget(scrollArea);

}

void ImageProcessing::File_new()
{

}

void ImageProcessing::File_open()
{

}

void ImageProcessing::File_save()
{

}

void ImageProcessing::File_save_as()
{

}