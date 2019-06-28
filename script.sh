#! /bin/bash

echo "please add line in README file"
read var
echo $var >> README.md
git init
git add .
echo "please Enter the commit name"
read var
git commit -m $var
git remote add origin https://github.com/niteshgpt83/sms_application.git
git push -u origin master
