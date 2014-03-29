#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H

#include <QWidget>

#include <QString>
#include <QBuffer>
#include <QDataStream>
#include <QSharedMemory>

#include <QDebug>

class SharedMemory : public QWidget
{
	Q_OBJECT

public:
	explicit SharedMemory(QString name, QWidget *parent = 0);

	QString read();

	void write();
	void erase();

	bool attach();
	bool detach();

	bool isAttached();
	bool isDetached();
	bool isEmpty();

private:
	QSharedMemory *memory;

	QString name;

signals:

public slots:

};

#endif // SHAREDMEMORY_H
