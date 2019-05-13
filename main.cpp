#include <QtCore/QCoreApplication>
#include <QtTcpSocket.h>
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QtTcpServer* tcpServer = new QtTcpServer();
	QtTcpClient* tcpClient = new QtTcpClient();	
	return a.exec();
}
