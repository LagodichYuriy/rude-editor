#include "dialoginput.h"

DialogInput::DialogInput(QWidget *parent) :
	QWidget(parent)
{

}

void DialogInput::setTitle(QString title)
{
	this->title = title;
}

void DialogInput::popup()
{
	bool ok;

	QString input = QInputDialog::getText(this, this->title, this->title, QLineEdit::Normal, QDir::home().dirName(), &ok);

	if (ok && !input.isEmpty())
	{
		qDebug() << input;

		this->input = input;
	}
}

QString DialogInput::getInput()
{
	return this->input;
}
