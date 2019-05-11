#ifndef WORKERCAMINAR_H
#define WORKERCAMINAR_H


#include <QThread>
#include <QObject>

class WorkerCaminar : public QThread
{
    Q_OBJECT
public:
    explicit WorkerCaminar(QObject *parent=0);
    void terminar(bool cambio);
    bool end;
signals:
    void progreso();
protected:
    void run() override;
};

#endif // WORKERCAMINAR_H
