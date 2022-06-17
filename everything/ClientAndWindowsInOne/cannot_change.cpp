#include "cannot_change.h"
#include "ui_cannot_change.h"
/**
 * @brief cannot_change::cannot_change конструктор, открытие формы предупреждения
 * @param parent
 */
cannot_change::cannot_change(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cannot_change)
{
    ui->setupUi(this);
}
/**
 * @brief cannot_change::~cannot_change деструктор, закрытие формы
 */
cannot_change::~cannot_change()
{
    delete ui;
}
