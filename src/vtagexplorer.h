/*!
\copyright  VNote is developed and maintained by Le Tan.\n
            VNote is licensed under the MIT license.
\version    Part of 2.7.2
\file       Vtagexplorer.h
\brief      Header file for Tag Explorer
*/

#ifndef VTAGEXPLORER_H
#define VTAGEXPLORER_H

#include <QWidget>
#include <QIcon>

#include "vsearchconfig.h"

class QLabel;
class VListWidget;
class QListWidgetItem;
class QSplitter;
class VNotebook;
class VSearch;

/*! \brief Implementation to the tags explorer. */
class VTagExplorer : public QWidget
{
    Q_OBJECT
public:
    explicit VTagExplorer(QWidget *p_parent = nullptr);

    void clear();

    void setNotebook(VNotebook *p_notebook);

    void saveStateAndGeometry();

    void registerNavigationTarget();

protected:
    void showEvent(QShowEvent *p_event) Q_DECL_OVERRIDE;

    void focusInEvent(QFocusEvent *p_event) Q_DECL_OVERRIDE;

private slots:
    void handleSearchItemAdded(const QSharedPointer<VSearchResultItem> &p_item);

    void handleSearchItemsAdded(const QList<QSharedPointer<VSearchResultItem> > &p_items);

    void handleSearchFinished(const QSharedPointer<VSearchResult> &p_result);

    void openFileItem(QListWidgetItem *p_item) const;

    void openSelectedFileItems() const;

    void locateCurrentFileItem() const;

    void addFileToCart() const;

    void pinFileToHistory() const;

    void handleFileListContextMenuRequested(QPoint p_pos);

private:
    void setupUI();

    void updateNotebookLabel();

    void updateTagLabel(const QString &p_tag);

    bool tagListObsolete(const QStringList &p_tags) const;

    void updateTagList(const QStringList &p_tags);

    void updateContent();

    // Return ture if succeeded.
    bool activateTag(const QString &p_tag);

    void addTagItem(const QString &p_tag);

    void restoreStateAndGeometry();

    VSearch *getVSearch() const;

    void initVSearch();

    void appendItemToFileList(const QSharedPointer<VSearchResultItem> &p_item);

    QString getFilePath(const QListWidgetItem *p_item) const;

    void promptToRemoveEmptyTag(const QString &p_tag);

    void setupFileListSplitOut(bool p_enabled);

    void showTagWidget();

    bool m_uiInitialized;               /*!< Flag to check whether VTagExplorer has been instantiated. */

    QLabel *m_notebookLabel;            /*!< Label to show the title of m_tagList. */

    QLabel *m_tagLabel;                 /*!< Label to show the title of m_fileList. */

    QPushButton *m_splitBtn;            /*!< Switch the layout of m_notebookLabel and m_tagLabel between vertical or horizontal . */

    VListWidget *m_tagList;             /*!< Create a explorer to browse all the tages. */

    VListWidget *m_fileList;            /*!< Create a explorer to browse the files by specified tag. */

    QSplitter *m_splitter;              /*!< Splitter to distribute the m_notebookLabel and m_tagLabel. */

    VNotebook *m_notebook;      /*!< Pointer to the notebook in use. */

    bool m_notebookChanged;     /*!< Force to update tag list if notebook is changed. */

    QIcon m_noteIcon;           /*!< resources/icons/note_item */

    VSearch *m_search;          /*!< Used to search the tag in tag list */
};

/*! \brief Return the search pointer

    If m_search is not initialized, call initVSearch to create one.
*/
inline VSearch *VTagExplorer::getVSearch() const
{
    if (m_search) {
        return m_search;
    }

    const_cast<VTagExplorer *>(this)->initVSearch();
    return m_search;
}

#endif // VTAGEXPLORER_H
