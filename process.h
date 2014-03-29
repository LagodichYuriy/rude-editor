#ifndef PROCESS_H
#define PROCESS_H

#include <QWidget>

#include <QProcess>

class Process : public QWidget
{
	Q_OBJECT
public:
	explicit Process(QWidget *parent = 0);

	Q_PID pid();

signals:

public slots:

};

#endif // PROCESS_H
