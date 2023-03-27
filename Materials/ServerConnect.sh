#!/usr/bin/expect -f

spawn ssh -Y fkiran@mreb202.cacds.e.uh.edu
expect "fkiran@mreb202.cacds.e.uh.edu's password: "
send "HSFtth-krn0513"
expect "$ "
interact