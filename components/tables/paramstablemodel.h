#ifndef PARAMSTABLEMODEL_H
#define PARAMSTABLEMODEL_H

#include <QAbstractTableModel>
#include "models/request_models.h"

class ParamsTableModel : public QAbstractTableModel{
    Q_OBJECT

public:
    explicit ParamsTableModel(QObject *parent = nullptr);
    explicit ParamsTableModel(const QJsonArray &params, QObject *parent = nullptr);

    void addParams(const QJsonArray &params);
    void addParam(const QJsonObject &param);

public:
    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section,
                       Qt::Orientation orientation,
                       const QVariant &value,
                       int role = Qt::EditRole) override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    QJsonArray m_params;
};

#endif // PARAMSTABLEMODEL_H
