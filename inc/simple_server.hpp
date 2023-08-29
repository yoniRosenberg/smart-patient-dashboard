#ifndef SIMPLE_SERVER_HPP
#define SIMPLE_SERVER_HPP

#include <QTcpServer>
#include <QTcpSocket>
#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QDateTime>
#include <QScopedPointer>
#include "event.hpp"

class SimpleServer : public QObject {
    Q_OBJECT

public:
    SimpleServer();
    void connect_to_client_manager(const QHostAddress &a_address, quint16 a_port);
    Event get_event() const;
    void forward_event_to_client(const Event& a_dequeued_Event);


private slots:
    void on_new_connection();
    void on_data_received();
    void on_request_received();

signals:
    void eventReceived(const Event &event);
    void requestReceived(int room_number);

private:
    QScopedPointer<QTcpServer> m_server;
    QScopedPointer<QTcpSocket> m_forwarding_socket;
    //Event m_event;
};

#endif // SIMPLE_SERVER_HPP
