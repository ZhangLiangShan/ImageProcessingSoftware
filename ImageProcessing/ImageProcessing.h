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

	std::vector<std::vector<QImage>> imgVector; //存储图像的vector容器

private:
	Ui::ImageProcessingClass ui;

	QDockWidget *dock_Image;                    // 图像窗口
	QString currentPath;                        // 当前图像的路径
	QLabel *imgLabel;                           // 图像显示框

	void InitImage();						//初始化图像
	void Menu_File();						//文件菜单
	void init();							//初始化
	void Show();							//界面

private slots:
	void File_new();						//新建
	void File_open();						//打开
	void File_save();						//保存
	void File_save_as();					//另存为
};
