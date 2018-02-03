set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Red

set nf [open output.nam w]
$ns namtrace-all $nf 

proc finish {} {
	global ns nf
	$ns flush-trace
	close $nf
	exec nam output.nam.
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]


$ns duplex-link $n0 $n1 100Mb 10ms DropTail
$ns duplex-link $n1 $n2 100Mb 100ms DropTail
$ns duplex-link $n1 $n3 2Mb 5ms DropTail
$ns duplex-link $n3 $n4 100Mb 10ms DropTail
$ns duplex-link $n3 $n5 100Mb 100ms DropTail

$ns duplex-link-op $n0 $n1 orient right-down
$ns duplex-link-op $n1 $n2 orient left-down
$ns duplex-link-op $n1 $n3 orient right
$ns duplex-link-op $n3 $n4 orient right-up
$ns duplex-link-op $n3 $n5 orient right-down

$ns queue-limit $n0 $n1 1500
$ns queue-limit $n1 $n2 1500
$ns queue-limit $n1 $n3 1500
$ns queue-limit $n3 $n4 1500
$ns queue-limit $n3 $n5 1500

# set loss_rv [new RandomVariable/Uniform]
# $loss_rv set min_ 0 # the range of the random variable;
# $loss_rv set max_ 100 

# set loss_module [new ErrorModel] 
# $loss_module drop-target [new Agent/Null]
# $loss_module set rate_ 10
# $loss_module ranvar $loss_rv

# set loss_module1 [new ErrorModel] 
# $loss_module1 drop-target [new Agent/Null]
# $loss_module1 set rate_ 5
# $loss_module1 ranvar $loss_rv

# set rng [new RNG]
# $rng seed 1

# set loss_module_BNlink [new ErrorModel]
# $loss_module_BNlink drop-target [new Agent/Null]
# $loss_module_BNlink set rate_ $rng
# $loss_module_BNlink ranvar $loss_rv

# # $ns lossmodel $loss_module $n0 $n1
# # $ns lossmodel $loss_module1 $n2 $n1
# # $ns lossmodel $loss_module $n3 $n4
# # $ns lossmodel $loss_module1 $n3 $n5
# # $ns lossmodel $loss_module_BNlink $n1 $n3

set tcp [new Agent/TCP]
$tcp set class_ 1
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n5 $sink  
$ns connect $tcp $sink

set tcp1 [new Agent/TCP]
$tcp1 set class_ 2
$ns attach-agent $n2 $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $n4 $sink1  
$ns connect $tcp1 $sink1

set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP
# $ftp set interval_ 0.04
# $ftp set packet_size_ 1000
# $ftp set rate_ 100mb

set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ftp1 set type_ FTP
# $ftp1 set interval_ 0.04
# $ftp1 set packet_size_ 1000
# $ftp1 set rate_ 100mb


$ns at 0.1 "$ftp start"
$ns at 0.1 "$ftp1 start"
$ns at 4.4 "$ftp stop"
$ns at 4.5 "$ftp1 stop"
$ns at 5.0 "finish"

# set udp0 [new Agent/UDP]
# $udp0 set class_ 1
# $ns attach-agent $n0 $udp0
# set null0 [new Agent/Null]
# $ns attach-agent $n5 $null0
# $ns connect $udp0 $null0
 
# set cbr0 [new Application/Traffic/CBR]
# $cbr0 set packetSize_ 1000
# $cbr0 set interval_ 0.04
# $cbr0 attach-agent $udp0

 
# set udp1 [new Agent/UDP]
# $udp1 set class_ 2
# $ns attach-agent $n4 $udp1
# set null1 [new Agent/Null]
# $ns attach-agent $n2 $null1
# $ns connect $udp1 $null1
 
# # Create a CBR traffic source and attach it to udp1
# set cbr1 [new Application/Traffic/CBR]
# $cbr1 set packetSize_ 1000
# $cbr1 set interval_ 0.4
# $cbr1 attach-agent $udp1


# $ns at 0.1 "$cbr0 start"
# $ns at 0.2 "$cbr1 start"
# $ns at 4.4 "$cbr1 stop"
# $ns at 4.5 "$cbr0 stop"
# $ns at 5.0 "finish"

$ns run