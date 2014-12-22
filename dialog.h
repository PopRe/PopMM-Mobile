#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QUrlQuery>
#include <QCryptographicHash>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDomComment>
#include <QVector>
#include <QSslSocket>
#include <QTimer>
#include <QSettings>
#include <Irc>
#include <IrcUser>
#include <IrcBuffer>
#include <IrcCommand>
#include <IrcMessage>
#include <IrcUserModel>
#include <IrcCompleter>
#include <IrcConnection>
#include <IrcBufferModel>
#include <IrcCommandParser>
#include <IrcTextFormat>
#include <QMessageBox>
#include <QScrollBar>
#include <QStyledItemDelegate>
#include <QAbstractTextDocumentLayout>
#include <QPainter>
#include <QSortFilterProxyModel>
#include "notificationbar.h"
#include "irctextformatter.h"

#define POPMM_VERSION "1.0"

namespace Ui {
class Dialog;
}

struct IrcNetworkInfo
{
	QString name;
	QString server_default;
	QString server_name;
	QString server_addr;
	QString server_port;
	QString srever_channel;
	QString server_password;
	QString server_ssl;
};

class HtmlDelegate : public QStyledItemDelegate
{
public:
	explicit HtmlDelegate(QObject* parent = 0);

protected:
	void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
	QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const;
};

class CustomSort : public QSortFilterProxyModel
{
	Q_OBJECT

public:
	explicit CustomSort(QObject* parent = 0);
    // QSortFilterProxyModel interface
protected:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
};

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
	QNetworkAccessManager* mgr;
	IrcConnection* connection;
	IrcBufferModel* buffer;
	IrcUserModel* model;
	IrcCommandParser* parser;
	CustomSort* proxymodel;
	QVector<IrcNetworkInfo> networks;
	QString loggeduser;;
	bool makehash;
	bool wassetting;
	QString username;
	QString welcome;
	QString curchannel;
	QString oldmessage;

	void createParser();
	void scrollToEnd(QString val);
	QStringList usersMatchList(QString user);

public slots:
	void requestFinished(QNetworkReply*);
	void login(QString username, QString password);
	void connectIRC();
	void disconnectIRC();
	void onConnected();
	void onConnecting();
	void onDisconnected();

	void onBufferAdded(IrcBuffer* buff);
	void onBufferRemoved(IrcBuffer* buff);
	void setChannels(QStringList list);
	void receiveMessage(IrcMessage* msg);

	void onTextEntered();
	void connectAll();
	void disconnectAll();

private slots:
    void on_btn_send_clicked();
    void on_usernameLineEdit_textChanged(const QString &arg1);
    void on_passwordLineEdit_textChanged(const QString &arg1);
    void on_btn_players_clicked(bool checked);
    void on_btn_settings_clicked(bool checked);
    void on_usersList_activated(const QModelIndex &index);
    void on_btn_connect_clicked();
    void on_textBrowser_textChanged();
	void rangeChanged();
    void on_btn_info_clicked();
	void errorMessageReceived(IrcErrorMessage* msg);
    void on_showTimestampCheckBox_toggled(bool checked);
    void on_pvtNotificationsCheckBox_toggled(bool checked);
    void on_textBrowser_cursorPositionChanged();
    void on_maxLinesSpinBox_valueChanged(int arg1);
};

#endif // DIALOG_H
