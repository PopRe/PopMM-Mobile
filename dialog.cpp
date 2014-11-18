/*Copyright(c) 2014 Omkar Kanase

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.*/

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
	ui->groupBox->setHidden(true);
	model = 0;
	wassetting = false;
	settings = new QSettings(this);
	mainwin = this;

	//QString listcol = "F0F8FF,FAEBD7,00FFFF,7FFFD4,F0FFFF,F5F5DC,FFE4C4,0,FFEBCD,0000FF,8A2BE2,A52A2A,DEB887,5F9EA0,7FFF00,D2691E,FF7F50,6495ED,FFF8DC,DC143C,00FFFF,00008B,008B8B,B8860B,A9A9A9,6400,BDB76B,8B008B,556B2F,FF8C00,9932CC,8B0000,E9967A,8FBC8F,483D8B,2F4F4F,00CED1,9400D3,FF1493,00BFFF,696969,1E90FF,B22222,FFFAF0,228B22,FF00FF,DCDCDC,F8F8FF,FFD700,DAA520,808080,8000,ADFF2F,F0FFF0,FF69B4,CD5C5C,4B0082,FFFFF0,F0E68C,E6E6FA,FFF0F5,7CFC00,FFFACD,ADD8E6,F08080,E0FFFF,FAFAD2,D3D3D3,90EE90,FFB6C1,FFA07A,20B2AA,87CEFA,778899,B0C4DE,FFFFE0,00FF00,32CD32,FAF0E6,FF00FF,800000,66CDAA,0000CD,BA55D3,9370DB,3CB371,7B68EE,00FA9A,48D1CC,C71585,191970,F5FFFA,FFE4E1,FFE4B5,FFDEAD,80,FDF5E6,808000,6B8E23,FFA500,FF4500,DA70D6,EEE8AA,98FB98,AFEEEE,DB7093,FFEFD5,FFDAB9,CD853F,FFC0CB,DDA0DD,B0E0E6,800080,FF0000,BC8F8F,4169E1,8B4513,FA8072,F4A460,2E8B57,FFF5EE,A0522D,C0C0C0,87CEEB,6A5ACD,708090,FFFAFA,00FF7F,4682B4,D2B48C,8080,D8BFD8,FF6347,40E0D0,EE82EE,F5DEB3,FFFFFF,F5F5F5,FFFF00,9ACD32,F0F8FF,FAEBD7,00FFFF,7FFFD4,F0FFFF,F5F5DC,FFE4C4,0,FFEBCD,0000FF,8A2BE2,A52A2A,DEB887,5F9EA0,7FFF00,D2691E,FF7F50,6495ED,FFF8DC,DC143C,00FFFF,00008B,008B8B,B8860B,A9A9A9,6400,BDB76B,8B008B,556B2F,FF8C00,9932CC,8B0000,E9967A,8FBC8F,483D8B,2F4F4F,00CED1,9400D3,FF1493,00BFFF,696969,1E90FF,B22222,FFFAF0,228B22,FF00FF,DCDCDC,F8F8FF,FFD700,DAA520,808080,8000,ADFF2F,F0FFF0,FF69B4,CD5C5C,4B0082,FFFFF0,F0E68C,E6E6FA,FFF0F5,7CFC00,FFFACD,ADD8E6,F08080,E0FFFF,FAFAD2,D3D3D3,90EE90,FFB6C1,FFA07A,20B2AA,87CEFA,778899,B0C4DE,FFFFE0,00FF00,32CD32,FAF0E6,FF00FF,800000,66CDAA,0000CD,BA55D3,9370DB,3CB371,7B68EE,00FA9A,48D1CC,C71585,191970,F5FFFA,FFE4E1,FFE4B5,FFDEAD,80,FDF5E6,808000,6B8E23,FFA500,FF4500,DA70D6,EEE8AA,98FB98,AFEEEE,DB7093,FFEFD5,FFDAB9,CD853F,FFC0CB,DDA0DD,B0E0E6,800080,FF0000,BC8F8F,4169E1,8B4513,FA8072,F4A460,2E8B57,FFF5EE,A0522D,C0C0C0,87CEEB,6A5ACD,708090,FFFAFA,00FF7F,4682B4,D2B48C,8080,D8BFD8,FF6347,40E0D0,EE82EE,F5DEB3,FFFFFF,F5F5F5,FFFF00,9ACD32,F0F8FF,FAEBD7,00FFFF,7FFFD4,F0FFFF,F5F5DC,FFE4C4,0,FFEBCD,0000FF,8A2BE2,A52A2A,DEB887,5F9EA0,7FFF00,D2691E,FF7F50,6495ED,FFF8DC,DC143C,00FFFF,00008B,008B8B,B8860B,A9A9A9,6400,BDB76B,8B008B,556B2F,FF8C00,9932CC,8B0000,E9967A,8FBC8F,483D8B,2F4F4F,00CED1,9400D3,FF1493,00BFFF,696969,1E90FF,B22222,FFFAF0,228B22,FF00FF,DCDCDC,F8F8FF,FFD700,DAA520,808080,8000,ADFF2F,F0FFF0,FF69B4,CD5C5C,4B0082,FFFFF0,F0E68C,E6E6FA,FFF0F5,7CFC00,FFFACD,ADD8E6,F08080,E0FFFF,FAFAD2,D3D3D3,90EE90,FFB6C1,FFA07A,20B2AA,87CEFA,778899,B0C4DE,FFFFE0,00FF00,32CD32,FAF0E6,FF00FF,800000,66CDAA,0000CD,BA55D3,9370DB,3CB371,7B68EE,00FA9A,48D1CC,C71585,191970,F5FFFA,FFE4E1,FFE4B5,FFDEAD,80,FDF5E6,808000,6B8E23,FFA500,FF4500,DA70D6,EEE8AA,98FB98,AFEEEE,DB7093,FFEFD5,FFDAB9,CD853F,FFC0CB,DDA0DD,B0E0E6,800080,FF0000,BC8F8F,4169E1,8B4513,FA8072,F4A460,2E8B57,FFF5EE,A0522D,C0C0C0,87CEEB,6A5ACD,708090,FFFAFA,00FF7F,4682B4,D2B48C,8080,D8BFD8,FF6347,40E0D0,EE82EE,F5DEB3,FFFFFF,F5F5F5,FFFF00,9ACD32,F0F8FF,FAEBD7,00FFFF,7FFFD4,F0FFFF,F5F5DC,FFE4C4,0,FFEBCD,0000FF,8A2BE2,A52A2A,DEB887,5F9EA0,7FFF00,D2691E,FF7F50,6495ED,FFF8DC,DC143C,00FFFF,00008B,008B8B,B8860B,A9A9A9,6400,BDB76B,8B008B,556B2F,FF8C00,9932CC,8B0000,E9967A,8FBC8F,483D8B,2F4F4F,00CED1,9400D3,FF1493,00BFFF,696969,1E90FF,B22222,FFFAF0,228B22,FF00FF,DCDCDC,F8F8FF,FFD700,DAA520,808080,8000,ADFF2F,F0FFF0,FF69B4,CD5C5C,4B0082,FFFFF0,F0E68C,E6E6FA,FFF0F5,7CFC00,FFFACD,ADD8E6,F08080,E0FFFF,FAFAD2,D3D3D3,90EE90,FFB6C1,FFA07A,20B2AA,87CEFA,778899,B0C4DE,FFFFE0,00FF00,32CD32,FAF0E6,FF00FF,800000,66CDAA,0000CD,BA55D3,9370DB,3CB371,7B68EE,00FA9A,48D1CC,C71585,191970,F5FFFA,FFE4E1,FFE4B5,FFDEAD,80,FDF5E6,808000,6B8E23,FFA500,FF4500,DA70D6,EEE8AA,98FB98,AFEEEE,DB7093,FFEFD5,FFDAB9,CD853F,FFC0CB,DDA0DD,B0E0E6,800080,FF0000,BC8F8F,4169E1,8B4513,FA8072,F4A460,2E8B57,FFF5EE,A0522D,C0C0C0,87CEEB,6A5ACD,708090,FFFAFA,00FF7F,4682B4,D2B48C,8080,D8BFD8,FF6347,40E0D0,EE82EE,F5DEB3,FFFFFF,F5F5F5,FFFF00,9ACD32,F0F8FF,FAEBD7,00FFFF,7FFFD4,F0FFFF,F5F5DC,FFE4C4,0,FFEBCD,0000FF,8A2BE2,A52A2A,DEB887,5F9EA0,7FFF00,D2691E,FF7F50,6495ED,FFF8DC,DC143C,00FFFF,00008B,008B8B,B8860B,A9A9A9,6400,BDB76B,8B008B,556B2F,FF8C00,9932CC,8B0000,E9967A,8FBC8F,483D8B,2F4F4F,00CED1,9400D3,FF1493,00BFFF,696969,1E90FF,B22222,FFFAF0,228B22,FF00FF,DCDCDC,F8F8FF,FFD700,DAA520,808080,8000,ADFF2F,F0FFF0,FF69B4,CD5C5C,4B0082,FFFFF0,F0E68C,E6E6FA,FFF0F5,7CFC00,FFFACD,ADD8E6,F08080,E0FFFF,FAFAD2,D3D3D3,90EE90,FFB6C1,FFA07A,20B2AA,87CEFA,778899,B0C4DE,FFFFE0,00FF00,32CD32,FAF0E6,FF00FF,800000,66CDAA,0000CD,BA55D3,9370DB,3CB371,7B68EE,00FA9A,48D1CC,C71585,191970,F5FFFA,FFE4E1,FFE4B5,FFDEAD,80,FDF5E6,808000,6B8E23,FFA500,FF4500,DA70D6,EEE8AA,98FB98,AFEEEE,DB7093,FFEFD5,FFDAB9,CD853F,FFC0CB,DDA0DD,B0E0E6,800080,FF0000,BC8F8F,4169E1,8B4513,FA8072,F4A460,2E8B57,FFF5EE,A0522D,C0C0C0,87CEEB,6A5ACD,708090,FFFAFA,00FF7F,4682B4,D2B48C,8080,D8BFD8,FF6347,40E0D0,EE82EE,F5DEB3,FFFFFF,F5F5F5,FFFF00,9ACD32,F0F8FF,FAEBD7,00FFFF,7FFFD4,F0FFFF,F5F5DC,FFE4C4,0,FFEBCD,0000FF,8A2BE2,A52A2A,DEB887,5F9EA0,7FFF00,D2691E,FF7F50,6495ED,FFF8DC,DC143C,00FFFF,00008B,008B8B,B8860B,A9A9A9,6400,BDB76B,8B008B,556B2F,FF8C00,9932CC,8B0000,E9967A,8FBC8F,483D8B,2F4F4F,00CED1,9400D3,FF1493,00BFFF,696969,1E90FF,B22222,FFFAF0,228B22,FF00FF,DCDCDC,F8F8FF,FFD700,DAA520,808080,8000,ADFF2F,F0FFF0,FF69B4,CD5C5C,4B0082,FFFFF0,F0E68C,E6E6FA,FFF0F5,7CFC00,FFFACD,ADD8E6,F08080,E0FFFF,FAFAD2,D3D3D3,90EE90,FFB6C1,FFA07A,20B2AA,87CEFA,778899,B0C4DE,FFFFE0,00FF00,32CD32,FAF0E6,FF00FF,800000,66CDAA,0000CD,BA55D3,9370DB,3CB371,7B68EE,00FA9A,48D1CC,C71585,191970,F5FFFA,FFE4E1,FFE4B5,FFDEAD,80,FDF5E6,808000,6B8E23,FFA500,FF4500,DA70D6,EEE8AA,98FB98,AFEEEE,DB7093,FFEFD5,FFDAB9,CD853F,FFC0CB,DDA0DD,B0E0E6,800080,FF0000,BC8F8F,4169E1,8B4513,FA8072,F4A460,2E8B57,FFF5EE,A0522D,C0C0C0,87CEEB,6A5ACD,708090,FFFAFA,00FF7F,4682B4,D2B48C,8080,D8BFD8,FF6347,40E0D0,EE82EE,F5DEB3,FFFFFF,F5F5F5,FFFF00,9ACD32,F0F8FF,FAEBD7,00FFFF,7FFFD4,F0FFFF,F5F5DC,FFE4C4,0,FFEBCD,0000FF,8A2BE2,A52A2A,DEB887,5F9EA0,7FFF00,D2691E,FF7F50,6495ED,FFF8DC,DC143C,00FFFF,00008B,008B8B,B8860B,A9A9A9,6400,BDB76B,8B008B,556B2F,FF8C00,9932CC,8B0000,E9967A,8FBC8F,483D8B,2F4F4F,00CED1,9400D3,FF1493,00BFFF,696969,1E90FF,B22222,FFFAF0,228B22,FF00FF,DCDCDC,F8F8FF,FFD700,DAA520,808080,8000,ADFF2F,F0FFF0,FF69B4,CD5C5C,4B0082,FFFFF0,F0E68C,E6E6FA,FFF0F5,7CFC00,FFFACD,ADD8E6,F08080,E0FFFF,FAFAD2,D3D3D3,90EE90,FFB6C1,FFA07A,20B2AA,87CEFA,778899,B0C4DE,FFFFE0,00FF00,32CD32,FAF0E6,FF00FF,800000,66CDAA,0000CD,BA55D3,9370DB,3CB371,7B68EE,00FA9A,48D1CC,C71585,191970,F5FFFA,FFE4E1,FFE4B5,FFDEAD,80,FDF5E6,808000,6B8E23,FFA500,FF4500,DA70D6,EEE8AA,98FB98,AFEEEE,DB7093,FFEFD5,FFDAB9,CD853F,FFC0CB,DDA0DD,B0E0E6,800080,FF0000,BC8F8F,4169E1,8B4513,FA8072,F4A460,2E8B57,FFF5EE,A0522D,C0C0C0,87CEEB,6A5ACD,708090,FFFAFA,00FF7F,4682B4,D2B48C,8080,D8BFD8,FF6347,40E0D0,EE82EE,F5DEB3,FFFFFF,F5F5F5,FFFF00,9ACD32,F0F8FF,FAEBD7,00FFFF,7FFFD4,F0FFFF,F5F5DC,FFE4C4,0,FFEBCD,0000FF,8A2BE2,A52A2A,DEB887,5F9EA0,7FFF00,D2691E,FF7F50,6495ED,FFF8DC,DC143C,00FFFF,00008B,008B8B,B8860B,A9A9A9,6400,BDB76B,8B008B,556B2F,FF8C00,9932CC,8B0000,E9967A,8FBC8F,483D8B,2F4F4F,00CED1,9400D3,FF1493,00BFFF,696969,1E90FF,B22222,FFFAF0";
	//QStringList lst = listcol.split(",");
	//
	///*ui->backgroundComboBox->addItems(lst);

	//for (int i = 0; i < ui->backgroundComboBox->count(); i++)
	//{
	//	ui->backgroundComboBox->setItemData(i, QColor("#" + ui->backgroundComboBox->itemText(i)), Qt::BackgroundRole);
	//}*/

	QFontMetrics fm(ui->btn_send->font());
	//int height = this->width() * 0.1f;
	ui->btn_send->setIconSize(QSize(fm.height() * 1, fm.height() * 1));

	ui->btn_info->setIconSize(QSize(fm.height() * 2, fm.height() * 2));
	ui->btn_players->setIconSize(QSize(fm.height() * 2, fm.height() * 2));
	ui->btn_connect->setIconSize(QSize(fm.height() * 2, fm.height() * 2));
	ui->btn_settings->setIconSize(QSize(fm.height() * 2, fm.height() * 2));

	ui->usersList->setItemDelegate(new HtmlDelegate(ui->usersList));

	//connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(onTextEntered()));
	//connect(ui->textBrowser->verticalScrollBar(), SIGNAL(rangeChanged()), this, SLOT(rrangeChanged()));

	makehash = false;
	ui->usernameLineEdit->setText(settings->value("username", "").toString());
	ui->passwordLineEdit->setText(settings->value("password", "").toString());
	ui->pvtNotificationsCheckBox->setChecked(settings->value("notification", true).toBool());
	ui->showTimestampCheckBox->setChecked(settings->value("timestamp", true).toBool());
    ui->maxLinesSpinBox->setValue(settings->value("maxlines", 300).toInt());
	makehash = true;

	parser = new IrcCommandParser(this);
	createParser();

	mgr = new QNetworkAccessManager(this);
	connect(mgr, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));

    /*bool s = QSslSocket::supportsSsl();
    if(s) this->setWindowTitle("supported");
    else this->setWindowTitle("not supported");	*/

	//notification.setNotification("test", "this is test:");

	qsrand(QTime::currentTime().msec());

	connectAll();	
}

void Dialog::connectAll()
{
	if (wassetting)
	{
		ui->btn_players->setChecked(true);
		ui->usersList->show();
		ui->textBrowser->show();
		ui->groupBox->hide();
		ui->btn_settings->setChecked(false);
		ui->btn_settings->setDisabled(false);
		ui->btn_players->setDisabled(false);
		wassetting = false;
	}
	connection = new IrcConnection(this);
	connect(connection, SIGNAL(connected()), this, SLOT(onConnected()));
	connect(connection, SIGNAL(connecting()), this, SLOT(onConnecting()));
	connect(connection, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
	connect(connection, SIGNAL(errorMessageReceived(IrcErrorMessage* msg)), this, SLOT(errorMessageReceived(IrcErrorMessage* msg)));

	buffer = new IrcBufferModel(connection);
	connect(buffer, SIGNAL(added(IrcBuffer*)), this, SLOT(onBufferAdded(IrcBuffer*)));
	connect(buffer, SIGNAL(removed(IrcBuffer*)), this, SLOT(onBufferRemoved(IrcBuffer*)));
	connect(buffer, SIGNAL(channelsChanged(QStringList)), this, SLOT(setChannels(QStringList)));

	QString username = settings->value("username", "").toString();
	QString password = settings->value("password", "").toString();

	if (username.isEmpty() || password.isEmpty())
	{
		ui->statuslabel->setText(QString("Status : Username/Password not set"));
		//QMessageBox::information(this, "Settings", "Username/Password are not set, Please enter Username/Password and then try pressing connect button");
		ui->groupBox->show();
		ui->btn_settings->setChecked(true);
		ui->usersList->hide();
		ui->btn_players->setChecked(false);
		ui->textBrowser->hide();
		ui->btn_settings->setDisabled(true);
		ui->btn_players->setDisabled(true);
		wassetting = true;
		return;
	}

	login(username, password);
}

void Dialog::disconnectAll()
{
	disconnectIRC();
	loggeduser = "";
	username = "";
	ui->statuslabel->show();
}

void Dialog::createParser()
{
	parser->setTolerant(true);
	parser->setTriggers(QStringList("!"));
	/*parser->addCommand(IrcCommand::Join, "JOIN <#channel> (<key>)");*/
	parser->addCommand(IrcCommand::CtcpAction, "ME [target] <message...>");
	/*parser->addCommand(IrcCommand::Mode, "MODE (<channel/user>) (<mode>) (<arg>)");
	parser->addCommand(IrcCommand::Nick, "NICK <nick>");*/
	parser->addCommand(IrcCommand::Part, "PART (<#channel>) (<message...>)");
	parser->addCommand(IrcCommand::Message, "PRIVMSG <user/channel> (<message...>)");
	parser->addCommand(IrcCommand::Message, "pvt: <user> (<message...>)");
	parser->addCommand(IrcCommand::Message, "p [target] <message...>");
}

void Dialog::errorMessageReceived(IrcErrorMessage* msg)
{
	scrollToEnd(QString("<br/><font color='Red'>error : %1</font>").arg(msg->error()));
}

void Dialog::receiveMessage(IrcMessage* msg)
{
	QString dt = IRCTextFormatter::formatMessage(msg);

	if (!dt.isEmpty())
	scrollToEnd("<br/>" + dt);
	//QString dt = IrcTextFormat().toHtml(msg->content());
}

void Dialog::onBufferAdded(IrcBuffer* buff)
{
	connect(buff, SIGNAL(messageReceived(IrcMessage*)), this, SLOT(receiveMessage(IrcMessage*)));

	if (model == 0)
	{
		model = new IrcUserModel(buff);
		model->setDisplayRole(Irc::UserRole);
		ui->usersList->setModel(model);
	}	
}

void Dialog::onBufferRemoved(IrcBuffer* buff)
{
	if (model->parent() == buff)
		ui->usersList->setModel(0);
}

void Dialog::setChannels(QStringList list)
{

}

void Dialog::disconnectIRC()
{
	if (connection)
	{
		connection->quit();
		QTimer::singleShot(5000, connection, SLOT(deleteLater()));
	}
}

QStringList Dialog::usersMatchList(QString user)
{
	QStringList lst;

	if (model)
	{
		for (int i = 0; i < model->rowCount(); i++)
		{
			QModelIndex ind = model->index(i);
			QString nick = ind.data(Qt::DisplayRole).toString();
			if (IRCTextFormatter::praseNick(nick) == user)
			{
				lst.append(nick);
			}
		}
	}

	return lst;
}

void Dialog::onTextEntered()
{
	QString input = ui->lineEdit->text();

	IrcCommand* command = 0;

	if (!input.startsWith("!") && input.size() > 0)
	{
		command = IrcCommand::createMessage(curchannel, input);	
		if (input == oldmessage || input.isEmpty())
		{
			return;
		}
		oldmessage = input;
	}
	else
	{
		if (input.startsWith("!pvt:"))
		{
			QString targetname, message;
			QRegularExpression regex("(?<=!pvt: )(.*)(?=\\> )(\\> )(.*)");
			QRegularExpressionMatch match = regex.match(input);
			if (match.hasMatch())
			{
				if (match.capturedLength() > 3)
				{
					targetname = match.captured(1);
					message = match.captured(3);
					if (message == oldmessage || message.isEmpty())
					{
						return;
					}
					oldmessage = message;
				}

				QStringList lst = usersMatchList(targetname);
				bool printed = false;
				for (int i = 0; i < lst.size(); i++)
				{
					QString commandtxt = QString("!pvt: %1 %2").arg(lst[i], message);
					command = parser->parse(commandtxt);

					if (command)
					{
						connection->sendCommand(command);
						if ((command->type() == IrcCommand::Message || command->type() == IrcCommand::CtcpAction) && !printed)
						{
							IrcMessage* msg = command->toMessage(connection->nickName(), connection);
							receiveMessage(msg);
							delete msg;
							printed = true;
						}
					}
				}

				ui->lineEdit->clear();

				if (input.startsWith("!pvt:"))
				{
					if (!username.isEmpty())
					{
						ui->lineEdit->setText(QString("!pvt: %1> ").arg(username));
						ui->lineEdit->setFocus();
					}
					else
					{
						ui->lineEdit->setText("");
					}
				}
				else
				{
					ui->lineEdit->setText("");
				}

				return;
			}
		}

		command = parser->parse(input);
	}

	if (command) 
	{
		connection->sendCommand(command);
		// echo own messages (servers do not send our own messages back)
		if (command->type() == IrcCommand::Message || command->type() == IrcCommand::CtcpAction) 
		{
			IrcMessage* msg = command->toMessage(connection->nickName(), connection);
			receiveMessage(msg);
			delete msg;
		}
		ui->lineEdit->clear();
	}
	else if (input.length() > 1) 
	{
		QString error;
		QString command = ui->lineEdit->text().mid(1).split(" ", QString::SkipEmptyParts).value(0).toUpper();
		if (parser->commands().contains(command))
		{
			error = tr("[ERROR] Syntax: %1").arg(parser->syntax(command).replace("<", "&lt;").replace(">", "&gt;"));
		}
		else
		{
			error = tr("[ERROR] Unknown command: %1").arg(command);
		}
		ui->textBrowser->append(IRCTextFormatter::formatMessage(error));
	}

	if (input.startsWith("!pvt:"))
	{
		if (!username.isEmpty())
		{
			ui->lineEdit->setText(QString("!pvt: %1> ").arg(username));
			ui->lineEdit->setFocus();
		}
		else
		{
			ui->lineEdit->setText("");
		}
	}
	else
	{
		ui->lineEdit->setText("");
	}	
}

void Dialog::onConnected()
{
	ui->statuslabel->setText(QString("Status : Connected"));
	ui->statuslabel->hide();
	ui->btn_connect->setText("Disconnect");
	ui->btn_connect->setEnabled(true);
	ui->textBrowser->insertPlainText(welcome);
	scrollToEnd("<br/>");
}

void Dialog::onConnecting()
{
	ui->statuslabel->setText(QString("Status : Connecting"));
}

void Dialog::onDisconnected()
{
	ui->statuslabel->show();
	ui->statuslabel->setText(QString("Status : Disconnected"));
	ui->btn_connect->setText("Connect");
	connection = 0;
	model = 0;
	ui->usersList->setModel(0);
	ui->btn_connect->setEnabled(true);
}

void Dialog::connectIRC()
{
	if (!networks.size())
	{
		ui->statuslabel->setText(QString("Status : No network found"));
		ui->btn_connect->setEnabled(true);
		return;
	}

	if (loggeduser.isEmpty())
	{
		ui->statuslabel->setText(QString("Status : Not logged in"));
		ui->btn_connect->setEnabled(true);
		return;
	}

	IrcNetworkInfo net;
	bool found = false;

	for (int i = 0; i < networks.size(); i++)
	{
		if (networks[i].server_default == "true")
		{
			net = networks[i]; 
			found = true;
			break;
		}
	}

	if (!found)
	{
		net = networks[0];
	}

	connection->setHost(net.server_addr);
#ifdef __ANDROID__
	connection->setUserName(QString("y000%1").arg(loggeduser));
#else
	connection->setUserName(QString("y001%1").arg(loggeduser));
#endif
	connection->setPort(net.server_port.toInt());
	if (net.server_ssl == "true")
	{
		if (QSslSocket::supportsSsl() == false)
		{
			ui->statuslabel->setText(QString("Status : SSL not found"));
			ui->btn_connect->setEnabled(true);
			return;
		}
		connection->setSecure(true);		
	}
#ifdef __ANDROID__
	connection->setNickName(QString("y000%1").arg(loggeduser));
#else
	connection->setNickName(QString("y001%1").arg(loggeduser));
#endif
	connection->setRealName(tr("POPMM Mobile Client %1").arg(POPMM_VERSION));
	connection->sendCommand(IrcCommand::createJoin(net.srever_channel));
	curchannel = net.srever_channel;
	connection->open();
}

void Dialog::requestFinished(QNetworkReply* rep)
{
	QString answer = rep->readAll();
	QDomDocument doc;
	doc.setContent(answer);

	QDomNodeList list = doc.elementsByTagName("login");
	if (list.isEmpty())
	{
		ui->statuslabel->setText(QString("Status : Login failed - %1").arg("Empty response"));
		ui->btn_connect->setEnabled(true);
		return;
	}

	QDomNodeList list2 = list.at(0).toElement().elementsByTagName("POPMM_LOGIN");
	if (list2.isEmpty())
	{
		ui->statuslabel->setText(QString("Status : Login failed - %1").arg("Empty response POPMM_LOGIN"));
		ui->btn_connect->setEnabled(true);
		return;
	}

	QString reason = list2.at(0).toElement().attribute("reason");;
	QString success = list2.at(0).toElement().text();

	if (success == "LOGIN FAILED") 
	{
		ui->statuslabel->setText(QString("Status : Login failed - %1").arg(reason));
		ui->btn_connect->setEnabled(true);
		return;
	}

	if (success == "LOGIN BANNED")
	{
		ui->statuslabel->setText(QString("Status : Login banned - %1").arg(reason));
		ui->btn_connect->setEnabled(true);
		return;
	}

	list2 = list.at(0).toElement().elementsByTagName("welcomemsg");
	if (!list2.isEmpty())
	{
		welcome = list2.at(0).toElement().text();
	}

	networks.clear();
	list2 = list.at(0).toElement().elementsByTagName("network");

	for (int i = 0; i < list2.count(); i++)
	{
		QString networkname = list2.at(i).toElement().attribute("name");
		QDomNodeList list3 = list2.at(i).toElement().elementsByTagName("server");

		for (int f = 0; f < list3.count(); f++)
		{
			IrcNetworkInfo net;
			net.name = networkname;
			net.server_default = list3.at(f).toElement().attribute("default");
			net.server_name = list3.at(f).toElement().attribute("name");
			net.server_addr = list3.at(f).toElement().attribute("server");
			net.server_port = list3.at(f).toElement().attribute("port");
			net.srever_channel = list3.at(f).toElement().attribute("channel");
			net.server_password = list3.at(f).toElement().attribute("password");
			net.server_ssl = list3.at(f).toElement().attribute("ssl");
			networks.push_back(net);
		}
	}

	connectIRC();
}

void Dialog::login(QString username, QString password)
{
	welcome = "";
	ui->btn_connect->setEnabled(false);
	QUrl serviceUrl = QUrl("http://www.popre.net/matchmaker/login.php");
	QByteArray postData;

	postData.append("username=");
	postData.append(username);
	postData.append("&login=Login&password=");
	postData.append(password);

	QNetworkRequest networkRequest(serviceUrl);
	networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	networkRequest.setRawHeader("User-Agent", QString("PopMMMobile/%1").arg(POPMM_VERSION).toStdString().c_str());
	networkRequest.setRawHeader("Referer", "http://www.popre.net");

	mgr->post(networkRequest, postData);
	loggeduser = username;
	ui->statuslabel->setText("Status : Logging in");
}

void Dialog::scrollToEnd(QString txt)
{
	int max = ui->textBrowser->verticalScrollBar()->maximum();
	int val = ui->textBrowser->verticalScrollBar()->value();

	QTextCursor tmpCursor = ui->textBrowser->textCursor();
	tmpCursor.movePosition(QTextCursor::MoveOperation::End);
	ui->textBrowser->setTextCursor(tmpCursor);
	ui->textBrowser->insertHtml(txt);

    if (ui->textBrowser->document()->lineCount() > settings->value("maxlines", 300).toInt())
	{
		QTextCursor tc = ui->textBrowser->textCursor();
		tc.movePosition(QTextCursor::Start);
		tc.select(QTextCursor::LineUnderCursor);
		tc.removeSelectedText();
	}

	if (val >= max - 1)
	{
		QScrollBar *sb = ui->textBrowser->verticalScrollBar();
		sb->setValue(sb->maximum());
	}
	else
	{
		QScrollBar *sb = ui->textBrowser->verticalScrollBar();

		sb->setValue(sb->value() - (sb->value() - val));
	}
}

Dialog::~Dialog()
{
	if (connection) connection->quit();
    delete ui;
}

void Dialog::on_btn_send_clicked()
{
	onTextEntered();
}

void Dialog::on_usernameLineEdit_textChanged(const QString &arg1)
{
	settings->setValue("username", arg1);
}

void Dialog::on_passwordLineEdit_textChanged(const QString &arg1)
{
	if (makehash)
	{
		QString pass = QString(QCryptographicHash::hash(QByteArray(arg1.toStdString().c_str()), QCryptographicHash::Md5).toHex());
		settings->setValue("password", pass);
	}
	else
	{
		settings->setValue("password", arg1);
	}
	
}

void Dialog::on_btn_players_clicked(bool checked)
{
	if (checked)
	{
		ui->usersList->setVisible(true);
		ui->groupBox->setVisible(false);
		ui->btn_settings->setChecked(false);
	}
	else
	{
		ui->usersList->setVisible(false);
	}
}

void Dialog::on_btn_settings_clicked(bool checked)
{
	if (checked)
	{
		ui->groupBox->setVisible(true);
		ui->usersList->setVisible(false);
		ui->btn_players->setChecked(false);
	}
	else
	{
		ui->groupBox->setVisible(false);
	}
}

void Dialog::on_usersList_activated(const QModelIndex &index)
{
	IrcUser* user = model->user(index);
	if (user)
	{
		username = IRCTextFormatter::praseNick(user->name());
		ui->lineEdit->setText(QString("!pvt: %1> ").arg(username));
		ui->lineEdit->setFocus();
	}
}

void Dialog::on_btn_connect_clicked()
{
	if (ui->btn_connect->text() == "Connect")
	{
		disconnectAll();
		connectAll();
	}
	else if (ui->btn_connect->text() == "Disconnect")
	{
		disconnectAll();
	}
}

void Dialog::on_textBrowser_textChanged()
{
		
}

void Dialog::rangeChanged()
{
	
}


//delegate
HtmlDelegate::HtmlDelegate(QObject* parent) : QStyledItemDelegate(parent)
{

}

void HtmlDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QStyleOptionViewItemV4 optionV4 = option;
	initStyleOption(&optionV4, index);

	QStyle *style = optionV4.widget ? optionV4.widget->style() : QApplication::style();

	IrcUser* u = index.data().value<IrcUser*>();

	QTextDocument doc;
	//QString txt = IRCTextFormatter::praseNick(optionV4.text);
	QString txt = IRCTextFormatter::praseNick(u->name());
	doc.setPlainText(txt);

	/// Painting item without text
	optionV4.text = QString();
	style->drawControl(QStyle::CE_ItemViewItem, &optionV4, painter);

	QAbstractTextDocumentLayout::PaintContext ctx;

	// Highlighting text if item is selected
	if (optionV4.state & QStyle::State_Selected)
		ctx.palette.setColor(QPalette::Text, optionV4.palette.color(QPalette::Active, QPalette::HighlightedText));

	QRect textRect = style->subElementRect(QStyle::SE_ItemViewItemText, &optionV4);
	painter->save();
	painter->translate(textRect.topLeft());
	painter->setClipRect(textRect.translated(-textRect.topLeft()));
	doc.documentLayout()->draw(painter, ctx);
	painter->restore();
}

QSize HtmlDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QStyleOptionViewItemV4 optionV4 = option;
	initStyleOption(&optionV4, index);

	QTextDocument doc;
	doc.setHtml(optionV4.text);
	doc.setTextWidth(optionV4.rect.width());
	return QSize(doc.idealWidth(), doc.size().height());
}

void Dialog::on_btn_info_clicked()
{
    QFile file(":/license/license2.txt");
	file.open(QFile::ReadOnly);
	QString license = file.readAll();
	QMessageBox::information(this, "Information", license);
}

void Dialog::on_showTimestampCheckBox_toggled(bool checked)
{
	settings->setValue("timestamp", checked);
}

void Dialog::on_pvtNotificationsCheckBox_toggled(bool checked)
{
	settings->setValue("notification", checked);
}

void Dialog::on_textBrowser_cursorPositionChanged()
{
    QTextCursor tc = ui->textBrowser->textCursor();
    tc.select(QTextCursor::WordUnderCursor);
	int end = tc.selectionEnd();
	tc.setPosition(tc.selectionStart());
	tc.setPosition(end + 1, QTextCursor::KeepAnchor);
    QString word = tc.selectedText();

	if (word.endsWith(">"))
	{
		QString name = word.left(word.length() - 1);
		QStringList lst = usersMatchList(name);
		if (lst.size())
		{
			username = name;
			if (!username.isEmpty())
			{
				ui->lineEdit->setText(QString("!pvt: %1> ").arg(username));
				ui->lineEdit->setFocus();
			}
		}
	}
}

void Dialog::on_maxLinesSpinBox_valueChanged(int arg1)
{
    settings->setValue("maxlines", arg1);
}
