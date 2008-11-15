#ifndef CHATTYITEMDELEGATE_H
#define CHATTYITEMDELEGATE_H

#include <QItemDelegate>

/**
 * Delegate for the tasks view
 * FIXME: rename
 */
class ChattyItemDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    explicit ChattyItemDelegate( QObject* parent = 0 );

    // painting
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const;

    // reimpl
    QWidget* createEditor( QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index ) const;

    bool isEditing() const;

signals:
    void editingStateChanged() const;

private slots:
    void slotCloseEditor( QWidget* editor, QAbstractItemDelegate::EndEditHint );

private:
    int firstLineHeight(const QStyleOptionViewItem& option) const;
    mutable bool m_editing;
};
#endif
