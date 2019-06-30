# git/shell 学习笔记


### 1.  IDEA vcs 新建了git仓库，第一次push github时遇到push to origin/master was rejected

 **原因： 需要从远程仓库pull 一次**

先进入本地仓库目录

```bash
git pull  

git pull origin master

git pull origin master --allow-unrelated-histories
```

### 2. docker

本地docker有一个debian,端口20022， 登录进去用`ssh -p 20022 ics@127.0.0.1`
要复制进去文件，`docker cp`不管用，只能用` scp -P 20022 xxx.txt ics@127.0.0.1:~`

`scp -i xxx.pem xxx.jar root@47.100.xxx.xxx:~/web/` 密钥文件的scp命令
