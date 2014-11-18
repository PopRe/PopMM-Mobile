package net.popre.popmmmobile.notification;

import net.popre.popmmmobile.R;
import android.os.Bundle;
import android.media.RingtoneManager;
import android.net.Uri;
import android.app.Notification;
import android.app.NotificationManager;
import android.content.Context;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;

public class NotificationBar extends org.qtproject.qt5.android.bindings.QtActivity
{
    private static NotificationManager notificationManager;
    private static Notification.Builder m_notification;
    private static NotificationBar m_instance;
    private static Intent intent;
    private static boolean m_paused = false;

    public void onCreate(Bundle InstanceState)
    {
        super.onCreate(InstanceState);
        NotificationManager myManager = (NotificationManager)getSystemService(NOTIFICATION_SERVICE);
        myManager.cancelAll();
    }

    @Override
    public void onPause()
    {
        super.onPause();
        m_instance.m_paused = true;
    }

    @Override
    public void onResume()
    {
        super.onResume();
        m_instance.m_paused = false;
    }

    public NotificationBar()
    {
        m_instance = this;
    }

    public static boolean isPaused()
    {
        return m_instance.m_paused;
    }


    public static void setNotification(int id, String title, String message)
    {
        if(m_paused == false) return;
		if (notificationManager == null)
		{
			Uri soundUri = RingtoneManager.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION);
                        intent = new Intent(m_instance, NotificationBar.class);
                        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
			PendingIntent pIntent = PendingIntent.getActivity(m_instance, 0, intent, 0);			
			notificationManager = (NotificationManager) (NotificationManager)m_instance.getSystemService(NOTIFICATION_SERVICE);

			m_notification = new Notification.Builder(m_instance)
				.setContentTitle(title)
				.setSmallIcon(R.drawable.notify)
				.setContentIntent(pIntent)
				.setSound(soundUri)
                                .setAutoCancel(true);

		}
		
		m_notification.setContentText(message);
                Notification nt = m_notification.build();
                nt.flags |= Notification.FLAG_AUTO_CANCEL;
                notificationManager.notify(id, m_notification.build());
    }
	
	public static void cancelNotification(int notificationId)
	{
		if (notificationManager != null)
		{
			notificationManager.cancel(notificationId);
		}
        }
}
