#include "dialogmessage.h"

DialogMessage::DialogMessage(QWidget *parent) :
	QWidget(parent)
{

}

void DialogMessage::setMessage(QString message)
{
	this->message = message;
}

void DialogMessage::popup()
{
	QMessageBox::information(0, "error", this->message);
}
