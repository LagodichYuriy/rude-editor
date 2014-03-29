#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>

#include <QFile>
#include <QString>
#include <QTextStream>

#include "dialogmessage.h"

#include <QDebug>

class FileSystem : public QWidget
{
	Q_OBJECT

public:
	explicit FileSystem(QWidget *parent = 0);

	QString read(QString filePath);

signals:

public slots:

};

#endif // EDITOR_H
