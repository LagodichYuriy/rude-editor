#include "semaphore.h"

Semaphore::Semaphore(QString name, QWidget *parent) :
	QWidget(parent)
{
	this->name = name;

	this->semaphore = new QSystemSemaphore(this->name, 1, QSystemSemaphore::Create);

	this->locked = false;
	this->owner = false;
}

bool Semaphore::lock()
{
	if (!this->semaphore->acquire())
	{
		qDebug() << "locked";

		return false;
	}

	qDebug() << "unable to lock";

	this->locked = true;
	this->owner = true;

	return true;
}

bool Semaphore::unlock()
{
	if (!this->semaphore->release())
	{
		return false;
	}


	this->locked = false;
	this->owner = false;

	return true;
}

bool Semaphore::isOwner()
{
	return this->owner;
}

bool Semaphore::isLocked()
{
	if (this->locked)
	{
		return true;
	}

	return false;
}

bool Semaphore::isUnlocked()
{
	return !this->isLocked();
}

QString Semaphore::getName()
{
	return this->name;
}
