#ifndef DIALOGOPENFILE_H
#define DIALOGOPENFILE_H

#include <QWidget>

#include <QFileDialog>

#include <QDebug>

class DialogOpenFile : public QWidget
{
	Q_OBJECT

public:
	explicit DialogOpenFile(QWidget *parent = 0);

	void popup();

	QString getFilePath();

private:
	QString filePath;

signals:

public slots:

};

#endif // DIALOGOPENFILE_H
