git push不上去问题

```
//代理查询
git config --global http.proxy
git config --global https.proxy

//重新设置代理
git config --global https.proxy 127.0.0.1:7890
git config --global http.proxy 127.0.0.1:7890

//代理取消
git config --global --unset http.proxy
git config --global --unset https.proxy
```
