#include "connect-server-dialog.h"

#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QSpacerItem>
#include <QButtonGroup>
#include <QSizePolicy>

ConnectServerDialog::ConnectServerDialog(QWidget *parent) : QWidget(parent)
{
    setFixedSize(m_widget_size);
    setWindowIcon(QIcon::fromTheme("network-server"));
    setWindowTitle(tr("connect to server"));
    m_main_layout = new QVBoxLayout(this);

    m_remote_type_edit      = new QComboBox;
    m_remote_type_label     = new QLabel;
    m_ip_label              = new QLabel;
    m_port_label            = new QLabel;
    m_ip_edit               = new QLineEdit;
    m_port_editor           = new QComboBox;
    m_remote_layout         = new QGridLayout;

    m_main_layout->addSpacing(12);

    m_ip_label->setText(tr("ip"));
    m_port_label->setText(tr("port"));
    m_remote_type_label->setText(tr("type"));
    m_main_layout->setMargin(m_widget_margin);
    m_port_label->setMargin(6);
    m_remote_type_edit->setAutoCompletion(true);
    m_ip_label->setFixedHeight(36);
    m_ip_edit->setFixedHeight(36);
    m_port_label->setFixedHeight(36);
    m_port_editor->setFixedHeight(36);
    m_remote_type_label->setFixedHeight(36);
    m_remote_type_edit->setFixedHeight(36);
    m_remote_type_edit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    m_remote_layout->addWidget(m_remote_type_label, 0, 0, 1, 1);
    m_remote_layout->addWidget(m_remote_type_edit,  0, 1, 1, 3);
    m_remote_layout->setVerticalSpacing(20);
    m_remote_layout->addWidget(m_ip_label,          1, 0, 1, 1);
    m_remote_layout->addWidget(m_ip_edit,           1, 1, 1, 1);
    m_remote_layout->addWidget(m_port_label,        1, 2, 1, 1);
    m_remote_layout->addWidget(m_port_editor,       1, 3, 1, 1);

    m_main_layout->addLayout(m_remote_layout);
    m_main_layout->addSpacing(28);

    m_favorite_label        = new QLabel;
    m_favorite_layout       = new QVBoxLayout;
    m_favorite_list         = new QListWidget;
    m_favorite_list->setFixedSize(m_favorite_list_size);
    m_favorite_label->setText(tr("Personal Collection server:"));

    m_favorite_layout->addWidget(m_favorite_label);
    m_favorite_layout->addWidget(m_favorite_list);
    m_main_layout->addLayout(m_favorite_layout);

    m_btn_add               = new QPushButton;
    m_btn_del               = new QPushButton;
    m_btn_conn              = new QPushButton;
    m_btn_layout            = new QHBoxLayout;

    m_main_layout->addSpacing(12);

    m_btn_add->setText(tr("add"));
    m_btn_del->setText(tr("delete"));
    m_btn_conn->setText(tr("connect"));
    m_btn_layout->addWidget(m_btn_add);
    m_btn_layout->addWidget(m_btn_del);
    m_btn_layout->addSpacing(72);
    m_btn_layout->addWidget(m_btn_conn);
    m_main_layout->addLayout(m_btn_layout);

    setLayout(m_main_layout);
}

ConnectServerDialog::~ConnectServerDialog()
{
    delete m_remote_type_label;
    delete m_main_layout;
}



ConnectServerLogin::ConnectServerLogin(QString& remoteIP, QWidget *parent) : QWidget(parent)
{
    setFixedSize(m_widget_size_little);
    setWindowIcon(QIcon::fromTheme("network-server"));
    setWindowTitle(tr("The login user"));
    m_main_layout = new QVBoxLayout(this);
    m_main_layout->addSpacing(12);
    m_main_layout->setMargin(m_widget_margin);

    m_tip                   = new QLabel;
    m_tip->setWordWrap(true);
    m_tip->setText(QString("Please enter the %1's user name and password of the server.").arg(remoteIP));
    m_main_layout->addWidget(m_tip);

    m_usr_label             = new QLabel;
    m_usr_btn_group         = new QVBoxLayout;
    m_usr_btn_guest         = new QRadioButton;
    m_usr_btn_usr           = new QRadioButton;
    m_usr_layout            = new QHBoxLayout;

    m_usr_label->setText(tr("User's identity"));
    m_usr_btn_guest->setText(tr("guest"));
    m_usr_btn_usr->setText(tr("Registered users"));
    m_usr_btn_group->addWidget(m_usr_btn_guest);
    m_usr_btn_group->addWidget(m_usr_btn_usr);
    m_usr_layout->addWidget(m_usr_label);
    m_usr_layout->addLayout(m_usr_btn_group);
    m_usr_label->setAlignment (Qt::AlignTop | Qt::AlignLeft);
    m_usr_layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    m_main_layout->addLayout(m_usr_layout);

    m_reg_usr_name_label    = new QLabel;
    m_reg_usr_passwd_label  = new QLabel;
    m_reg_usr_name_editor   = new QLineEdit;
    m_reg_usr_passwd_editor = new QLineEdit;
    m_reg_usr_combox        = new QCheckBox;
    m_reg_usr_layout        = new QGridLayout;

    m_reg_usr_name_label->setText(tr("name"));
    m_reg_usr_passwd_label->setText(tr("password"));
    m_reg_usr_combox->setText(tr("Remember the password"));
    m_reg_usr_name_label->setFixedHeight(36);
    m_reg_usr_passwd_label->setFixedHeight(36);
    m_reg_usr_name_editor->setFixedHeight(36);
    m_reg_usr_passwd_editor->setFixedHeight(36);
    m_reg_usr_combox->setFixedHeight(36);
    m_reg_usr_layout->addWidget(m_reg_usr_name_label,       0, 0);
    m_reg_usr_layout->addWidget(m_reg_usr_name_editor,      0, 1);
    m_reg_usr_layout->addWidget(m_reg_usr_passwd_label,     1, 0);
    m_reg_usr_layout->addWidget(m_reg_usr_passwd_editor,    1, 1);
    m_reg_usr_layout->addWidget(m_reg_usr_combox,           2, 1);
    m_reg_usr_layout->setVerticalSpacing(20);
    m_main_layout->addLayout(m_reg_usr_layout);

    m_btn_cancel            = new QPushButton;
    m_btn_ok                = new QPushButton;
    m_btn_layout            = new QHBoxLayout;
    m_btn_layout->addSpacing(192);
    m_btn_cancel->setText(tr("cancel"));
    m_btn_ok->setText(tr("ok"));
    m_btn_layout->addWidget(m_btn_cancel);
    m_btn_layout->addWidget(m_btn_ok);
    m_main_layout->addLayout(m_btn_layout);

    setLayout(m_main_layout);

    m_usr_btn_guest->setChecked(true);
    m_reg_usr_combox->setHidden(true);
    m_reg_usr_name_label->setHidden(true);
    m_reg_usr_name_editor->setHidden(true);
    m_reg_usr_passwd_label->setHidden(true);
    m_reg_usr_passwd_editor->setHidden(true);

    connect(m_usr_btn_guest, &QRadioButton::clicked, [=] () {
        setFixedSize(m_widget_size_little);
        m_reg_usr_combox->setHidden(true);
        m_reg_usr_name_label->setHidden(true);
        m_reg_usr_name_editor->setHidden(true);
        m_reg_usr_passwd_label->setHidden(true);
        m_reg_usr_passwd_editor->setHidden(true);
    });

    connect(m_usr_btn_usr, &QRadioButton::clicked, [=] () {
        setFixedSize(m_widget_size);
        m_reg_usr_combox->setHidden(false);
        m_reg_usr_name_label->setHidden(false);
        m_reg_usr_name_editor->setHidden(false);
        m_reg_usr_passwd_label->setHidden(false);
        m_reg_usr_passwd_editor->setHidden(false);
    });

    connect(m_btn_cancel, &QPushButton::clicked, [=] () {
        close();
    });
}

ConnectServerLogin::~ConnectServerLogin()
{

}
