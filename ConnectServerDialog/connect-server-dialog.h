#ifndef CONNECTSERVERDIALOG_H
#define CONNECTSERVERDIALOG_H

#include <QWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

class QLabel;

class ConnectServerDialog : public QWidget
{
    Q_OBJECT
public:
    explicit ConnectServerDialog(QWidget *parent = nullptr);
    ~ConnectServerDialog();

signals:

private:
    QSize           m_widget_size           = QSize (424, 440);
    QVBoxLayout*    m_main_layout           = nullptr;

    QPoint          m_remote_type_pos       = QPoint (24, 70);
    QSize           m_remote_type_size      = QSize (28, 24);
    QLabel*         m_remote_type_label     = nullptr;
    QComboBox*      m_remote_type_edit      = nullptr;
    QHBoxLayout*    m_remote_layout         = nullptr;

    QLabel*         m_ip_label              = nullptr;
    QLineEdit*      m_ip_edit               = nullptr;
    QLabel*         m_port_label            = nullptr;
    QComboBox*      m_port_editor           = nullptr;
    QHBoxLayout*    m_ip_port_layout        = nullptr;

    QLabel*         m_favorite_label        = nullptr;
    QVBoxLayout*    m_favorite_layout       = nullptr;

    QPushButton*    m_btn_add               = nullptr;
    QPushButton*    m_btn_del               = nullptr;
    QPushButton*    m_btn_conn              = nullptr;
    QHBoxLayout*    m_btn_layout            = nullptr;


};

#endif // CONNECTSERVERDIALOG_H
