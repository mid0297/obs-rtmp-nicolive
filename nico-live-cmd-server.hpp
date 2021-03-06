#pragma once

#include <QtCore>
#include <QtNetwork>

class NicoLive;

class NicoLiveCmdServer : public QObject {
	Q_OBJECT
public:
	enum struct COMMAND {
		UNKNOWN = 0, // default
		GET,
		SET,
		STAT,
		STRT,
		STOP,
		HELO,
		KEEP,
		QUIT
	};
	enum struct TARGET {
		UNKNOWN = 0, // default
		SESSION,
		STREAMING
	};
	static const QMap<QString, NicoLiveCmdServer::COMMAND> COMMAND_NAME;
	static const QMap<QString, NicoLiveCmdServer::TARGET> TARGET_NAME;
	static const QMap<int, QByteArray> CODE_NAME;
	static const int DEFAULT_PORT = 25083;
private:
	NicoLive *nicolive;
	QTcpServer *tcp4_server;
	QTcpServer *tcp6_server;
	int port = NicoLiveCmdServer::DEFAULT_PORT;
	int timeout = 60 * 1000;
	QHash<QTcpSocket *, QByteArray> socket_buff;
public:
	NicoLiveCmdServer(NicoLive *nicolive);
	~NicoLiveCmdServer();
	int getPort();
	void setPort(int port);
	bool start();
	void stop();
	bool isActive();
private slots:
	void tcpConnection(QTcpServer *server);
	void readSocket(QTcpSocket *socket);
private:
	QByteArray command(const QByteArray &cmd, bool &close_flag);
};
