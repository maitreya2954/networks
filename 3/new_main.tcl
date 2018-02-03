set ns [new Simulator]

$ns color 123 Blue
$ns color 456 Red

set nf [open output.nam w]
$ns namtrace-all $nf 

set trace [opem basic2.tr.w]
$ns trace-all $trace

proc finish {} {
	global ns nf
	$ns flush-trace
	close $nf
	exec nam output.nam
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns DelayBox]
set n3 [$ns DelayBox]
set n4 [$ns node]
set n5 [$ns node]

$n0 color Blue
$n5 color Blue
$n1 color Red
$n4 color Red
$n2 color Yellow
$n3 color Yellow


set access_delay [new RandomVariable/Uniform]
$access_delay set min_ 10
$access_delay set max_ 100

set delay [new RandomVariable/Constant];
$delay set val_ 5

set loss_rate [new RandomVariable/Uniform];
$loss_rate set min_ 0.001
$loss_rate set max_ 0.05

# set loss_rate1 [new RandomVariable/Uniform];
# $loss_rate1 set min_ 0.05
# $loss_rate1 set max_ 0.05

set ms "ms"

$ns duplex-link $n0 $n2 1000Mb [expr round([$access_delay value]) + 40]$ms DropTail
$ns duplex-link $n1 $n2 1000Mb [expr round([$access_delay value]) + 40]$ms DropTail
$ns duplex-link $n2 $n3 20Mb 5ms DropTail
$ns duplex-link $n3 $n4 1000Mb [expr round([$access_delay value]) + 40]$ms DropTail
$ns duplex-link $n3 $n5 1000Mb [expr round([$access_delay value]) + 40]$ms DropTail

# $ns duplex-link $n0 $n2 1000Mb 40ms DropTail
# $ns duplex-link $n1 $n2 1000Mb 40ms DropTail
# $ns duplex-link $n2 $n3 20Mb 5ms DropTail
# $ns duplex-link $n3 $n4 1000Mb 40ms DropTail
# $ns duplex-link $n3 $n5 1000Mb 40ms DropTail

$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link-op $n3 $n4 orient right-up
$ns duplex-link-op $n3 $n5 orient right-down


$ns queue-limit $n0 $n2 1500
$ns queue-limit $n1 $n2 1500
$ns queue-limit $n2 $n3 1500 
$ns queue-limit $n3 $n4 1500
$ns queue-limit $n3 $n5 1500

# set src [new Agent/TCP/FullTcp]
# set sink [new Agent/TCP/FullTcp]
# $src set fid_ 1
# $sink set fid_ 1
# $src set class_ 1
# $ns attach-agent $n0 $src
# $ns attach-agent $n5 $sink
# $ns connect $src $sink
# $sink listen

# set src1 [new Agent/TCP/FullTcp]
# set sink1 [new Agent/TCP/FullTcp]
# $src1 set fid_ 2
# $src1 set class_ 2
# $sink1 set fid_ 2
# $ns attach-agent $n1 $src1
# $ns attach-agent $n4 $sink1
# $ns connect $src1 $sink1
# $sink1 listen

set tcp [new Agent/TCP]
$tcp set class_ 1
$tcp set fid_ 123
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n5 $sink  
$ns connect $tcp $sink

set tcp1 [new Agent/TCP]
$tcp1 set class_ 2
$tcp1 set fid_ 456
$ns attach-agent $n1 $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $n4 $sink1  
$ns connect $tcp1 $sink1


set telnet [new Application/Telnet]
$telnet attach-agent $tcp
$telnet set interval_ 0.8


set telnet1 [new Application/Telnet]
$telnet1 attach-agent $tcp1
$telnet1 set interval_ 0.8

$n2 add-rule [$n0 id] [$n5 id] $delay $loss_rate 
$n3 add-rule [$n0 id] [$n5 id] $delay $loss_rate
$n2 add-rule [$n1 id] [$n4 id] $delay $loss_rate 
$n3 add-rule [$n1 id] [$n4 id] $delay $loss_rate

$n3 set-debug 1	
$n2 set-debug 1

$n2 set-delay-file "n2.out"
$n3 set-delay-file "n3.out"

$ns at 0.5 "$telnet start"
$ns at 100.0 "$telnet stop"
$ns at 0.5 "$telnet1 start"
$ns at 100.0 "$telnet1 stop"
$ns at 1000.0 "finish"

$ns run