#ifndef NOTIFICATIONBAR_H
#define NOTIFICATIONBAR_H

#include <QObject>
#include <QString>
#ifdef __ANDROID__
#include <QtAndroidExtras/QAndroidJniObject>
#endif

class NotificationBar : public QObject
{
    Q_OBJECT
public:
    explicit NotificationBar(QObject *parent = 0);

signals:

public slots :
	void setNotification(QString title, QString message, int id = 1);
	void cancelNotification(int id = 1);

};

#endif // NOTIFICATIONBAR_H
