Introduction
===========

It is a very simple module which provides an integration between widely 
used modules "LoginToboggan" and "Rules".

Installation
============
1. Enable the module in the module listing page.
2. In LoginToboggan settings (admin/user/logintoboggan), 
   check "Set password" option.
3. For best results , uncheck the "Immediate login" option on 
   LoginToboggan settings
4. Thats it!!

Usage
=====
Create a rule. You will now see "When the user account is validated" 
event under LoginToboggan category. 
In this event, the validated user's account information is available. 
Use this event to implement various automation tasks.

Currently maintained by Sudhir (porwal.lucky@gmail.com)
