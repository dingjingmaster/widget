#ifndef CONNECTSERVERDIALOG_H
#define CONNECTSERVERDIALOG_H

#include <QWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QRadioButton>

class QLabel;

class ConnectServerDialog : public QWidget
{
    Q_OBJECT
public:
    explicit ConnectServerDialog(QWidget *parent = nullptr);
    ~ConnectServerDialog();

signals:

private:
    float           m_widget_margin         = 24;
    QSize           m_widget_size           = QSize (424, 440);
    QVBoxLayout*    m_main_layout           = nullptr;

    QPoint          m_remote_type_pos       = QPoint (24, 70);
    QSize           m_remote_type_size      = QSize (28, 24);
    QLabel*         m_remote_type_label     = nullptr;
    QComboBox*      m_remote_type_edit      = nullptr;
    QLabel*         m_ip_label              = nullptr;
    QLineEdit*      m_ip_edit               = nullptr;
    QLabel*         m_port_label            = nullptr;
    QComboBox*      m_port_editor           = nullptr;
    QGridLayout*    m_remote_layout         = nullptr;

    QSize           m_favorite_list_size    = QSize (376, 144);
    QLabel*         m_favorite_label        = nullptr;
    QListWidget*    m_favorite_list         = nullptr;
    QVBoxLayout*    m_favorite_layout       = nullptr;

    QPushButton*    m_btn_add               = nullptr;
    QPushButton*    m_btn_del               = nullptr;
    QPushButton*    m_btn_conn              = nullptr;
    QHBoxLayout*    m_btn_layout            = nullptr;


};

class ConnectServerLogin : public QWidget
{
    Q_OBJECT
public:
    explicit ConnectServerLogin(QString& remoteIP, QWidget* parent = nullptr);
    ~ConnectServerLogin();

private:
    float           m_widget_margin         = 24;
    QSize           m_widget_size           = QSize (424, 394);
    QSize           m_widget_size_little    = QSize (424, 250);
    QVBoxLayout*    m_main_layout           = nullptr;

    QLabel*         m_tip                   = nullptr;

    QLabel*         m_usr_label             = nullptr;
    QVBoxLayout*    m_usr_btn_group         = nullptr;
    QRadioButton*   m_usr_btn_guest         = nullptr;
    QRadioButton*   m_usr_btn_usr           = nullptr;
    QHBoxLayout*    m_usr_layout            = nullptr;

    QLabel*         m_reg_usr_name_label    = nullptr;
    QLabel*         m_reg_usr_passwd_label  = nullptr;
    QLineEdit*      m_reg_usr_name_editor   = nullptr;
    QLineEdit*      m_reg_usr_passwd_editor = nullptr;
    QCheckBox*      m_reg_usr_combox        = nullptr;
    QGridLayout*    m_reg_usr_layout        = nullptr;

    QPushButton*    m_btn_cancel            = nullptr;
    QPushButton*    m_btn_ok                = nullptr;
    QHBoxLayout*    m_btn_layout            = nullptr;
};
#endif // CONNECTSERVERDIALOG_H
