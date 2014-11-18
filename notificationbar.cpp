#include "notificationbar.h"

NotificationBar::NotificationBar(QObject *parent) : QObject(parent)
{
}

void NotificationBar::setNotification(QString title, QString message, int id)
{
#ifdef __ANDROID__
    jint javaId = id;
    QAndroidJniObject javaTitle = QAndroidJniObject::fromString(title);
    QAndroidJniObject javaMessage = QAndroidJniObject::fromString(message);
    QAndroidJniObject::callStaticMethod<void>("net/popre/popmmmobile/notification/NotificationBar", "setNotification", "(ILjava/lang/String;Ljava/lang/String;)V", javaId, javaTitle.object<jstring>(), javaMessage.object<jstring>());
#endif
}

void NotificationBar::cancelNotification(int id)
{
#ifdef __ANDROID__
    jint javaId = id;
    QAndroidJniObject::callStaticMethod<void>("net/popre/popmmmobile/notification/NotificationBar", "cancelNotification", "(I)V", javaId);
#endif
}
