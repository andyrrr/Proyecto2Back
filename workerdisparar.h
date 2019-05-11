#ifndef WORKERDISPARAR_H
#define WORKERDISPARAR_H

#include <QThread>
#include <QObject>

class WorkerDisparar : public QThread
{
    Q_OBJECT
public:
    explicit WorkerDisparar(QObject *parent=0);
    void terminar(bool cambio);
    bool end;
signals:
    void progreso();
protected:
    void run() override;
};

#endif // WORKERDISPARAR_H
