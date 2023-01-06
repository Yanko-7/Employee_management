#include "DatabaseUtil.h"

DatabaseUtil* DatabaseUtil::instance = nullptr;

DatabaseUtil::DatabaseUtil() {
    connect();
}

DatabaseUtil::~DatabaseUtil() {
    disconnect();
}

DatabaseUtil& DatabaseUtil::getInstance() {
    //����ģʽ
    if (!instance)
        instance = new DatabaseUtil();
    return *instance;
}

bool DatabaseUtil::connect() {
    //�������ݿ�
    string filePath = "./database.db";
    int ret = sqlite3_open(filePath.c_str(), &pdb);
    if (ret != SQLITE_OK) {
        cout << "���ݿ�����ʧ�ܣ�" << endl;
        return false;
    }
    cout << "���ݿ����ӳɹ���" << endl;
    //���Խ���
    createTable();
    //�����Լ��
    string sql = "PRAGMA foreign_keys = ON;";
    ret = sqlite3_exec(pdb, sql.c_str(), 0, 0, NULL);
    return true;
}

void DatabaseUtil::disconnect() {
    sqlite3_close(pdb);
    cout << "�ر�����" << endl;
}

void DatabaseUtil::createTable()
{
    //������
    int ret;
    //����user��
    string user = "create table if not exists user(id text, password text, primary key(id)); ";
    ret = sqlite3_exec(pdb, user.c_str(), 0, 0, NULL);
    if (ret != SQLITE_OK) {
        cout << "�� user ����ʧ�ܣ�" << sqlite3_errmsg(pdb) << endl;
    }
    else {
        cout << "�� user ����/��ȡ�ɹ���" << endl;
    }
    //����manager��
    string manager = "create table if not exists manager( id text, name text, primary key(id), constraint fk_user foreign key(id) references user(id) ); ";
    ret = sqlite3_exec(pdb, manager.c_str(), 0, 0, NULL);
    if (ret != SQLITE_OK) {
        cout << "�� manager ����ʧ�ܣ�" << sqlite3_errmsg(pdb) << endl;
    }
    else {
        cout << "�� manager ����/��ȡ�ɹ���" << endl;
    }
    //����employee��
    string employee = "create table if not exists employee( id text, name text, city text, position text, manager_id text, salary real, primary key(id), constraint fk_manager foreign key(manager_id) references manager(id)); ";
    ret = sqlite3_exec(pdb, employee.c_str(), 0, 0, NULL);
    if (ret != SQLITE_OK) {
        cout << "�� employee ����ʧ�ܣ�" << sqlite3_errmsg(pdb) << endl;
    }
    else {
        cout << "�� employee ����/��ȡ�ɹ���" << endl;
    }
    return;
}

bool DatabaseUtil::updateData(string& sql)
{
    //���²���
    if (!execute(sql)) {
        cout << "����ʧ�ܣ�" << sql << endl;
        cout << "ԭ��" << sqlite3_errmsg(pdb) << endl;
        return false;
    }
    return true;
}

bool DatabaseUtil::saveData(string& sql)
{
    //�������
    if (!execute(sql)) {
        cout << "����ʧ�ܣ�" << sql << endl;
        cout << "ԭ��" << sqlite3_errmsg(pdb) << endl;
        return false;
    }
    return true;
}

bool DatabaseUtil::deleteData(string& sql)
{
    //ɾ������
    if (!execute(sql)) {
        cout << "ɾ��ʧ�ܣ�" << sql << endl;
        cout << "ԭ��" << sqlite3_errmsg(pdb) << endl;
        return false;
    }
    return true;
}

void DatabaseUtil::find(string& sql, char*** result, int& nrow, int& ncol) {
    //��ѯ����
    int ret = sqlite3_get_table(pdb, sql.c_str(), result, &nrow, &ncol, NULL);
    if (ret != SQLITE_OK) {
        cout << "��ѯʧ�ܣ�" << sql << endl;
        cout << "ԭ��" << sqlite3_errmsg(pdb) << endl;
    }
}

bool DatabaseUtil::execute(string& sql) {
    //ִ��������
    int ret = sqlite3_exec(pdb, sql.c_str(), 0, 0, NULL);
    if (ret != SQLITE_OK) {
        return false;
    }
    return true;
}