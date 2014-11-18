#include "irctextformatter.h"
#include <IrcTextFormat>

NotificationBar notification;
QSettings* settings = 0;
QDialog* mainwin = 0;

IRCTextFormatter::IRCTextFormatter()
{
}

QString IRCTextFormatter::filterMessage(QString message)
{
	if (message.startsWith("$QTH", Qt::CaseInsensitive))
	{
		return QString();
	}
	else if (message.startsWith("$cmd", Qt::CaseInsensitive))
	{
		return QString();
	}
	else if (message.startsWith("$hut", Qt::CaseInsensitive))
	{
		return QString();
	}
	else if (message.startsWith("$map", Qt::CaseInsensitive))
	{
		return QString();
	}

	return message;
}

QString IRCTextFormatter::formatMessage(IrcMessage* message)
{
	QString formatted;
	switch (message->type()) 
	{
	case IrcMessage::Join:
		formatted = formatJoinMessage(static_cast<IrcJoinMessage*>(message));
		break;
	case IrcMessage::Mode:
		formatted = formatModeMessage(static_cast<IrcModeMessage*>(message));
		break;
	case IrcMessage::Names:
		formatted = formatNamesMessage(static_cast<IrcNamesMessage*>(message));
		break;
	case IrcMessage::Nick:
		formatted = formatNickMessage(static_cast<IrcNickMessage*>(message));
		break;
	case IrcMessage::Part:
		formatted = formatPartMessage(static_cast<IrcPartMessage*>(message));
		break;
	case IrcMessage::Private:
		formatted = formatPrivateMessage(static_cast<IrcPrivateMessage*>(message));
		break;
	case IrcMessage::Quit:
		formatted = formatQuitMessage(static_cast<IrcQuitMessage*>(message));
		break;
	default:
		break;
	}
	return formatMessage(formatted);
}

QString IRCTextFormatter::formatMessage(const QString& message)
{
	if (!message.isEmpty()) 
	{
		QString formatted = QObject::tr("[%1] %2").arg(QTime::currentTime().toString(), message);

		if (settings->value("timestamp", true).toBool())
		{
			formatted = QObject::tr("[%1] %2").arg(QTime::currentTime().toString(), message);
		}
		else
		{
			formatted = QObject::tr("%2").arg(message);
		}

		/*if (message.startsWith("!"))
			formatted = QObject::tr("<font color='gray'>%1</font>").arg(formatted);
		else if (message.startsWith("*"))
			formatted = QObject::tr("<font color='maroon'>%1</font>").arg(formatted);
		else if (message.startsWith("["))
			formatted = QObject::tr("<font color='indianred'>%1</font>").arg(formatted);*/
		return formatted;
	}
	return QString();
}

QString IRCTextFormatter::formatJoinMessage(IrcJoinMessage* message)
{
	if (message->flags() & IrcMessage::Own)
		/*return QObject::tr("! You have joined %1 as %2").arg(message->channel(), message->nick());*/
		return "";
	else
		return QObject::tr("<font color='CornflowerBlue'>%1 in</font>").arg(praseNick(message->nick()));
		/*return QObject::tr("! %1 has joined %2").arg(message->nick(), message->channel());*/
}

QString IRCTextFormatter::formatModeMessage(IrcModeMessage* message)
{
	return "";
	/*QString args = message->arguments().join(" ");
	if (message->isReply())
		return QObject::tr("! %1 mode is %2 %3").arg(message->target(), message->mode(), args);
	else
		return QObject::tr("! %1 sets mode %2 %3 %4").arg(message->nick(), message->target(), message->mode(), args);*/
}

QString IRCTextFormatter::formatNamesMessage(IrcNamesMessage* message)
{
	return "";
	//return QObject::tr("! %1 has %2 users").arg(message->channel()).arg(message->names().count());
}

QString IRCTextFormatter::formatNickMessage(IrcNickMessage* message)
{
	return "";
	//return QObject::tr("! %1 has changed nick to %2").arg(message->oldNick(), message->newNick());
}

QString IRCTextFormatter::formatPartMessage(IrcPartMessage* message)
{
	/*if (message->reason().isEmpty())
		return QObject::tr("%1 has left %2").arg(message->nick(), message->channel());
	else
		return QObject::tr("%1 has left %2 (%3)").arg(message->nick(), message->channel(), message->reason());*/

	return QObject::tr("<font color='CornflowerBlue'>%1 out</font>").arg(praseNick(message->nick()));
}

QString IRCTextFormatter::formatPrivateMessage(IrcPrivateMessage* message)
{
	const QString content = IrcTextFormat().toHtml(filterMessage(message->content()));

	if (content.isEmpty()) return QString();

	if (message->isAction())
		return QObject::tr("* %1&gt %3: %2").arg(message->nick(), content, message->target());
	else
	{
		QString target = message->target();

		QString playerColor = "RoyalBlue";
		if (message->isOwn())
		{
			playerColor = "DarkMagenta";
		}

		
		if ((message->isPrivate() || !target.isEmpty()) && !target.startsWith("#"))
		{
			QString target = message->target();

			if (settings->value("notification", true).toBool())
			{
				notification.setNotification(QString("%1 says : ").arg(praseNick(message->nick())), QString("%1").arg(content));
			}			
			return QObject::tr("<font color='%4'>%1&gt;</font><font color='green'> %3: %2</font>").arg(praseNick(message->nick()), content, praseNick(target), playerColor);
		}

		return QObject::tr("<font color='%3'>%1&gt;</font> %2").arg(praseNick(message->nick()), content, playerColor);
	}
}

QString IRCTextFormatter::formatQuitMessage(IrcQuitMessage* message)
{
	/*if (message->reason().isEmpty())
		return QObject::tr("! %1 has quit").arg(message->nick());
	else
		return QObject::tr("! %1 has quit (%2)").arg(message->nick(), message->reason());*/
	return QObject::tr("<font color='CornflowerBlue'>%1 out</font>").arg(praseNick(message->nick()));
}

QString IRCTextFormatter::praseNick(QString nick)
{
	if (nick.startsWith("y", Qt::CaseInsensitive))
		return nick.mid(4);
	else return nick;
}