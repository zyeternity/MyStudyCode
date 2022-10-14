@echo off
git config --global user.email "a15131807278@163.com"
git config --global user.name "lgloryl"
git add ./
git commit -am "new"
set http_proxy=http://127.0.0.1:7890 & set https_proxy=http://127.0.0.1:7890
git push origin main
exit