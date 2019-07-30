#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ExamenOOP.h"

class ExamenOOP : public QMainWindow
{
	Q_OBJECT

public:
	ExamenOOP(QWidget *parent = Q_NULLPTR);

private:
	Ui::ExamenOOPClass ui;
};
