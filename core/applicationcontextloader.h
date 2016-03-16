#ifndef APPLICATIONCONTEXTLOADER_H
#define APPLICATIONCONTEXTLOADER_H

#include <QObject>
#include <QSettings>
#include "nodecontainer.h"

class ApplicationContextLoader : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationContextLoader(QObject *parent = 0);

    void loadApplicationContext(const QString &config_path);
    void loadTestContext();

    void setNodeContainer(NodeContainer *node_container);

signals:

public slots:

private:
    NodeContainer *node_container_;
    QSettings *user_settings_;

    void assertNodeContainerExists();
};

#endif // APPLICATIONCONTEXTLOADER_H
