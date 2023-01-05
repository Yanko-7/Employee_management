#include "ManagerDAO.h"

bool ManagerDAO::saveData(Manager& manager)
{
    //����
    string sql = "insert into manager(id,name) values(\"" + manager.getID() + "\",\"" + manager.getName() + "\"); ";
    return DatabaseUtil::getInstance().saveData(sql);
}

bool ManagerDAO::updateData(Manager& manager)
{
    //����
    string sql = "update manager set name = \"" + manager.getName() + "\" where id = \"" + manager.getID() + "\";";
    return DatabaseUtil::getInstance().updateData(sql);
}

bool ManagerDAO::deleteData(Manager& manager)
{
    //ɾ��
    string sql = "delete from manager where id = \"" + manager.getID() + "\";";
    return DatabaseUtil::getInstance().deleteData(sql);
}

Manager* ManagerDAO::findData(string& id)
{
    //���ҵ���
    string sql = "select * from manager where id =\"" + id + "\";";
    int nrow, ncol;
    char** result = NULL;
    DatabaseUtil::getInstance().find(sql, &result, nrow, ncol);
    if (nrow == 0 || ncol == 0) {
        cout << "����ʧ�ܣ��޸�id  " << id << endl;
        //�ͷ���Դ
        sqlite3_free_table(result);
        return NULL;
    }
    else {
        int idxCol = ncol;
        string id = result[idxCol];
        string name = result[idxCol + 1];
        //�ͷ���Դ
        sqlite3_free_table(result);
        return new Manager(id, name);
    }
}