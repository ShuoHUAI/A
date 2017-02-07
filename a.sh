#!/bin/bash
# Interactive pptp vpn  install script for an OpenVZ VPS
# surport  : Cenost ,Fedora  6.x 
# Augest 24, 2014 v1.00
#url ：   http://www.dabu.info/?p=2178
 
echo "######################################################"
echo "Interactive PoPToP Install Script for an OpenVZ VPS"
echo
echo "Make sure to contact your provider and have them enable"
echo "IPtables and ppp modules prior to setting up PoPToP."
echo "PPP can also be enabled from SolusVM."
echo
echo "You need to set up the server before creating more users."
echo "A separate user is required per connection or machine."
echo "######################################################"
echo
echo
echo "######################################################"
echo "Select on option:"
echo "1) Set up new PoPToP server AND create one user"
echo "2) Create additional users"
echo "######################################################"
read x
if test $x -eq 1; then
echo "Enter username that you want to create (eg. client1 or john):"
read u
echo "Specify password that you want the server to use:"
read p
 
## get the VPS IP
#ip=`ifconfig venet0:0 | grep 'inet addr' | awk {'print $2'} | sed s/.*://`
 
echo
echo "######################################################"
echo "Downloading and Installing ppp  and   pptpd  "
echo "######################################################"
yum   install  ppp   -y
rpm -Uvh http://poptop.sourceforge.net/yum/stable/rhel6/pptp-release-current.noarch.rpm
yum    install  pptpd  -y
 
echo
echo "######################################################"
echo "Creating Server Config"
echo "######################################################"
cp /etc/ppp/options.pptpd /etc/ppp/options.pptpd.bak
sed -i '70a ms-dns 8.8.8.8'    /etc/ppp/options.pptpd
 
 
 
 
 
 
# setting up pptpd.conf
sed -i '101a localip 192.168.9.1'    /etc/pptpd.conf
sed -i '102a  remoteip 192.168.9.11-30'    /etc/pptpd.conf
 
# adding new user
echo "$u * $p *" >> /etc/ppp/chap-secrets
 
echo
echo "######################################################"
echo "Forwarding IPv4 and Enabling it on boot"
echo "######################################################"
cat >> /etc/sysctl.conf <<END
net.ipv4.ip_forward=1
END
sysctl -p
 
echo
echo "######################################################"
echo "Updating IPtables Routing and Enabling it on boot"
echo "######################################################"
iptables -t nat -A POSTROUTING -o eth0 -j  MASQUERADE
# saves iptables routing rules and enables them on-boot
iptables-save > /etc/iptables.conf
 
cat > /etc/network/if-pre-up.d/iptables <<END
#!/bin/sh
iptables-restore < /etc/iptables.conf
END
 
chmod +x /etc/network/if-pre-up.d/iptables
cat >> /etc/ppp/ip-up <<END
ifconfig ppp0 mtu 1400
END
 
echo
echo "######################################################"
echo "Restarting PoPToP"
echo "######################################################"
sleep 5
/etc/init.d/pptpd restart
 
echo
echo "######################################################"
echo "Server setup complete!"
echo "Connect to your VPS at $ip with these credentials:"
echo "Username:$u ##### Password: $p"
echo "######################################################"
 
# runs this if option 2 is selected
elif test $x -eq 2; then
echo "Enter username that you want to create (eg. client1 or john):"
read u
echo "Specify password that you want the server to use:"
read p
 
 
 
# adding new user
echo "$u * $p *" >> /etc/ppp/chap-secrets
 
echo
echo "######################################################"
echo "Addtional user added!"
echo "Connect to your VPS at $ip with these credentials:"
echo "Username:$u ##### Password: $p"
echo "######################################################"
 
else
echo "Invalid selection, quitting."
exit
fi