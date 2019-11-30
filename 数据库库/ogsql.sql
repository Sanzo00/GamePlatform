CREATE DATABASE OGSQL DEFAULT CHARSET=utf8;
-- default charset utf8 collate utf8_bin
USE OGSQL;
-- 用户表
create TABLE users
(
uname CHAR(20) NOT NULL,
upwd CHAR(20) NOT NULL,
usex CHAR(20) NOT NULL,
utype INT(1) default 0 NOT NULL,
PRIMARY KEY(uname)
)DEFAULT CHARSET=utf8;
-- 游戏表
CREATE TABLE games
(
gname CHAR(20) NOT NULL,
gtype CHAR(20),
PRIMARY KEY(gname)
)DEFAULT CHARSET=utf8;
-- 成绩表
CREATE TABLE ug
(
gname CHAR(20),
uname CHAR(20),
grade CHAR(10),
PRIMARY KEY(gname,uname),
FOREIGN KEY (gname) REFERENCES games(gname) ON DELETE CASCADE ON UPDATE CASCADE,
FOREIGN KEY (uname) REFERENCES users(uname) ON DELETE CASCADE ON UPDATE CASCADE
)DEFAULT CHARSET=utf8;
-- 用户数据
INSERT INTO users VALUES ('小红', '123456', '男',DEFAULT);
INSERT INTO users VALUES ('小蓝', '123456', '男',DEFAULT);
INSERT INTO users VALUES ('小绿', '123456', '男',DEFAULT);
INSERT INTO users VALUES ('小紫', '123456', '男',DEFAULT);
-- 游戏数据
INSERT INTO games VALUES ('五子棋',NULL);
INSERT INTO games VALUES ('赛车',NULL);
INSERT INTO games VALUES ('飞机大战',NULL);
-- 分数数据
INSERT INTO ug VALUES ('五子棋','小红','88');
INSERT INTO ug VALUES ('五子棋','小蓝','87');
INSERT INTO ug VALUES ('五子棋','小绿','80');

INSERT INTO ug VALUES ('赛车','小红','68');
INSERT INTO ug VALUES ('赛车','小蓝','87');
INSERT INTO ug VALUES ('赛车','小绿','80');

INSERT INTO ug VALUES ('飞机大战','小红','88');
INSERT INTO ug VALUES ('飞机大战','小蓝','77');
INSERT INTO ug VALUES ('飞机大战','小绿','80');









