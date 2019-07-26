#pragma once

#include <QMainWindow>
#include <QtGui>
#include <QtWidgets>
#include <QtWidgets/QMainWindow>
#include "ui_ImageProcessing.h"

class ImageProcessing : public QMainWindow
{
	Q_OBJECT

public:
	ImageProcessing(QWidget *parent = Q_NULLPTR);
	~ImageProcessing();

	std::vector<std::vector<QImage>> imgVector; //�洢ͼ���vector����

private:
	Ui::ImageProcessingClass ui;

	QDockWidget *dock_Image;                    // ͼ�񴰿�
	QString currentPath;                        // ��ǰͼ���·��
	QLabel *imgLabel;                           // ͼ����ʾ��

	void InitImage();						//��ʼ��ͼ��
	void Menu_File();						//�ļ��˵�
	void init();							//��ʼ��
	void Show();							//����

private slots:
	void File_new();						//�½�
	void File_open();						//��
	void File_save();						//����
	void File_save_as();					//���Ϊ
};
