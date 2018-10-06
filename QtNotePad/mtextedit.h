#ifndef MTEXTEDIT_H
#define MTEXTEDIT_H


#include <QTextEdit>
#include <QMimeData>
#include <QImage>


class mtextedit: public QTextEdit {
    Q_OBJECT
  public:
    mtextedit(QWidget *parent);

    void        dropImage(const QImage& image, const QString& format);

  protected:
    bool        canInsertFromMimeData(const QMimeData *source) const;
    void        insertFromMimeData(const QMimeData *source);
    QMimeData  *createMimeDataFromSelection() const;

};

#endif
