# Libftpp

## Skills list

- Design Patterns           : Singleton, Observer
- Concurrence               : Thread safety, mutex, atomic, lock-free
- Structures de donnees     : Containers personnalises
- Reseau                    : Sockets, TCP/IP, protocoles
- Mathematiques             : Vecteurs, algebre lineaire
- Generation aleatoire      : RNG, distributions
- Architecture logicielle   : API design, modularite
- Qualite logicielle        : Tests, robustesse, maintenance

ip addr
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute 
       valid_lft forever preferred_lft forever
2: enp0s3: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 08:00:27:22:ef:2a brd ff:ff:ff:ff:ff:ff
    altname enx08002722ef2a
    inet 10.0.2.15/24 brd 10.0.2.255 scope global dynamic noprefixroute enp0s3
       valid_lft 85850sec preferred_lft 85850sec
    inet6 fd17:625c:f037:2:1869:8f92:dd57:c3ca/64 scope global temporary dynamic 
       valid_lft 86288sec preferred_lft 14288sec
    inet6 fd17:625c:f037:2:a00:27ff:fe22:ef2a/64 scope global dynamic mngtmpaddr noprefixroute 
       valid_lft 86288sec preferred_lft 14288sec
    inet6 fe80::a00:27ff:fe22:ef2a/64 scope link noprefixroute 
       valid_lft forever preferred_lft forever
3: enp0s8: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 08:00:27:0c:0a:f3 brd ff:ff:ff:ff:ff:ff
    altname enx0800270c0af3
ichpakov@my-vm:~$ ip link
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN mode DEFAULT group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
2: enp0s3: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP mode DEFAULT group default qlen 1000
    link/ether 08:00:27:22:ef:2a brd ff:ff:ff:ff:ff:ff
    altname enx08002722ef2a
3: enp0s8: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP mode DEFAULT group default qlen 1000
    link/ether 08:00:27:0c:0a:f3 brd ff:ff:ff:ff:ff:ff
    altname enx0800270c0af3
ichpakov@my-vm:~$ ip route
default via 10.0.2.2 dev enp0s3 proto dhcp src 10.0.2.15 metric 100 
10.0.2.0/24 dev enp0s3 proto kernel scope link src 10.0.2.15 metric 100 
ichpakov@my-vm:~$ sudo systemctl status NetworkManager
[sudo] password for ichpakov: 
● NetworkManager.service - Network Manager
     Loaded: loaded (/usr/lib/systemd/system/NetworkManager.service; enabled; preset: enabled)
     Active: active (running) since Sat 2026-08-01 15:20:39 CEST; 14min ago
 Invocation: 3747a34ea18242989b55b73f6b1d7cae
       Docs: man:NetworkManager(8)
   Main PID: 844 (NetworkManager)
      Tasks: 4 (limit: 4616)
     Memory: 15M (peak: 15.6M)
        CPU: 491ms
     CGroup: /system.slice/NetworkManager.service
             └─844 /usr/sbin/NetworkManager --no-daemon

Aug 01 15:20:39 my-vm NetworkManager[844]: <info>  [1785590439.4888] device (enp0s3): state change: ip-config -> ip-check (reason 'none', m>
Aug 01 15:20:39 my-vm NetworkManager[844]: <info>  [1785590439.4924] device (enp0s3): state change: ip-check -> secondaries (reason 'none',>
Aug 01 15:20:39 my-vm NetworkManager[844]: <info>  [1785590439.4927] device (enp0s3): state change: secondaries -> activated (reason 'none'>
Aug 01 15:20:39 my-vm NetworkManager[844]: <info>  [1785590439.4932] manager: NetworkManager state is now CONNECTED_SITE
Aug 01 15:20:39 my-vm NetworkManager[844]: <info>  [1785590439.4935] device (enp0s3): Activation: successful, device activated.
Aug 01 15:20:39 my-vm NetworkManager[844]: <info>  [1785590439.4940] manager: NetworkManager state is now CONNECTED_GLOBAL
Aug 01 15:20:39 my-vm NetworkManager[844]: <info>  [1785590439.4944] manager: startup complete
Aug 01 15:20:40 my-vm NetworkManager[844]: <info>  [1785590440.7833] policy: set 'Wired connection 1' (enp0s3) as default for IPv6 routing >
Aug 01 15:20:50 my-vm NetworkManager[844]: <info>  [1785590450.4304] agent-manager: agent[b61e587046482ed3,:1.35/org.gnome.Shell.NetworkAge>
Aug 01 15:22:47 my-vm NetworkManager[844]: <info>  [1785590567.2239] agent-manager: agent[f7e2744011f09bdb,:1.85/org.gnome.Shell.NetworkAge>
