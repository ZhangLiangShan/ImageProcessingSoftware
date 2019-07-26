#pragma execution_character_set("utf-8")

#include "ImageProcessing.h"
#include <qmainwindow.h>
#include<QtGui>
#include<QtWidgets>



ImageProcessing::ImageProcessing(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	Menu_File();			//文件菜单
	//init();					//初始化图像QLabel
	InitImage();			//初始化图像QLabel
}

ImageProcessing::~ImageProcessing(){}

//文件菜单
void ImageProcessing::Menu_File()
{
	//菜单栏
	QMenu *file = menuBar()->addMenu(tr("文件"));

	//菜单动作
	QAction *Act_file_new = new QAction(QIcon("../ConfigPicture/file/New.png"), tr("新建"), this);
	Act_file_new->setShortcuts(QKeySequence::New);//快捷键Ctrl +N
	connect(Act_file_new, SIGNAL(triggered()), this, SLOT(File_new()));

	QAction *Act_file_open = new QAction(QIcon("../ConfigPicture/file/Open.png"), tr("打开"), this);
	Act_file_open->setShortcuts(QKeySequence::Open);// 快捷键 Ctrl+O
	connect(Act_file_open, SIGNAL(triggered()), this, SLOT(File_open()));

	QAction *Act_file_save = new QAction(QIcon("../ConfigPicture/file/Save.png"), tr("保存"), this);
	Act_file_save->setShortcuts(QKeySequence::Save);// 快捷键 Ctrl+S
	connect(Act_file_save, SIGNAL(triggered()), this, SLOT(File_save()));

	QAction *Act_file_saveas = new QAction(QIcon("../ConfigPicture/file/SaveAs.png"), tr("另存为"), this);
	Act_file_saveas->setShortcuts(QKeySequence::SaveAs);// 快捷键 
	connect(Act_file_saveas, SIGNAL(triggered()), this, SLOT(File_saveas()));

	QAction *Act_file_close = new QAction(QIcon("../ConfigPicture/file/Close.png"), tr("关闭"), this);
	Act_file_close->setShortcuts(QKeySequence::Close);// 快捷键 Ctrl+F4
	connect(Act_file_close, SIGNAL(triggered()), this, SLOT(close()));

	//将动作添加到菜单上
	file->addAction(Act_file_new);
	file->addAction(Act_file_open);
	file->addAction(Act_file_save);
	file->addAction(Act_file_saveas);
	file->addSeparator();                       //添加分割线
	file->addAction(Act_file_close);

	//工具栏
	ui.mainToolBar->addAction(Act_file_new);
	ui.mainToolBar->addAction(Act_file_open);
	ui.mainToolBar->addAction(Act_file_save);

	//任务栏
	Act_file_new->setStatusTip(tr("新建图像"));
	Act_file_open->setStatusTip(tr("打开图像"));
	Act_file_save->setStatusTip(tr("保存图像"));
	Act_file_saveas->setStatusTip(tr("图像另存为"));
	Act_file_close->setStatusTip(tr("关闭软件"));
	
}



//初始化界面
void ImageProcessing::init()
{
	imgVector.resize(2);

	//软件图标
	setWindowIcon(QIcon("../ConfigPicture/icon/ImageProcessing.png"));
}

//显示界面
void ImageProcessing::Show()
{
	//标题文本
	setWindowTitle("基于CV的图像处理自编软件 by ZLS");
	//界面大小
	resize(QApplication::desktop()->width()*0.8, QApplication::desktop()->height()*0.9);
	move(QApplication::desktop()->width()*0.05, QApplication::desktop()->height()*0.01);
}

//初始化图像
void ImageProcessing::InitImage()
{
	// 初始化QDockWidget.在以后会讲到，是可移动隐藏的小窗口，
	// 可以实现PS、VS停靠窗口的效果，目前只需了解
	dock_Image = new QDockWidget(tr("图像"), this);
	setCentralWidget(dock_Image);

	// 初始化QLabel
	imgLabel = new QLabel(dock_Image);
	imgLabel->setScaledContents(true);// 设置QLabel自动适应图像大小

	// 初始图像
	QImage image = QImage(500, 500, QImage::Format_RGB32);  // 新建图像
	image.fill(qRgb(255, 255, 255));                        // 全白
	imgLabel->setPixmap(QPixmap::fromImage(image));         // 显示图像
	imgLabel->resize(image.width(), image.height());        // 图像与imgLabel同大小

															// 增加滚动条,如果图像比imgLabel大，就会出现滚动条
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