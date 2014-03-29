#ifndef INPUT_H
#define INPUT_H

#include <QWidget>

#include <QDir>
#include <QString>
#include <QInputDialog>

#include <QDebug>

class DialogInput : public QWidget
{
	Q_OBJECT

public:
	explicit DialogInput(QWidget *parent = 0);

	void setTitle(QString title);
	void popup();

	QString getInput();

private:
	QString title;
	QString input;

signals:

public slots:

};

#endif // INPUT_H
