#ifndef DIALOGALERT_H
#define DIALOGALERT_H

#include <QWidget>

#include <QString>
#include <QMessageBox>

class DialogMessage : public QWidget
{
	Q_OBJECT

public:
	explicit DialogMessage(QWidget *parent = 0);

	void setMessage(QString message);
	void popup();

private:
	QString message;

signals:

public slots:

};

#endif // DIALOGALERT_H
