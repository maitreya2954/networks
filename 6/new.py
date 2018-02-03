from mininet.net import Mininet                                                                        
from mininet.node import Controller                                                                    
from mininet.topo import SingleSwitchTopo                                                              
from mininet.log import setLogLevel                                                                    
                                                                                                       
import os

net = Mininet()                                                                                                       
h1 = net.addHost( 'h1' )                                                                                              
h2 = net.addHost( 'h2' )                                                                                              
s1 = net.addSwitch( 's1' )
c0 = net.addController( 'c0', controller=RemoteController, ip='127.0.0.1', port=6633)                                                                                          
net.addLink( h1, s1 )                                                                                                 
net.addLink( h2, s1 )                                                                                                 
net.start()
print h1.cmd( 'ping -c2', h2.IP() )

net.stop()  