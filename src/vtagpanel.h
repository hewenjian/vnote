#ifndef VTAGPANEL_H
#define VTAGPANEL_H

#include <QWidget>
#include "vnavigationmode.h"

#include <QVector>

class VTagLabel;
class VButtonWithWidget;
class VNoteFile;
class VAllTagsPanel;
class VLineEdit;
class QStringListModel;
class VNotebook;

/*! \brief Implementation to show a tag bar. */
class VTagPanel : public QWidget, public VNavigationMode
{
    Q_OBJECT
public:
    explicit VTagPanel(QWidget *parent = nullptr);

    void updateTags(VNoteFile *p_file);

    // Implementations for VNavigationMode.
    void showNavigation() Q_DECL_OVERRIDE;
    bool handleKeyNavigation(int p_key, bool &p_succeed) Q_DECL_OVERRIDE;

protected:
    bool eventFilter(QObject *p_obj, QEvent *p_event) Q_DECL_OVERRIDE;

private slots:
    void updateAllTagsPanel();

    void removeTag(const QString &p_text);

private:
    void setupUI();

    void clearLabels();

    void updateTags();

    bool addTag(const QString &p_text);

    void updateCompleter(const VNoteFile *p_file);

    void updateCompleter();

    bool isAllTagsPanelAvailable() const;

    QVector<VTagLabel *> m_labels;              /*! Container for the tags to show */

    VButtonWithWidget *m_btn;                   /*! Button to show the rest of tags. */

    VAllTagsPanel *m_tagsPanel;                 /*! Component to show the tag bar. */

    VLineEdit *m_tagEdit;                       /*! LineEdit to add a tag. */

    // Used for auto completion.
    QStringListModel *m_tagsModel;              /*! Provide a model that supplies tags to views. */

    VNoteFile *m_file;                          /*! Pointer to the VNoteFile in use. */

    const VNotebook *m_notebookOfCompleter;     /*! Completer of tags depending on notebook. */
};
#endif // VTAGPANEL_H
