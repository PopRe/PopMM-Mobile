/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *statuslabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_connect;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_players;
    QPushButton *btn_settings;
    QPushButton *btn_info;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *textBrowser;
    QListView *usersList;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QLabel *showTimestampLabel;
    QCheckBox *showTimestampCheckBox;
    QLabel *pvtNotificationsLabel;
    QCheckBox *pvtNotificationsCheckBox;
    QLabel *maxLinesLabel;
    QSpinBox *maxLinesSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QPushButton *btn_send;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(936, 582);
        Dialog->setStyleSheet(QLatin1String("QCheckBox::indicator {\n"
"     width: 80px;\n"
"     height: 40px;\n"
" }\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	image: url(:/icons/icons/checkon.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/icons/icons/checkoff.png);\n"
" }"));
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        statuslabel = new QLabel(Dialog);
        statuslabel->setObjectName(QStringLiteral("statuslabel"));

        horizontalLayout_4->addWidget(statuslabel);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_connect = new QPushButton(Dialog);
        btn_connect->setObjectName(QStringLiteral("btn_connect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/1412808682_globe-01-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_connect->setIcon(icon);
        btn_connect->setIconSize(QSize(54, 54));
        btn_connect->setAutoDefault(true);
        btn_connect->setFlat(false);

        horizontalLayout->addWidget(btn_connect);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_players = new QPushButton(Dialog);
        btn_players->setObjectName(QStringLiteral("btn_players"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/1412808690_user-01-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_players->setIcon(icon1);
        btn_players->setIconSize(QSize(54, 54));
        btn_players->setCheckable(true);
        btn_players->setChecked(true);
        btn_players->setAutoDefault(true);

        horizontalLayout->addWidget(btn_players);

        btn_settings = new QPushButton(Dialog);
        btn_settings->setObjectName(QStringLiteral("btn_settings"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/1412808704_gear-01-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_settings->setIcon(icon2);
        btn_settings->setIconSize(QSize(54, 54));
        btn_settings->setCheckable(true);
        btn_settings->setAutoDefault(true);
        btn_settings->setFlat(false);

        horizontalLayout->addWidget(btn_settings);

        btn_info = new QPushButton(Dialog);
        btn_info->setObjectName(QStringLiteral("btn_info"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_info->setIcon(icon3);
        btn_info->setIconSize(QSize(54, 54));

        horizontalLayout->addWidget(btn_info);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textBrowser = new QTextBrowser(Dialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setAutoFillBackground(false);
        textBrowser->setOpenExternalLinks(true);

        horizontalLayout_2->addWidget(textBrowser);

        usersList = new QListView(Dialog);
        usersList->setObjectName(QStringLiteral("usersList"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(usersList->sizePolicy().hasHeightForWidth());
        usersList->setSizePolicy(sizePolicy1);
        usersList->setMinimumSize(QSize(150, 0));

        horizontalLayout_2->addWidget(usersList);

        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(4);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(200, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        usernameLabel = new QLabel(groupBox);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, usernameLabel);

        usernameLineEdit = new QLineEdit(groupBox);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameLineEdit);

        passwordLabel = new QLabel(groupBox);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(groupBox);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordLineEdit);

        showTimestampLabel = new QLabel(groupBox);
        showTimestampLabel->setObjectName(QStringLiteral("showTimestampLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, showTimestampLabel);

        showTimestampCheckBox = new QCheckBox(groupBox);
        showTimestampCheckBox->setObjectName(QStringLiteral("showTimestampCheckBox"));
        showTimestampCheckBox->setChecked(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, showTimestampCheckBox);

        pvtNotificationsLabel = new QLabel(groupBox);
        pvtNotificationsLabel->setObjectName(QStringLiteral("pvtNotificationsLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, pvtNotificationsLabel);

        pvtNotificationsCheckBox = new QCheckBox(groupBox);
        pvtNotificationsCheckBox->setObjectName(QStringLiteral("pvtNotificationsCheckBox"));
        pvtNotificationsCheckBox->setMinimumSize(QSize(0, 0));
        pvtNotificationsCheckBox->setIconSize(QSize(16, 16));
        pvtNotificationsCheckBox->setChecked(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, pvtNotificationsCheckBox);

        maxLinesLabel = new QLabel(groupBox);
        maxLinesLabel->setObjectName(QStringLiteral("maxLinesLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, maxLinesLabel);

        maxLinesSpinBox = new QSpinBox(groupBox);
        maxLinesSpinBox->setObjectName(QStringLiteral("maxLinesSpinBox"));
        maxLinesSpinBox->setMaximum(9999);
        maxLinesSpinBox->setValue(300);

        formLayout->setWidget(2, QFormLayout::FieldRole, maxLinesSpinBox);


        verticalLayout_2->addLayout(formLayout);


        horizontalLayout_2->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setClearButtonEnabled(false);

        horizontalLayout_3->addWidget(lineEdit);

        btn_send = new QPushButton(Dialog);
        btn_send->setObjectName(QStringLiteral("btn_send"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icons/1412808698_arrow-right-01-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_send->setIcon(icon4);
        btn_send->setIconSize(QSize(32, 32));
        btn_send->setDefault(true);

        horizontalLayout_3->addWidget(btn_send);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "POPMM Mobile Client", 0));
        statuslabel->setText(QApplication::translate("Dialog", "Status : Disconnected", 0));
        btn_connect->setText(QApplication::translate("Dialog", "Connect", 0));
#ifndef QT_NO_TOOLTIP
        btn_players->setToolTip(QApplication::translate("Dialog", "Show players", 0));
#endif // QT_NO_TOOLTIP
        btn_players->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_settings->setToolTip(QApplication::translate("Dialog", "Settings", 0));
#endif // QT_NO_TOOLTIP
        btn_settings->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_info->setToolTip(QApplication::translate("Dialog", "Info", 0));
#endif // QT_NO_TOOLTIP
        btn_info->setText(QString());
        groupBox->setTitle(QApplication::translate("Dialog", "Settings : ", 0));
        usernameLabel->setText(QApplication::translate("Dialog", "Username : ", 0));
        passwordLabel->setText(QApplication::translate("Dialog", "Password : ", 0));
        showTimestampLabel->setText(QApplication::translate("Dialog", "Show timestamp : ", 0));
        pvtNotificationsLabel->setText(QApplication::translate("Dialog", "Pvt notifications : ", 0));
        maxLinesLabel->setText(QApplication::translate("Dialog", "Max lines : ", 0));
        btn_send->setText(QApplication::translate("Dialog", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
