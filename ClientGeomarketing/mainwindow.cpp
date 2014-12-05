#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytcpsocket.h"
#include <QMessageBox>
#include <QNetworkInterface>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    s.doConnect();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
 /*   QString mac;
    QList<QString> possibleMatches;
    QList<QNetworkInterface> ifaces = QNetworkInterface::allInterfaces();
    if ( !ifaces.isEmpty() )
    {
      for(int i=0; i < ifaces.size(); i++)
      {
        unsigned int flags = ifaces[i].flags();
        bool isLoopback = (bool)(flags & QNetworkInterface::IsLoopBack);
        bool isP2P = (bool)(flags & QNetworkInterface::IsPointToPoint);
        bool isRunning = (bool)(flags & QNetworkInterface::IsRunning);

        // If this interface isn't running, we don't care about it
        if ( !isRunning ) continue;
        // We only want valid interfaces that aren't loopback/virtual and not point to point
        if ( !ifaces[i].isValid() || isLoopback || isP2P ) continue;
        QList<QHostAddress> addresses = ifaces[i].allAddresses();
        for(int a=0; a < addresses.size(); a++)
        {
          // Ignore local host
          if ( addresses[a] == QHostAddress::LocalHost ) continue;

          // Ignore non-ipv4 addresses
          if ( !addresses[a].toIPv4Address() ) continue;

          QString ip = addresses[a].toString();
          if ( ip.isEmpty() ) continue;
          bool foundMatch = false;
          for (int j=0; j < possibleMatches.size(); j++) if ( ip == possibleMatches[j] ) { foundMatch = true; break; }
          if ( !foundMatch ) { possibleMatches.push_back( ip );
             mac = ifaces[i].hardwareAddress();
          }
        }
      }
    }
    */
    QStringList macs;
    QString mac;
    foreach(QNetworkInterface interface, QNetworkInterface::allInterfaces())
    {
        if(interface.hardwareAddress()!="00:00:00:00:00:00"){
            macs.append(interface.hardwareAddress());
        }
    }

    mac = macs.join(";");

    QString username = ui->username->text();
    QString password = ui->password->text();

    QByteArray serverData;
    serverData.append("{"+mac+"}|"+username+"|"+password);

    //MyTcpSocket s;
    //s.doConnect();

    s.send(serverData);
    QByteArray responseByte = s.get();
    QString response(responseByte);

    qDebug() << response;

    if(response=="ok"){
       QApplication::quit();
       QString link = "http://www.google.com";
       QDesktopServices::openUrl(QUrl(link));
    }else{
        QMessageBox msgBox;

        msgBox.setText("Username o password errati!");
        msgBox.exec();
    }
    //s.close();





}
