#pragma once
#include <QThread>
#include <QStringList>

class CollectPostsWorker : public QThread {
    Q_OBJECT
public:
    explicit CollectPostsWorker(const QString &channelUrl, QObject *parent = nullptr);
    QStringList posts() const { return m_posts; }
signals:
    void progress(int done, int total);
    void finished();
    void error(const QString &msg);
protected:
    void run() override;
private:
    QString m_url;
    QStringList m_posts;
};
