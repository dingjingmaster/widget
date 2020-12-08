#include "connect-server-dialog.h"

#include <QIcon>
#include <QLabel>
#include <QLineEdit>

ConnectServerDialog::ConnectServerDialog(QWidget *parent) : QWidget(parent)
{
    setFixedSize(m_widget_size);
    setWindowIcon(QIcon::fromTheme("network-server"));
    setWindowTitle(tr("connect to server"));
    m_main_layout = new QVBoxLayout(this);

    m_remote_type_edit      = new QComboBox();
    m_remote_type_label     = new QLabel(this);
    m_remote_layout         = new QHBoxLayout();
    m_remote_type_label->setText(tr("type"));

    m_remote_layout->addWidget(m_remote_type_label);
    m_remote_layout->addWidget(m_remote_type_edit);
    m_main_layout->addLayout(m_remote_layout);

    m_ip_label              = new QLabel;
    m_ip_edit               = new QLineEdit;
    m_port_label            = new QLabel;
    m_port_editor           = new QComboBox;
    m_ip_port_layout        = new QHBoxLayout;
    m_ip_label->setText(tr("service ip"));
    m_port_label->setText(tr("service port"));

    m_ip_port_layout->addWidget(m_ip_label);
    m_ip_port_layout->addWidget(m_ip_edit);
    m_ip_port_layout->addWidget(m_port_label);
    m_ip_port_layout->addWidget(m_port_editor);
    m_main_layout->addLayout(m_ip_port_layout);

    m_favorite_label        = new QLabel;
    m_favorite_layout       = new QVBoxLayout;
    m_favorite_label->setText(tr("Personal Collection server:"));

    m_favorite_layout->addWidget(m_favorite_label);
    m_main_layout->addLayout(m_favorite_layout);

    m_btn_add               = new QPushButton;
    m_btn_del               = new QPushButton;
    m_btn_conn              = new QPushButton;
    m_btn_layout            = new QHBoxLayout;

    m_btn_add->setText(tr("add"));
    m_btn_del->setText(tr("delete"));
    m_btn_conn->setText(tr("connect"));
    m_btn_layout->addWidget(m_btn_add);
    m_btn_layout->addWidget(m_btn_del);
    m_btn_layout->addWidget(m_btn_conn);
    m_main_layout->addLayout(m_btn_layout);

    setLayout(m_main_layout);
}

ConnectServerDialog::~ConnectServerDialog()
{
    delete m_remote_type_label;
    delete m_main_layout;
}
