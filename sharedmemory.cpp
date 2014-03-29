#include "sharedmemory.h"

SharedMemory::SharedMemory(QString name, QWidget *parent) :
	QWidget(parent)
{
	this->name = name;

	this->memory = new QSharedMemory(this->name);
	this->attach();
}

QString SharedMemory::read()
{
	QBuffer buffer;
	QDataStream in(&buffer);
	QString data;

	buffer.setData((char *) this->memory->constData(), this->memory->size());
	buffer.open(QBuffer::ReadOnly);
	in >> data;

	return data;
}

void SharedMemory::write()
{
	QBuffer buffer;
	buffer.open(QBuffer::ReadWrite);

	QDataStream out(&buffer);
	out << this->name;


	int size = buffer.size();

	this->memory->create(size);

	char *to = (char *) this->memory->data();
	const char *from = buffer.data().data();
	memcpy(to, from, qMin(this->memory->size(), size));
}

void SharedMemory::erase()
{
	this->memory->lock();

	memset(this->memory->data(), '\0', this->memory->size());

	this->memory->unlock();
}

bool SharedMemory::isEmpty()
{
	if (this->read().isEmpty())
	{
		return true;
	}

	return false;
}

bool SharedMemory::attach()
{
	if (this->isDetached())
	{
		return this->memory->attach();
	}

	return false;
}

bool SharedMemory::detach()
{
	if (this->isAttached())
	{
		return this->memory->detach();
	}

	return false;
}

bool SharedMemory::isAttached()
{
	return this->memory->isAttached();
}

bool SharedMemory::isDetached()
{
	return !this->isAttached();
}
