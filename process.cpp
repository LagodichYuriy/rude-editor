#include "process.h"

Process::Process(QWidget *parent) :
	QWidget(parent)
{
}

Q_PID Process::pid()
{
	QProcess process;

	return process.pid();
}
