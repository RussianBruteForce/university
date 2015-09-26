#ifndef MT_H
#define MT_H

#include <QWidget>
#include "mtmodel.h"

namespace Ui {
class MT;
}

class MT : public QWidget
{
	Q_OBJECT

public:
	explicit MT(QWidget *parent = 0);
	~MT();

private:
	Ui::MT *ui;
	MTModel *model;

private slots:
	void changeBase(int b);
	void changeRange();
};

#endif // MT_H
