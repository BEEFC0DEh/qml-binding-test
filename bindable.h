#ifndef BINDABLE_H
#define BINDABLE_H

#include <QObject>

class Bindable : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int value READ value NOTIFY valueChanged)
    int m_value;
    int m_ticks;

public:
    explicit Bindable(QObject *parent = nullptr, int value = 0);
    int value() const;

signals:
    void valueChanged(int value);

    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
};

class BindableHelper : public QObject
{
    Q_OBJECT

public:
    explicit BindableHelper(QObject *parent = nullptr);

    Q_INVOKABLE Bindable* bind(int value);
};

#endif // BINDABLE_H
