#include "filesystem.h"

FileSystem::FileSystem(QWidget *parent) :
	QWidget(parent)
{
}

QString FileSystem::read(QString filePath)
{
	QFile file(filePath);

	if (!file.open(QIODevice::ReadOnly))
	{
		DialogMessage message;

		message.setMessage(file.errorString());
		message.popup();
	}

	QTextStream in(&file);

	QString data;
	data = in.readAll();

	file.close();


	return data;
}
