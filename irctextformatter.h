#ifndef IRCTEXTFORMATTER_H
#define IRCTEXTFORMATTER_H

#include <IrcMessage>
#include <QSettings>
#include <QDialog>
#include "notificationbar.h"

extern QSettings* settings;
extern NotificationBar notification;
extern QDialog* mainwin;

class IRCTextFormatter
{
public:
    IRCTextFormatter();
	static QString formatMessage(IrcMessage* message);
	static QString formatMessage(const QString& message);
	static QString praseNick(QString nick);
	static QString filterMessage(QString message);

private:
	static QString formatJoinMessage(IrcJoinMessage* message);
	static QString formatModeMessage(IrcModeMessage* message);
	static QString formatNamesMessage(IrcNamesMessage* message);
	static QString formatNickMessage(IrcNickMessage* message);
	static QString formatPartMessage(IrcPartMessage* message);
	static QString formatPrivateMessage(IrcPrivateMessage* message);
	static QString formatQuitMessage(IrcQuitMessage* message);
};

#endif // IRCTEXTFORMATTER_H
