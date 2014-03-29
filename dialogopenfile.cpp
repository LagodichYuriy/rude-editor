#include "dialogopenfile.h"

DialogOpenFile::DialogOpenFile(QWidget *parent) :
	QWidget(parent)
{

}

void DialogOpenFile::popup()
{
	this->filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));

	qDebug() << this->filePath;
}

QString DialogOpenFile::getFilePath()
{
	return this->filePath;
}
