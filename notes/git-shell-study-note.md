# git/shell 学习笔记


### 1.  IDEA vcs 新建了git仓库，第一次push github时遇到push to origin/master was rejected

 **原因： 需要从远程仓库pull 一次**

先进入本地仓库目录

```bash
git pull  

git pull origin master

git pull origin master --allow-unrelated-histories
```

---
