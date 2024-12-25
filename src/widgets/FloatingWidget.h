#ifndef FLOATINGWIDGET_H
#define FLOATINGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QScreen>
#include <QApplication>
#include <QMainWindow>

#include "FloatingSettings.h"

class QLabel;

class FloatingWidget : public QWidget {
public:
    int cur_height = -1;
    int cur_width = -1;
    FloatingWidget(QWidget *parent = nullptr);
    void addWidget(QString name, QWidget *widget);
    void setSettings(QWidget *widget);
    void setMainWindow(QWidget *widget);
    void moveAction();
    bool is_vertical;
    void setVertical(bool state);
    QMainWindow *mainWindow;
protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
private:
    int num_of_item = 0;
    int offset_x = -1;
    int offset_y = -1;
    FloatingSettings* floatingSettings;
    QPoint dragPosition;
    QBoxLayout *layout;
    QMap<QString, QWidget*> widgets;
};

#endif // FLOATINGWIDGET_H
