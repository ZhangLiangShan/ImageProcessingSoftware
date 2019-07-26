#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ImageProcessing.h"

class ImageProcessing : public QMainWindow
{
	Q_OBJECT

public:
	ImageProcessing(QWidget *parent = Q_NULLPTR);
	~ImageProcessing();

private:
	Ui::ImageProcessingClass ui;

signals:
	void iSignal(int b); //ÐÅºÅ

	private slots:
	void iSlot(int b);//²Ûº¯Êý
};
