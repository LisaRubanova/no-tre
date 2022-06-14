#ifndef CANNOT_CHANGE_H
#define CANNOT_CHANGE_H

#include <QWidget>

namespace Ui {
class cannot_change;
}

class cannot_change : public QWidget
{
    Q_OBJECT

public:
    explicit cannot_change(QWidget *parent = nullptr);
    ~cannot_change();

private:
    Ui::cannot_change *ui;
};

#endif // CANNOT_CHANGE_H
