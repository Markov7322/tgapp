#pragma once
#include <QThread>
#include <QStringList>
#include <QVariantList>

class CollectContactsWorker : public QThread {
    Q_OBJECT
public:
    explicit CollectContactsWorker(const QStringList &posts, QObject *parent = nullptr);
    QVariantList data() const { return m_data; }
signals:
    void progress(int done, int total);
    void finished();
    void error(const QString &msg);
protected:
    void run() override;
private:
    QStringList m_posts;
    QVariantList m_data;
};
