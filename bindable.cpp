#include "bindable.h"
#include <QDebug>

Bindable::Bindable(QObject *parent, int value)
    : QObject(parent),
      m_value(value),
      m_ticks(0)
{
    startTimer(200);
}

int Bindable::value() const
{
    return  m_value * m_ticks;
}


void Bindable::timerEvent(QTimerEvent *event)
{
    m_ticks++;
    qDebug() << "lol" << value() << this;
    emit valueChanged( value() );
}

BindableHelper::BindableHelper(QObject *parent)
    : QObject(parent)
{ }

Bindable* BindableHelper::bind(int value)
{
    return new Bindable{this, value}; // No lifetime control. Memory leak.
}
