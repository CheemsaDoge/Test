### 当你遇见错误 `fatal: unable to access 'https://github.com/xxx/xxx.git': Recv failure: Connection was reset.`

检查是否使用 `代理` 

- 是：

  ```git
  git config --global http.proxy http://127.0.0.1:xxx //（xxx为墙的端口
  ```

- 否：

  ```git
  git config --global --unset.http.proxy
  git config --global --unset.https.proxy
  ```

### 当你第一次使用 `git`

1. 设定 `user.name` 和 `user.email`

   ```git
   git config --global user.name CheemsaDoge
   git config --global user.email ywjh.net@qq.com
   ```

2. 获得 `.ssh` 密匙并加入到 `Github` 中。

   ```git
   ssh-keygen -t rsa –C “youremail@example.com”
   ```

   将 `users/"username"/.ssh/id_rsa.pub` 中的内容复制后加入 `Github` 。 
3. 使用 `init` , `add` , `commit` , `push` 等指令上传仓库。

### 当你不喜欢珂朵莉了
- 那她会伤心的 :cry: 
