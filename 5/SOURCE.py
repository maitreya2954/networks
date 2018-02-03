#!/usr/bin/python                                                                            
                                                                                             
from mininet.topo import Topo
from mininet.net import Mininet                                 
from mininet.node import Controller 
from mininet.util import dumpNodeConnections
from mininet.log import setLogLevel
        

def simpleTest():
    "Create and test a simple network"
    # p=int(input())
    net = Mininet()
    s1 = net.addSwitch('s1')
    s2 = net.addSwitch('s2')
    h1 = net.addHost('h1')
    h2 = net.addHost('h2')
    h3 = net.addHost('h3')
    h4 = net.addHost('h4')
    net.addLink(h1, s1)
    net.addLink(h2, s1)
    net.addLink(h3, s2)
    net.addLink(h4, s2)
    net.addLink(s1, s2)
    net.Controller()
    net.start()
    print "Dumping host connections"
    dumpNodeConnections(net.hosts)
    print "Testing network connectivity"
    net.pingAll()
    net.stop()

if __name__ == '__main__':
    # Tell mininet to print useful information
    setLogLevel('info')
    simpleTest()