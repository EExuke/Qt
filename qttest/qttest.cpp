/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/
# include <QApplication>
# include <QPushButton>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QPushButton hello("Hello World!");
	hello.show();
	QObject::connect(&hello, SIGNAL(clicked()), &app, SLOT(quit()));
	return app.exec();
}

