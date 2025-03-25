#include "paramstablemodel.h"

ParamsTableModel::ParamsTableModel(QObject *parent)
    : QAbstractTableModel(parent){

    QJsonObject p1{
        {PARAMS_KEY_CHECKED, true},
        {PARAMS_KEY_NAME, "name"},
        {PARAMS_KEY_VALUE, "Linux"},
        {PARAMS_KEY_COMMENT, "The first param"}};
    this->addParam(p1);
}

ParamsTableModel::ParamsTableModel(const QJsonArray &params, QObject *parent)
    : QAbstractTableModel(parent){
    this->addParams(params);
}

void ParamsTableModel::addParams(const QJsonArray &params){
    this->m_params += params;
    qDebug() << this->m_params;
}

void ParamsTableModel::addParam(const QJsonObject &param){
    const int newRow = m_params.size();
    beginInsertRows(QModelIndex(), newRow, newRow);
    this->m_params.push_back(param);
    endInsertRows();
}

QVariant ParamsTableModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if(role != Qt::DisplayRole)
        return QVariant();

    if(orientation == Qt::Horizontal){
        if(role == Qt::DisplayRole){
            switch(section){
            case 0:
                return QVariant(tr(""));
            case 1:
                return QVariant(tr("Name"));
            case 2:
                return QVariant(tr("Value"));
            case 3:
                return QVariant(tr("Comment"));
            }

        }
    }
    return QVariant();
}

bool ParamsTableModel::setHeaderData(int section,
                                     Qt::Orientation orientation,
                                     const QVariant &value,
                                     int role){
    if(value != headerData(section, orientation, role)) {
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

int ParamsTableModel::rowCount(const QModelIndex &parent) const{
    if(parent.isValid())
        return 0;

    return this->m_params.size();
}

int ParamsTableModel::columnCount(const QModelIndex &parent) const{
    if(parent.isValid())
        return 0;

    return 4;
}

QVariant ParamsTableModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid())
        return QVariant();

    const int col = index.column();
    const int row = index.row();
    QJsonObject param = this->m_params[row].toObject();
    if(role == Qt::DisplayRole || role == Qt::EditRole){
        switch(col){
        case 1: return param.value(PARAMS_KEY_NAME);
        case 2: return param.value(PARAMS_KEY_VALUE);
        case 3: return param.value(PARAMS_KEY_COMMENT);
        default: break;
        }
    }else if(role == Qt::CheckStateRole && col == 0){
        return param.value(PARAMS_KEY_CHECKED).toBool() ? Qt::Checked : Qt::Unchecked;
    }

    return QVariant();
}
bool ParamsTableModel::setData(const QModelIndex &index, const QVariant &value, int role){
    if(!index.isValid())
        return false;

    if(data(index, role) != value) {
        const int col = index.column();
        const int row = index.row();
        QJsonObject param = this->m_params[row].toObject();
        if(col == 0){
            param[PARAMS_KEY_CHECKED] = value.toBool();
        }else{
            QString strVal = value.toString();
            switch(col){
            case 1: param[PARAMS_KEY_NAME] = strVal; break;
            case 2: param[PARAMS_KEY_VALUE] = strVal; break;
            case 3: param[PARAMS_KEY_COMMENT] = strVal; break;
            default: return false;
            }
        }

        this->m_params[row] = param;

        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags ParamsTableModel::flags(const QModelIndex &index) const{
    if(!index.isValid())
        return Qt::NoItemFlags;

    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if(index.column() == 0) flags |= Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
    flags |= Qt::ItemIsEditable;

    return flags;
}
