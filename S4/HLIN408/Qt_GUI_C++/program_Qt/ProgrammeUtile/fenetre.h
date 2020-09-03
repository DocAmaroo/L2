#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>
#include <QTimer>
#include <QProgressBar>
#include <QPushButton>

class Fenetre : public QWidget
{
    Q_OBJECT
public:
    explicit Fenetre(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);
    void closeEvent(QCloseEvent*);

signals:

public slots:
    void timeout();
    void buttonPushed();
    void antispam();

private:
    QTimer* timer;
    QProgressBar* bar;
    QPushButton* quitter, *appuyer;
};

#endif // FENETRE_H
