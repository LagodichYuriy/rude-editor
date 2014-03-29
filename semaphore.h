#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <QWidget>

#include <QString>
#include <QSystemSemaphore>

#include <QDebug>

class Semaphore : public QWidget
{
	Q_OBJECT
public:
	explicit Semaphore(QString name, QWidget *parent = 0);

	bool lock();
	bool unlock();

	bool isOwner();
	bool isLocked();
	bool isUnlocked();

	QString getName();

private:
	QSystemSemaphore *semaphore;

	QString name;

	bool locked;
	bool owner;

signals:

public slots:

};

#endif // SEMAPHORE_H
