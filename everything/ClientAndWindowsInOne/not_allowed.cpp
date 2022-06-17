#include "not_allowed.h"
#include "ui_not_allowed.h"
/**
 * @brief not_allowed::not_allowed конструктор, создание формы
 * @param parent
 */
not_allowed::not_allowed(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::not_allowed)
{
    ui->setupUi(this);
}
/**
 * @brief not_allowed::~not_allowed деструктор, закрытие формы
 */
not_allowed::~not_allowed()
{
    delete ui;
}
