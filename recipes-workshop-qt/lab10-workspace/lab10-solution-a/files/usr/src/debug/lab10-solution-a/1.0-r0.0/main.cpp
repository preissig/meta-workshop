#include <QApplication>
#include <QLabel> 

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QLabel label("Hello World");
	label.setGeometry(10, 40,300,200);
	label.setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
	label.show();

	return app.exec();
}

