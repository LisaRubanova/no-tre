#ifndef NOT_ALLOWED_H
#define NOT_ALLOWED_H

#include <QWidget>

namespace Ui {
class not_allowed;
}

class not_allowed : public QWidget
{
    Q_OBJECT

public:
    explicit not_allowed(QWidget *parent = nullptr);
    ~not_allowed();

private:
    Ui::not_allowed *ui;
};

#endif // NOT_ALLOWED_H
