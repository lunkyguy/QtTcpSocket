#pragma once
#include <qthread.h>
#include <qtcpserver.h>
#include <qtcpsocket.h>
#include <qtimer.h>
class QtTcpClient
	:public QThread
{
	Q_OBJECT
public:
	QtTcpClient();
	virtual ~QtTcpClient();

private:
	QTimer* timer;
	QTcpSocket* tcpClient;
public slots:
	void readMessage();
};

class QtTcpServer
	:public QThread
{
	Q_OBJECT
public:
	QtTcpServer();
	virtual ~QtTcpServer();

private:
	QTcpServer* tcpServer;
	QTcpSocket* tcpSocket;
public slots:
	void newConnect();
	void readMessage();
};