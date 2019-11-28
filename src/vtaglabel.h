#ifndef VTAGLABEL_H
#define VTAGLABEL_H

#include <QWidget>

class QLabel;
class QPushButton;

/*! \brief Implementation to the tag label of file. */
class VTagLabel : public QWidget
{
    Q_OBJECT
public:
    explicit VTagLabel(const QString &p_text,
                       bool p_useFullText,
                       QWidget *p_parent = nullptr);

    explicit VTagLabel(QWidget *p_parent = nullptr);

    void clear();

    void setText(const QString &p_text);

    const QString &text() const;

signals:
    void removalRequested(const QString &p_text);

protected:
    virtual bool event(QEvent *p_event) Q_DECL_OVERRIDE;

private:
    void setupUI();

    void updateLabel();

    QString m_text;                 /*!< Tips to the tag label. */

    bool m_useFullText;             /*!< Flag to show the full filename. */

    QLabel *m_label;                /*!< Display the opened filename. */
    QPushButton *m_closeBtn;        /*!< Display the close button. */
};

/*! \brief Return the tips of tag label
*/
inline const QString &VTagLabel::text() const
{
    return m_text;
}

#endif // VTAGLABEL_H
