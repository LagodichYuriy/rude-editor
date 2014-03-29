#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>

#include "process.h"
#include "semaphore.h"
#include "filesystem.h"
#include "dialoginput.h"
#include "sharedmemory.h"
#include "dialogopenfile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void lockButtons();
	void unlockButtons();

private slots:
	void on_openButton_clicked();

public slots:
	void checkEditorFocus();

private:
	Ui::MainWindow *ui;

	Semaphore *semaphore;
	SharedMemory *memory;
	Process *process;
};

#endif // MAINWINDOW_H
