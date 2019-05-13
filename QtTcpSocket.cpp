#include "QtTcpSocket.h"



QtTcpClient::QtTcpClient()
{
	tcpClient = new QTcpSocket();
	tcpClient->abort();
	tcpClient->connectToHost("127.0.0.1", 8810);
	connect(tcpClient, SIGNAL(readyRead()), this, SLOT(readMessage()));
	QString msgS = QStringLiteral("������Ϣ");
	tcpClient->write(msgS.toUtf8(), msgS.toUtf8().length());
	//QString msgS = QString::fromLocal8Bit("������Ϣ");
	//tcpClient->write(msgS.toLocal8Bit(), msgS.toLocal8Bit().length());
}


QtTcpClient::~QtTcpClient()
{
}


void QtTcpClient::readMessage()
{
	QByteArray datagram = tcpClient->readAll();

	QString msg = QString::fromUtf8(datagram);
	qDebug() << msg;

	//QString msg = QString::fromLocal8Bit(datagram);
	//qDebug() << msg;
}

QtTcpServer::QtTcpServer()
{
	tcpServer = new QTcpServer();
	tcpServer->listen(QHostAddress::Any, 8810);
	connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnect()));
}


QtTcpServer::~QtTcpServer()
{
}

void QtTcpServer::newConnect()
{
	tcpSocket = tcpServer->nextPendingConnection();
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
}

void QtTcpServer::readMessage()
{
	QByteArray datagram = tcpSocket->readAll(); //��ȡ   
	QString msg = QString::fromUtf8(datagram);
	QString msgS = QStringLiteral("�յ���Ϣ");
	qDebug() << msg;
	tcpSocket->write(msgS.toUtf8(), msgS.toUtf8().length());

	//QString msg = QString::fromLocal8Bit(datagram);
	//QString msgS = QString::fromLocal8Bit("�յ���Ϣ");
	//qDebug() << msg;
	//tcpSocket->write(msgS.toLocal8Bit(), msgS.toLocal8Bit().length());
}