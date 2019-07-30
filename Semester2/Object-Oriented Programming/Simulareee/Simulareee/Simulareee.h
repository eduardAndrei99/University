#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Simulareee.h"

class Simulareee : public QMainWindow
{
	Q_OBJECT

public:
	Simulareee(QWidget *parent = Q_NULLPTR);

private:
	Ui::SimulareeeClass ui;
};
