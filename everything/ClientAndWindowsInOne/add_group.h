#ifndef ADD_GROUP_H
#define ADD_GROUP_H
#include "back_func.h"
#include "cannot_change.h"
#include <QWidget>
#include <QRegularExpression>
#include <QMap>
#include <QRegularExpressionMatch>

namespace Ui {
class add_group;
}

class add_group : public QWidget
{
    Q_OBJECT

public:
    explicit add_group(QWidget *parent = nullptr);
    ~add_group();
    void clean();

private slots:
    void on_pushButton_clicked();
    void no_changes();

private:
    Ui::add_group *ui;
    cannot_change * changes;
};

#endif // ADD_GROUP_H
