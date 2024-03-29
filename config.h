//
// Created by shotacon on 23-7-30.
//

//
// Created by shotacon on 23-3-15.
//

#ifndef YY_SERVER_CONFIG_H
#define YY_SERVER_CONFIG_H

#include "cstring"
#include "string"
using std::string;

//服务器
#define _PORT 6666

//数据库
#define _DB_IP "localhost"

#define _DB_NAME "meeting"

#define _DB_PASSWD "88888888"

#define _DB_USER "root"


//线程池
#define _MANAGE_LOOP_INTERVAL 5

#define _ADD_THREAD_NUM 3

#define _DE_THREAD_NUM 3

//epoll
#define _LT         0

#define _READ_SIZE 2048     //缓冲层大小

#define _WRITE_SIZE 2048

#define _READ_BUFF_SIZE 256*1024    //内核缓冲区大小

#define _WRITE_BUFF_SIZE 128*10242

#define _MAX_LISTEN_EVENT 10000

//logic protocol


#define DEF_PACK_BASE  (10000)
#define DEF_PACK_COUNT  (100)
#define DEF_CONTENT_SIZE        (1024)
#define DEF_BUFFER  ( 4096 )
#define MAX_SIZE	(40)
#define MAX_PATH   (260)
//注册
#define  DEF_PACK_REGISTER_RQ    (DEF_PACK_BASE + 0)
#define  DEF_PACK_REGISTER_RS    (DEF_PACK_BASE + 1)
//登录
#define  DEF_PACK_LOGIN_RQ    (DEF_PACK_BASE + 2)
#define  DEF_PACK_LOGIN_RS    (DEF_PACK_BASE + 3)
//创建房间
#define DEF_PACK_CREATEROOM_RQ  (DEF_PACK_BASE + 4)
#define DEF_PACK_CREATEROOM_RS  (DEF_PACK_BASE + 5)
//加入房间
#define DEF_PACK_JOINROOM_RQ  (DEF_PACK_BASE + 6)
#define DEF_PACK_JOINROOM_RS  (DEF_PACK_BASE + 7)
//房间列表请求
#define DEF_PACK_ROOM_MEMBER    (DEF_PACK_BASE + 8)
//音频数据
#define DEF_PACK_AUDIO_FRAME    (DEF_PACK_BASE + 9)
//视频数据
#define DEF_PACK_VIDEO_FRAME    (DEF_PACK_BASE + 10)
//退出房间请求
#define DEF_PACK_LEAVEROOM_RQ   (DEF_PACK_BASE + 11)
//退出房间回复
#define DEF_PACK_OFFLINE   (DEF_PACK_BASE + 12)
//音频注册
#define DEF_PACK_AUDIO_REGISTER (DEF_PACK_BASE + 13)
//视频注册
#define DEF_PACK_VIDEO_REGISTER (DEF_PACK_BASE + 14)
//用户信息
#define DEF_PACK_USER_INFO       (DEF_PACK_BASE + 15)
//用户下线
#define DEF_PACK_USER_OFFLINE    (DEF_PACK_BASE + 16)
//聊天请求
#define DEF_PACK_CHAT_RQ       (DEF_PACK_BASE + 17)
//聊天回复
#define DEF_PACK_CHAT_RS       (DEF_PACK_BASE + 18)
//上传文件请求
#define DEF_PACK_UPLOAD_FILE_RQ    (DEF_PACK_BASE + 19)
//上传文件回复
#define DEF_PACK_UPLOAD_FILE_RS    (DEF_PACK_BASE + 20)
//文件内容请求
#define DEF_PACK_FILE_CONTENT_RQ    (DEF_PACK_BASE + 21)
//文件内容回复
#define DEF_PACK_FILE_CONTENT_RS    (DEF_PACK_BASE + 22)
//上传文件请求
#define DEF_PACK_FILE_DOWNLOAD_RQ    (DEF_PACK_BASE + 23)
//上传文件回复
#define DEF_PACK_FILE_DOWNLOAD_RS    (DEF_PACK_BASE + 24)
//注册请求结果
#define tel_is_exist        (0)
#define register_success    (1)
#define name_is_exist       (2)

//登录请求结果
#define user_not_exist        (0)
#define password_error        (1)
#define login_success        (2)
//#define user_online          3

//创建房间结果
#define room_is_exist        0
#define create_success       1

//加入房间结果
#define room_no_exist        0
#define join_success         1

//聊天结果
#define chat_user_no_exist   1
#define chat_room_no_exist   2
#define chat_success         0

#define DEF_FILE_PATH      "/home/shotacon/CLionProjects/Meeting_Server/files/"


/////////////////////网络//////////////////////////////////////


typedef int PackType;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//登录请求
typedef struct STRU_LOGIN_RQ {
    STRU_LOGIN_RQ() {
        m_nType = DEF_PACK_LOGIN_RQ;
        memset(m_tel, 0, MAX_SIZE);
        memset(m_password, 0, MAX_SIZE);
    }

    PackType m_nType;   //包类型
    char m_tel[MAX_SIZE]; //用户ID
    char m_password[MAX_SIZE];  //密码
} STRU_LOGIN_RQ;


//登录回复
typedef struct STRU_LOGIN_RS {
    STRU_LOGIN_RS() {
        m_nType = DEF_PACK_LOGIN_RS;
        m_userid = 0;
        m_lResult = 0;
        memset(m_name, 0, MAX_SIZE);
    }

    PackType m_nType;   //包类型
    int m_userid;
    int m_lResult; //注册结果
    char m_name[MAX_SIZE];  //用户名

} STRU_LOGIN_RS;

//注册请求
typedef struct STRU_REGISTER_RQ {
    STRU_REGISTER_RQ() {
        m_nType = DEF_PACK_REGISTER_RQ;
        memset(m_tel, 0, MAX_SIZE);
        memset(m_password, 0, MAX_SIZE);
    }

    PackType m_nType;   //包类型
    char m_tel[MAX_SIZE]; //手机号
    char m_name[MAX_SIZE];
    char m_password[MAX_SIZE];  //密码

} STRU_REGISTER_RQ;

//注册回复
typedef struct STRU_REGISTER_RS {
    STRU_REGISTER_RS() {
        m_nType = DEF_PACK_REGISTER_RS;
        m_lResult = 0;
    }

    PackType m_nType;   //包类型
    int m_lResult; //注册结果

} STRU_REGISTER_RS;


//创建房间请求
typedef struct STRU_CREATEROOM_RQ {
    STRU_CREATEROOM_RQ() {
        m_nType = DEF_PACK_CREATEROOM_RQ;
        m_UserID = 0;
    }

    PackType m_nType;   //包类型
    int m_UserID;

} STRU_CREATEROOM_RQ;

//创建房间回复
typedef struct STRU_CREATEROOM_RS {
    STRU_CREATEROOM_RS() {
        m_nType = DEF_PACK_CREATEROOM_RS;
        m_lResult = 0;
        m_RoomId = 0;
    }

    PackType m_nType;   //包类型
    int m_lResult;    //创建结果
    int m_RoomId;

} STRU_CREATEROOM_RS;

//加入房间请求
typedef struct STRU_JOINROOM_RQ {
    STRU_JOINROOM_RQ() {
        m_nType = DEF_PACK_JOINROOM_RQ;
        m_UserID = 0;
        m_RoomID = 0;
    }

    PackType m_nType;   //包类型
    int m_UserID;
    int m_RoomID;

} STRU_JOINROOM_RQ;

//加入房间回复
typedef struct STRU_JOINROOM_RS {
    STRU_JOINROOM_RS() {
        m_nType = DEF_PACK_JOINROOM_RS;
        m_lResult = 0;
        m_RoomID = 0;
    }

    PackType m_nType;   //包类型
    int m_lResult;    //注册结果
    int m_RoomID;
} STRU_JOINROOM_RS;

//房间成员请求
typedef struct STRU_ROOM_MEMBER_RQ {
    STRU_ROOM_MEMBER_RQ() {
        m_nType = DEF_PACK_ROOM_MEMBER;
        m_UserID = 0;
        memset(m_szUser, 0, MAX_SIZE);
    }

    PackType m_nType;   //包类型
    int m_UserID;
    int m_icon;
    char m_szUser[MAX_SIZE];

} STRU_ROOM_MEMBER_RQ;


//离开房间请求
typedef struct STRU_LEAVEROOM_RQ {
    STRU_LEAVEROOM_RQ() {
        m_nType = DEF_PACK_LEAVEROOM_RQ;
        m_nUserId = 0;
        m_RoomId = 0;
        memset(szUserName, 0, MAX_SIZE);
    }

    PackType m_nType;   //包类型
    int m_nUserId; //用户ID
    int m_RoomId;
    char szUserName[MAX_SIZE];
} STRU_LEAVEROOM_RQ;


// id -> userInfo
typedef struct UserInfo {
    UserInfo() {
        m_sockfd = 0;
        m_id = 0;
        m_roomid = 0;
        memset(m_userName, 0, MAX_SIZE);
        m_videofd = 0;
        m_audiofd = 0;
    }

    //struct bufferevent*  m_sockfd;  用下面的替换y
    int m_sockfd;
    int m_id;
    int m_roomid;
    char m_userName[MAX_SIZE];

    int m_videofd;
    int m_audiofd;
} UserInfo;

//信息请求结构体
typedef struct STRU_USER_INFO_RQ {
    STRU_USER_INFO_RQ() : type(DEF_PACK_USER_INFO), userid(0), iconid(0) {
        memset(name, 0, sizeof(name));
        memset(feeling, 0, sizeof(feeling));
    }

    //需要 用户id 头像id 昵称 签名 状态--是否在线
    PackType type;
    int userid;
    int iconid;
    char name[MAX_SIZE];
    char feeling[MAX_SIZE];
} STRU_USER_INFO_RQ;

//注册音频
struct STRU_AUDIO_REGISTER {
    STRU_AUDIO_REGISTER() : m_nType(DEF_PACK_AUDIO_REGISTER) {
        m_userid = 0;
    }

    PackType m_nType;   //包类型
    int m_userid;
};

//注册视频
struct STRU_VIDEO_REGISTER {
    STRU_VIDEO_REGISTER() : m_nType(DEF_PACK_VIDEO_REGISTER) {
        m_userid = 0;
    }

    PackType m_nType;   //包类型
    int m_userid;
};

//下线数据包
struct STRU_OFFLINE {
    STRU_OFFLINE() : m_nType(DEF_PACK_USER_OFFLINE) {}

    PackType m_nType;
    int m_userid;
};

//聊天
struct STRU_CHAT_RQ
{
    STRU_CHAT_RQ():type(DEF_PACK_CHAT_RQ) , userid(0) , roomid(0)
    {
        memset( content , 0 , DEF_CONTENT_SIZE );
    }
    STRU_CHAT_RQ(const STRU_CHAT_RQ& rq):type(DEF_PACK_CHAT_RQ){
        userid = rq.userid;
        iconid = rq.iconid;
        roomid = rq.roomid;
        strcpy(name, rq.name);
        strcpy(content, rq.content);
    }
    // 谁发给哪个房间 服务器转发
    PackType type;
    int userid;
    int iconid;
    int roomid;
    char name[MAX_SIZE];
    char content[DEF_CONTENT_SIZE];

};

struct STRU_CHAT_RS
{
    STRU_CHAT_RS():type(DEF_PACK_CHAT_RS) , userid(0) , roomid(0), result(0)
    {

    }
    PackType type;
    int userid;
    int roomid; //方便找是哪个人不在线
    int result;

};


//文件信息
struct FileInfo{
    FileInfo():file_id(0), size(0), file_fd(0), pos(0), is_pause(0), timestamp(0){

    }
    int file_id;
    int user_id;
    string name;
    string dir;
    string time;
    int size;
    int room_id;
    string md5;
    string type;
    string absolute_path;
    int timestamp;
    int pos;
    int is_pause;
    int file_fd;
};

//上传文件请求
struct STRU_UPLOAD_FILE_RQ
{
    STRU_UPLOAD_FILE_RQ():type(DEF_PACK_UPLOAD_FILE_RQ)
            ,userid(0),size(0),timestamp(0){
        memset( fileName , 0, sizeof(fileName) );
        memset( dir , 0, sizeof(dir) );
        memset( md5 , 0, sizeof(md5) );
        memset( fileType , 0, sizeof(fileType) );
        memset( time , 0, sizeof(time) );
    }
    PackType type;
    int timestamp;//时间戳用于区分不同任务
    int userid; //服务器与时间戳配合,区分不同任务
    char fileName[MAX_PATH]; //上传文件名字
    int size;//大小
    int room_id;
    char dir[MAX_PATH];//上传到什么目录
    char md5[MAX_SIZE]; //上传文件的md5, 用于验证文件是否完整无误
    char fileType[MAX_SIZE];//文件类型
    char time[MAX_SIZE]; //上传时间
};

//上传文件回复
struct STRU_UPLOAD_FILE_RS
{
    STRU_UPLOAD_FILE_RS(): type(DEF_PACK_UPLOAD_FILE_RS)
            , userid(0), fileid(0),result(1),timestamp(0){

    }
    PackType type;
    int timestamp;//时间戳用于区分不同任务
    int userid;//用户id
    int fileid; //文件id
    int result; //结果
};


//文件内容请求
struct STRU_FILE_CONTENT_RQ
{
    STRU_FILE_CONTENT_RQ():type(DEF_PACK_FILE_CONTENT_RQ),
                           userid(0),fileid(0),len(0),timestamp(0){
        memset( content , 0 , sizeof(content));
    }
    PackType type;
    int timestamp;//时间戳用于区分不同任务
    int userid;//用户id
    int fileid;//文件id
    char content[DEF_BUFFER];//文件内容 也叫文件块   _DEF_BUFFER  4096
    int len;//文件内容长度
};

//文件内容回复
struct STRU_FILE_CONTENT_RS
{
    STRU_FILE_CONTENT_RS():type(DEF_PACK_FILE_CONTENT_RS),
                           userid(0),fileid(0),result(1),len(0),timestamp(0){

    }
    PackType type;
    int timestamp;//时间戳用于区分不同任务
    int userid;//用户id
    int fileid;//文件id
    int result;//结果
    int len;//文件内容长度

};

//文件下载请求
struct STRU_FILE_DOWNLOAD_RQ
{
    STRU_FILE_DOWNLOAD_RQ():type(DEF_PACK_FILE_DOWNLOAD_RQ),userid(0),size(0),timestamp(0)
    {
        memset( fileName , 0, sizeof(fileName));
        memset( md5 , 0, sizeof(md5));
    }
    PackType type;
    int timestamp;//时间戳用于区分不同任务
    int userid; //服务器与时间戳配合,区分不同任务
    char fileName[MAX_PATH]; //上传文件名字
    int size;//大小
    char dir[MAX_PATH];
    char md5[MAX_SIZE]; //上传文件的md5, 用于验证文件是否完整无误

};

//文件下载回复
struct STRU_FILE_DOWNLOAD_RS
{
    STRU_FILE_DOWNLOAD_RS(): type(DEF_PACK_FILE_DOWNLOAD_RS)
            , userid(0),result(1){

    }
    PackType type;
    int timestamp;//时间戳用于区分不同任务
    int userid;//用户id
    int result; //结果
};
#endif //YY_SERVER_CONFIG_H