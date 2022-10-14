@echo off
set http_proxy=http://127.0.0.1:7890 & set https_proxy=http://127.0.0.1:7890
git config --global user.email "a15131807278@163.com"
git config --global user.name "lgloryl"
:push
git add ./
git commit -am "new"
git push origin main
timeout -t 10
goto push