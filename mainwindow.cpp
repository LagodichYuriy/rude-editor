#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	this->semaphore = NULL;
	this->memory = NULL;
	this->process = new Process();

	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(checkEditorFocus()));
	timer->start(750);


	ui->setupUi(this);

	lockButtons();

	QWidget::setWindowTitle(tr("Empty project"));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_openButton_clicked()
{
	DialogOpenFile openFile;

	openFile.popup();

	QString filePath = openFile.getFilePath();

	if (filePath.isEmpty())
	{
		return;
	}


	QWidget::setWindowTitle(filePath);


	if (semaphore && semaphore->isLocked())
	{
		qDebug() << "unlock!";

		semaphore->unlock();
		semaphore = NULL;
	}

	if (memory && memory->isAttached())
	{
		qDebug() << "detach!";

		memory->erase();
		memory->detach();
		memory = NULL;
	}

	semaphore = new Semaphore(filePath);
	memory = new SharedMemory(filePath);

	qDebug() << "new!";

	if (memory->isEmpty())
	{
		memory->write();

		qDebug() << "let's lock it!";

		semaphore->lock();
	}

	qDebug() << "==========================";


	FileSystem filesystem;

	QString fileData = filesystem.read(filePath);

	ui->plainTextEdit->clear();
	ui->plainTextEdit->appendPlainText(fileData);
}

void MainWindow::lockButtons()
{
	ui->saveAsButton->setDisabled(true);
	ui->saveButton->setDisabled(true);
}

void MainWindow::unlockButtons()
{
	ui->saveAsButton->setEnabled(true);
	ui->saveButton->setEnabled(true);
}

void MainWindow::checkEditorFocus()
{
	if (!semaphore)
	{
		return;
	}


	if (semaphore->isLocked())
	{
		qDebug() << "[sem]: locked";
	}
	else
	{
		qDebug() << "[sem]: unlocked";
	}

	if (semaphore->isOwner())
	{
		qDebug() << "[sem]: owner";
	}
	else
	{
		qDebug() << "[sem]: not owner";
	}

	if (memory->isEmpty())
	{
		qDebug() << "[mem]: empty";
	}
	else
	{
		qDebug() << "[mem]:" << memory->read();
	}

	if (memory->isAttached())
	{
		qDebug() << "[mem]: attached";
	}
	else
	{
		qDebug() << "[mem]: detached";
	}

	if (semaphore->getName().isEmpty())
	{
		qDebug() << "[fil]: undefined";
	}
	else
	{
		qDebug() << "[fil]:" << semaphore->getName();
	}

	qDebug() << "==========================";


//	bool isFocused = ui->plainTextEdit->hasFocus();

	if (semaphore->isOwner())
	{
		unlockButtons();
		return;
	}

	if (memory->isEmpty())
	{
		if (semaphore->isUnlocked())
		{
			memory->attach();
			memory->write();
			semaphore->lock();
		}

		unlockButtons();
		return;
	}

	lockButtons();
	return;
}
