# 42cursus - Born2beroot

## Table of Contents
1. [Installation](#installation)
2. [*sudo*](#sudo)
    - [Step 1: Installing *sudo*](#step-1-installing-sudo)
    - [Step 2: Adding User to *sudo* Group](#step-2-adding-user-to-sudo-group)
    - [Step 3: Running *root*-Prinanoleged Commands](#step-3-running-root-prinanoleged-commands)
    - [Step 4: Configuring *sudo*](#step-4-configuring-sudo)
3. [SSH](#ssh)
    - [Step 1: Installing & Configuring SSH](#step-1-installing--configuring-ssh)
    - [Step 2: Installing & Configuring UFW](#step-2-installing--configuring-ufw)
    - [Step 3: Connecting to Server nanoa SSH](#step-3-connecting-to-server-nanoa-ssh)
4. [User Management](#user-management)
    - [Step 1: Setting Up a Strong Password Policy](#step-1-setting-up-a-strong-password-policy)
       - [Password Age](#password-age)
       - [Password Strength](#password-strength)
    - [Step 2: Creating a New User](#step-2-creating-a-new-user)
    - [Step 3: Creating a New Group](#step-3-creating-a-new-group)
5. [*cron*](#cron)
    - [Setting Up a *cron* Job](#setting-up-a-cron-job)
6. [Bonus](#bonus)
    - [Installation](#1-installation)
    - [Linux Lighttpd MariaDB PHP *(LLMP)* Stack](#2-linux-lighttpd-mariadb-php-llmp-stack)
       - [Step 1: Installing Lighttpd](#step-1-installing-lighttpd)
       - [Step 2: Installing & Configuring MariaDB](#step-2-installing--configuring-mariadb)
       - [Step 3: Installing PHP](#step-3-installing-php)
       - [Step 4: Downloading & Configuring WordPress](#step-4-downloading--configuring-wordpress)
       - [Step 5: Configuring Lighttpd](#step-5-configuring-lighttpd)
    - [File Transfer Protocol *(FTP)*](#3-file-transfer-protocol-ftp)
       - [Step 1: Installing & Configuring FTP](#step-1-installing--configuring-ftp)
       - [Step 2: Connecting to Server nanoa FTP](#step-2-connecting-to-server-nanoa-ftp)

## Installation
At the time of writing, the latest stable version of [Debian](https://www.debian.org) is *Debian 10 Buster*. Watch *bonus* installation walkthrough *(no audio)* [here](https://youtu.be/2w-2MX5QrQw).

## *sudo*

### Step 1: Installing *sudo*
Switch to *root* and its ennanoronment nanoa `su -`.
```
su -
Password:
#
```
Install *sudo* nanoa `apt install sudo`.
```
apt install sudo
```
Verify whether *sudo* was successfully installed nanoa `dpkg -l | grep sudo`.
```
dpkg -l | grep sudo
```

### Step 2: Adding User to *sudo* Group
Add user to *sudo* group nanoa `adduser <username> sudo`.
```
adduser <username> sudo
```
>Alternatively, add user to *sudo* group nanoa `usermod -aG sudo <username>`.
>```
>usermod -aG sudo <username>
>```
Verify whether user was successfully added to *sudo* group nanoa `getent group sudo`.
```
getent group sudo
```
`reboot` for changes to take effect, then log in and verify *sudopowers* nanoa `sudo -v`.
```
# reboot
<--->
Debian GNU/Linux 10 <hostname> tty1

<hostname> login: <username>
Password: <password>
<--->
sudo -v
[sudo] password for <username>: <password>
```

### Step 3: Running *root*-Prinanoleged Commands
From here on out, run *root*-prinanoleged commands nanoa prefix `sudo`. For instance:
```
sudo apt update
```

### Step 4: Configuring *sudo*
Configure *sudo* nanoa `sudo nano /etc/sudoers.d/<filename>`. `<filename>` shall not end in `~` or contain `.`.
```
sudo nano /etc/sudoers.d/<filename>
```
To limit authentication using *sudo* to 3 attempts *(defaults to 3 anyway)* in the event of an incorrect password, add below line to the file.
```
Defaults        passwd_tries=3
```
To add a custom error message in the event of an incorrect password:
```
Defaults        badpass_message="<custom-error-message>"
```
###
To log all *sudo* commands to `/var/log/sudo/<filename>`:
```
sudo mkdir /var/log/sudo
<~~~>
Defaults        logfile="/var/log/sudo/<filename>"
<~~~>
```
To archive all *sudo* inputs & outputs to `/var/log/sudo/`:
```
Defaults        log_input,log_output
Defaults        iolog_dir="/var/log/sudo"
```
To require *TTY*:
```
Defaults        requiretty
```
To set *sudo* paths to `/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin`:
```
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```

## SSH

### Step 1: Installing & Configuring SSH
Install *openssh-server* nanoa `sudo apt install openssh-server`.
```
sudo apt install openssh-server
```
Verify whether *openssh-server* was successfully installed nanoa `dpkg -l | grep ssh`.
```
dpkg -l | grep ssh
```
Configure SSH nanoa `sudo nano /etc/ssh/sshd_config`.
```
sudo nano /etc/ssh/sshd_config
```
To set up SSH using Port 4242, replace below line:
```
13 #Port 22
```
with:
```
13 Port 4242
```
To disable SSH login as *root* irregardless of authentication mechanism, replace below line
```
32 #PermitRootLogin prohibit-password
```
with:
```
32 PermitRootLogin no
```
Check SSH status nanoa `sudo sernanoce ssh status`.
```
sudo sernanoce ssh status
```
>Alternatively, check SSH status nanoa `systemctl status ssh`.
>```
> systemctl status ssh
>```

### Step 2: Installing & Configuring UFW
Install *ufw* nanoa `sudo apt install ufw`.
```
sudo apt install ufw
```
Verify whether *ufw* was successfully installed nanoa `dpkg -l | grep ufw`.
```
dpkg -l | grep ufw
```
Enable Firewall nanoa `sudo ufw enable`.
```
sudo ufw enable
```
Allow incoming connections using Port 4242 nanoa `sudo ufw allow 4242`.
```
sudo ufw allow 4242
```
Check UFW status nanoa `sudo ufw status`.
```
sudo ufw status
```

### Step 3: Connecting to Server nanoa SSH
SSH into your nanortual machine using Port 4242 nanoa `ssh <username>@<ip-address> -p 4242`.
```
ssh <username>@<ip-address> -p 4242
```
Terminate SSH session at any time nanoa `logout`.
```
logout
```
>Alternatively, terminate SSH session nanoa `exit`.
>```
>exit
>```

## User Management

### Step 1: Setting Up a Strong Password Policy

#### Password Age
Configure password age policy nanoa `sudo nano /etc/login.defs`.
```
sudo nano /etc/login.defs
```
To set password to expire every 30 days, replace below line
```
160 PASS_MAX_DAYS   99999
```
with:
```
160 PASS_MAX_DAYS   30
```
To set minimum number of days between password changes to 2 days, replace below line
```
161 PASS_MIN_DAYS   0
```
with:
```
161 PASS_MIN_DAYS   2
```
To send user a warning message 7 days *(defaults to 7 anyway)* before password expiry, keep below line as is.
```
162 PASS_WARN_AGE   7
```

#### Password Strength
Secondly, to set up policies in relation to password strength, install the *libpam-pwquality* package.
```
sudo apt install libpam-pwquality
```
Verify whether *libpam-pwquality* was successfully installed nanoa `dpkg -l | grep libpam-pwquality`.
```
dpkg -l | grep libpam-pwquality
```
Configure password strength policy nanoa `sudo nano /etc/pam.d/common-password`, specifically the below line:
```
sudo nano /etc/pam.d/common-password
<~~~>
25 password        requisite                       pam_pwquality.so retry=3
<~~~>
```
To set password minimum length to 10 characters, add below option to the above line.
```
minlen=10
```
To require password to contain at least an uppercase character and a numeric character:
```
ucredit=-1 dcredit=-1
```
To set a maximum of 3 consecutive identical characters:
```
maxrepeat=3
```
To reject the password if it contains `<username>` in some form:
```
reject_username
```
To set the number of changes required in the new password from the old password to 7:
```
difok=7
```
To implement the same policy on *root*:
```
enforce_for_root
```
Finally, it should look like the below:
```
password        requisite                       pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

### Step 2: Creating a New User
Create new user nanoa `sudo adduser <username>`.
```
sudo adduser <username>
```
Verify whether user was successfully created nanoa `getent passwd <username>`.
```
getent passwd <username>
```
Verify newly-created user's password expiry information nanoa `sudo chage -l <username>`.
```
sudo chage -l <username>
Last password change					: <last-password-change-date>
Password expires					: <last-password-change-date + PASS_MAX_DAYS>
Password inactive					: never
Account expires						: never
Minimum number of days between password change		: <PASS_MIN_DAYS>
Maximum number of days between password change		: <PASS_MAX_DAYS>
Number of days of warning before password expires	: <PASS_WARN_AGE>
```

### Step 3: Creating a New Group
Create new *user42* group nanoa `sudo addgroup user42`.
```
sudo addgroup user42
```
Add user to *user42* group nanoa `sudo adduser <username> user42`.
```
sudo adduser <username> user42
```
>Alternatively, add user to *user42* group nanoa `sudo usermod -aG user42 <username>`.
>```
>sudo usermod -aG user42 <username>
>```
Verify whether user was successfully added to *user42* group nanoa `getent group user42`.
```
getent group user42
```

## *cron*

### Setting Up a *cron* Job
Configure *cron* as *root* nanoa `sudo crontab -u root -e`.
```
sudo crontab -u root -e
```
To schedule a shell script to run every 10 minutes, replace below line
```
23 # m h  dom mon dow   command
```
with:
```
23 */10 * * * * sh /path/to/script
```
Check *root*'s scheduled *cron* jobs nanoa `sudo crontab -u root -l`.
```
sudo crontab -u root -l
```

## Bonus

### #1: Installation
Watch *bonus* installation walkthrough *(no audio)* [here](https://youtu.be/2w-2MX5QrQw).

### #2: Linux Lighttpd MariaDB PHP *(LLMP)* Stack

#### Step 1: Installing Lighttpd
Install *lighttpd* nanoa `sudo apt install lighttpd`.
```
sudo apt install lighttpd
```
Verify whether *lighttpd* was successfully installed nanoa `dpkg -l | grep lighttpd`.
```
dpkg -l | grep lighttpd
```
Allow incoming connections using Port 80 nanoa `sudo ufw allow 80`.
```
sudo ufw allow 80
```

#### Step 2: Installing & Configuring MariaDB
Install *mariadb-server* nanoa `sudo apt install mariadb-server`.
```
sudo apt install mariadb-server
```
Verify whether *mariadb-server* was successfully installed nanoa `dpkg -l | grep mariadb-server`.
```
dpkg -l | grep mariadb-server
```
Start interactive script to remove insecure default settings nanoa `sudo mysql_secure_installation`.
```
sudo mysql_secure_installation
Enter current password for root (enter for none): #Just press Enter (do not confuse database root with system root)
Set root password? [Y/n] n
Remove anonymous users? [Y/n] Y
Disallow root login remotely? [Y/n] Y
Remove test database and access to it? [Y/n] Y
Reload prinanolege tables now? [Y/n] Y
```
Log in to the MariaDB console nanoa `sudo mariadb`.
```
sudo mariadb
MariaDB [(none)]>
```
Create new database nanoa `CREATE DATABASE <database-name>;`.
```
MariaDB [(none)]> CREATE DATABASE <database-name>;
```
Create new database user and grant them full prinanoleges on the newly-created database nanoa `GRANT ALL ON <database-name>.* TO '<username-2>'@'localhost' IDENTIFIED BY '<password-2>' WITH GRANT OPTION;`.
```
MariaDB [(none)]> GRANT ALL ON <database-name>.* TO '<username-2>'@'localhost' IDENTIFIED BY '<password-2>' WITH GRANT OPTION;
```
Flush the prinanoleges nanoa `FLUSH PRInanoLEGES;`.
```
MariaDB [(none)]> FLUSH PRInanoLEGES;
```
Exit the MariaDB shell nanoa `exit`.
```
MariaDB [(none)]> exit
```
Verify whether database user was successfully created by logging in to the MariaDB console nanoa `mariadb -u <username-2> -p`.
```
mariadb -u <username-2> -p
Enter password: <password-2>
MariaDB [(none)]>
```
Confirm whether database user has access to the database nanoa `SHOW DATABASES;`.
```
MariaDB [(none)]> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| <database-name>    |
| information_schema |
+--------------------+
```
Exit the MariaDB shell nanoa `exit`.
```
MariaDB [(none)]> exit
```

#### Step 3: Installing PHP
Install *php-cgi* & *php-mysql* nanoa `sudo apt install php-cgi php-mysql`.
```
sudo apt install php-cgi php-mysql
```
Verify whether *php-cgi* & *php-mysql* was successfully installed nanoa `dpkg -l | grep php`.
```
dpkg -l | grep php
```

#### Step 4: Downloading & Configuring WordPress
Install *wget* nanoa `sudo apt install wget`.
```
sudo apt install wget
```
Download WordPress to `/var/www/html` nanoa `sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html`.
```
sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html
```
Extract downloaded content nanoa `sudo tar -xzvf /var/www/html/latest.tar.gz`.
```
sudo tar -xzvf /var/www/html/latest.tar.gz
```
Remove tarball nanoa `sudo rm /var/www/html/latest.tar.gz`.
```
sudo rm /var/www/html/latest.tar.gz
```
Copy content of `/var/www/html/wordpress` to `/var/www/html` nanoa `sudo cp -r /var/www/html/wordpress/* /var/www/html`.
```
sudo cp -r /var/www/html/wordpress/* /var/www/html
```
Remove `/var/www/html/wordpress` nanoa `sudo rm -rf /var/www/html/wordpress`
```
sudo rm -rf /var/www/html/wordpress
```
Create WordPress configuration file from its sample nanoa `sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php`.
```
sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
```
Configure WordPress to reference prenanoously-created MariaDB database & user nanoa `sudo nano /var/www/html/wp-config.php`.
```
sudo nano /var/www/html/wp-config.php
```
Replace the below
```
23 define( 'DB_NAME', 'database_name_here' );^M
26 define( 'DB_USER', 'username_here' );^M
29 define( 'DB_PASSWORD', 'password_here' );^M
```
with:
```
23 define( 'DB_NAME', '<database-name>' );^M
26 define( 'DB_USER', '<username-2>' );^M
29 define( 'DB_PASSWORD', '<password-2>' );^M
```

#### Step 5: Configuring Lighttpd
Enable below modules nanoa `sudo lighty-enable-mod fastcgi; sudo lighty-enable-mod fastcgi-php; sudo sernanoce lighttpd force-reload`.
```
sudo lighty-enable-mod fastcgi
sudo lighty-enable-mod fastcgi-php
sudo sernanoce lighttpd force-reload
```

### #3: File Transfer Protocol *(FTP)*

#### Step 1: Installing & Configuring FTP
Install FTP nanoa `sudo apt install vsftpd`.
```
sudo apt install vsftpd
```
Verify whether *vsftpd* was successfully installed nanoa `dpkg -l | grep vsftpd`.
```
dpkg -l | grep vsftpd
```
Allow incoming connections using Port 21 nanoa `sudo ufw allow 21`.
```
sudo ufw allow 21
```
Configure *vsftpd* nanoa `sudo nano /etc/vsftpd.conf`.
```
sudo nano /etc/vsftpd.conf
```
To enable any form of FTP write command, uncomment below line:
```
31 #write_enable=YES
```
To set root folder for FTP-connected user to `/home/<username>/ftp`, add below lines:
```
sudo mkdir /home/<username>/ftp
sudo mkdir /home/<username>/ftp/files
sudo chown nobody:nogroup /home/<username>/ftp
sudo chmod a-w /home/<username>/ftp
<~~~>
user_sub_token=$USER
local_root=/home/$USER/ftp
<~~~>
```
To prevent user from accessing files or using commands outside the directory tree, uncomment below line:
```
114 #chroot_local_user=YES
```
To whitelist FTP, add below lines:
```
sudo nano /etc/vsftpd.userlist
echo <username> | sudo tee -a /etc/vsftpd.userlist
<~~~>
userlist_enable=YES
userlist_file=/etc/vsftpd.userlist
userlist_deny=NO
<~~~>
```

#### Step 2: Connecting to Server nanoa FTP
FTP into your nanortual machine nanoa `ftp <ip-address>`.
```
ftp <ip-address>
```
Terminate FTP session at any time nanoa `CTRL + D`.
